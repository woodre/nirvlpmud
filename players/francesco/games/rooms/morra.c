#include "/players/francesco/univ/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
if (!present("cindy")) {
  move_object(clone_object("/players/francesco/games/mobs/tippy.c"),
	this_object());  }
if (!present("flier")) {
  move_object(clone_object("/players/francesco/games/items/morra.c"),this_object());}

set_light(1);

short_desc = "Morra" ;
long_desc =
     "   Being part of the game area of the University, this room has been\n"+
     "decorated with several posters and drawings on the walls.  A table\n"+
     "with two chairs is in the middle of it,  and some other chairs are \n"+
     "roundly aligned.  An ample chandelier hangs down from the ceiling and\n"+
     "lights the room.  A board is suspended on a stand.\n",

items = ({
   "walls","They are covered with some posters",
   "posters","They depict the announcements made for game tournaments",
   "drawings","They show some typical games played in the University",
   "chairs","They look simple and comfortable, made of wood",
   "chandelier","It is made of three tubes, which emit a white shining light",
   "ceiling","It is about twelve feet high",
   "board","A large black board holding a flier which you could read",
   "stand","It has three legs and holds a sign",
   "table","This is a wooden table, covered with a soft green felt, with ashtrays\n"+
           "at the four corners.  A flier lies on the table and can be 'read'",
   "flier","It is made by one single page, with several colors",
});

dest_dir = ({
  "/players/francesco/games/rooms/hubnew.c","exit",
});

}

query_no_fight() {return 1;}
