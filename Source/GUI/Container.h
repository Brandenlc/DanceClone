//      Container.h
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

#ifndef GUI_CONTAINER_H
#define GUI_CONTAINER_H

#include <vector>
using std::vector;

#include "../Platform/LOG.H"
#include "../Platform/Tools.h"

#include "Element.h"
#include "Image.h"
#include "Button.h"
#include "Container.h"
#include "Label.h"

namespace Gooey
{
class Container;

class Container : public Element
{
protected:


public:
  vector<Container> containers;
  vector<Image> images;
  vector<Button> buttons;
  vector<Label> labels;
  
  
  Container();
  Container(int _x, int _y, int _w, int _h, int ta = -1);
  virtual ~Container();
  
  vector<Container>& Containers();  
  vector<Image>& Images();
  vector<Button>& Buttons();
  vector<Button> AllButtons();
  vector<Label>& Labels();
  void Add(Element& e);
  bool Clicked(int testx, int testy, int channel);
  void CursorClear();
  void CursorAt(int testx, int testy);
};


}

#endif
