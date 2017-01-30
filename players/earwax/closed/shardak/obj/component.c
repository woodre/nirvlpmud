/* Changed from verte ansi.h to waxy ansi.h */
/* and tweaked the color some - Linus 7/18/03 */


#include "../include/ansi.h"

int type, Uses;

status id(string str)
{
    if(!type) return str == "component";
    else
      switch(type)
      {
        case 1:
          return (str == "obsidian" || str == "piece" || str == "shardak_obsidian");
          break;
        case 2:
          return str == "flask" || str == "nitropyr";
          break;
        case 3:
          return str == "chalk" || str == "blood chalk" || str == "piece";
          break;
      }
}

query_shardak_component()
{
    return type;
}

void long()
{
    if(type == 1)
      write(BOLD + BLK + "\
A dark black piece of obsidian crafted from the rock\n\
that rests deep within the grotto of Shardak.\n" + NORM);
    else if(type == 2)
      write("\
A tin flask of " + BOLD + RED + "Nitropyr" + NORM + ", an acidic liquid used to expediate\n\
the burning in demonic fires.  " + BOLD + RED +"Nitropyr is actually\n\
extracted demon's blood.\n" + NORM);
    else if(type == 3)
      write("\
A piece of " + RED + "blood-red" + NORM + " chalk, used for writing ages-old\n\
symbols and such into the ground.\n");
    else write("\
Bad clone.  Dest this.\n");

}

Set_Uses(x)
{
    Uses = x;
}

short() 
{
    if(type == 1)
      return "A piece of" + BOLD + BLK + " obsidian" + NORM;
    if(type == 2)
      return "A flask of " + BOLD + RED + "Nitropyr" + NORM;
    if(type == 3)
      return "A piece of " + RED + "blood chalk" + NORM;
    else
      return "Component";
}
      
Add_Uses(x)
{
    Uses += x;
}

query_save_flag()
{
    return 1;
}

set_type(s) { type = s; }

init()
{
/*
    add_action("do_draw","draw");
*/
}

/*
do_draw(string str)
{
    if(str == "darkness")
    {
      if(present("darkness_drawing", environment(this_player())))
      {
        notify_fail("A drawing of darkness has been scrawled here.\n");
        return 0;
      }
      if(this_player()->query_attack())
      {
*/

get() { return 1; }

int
query_weight() { return 1; }

int
query_value() { return 50; }
