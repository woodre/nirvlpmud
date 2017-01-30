#include "/players/pavlik/guild/mages/rooms/ROOMS"
inherit "room/room";
reset(arg) {
  if(!arg) {
set_light(1);
short_desc="Jhavostrahd's Chambers";
long_desc=
"It is rumored that the chambers of Jhavostrahd contain more books\n"+
"and scrolls than even the Great Library itself!  Nearly every\n"+
"inch of the room is covered with either large books or neatly\n"+
"wrapped scrolls.  Jhavostrahd hordes his literature jealously\n"+
"and is zealous in the pursuit of knowledge.  A door in the southern\n"+
"wall leads back to the hallway.  There does not appear to be any\n"+
"other exits.\n";

items=({
"floor",
"The old floor is dusty and books are stacked everywhere on it",
"shelves",
"Old shelves that are lined with various books and scrolls",
"books",
"Hundreds upon hundreds of books cover the room.  They are neatly\n"+
"stacked and organized on shelves or on the floor.  You pause\n"+
"to consider how old some of these tomes are and how any one\n"+
"person could read all of them",
"scrolls",
"Scrolls of unknown origin are rolled up and stuffed in various\n"+
"places.  You know better than to touch any of them",
});

dest_dir=({
 "/players/pavlik/guild/mages/rooms/masters_hall2", "south",
});

if(!present("jhavostrahd", this_object()))
 move_object(clone_object("players/pavlik/guild/mages/rooms/npc/jhavostrahd"),
 this_object());

   }
}

query_mguild(){ return "Jhabostrahd's"; }

init(){
  ::init();
  add_action("guild_move","gm");
  mage_check();
}

