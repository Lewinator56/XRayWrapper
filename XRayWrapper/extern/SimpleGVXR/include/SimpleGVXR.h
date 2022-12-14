/*

Copyright (c) 2019, Dr Franck P. Vidal (franck.p.vidal@fpvidal.net),
http://www.fpvidal.net/
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice,
this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation and/or
other materials provided with the distribution.

3. Neither the name of the Bangor University nor the names of its contributors
may be used to endorse or promote products derived from this software without
specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/


#ifndef __SimpleGVXR_h
#define __SimpleGVXR_h


/**
********************************************************************************
*
*   @file       SimpleGVXR.h
*
*   @brief      SimpleGVXR is an API to the bulk functionalities and classes of
*               gVirtualXRay. SimpleGVXR is used as the basis for
*               the language bindings generated using SWIG.
*
*   @version    1.0
*
*   @date       03/10/2018
*
*   @author     Dr Franck P. Vidal
*
*   License
*   BSD 3-Clause License.
*
*   For details on use and redistribution please refer
*   to http://opensource.org/licenses/BSD-3-Clause
*
*   Copyright
*   (c) by Dr Franck P. Vidal (franck.p.vidal@fpvidal.net),
*   http://www.fpvidal.net/, Oct 2018, 2018, version 1.1, BSD 3-Clause License
*
********************************************************************************
*/


//******************************************************************************
//  Include
//******************************************************************************
#include <vector>
#include <string>


//------------------------------------------------------------------------------
/// Accessor on the major version of the core gVirtualXRay library (gvxr).
/// This number is changed when incompatible API changes have been made.
/**
 *  @return the major version number
 */
//------------------------------------------------------------------------------
int getMajorVersionOfCoreGVXR();


//------------------------------------------------------------------------------
/// Accessor on the minor version of the core gVirtualXRay library (gvxr).
/// This number is changed when new functionalities have been added in
/// a backwards-compatible manner.
/**
 *  @return the minor version number
 */
//------------------------------------------------------------------------------
int getMinorVersionOfCoreGVXR();


//------------------------------------------------------------------------------
/// Accessor on the minor version of the core gVirtualXRay library (gvxr).
/// This number is changed when bug fixes have been added in
/// a backwards-compatible manner.
/**
 *  @return the patch version number
 */
//------------------------------------------------------------------------------
int getPatchVersionOfCoreGVXR();


//------------------------------------------------------------------------------
/// Accessor on the full string version of the core gVirtualXRay library (gvxr).
/**
 *  @return the full version number
 */
//------------------------------------------------------------------------------
std::string getVersionOfCoreGVXR();


//------------------------------------------------------------------------------
/// Accessor on the major version of SimpleGVXR. This number is changed
/// when incompatible API changes have been made.
/**
 *  @return the major version number
 */
//------------------------------------------------------------------------------
int getMajorVersionOfSimpleGVXR();


//------------------------------------------------------------------------------
/// Accessor on the minor version of SimpleGVXR. This number is changed when
/// new functionalities have been added in a backwards-compatible manner.
/**
 *  @return the minor version number
 */
//------------------------------------------------------------------------------
int getMinorVersionOfSimpleGVXR();


//------------------------------------------------------------------------------
/// Accessor on the minor version of SimpleGVXR. This number is changed when
/// bug fixes have been added in a backwards-compatible manner.
/**
 *  @return the patch version number
 */
//------------------------------------------------------------------------------
int getPatchVersionOfSimpleGVXR();


//------------------------------------------------------------------------------
/// Accessor on the full string version of SimpleGVXR.
/**
 *  @return the full version number
 */
//------------------------------------------------------------------------------
std::string getVersionOfSimpleGVXR();


//------------------------------------------------------------------------------
/// Accessor on the OpenGL renderer.
/**
 *  @return a string displaying the OpenGL renderer
 */
//------------------------------------------------------------------------------
std::string getOpenGlRenderer();


//------------------------------------------------------------------------------
/// Accessor on the OpenGL version.
/**
 *  @return a string displaying the OpenGL version
 */
//------------------------------------------------------------------------------
std::string getOpenGlVersion();


//------------------------------------------------------------------------------
/// Accessor on the OpenGL vendor.
/**
 *  @return a string displaying the OpenGL vendor
 */
//------------------------------------------------------------------------------
std::string getOpenGlVendor();


void useLogFile(const char* aFileName = "gvxr.log");

void displayBeam(bool aState = true);
void displayDetector(bool aState = true);
void displayNormalVectors(bool aState = true);
void useWireframe(bool aState = true);
void useLighing(bool aState = true);
void useNegative(bool aState = true);


//------------------------------------------------------------------------------
/// Replace the projection matrix by a orthographic projection matrix.
/// It behaves as the old glOrtho function.
/**
*   @param  left:   Specify the coordinates for the left vertical clipping plane
*   @param  right:  Specify the coordinates for the right vertical
*                   clipping plane
*   @param  bottom: Specify the coordinates for the bottom horizontal
*                   clipping plane
*   @param  top:    Specify the coordinates for the top horizontal
*                   clipping plane
*   @param  zNear:  Specify the distances to the near clipping plane.
*                   The value must be positive
*   @param  zFar:   Specify the distances to the far clipping plane.
*                   The value must be positive
*/
//------------------------------------------------------------------------------
void orthographic(double left,
        double right,
        double bottom,
        double top,
        double zNear,
        double zFar);


//------------------------------------------------------------------------------
/// Replace the projection matrix by a perspective projection matrix.
/// It behaves as the old gluPerspective function.
/**
*   @param  fovy:   specifies the field of view angle, in degrees, in
*                   the y-direction.
*   @param  aspect: Specifies the aspect ratio that determines
*                   the field of view in the x direction.
*                   The aspect ratio is the ratio of x (width) to y (height).
*   @param  zNear:  Specifies the distance from the viewer to the near
*                   clipping plane (always positive)
*   @param  zFar:   Specifies the distance from the viewer to the far
*                   clipping plane (always positive).
*/
//------------------------------------------------------------------------------
void perspective(double fovy, double aspect, double  zNear, double  zFar);


//------------------------------------------------------------------------------
/// Replace the modelling-viewing matrix by a viewing transformation matrix.
/// It behaves as the old gluLookAt function.
/**
*   @param  eyeX:       Specifies the position of the eye point along the X-axis
*   @param  eyeY:       Specifies the position of the eye point along the Y-axis
*   @param  eyeZ:       Specifies the position of the eye point along the Z-axis
*   @param  lookAtX:    Specifies the position of the reference point along
*                       the X-axis
*   @param  lookAtY:    Specifies the position of the reference point along
*                       the Y-axis
*   @param  lookAtZ:    Specifies the position of the reference point along
*                       the Z-axis
*   @param  upX         Specifies the direction of the up vector along
*                       the X-axis
*   @param  upY         Specifies the direction of the up vector along
*                       the Y-axis
*   @param  upZ         Specifies the direction of the up vector along
*                       the Z-axis
*/
//------------------------------------------------------------------------------
void lookAt(double eyeX,
            double eyeY,
            double eyeZ,
            double lookAtX,
            double lookAtY,
            double lookAtZ,
            double upX,
            double upY,
            double upZ);


//------------------------------------------------------------------------------
/// Add the current matrix to the model/view matrix stack.
/// It behaves as the combination of the old
/// glMatrixMode(GL_MODELVIEW);glPushMatrix() functions.
//------------------------------------------------------------------------------
void pushModelViewMatrix();


//------------------------------------------------------------------------------
/// Restore the matrix from the model/view matrix stack,
/// and remove the last matrix of the stack.
/// glMatrixMode(GL_MODELVIEW);glPopMatrix() functions.
//------------------------------------------------------------------------------
void popModelViewMatrix();


//------------------------------------------------------------------------------
/// Restore the matrix from the model/view matrix stack,
/// and remove the last matrix of the stack.
/// glMatrixMode(GL_MODELVIEW);glRotate() functions.
/**
 *   @param  anAngle:   the angle of rotation in degrees
 *   @param  x: the coordinate of the rotation axis along the X-axis
 *   @param  y: the coordinate of the rotation axis along the Y-axis
 *   @param  z: the coordinate of the rotation axis along the Z-axis
 */
//------------------------------------------------------------------------------
void rotateModelView(double anAngle, double x, double y, double z);


//------------------------------------------------------------------------------
/// Create an OpenGL context automatically.
/**
 *  @param aFlag:   true to create the OpenGL context automatically,
 *                  false otherwise (default value: true)
 */
//------------------------------------------------------------------------------
void autoCreateOpenGLContext(bool aFlag = true);


//------------------------------------------------------------------------------
/// Set the position of the X-ray source.
/**
 *  @param x:   the position along the X-axis
 *  @param y:   the position along the Y-axis
 *  @param z:   the position along the Z-axis
 *  @param aUnitOfLength:   the unit of length corresponding to the x, y and z
 *                          parameters. Acceptable values are:
 *                          "um", "micrometre",  "micrometer",
 *                          "mm", "millimetre",  "millimeter",
 *                          "cm", "centimetre",  "centimeter",
 *                          "dm",  "decimetre",  "decimeter",
 *                          "m",   "metre",      "meter",
 *                          "dam", "decametre",  "decameter",
 *                          "hm",  "hectometre", "hectometer",
 *                          "km",  "kilometre",  "kilometer"
 */
//------------------------------------------------------------------------------
void setSourcePosition(double x,
    double y,
    double z,
    const std::string& aUnitOfLength);


//------------------------------------------------------------------------------
/// Accessor on the position of the X-ray source.
/**
 *  @param aUnitOfLength:   the unit of length corresponding to
 *                          the returned value. Acceptable values are:
 *                          "um", "micrometre",  "micrometer",
 *                          "mm", "millimetre",  "millimeter",
 *                          "cm", "centimetre",  "centimeter",
 *                          "dm",  "decimetre",  "decimeter",
 *                          "m",   "metre",      "meter",
 *                          "dam", "decametre",  "decameter",
 *                          "hm",  "hectometre", "hectometer",
 *                          "km",  "kilometre",  "kilometer"
 *  @return the source position in a given unit of length
 */
//------------------------------------------------------------------------------
std::vector<double> getSourcePosition(const std::string& aUnitOfLength);


