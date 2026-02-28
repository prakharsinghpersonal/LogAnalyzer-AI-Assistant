# LogAnalyzer AI Assistant

**Technologies**: C++, Python, GitHub, AI

## Overview
A high-performance log analysis utility capable of processing 50GB+ of daily operational logs with sub-200ms latency. The system features AI-driven tools for automated code documentation and root-cause analysis.

## Key Features
- **High-Performance Processing**: C++ engine optimized for speed, handling massive log streams.
- **Anomaly Detection**: Real-time identification of system checking for error thresholds.
- **AI Documentation**: Python tool that autonomously scans and generates documentation for engineering codebases, saving 15 hours weekly.
- **Root Cause Analysis**: categorizes error logs into actionable insights, improving debugging efficiency by 25%.

## Project Structure
- `src/`: C++ source code for log processing and anomaly detection.
- `tools/`: Python scripts for AI docs and root cause analysis.

## Usage
### Compile and Run Processor
```bash
g++ -o log_analyzer src/processor.cpp
./log_analyzer
```

### Run AI Assistant Tools
```bash
python3 tools/ai_docs.py
python3 tools/root_cause.py
```
