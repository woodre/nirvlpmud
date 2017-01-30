#define NAME "Anshar"
#define DEST "room/orc_vall"

#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */

id(str) { return str == "path"; }

short() { return HIG+"A worn path"+NORM; }

long()
{
  write("The worn path winds away out of sight to the south.\n");
  write("There is no telling where it will lead you, if you \n");
  write("simply walk the path.\n");
}

init()
{
  add_action("walk", "walk");
}

walk(str)
{
  if(!str || str != "path")
  {
    write("Walk what?\n");
    return 1;
  }
  write("You leave down the path.\n");
  this_player()->move_player("along the path#players/anshar/forest/room/path1");
  return 1;
}

reset(arg)
{
  if(arg) return;
  move_object(this_object(),DEST);
}

is_castle(){return 1;}
