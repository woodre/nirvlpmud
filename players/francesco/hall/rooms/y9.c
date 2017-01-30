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

short_desc = ""+HIW+"Cross-country skiing"+NORM+"" ;
long_desc =

     ""+HIW+"   Cross-country skiing is great in such sunny days.  The \n"+
            "temperature is low enough to assure that the snow doesnt melt, \n"+
            "the sun is warm enough to provide comfortable weather, the \n"+
            "visibility of the far mountains is perfect and the skyline \n"+
            "is wonderful.  This track is easy and relaxing and can be done\n"+
            "also by beginner cross-country skiers."+NORM+"\n",

items = ({
   "snow","Powdery enough, must of snowed last night",
   "mountains","The famous peaks of the Alps",
   "skyline","Your sight is lost at the horizon",
   "downhill","It averages about 10% of slope",
   "track","This cross-country track runs up and down",
   "peaks","Some can be as high as 12000 ft",
   "horizon","It separes the mountains from the sky",
   "sky","It is bright sky-blue",
   "sun","Today it is particularly bright",
   "skiers","They move cautiously along the track",
});


dest_dir = ({
  "/players/francesco/hall/rooms/y10.c","northwest",
  "/players/francesco/hall/rooms/y8.c","east"
});}


init() {
    ::init();
}

