// XRayWrapper.cpp : Defines the entry point for the application.
//

#include "XRayWrapper.h"
#include <sstream>

using namespace std;

int find_close(string& s, int start) {
	
	int count = 0;
	for (int i = start+1; i < s.length(); i++) {
		if (s[i] == '{') {
			count++;
			//cout << "found open" << endl;
		}
		if (s[i] == '}') {
			//cout << "found close"<<  endl;
			count--;
		}
		if (count == -1) {
			
			return i;
		}
	}
	return -1;
}



vector<string> parseLevel(string s) {
	//cout << "parse level" << endl;
	vector<string> sv;
	int start = 0;
	while (true) {
		//find the closing index
		//cout << start << endl;
		int c = find_close(s, start);
		//cout << c << endl;
		sv.push_back(
			string(&s[start + 1], &s[c])
		);
		
		//see if there is a comma following find close
		
		if (s[c+1] == ',') {
			start = c+2;
		}
		else {
			break;
		}
	}
	//cout << sv[0] << endl;
	return sv;
}

vector<string> substring(string s, char delimiter) {
	vector<string>strv;
	stringstream ss(s);

	while (ss.good()) {
		string substr;
		getline(ss, substr, delimiter);
		strv.push_back(substr);
	}
	return strv;
}

// check inputs
/*
	-d "{{detectorSize(x,y)},{sourceType(1/0)},{spectrum(energy (keV), n.photons)},{{detectorPosition(Vector3)}, {detectorUp(Vector3)}},{sourcePosition(Vector3)},{samples(path list)}, {rotation(Vector3)},{mixtures(string)},{{density(float),unit(int)}}"
	so, for example, loading the dragon if its in this directory
	-d '{
		{600,600},
		{80, 1000},
		{1},
		{
			{1, 0, 0},
			{0 ,0, -1}
		},
		{-1, 0, 0},
		{"welsh-dragon-small.stl"},
		{90, 0, 0},
		{"Ti90Al6V4"},
		{4.43},
	}'
	will set the detector to 600x600 pixels at the default size, with a point source type (1). The spectrum is 80 keV with 1000 photons. The detector is positioned at 1,0,0 with its up vector as 0, 0, -1 and the source at -1, 0, 0.
	A list of samples contains the path to the dragon. The sample set is rotation 90 degrees in the X axis. followed by a list of mixtures corresponding to the sample indexes, followed by a list of densities in g/cm3

	for multiple objects:

	-d "[
		{600,600},
		{80, 1000},
		{1},
		{
			{1, 0, 0},
			{0 ,0, -1}
		},
		{-1, 0, 0},
		{"welsh-dragon-small.stl", "flying-banana.stl"},
		{90, 0, 0},
		{"Ti90Al6V4", "AL100"},
		{4.43, 5},
	]"

	This is NOT JSON and MUST be in this order!!!!!!!

	-d specifies 'direct' in the format above
	-j will implement JSON later
*/
int main(int argc, char** argv)
{
	if (argc < 2) {
		std::cout << "Please run this program with the correct arguements" << std::endl;


	}
	else {

		if (strcmp(argv[1], "-d") == 0) {
			//std::cout << argv[2] << std::endl;
			// look through the input string 
			// //convert char** to string
			string d = argv[2];
			//string d = " \'{{600,600},{80, 1000},{1},{{1, 0, 0},{0 ,0, -1}},{-1, 0, 0},{\". / welsh - dragon - small.stl\"},{90, 0, 0},{\"Ti90Al6V4\"},{4.43}}\' ";
			// get the main body
			//std::cout << d.find_last_of('}') << std::endl;
			//string body = string(&d[d.find_first_of('{') + 1], &d[find_close(d, d.find_first_of('{'))]);
			string body = parseLevel(d)[0];
			//cout << body << endl;
			// split string at comma
			
			// get the detector size
			//string dxy = string(&body[body.find_first_of('{') + 1], &body[body.find_first_of('}')]);
			vector<string> l1 = parseLevel(body);
			string dxy = l1[0];

			//get the spectrum
			string spectrum = l1[1];

			//get the source type
			int sourceType = stoi(l1[2]);

			//get the detector position and up vector
			string dpv = l1[3];

			//get the source position
			string sp = l1[4];

			//get the list of samples
			string samplePaths = l1[5];

			//get the master rotation
			string rot = l1[6];

			//get the mixtures for each sample
			string mixtures = l1[7];

			//get the densities and units for each sample
			string densities = l1[8];

			//cout << l1.size() << endl;


			std::cout << dxy << std::endl;

			cout << spectrum << "\n" << sourceType << "\n" << dpv << "\n" << sp << "\n" << samplePaths << "\n" << rot << "\n" << mixtures << "\n" << densities << endl;
			createOpenGLContext();
			//set up the source
			if (sourceType == 1) {
				usePointSource();
			}
			else {
				useParallelSource();
			}
			vector<string> spv = substring(sp, ',');
			setSourcePosition(stod(spv[0]), stod(spv[1]), stod(spv[2]), "m");
			vector<string> sm = substring(spectrum, ',');
			setMonoChromatic(stod(sm[0]), "keV", stod(sm[1]));

			//set up the detector
			vector<string> ds = parseLevel(dpv);
			vector<string> dp = substring(ds[0], ',');
			vector<string> du = substring( ds[1], ',');

			setDetectorPosition(stod(dp[0]), stod(dp[1]), stod(dp[2]), "m");
			setDetectorUpVector(stod(du[0]), stod(du[1]), stod(du[2]));

			//load files, set materials and set densities (one loop to save time)
			vector<string> vFilePaths = substring(samplePaths, ',');
			vector<string> vMixtures = substring(mixtures, ',');
			vector<string> vDensities = substring(densities, ',');
			vector<string> vRot = substring(rot, ',');

			for (int i = 0; i < vFilePaths.size(); i++) {
				cout << "adding file: " << vFilePaths[i] << "\n" << endl;
				loadMeshFile("sample" + i, vFilePaths[i], "mm");
				moveToCenter("sample" + i);
				setMixture("sample" + i, vMixtures[i]);
				setDensity("sample" + i, stod(vDensities[i]), "g/cm3");
				//rotateNode("sample" + i, stod(vRot[0]), stod(vRot[1]), stod(vRot[2]));
				cout << "finished" << endl;
			}
			//loadMeshFile("dragon", "F:\\gvxr-build\\_gvxrPython3\\welsh-dragon-small.stl", "m");
			// set the detector pixels
			vector<string> vDxy = substring(dxy, ',');
			setDetectorNumberOfPixels(stoi(vDxy[0]), stoi(vDxy[1]));
			setDetectorPixelSize(0.5, 0.5, "mm");
			cout << "creating openGL context" << endl;
			
			std::vector<std::vector<float> > im = computeXRayImage();
			saveLastXRayImage("out.tif");

		}
		else if (argv[1] == "-j") {
			std::cout << "JSON loading not supported yet, sorry" << std::endl;
		}

	}
}






// the following methods expose their corresponding methods in simpleGVXR.h to the engine, ideally this will work in a blueprint which makes my life a lot easier

void setGVXRSourcePosition(Vector3 pos) {
	setSourcePosition(pos.X, pos.Y, pos.Z, "m");
}

void setGVXRDetectorPosition(Vector3 pos) {
	setDetectorPosition(pos.X, pos.Y, pos.Z, "m");
}

void setGVXRDetectorUpVector(Vector3 up) {
	setDetectorUpVector(up.X, up.Y, up.Z);
}

// set the source type, default point, 0 point, 1/2 parallel (orthographic) 
void setUseParallelSource(bool s) {
	if (s) {
		useParallelSource();
	}
	else {
		usePointSource();
	}
}

std::vector<std::vector<float>> computeGVXRImage() {
	return  computeXRayImage(); //call simpleGVXR
}