//------------------------------------------------------------------------------
/// Set the position of the X-ray detector.
/**
 *  @param x:   the position along the X-axis
 *  @param y:   the position along the Y-axis
 *  @param z:   the position along the Z-axis
 *  @param aUnitOfLength:   the unit of length corresponding to the x, y and z
 *                          parameters. Acceptable values are:
 *                          "um", "micrometre",  "micrometer",
 *                          "mm", "millimetre",  "millimeter",
 *                          "cm", "centimetre",  "centimeter",
 *                          "dm",  "decimetre",  "decimeter",
 *                          "m",   "metre",      "meter",
 *                          "dam", "decametre",  "decameter",
 *                          "hm",  "hectometre", "hectometer",
 *                          "km",  "kilometre",  "kilometer"
 */
//------------------------------------------------------------------------------
void setDetectorPosition(double x,
    double y,
    double z,
    const std::string& aUnitOfLength);


//------------------------------------------------------------------------------
/// Accessor on the position of the X-ray detector.
/**
 *  @param aUnitOfLength:   the unit of length corresponding to
 *                          the returned value. Acceptable values are:
 *                          "um", "micrometre",  "micrometer",
 *                          "mm", "millimetre",  "millimeter",
 *                          "cm", "centimetre",  "centimeter",
 *                          "dm",  "decimetre",  "decimeter",
 *                          "m",   "metre",      "meter",
 *                          "dam", "decametre",  "decameter",
 *                          "hm",  "hectometre", "hectometer",
 *                          "km",  "kilometre",  "kilometer"
 *  @return the source position in a given unit of length
 */
//------------------------------------------------------------------------------
std::vector<double> getDetectorPosition(const std::string& aUnitOfLength);


//------------------------------------------------------------------------------
/// Set the up-vector defining the orientation of the X-ray detector.
/**
 *  @param x:   the component of the vector along the X-axis
 *  @param y:   the component of the vector along the Y-axis
 *  @param z:   the component of the vector along the Z-axis
 */
//------------------------------------------------------------------------------
void setDetectorUpVector(double x, double y, double z);


//------------------------------------------------------------------------------
/// Accessor on the up-vector defining the orientation of the X-ray detector.
/**
 *  @return the up-vector
 */
//------------------------------------------------------------------------------
std::vector<double> getDetectorUpVector();


//------------------------------------------------------------------------------
/// Accessor on the right-vector defining the orientation of the X-ray detector.
/**
 *  @return the right-vector
 */
//------------------------------------------------------------------------------
std::vector<double> getDetectorRightVector();


//------------------------------------------------------------------------------
/// Set the number of pixels of the X-ray detector.
/**
 *  @param aWidth:  the number of pixels along the X-axis
 *  @param aHeight: the number of pixels along the Y-axis
 */
//------------------------------------------------------------------------------
void setDetectorNumberOfPixels(int aWidth, int aHeight);


//------------------------------------------------------------------------------
/// Accessor on the number of pixels of the X-ray detector.
/**
 *  @return the size of the detector in number of pixels
 */
//------------------------------------------------------------------------------
std::vector<int> getDetectorNumberOfPixels();


//--------------------------------------------------------------------------
/// Set the multiplicative factor to oversample the L-buffers.
/**
 *  @param aFactor:  the multiplicative factor (default value: 1, for no oversampling)
 */
//--------------------------------------------------------------------------
void setOversamplingFactor(int aFactor = 1);


//--------------------------------------------------------------------------
/// Accessor on the multiplicative factor to oversample the L-buffers.
/**
 *  @return the multiplicative factor
 */
//--------------------------------------------------------------------------
int getOversamplingFactor();


//------------------------------------------------------------------------------
/// Set the pixel size.
/**
 *  @param aWidth:  the pixel size along the X-axis
 *  @param aHeight: the pixel size along the Y-axis
 *  @param aUnitOfLength:   the unit of length corresponding to the aWidth and
 *                          aHeight parameters. Acceptable values are:
 *                          "um", "micrometre",  "micrometer",
 *                          "mm", "millimetre",  "millimeter",
 *                          "cm", "centimetre",  "centimeter",
 *                          "dm",  "decimetre",  "decimeter",
 *                          "m",   "metre",      "meter",
 *                          "dam", "decametre",  "decameter",
 *                          "hm",  "hectometre", "hectometer",
 *                          "km",  "kilometre",  "kilometer"
 */
//------------------------------------------------------------------------------
void setDetectorPixelSize(double aWidth,
    double aHeight,
    const std::string& aUnitOfLength);


//------------------------------------------------------------------------------
/// Accessor on the size of the X-ray detector.
/**
 *  @param aUnitOfLength:   the unit of length corresponding to
 *                          the returned value. Acceptable values are:
 *                          "um", "micrometre",  "micrometer",
 *                          "mm", "millimetre",  "millimeter",
 *                          "cm", "centimetre",  "centimeter",
 *                          "dm",  "decimetre",  "decimeter",
 *                          "m",   "metre",      "meter",
 *                          "dam", "decametre",  "decameter",
 *                          "hm",  "hectometre", "hectometer",
 *                          "km",  "kilometre",  "kilometer"
 *  @return the size in a given unit of length
 */
//------------------------------------------------------------------------------
std::vector<double> getDetectorSize(const std::string& aUnitOfLength);


//------------------------------------------------------------------------------
/// Clear the energy response of the detector.
//------------------------------------------------------------------------------
void clearDetectorEnergyResponse();


//------------------------------------------------------------------------------
/// Load the energy response of the detector from a TSV file.
/**
 *  @param aFileName: name of the file. Each line of the file is formatted as follows:
 *                    input_energy  output_energy
 *  @param aUnitOfEnergy: the unit of energy corresponding to the data in the file
 */
//------------------------------------------------------------------------------
void loadDetectorEnergyResponse(const std::string& aFileName,
    const std::string& aUnitOfEnergy);


//------------------------------------------------------------------------------
/// Load a polygon mesh from a file, set its label in the scenegraph
/// (i.e. identifier) and add it to the X-ray renderer.
/**
 *  @param aLabel:          the label in the scenegraph
 *  @param aFileName:       the file where the polygon mesh data is stored
 *  @param aUnitOfLength:   the unit of length corresponding to the data stored
 *                          in the file. Acceptable values are:
 *                          "um", "micrometre",  "micrometer",
 *                          "mm", "millimetre",  "millimeter",
 *                          "cm", "centimetre",  "centimeter",
 *                          "dm",  "decimetre",  "decimeter",
 *                          "m",   "metre",      "meter",
 *                          "dam", "decametre",  "decameter",
 *                          "hm",  "hectometre", "hectometer",
 *                          "km",  "kilometre",  "kilometer"
 *  @addToRendererAsInnerSurface: a flag to add the mesh to the X-ray renderer (as an inner surface) (default value: true)
 */
//------------------------------------------------------------------------------
void loadMeshFile(const std::string& aLabel,
                  const std::string& aFileName,
                  const std::string& aUnitOfLength,
				  bool addToRendererAsInnerSurface = true);


//------------------------------------------------------------------------------
/// Load a scenegraph from a file and add its polygon meshes
/// to the X-ray renderer.
/**
 *  @param aFileName:       the file where the polygon mesh data is stored
 *  @param aUnitOfLength:   the unit of length corresponding to the data stored
 *                          in the file. Acceptable values are:
 *                          "um", "micrometre",  "micrometer",
 *                          "mm", "millimetre",  "millimeter",
 *                          "cm", "centimetre",  "centimeter",
 *                          "dm",  "decimetre",  "decimeter",
 *                          "m",   "metre",      "meter",
 *                          "dam", "decametre",  "decameter",
 *                          "hm",  "hectometre", "hectometer",
 *                          "km",  "kilometre",  "kilometer"
 */
//------------------------------------------------------------------------------
void loadSceneGraph(const std::string& aFileName,
    const std::string& aUnitOfLength);


//------------------------------------------------------------------------------
/// Accessor on the number of primitives of a given node.
/**
 *  @param aLabel:  the label in the scenegraph
 *  @return the number of primitives
 */
//------------------------------------------------------------------------------
unsigned int getNumberOfPrimitives(const std::string& aLabel);


//------------------------------------------------------------------------------
/// Create an empty polygon mesh and set its label in the scenegraph
/// (i.e. identifier). Note that it is not added to the X-ray renderer.
/**
 *  @param aLabel:  the label in the scenegraph
 *  @param aParent: the parent of the node in the scenegraph (default: "root")
 */
//------------------------------------------------------------------------------
void emptyMesh(const std::string& aLabel,
        const std::string& aParent = "root");


//------------------------------------------------------------------------------
/// Create a cube, centred on (0, 0, 0) and set its label in the scenegraph (i.e. identifier).
/// Note that it is not added to the X-ray renderer.
/**
 *  @param aLabel:  the label in the scenegraph
 *  @param aLength: the size of an edge of the cube
 *  @param aUnitOfLength:   the unit of length corresponding to aLength.
 *                          Acceptable values are:
 *                          "um", "micrometre",  "micrometer",
 *                          "mm", "millimetre",  "millimeter",
 *                          "cm", "centimetre",  "centimeter",
 *                          "dm",  "decimetre",  "decimeter",
 *                          "m",   "metre",      "meter",
 *                          "dam", "decametre",  "decameter",
 *                          "hm",  "hectometre", "hectometer",
 *                          "km",  "kilometre",  "kilometer"
 *                          (default value: "cm")
 *  @param aParent: the parent of the node in the scenegraph (default: "root")
 */
//------------------------------------------------------------------------------
void makeCube(const std::string& aLabel,
        double aLength = 1.0,
        const std::string& aUnitOfLength = "cm",
        const std::string& aParent = "root");


//------------------------------------------------------------------------------
/// Create a cylinder and set its label in the scenegraph (i.e. identifier).
/// Note that it is not added to the X-ray renderer.
/**
 *  @param aLabel:  the label in the scenegraph
 *  @param aNumberOfSectors:    the number of sector defining the mesh
 *  @param aHeight: the height of the cylinder
 *  @param aRadius: the radius of the cylinder
 *  @param aUnitOfLength:   the unit of length corresponding to aHeight and
 *                          aRadius. Acceptable values are:
 *                          "um", "micrometre",  "micrometer",
 *                          "mm", "millimetre",  "millimeter",
 *                          "cm", "centimetre",  "centimeter",
 *                          "dm",  "decimetre",  "decimeter",
 *                          "m",   "metre",      "meter",
 *                          "dam", "decametre",  "decameter",
 *                          "hm",  "hectometre", "hectometer",
 *                          "km",  "kilometre",  "kilometer"
 *                          (default value: "cm")
 *  @param aParent: the parent of the node in the scenegraph (default: "root")
 */
