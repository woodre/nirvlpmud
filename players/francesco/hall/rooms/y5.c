#include "/players/francesco/univ/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
int blah;
reset(arg) {
  if(arg) return;
 if (!present("monster")) {
   move_object(clone_object("/players/francesco/hall/mobs/wayne.c"),this_object());}
set_light(1);

short_desc = ""+HIW+"Ice Palace"+NORM+"" ;
long_desc =

     ""+HIW+"   The ice palace is an imponent building with the shape of a\n"+
            "cylinder, about 150 ft tall and 300 ft wide.  It can host up to\n"+
            "20,000 attendants around the ice rink.  Some skaters are training\n"+
            "in the middle, some others are checking their equipping to get \n"+
            "for the next game."+NORM+"\n",

items = ({
   "palace","An imponent construction",
   "building","An imponent construction",
   "rink","It has a rectangular shape with some red and blue lines painted on it",
   "ice rink","It has a rectangular shape with some red and blue lines painted on it",
   "skaters","They move fluidly, running on their skates inside the track",
   "equipping","Icepicks, skaters, masks and wears",
});


dest_dir = ({
  "/players/francesco/hall/rooms/y4.c","north",
  "/players/francesco/hall/rooms/y6.c","southwest"
});}


init() {
    ::init();
}

