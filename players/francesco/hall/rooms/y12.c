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
    "towards north and south it is possible to take a full look of the ski\n"+
    "area.  To the east and to the northeast there is the swimming pool."+NORM+"\n",

items = ({
   "pool","It is a rectangular pool, 55 by 30 yards wide",
   "swimming pool","It is a rectangular pool, 55 by 30 yards wide",
   "area","Mountains full of snow",
   "ski area","Mountains full of snow",
});


dest_dir = ({
  "/players/francesco/hall/rooms/y13.c","north",
  "/players/francesco/hall/rooms/y11.c","south",
  "/players/francesco/hall/rooms/b8.c","northeast",
  "/players/francesco/hall/rooms/b9.c","west"
});}


init() {
    ::init();

}