//------------------------------------------------------------------------------
void makeCylinder(const std::string& aLabel,
                  unsigned int aNumberOfSectors = 10,
                  double aHeight = 1.0,
                  double aRadius = 0.5,
                  const std::string& aUnitOfLength = "cm",
                  const std::string& aParent = "root");


//------------------------------------------------------------------------------
/// Create an iso-surface from a 3D image and set its label in the scenegraph (i.e. identifier).
/// Note that it is not added to the X-ray renderer.
/**
*  @param aLabel:  the label in the scenegraph
*  @param anIsoValue: the iso-value
*  @param aVoxelDataSet:  the voxel dataset
*  @param aWidth:  the number of voxel along the X-axis
*  @param aHeight:  the number of voxel along the Y-axis
*  @param aDepth:  the number of voxel along the Z-axis
*  @param aSpacingX: the space between the centre of two successive voxels along the X-axis
*  @param aSpacingY: the space between the centre of two successive voxels along the Y-axis
*  @param aSpacingZ: the space between the centre of two successive voxels along the Z-axis
*  @param aUnitOfLength:   the unit of length corresponding to aSpacingX, aSpacingY and aSpacingZ.
*                          Acceptable values are:
*                          "um", "micrometre",  "micrometer",
*                          "mm", "millimetre",  "millimeter",
*                          "cm", "centimetre",  "centimeter",
*                          "dm",  "decimetre",  "decimeter",
*                          "m",   "metre",      "meter",
*                          "dam", "decametre",  "decameter",
*                          "hm",  "hectometre", "hectometer",
*                          "km",  "kilometre",  "kilometer"
*                          (default value: "cm")
*  @param aParent: the parent of the node in the scenegraph (default: "root")
*/
//------------------------------------------------------------------------------
void makeIsoSurface(const std::string& aLabel,
    short anIsoValue,
    const std::vector<short>& aVoxelDataSet,
    unsigned int aWidth,
    unsigned int aHeight,
    unsigned int aDepth,
    double aSpacingX,
    double aSpacingY,
    double aSpacingZ,
    const std::string& aUnitOfLength = "cm",
    const std::string& aParent = "root");


void makeTriangularMesh(const std::string& aLabel,
		const std::vector<float>& aVertexSet,
	    const std::string& aUnitOfLength = "cm",
		const std::string& aParent = "root");


void makeTriangularMesh(const std::string& aLabel,
		const std::vector<float>& aVertexSet,
		const std::vector<int>& aTriangleIndexSet,
	    const std::string& aUnitOfLength = "cm",
		const std::string& aParent = "root");


//------------------------------------------------------------------------------
/// Add a polygon mesh (aSource) to another one (aDestination).
/// It corresponds to the operation as follows: aDestination += aSource.
/// Both aSource and aDestination have to already exist in the scenegraph.
/**
 *  @param aDestination:    the polygon mesh that is going to be modified
 *  @param aSource:         the polygon mesh that is going to be added
 *                          to aDestination
 */
//------------------------------------------------------------------------------
void addMesh(const std::string& aDestination, const std::string& aSource);


//------------------------------------------------------------------------------
/// Subtract a polygon mesh (aSource) from another one (aDestination).
/// It corresponds to the operation as follows: aDestination -= aSource.
/// Both aSource and aDestination have to already exist in the scenegraph.
/**
 *  @param aDestination:    the polygon mesh that is going to be modified
 *  @param aSource:         the polygon mesh that is going to be subtracted
 *                          from aDestination
 */
//------------------------------------------------------------------------------
void subtractMesh(const std::string& aDestination, const std::string& aSource);


//------------------------------------------------------------------------------
/// Get the number of children of a node in the scenegraph.
/**
 *  @param aLabel:  the label in the scenegraph
 *  @return the number of chidren
 */
//------------------------------------------------------------------------------
unsigned int getNumberOfChildren(const std::string& aLabel);


//------------------------------------------------------------------------------
/// Accessor on the i-th child's label in the list of children of a given node
/// in the scenegraph.
/**
 *  @param aLabel:  the label in the scenegraph
 *  @param i:   the ID of the child
 *  @return the label corresponding to the i-th child
 */
//------------------------------------------------------------------------------
std::string getChildLabel(const std::string& aLabel, unsigned int i);


//------------------------------------------------------------------------------
/// Accessor on the local transformation matrix of a given node in
/// the scenegraph. If the node does not exist, the identity matrix is returned.
/**
 *  @param aLabel:  the label in the scenegraph
 *  @return the corresponding local transformation matrix
 */
//------------------------------------------------------------------------------
std::vector<double> getLocalTransformationMatrix(const std::string& aLabel);


//------------------------------------------------------------------------------
/// Set the local transformation matrix of a given node in the scenegraph.
/**
 *  @param aLabel:  the label in the scenegraph
 *  @param aMatrix: the local transformation matrix
 */
//------------------------------------------------------------------------------
void setLocalTransformationMatrix(const std::string& aLabel,
    const std::vector<double>& aMatrix);


//------------------------------------------------------------------------------
/// Apply the current local transformation to all the vertices of a given node in the scenegraph.
/// Note the the local transformation is then reset to the identity matrix.
/**
 *  @param aLabel:  the label in the scenegraph
 */
//------------------------------------------------------------------------------
void applyCurrentLocalTransformation(const std::string& aLabel);


//------------------------------------------------------------------------------
/// Access the bounding box of a given node and all its children (if any).
/// The bounding box is given in the world coordinate system.
/**
 *  @param aLabel:  the label in the scenegraph
 *  @param aUnitOfLength:   the unit of length corresponding to the bounding box.
 *                          Acceptable values are:
 *                          "um", "micrometre",  "micrometer",
 *                          "mm", "millimetre",  "millimeter",
 *                          "cm", "centimetre",  "centimeter",
 *                          "dm",  "decimetre",  "decimeter",
 *                          "m",   "metre",      "meter",
 *                          "dam", "decametre",  "decameter",
 *                          "hm",  "hectometre", "hectometer",
 *                          "km",  "kilometre",  "kilometer"
 *                          (default value: "cm")
 *  @return the bounding box as: min_x, min_y, min_z, max_x, max_y, max_z
 */
//------------------------------------------------------------------------------
std::vector<double> getNodeAndChildrenBoundingBox(const std::string& aLabel,
    const std::string& aUnitOfLength = "cm");


//------------------------------------------------------------------------------
/// Access the bounding box of a given node (without its children).
/// The bounding box is given in the world coordinate system.
/**
 *  @param aLabel:  the label in the scenegraph
 *  @param aUnitOfLength:   the unit of length corresponding to the bounding box.
 *                          Acceptable values are:
 *                          "um", "micrometre",  "micrometer",
 *                          "mm", "millimetre",  "millimeter",
 *                          "cm", "centimetre",  "centimeter",
 *                          "dm",  "decimetre",  "decimeter",
 *                          "m",   "metre",      "meter",
 *                          "dam", "decametre",  "decameter",
 *                          "hm",  "hectometre", "hectometer",
 *                          "km",  "kilometre",  "kilometer"
 *                          (default value: "cm")
 *  @return the bounding box as: min_x, min_y, min_z, max_x, max_y, max_z
 */
//------------------------------------------------------------------------------
std::vector<double> getNodeOnlyBoundingBox(const std::string& aLabel,
    const std::string& aUnitOfLength = "cm");


//------------------------------------------------------------------------------
/// Display the scenegraph node using OpenGL.
/**
 *  @param aLabel:          the label of the polygon mesh
 */
//------------------------------------------------------------------------------
void displayNode(const std::string& aLabel);


//------------------------------------------------------------------------------
/// Invert the normal vectors of a given polygon mesh.
/**
 *  @param aLabel:  the label of the polygon mesh
 */
//------------------------------------------------------------------------------
void invertNormalVectors(const std::string& aLabel);


//------------------------------------------------------------------------------
/// Set the color of a given polygon mesh.
/**
 *  @param aLabel:  the label of the polygon mesh
 *  @param R:   the red channel
 *  @param G:   the green channel
 *  @param B:   the blue channel
 *  @param A:   the alpha channel
 */
//------------------------------------------------------------------------------
void setColor(const std::string& aLabel, float R, float G, float B, float A);


//------------------------------------------------------------------------------
/// Set the colour of a given polygon mesh.
/**
 *  @param aLabel:  the label of the polygon mesh
 *  @param R:   the red channel
 *  @param G:   the green channel
 *  @param B:   the blue channel
 *  @param A:   the alpha channel
 */
//------------------------------------------------------------------------------
void setColour(const std::string& aLabel, float R, float G, float B, float A);


//------------------------------------------------------------------------------
/// Accessor on the ambient colour of the material of a given polygon mesh.
/**
 *  @return the ambient colour
 */
//------------------------------------------------------------------------------
std::vector<float> getAmbientColour(const std::string& aLabel);


//------------------------------------------------------------------------------
/// Accessor on the diffuse colour of the material of a given polygon mesh.
/**
 *  @return the diffuse colour
 */
//------------------------------------------------------------------------------
std::vector<float> getDiffuseColour(const std::string& aLabel);


//------------------------------------------------------------------------------
/// Accessor on the specular colour of the material of a given polygon mesh.
/**
 *  @return the specular colour
 */
//------------------------------------------------------------------------------
std::vector<float> getSpecularColour(const std::string& aLabel);


//------------------------------------------------------------------------------
/// Accessor on the shininess of the material of a given polygon mesh.
/**
 *  @return the shininess coefficient
 */
//------------------------------------------------------------------------------
float getShininess(const std::string& aLabel);


//------------------------------------------------------------------------------
/// Add a polygon mesh, given its label, to the X-ray renderer as
/// an inner surface.
/**
 *  @param aLabel:  the label of the polygon mesh in the scenegraph
 */
