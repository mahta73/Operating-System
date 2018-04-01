  #include <iostream>

  class Log {
  public:
    enum Level : unsigned int {
      LevelError = 0, LevelWarning, LevelInfo
    };
  private:
    Level m_LogLevel;
  public:
    void SetLevel(int level) {
      m_LogLevel = LevelWarning;
    }

    void Error (const char* message) {
      if ( m_LogLevel >= LevelError)
      std::cout << "[Error: ] " << message << std::endl;
    }

    void Warn (const char* message) {
      if ( m_LogLevel >= LevelWarning)
      std::cout << "[Warning: ] " << message << std::endl;
    }

    void Info (const char* message) {
      if ( m_LogLevel >= LevelInfo)
      std::cout << "[Info: ] " << message << std::endl;
    }
  };

  int main() {
    Log log;
    log.SetLevel(Log::LevelWarning);
    log.Error("Hello");
    log.Warn("Hello");
    log.Info("Hello");
    std::cin.get();
  }
