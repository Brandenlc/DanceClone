//TODO: .ini for rating times
//      Constants.cpp
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

#include "Constants.h"

namespace DanceClone
{

Constants constants;

const char* Constants::difficultyText[] = {"Beginner", "Easy", "Medium", "Hard", "Challenge"};

void Constants::Init(string ConfigFilePath)
{
  LOG(DEBUG_MINOR, "DanceClone::Constants::Init()" << endl)
  arrowsHitAnimMs = 300.0;
  numDifficulties = 5;
  songStartOffset = 105;

  goalOffset = 0;
  maxPlayers = 2;
  playerArrowColumnWidth = 65;
  playerArrowFieldMargin = 20;
  
  preStartDelay = 3000;
  songAbortDelay = 2000;
  jumpAllowDelay = 80;
  booDelay = 250;
  goodDelay = 150;
  greatDelay = 100;
  perfectDelay = 50;
  marvellousDelay = 25;
  freezeFailDelay = 250;
  freezeLengthAllow = 25;
  // how many pixels before the end of a freeze arrow the player is
  //  allowed to lift off without failing the freeze

  #ifdef LINUX
  musicFileRoot = "../Music/";  // to avoid potential of music data ending up in git repository.  you probably want to change this if actually planning to use on Linux :)
  #endif
  #ifdef WII
  musicFileRoot = "Music/";
  #endif
  
  baseFileButtonTag = 1024;
  
  pixelsPerMsAt1Bpm = 0.0;
  
  bannerSize = 128;
  bannerMiniZoomFactor = 0.3;

  maxRecordFile = 4;
}

}
