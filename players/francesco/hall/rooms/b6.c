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
    "   At the crossing point between the ski area and the pool.  By looking\n"+
    "towards north and south it is possible to take a full look of the swimming\n"+
    "pool.  To the east and to the southwest there is the ski area."+NORM+"\n",

items = ({
   "pool","It is a rectangular pool, 55 by 30 yards wide",
   "swimming pool","It is a rectangular pool, 55 by 30 yards wide",
   "area","Mountains full of snow",
   "ski area","Mountains full of snow",
});


dest_dir = ({
  "/players/francesco/hall/rooms/b5.c","north",
  "/players/francesco/hall/rooms/b7.c","south",
  "/players/francesco/hall/rooms/y1.c","east",
  "/players/francesco/hall/rooms/y14.c","southwest"
});}


init() {
    ::init();

}