//------------------------------------------------------------------------------
void addPolygonMeshAsInnerSurface(const std::string& aLabel);


//------------------------------------------------------------------------------
/// Add a polygon mesh, given its label, to the X-ray renderer as
/// an outer surface.
/**
 *  @param aLabel:  the label of the polygon mesh in the scenegraph
 */
//------------------------------------------------------------------------------
void addPolygonMeshAsOuterSurface(const std::string& aLabel);


//------------------------------------------------------------------------------
/// Empty the scenegraph. Note that it also empties the X-ray renderer
/// from all its meshes.
//------------------------------------------------------------------------------
void removePolygonMeshesFromSceneGraph();


//------------------------------------------------------------------------------
/// Empty the X-ray renderer from all its meshes.
/// Note that the meshes are kept in the scenegraph.
//------------------------------------------------------------------------------
void removePolygonMeshesFromXRayRenderer();


//------------------------------------------------------------------------------
/// Move the scenegraph to the centre.
//------------------------------------------------------------------------------
void moveToCenter();


//------------------------------------------------------------------------------
/// Move the scenegraph to the centre.
//------------------------------------------------------------------------------
void moveToCentre();


//------------------------------------------------------------------------------
/// Move a polygon mesh to the centre.
/**
 *  @param aLabel:  the label of the polygon mesh in the scenegraph
 */
//------------------------------------------------------------------------------
void moveToCenter(const std::string& aLabel);


//------------------------------------------------------------------------------
/// Move a polygon mesh to the centre.
/**
 *  @param aLabel:  the label of the polygon mesh in the scenegraph
 */
//------------------------------------------------------------------------------
void moveToCentre(const std::string& aLabel);


//------------------------------------------------------------------------------
/// Scale a polygon mesh.
/**
 *  @param aLabel:  the label of the polygon mesh to transform
 *  @param x:   the scaling factor along the X-axis
 *  @param y:   the scaling factor along the Y-axis
 *  @param z:   the scaling factor along the Z-axis
 */
//------------------------------------------------------------------------------
void scaleNode(const std::string& aLabel,
    double x,
    double y,
    double z);


//------------------------------------------------------------------------------
/// Rotate a polygon mesh.
/**
 *  @param aLabel:  the label of the polygon mesh to transform
 *  @param anAngle:   the rotation angle in degrees
 *  @param x:   the component of the rotation vector along the X-axis
 *  @param y:   the component of the rotation vector along the Y-axis
 *  @param z:   the component of the rotation vector along the Z-axis
 */
//------------------------------------------------------------------------------
void rotateNode(const std::string& aLabel,
    double anAngle,
    double x,
    double y,
    double z);


//------------------------------------------------------------------------------
/// Rotate a polygon mesh using the yaw, pitch, roll method
/**
 *  @param aLabel:  the label of the polygon mesh to transform
 *  @param yaw: a counterclockwise rotation of yaw degrees about the z-axis
 *  @param pitch: a counterclockwise rotation of yaw degrees about the y-axis
 *  @param roll: a counterclockwise rotation of yaw degrees about the x-axis
 */
//------------------------------------------------------------------------------
void rotateNode(const std::string& aLabel,
    double yaw, double pitch, double roll);


//------------------------------------------------------------------------------
/// Translate a polygon mesh.
/**
 *  @param aLabel:  the label of the polygon mesh to transform
 *  @param x:   the component of the translation vector along the X-axis
 *  @param y:   the component of the translation vector along the Y-axis
 *  @param z:   the component of the translation vector along the Z-axis
 *  @param aUnitOfLength:   the unit of length corresponding to the x, y and z
 *                          parameters. Acceptable values are:
 *                          "um", "micrometre",  "micrometer",
 *                          "mm", "millimetre",  "millimeter",
 *                          "cm", "centimetre",  "centimeter",
 *                          "dm",  "decimetre",  "decimeter",
 *                          "m",   "metre",      "meter",
 *                          "dam", "decametre",  "decameter",
 *                          "hm",  "hectometre", "hectometer",
 *                          "km",  "kilometre",  "kilometer"
 */
//------------------------------------------------------------------------------
void translateNode(const std::string& aLabel,
    double x,
    double y,
    double z,
    const std::string& aUnitOfLength);


//------------------------------------------------------------------------------
/// Use a shear matrix  to transform the node.
/**
 *  @param aLabel:  the label of the polygon mesh to transform
 *  @param yx:   the yx component of the shear matrix
 *  @param zx:   the zx component of the shear matrix
 *  @param xy:   the xy component of the shear matrix
 *  @param zy:   the zy component of the shear matrix
 *  @param xz:   the xz component of the shear matrix
 *  @param yz:   the yz component of the shear matrix
 */
//------------------------------------------------------------------------------
void shearNode(const std::string& aLabel,
               double yx,
               double zx,
               double xy,
               double zy,
               double xz,
               double yz);


//------------------------------------------------------------------------------
/// Replace the 3-D transformation matrix of the overall 3-D scene by
/// an identity matrix.
//------------------------------------------------------------------------------
void resetSceneTransformation();


//------------------------------------------------------------------------------
/// Scale the 3-D scene
/// (all the polygon meshes will be affected but not modified).
/**
 *  @param x:   the scaling factor along the X-axis
 *  @param y:   the scaling factor along the Y-axis
 *  @param z:   the scaling factor along the Z-axis
 */
//------------------------------------------------------------------------------
void scaleScene(double x, double y, double z);


//------------------------------------------------------------------------------
/// Scale the 3-D scene
/// (all the polygon meshes will be affected but not modified).
/**
 *  @param x:   the scaling factor along the X-axis
 *  @param y:   the scaling factor along the Y-axis
 *  @param z:   the scaling factor along the Z-axis
 *  @param aUnitOfLength:   the unit of length corresponding to the x, y and z
 *                          parameters. Acceptable values are:
 *                          "um", "micrometre",  "micrometer",
 *                          "mm", "millimetre",  "millimeter",
 *                          "cm", "centimetre",  "centimeter",
 *                          "dm",  "decimetre",  "decimeter",
 *                          "m",   "metre",      "meter",
 *                          "dam", "decametre",  "decameter",
 *                          "hm",  "hectometre", "hectometer",
 *                          "km",  "kilometre",  "kilometer"
 */
//------------------------------------------------------------------------------
void scaleScene(double x, double y, double z, const std::string& aUnitOfLength);


//------------------------------------------------------------------------------
/// Rotate the 3-D scene
/// (all the polygon meshes will be affected but not modified).
/**
 *  @param anAngle:   the rotation angle in degrees
 *  @param x:   the component of the rotation vector along the X-axis
 *  @param y:   the component of the rotation vector along the Y-axis
 *  @param z:   the component of the rotation vector along the Z-axis
 */
//------------------------------------------------------------------------------
void rotateScene(double anAngle, double x, double y, double z);


//------------------------------------------------------------------------------
/// Rotate the 3-D scene using the yaw, pitch, roll method
/// (all the polygon meshes will be affected but not modified).
/**
 *  @param yaw: a counterclockwise rotation of yaw degrees about the z-axis
 *  @param pitch: a counterclockwise rotation of yaw degrees about the y-axis
 *  @param roll: a counterclockwise rotation of yaw degrees about the x-axis
 */
//------------------------------------------------------------------------------
void rotateScene(double yaw, double pitch, double roll);


//------------------------------------------------------------------------------
/// Translate the 3-D scene
/// (all the polygon meshes will be affected but not modified).
/**
 *  @param x:   the component of the translation vector along the X-axis
 *  @param y:   the component of the translation vector along the Y-axis
 *  @param z:   the component of the translation vector along the Z-axis
 *  @param aUnitOfLength:   the unit of length corresponding to the x, y and z
 *                          parameters. Acceptable values are:
 *                          "um", "micrometre",  "micrometer",
 *                          "mm", "millimetre",  "millimeter",
 *                          "cm", "centimetre",  "centimeter",
 *                          "dm",  "decimetre",  "decimeter",
 *                          "m",   "metre",      "meter",
 *                          "dam", "decametre",  "decameter",
 *                          "hm",  "hectometre", "hectometer",
 *                          "km",  "kilometre",  "kilometer"
 */
//------------------------------------------------------------------------------
void translateScene(double x,
                    double y,
                    double z,
                    const std::string& aUnitOfLength);


//------------------------------------------------------------------------------
/// Accessor on the 3-D scene transformation matrix.
/**
 *  @return the 3-D scene transformation matrix as a 4x4 array
 */
//------------------------------------------------------------------------------
std::vector<std::vector<float> > getSceneTransformationMatrix();


//------------------------------------------------------------------------------
/// Accessor on the transformation matrix of the scengraph's root node.
/**
 *  @return the scengraph's root node transformation matrix as a 4x4 array
 */
//------------------------------------------------------------------------------
std::vector<std::vector<float> > getRootTransformationMatrix();


//------------------------------------------------------------------------------
/// Accessor on the transformation matrix of a given node.
/**
 *  @param aLabel:  the label of the polygon mesh
 *  @return the scengraph's root node transformation matrix as a 4x4 array
 */
//------------------------------------------------------------------------------
std::vector<std::vector<float> > getNodeLocalTransformationMatrix(
    const std::string& aLabel);


//------------------------------------------------------------------------------
/// Accessor on the transformation matrix of a given node.
/**
 *  @param aLabel:  the label of the polygon mesh
 *  @return the scengraph's root node transformation matrix as a 4x4 array
 */
//------------------------------------------------------------------------------
std::vector<std::vector<float> > getNodeWorldTransformationMatrix(
    const std::string& aLabel);


//------------------------------------------------------------------------------
/// Set the 3-D scene transformation matrix.
/**
 *  @param aMatrix: the transformation matrix as a 4x4 array
 */
//------------------------------------------------------------------------------
void setSceneTransformationMatrix(
    const std::vector<std::vector<float> >& aMatrix);


//------------------------------------------------------------------------------
/// Set the transformation matrix of the scengraph's root node.
/**
 *  @param aMatrix: the transformation matrix as a 4x4 array
 */
//------------------------------------------------------------------------------
void setRootTransformationMatrix(
    const std::vector<std::vector<float> >& aMatrix);


