#ifndef __Logger_h
#define __Logger_h


//******************************************************************************
//  Include
//******************************************************************************
#include <string>
#include <fstream>
#include <iostream>


//******************************************************************************
//  namespace
//******************************************************************************
namespace gVirtualXRay {


class Logger;

extern Logger LOGGER;

class Logger
{
public:
    Logger(const char* aFileName = "gvxr.log");
    Logger(const std::string& aFileName = "gvxr.log");
    ~Logger();

    bool is_open() const;
    void open(const std::string& aFileName);
    void close();

    const std::string& getFilename() const;
    const std::string& getFname() const;

    std::ostream& logNow(const std::string& aMessage);
    std::ostream& logError(const std::string& aMessage);
    std::ostream& logWarning(const std::string& aMessage);

protected:
    std::string getNow() const;

    Logger& operator=(const Logger& aLogger);
    Logger(const Logger& aLogger);


    std::ofstream m_output;
    std::string m_filename;
};


}


#endif // __Logger_h
