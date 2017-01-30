#include "/players/francesco/univ/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
int blah;
reset(arg) {
  if(arg) return;
 if (!present("monster")) {  }
set_light(1);

short_desc = ""+HIY+"Wrestling Arena"+NORM+"" ;
long_desc =

     ""+HIW+"   This snowy road connects downtown with the alpine ski \n"+
            "area.  it can be easily walked by because the snow is well\n"+
            "compacted and the risks of sliding are close to zero.  The\n"+
            "perfect visibility of the far mountains and the wonderful\n"+
            "skyline make this walk very enjoyable for most people."+NORM+"\n",

items = ({
   "road","A walkable path through two walls of snow",
   "snow","The snow is well compacted even though last might must of snowed",
   "mountains","The famous peaks of the Alps",
   "skyline","Your sight is lost at the horizon",
   "peaks","Some can be as high as 12000 ft",
   "horizon","It separes the mountains from the sky",
   "sky","It is bright sky-blue",
   "sun","Today it is particularly bright",
   "people","They move happily along the path to reach the skiing area",
});


dest_dir = ({
  "/players/francesco/hall/rooms/y2.c","northwest",
  "/players/francesco/hall/rooms/y4.c","south"
});}


init() {
    ::init();
}

