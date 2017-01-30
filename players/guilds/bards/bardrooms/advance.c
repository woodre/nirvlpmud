#include "/players/guilds/bards/bard_lib/lib.h"
#include <ansi.h>
inherit ROOM;

realm() { return "NT"; }
query_no_fight(){ return 1; }

void create() {
	::create();

  if(!present("water",this_object())){
  move_object(
    clone_object("/players/guilds/bards/fountain.c"),
  this_object()); }

  if(!present("star",this_object())){
  move_object(
    clone_object("/players/guilds/bards/star.c"),
  this_object()); }

  set_short(HIM+"Star's Pool"+NORM);
  set_long(HIM+
    "Star's Pool\n"+NORM+
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
    "east" : "/players/guilds/bards/bardrooms/teleport",
    "south" : "/players/guilds/bards/bardrooms/lore",
    ]));
  set_light(1);
  replace_program(ROOM);
}
