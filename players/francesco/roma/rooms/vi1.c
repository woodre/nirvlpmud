#include "/players/francesco/univ/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;

set_light(1);

short_desc = "A narrow street" ;
long_desc =
     "   This narrow street slopes upward to a small hill, visible to the \n"+
     "north.  The sidewalks are marked by yellow lines of paint traced on \n"+
     "the pavement.  The buildings at the sides appear recently renovated.\n",

items = ({
 "hill","It is made by green lawn, decently maintained",
 "sidewalks","They are only three foot wide, since the whole street is only fifteen feet wide",
 "buildings","Apartment buildings, four flats high",
 "pavement","It is made by black square bricks, only five inches wide. These\n"+
            "are the the so-called sampietrini, typically used in this town",
 "lines","They separate the car lane from the pedestrian's one",
});

dest_dir = ({
  "/players/francesco/roma/rooms/vi2.c","north",
  "/players/francesco/univ/rooms/bar2.c","exit"
});

}


init(){
      ::init();
      }


