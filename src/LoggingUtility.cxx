#ifndef LOGGING_UTILITY_CXX_
#define LOGGING_UTILITY_CXX_

// LoggingUtility
#include "LoggingUtility.h"

// STL includes
#include <ctime>
#include <cstdio>
#include <time.h>
#include <iostream>
#include <iomanip>

// ============================================================================

LoggingUtility ::
LoggingUtility()
{
};

// ============================================================================

LoggingUtility ::
~LoggingUtility()
{
	os << std::endl;
	fprintf(stderr, "%s", os.str().c_str());
	fflush(stderr);
};

// ============================================================================

std::ostringstream& LoggingUtility :: 
print(ELogLvl level)
{
  os << " " << TimeNow();
  os << SetColor(level);
  os << " [" << ToString(level) << "] ";
  os << Color("reset");
	return os;
};

// ============================================================================

ELogLvl& LoggingUtility :: 
ReportingLevel()
{ 
    static ELogLvl reportingLevel = kDEBUG4;
    return reportingLevel;
};

// ============================================================================

std::string LoggingUtility ::
SetColor(ELogLvl level)
{
  static const std::string colors[] = { Color("red"), Color("yellow"), 
                                        Color("dgreen"), Color("blue"), 
                                        Color("lightblue"), Color("lightblue"),
                                        Color("lightblue"), Color("lightblue") };
  return colors[level];
};

// ============================================================================

std::string LoggingUtility ::
ToString(ELogLvl level)
{
	static const char* const buffer[] = { "ERROR", "WARNING", "INFO", "DEBUG",
                                        "DEBUG1", "DEBUG2", "DEBUG3", "DEBUG4" };
  return buffer[level];
};

// =============================================================================

ELogLvl LoggingUtility ::
FromString(const std::string& level)
{
  if (level == "DEBUG4")
      return kDEBUG4;    
  if (level == "DEBUG3")
      return kDEBUG3;
  if (level == "DEBUG2")
      return kDEBUG2;
  if (level == "DEBUG1")
      return kDEBUG1;
  if (level == "DEBUG")
      return kDEBUG;
  if (level == "INFO")
      return kINFO;
  if (level == "WARNING")
      return kWARNING;
  if (level == "ERROR")
      return kERROR;
  LoggingUtility().print(kWARNING) << "Unknown logging level '" << level << "'. Using INFO level as default.";
  return kINFO;
};

// =============================================================================

std::string LoggingUtility ::
TimeNow()
{
  time_t t = time(0);
  struct tm *now = localtime(&t);
  int year = now->tm_year + 1900;
  int month = now->tm_mon + 1;
  int day = now->tm_mday;
  int hour = now->tm_hour;
  int minute = now->tm_min;
  int second = now->tm_sec + 1;

  char date[50]; sprintf(date, "%02i-%02i-%i %02i:%02i:%02i", day, month, year, hour, minute, second);
  
  std::string result(date);
  
  return std::string(date);
};

// =============================================================================

const std::string& LoggingUtility::Color( const std::string& c ) 
{
  // human readable color strings
  static std::string gClr_none         = "" ;
  static std::string gClr_white        = "\033[1;37m";  // white
  static std::string gClr_black        = "\033[30m";    // black
  static std::string gClr_blue         = "\033[34m";    // blue
  static std::string gClr_red          = "\033[1;31m" ; // red
  static std::string gClr_yellow       = "\033[1;33m";  // yellow
  static std::string gClr_darkred      = "\033[31m";    // dark red
  static std::string gClr_darkgreen    = "\033[32m";    // dark green
  static std::string gClr_darkyellow   = "\033[33m";    // dark yellow
                                  
  static std::string gClr_bold         = "\033[1m"    ; // bold 
  static std::string gClr_black_b      = "\033[30m"   ; // bold black
  static std::string gClr_lblue_b      = "\033[1;34m" ; // bold light blue
  static std::string gClr_cyan_b       = "\033[0;36m" ; // bold cyan
  static std::string gClr_lgreen_b     = "\033[1;32m";  // bold light green
                                  
  static std::string gClr_blue_bg      = "\033[44m";    // blue background
  static std::string gClr_red_bg       = "\033[1;41m";  // white on red background
  static std::string gClr_whiteonblue  = "\033[1;44m";  // white on blue background
  static std::string gClr_whiteongreen = "\033[1;42m";  // white on green background
  static std::string gClr_grey_bg      = "\033[47m";    // grey background

  static std::string gClr_reset  = "\033[0m"; // reset

  if (c.compare("white") == 0)         return gClr_white; 
  if (c.compare("blue") == 0)         return gClr_blue; 
  if (c.compare("black") == 0)        return gClr_black; 
  if (c.compare("lightblue") == 0)      return gClr_cyan_b;
  if (c.compare("yellow") == 0)         return gClr_yellow; 
  if (c.compare("red") == 0)         return gClr_red; 
  if (c.compare("dred") == 0)         return gClr_darkred; 
  if (c.compare("dgreen") == 0)         return gClr_darkgreen; 
  if (c.compare("lgreenb") == 0)        return gClr_lgreen_b;
  if (c.compare("dyellow") == 0)        return gClr_darkyellow; 
  if (c.compare("bold") == 0)           return gClr_bold; 
  if (c.compare("bblack") == 0)         return gClr_black_b; 
  if (c.compare("blue_bgd") == 0)       return gClr_blue_bg; 
  if (c.compare("red_bgd") == 0)       return gClr_red_bg; 
  if (c.compare("white_on_blue") == 0) return gClr_whiteonblue; 
  if (c.compare("white_on_green") == 0) return gClr_whiteongreen; 
  if (c.compare("reset") == 0)          return gClr_reset;
  std::cout << "Unknown color " << c << std::endl;

  return gClr_none;
}; 

#endif
/**< END LOGGING_UTILITY_CXX_ */
