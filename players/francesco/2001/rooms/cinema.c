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
     "   The cinema of the University is not very large.  Nothwithstanding\n"+
     "the obscurity, it is possible to see about ten lines of seats, each\n"+
     "with ten chairs, crossed by two perpendicular aisles.\n",

items = ({
   "chairs","Comfortable enough for staying there for two hours",
   "aisles","They separate the chairs. Some marks of lights are regularly put on the floor",
});

dest_dir = ({
  "/players/francesco/2001/rooms/africa1.c","start",
  "/players/francesco/univ/rooms/bar.c","exit",
});

}

init(){
      ::init();
      add_action("start","start");
      }

start() {
   dummy=this_player();
   play = 1; call_out("narrate",3,dummy);
   return 1; }

narrate(dummy){
   narrate_it();
   x += 1;
   if(x<12) call_out("narrate",1,dummy);
   else { play = 0; x = 0; 
   dummy->move_player(" #players/francesco/2001/rooms/africa1.c");
   }
   return 1; }

narrate_it() {
 string lyric;
   switch(x) {
      case 0: lyric = " ";break;
      case 1: lyric = "               2001: A SPACE ODYSSEY ";break;
      case 2: lyric = " ";break;
      case 3: lyric = "                  Screenplay by";break;
      case 4: lyric = "         Stanley Kubrick and Arthur C. Clark";break;
      case 5: lyric = "                  Hawk Films Ltd";break;
      case 6: lyric = "                c/o. M-G-M Studios";break;
      case 7: lyric = "                   Boreham Wood";break;
      case 8: lyric = "                       Hert";break;
      case 9: lyric = " ";break;
      case 10: lyric = "     freely adapted by Francesco, September 2000";break;
      case 11: lyric = " ";break;}
    tell_room(this_object(),HIW+lyric+NORM+"\n");      
return 1; }

query_no_fight() {return 1;}
