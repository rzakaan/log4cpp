#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

enum LogLevel { NONE = 0, FATAL = 1, ERROR = 2, ALERT = 3, WARNING = 4, INFO = 5, DEBUG = 6, TRACE = 7 };

#define LOG_TRACE   Logger(LogLevel::TRACE)
#define LOG_DEBUG   Logger(LogLevel::DEBUG)
#define LOG_INFO    Logger(LogLevel::INFO)
#define LOG_WARNING Logger(LogLevel::WARNING)
#define LOG_ERROR   Logger(LogLevel::ERROR)
#define LOG_ALERT   Logger(LogLevel::ALERT)
#define LOG_FATAL   Logger(LogLevel::FATAL)

class Logger {
    ofstream logFile;
    LogLevel curLogLevel;

    string level_to_str(LogLevel level) {
        switch (level) {
            case TRACE:
                return "TRACE";
            case DEBUG:
                return "DEBUG";
            case INFO:
                return "INFO";
            case WARNING:
                return "WARNING";
            case ERROR:
                return "ERROR";
            case FATAL:
                return "FATAL";
            default:
              return "UNKNOWN";
        }
    }

    inline std::string getLogLevelColorStr(const LogLevel &selectedLogLevel_) {
        switch (selectedLogLevel_) {
        case FATAL:
            return "\033[41m";
        case ERROR:
            return "\033[31m";
        case ALERT:
            return "\033[35m";
        case WARNING:
            return "\033[33m";
        case INFO:
            return "\x1b[32m";
        case DEBUG:
            return "\x1b[94m";
        case TRACE:
            return "\x1b[36m";
        default:
            return "";
        }
    }
    
    void init(const string& fname) {
        curLogLevel = TRACE;
        logFile.open(fname, ios::app);
        if (!logFile.is_open()) {
            std::cerr << "error: opening log file" << endl;
        }
    }

public:
    Logger() { init("logfile"); }
    Logger(const string& fname) { init(fname); }
    
    ~Logger() {
        logFile.close();
    }

    void log(LogLevel level, const string& message) {
        
        if (curLogLevel > level) return;

        time_t now = time(0);
        tm* timeinfo = localtime(&now);
        char timestamp[20];

        strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", timeinfo);

        string color = getLogLevelColorStr(level);

        ostringstream logEntry;
        logEntry << "" << timestamp << " " << level_to_str(level) << " : " << message << endl;
        cout << color << logEntry.str();
        if (logFile.is_open() && true) {
            logFile << logEntry.str();
            logFile.flush();
        }
    }

    Logger& operator<<(const string& message) {
        log(DEBUG, message);
        return *this;
    }

};
