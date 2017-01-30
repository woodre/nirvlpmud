#include "defs.h"

inherit "/obj/armor.c";

int running;

void reset(int arg)
{
  set_name("boots");
  set_ac(1);
  set_type("boots");
  set_short(HIG+"Boots of Snail Speed"+NORM);
  set_long("This pair of boots was an early cousin of the Boots of\n"+
           "Sprinting.  They are a dull green and glow slightly.\n");
  set_weight(1);
  set_value(5);
}
void init()
{
  ::init();
  add_action("cmd_hurry","up");
  add_action("cmd_hurry","down");
  add_action("cmd_hurry","north");
  add_action("cmd_hurry","west");
  add_action("cmd_hurry","east");
  add_action("cmd_hurry","south");
}
int cmd_hurry(string str)
{
  if(!worn) return 0;
  switch(random(7))
  {
    case 0: write("Hold your horses!\n");
            break;
    case 1: write("What's the rush?\n");
            break;
    case 2: write("Where's the fire?\n");
            break;
    case 3: write("Don't hassle me!  We'll get there eventually.\n");
            break;
    case 4: write("Hurry hurry hurry...Nobody takes their time anymore.\n");
            break;
    case 5: write("You move "+query_verb()+" as fast as you can.\n");
            break;
     case 6: write("With turtle speed, you rush "+query_verb()+"!\n");
            break;
  }
  return 1;
}
int wear(string str)
{
  if(::wear(str))
  {
    move_object(this_object(),this_player());
    return 1;
  }
}
