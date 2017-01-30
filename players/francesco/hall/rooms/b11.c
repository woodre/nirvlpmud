#include "/players/francesco/univ/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
int blah;
reset(arg) {
  if(arg) return;
   if (!present("monster")) {  
   move_object(clone_object("/players/francesco/hall/mobs/kris.c"),
	this_object());  }
set_light(1);

short_desc = ""+HIC+"Swimming pool"+NORM+"" ;
long_desc =

     ""+HIC+"   Swimming along the pool.  The fresh water is all transparent and\n"+
            "its temperature is mostly enjoyable.  Some other swimmers run in the\n"+
            "neighbouring lanes, some are resting on the borders of the pool,  some\n"+
            "are sunbathing on comfortable chaise lounges around the pool.  There\n"+
            "is a buoy floating around."+NORM+"\n",

items = ({
   "pool","It is a rectangular pool, 55 by 30 yards wide",
   "water","Clean, fresh and transparent",
   "swimmers","Most of them are training along the lanes",
   "lanes","Each lane is about 3 yards wide and is delimited by floating buoys",
   "neighbouring lanes","Each lane is about 3 yards wide and is delimited by floating buoys",
   "borders","The borders of the pool are at the same level of the water",
   "buoys","Small and connected by thin wires",
   "buoy","It holds a sign which can be read",
   "sign","It has some wording on it",
   "lounges","Horizontal chairs, with confortable cushions on them",
   "chaise lounges","Horizontal chairs, with confortable cushions on them",

});


dest_dir = ({
  "/players/francesco/hall/rooms/b12.c","northwest",
  "/players/francesco/hall/rooms/b10.c","southeast"
});}


init() {
    ::init();
    add_action("buoy","read");
}

buoy(str) {
   if(!str) {notify_fail("Read what?\n"); return 0;}
   if(str=="sign"){
    write("For more info on backstroke, please feel free to visit\n"+
          "the following sites:\n"+
          "http://www.svl.ch/backstroke.html\n"+
          "http://www.totalimmersion.net/articles/backstroke.html\n"+
          "http://www.wellesley.edu/Athletics/pe/swimming/swimming_wholebackstroke.html");
    return 1;}
    notify_fail("You cant read the "+str+".\n"); return 0;}


