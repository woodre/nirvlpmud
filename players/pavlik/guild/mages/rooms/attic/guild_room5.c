#include "/players/pavlik/guild/mages/rooms/ROOMS"
#include <ansi.h>
#define tp this_player()
inherit "room/room";

static object obj;

string spells;

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="The Mage's Tower";
  long_desc=
   "You are in the Mage's Chamber.  This chamber is at the very top of the\n"+
   "Tower.  Sparkling gemstones of all types are embedded along the walls\n"+
   "reflecting the sunlight to create marvelous displays.  There is a tall\n"+
   "silver mirror on the north wall, and a window on the opposite wall\n"+
   "provides a splendid view of the realms.  A thick carpet with the Mage's\n"+
   "dragon emblem covers the floor.  You feel a strange warmth emanating from\n"+
   "the walls.  This entire chamber pulses with Magic.  You are home.\n";

  items=({
   "gemstones",
	"Various precious stones of incalcuable wealth are embedded along the\n"+
	"walls of this chamber.  The gems twinkle mystically",
   "wall",
	"The curved walls of this chamber are decorated with precious gemstones",
   "mirror",
	"A full-length silver mirror.  You gaze at the mirror and straighten\n"+
	"your robes and smooth out that annoying cow-lick.\n"+
	"You look marvelous",
   "window",
	"A small window provides an excellent portrait of Nirvana's landscape",
   "carpet",
	"A thick rug with the symbol of the Mage's Guild imprinted on it",
  });

  dest_dir=({
	"/players/pavlik/guild/mages/rooms/guild_room4", "down",
  });

  if(!present("bboard", this_object()))
  {
	obj = clone_object("players/pavlik/guild/mages/obj/announcement_board");
	move_object(obj, this_object());
  }

}

query_mguild(){ return "Guild Room 5"; }

init() {
  ::init();
  if(!this_player()->is_player()) return;
  add_action("guild_move","gm");
  top_check();
  if(present("mageobj", tp))
	present("mageobj", tp)->do_login_cmds();
}


top_check()
{
  /* if guild name is not mage get them out of here */
  if( (!tp->query_guild_name() || tp->query_guild_name() != "mage") &&
      (tp->query_level() < 20) )
  {
	write("You are not invited.\n");
	tp->move_player("through the ceiling#room/church");
	return 1;
  }

  if(!present("mageobj", tp))
  {
	if(tp->query_level() > 20)
		move_object(clone_object("players/pavlik/guild/mages/gob"), tp);
	else
		move_object(clone_object("players/pavlik/guild/mages/mageobj2"), tp);
	command("renew", tp);
	return 1;
  }

}


