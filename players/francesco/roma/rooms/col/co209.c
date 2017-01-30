#include "/players/francesco/univ/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;

if (!present("emperor")) {
  move_object(clone_object("/players/francesco/roma/mobs/emperor.c"),
	this_object()); }
set_light(1);

short_desc = "Podium of the Coliseum" ;
long_desc =
     "   The Podium is the area where the Emperor and his court sat when\n"+
     "they were watching at the shows performed in the arena.  It is very \n"+
     "close to the arena and therefore the view of it is nearly perfect.  \n"+
     "It is covered with a canopy, shielding from the sunshine.  About ten \n"+
     "triclinia are scattered around.  Several marble friezes and purple \n"+
     "curtains hang around. \n",

items = ({
 "arena","The elliptical area in the center of the Coliseum.\n"+
         "It is only 15 feet far from here",
 "canopy","It is made by wood slabs, painted with yellow",
 "triclinia","The triclinia are comfortable wooden couches, covered with pillows",
 "friezes","They depict battle scenes",
 "curtain","They partially seclude the sight from the other segments of the Coliseum",
});

dest_dir = ({
  "/players/francesco/roma/rooms/col/co208.c","east",
  "/players/francesco/roma/rooms/col/co210.c","west"
});

}


init(){
      ::init();
      }


