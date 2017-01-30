#include "/players/francesco/univ/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
int blah;
reset(arg) {
  if(arg) return;
  set_light(1);
short_desc = "Crossing point" ;
long_desc =
    "   At the crossing point between the ski area and the misc sports one.\n"+
    "By looking towards north and south it is possible to take a full look  \n"+
    "of the misc sports area.  To the east and to the southwest there is the\n"+
    "ski area."+NORM+"\n",

items = ({
   "ski area","Mountains full of snow",
});


dest_dir = ({
  "/players/francesco/hall/rooms/n3.c","north",
  "/players/francesco/hall/rooms/n11.c","south",
  "/players/francesco/hall/rooms/y1.c","west",
  "/players/francesco/hall/rooms/y2.c","southeast"
});}


init() {
    ::init();

}

