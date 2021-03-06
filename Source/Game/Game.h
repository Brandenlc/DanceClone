//      Game.h
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

#define GAMESTRING "DanceClone"
#define GAMEVERSION "v0.68"
#define GAMEVERSIONSTRING "DanceClone v0.68"


#include <string>
using std::string;
#include <vector>
using std::vector;
#include <map>
using std::map;

#include <fstream>
using std::ofstream;
using std::ifstream;
using std::endl;
#include "unistd.h" //usleep()

#include <boost/algorithm/string.hpp>

#include "../Platform/OS.h"
using Platform::OS;
using Platform::DirectoryEntry;
#include "../Platform/Tools.h"
#include "../GUI/GUI.h"
using Gooey::GUI;
using Gooey::Container;
using Gooey::Element;
using Gooey::Button;
using Gooey::Image;
using Gooey::Label;
#include "Constants.h"
#include "Sound.h"
#include "Graphics.h"
using DanceClone::Graphics;
#include "Player.h"
#include "Song.h"
#include "SongMenuItem.h"
#include "Decal.h"

namespace DanceClone
{

class Game
{
public:

  enum GameState
  {
    NONE,         //
    TITLE,        // 0
    CHOOSE_NUM_PLAYERS,
    CHOOSE_RECORD_FILE,
    CREDITS,      // 1
    SCORE,        // 2, 9
    SELECT_SONG, // 3
    SELECT_DIFFICULTY, // 4
    STEP_CREATE,  // 5
    PLAY_PREP1,   // 7
    PLAY_PREP2,   // 11
    PLAY,         // 8
    DEBUG,         // 10
    LOADING_SONG
  };

private:
  
  Game(); //disallow empty public ctor 
  
  OS& sys;
  GUI& gui;
  Graphics gfx;
  Sound sound;
  
  GameState state;
  bool gameStateChanged;
  
  vector<Player> players;
  int numPlayers;
  
  map<string, Song> songs;
  string currentSong; // map key
  vector<SongMenuItem> songMenuItems;

  int currentBpmChange;
  int numBpmChanges;
  int currentMeasure;
  int currentBeat;
  int lastAssistBeat; 
  float currentBeatFraction;
  float lastBeatTime;
  float beatTimeElapsedAtPreviousBPMs;
  float beatFractionAtPreviousBPMs;
  unsigned long songStartTime;
  long songTime;
  unsigned long songAbortStartTime;
  unsigned long frameTime;
  long viewportOffset;
  float pixelsPerMsAtCurrentBpm;
  float pixelsLeftToScroll;
  SDL_Surface* songBg;
  //TODO: this is a buggy way to do it, each player object must maintain its own decals.
  // there was a reason why it wasn't implemented that way, but the bullet must be bitten...
  vector<Decal> ratingDecals;
  vector<Decal> comboDecals;
  vector<Decal> okNgDecals;
  
  vector<long> putzes;
  vector<long> wbs;
  vector<long> claps;
  unsigned long frame;
public:

  Game(OS& os, GUI& g);
  bool Init(string configFilePath = "");
  void Cleanup();
  void Run();
  GameState State();
  void RunTitleScreen();
  void RunCreditsScreen();
  void RunDebugScreen();
  void RunChooseNumPlayers();
  void RunChooseRecordFile();
  void RunSelectSong();
  void RunSelectSongv2();
  void RunSelectDifficulty();
  void PreloadSongs();
  void RunLoadingSong();
  void RunPlayPrep();
  void RunPlay();
  void RunPlayCleanup();
  void RunScoreScreen();
  bool CheckAbort();
  void InitialFrame();
  void Frame();
  void PartialFrame(float begin, float end);
  void DrawHomeArrows(Player& p);
  void DrawEnergyBar(Player& p);
  void DrawDecals(Player& p);
  void DrawArrows(Player& p);
  void RateArrows(Player& p);
  void DoAssistTick(Player& p);
  bool CanInterrupt();
};

}
