//      LOG.H
//      
//      Copyright 2012 Carl Lefrançois <carl.lefrancois@gmail.com>
//      
//      This program is free software; you can redistribute it and/or modify
//      it under the terms of the GNU General Public License as published by
//      the Free Software Foundation; either version 2 of the License, or
//      (at your option) any later version.
//      
//      This program is distributed in the hope that it will be useful,
//      but WITHOUT ANY WARRANTY; without even the implied warranty of
//      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//      GNU General Public License for more details.
//      
//      You should have received a copy of the GNU General Public License
//      along with this program; if not, write to the Free Software
//      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
//      MA 02110-1301, USA.



//ultra cheap logging
#ifndef LOG_H
#define LOG_H

#include <iostream>
using std::cerr;
using std::cout;
using std::endl;
#include <fstream>
using std::ofstream;
using std::ifstream;
#include <cstdlib>

static ofstream logFile;

#define DEBUG_OFF 0
#define DEBUG_BASIC 1
#define DEBUG_MINOR 2
#define DEBUG_DETAIL 3
#define DEBUG_GUTS 4
#define LOG_LEVEL DEBUG_BASIC
#define SAFE_LOGGING

#ifdef SAFE_LOGGING
  #define LOG(lev, content) if (LOG_LEVEL >= lev) \
                            { logFile.open("debug", std::ios_base::app); \
                              logFile << content; \
                              logFile.close(); \
                            }
                          
  #define INIT_LOG  logFile.open("debug", std::ios_base::trunc); \
                    logFile.close();

  #define CLOSE_LOG 
  #define FLUSH_LOG
#else
  #define LOG(lev, content) if (LOG_LEVEL >= lev) { logFile << content; }
  
  #define INIT_LOG  logFile.open("debug", std::ios_base::trunc);  \
                    logFile.close(); \
                    logFile.open("debug", std::ios_base::app);
                    
  #define CLOSE_LOG logFile.close();
  #define FLUSH_LOG logFile.close(); logFile.open("debug", std::ios_base::app);
#endif


#endif
