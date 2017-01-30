#include "/players/francesco/univ/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
if (!present("narrator")) {
  move_object(clone_object("/players/francesco/2001/mobs/narrator5.c"),
	this_object());  }
set_light(1);

short_desc = "White shining room" ;
long_desc =
     "    CONCLUSION\n"+
     "A very large and long room. The white  walls, the white ceiling and \n"+
     "the white floor make the atmosphere of this room very unique.  The \n"+
     "extremely intense bright light coming from nowhere almost blinds you.  \n"+
     "On the far end wall, there are some drawings and a small plaque.\n",

items = ({
   "plaque","\n                 T h e   K n o w l e d g e ",
   "drawings","A fetus and a Monolith can be recognized in these drawings.\n"+
              "They both can be looked at closer",
   "ceiling","You can barely see its end due to its high dimension",
   "floor","It is covered by a white carpet, it absorbs any sound \n"+
           "made by someone who might walk around",
   "walls","These two parallel long surfaces look like they lead to infinity",
   "fetus","It is the fetus of a human, likely five months old, eyes almost shut.\n"+
           "As you examine it closer, a sudden feeling invades your mind, like your \n"+
           "heartbeats start pacing faster",
   "monolith","It has the same shape of what was found in the African Drylands and \n"+
              "in the Moon surface.  As you examine it closer, a sudden feeling invades\n"+
              "your mind, like your heartbeats start pacing faster",
   "wall","The end wall must be about 200 feet afar",
});

dest_dir = ({
  "/players/francesco/2001/rooms/cinema1.c","end",
});

}

init(){
      ::init();
      add_action("the_end","end");
      }

the_end() 
  {
  write("                         T H E   E N D \n\n"+
        "   ....... ......... ........... ........... ......... .......\n"+
    HIW+"                      2001: A SPACE ODYSSEY\n"+
   NORM+"   ....... ......... ........... ........... ......... .......\n"+
        "                         Screenplay by \n"+
        "                Stanley Kubrick and Arthur C. Clark\n"+
        "                        Hawk Films Ltd.\n"+
        "                       c/o M-G-M Studios\n"+
        "                         Boreham Wood\n"+
        "                             Hert\n\n"+
    HIR+"           freely adapted by Francesco, September 2000\n\n"+NORM);
  this_player()->move_player(". The movie is over #players/francesco/2001/rooms/cinema1.c");
/**
  this_player()->move_player(" #players/francesco/2001/rooms/cinema1.c");
**/
  destruct(present("ticket",this_player()));
  return 1;
  }


query_no_fight() {return 1;}
