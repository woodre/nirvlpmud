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

short_desc = ""+HIW+"Atop of a mountain"+NORM+"" ;
long_desc =

     ""+HIW+"   This is the arrival point of the chairlifter which brings up \n"+
            "the skiers up to the mountain.  There is an ample terrace where\n"+
            "some chaise lounges are positioned and where people can rest and,\n"+
            "eventually, sunbath during sunny days.  The baita here hosts a \n"+
            "small bar where people can get something to eat and to drink for\n"+ 
            "healing from the fatigue of the sport day.  The visibility of the \n"+
            "far mountains is perfect and the skyline is wonderful."+NORM+"\n",

items = ({
   "mountains","The famous peaks of the Alps",
   "peaks","Some can be as high as 12000 ft",
   "skyline","Your sight is lost at the horizon",
   "horizon","It separes the mountains from the sky",
   "sky","It is bright sky-blue",
   "skiers","Most are getttng ready to wear their skies, some are resting in the sun",
   "sun","Today it is particularly bright",
   "terrace","It is wide enough to host about 40 chaise lounges",
   "lounges","Horizontal chairs, with confortable cushions on them",
   "chaise lounges","Horizontal chairs, with confortable cushions on them",
   "cushions","The cushions are all vividly colored",
   "baita","It is a typical alpine mountain hut, all made by wood beams",
   "beams","They cross each other to make the frame of the baita",
   "snowboarders","They are all wearing ample skiwears, which protect them when they fall down",
   "skiwears","Snowboarders wear colored skiwears",
   "chairlifter","Continuously climbing up, 4 skiers at a time",
});


dest_dir = ({
  "/players/francesco/hall/rooms/b6.c","northeast",
  "/players/francesco/hall/rooms/y13.c","southwest",
});}


init() {
    ::init();
}

