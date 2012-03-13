//      Image.cpp
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

#include "Image.h"

namespace Gooey
{


Image::Image(SDL_Surface* s) :
  surface(s)
{
}

Image::Image(SDL_Surface* s, int _x, int _y, int _w, int _h, int t) :
  Element(_x, _y, _w, _h, true, true, false, "", t),
  surface(s)
{
}

bool Image::Clicked(int testx, int testy)
{
  return false;
}

}
