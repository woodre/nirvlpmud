#include "/players/francesco/univ/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
int blah;
reset(arg) {
  if(arg) return;
 if (!present("monster")) {}
set_light(1);

short_desc = ""+HIW+"Downhill of a mountain"+NORM+"" ;
long_desc =

     ""+HIW+"   Skiing is great in such sunny days.  The temperature is low\n"+ 
            "enough to assure that the snow doesnt melt,  the visibility of\n"+
            "the far mountains is perfect and the skyline is wonderful.  This\n"+
            "downhill is still easy and mostly frequented by beginners.  Also,\n"+
            "some snowboarders can enjoy this downhill for it permits their\n"+
            "ample evolutions from one part to the other of the track."+NORM+"\n",

items = ({
   "snow","Powdery enough, must of snowed last night",
   "mountains","The famous peaks of the Alps",
   "skyline","Your sight is lost at the horizon",
   "downhill","It averages about 10% of slope",
   "beginners","Most of them are grouped in classes, with a teacher.\n"+
               "They sky down the track one after the other, tracing\n"+
               "their route like a snake",
   "snowboarders","They are all wearing ample skiwears, running fast on their boards",
   "track","The downhill track is about 100 ft wide, delimited by high fir trees",
   "peaks","Some can be as high as 12000 ft",
   "horizon","It separes the mountains from the sky",
   "sky","It is bright sky-blue",
   "sun","Today it is particularly bright",
   "skiwears","Snowboarders wear colored skiwears",
});


dest_dir = ({
  "/players/francesco/hall/rooms/y12.c","north",
  "/players/francesco/hall/rooms/y10.c","southeast"
});}


init() {
    ::init();
}

