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

short_desc = ""+HIC+"Swimming pool"+NORM+"" ;
long_desc =

     ""+HIC+"   Swimming along the pool.  The fresh water is all transparent and\n"+
            "its temperature is mostly enjoyable.  Some other swimmers run in the\n"+
            "neighbouring lanes.  There is a buoy floating around."+NORM+"\n",

items = ({
   "pool","It is a rectangular pool, 55 by 30 yards wide",
   "water","Clean, fresh and transparent",
   "swimmers","Most of them are training along the lanes",
   "lanes","Each lane is about 3 yards wide and is delimited by floating buoys",
   "neighbouring lanes","Each lane is about 3 yards wide and is delimited by floating buoys",
   "buoys","Small and connected by thin wires",
   "buoy","It holds a sign which can be read",
   "sign","It has some wording on it",
});


dest_dir = ({
  "/players/francesco/hall/rooms/b13.c","north",
  "/players/francesco/hall/rooms/b11.c","southeast"
});}


init() {
    ::init();
    add_action("buoy","read");
}

buoy(str) {
   if(!str) {notify_fail("Read what?\n"); return 0;}
   if(str=="sign"){
    write("The freestyle allows for everyone to use their favorite style.\n"+
          "The most effective one was setup at the beginning of the 20th\n"+
          "century and consists of alternating movements of the arms, \n"+
          "accompanied by a very frequent legs beating, which provide\n"+
          "further propulsion.  This is the so-called crawl, which is\n"+
          "the fastest style.\n");
    return 1;}
    notify_fail("You cant read the "+str+".\n"); return 0;}


