#ifndef ANOMALY_DETECT_H
#define ANOMALY_DETECT_H

#include <string>
#include <vector>
#include <map>
#include <algorithm>

// Structure to hold log entry data
struct LogEntry {
    long long timestamp;
    std::string level;
    std::string module;
    std::string message;
};

// Class for detecting anomalies in log streams
class AnomalyDetector {
private:
    std::map<std::string, int> module_error_counts;
    const int ERROR_THRESHOLD = 50;

public:
    AnomalyDetector() {}

    // Analyze a batch of logs for anomalies
    std::vector<std::string> scan(const std::vector<LogEntry>& entries) {
        std::vector<std::string> report;
        module_error_counts.clear();

        for (const auto& entry : entries) {
            if (entry.level == "ERROR" || entry.level == "CRITICAL") {
                module_error_counts[entry.module]++;
            }
        }

        for (const auto& [module, count] : module_error_counts) {
            if (count > ERROR_THRESHOLD) {
                report.push_back("High Error Rate: Module " + module + " exceeded threshold (" + std::to_string(count) + ")");
            }
        }
        return report;
    }

    // Detect patterns (mock implementation of AI logic)
    bool isRootCauseCandidate(const LogEntry& entry) {
        // Simple heuristic: specific keywords often indicate root causes
        return (entry.message.find("timeout") != std::string::npos || 
                entry.message.find("deadlock") != std::string::npos ||
                entry.message.find("segfault") != std::string::npos);
    }
};

#endif // ANOMALY_DETECT_H
