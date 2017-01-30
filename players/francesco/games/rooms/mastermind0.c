#include "/players/francesco/univ/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
if (!present("table",this_object())) {
  move_object(clone_object("/players/francesco/games/items/mastermind4.c"),this_object());}
if (!present("jasmine",this_object())) {
  move_object(clone_object("/players/francesco/games/mobs/jasmine.c"),
	this_object());  }

set_light(1);

short_desc = "Mastermind" ;
long_desc =
     "   Being part of the game area of the University, this room has been\n"+
     "decorated with several posters and drawings on the walls.  A table\n"+
     "with one business chair is in the middle of it.  An ample chandelier\n"+
     "hangs down from the ceiling and lights the room.  A board is suspended\n"+
     "on a stand.\n",

items = ({
   "walls","They are covered with some posters",
   "posters","They depict the announcements made for game tournaments",
   "drawings","They show some typical games played in the University",
   "chair","It is made by leather and is very comfortable",
   "chandelier","It is made of three tubes, which emit a white shining light",
   "ceiling","It is about twelve feet high",
   "board","A large black board holding a flier which you could read",
   "stand","It has three legs and holds a sign",
   "table",HIC+"This is a wooden table, covered with a soft green felt, with\n"+
           "one single ashtray.  A flier lies on the table and can be 'read'"+NORM,
   "flier","It is made by one single page, with several colors",
});

dest_dir = ({
  "/players/francesco/games/rooms/mastermindhub.c","exit",
});

}

query_no_fight() {return 1;}
