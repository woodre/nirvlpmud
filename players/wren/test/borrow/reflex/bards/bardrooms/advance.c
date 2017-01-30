#include "/players/reflex/lib/lib.h"
#include "/players/reflex/lib/include/ansi.h"
inherit ROOM;

realm() { return "NT"; }
query_no_fight(){ return 1; }

void create() {
	::create();

  if(!present("water",this_object())){
  move_object(
    clone_object("/players/reflex/guilds/bards/fountain.c"),
  this_object()); }

  if(!present("star",this_object())){
  move_object(
    clone_object("/players/reflex/guilds/bards/star.c"),
  this_object()); }

  set_short(HIM+"If you wish upon a Star..."+NORM);
  set_long(HIM+
    "Star's Greenery\n"+NORM+
    "This room is filled with lush plants and has a skylight in\n"+
    "the ceiling.  All around you is radiated life and sunlight,\n"+
    "and in the center of it all sits a young girl by a small pool,\n"+
    "dangling one hand into the water somewhat wistfully.  To the\n"+
    "east is the teleport chamber and to the south is the lore\n"+
    "room.\n"
    );
  set_items(([
    "plants" :
    "Many types of plants grace this chamber with their presence.\n",
    "skylight" :
    "Through the skylight rays of sunlight streak in.\n",
    "ceiling" :
    "There is a large skylight in the ceiling.\n",
    ]));
  set_smells(([
    "default" :
    "The smell of fresh soil permeates this room.\n",
    ]));
  set_sounds(([
    "default" :
    "The rustle of leaves can occasionally be heard.\n",
    ]));
  set_exits(([
    "east" : "/players/reflex/guilds/bards/bardrooms/teleport",
    "south" : "/players/reflex/guilds/bards/bardrooms/lore",
    ]));
  set_light(1);
  replace_program(ROOM);
}
