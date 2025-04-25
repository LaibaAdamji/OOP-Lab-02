#include <iostream>
#include <vector>
#include <string>

class Logger {
private:
    std::vector<std::string> logs;
    static constexpr size_t MAX_LOGS = 1000;

    void addLog(const std::string& severity, const std::string& message) {
        if (logs.size() >= MAX_LOGS) {
            logs.erase(logs.begin());
        }
        logs.push_back("[" + severity + "] " + message);
    }

public:
    void logInfo(const std::string& message) { addLog("INFO", message); }
    void logWarning(const std::string& message) { addLog("WARN", message); }
    void logError(const std::string& message) { addLog("ERROR", message); }

    std::vector<std::string> getLogs(bool isAuthenticated) const {
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
        std::cout << log << std::endl;
    }
    return 0;
}
