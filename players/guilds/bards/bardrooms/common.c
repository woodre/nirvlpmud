#include "/players/guilds/bards/bard_lib/lib.h"
#include <ansi.h>
#define tp this_player()->query_name()
inherit ROOM;

realm() { return "NT"; }
query_no_fight(){ return 1; }

void create() {

  if(!present("book",this_object())){
  move_object(
    clone_object("/players/guilds/bards/boards/bard_news.c"),
  this_object()); }

	::create();
  set_short(HIM+"The Bard Common Room"+NORM);
  set_long(HIM+
    "The Bard Common Room\n"+NORM+
    "The common room of the Bards Guild is a pleasant chamber\n"+
    "constructed entirely from mahogany wood.  It is filled with\n"+
    "large chairs and comfortable couches.  A large fireplace in\n"+
    "built into the northern wall, while a spiral staircase is set\n"+
    "against the southern one.  To the east is the lockers and\n"+
    "charity room, while the door to the west leads to the lore\n"+
    "and equipment chamber.  A beautiful wooden sign hangs against\n"+
    "the west wall amidst various paintings.\n"
    );
  set_items(([
    "floor" :
    "The floor is made from a beautiful mahogany wood.\n",
    "fireplace" :
    "A large fire, blazing in the hearth in the northern wall.\n",
    "chairs" :
    "One of several large mahogany chairs.\n",
    "wood" :
    "A deep, beuatiful dark mahogany wood imported from the forest\n"+
    "of dreams.\n",
    "mahogany" :
    "A deep, beuatiful dark mahogany wood imported from the forest\n"+
    "of dreams.\n",
    "couches" :
    "One of several large comfortable couches.\n",
    "staircase" :
    "A spiral staircase leading up the Alliance chamber.\n",
    "door" :
    "The door to the west leads to the lore and equipment chamber.\n",
    "sign" :
    "The sign reads: The Common Room of the Bards of Ryllian.\n",
    "paintings" :
    "Many large and exquisite paintings cover the west wall.\n",
    ]));
  set_smells(([
    "default" :
    "The smell of burning pine fills the air from the fireplace.\n",
    ]));
  set_sounds(([
    "default" :
    "You hear the crackling of the fire.\n",
    ]));
  set_exits(([
    "west" : "/players/guilds/bards/bardrooms/lore",
    "east" : "/players/guilds/bards/bardrooms/charity",
    "north" : "/players/guilds/bards/bardrooms/teleport",
    "south" : "/players/guilds/bards/bardrooms/enterance",
    ]));
  set_light(1);
  replace_program(ROOM);
}

init(){
 ::init();
if(!present("instrument",this_player()))  {
  write("You get the brief image of a blue circle before\n"+
     "\n"+BLU+
    " * * * * *  B O O M  * * * * *\n"+NORM+
    "\nYour body flies through space.\nYou find yourself somewhere new.\n");
  say(tp+" bounces off the Circle of Warding.\n");
  move_object(this_player(),"/room/church");
  tell_room(environment(this_player()), tp+" falls screaming from the sky.\n"+
      "THUD.\n");
  return 1;
}
}
