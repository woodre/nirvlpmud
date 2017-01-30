#include "/players/francesco/univ/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
int blah;
reset(arg) {
  if(arg) return;
 if (!present("monster")) {
   move_object(clone_object("/players/francesco/hall/mobs/tomba.c"),this_object());}
set_light(1);

short_desc = ""+HIW+"Downhill of a mountain"+NORM+"" ;
long_desc =

     ""+HIW+"   Skiing is great in such sunny days.  The temperature is low\n"+ 
            "enough to assure that the snow doesnt melt,  the visibility of\n"+
            "the far mountains is perfect and the skyline is wonderful.  The\n"+
            "upper part of this downhill is the most challenging.  This is\n"+
            "where the skilled skiers take the most pleasure.  Also the\n"+
            "snowboarders can enjoy this downhill but yet most of them are\n"+
            "falling down unless very skilled."+NORM+"\n",

items = ({
   "snow","Powdery enough, must of snowed last night",
   "mountains","The famous peaks of the Alps",
   "skyline","Your sight is lost at the horizon",
   "downhill","It averages about 50% of slope",
   "skiers","Wow, how fast they do their turns and their jumps",
   "snowboarders","They are all wearing ample skiwears, which protect them when they fall down",
   "track","The downhill track is only 40 ft wide, delimited by high fir trees",
   "peaks","Some can be as high as 12000 ft",
   "horizon","It separes the mountains from the sky",
   "sky","It is bright sky-blue",
   "sun","Today it is particularly shining",
   "skiwears","Snowboarders wear colored skiwears",
});


dest_dir = ({
  "/players/francesco/hall/rooms/y13.c","north",
  "/players/francesco/hall/rooms/y11.c","south",
  "/players/francesco/hall/rooms/b9.c","west",
  "/players/francesco/hall/rooms/b8.c","northeast"
});}


init() {
    ::init();
}