//------------------------------------------------------------------------------
/// Set the transformation matrix of a given node.
/**
 *  @param aLabel:  the label of the polygon mesh
 *  @param aMatrix: the transformation matrix as a 4x4 array
 */
//------------------------------------------------------------------------------
void setNodeTransformationMatrix(
    const std::string& aLabel,
    const std::vector<std::vector<float> >& aMatrix);


//------------------------------------------------------------------------------
/// Set the Hounsfield value corresponding to the material properties of
/// a polygon mesh.
/**
 *  @param aLabel:  the label of the polygon mesh
 *  @param HU:      the Hounsfield value
 */
//------------------------------------------------------------------------------
void setHU(const std::string& aLabel, short HU);


//------------------------------------------------------------------------------
/// Set the Hounsfield value corresponding to the material properties of
/// a polygon mesh.
/**
 *  @param aLabel:  the label of the polygon mesh
 *  @param HU:      the Hounsfield value
 */
//------------------------------------------------------------------------------
void setHounsfieldUnit(const std::string& aLabel, short HU);


//------------------------------------------------------------------------------
/// Set the Hounsfield value corresponding to the material properties of
/// a polygon mesh.
/**
 *  @param aLabel:  the label of the polygon mesh
 *  @param HU:      the Hounsfield value
 */
//------------------------------------------------------------------------------
void setHounsfieldValue(const std::string& aLabel, short HU);


//------------------------------------------------------------------------------
/// Set the chemical element (or element) corresponding
/// to the material properties of a polygon mesh.
/**
 *  @param aLabel:  the label of the polygon mesh
 *  @param Z:       the atomic number (or Z number) corresponding to the element
 */
//------------------------------------------------------------------------------
void setElement(const std::string& aLabel, unsigned short Z);


//------------------------------------------------------------------------------
/// Set the chemical element (or element) corresponding
/// to the material properties of a polygon mesh.
/**
 *  @param aLabel:  the label of the polygon mesh
 *  @param aName:   the symbol or name corresponding to the element
 */
//------------------------------------------------------------------------------
void setElement(const std::string& aLabel, const std::string& aName);


//------------------------------------------------------------------------------
/// Set the mixture corresponding to the material properties of a polygon mesh.
/// Don't forget to set the density of the material.
/**
 *  @param aLabel:      the label of the polygon mesh
 *  @param aMixture:    the details about the mixture. It is given as a sequence
 *                      of element symbol & relative weight, e.g.
 *                      Ti90Al6V4.
 */
//------------------------------------------------------------------------------
void setMixture(const std::string& aLabel, const std::string& aMixture);


//------------------------------------------------------------------------------
/// Set the mixture corresponding to the material properties of a polygon mesh.
/// Don't forget to set the density of the material.
/**
 *  @param aLabel:      the label of the polygon mesh
 *  @param aZNumberSet:      the array of Z numbers
 *  @param aWeightSet:      the corresponding weights
 */
//------------------------------------------------------------------------------
void setMixture(const std::string& aLabel,
                const std::vector<int>& aZNumberSet,
                const std::vector<double>& aWeightSet);


//------------------------------------------------------------------------------
/// Set the compound corresponding to the material properties of a polygon mesh.
/// Don't forget to set the density of the material.
/**
 *  @param aLabel:      the label of the polygon mesh
 *  @param aCompound:   the details about the compound. It is given as
 *                      a sequence of element symbol & number of atoms, e.g.
 *                      H2O for water and SiC for silicon carbide.
 */
//------------------------------------------------------------------------------
void setCompound(const std::string& aLabel, const std::string& aCompound);


//------------------------------------------------------------------------------
/// Set the mass attenuation coefficient corresponding to
/// the material properties of a polygon mesh.
/// Don't forget to set the density of the material.
/**
 *  @param aLabel:          the label of the polygon mesh
 *  @param aCoefficient:    the mass attenuation coefficient
 *  @param aUnit:           the unit corresponding to aCoefficient.
 *                          Acceptable values are:
 *                          "cm2/g" and "cm2.g-1"
 */
//------------------------------------------------------------------------------
void setMassAttenuationCoefficient(const std::string& aLabel,
                                   double aCoefficient,
                                   const std::string& aUnit);


//------------------------------------------------------------------------------
/// Set the linear attenuation coefficient corresponding
/// to the material properties of a polygon mesh.
/**
 *  @param aLabel:          the label of the polygon mesh
 *  @param aCoefficient:    the liner attenuation coefficient
 *  @param aUnit:           the unit corresponding to aCoefficient.
 *                          Acceptable values are:
 *                          "cm-1"
 */
//------------------------------------------------------------------------------
void setLinearAttenuationCoefficient(const std::string& aLabel,
                                     double aCoefficient,
                                     const std::string& aUnit);


//------------------------------------------------------------------------------
/// Set the linear attenuation coefficient corresponding
/// to the material properties of a polygon mesh.
/**
 *  @param aLabel:          the label of the polygon mesh
 *  @param aCoefficient:    the liner attenuation coefficient
 *  @param aUnit:           the unit corresponding to aCoefficient.
 *                          Acceptable values are:
 *                          "cm-1"
 */
//------------------------------------------------------------------------------
void setMu(const std::string& aLabel,
           double aCoefficient,
           const std::string& aUnit);


//------------------------------------------------------------------------------
/// Set the density corresponding to the material properties of a polygon mesh.
/**
 *  @param aLabel:      the label of the polygon mesh
 *  @param aDensity:    the density
 *  @param aUnit:       the unit corresponding to aDensity.
 *                      Acceptable values are:
 *                      "g/cm3" and "g.cm-3"
 */
//------------------------------------------------------------------------------
void setDensity(const std::string& aLabel,
                double aDensity,
                const std::string& aUnit);


//------------------------------------------------------------------------------
/// Accessor on the density corresponding
/// to the material properties of a polygon mesh.
/**
 *  @param aLabel:  the label of the polygon mesh
 *  @return the density of the polygon mesh's material in g/cm3
 */
//------------------------------------------------------------------------------
double getDensity(const std::string& aLabel);


//------------------------------------------------------------------------------
/// Accessor on the mass attenuation coefficient at a given energy
/// corresponding to the material properties of a polygon mesh.
/**
 *  @param aLabel:          the label of the polygon mesh
 *  @param anEnergy:        the photon energy of interest
 *  @param aUnitOfEnergy:   the unit of energy corresponding to anEnergy.
 *                          Acceptable values are:
 *                          "electronvolt", "eV",
 *                          "kiloelectronvolt", "keV",
 *                          "megaelectronvolt", "MeV"
 *  @return the mass attenuation coefficient of the polygon mesh's material
 *          in cm2/g
 */
//------------------------------------------------------------------------------
double getMassAttenuationCoefficient(const std::string& aLabel,
                                     double anEnergy,
                                     const std::string& aUnitOfEnergy);


//------------------------------------------------------------------------------
/// Accessor on the linear attenuation coefficient at a given energy
/// corresponding to the material properties of a polygon mesh.
/**
 *  @param aLabel:          the label of the polygon mesh
 *  @param anEnergy:        the photon energy of interest
 *  @param aUnitOfEnergy:   the unit of energy corresponding to anEnergy.
 *                          Acceptable values are:
 *                          "electronvolt", "eV",
 *                          "kiloelectronvolt", "keV",
 *                          "megaelectronvolt", "MeV"
 *  @return the linear attenuation coefficient of the polygon mesh's material
 *          in cm-1
 */
//------------------------------------------------------------------------------
double getLinearAttenuationCoefficient(const std::string& aLabel,
                                       double anEnergy,
                                       const std::string& aUnitOfEnergy);


//------------------------------------------------------------------------------
/// Accessor on the material label of a polygon mesh.
/**
 *  @param aLabel:  the label of the polygon mesh
 *  @return the label of the material
 */
//------------------------------------------------------------------------------
std::string getMaterialLabel(const std::string& aLabel);


//------------------------------------------------------------------------------
/// Create an OpenGL context (the window won't be shown).
/**
 *  @param aWindowID:   the numerical ID of the context to create
 *                      (default value: -1, means that the ID will be
 *                      automatically generated)
 *  @param aRendererMajorVersion: Select the major version of the renderer.
 *                    (default value: 3)
 *  @param aRendererMajorVersion: Select the minor version of the renderer.
 *                    (default value: 2)
 */
//------------------------------------------------------------------------------
void createOpenGLContext(int aWindowID = -1,
		int aRendererMajorVersion = 3,
		int aRendererMinorVersion = 2);


//------------------------------------------------------------------------------
/// Create an OpenGL context and display it in a window
/**
 *  @param aWindowID:   the numerical ID of the context to create
 *                      (default value: -1, means that the ID will be
 *                      automatically generated)
 *  @param aRenderer: Select the renderer to use, e.g. OpenGL or Vulkan.
 *                    (default value: OPENGL)
 *  @param aRendererMajorVersion: Select the major version of the renderer.
 *                    (default value: 3)
 *  @param aRendererMajorVersion: Select the minor version of the renderer.
 *                    (default value: 2)
 *  @param aVisibilityFlag: flag controling if the window should be visible (1)
 *                          or hidden (0). (default value: 0)
 */
//------------------------------------------------------------------------------
#ifndef __APPLE__
void createWindow(int aWindowID = -1,
		int aVisibilityFlag = 0,
		const std::string& aRenderer = "OPENGL",
		int aRendererMajorVersion = 3,
		int aRendererMinorVersion = 2);
#else // __APPLE__
void createWindow(int aWindowID = -1,
		int aVisibilityFlag = 0,
		const std::string& aRenderer = "OPENGL",
		int aRendererMajorVersion = 2,
		int aRendererMinorVersion = 1);
#endif // __APPLE__


//------------------------------------------------------------------------------
/// Create an OpenGL context
/**
 *  @param aRenderer: Select the renderer to use, e.g. OpenGL or Vulkan.
 *                    (default value: OPENGL)
 *  @param aWindowID:   the numerical ID of the context to create
 *                      (default value: -1, means that the ID will be
 *                      automatically generated)
 *  @param aRendererMajorVersion: Select the major version of the renderer.
 *                    (default value: 3)
 *  @param aRendererMajorVersion: Select the minor version of the renderer.
 *                    (default value: 2)
 *  @param aVisibilityFlag: flag controling if the window should be visible (1)
 *                          or hidden (0). (default value: 0)
 */
