inherit "/obj/generic_heal.c";
#include "/players/softly/closed/ansi.h"

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("snake oil");
  add_alias("oil");
  add_alias("snake");
  set_short(YEL+"Snake Oil"+NORM);
  set_long("A small brown bottle with a hand written\n\
label that reads 'Snake Oil',\n");
  set_type("heal");
  set_msg("\You uncork the bottle and quickly gulp the\n\
nasty tasting oil.  You involuntarily cringe!\n\
The bottle magically disappears.\n");
  set_msg2(" quickly gulps the snake oil.\n");
  add_cmd("drink");
  add_cmd("gulp");
  set_heal(0,0); 
  set_charges(1);
  set_stuff(0);
  set_value(200);
}
short(){return YEL+"Snake Oil"+NORM+" ["+charges+"]"; }
