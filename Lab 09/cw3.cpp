#include <iostream>
#include <vector>
#include <string>
using namespace std

class Logger {
private:
    vector<string> logs;
    static constexpr size_t MAX_LOGS = 1000;

    void addLog(const string& severity, const string& message) {
        if (logs.size() >= MAX_LOGS) {
            logs.erase(logs.begin());
        }
        logs.push_back("[" + severity + "] " + message);
    }

public:
    void logInfo(const string& message) { addLog("INFO", message); }
    void logWarning(const string& message) { addLog("WARN", message); }
    void logError(const string& message) { addLog("ERROR", message); }

    vector<string> getLogs(bool isAuthenticated) const {
        if (!isAuthenticated) return {};
        return logs;
    }
};

int main() {
    Logger logger;
    logger.logInfo("System started");
    logger.logWarning("Low memory");
    logger.logError("Disk full");
    auto logs = logger.getLogs(true);
    for (const auto& log : logs) {
        cout << log << endl;
    }
    return 0;
}
