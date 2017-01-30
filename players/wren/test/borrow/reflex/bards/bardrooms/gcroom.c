#include "/players/reflex/lib/lib.h"
#define tp this_player()->query_name()
inherit ROOM;

realm() { return "NT"; }
query_no_fight(){ return 1; }

void create() {

  if(!present("board",this_object())){
  move_object(
    clone_object("/players/reflex/guilds/bards/boards/gcboard.c"),
  this_object()); }

	::create();
  set_short(HIM+"A very merry place."+NORM);
  set_long(HIM+
    "The Bard Guild Commander Room\n"+NORM+
    "THIS IS A PLACEHOLDER DESCRIPT FOR NOW!\n"+
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
    "west" : "/players/reflex/guilds/bards/bardrooms/teleport",
    ]));
  set_light(1);
  replace_program(ROOM);

}
init(){
 ::init();
   if(this_player())
  if(present("bard_obj", this_player()))
    if(present("bard_obj", this_player())->
    query_bard_level() < 10){ write("You are not a Guild Commander.\n");
    move_object(this_player(),"/players/reflex/guilds/bards/bardrooms/teleport.c");
    tell_room(environment(this_player()),tp+
        " is escorted out of the Guild Commander room.\n");
    return 1;
    }
}
