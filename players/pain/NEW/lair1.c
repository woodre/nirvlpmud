

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "The Lair of the Blood Fisted Clan";
    no_castle_flag = 0;
    long_desc =
        "You are in the upper level of the cave. It is dark and dank\n"
        + "here. You here the sounds of water dripping and see that the\n"
        + "walls are damp. You hear a low rumbling noise running through\n"
        + "cave. Perhaps you should turn back before you run into any of\n"
        + "clansmen. An omnious fear presses down on you from all sides.\n\n"
	+ "You see that you can go: North, South or Down.\n";

items = ({
	"walls", "Damp cavern walls covered with calcium residue."+
                 " How cheery",
});
if(!present("orc"))
{
move_object(clone_object("/players/pain/NEW/mon/orc_g"),this_object());
move_object(clone_object("/players/pain/NEW/mon/orc_g"),this_object());
move_object(clone_object("/players/pain/NEW/mon/orc_e"),this_object());
}
}

init() {
	::init();
add_action("down", "down");
add_action("north", "north");
add_action("south", "south");
}

realm() { return "NT"; }

down() {
  if(!present("orc")) {
    this_player()->move_player("down#/players/pain/NEW/cave3");
    return 1;
  }
  write("The orc maneuvers to block your path!\n");
  say("An orc maneuvers to block "+this_player()->query_name()+"'s path!\n");
  return 1;
}

north() {
  if(!present("orc")) {
    this_player()->move_player("north#/players/pain/NEW/lair2");
    return 1;
  }
  write("The orc maneuvers to block your path!\n");
  say("An orc maneuvers to block "+this_player()->query_name()+"'s path!\n");
  return 1;
}

south() {
  if(!present("orc")) {
    this_player()->move_player("south#/players/pain/NEW/lair11.c");
    return 1;
  }
  write("The orc maneuvers to block your path!\n");
  say("An orc maneuvers to block "+this_player()->query_name()+"'s path!\n");
  return 1;
}


query_light() {
    return 1;
}
query_room_maker() {
    return 101;
}

/*
    remove the comments around the "room is modified()" code
    below to prevent changes you have done to this room to
    to be lost by using the room maker
*/
/*
room_is_modified() {
    return 1;
}
*/

/*
 make your additions below this comment, do NOT remove this comment
--END-ROOM-MAKER-CODE--
*/

