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

short_desc = ""+HIW+"Base of the chairlifter"+NORM+"" ;
long_desc =

     ""+HIW+"   The base of the chairlifter is a small open building\n"+
            "where the moving chairs enter, pick the skiers and exit\n"+
            "to climb up the mountain.  Some people are awaiting in\n"+
            "the queue.  A couple of tracked snowcats are parked just\n"+
            "about."+NORM+"\n",

items = ({
   "base","A small open building",
   "base of the chairlifter","A small open building",
   "chairs","large enough to keep four skiers at once",
   "mountain","One of the famous peaks of the Alps",
   "peaks","Some can be as high as 12000 ft",
   "snowcats","The have a powerful engine to climb easily the mountain",
   "tracked snowcats","The have a powerful engine to climb easily the mountain",
   "people","They patiently wait to pick the chair and climb the mountain",
});


dest_dir = ({
  "/players/francesco/hall/rooms/n12.c","east",
  "/players/francesco/hall/rooms/b6.c","west"
});}


init() {
    ::init();
}

