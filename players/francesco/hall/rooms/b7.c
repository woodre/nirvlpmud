#include "/players/francesco/univ/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
short_desc = ""+HIC+"Swimming pool"+NORM+"" ;
long_desc =

     ""+HIC+"   Just about the swimming pool.  The fresh and transparent water looks \n"+
            "very inviting for a relaxing swim.  From this side of the pool it is\n"+
            "possible to take a full look at the whole area.  Some swimmers run \n"+
            "in the training lanes, some are resting on the borders of the pool,  \n"+
            "some are sunbathing on comfortable chaise lounges around the pool."+NORM+"\n",

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
  "/players/francesco/hall/rooms/b6.c","north",
  "/players/francesco/hall/rooms/b8.c","southwest"
});}


init() {
    ::init();

}