//------------------------------------------------------------------------------
void createNewContext(const std::string& aRenderer = "OPENGL",
    int aWindowID = -1,
		int aVisibilityFlag = 0,
		int aRendererMajorVersion = 3,
		int aRendererMinorVersion = 2);


//------------------------------------------------------------------------------
/// Create an OpenGL context and display it in a window
/**
 *  @param aWidth:      the number of pixels along the X-axis
 *  @param aHeight:     the number of pixels along the Y-axis
 *  @param aWindowID:   the numerical ID of the corresponding context
 *                      (default value: -1, means that the active context
 *                      will be used)
 */
//------------------------------------------------------------------------------
void setWindowSize(int aWidth, int aHeight, int aWindowID = -1);


//------------------------------------------------------------------------------
/// 3-D visualisation of the 3-D scene (source, detector, and scanned objects).
/// Note that there is no interactive loop running.
/**
 *  @param aSceneRotationFlag:  true if the 3-D scene has to be rotated with
 *                              the arc-ball method, false otherwise
 *                              (default value: true)
 *  @param aWindowID:   the numerical ID of the corresponding context
 *                      (default value: -1, means that the active context
 *                      will be used)
 */
//------------------------------------------------------------------------------
void displayScene(bool aSceneRotationFlag = true, int aWindowID = -1);


//------------------------------------------------------------------------------
/// 3-D visualisation of the 3-D scene (source, detector, and scanned objects).
/// Note that there is interactive loop running.
/// Keys are:
/// - Q/Escape: to quit the event loop (does not close the window)
/// - B: display/hide the X-ray beam
/// - W: display the polygon meshes in solid or wireframe
/// - N: display the X-ray image in negative or positive
/// - L: switch lighting on/off
/// - D: display/hide the X-ray detector
/// - V: display/hide normal vectors
/**
 *  @param aWindowID:   the numerical ID of the corresponding context
 *                      (default value: -1, means that the active context
 * will be used)
 */
//------------------------------------------------------------------------------
void renderLoop(int aWindowID = -1);


//------------------------------------------------------------------------------
/// Call this function when the user starts an arc-ball rotation
/// (e.g. left-mouse button click in the 3-D visualisation window).
/**
 *  @param x:   the cursor x-axis position in the viewport coordinate system
 *  @param y:   the cursor y-axis position in the viewport coordinate system
 */
//------------------------------------------------------------------------------
void startArcBallRotation(double x, double y);


//------------------------------------------------------------------------------
/// Call this function when the user stops an arc-ball rotation
/// (e.g. release the left-mouse button click in the 3-D visualisation window).
//------------------------------------------------------------------------------
void stopArcBallRotation();


//------------------------------------------------------------------------------
/// Check if arc-ball rotation is currently in use.
/**
 *  @return true if arc-ball rotation is currently in use, false otherwise
 */
//------------------------------------------------------------------------------
bool usingArcBallRotation();


//------------------------------------------------------------------------------
/// Call this function when the user moves the mouse
/**
 *  @param x:   the cursor x-axis position in the viewport coordinate system
 *  @param y:   the cursor y-axis position in the viewport coordinate system
 *  @param aViewportWidth:  the size of the viewport along the x-axis
 *  @param aViewportHeight: the size of the viewport along the y-axis
 */
//------------------------------------------------------------------------------
void cursorPositionCallback(double x,
                            double y,
                            int aViewportWidth,
                            int aViewportHeight);


//------------------------------------------------------------------------------
/// Call this function when the user scrolls
/**
 *  @param xoffset: the scroll offset along the x-axis (not used)
 *  @param yoffset: the scroll offset along the y-axis (used for zooming in
 *                  and out)
 */
//------------------------------------------------------------------------------
void scrollCallback(double xoffset, double yoffset);


void setZoom(float aZoomValue);


float getZoom();


void setSceneRotationMatrix(const std::vector<double>& aRotationMatrix);


std::vector<double> getSceneRotationMatrix();


//------------------------------------------------------------------------------
/// Make an OpenGL context visible and display a window.
/**
 *  @param aWindowID:   the numerical ID of the corresponding context
 *                      (default value: -1, means that the active context
 *                      will be used)
 */
//------------------------------------------------------------------------------
void showWindow(int aWindowID = -1);


//------------------------------------------------------------------------------
/// Hide a window.
/**
 *  @param aWindowID:   the numerical ID of the corresponding context
 *                      (default value: -1, means that the active context
 *                      will be used)
 */
//------------------------------------------------------------------------------
void hideWindow(int aWindowID = -1);


//------------------------------------------------------------------------------
/// Set window background colour.
/**
 *  @param R: the red colour [0, 1]
 *  @param G: the green colour [0, 1]
 *  @param B: the blue colour [0, 1]
 *  @param aWindowID:   the numerical ID of the corresponding context
 *                      (default value: -1, means that the active context
 *                      will be used)
 */
//------------------------------------------------------------------------------
void setWindowBackGroundColour(float R, float G, float B, int aWindowID = -1);


//------------------------------------------------------------------------------
/// Set window background colour.
/**
 *  @param R: the red colour [0, 1]
 *  @param G: the green colour [0, 1]
 *  @param B: the blue colour [0, 1]
 *  @param aWindowID:   the numerical ID of the corresponding context
 *                      (default value: -1, means that the active context
 *                      will be used)
 */
//------------------------------------------------------------------------------
void setWindowBackGroundColor(float R, float G, float B, int aWindowID = -1);


//------------------------------------------------------------------------------
/// Take screenshot.
/**
 *  @param aWindowID:   the numerical ID of the corresponding context
 *                      (default value: -1, means that the active context
 *                      will be used)
 *  @return:            the 2D image in RGB
 */
//------------------------------------------------------------------------------
const std::vector<std::vector<std::vector< float> > >& takeScreenshot(int aWindowID = -1);


//------------------------------------------------------------------------------
/// Get the latest screenshot.
/**
 *  @return:            the 2D image in RGB
 */
//------------------------------------------------------------------------------
const std::vector<std::vector<std::vector< float> > >& getLatestScreenshot();


//------------------------------------------------------------------------------
/// Close and destroy a given window or OpenGL context.
//------------------------------------------------------------------------------
void destroyWindow(int aWindowID = -1);


//------------------------------------------------------------------------------
/// Close and destroy all the windows and OpenGL contexts that have been created.
//------------------------------------------------------------------------------
void destroyAllWindows(void);


//------------------------------------------------------------------------------
/// Use a point source.
//------------------------------------------------------------------------------
void usePointSource();


//------------------------------------------------------------------------------
/// Use a parallel source (e.g. to mimic a source that is extremely far from
/// the scanned object and detector).
//------------------------------------------------------------------------------
void useParallelBeam();


//------------------------------------------------------------------------------
/// Use a parallel source (e.g. to mimic a source that is extremely far from
/// the scanned object and detector).
//------------------------------------------------------------------------------
void useParallelSource();


//------------------------------------------------------------------------------
/// Set the size of the focal spot of the X-ray generator
/**
 *  @param x:   size along the x-axis
 *  @param y:   size along the y-axis
 *  @param z:   size along the z-axis
 *  @param aUnitOfLength:   the unit of length. Acceptable values are:
 *                          "um", "micrometre",  "micrometer",
 *                          "mm", "millimetre",  "millimeter",
 *                          "cm", "centimetre",  "centimeter",
 *                          "dm",  "decimetre",  "decimeter",
 *                          "m",   "metre",      "meter",
 *                          "dam", "decametre",  "decameter",
 *                          "hm",  "hectometre", "hectometer",
 *                          "km",  "kilometre",  "kilometer"
 *  @return the corresponding numerical value
 */
//------------------------------------------------------------------------------
//void setFocalSpot(x, y, z, aUnitOfLength);


//------------------------------------------------------------------------------
/// Empty the beam spectrum.
//------------------------------------------------------------------------------
void resetBeamSpectrum();


//------------------------------------------------------------------------------
/// Use a monochromatic beam spectrum (i.e. one single energy).
/**
 *  @param anEnergy:            the incident photon energy
 *  @param aUnitOfEnergy:       the unit of energy corresponding to anEnergy.
 *                              Acceptable values are:
 *                              "electronvolt", "eV",
 *                              "kiloelectronvolt", "keV",
 *                              "megaelectronvolt", "MeV"
 *  @param aNumberOfPhotons:    the number of incident photons
 */
//------------------------------------------------------------------------------
void setMonoChromatic(double anEnergy,
                      const std::string& aUnitOfEnergy,
                      double aNumberOfPhotons);


//------------------------------------------------------------------------------
/// Add an energy bin to the beam spectrum (useful to generate polychromatism).
/**
 *  @param anEnergy:            the incident photon energy
 *  @param aUnitOfEnergy:       the unit of energy corresponding to anEnergy.
 *                              Acceptable values are:
 *                              "electronvolt", "eV",
 *                              "kiloelectronvolt", "keV",
 *                              "megaelectronvolt", "MeV"
 *  @param aNumberOfPhotons:    the number of incident photons
 */
//------------------------------------------------------------------------------
void addEnergyBinToSpectrum(double anEnergy,
                            const std::string& aUnitOfEnergy,
                            double aNumberOfPhotons);


//------------------------------------------------------------------------------
/// Load the incident beam energy spectrum from a TSV file.
/**
 *  @param aFileName:           name of the file to load
 *  @param aUnitOfEnergy:       the unit of energy corresponding to anEnergy.
 *                              Acceptable values are:
 *                              "electronvolt", "eV",
 *                              "kiloelectronvolt", "keV",
 *                              "megaelectronvolt", "MeV"
 *  @param aNormalisationFlag:  true to normalise the total energy to 1,
 *                              false otherwise
 */
//------------------------------------------------------------------------------
void loadSpectrumFromTSV(const std::string& aFileName,
                         const std::string& aUnitOfEnergy,
                         bool aNormalisationFlag);


//------------------------------------------------------------------------------
/// Accessor on the energy bins of the beam spectrum.
/**
 *  @param aUnitOfEnergy:   the unit of energy corresponding to
 *                          the returned vector. Acceptable values are:
 *                          "electronvolt", "eV",
 *                          "kiloelectronvolt", "keV",
 *                          "megaelectronvolt", "MeV"
 *  @return the list of energy bins in aUnitOfEnergy
 */
