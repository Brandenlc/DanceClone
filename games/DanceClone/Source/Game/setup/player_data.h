// player_data
//


class player_data
{
private:

public:
  int base_arrow;
  vector<arrow> arrows;
  int longest_combo;
  int combo;
  int boo;
  int good;
  int perfect;
  vector<unsigned int> current_ratable_arrow;
  vector<unsigned int> next_ratable_arrow;
  int first_visible_arrow;
  int last_visible_arrow;
  int next_offscreen_arrow;
  int num_arrows;
  int up_control;
  int down_control;
  int left_control;
  int right_control;
    
  player_data();
  void init();
  int find_next_ratable_arrow(unsigned int direction);
};

player_data::player_data() :
current_ratable_arrow(4), // one for each direction. change to support dance-double
next_ratable_arrow(4) 
{
}

void player_data::init()
{
  arrows.clear();
  base_arrow = 0;
  longest_combo = 0;
  combo = 0;
  boo = 0;
  good = 0;
  perfect = 0;
  current_ratable_arrow[0]=current_ratable_arrow[1]=current_ratable_arrow[2]=current_ratable_arrow[3] = -1;
  next_ratable_arrow[0]=next_ratable_arrow[1]=next_ratable_arrow[2]=next_ratable_arrow[3] = -1;
  last_visible_arrow = -1;
  first_visible_arrow = -1;
  next_offscreen_arrow = -1;
  
  //TODO: control data in vector?
  up_control = 0;
  down_control = 0;
  left_control = 0;
  right_control = 0;
}

int player_data::find_next_ratable_arrow(unsigned int direction)
{
  return -1;
}
