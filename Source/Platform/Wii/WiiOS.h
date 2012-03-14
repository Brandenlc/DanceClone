//      WiiOS.h
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
#ifndef WIIPLATFORM_H
#define WIIPLATFORM_H

#include "../OS.h"

#include <gccore.h>
#include <fat.h>
#include <dirent.h>
#include <unistd.h>

#include "WiiVideo.h"
#include "WiiInput.h"
       
namespace Platform
{

class WiiOS : public OS
{
private:
  static void WiiResetPressed();
  static void WiiPowerPressed();
  static void WiimotePowerPressed(s32 chan);

public:
  WiiOS();
  void Init();
  void Cleanup();
  void Pump();
  vector<DirectoryEntry> ReadDirectory(string path);
};

}
#endif
