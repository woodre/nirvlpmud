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
  "/players/francesco/hall/rooms/b13.c","south",
  "/players/francesco/hall/rooms/b15.c","northeast"
});}


init() {
    ::init();
    add_action("buoy","read");
}

buoy(str) {
   if(!str) {notify_fail("Read what?\n"); return 0;}
   if(str=="sign"){
    write("The butterfly has the same movements than the frestyle, yet \n"+
          "legs and arms are moved in unison, whichs makes it a difficult\n"+ 
          "style.  Butterfly isn't easy. But it doesn't have to be as much\n"+ 
          "work as you think. The biggest problem for most people is breathing \n"+
          "and recovery of the arms. You feel you have to climb out of the \n"+
          "water for that precious air, which means you put so much effort \n"+
          "into breathing and recovery that you have nothing left for the \n"+
          "actions that move you forward.\n");
    return 1;}
    notify_fail("You cant read the "+str+".\n"); return 0;}


