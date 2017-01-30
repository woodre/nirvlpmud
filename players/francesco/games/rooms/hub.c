#include "/players/francesco/univ/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;

set_light(1);

short_desc = "Games room" ;
long_desc =
     "   This square room is the center of the games area.  It has some\n"+
     "passageways to the game rooms.  Each of those passageways are marked\n"+
     "with different nouns to remind what games are played inside.  The\n"+
     "windows are ample enough to decently light the room.  The ceiling is\n"+
     "high enough to give a feeling of freedom.  The walls are painted with\n"+
     "white color which allow for relaxing.  A black board is suspended on\n"+
     "a stand.\n",

items = ({
   "passageways","Just doors to the game rooms",
   "board","A large black board which you could read",
   "stand","It has three legs and holds a board",
   "nouns",HIR+"M O R R A     "+HIW+"S A S S O"+NORM,
   "windows","They are of ellyptical shape, about five feet high",
   "ceiling","It is about fifteen feet high and doesnt hold any chandelier.\n"+
             "The light from the windows is already enough to light the room",
   "walls","They hold some posters about the games played here",
   "posters","They announce the next tournaments",
});

dest_dir = ({
  "/players/francesco/univ/rooms/bar2.c","exit",
});

}


init(){
      ::init();
      add_action("read","read");
      add_action("sasso","sasso");
      add_action("morra","morra");
      }


read(str){
   if(str=="board")
    {write("     Presently available games are:\n\n"+HIW+
           "         Sasso         "+NORM+"(type sasso to enter)\n"+
           "         "+HIR+"Morra"+NORM+"         (type morra to enter)\n");
    return 1;}
  notify_fail("Read what?\n");
  return 0;
}

sasso(){
    this_player()->move_player("to the Sasso game#players/francesco/games/rooms/sasso.c");
    return 1;
     }

morra(){
    this_player()->move_player("to the Morra game#players/francesco/games/rooms/morra.c");
    return 1;
     }

query_no_fight() {return 1;}