//------------------------------------------------------------------------------
std::vector<double> getEnergyBins(const std::string& aUnitOfEnergy);


//------------------------------------------------------------------------------
/// Accessor on the number of photons per energy bin of the beam spectrum.
/**
 *  @return the list of number of photons
 */
//------------------------------------------------------------------------------
std::vector<double> getPhotonCountEnergyBins();


//--------------------------------------------------------------------------
/// Accessor on a total energy of the beam when the detector response is applied.
/**
 *  @return the total energy
 */
//--------------------------------------------------------------------------
double getTotalEnergyWithDetectorResponse();


//------------------------------------------------------------------------------
/// Save the polygon mesh of a given node.
/**
 *  @param aLabel:          the label of the polygon mesh
 *  @param aFileName:   the name of the output file
 *  (default: means that the filename will be
 *  automatically generated and the file saved in
 *  the current path)
 */
//------------------------------------------------------------------------------
void saveSTLfile(const std::string& aLabel,
		const std::string& aFileName = std::string());


//------------------------------------------------------------------------------
/// Save the last X-ray image that has been computed.
/**
 *  @param aFileName:   the name of the output file
 *  (default: means that the filename will be
 *  automatically generated and the file saved in
 *  the current path)
 *  @param useCompression:  use data compression is possible (default: true)
 */
//------------------------------------------------------------------------------
void saveLastXRayImage(const std::string& aFileName = std::string(),
    bool useCompression = true);


//------------------------------------------------------------------------------
/// Save the last L-buffer that has been computed.
/**
 *  @param aFileName:   the name of the output file
 *              (default: means that the filename will be
 *              automatically generated and the file saved in
 *              the current path)
 *  @param useCompression:  use data compression is possible (default: true)
 */
//------------------------------------------------------------------------------
void saveLastLBuffer(const std::string& aFileName = std::string(),
    bool useCompression = true);


//------------------------------------------------------------------------------
/// Save the last cumulated L-buffer that has been computed.
/**
 *  @param aFileName:   the name of the output file
 *              (default: means that the filename will be
 *              automatically generated and the file saved in
 *              the current path)
 *  @param useCompression:  use data compression is possible (default: true)
 */
//------------------------------------------------------------------------------
void saveLastCumulatedLBuffer(const std::string& aFileName = std::string(),
    bool useCompression = true);


    //------------------------------------------------------------------------------
    /// Save the last sinogram that has been computed.
    /**
     *  @param aFileName:   the name of the output file
     *                      (default: 0 means that the filename will be
     *                      automatically generated and the file saved in
     *                      the current path)
     *  @param useCompression:  use data compression is possible (default: true)
     */
    //------------------------------------------------------------------------------
    void saveLastSinogram(const std::string& aFileName = std::string(),
        bool useCompression = true);


//------------------------------------------------------------------------------
/// Save the last projection set that has been computed.
/**
 *  @param aFileName:   the name of the output file
 *                      (default: 0 means that the filename will be
 *                      automatically generated and the file saved in
 *                      the current path)
 *  @param useCompression:  use data compression is possible (default: true)
 */
//------------------------------------------------------------------------------
void saveLastProjectionSet(const std::string& aFileName = std::string(),
    bool useCompression = true);


//------------------------------------------------------------------------------
/// Enable artefact filtering on GPU (it is fast but can be inaccurate).
//------------------------------------------------------------------------------
void enableArtefactFilteringOnGPU(void);


//------------------------------------------------------------------------------
/// Enable artefact filtering on GPU (it is fast but can be inaccurate).
//------------------------------------------------------------------------------
void enableArtifactFilteringOnGPU(void);


//------------------------------------------------------------------------------
/// Enable artefact filtering on CPU (can be extremely slow as it makes use
/// of ray-tracing).
//------------------------------------------------------------------------------
void enableArtefactFilteringOnCPU(void);


//------------------------------------------------------------------------------
/// Enable artefact filtering on CPU (can be extremely slow as it makes use
/// of ray-tracing).
//------------------------------------------------------------------------------
void enableArtifactFilteringOnCPU(void);


//------------------------------------------------------------------------------
/// Disable artefact filtering altogether.
//------------------------------------------------------------------------------
void disableArtefactFiltering(void);


//------------------------------------------------------------------------------
/// Disable artefact filtering altogether.
//------------------------------------------------------------------------------
void disableArtifactFiltering(void);


//------------------------------------------------------------------------------
/// Accessor on the max radius of the L-buffer artefact correction filter
/**
 *  @return the radius in number of pixels
 */
//------------------------------------------------------------------------------
unsigned int getMaxRadiusLbufferArtefactFilter();


//------------------------------------------------------------------------------
/// Set the max radius of the L-buffer artefact correction filter
/**
 *  @param aRadius: the radius in number of pixels
 */
//------------------------------------------------------------------------------
void setMaxRadiusLbufferArtefactFilter(unsigned int aRadius);


//------------------------------------------------------------------------------
/// Check whether the GPU implementation of the L-buffer artefact correction filter
/// is enabled
/**
 *  @return true if the filter is active, otherwise return false
 */
//------------------------------------------------------------------------------
bool isArtefactFilteringOnGPUEnabled();


//------------------------------------------------------------------------------
/// Check whether the CPU implementation of the L-buffer artefact correction filter
/// is enabled
/**
 *  @return true if the filter is active, otherwise return false
 */
//------------------------------------------------------------------------------
bool isArtefactFilteringOnCPUEnabled();


//------------------------------------------------------------------------------
/// Accessor on the numerical value corresponding to a unit of energy.
/**
 *  @param aUnitOfEnergy:   the unit of energy.
 *                          Acceptable values are:
 *                          "electronvolt", "eV",
 *                          "kiloelectronvolt", "keV",
 *                          "megaelectronvolt", "MeV"
 *  @return the corresponding numerical value
 */
//------------------------------------------------------------------------------
double getUnitOfEnergy(const std::string& aUnitOfEnergy);


//------------------------------------------------------------------------------
/// Accessor on the numerical value corresponding to a unit of length.
/**
 *  @param aUnitOfLength:   the unit of length. Acceptable values are:
 *                          "um", "micrometre",  "micrometer",
 *                          "mm", "millimetre",  "millimeter",
 *                          "cm", "centimetre",  "centimeter",
 *                          "dm",  "decimetre",  "decimeter",
 *                          "m",   "metre",      "meter",
 *                          "dam", "decametre",  "decameter",
 *                          "hm",  "hectometre", "hectometer",
 *                          "km",  "kilometre",  "kilometer"
 *  @return the corresponding numerical value
 */
//------------------------------------------------------------------------------
double getUnitOfLength(const std::string& aUnitOfLength);


//------------------------------------------------------------------------------
/// Compute the X-ray projection corresponding to the environment that
/// has previously been set, i.e.
/// - Detector position
/// - Detector orientation
/// - Detector size and resolution
/// - Source position
/// - Source shape
/// - Beam spectrum
/// - Scanned object geometries
/// - Scanned object material properties
/**
 *  @param anIntegrateEnergyFlag: if true the energy fluence is returned,
 *                                otherwise the number of photons is returned
 *                                (default value: true)
 *  @return the corresponding X-ray image
 */
//------------------------------------------------------------------------------
std::vector<std::vector<float> > computeXRayImage(bool anIntegrateEnergyFlag = true);


//------------------------------------------------------------------------------
/// Compute the L-buffer of a polygon mesh corresponding to the environment that
/// has previously been set, i.e.
/// - Detector position
/// - Detector orientation
/// - Detector size and resolution
/// - Source position
/// - Source shape
/// - Scanned object geometry
/**
 *  @param aLabel:  the label of the polygon mesh
 *  @return the corresponding L-buffer
 */
//------------------------------------------------------------------------------
std::vector<std::vector<float> > computeLBuffer(const std::string& aLabel);


//------------------------------------------------------------------------------
/// Compute the sinogram corresponding to the environment that
/// has previously been set, i.e.
/// - Detector position
/// - Detector orientation
/// - Detector size and resolution
/// - Source position
/// - Source shape
/// - Beam spectrum
/// - Scanned object geometries
/// - Scanned object material properties
/// Note that the rotation vector is the same as the up-vector of the detector.
/**
 *  @param x:   the position of the rotation centre along the X-axis
 *  @param y:   the position of the rotation centre along the Y-axis
 *  @param z:   the position of the rotation centre along the Z-axis
 *  @param aUnitOfLength:   the unit of length corresponding to the x, y and z
 *                          parameters. Acceptable values are:
 *                          "um", "micrometre",  "micrometer",
 *                          "mm", "millimetre",  "millimeter",
 *                          "cm", "centimetre",  "centimeter",
 *                          "dm",  "decimetre",  "decimeter",
 *                          "m",   "metre",      "meter",
 *                          "dam", "decametre",  "decameter",
 *                          "hm",  "hectometre", "hectometer",
 *                          "km",  "kilometre",  "kilometer"
 *  @param aNumberOfAngle:  the total number of projections in the sinogram
 *  @param anAngleOffset:   the angle in degrees between
 *                          two successive projections
 *  @return the corresponding sinogram
 */
//------------------------------------------------------------------------------
std::vector<std::vector<std::vector<float> > > computeSinogram(
    double x,
    double y,
    double z,
    const std::string& aUnitOfLength,
    unsigned int aNumberOfAngle,
    double anAngleOffset);


//------------------------------------------------------------------------------
/// Compute the projection set corresponding to the environment that
/// has previously been set, i.e.
/// - Detector position
/// - Detector orientation
/// - Detector size and resolution
/// - Source position
/// - Source shape
/// - Beam spectrum
/// - Scanned object geometries
/// - Scanned object material properties
/// Note that the rotation vector is the same as the up-vector of the detector.
/**
 *  @param x:   the position of the rotation centre along the X-axis
 *  @param y:   the position of the rotation centre along the Y-axis
 *  @param z:   the position of the rotation centre along the Z-axis
 *  @param aUnitOfLength:   the unit of length corresponding to the x, y and z
 *                          parameters. Acceptable values are:
 *                          "um", "micrometre",  "micrometer",
 *                          "mm", "millimetre",  "millimeter",
 *                          "cm", "centimetre",  "centimeter",
 *                          "dm",  "decimetre",  "decimeter",
 *                          "m",   "metre",      "meter",
 *                          "dam", "decametre",  "decameter",
 *                          "hm",  "hectometre", "hectometer",
 *                          "km",  "kilometre",  "kilometer"
 *  @param aNumberOfAngle:  the total number of projections in the projection set
 *  @param anAngleOffset:   the angle in degrees between
 *                          two successive projections
 *  @return the corresponding projection set
 */
