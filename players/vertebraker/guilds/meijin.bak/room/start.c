#include "/players/pavlik/guild/colors.h";
#include "/players/pavlik/guild/room/room.h";
inherit "room/room";

/*****************************************************************/
/* This is the guild start room.  All guild members will login   */
/* here.  The object is cloned and moved to the player at login. */
/*****************************************************************/

object obj;

reset(arg) {
  if(!arg) {
  set_light(1);
  short_desc="The Great Hall";
  long_desc=
    "The Great Hall.  This magnificent chamber is the keystone of\n"+
    "the Citadel.  The ceiling arches elegantly overhead, artistic\n"+
    "skylights let the sunlight fill the room with warmth and light.\n"+
    "The walls are lined with golden scones and torches which keep\n"+
    "the room well-lit all through the night.  There is a magical\n"+
    "portal on the east wall that glows with mystic powers.\n";

  dest_dir=({
    "/players/pavlik/guild/room/lowerhall", "north",
    "/players/pavlik/guild/room/courtyard", "south",
  });

  items=({
    "portal",
    "The Magic Portal is an magical artifact that was presented to\n"+
    "the Meijin many many centuries ago.  This magical gateway allows\n"+
    "people to move instantly throughout the realm.  To use this\n"+
    "device you must 'step <destination>'.  Possible destinations are: \n"+
    "     church     - village church.\n"+
    "     shop       - village shop.\n"+
    "     hotel      - hotel of space and time.\n"+
    "     daycare    - daycare center.\n"+
    "     lockers    - theives lockers.\n"+
    "     post       - post office.\n"+
    "     portal     - black chamber",
  });

  if(!present("bboard", this_object())) {
	move_object(clone_object("players/pavlik/guild/obj/bboard"), this_object());
  }

  }
}

init() {
  ::init();

  if(!this_player()->is_player()) return 1;

  if(this_player()->query_level() < 20 && !is_member(this_player()->query_real_name())) {
	write("\n"+
		"--- You are no longer an active member of the Meijin guild.\n"+
		"--- Sorry, but due to circumstances you will need to rejoin the\n"+
		"--- guild.  Please contact Pavlik for more info.\n"+
		"\n"+
		"You are moved to the Village Church.\n\n");
	this_player()->move_player("out#room/church");
	return 1;
  }

  add_action("portal", "step");
  add_action("xmove", "xmove");

  if(this_player()->query_guild_name() != "meijin" && this_player()->query_level() < 20) {
	write("You are not permitted here.\n");
	write("You are carefully transported to the village church.\n");
	this_player()->move_player("abruptly#room/church");
	return 1;
  }
  if(!present("pavlik_guild_obj", this_player())) {
	if(this_player()->query_level() > 20)
		obj = clone_object("players/pavlik/guild/gob_real");
	else
		obj = clone_object("players/pavlik/guild/gob");
	move_object(obj, this_player());
	obj->guild_init();
  }

}

/* Fix old ppl */
is_member(name) {
  string *members;
  int i;

  members = ({
	"pavtest",
	"becktest",
	"mortarion",
	"marie",
	"gwydion",
	"tragedy",
	"hworang",
	"plum",
	"akumalore",
	"naika",
	"ireland",
	"ajax",
	"genji",
	"jayjay",
  });

  for(i=0; i<sizeof(members); i++) {
	if(members[i] == name) return 1;
  }
  return 0;
}

/* this func is for debugging/testing only */
getweap() {
	write("Ok!\n");
	move_object(clone_object("players/pavlik/guild/obj/sword"), this_player());
	return 1;
}

portal(str) {
  object obj;
  string dest;

  if(!str) return 0;

  switch (str) {
	case "church" :
		this_player()->move_player("into the portal#room/church");
		break;
	case "shop" :
		this_player()->move_player("into the portal#room/shop");
		break;
	case "hotel" :
		this_player()->move_player("into the portal#players/boltar/hotel/hotel");
		break;
	case "daycare" :
		this_player()->move_player("into the portal#players/boltar/sprooms/daycare");
		break;
	case "lockers" :
		this_player()->move_player("into the portal#players/catwoman/tl");
		break;
	case "post" :
		this_player()->move_player("into the portal#room/post");
		break;
	case "portal" :
		this_player()->move_player("into the portal#players/saber/ryllian/portal");
		break;
	default :
		write("You stare at the portal with awe.\n");
		break;
  }
  return 1;
}

