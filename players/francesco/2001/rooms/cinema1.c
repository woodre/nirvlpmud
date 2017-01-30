#include "/players/francesco/univ/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
int x, play;
string dummy;

reset(arg) {
  if(arg) return;

set_light(1);

short_desc = "Cinema" ;
long_desc =
     "   The cinema of the University is not very large.  Notwithstanding\n"+
     "the darkness, it is possible to see about ten rows of seats, each\n"+
     "with ten chairs, crossed by two perpendicular aisles.\n",

items = ({
   "chairs","They are made by soft leather with support for the arms and the head",
   "seats","These seats look comfortable enough for staying there for two hours",
   "aisles","They separate the chairs. Small lights are spaced at regular intervals\n"+
             "along the floor to mark the rows",
});


dest_dir = ({
  "/players/francesco/2001/rooms/africa1.c","start",
  "/players/francesco/2001/rooms/lobby.c","exit",
});

}

init(){
      ::init();
      add_action("start","start");
      }
start() 
  {
   write("The lights of the cinema go out and an introductory music starts over.\n"+
        "  On the dark screen in front of you the beginning titles come out.\n"+
        "   ....... ......... ........... ........... ......... .......\n"+
    HIW+"                      2001: A SPACE ODYSSEY\n"+
   NORM+"   ....... ......... ........... ........... ......... .......\n"+
        "                         Screenplay by \n"+
        "                Stanley Kubrick and Arthur C. Clark\n"+
        "                        Hawk Films Ltd.\n"+
        "                       c/o M-G-M Studios\n"+
        "                         Boreham Wood\n"+
        "                             Hert\n\n"+
    HIR+"           freely adapted by Francesco, September 2000\n\n"+
   NORM+"\n           After a few moments, the first scene starts.\n\n");
  this_player()->move_player("to see the movie#players/francesco/2001/rooms/africa1.c");
  return 1;
  }
  
