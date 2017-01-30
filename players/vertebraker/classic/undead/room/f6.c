#include <ansi.h>
#include "../lib/guild_defs.h"

inherit G_HALL;

void reset(status arg)
{
   if(arg) return;
   set_light(-5);
   set_short(CEN);
   set_long("\
  This backroom is small and dirty. A large black bed rests in the back\n\
corner of the room, and the bedding is dusty and undisturbed. An iron\n\
empty treasure chest lies open on the floor, covered with rust. A small\n\
golden altar sits across the room from the bed. A pile of blackened ash\n\
sits atop it, apparently magically affixed to the altar.\n");
    set_exits(({
ROOMDIR + "f5", "south" }));
    add_item(({"backroom","bed","corner","bedding","chest","treasure chest",
               "altar","ash","pile","button"}), "");
}

void long(string str)
{
  ::long(str);
  if((int)this_player()->query_attrib("int") < random(100))
    return;
  if(!str || str == "altar")
  {
    write("\
You notice a small red button on the back of the altar.\n");
  }
}

void init()
{
  ::init();
  add_action("cmd_push", "push");
  add_action("cmd_push", "press");
}

int cmd_push(string str)
{
  if(str != "button")
  {
    notify_fail("Push what?\n");
    return 0;
  }
  write("You press the red button.\n");
  say((string)TP->QN + " touches something on the altar.\n");
/*
  if((string)TP->query_guild_name() != "undead" && (string)TP->query_guild_name() != "vampire") {
*/
  if((string)TP->query_guild_name() != "Undead") {
    write("Nothing happens.\n");
    return 1;
  }
  tell_room(TO, HIW + "\
The bed swings away, revealing a secret passage!\n"+NORM);
  add_exit(ROOMDIR + "crypt", "north");
  init();
  return 1;
}
