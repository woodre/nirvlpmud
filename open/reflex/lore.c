#include "/players/reflex/lib/lib.h"
inherit ROOM;

realm() { return "NT"; }
query_no_fight(){ return 1; }

void create() {
	::create();

  if(!present("tuyen",this_object())){
  move_object(
    clone_object("/players/reflex/guilds/bards/tuyen.c"),
  this_object()); }

  set_short(HIM+"Let me tell you a story...."+NORM);
  set_long(HIM+
    "The Bard Lore Chamber\n"+NORM+
    "The Lore room is a pleasant chamber filled with shelf upon\n"+
    "shelf of scrolls and books.  The western wall is covered with\n"+
    "maps of both Ryllian and Nirvana.  In the eastern corner sits\n"+
    "Tuyen, the song master of the Bards.  In the center of the room\n"+
    "is a large leather bound book.  To the east is the Common\n"+
    "room and to the north is Star's Greenery.\n"+
    "Commands: maps, books and scrolls.\n"
    );
  set_items(([
    "floor" :
    "The floor is made from a beautiful mahogany wood.\n",
    "scrolls" :
    "The room is filled with shelf upon shelf of scrolls.\n",
    "book" :
    "A large leather bound book filled with the lore of the city of\n"+
    "Ryllian.\n",
    "maps" :
    "The west wall is covered with maps.  Type <maps> for help.\n",
    ]));
  set_smells(([
    "default" :
    "The musty smell of old paper.\n",
    ]));
  set_sounds(([
    "default" :
    "It is silent here.\n",
    ]));
  set_exits(([
    "east" : "/players/reflex/guilds/bards/bardrooms/common",
    "north" : "/players/reflex/guilds/bards/bardrooms/advance",
    ]));
  set_light(1);
  replace_program(ROOM);
}
