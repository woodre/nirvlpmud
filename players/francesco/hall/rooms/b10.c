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
            "has a very enjoyable temperature.  The sun is high on the sky.  By \n"+
            "looking towards the neighbouring lanes other swimmers can be seen. \n"+
            "Happy voices of children comes from a smaller pool where they learn\n"+
            "the basics of smimming.  There is a buoy floating around."+NORM+"\n",

items = ({
   "pool","It is a rectangular pool, 55 by 30 yards wide",
   "water","Clean, fresh and transparent",
   "swimmers","Most of them are training along the lanes",
   "lanes","Each lane is about 3 yards wide and is delimited by floating buoys",
   "neighbouring lanes","Each lane is about 3 yards wide and is delimited by floating buoys",
   "buoys","Small and connected by thin wires",
   "buoy","It holds a sign which can be read",
   "sign","It has some wording on it",
   "sun","It is shining high in the sky",
   "smaller pool","It has an oval shape, both instructors and children are inside",
   "instructors","Very young instructors, helping the children to float",
});


dest_dir = ({
  "/players/francesco/hall/rooms/b9.c","east",
  "/players/francesco/hall/rooms/b11.c","northwest"
});}


init() {
    ::init();
    add_action("buoy","read");
}

buoy(str) {
   if(!str) {notify_fail("Read what?\n"); return 0;}
   if(str=="sign"){
    write("The backstroke style requires long leverages to reach the top \n"+
          "performances.  The best backstrokers are always tall and light.\n"+
          "Opposite to any other style, the start is made from within the\n"+
          "pool, holding to the border and pushing hard with the feet against \n"+
          "the end wall.  See http://www.quickgetaway.com/backst01.html for\n"+
          "further reference.\n");
    return 1;}
    notify_fail("You cant read the "+str+".\n"); return 0;}


