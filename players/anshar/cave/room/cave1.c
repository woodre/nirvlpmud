#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */
#include "/players/anshar/closed/mydef.h"

inherit "room/room";

reset(arg)
{
  if (arg) return 0;
  set_light(1);
  short_desc="A Cave Entrance";
  long_desc =
"     The area at the mouth of this large cave is littered with debris \n\
and refuse consisting of a scattered assortment of bones, shattered   \n\
weapons and armor, and other undefineable objects. A stench as if of  \n\
rotten meat permeates the air. The mouth of the cave is darkened by an\n\
outcropping of stone overhanging it.\n";
  items =
  ({
    "mouth",       "The entrance of a large cave, a light flickers deep within",
    "cave",        "The entrance of a large cave, a light flickers deep within",
    "entrance",    "The entrance of a large cave, a light flickers deep within",
    "debris",      "Garbage is haphazardly strewn about the area",
    "refuse",      "Garbage is haphazardly strewn about the area",
    "garbage",     "Garbage is haphazardly strewn about the area",
    "bones",       "An assortment of cleaned bones, some of them show signs of having been gnawed on",
    "weapons",     "Shattered armaments, now useless",
    "armor",       "Shattered armaments, now useless",
    "outcropping", "A stone outcropping darkens the cave entrance",
  });
}

init()
{
  ::init();
  add_action ("enter_cave", "enter");
}

enter_cave(str)
{
  if(!str) return 0;
  if(str != "cave")
  {
    write("Enter what?\n");
    return 1;
  }
  if (this_player()->query_level() < 15)
  {
    write("You feel a sense of forboding and decide not to enter the cave.\n");
    return 1;
  }
  write("You enter into the darkness of the cave.\n");
  this_player()->move_player("cave#"+CROOM+"cave2");
  return 1;
}
