/****************************************************************************************************************************
  WeatherBirdFirebase_debug_h
  For ESP32 boards
  Debug macros for the WeatherBirdFirebase

  Based on ESPAsync_WiFiManager_Lite (https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite) is a library 
  Built by Khoi Hoang https://github.com/khoih-prog/ESPAsync_WiFiManager_Lite
  Licensed under MIT license
  
 *****************************************************************************************************************************/

#ifndef WeatherBirdFirebase_debug_h
#define WeatherBirdFirebase_debug_h

#ifdef WBF_DEBUG_OUTPUT
  #define DBG_PORT_WB       WBF_DEBUG_OUTPUT
#else
  #define DBG_PORT_WB       Serial
#endif

// Change _WBF_LOGLEVEL_ to set tracing and logging verbosity
// 0: DISABLED: no logging
// 1: ERROR: errors
// 2: WARN: errors and warnings
// 3: INFO: errors, warnings and informational (default)
// 4: DEBUG: errors, warnings, informational and debug

#ifndef _WBF_LOGLEVEL_
  #define _WBF_LOGLEVEL_       0
#endif

const char WBF_MARK[] = "[WBF] ";

#define WBF_PRINT_MARK   DBG_PORT_WB.print(WBF_MARK)

#define WBF_PRINT        DBG_PORT_WB.print
#define WBF_PRINTLN      DBG_PORT_WB.println


///////////////////////////////////////////

#define WBF_LOGERROR0(x)     if(_WBF_LOGLEVEL_>0) { WBF_PRINT(x); }
#define WBF_LOGERROR(x)      if(_WBF_LOGLEVEL_>0) { WBF_PRINT_MARK; WBF_PRINTLN(x); }
#define WBF_LOGERROR1(x,y)   if(_WBF_LOGLEVEL_>0) { WBF_PRINT_MARK; WBF_PRINT(x); WBF_PRINTLN(y); }
#define WBF_LOGERROR2(x,y,z) if(_WBF_LOGLEVEL_>0) { WBF_PRINT_MARK; WBF_PRINT(x); WBF_PRINT(y); WBF_PRINTLN(z); }
#define WBF_LOGERROR3(x,y,z,w) if(_WBF_LOGLEVEL_>0) { WBF_PRINT_MARK; WBF_PRINT(x); WBF_PRINT(y); WBF_PRINT(z); WBF_PRINTLN(w); }
#define WBF_LOGERROR5(x,y,z,w,xx,yy) if(_WBF_LOGLEVEL_>0) { WBF_PRINT_MARK; WBF_PRINT(x); WBF_PRINT(y); WBF_PRINT(z); WBF_PRINT(w); WBF_PRINT(xx); WBF_PRINTLN(yy); }

///////////////////////////////////////////

#define WBF_LOGWARN0(x)     if(_WBF_LOGLEVEL_>1) { WBF_PRINT(x); }
#define WBF_LOGWARN(x)      if(_WBF_LOGLEVEL_>1) { WBF_PRINT_MARK; WBF_PRINTLN(x); }
#define WBF_LOGWARN1(x,y)   if(_WBF_LOGLEVEL_>1) { WBF_PRINT_MARK; WBF_PRINT(x); WBF_PRINTLN(y); }
#define WBF_LOGWARN2(x,y,z) if(_WBF_LOGLEVEL_>1) { WBF_PRINT_MARK; WBF_PRINT(x); WBF_PRINT(y); WBF_PRINTLN(z); }
#define WBF_LOGWARN3(x,y,z,w) if(_WBF_LOGLEVEL_>1) { WBF_PRINT_MARK; WBF_PRINT(x); WBF_PRINT(y); WBF_PRINT(z); WBF_PRINTLN(w); }
#define WBF_LOGWARN5(x,y,z,w,xx,yy) if(_WBF_LOGLEVEL_>1) { WBF_PRINT_MARK; WBF_PRINT(x); WBF_PRINT(y); WBF_PRINT(z); WBF_PRINT(w); WBF_PRINT(xx); WBF_PRINTLN(yy); }

///////////////////////////////////////////

#define WBF_LOGINFO0(x)     if(_WBF_LOGLEVEL_>2) { WBF_PRINT(x); }
#define WBF_LOGINFO(x)      if(_WBF_LOGLEVEL_>2) { WBF_PRINT_MARK; WBF_PRINTLN(x); }
#define WBF_LOGINFO1(x,y)   if(_WBF_LOGLEVEL_>2) { WBF_PRINT_MARK; WBF_PRINT(x); WBF_PRINTLN(y); }
#define WBF_LOGINFO2(x,y,z) if(_WBF_LOGLEVEL_>3) { WBF_PRINT_MARK; WBF_PRINT(x); WBF_PRINT(y); WBF_PRINTLN(z); }
#define WBF_LOGINFO3(x,y,z,w) if(_WBF_LOGLEVEL_>3) { WBF_PRINT_MARK; WBF_PRINT(x); WBF_PRINT(y); WBF_PRINT(z); WBF_PRINTLN(w); }
#define WBF_LOGINFO5(x,y,z,w,xx,yy) if(_WBF_LOGLEVEL_>2) { WBF_PRINT_MARK; WBF_PRINT(x); WBF_PRINT(y); WBF_PRINT(z); WBF_PRINT(w); WBF_PRINT(xx); WBF_PRINTLN(yy); }

///////////////////////////////////////////

#define WBF_LOGDEBUG0(x)     if(_WBF_LOGLEVEL_>3) { WBF_PRINT(x); }
#define WBF_LOGDEBUG(x)      if(_WBF_LOGLEVEL_>3) { WBF_PRINT_MARK; WBF_PRINTLN(x); }
#define WBF_LOGDEBUG1(x,y)   if(_WBF_LOGLEVEL_>3) { WBF_PRINT_MARK; WBF_PRINT(x); WBF_PRINTLN(y); }
#define WBF_LOGDEBUG2(x,y,z) if(_WBF_LOGLEVEL_>3) { WBF_PRINT_MARK; WBF_PRINT(x); WBF_PRINT(y); WBF_PRINTLN(z); }
#define WBF_LOGDEBUG3(x,y,z,w) if(_WBF_LOGLEVEL_>3) { WBF_PRINT_MARK; WBF_PRINT(x); WBF_PRINT(y); WBF_PRINT(z); WBF_PRINTLN(w); }
#define WBF_LOGDEBUG4(x,y,z,w, xx) if(_WBF_LOGLEVEL_>3) { WBF_PRINT_MARK; WBF_PRINT(x); WBF_PRINT(y); WBF_PRINT(z); WBF_PRINT(w); WBF_PRINTLN(xx); }
#define WBF_LOGDEBUG5(x,y,z,w,xx,yy) if(_WBF_LOGLEVEL_>3) { WBF_PRINT_MARK; WBF_PRINT(x); WBF_PRINT(y); WBF_PRINT(z); WBF_PRINT(w); WBF_PRINT(xx); WBF_PRINTLN(yy); }

///////////////////////////////////////////

#endif    //WeatherBird_Prov_Debug_h
