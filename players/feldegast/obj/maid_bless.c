/*
File: maid_bless.c
Author: Feldegast
Date: 3-18-02
Description:
  A blessing for the maiden's locket found in Caladon.
Should not be stackable with other non-guild wc bonuses.
*/
#include "/players/feldegast/defines.h"

string name;

void start(string n)
{
  name = n;
}

string extra_look()
{
  return (string)environment()->query_name()+" has been inspired by "+name;
}

int id(string str)
{
  return str == "generic_wc_bonus" || str == "maiden_bonus" || str=="magic_bonus";
}


int gen_wc_bonus()
{
  if(!random(10))
    tell_object(environment(), "The memory of "+name+" inspires you to greater heights of skill!\n");
  return 1;
}

drop() {
  if(environment()->is_dieing()) destruct(this_object());
  else return 1;
}
