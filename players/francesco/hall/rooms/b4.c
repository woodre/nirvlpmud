#include "/players/francesco/univ/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
int blah;
reset(arg) {
  if(arg) return;
  set_light(1);
short_desc = ""+HIC+"Swimming pool"+NORM+"" ;
long_desc =

     ""+HIC+"   Just about the swimming pool.  The fresh and transparent water looks \n"+
            "very inviting for a relaxing swim.  Some swimmers run in the training\n"+
            "lanes, some are resting on the borders of the pool,  some are sunbathing\n"+
            "on comfortable chaise lounges around the pool.  There is a sign suspended \n"+
            "on a tripod."+NORM+"\n",

items = ({
   "pool","It is a rectangular pool, 55 by 30 yards wide",
   "swimming pool","It is a rectangular pool, 55 by 30 yards wide",
   "water","Clean, fresh and transparent",
   "swimmers","Most of them are training along the lanes",
   "lanes","Each lane is about 3 yards wide and is delimited by floating buoys",
   "training lanes","Each lane is about 3 yards wide and is delimited by floating buoys",
   "borders","The borders of the pool are at the same level of the water",
   "buoys","Small and connected by thin wires",
   "lounges","Horizontal chairs, with confortable cushions on them",
   "chaise lounges","Horizontal chairs, with confortable cushions on them",
   "sign","The sign has some words on it to read",
});


dest_dir = ({
  "/players/francesco/hall/rooms/b3.c","northwest",
  "/players/francesco/hall/rooms/b5.c","southeast"
});}


init() {
    ::init();
    add_action("buoy","read");
}

buoy(str) {
   if(!str) {notify_fail("Read what?\n"); return 0;}
   if(str=="words"){
    write("FINA, Federation Internationale de Natation.\n"+
          "http://www.fina.org\n");
    return 1;}
    notify_fail("You cant read the "+str+".\n"); return 0;}