//------------------------------------------------------------------------------
std::vector<std::vector<std::vector<float> > > computeProjectionSet(
    double x,
    double y,
    double z,
    const std::string& aUnitOfLength,
    unsigned int aNumberOfAngle,
    double anAngleOffset);


//------------------------------------------------------------------------------
/// Accessor on the last X-ray image that has been computed.
/**
 *  @return the last X-ray image
 */
//------------------------------------------------------------------------------
std::vector<std::vector<float> > getLastXRayImage();


//------------------------------------------------------------------------------
/// Accessor on the last L-buffer that has been computed.
/**
 *  @return the last L-buffer
 */
//------------------------------------------------------------------------------
std::vector<std::vector<float> > getLastLBuffer();


//------------------------------------------------------------------------------
/// Accessor on the last sinogram that has been computed.
/**
 *  @return the last sinogram
 */
//------------------------------------------------------------------------------
std::vector<std::vector<std::vector<float> > > getLastSinogram();


//------------------------------------------------------------------------------
/// Accessor on the last projection set that has been computed.
/**
 *  @return the last projection set
 */
//------------------------------------------------------------------------------
std::vector<std::vector<std::vector<float> > > getLastProjectionSet();


//------------------------------------------------------------------------------
/// Accessor on the width of a given image.
/**
 *  @param anImage: the image
 *  @return the width of the image (in number of pixels)
 */
//------------------------------------------------------------------------------
int getImageWidth(const std::vector<std::vector<float> >& anImage);


//------------------------------------------------------------------------------
/// Accessor on the height of a given image.
/**
 *  @param anImage: the image
 *  @return the height of the image (in number of pixels)
 */
//------------------------------------------------------------------------------
int getImageHeght(const std::vector<std::vector<float> >& anImage);


//------------------------------------------------------------------------------
/// Accessor on the j-th row of pixels of a given image.
/**
 *  @param anImage: the image
 *  @param j:       the row number
 *  @return the j-th row of pixels
 */
//------------------------------------------------------------------------------
std::vector<float> getImageRow(const std::vector<std::vector<float> >& anImage,
                               int j);


//------------------------------------------------------------------------------
/// Accessor on the chemical element's name depending on its Z number.
/**
 *  @param Z:   the atomic number of the element
 *  @return the name of the corresponding element
 */
//------------------------------------------------------------------------------
std::string getElementName(unsigned short Z);


//------------------------------------------------------------------------------
/// Accessor on the chemical element' symbol depending on its Z number.
/**
 *  @param Z:   the atomic number of the element
 *  @return the name of the corresponding element
 */
//------------------------------------------------------------------------------
std::string getElementSymbol(unsigned short Z);


//------------------------------------------------------------------------------
/// Accessor on the chemical element's Z number.
/**
 *  @param anElement:   the name or symbol of the element
 *  @return the Z number of the corresponding element
 */
//------------------------------------------------------------------------------
unsigned short getElementAtomicNumber(const std::string& anElement);


//------------------------------------------------------------------------------
/// Accessor on the chemical element's density.
/**
 *  @param anElement:   the name or symbol of the element
 *  @return the density of the corresponding element (in g / cm3)
 */
//------------------------------------------------------------------------------
double getDensityFromElement(const std::string& anElement);


//------------------------------------------------------------------------------
/// Accessor on the chemical element's density.
/**
 *  @param Z:   the Z number of the element
 *  @return the density of the corresponding element (in g / cm3)
 */
//------------------------------------------------------------------------------
double getDensityFromElement(unsigned short Z);


//------------------------------------------------------------------------------
/// Accessor on the HU's density.
/**
 *  @param HU:   the HU
 *  @return the density of the corresponding HU (in g / cm3)
 */
//------------------------------------------------------------------------------
double getDensityFromHU(double HU);


//------------------------------------------------------------------------------
/// Accessor on the chemical element's mass attenuation.
/**
 *  @param anElement:   the name or symbol of the element
 *  @param anEnergy:        the photon energy of interest
 *  @param aUnitOfEnergy:   the unit of energy corresponding to anEnergy.
 *                          Acceptable values are:
 *                          "electronvolt", "eV",
 *                          "kiloelectronvolt", "keV",
 *                          "megaelectronvolt", "MeV"
 *  @return the mass attenuation of the corresponding element (in cm2/g)
 */
//------------------------------------------------------------------------------
double getMassAttenuationFromElement(const std::string& anElement,
		double anEnergy,
		const std::string& aUnitOfEnergy);


//------------------------------------------------------------------------------
/// Accessor on the chemical element's mass attenuation.
/**
 *  @param Z:   the Z number of the element
 *  @param anEnergy:        the photon energy of interest
 *  @param aUnitOfEnergy:   the unit of energy corresponding to anEnergy.
 *                          Acceptable values are:
 *                          "electronvolt", "eV",
 *                          "kiloelectronvolt", "keV",
 *                          "megaelectronvolt", "MeV"
 *  @return the mass attenuation of the corresponding element (in cm2/g)
 */
//------------------------------------------------------------------------------
double getMassAttenuationFromElement(unsigned short Z,
		double anEnergy,
		const std::string& aUnitOfEnergy);


/// Accessor on the HU's mass attenuation.
/**
 *  @param HU:   the HU
 *  @param anEnergy:        the photon energy of interest
 *  @param aUnitOfEnergy:   the unit of energy corresponding to anEnergy.
 *                          Acceptable values are:
 *                          "electronvolt", "eV",
 *                          "kiloelectronvolt", "keV",
 *                          "megaelectronvolt", "MeV"
 *  @return the density of the corresponding HU (in cm2/g)
 */
//------------------------------------------------------------------------------
double getMassAttenuationFromHU(double HU,
		double anEnergy,
		const std::string& aUnitOfEnergy);


//------------------------------------------------------------------------------
/// Accessor on the mixture's mass attenuation.
/**
 *  @param aMixture:    the details about the mixture. It is given as a sequence
 *                      of element symbol & relative weight, e.g.
 *                      Ti90Al6V4.
 *  @param anEnergy:        the photon energy of interest
 *  @param aUnitOfEnergy:   the unit of energy corresponding to anEnergy.
 *                          Acceptable values are:
 *                          "electronvolt", "eV",
 *                          "kiloelectronvolt", "keV",
 *                          "megaelectronvolt", "MeV"
 *  @return the mass attenuation of the corresponding mixture (in cm2/g)
 */
//------------------------------------------------------------------------------
double getMassAttenuationFromMixture(const std::string& aMixture,
		double anEnergy,
		const std::string& aUnitOfEnergy);


//------------------------------------------------------------------------------
/// Accessor on the compound's mass attenuation.
/**
 *  @param aCompound:   the details about the compound. It is given as
 *                      a sequence of element symbol & number of atoms, e.g.
 *                      H2O for water and SiC for silicon carbide.
 *  @param anEnergy:        the photon energy of interest
 *  @param aUnitOfEnergy:   the unit of energy corresponding to anEnergy.
 *                          Acceptable values are:
 *                          "electronvolt", "eV",
 *                          "kiloelectronvolt", "keV",
 *                          "megaelectronvolt", "MeV"
 *  @return the mass attenuation of the corresponding compound (in cm2/g)
 */
//------------------------------------------------------------------------------
double getMassAttenuationFromCompound(const std::string& aCompound,
		double anEnergy,
		const std::string& aUnitOfEnergy);


/// Accessor on the HU's linear attenuation coefficient.
/**
 *  @param HU:   the HU
 *  @param anEnergy:        the photon energy of interest
 *  @param aUnitOfEnergy:   the unit of energy corresponding to anEnergy.
 *                          Acceptable values are:
 *                          "electronvolt", "eV",
 *                          "kiloelectronvolt", "keV",
 *                          "megaelectronvolt", "MeV"
 *  @return the linear attenuation coefficient (in cm-1)
 */
double getMuFromHU(double HU,
		double anEnergy,
		const std::string& aUnitOfEnergy);

std::vector<std::vector<std::vector< float> > > convertHU2mu(const std::vector<std::vector<std::vector< float> > >& anImage,
    double anEnergy,
    const std::string& aUnitOfEnergy);

/**
void setShiftFilter(double aValue);
void setScaleFilter(double aValue);
double getShiftFilter();
double getScaleFilter();
*/

std::vector<float> rayIntersect(const std::string& aLabel,
    double aRayOriginX, double aRayOriginY, double aRayOriginZ,
    double aRayDirectionX, double aRayDirectionY, double aRayDirectionZ);


std::vector<std::vector<float> > loadImage2D(const std::string& aFileName);

std::vector<std::vector<std::vector<float> > > loadImage3D(const std::string& aFileName);

double computeZNCC(const std::vector<std::vector<std::vector<float> > >& aReferenceImage, const std::vector<std::vector<std::vector<float> > >& aTestImage);
double computeRMSE(const std::vector<std::vector<std::vector<float> > >& aReferenceImage, const std::vector<std::vector<std::vector<float> > >& aTestImage);

double getMean(const std::vector<float>& anImage);
double getStddev(const std::vector<float>& anImage);

double computeZNCC(const std::vector<float>& aReferenceImage, const std::vector<float>& aTestImage);
double computeRMSE(const std::vector<float>& aReferenceImage, const std::vector<float>& aTestImage, bool normalise = false);

double computeRMSE(bool normalise = false);
double computeZNCC();
void loadReference(const std::vector<float>& aReferenceImage);
void loadTest(const std::vector<float>& aTestImage);
void lineariseTest(float aThreshold, float aScalingFactor);

float getMinValue(const std::vector<std::vector<std::vector<float> > >& aImage);
float getMaxValue(const std::vector<std::vector<std::vector<float> > >& aImage);

//void FBO2Thrust(unsigned int aFBO, void* aThrustVector, int anOffset = 0);


#endif
