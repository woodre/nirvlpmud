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
    "of the winter sports area.  To the east and to the northwest there is the\n"+
    "misc sports area."+NORM+"\n",

items = ({
   "winter sports area","Mountains full of snow",
});


dest_dir = ({
  "/players/francesco/hall/rooms/y3.c","north",
  "/players/francesco/hall/rooms/y5.c","south",
  "/players/francesco/hall/rooms/n9.c","east",
  "/players/francesco/hall/rooms/n10.c","northwest"
});}


init() {
    ::init();

}

