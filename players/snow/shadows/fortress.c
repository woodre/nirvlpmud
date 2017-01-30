/*  10/09/06 - Rumplemintz: moved inherit above #include statement  */

inherit "/players/snow/shadows/base.c";
#include "shaddefs.h"
realm() { return "NT"; }
 
 
reset(arg){
  
 if(!arg){
 
 set_light(0);
  short_desc="ShadowFortress";
 long_desc=
 "You have arrived at a huge edifice thrusting forth above the shadowplain.\n"+
 "It is strange that you did not see it as you approached but now that you \n"+
 "here it is as clear as anything in this realm of shadows. The huge grey\n"+
 "gates appear to be closed.\n"+
 "Shadows flit around the corners of your vision. What seems clear one moment\n"+
 "disappears the next. The landscape appears to somehow flow around your\n"+
 "solidity here. To move from place to place, you must make a huge effort. \n"+
"\n";
 
items=({
 "gates", "Huge gates of some grey shadowstuff. There appears to be a knocker\n"+
           "a little off to the side of the gates",
 "gate", "Huge gates of some grey shadowstuff. There appears to be a knocker\n"+
           "a little off to the side of the gates",
 "knocker","A dark grey knocker. You could 'use knocker' if you wanted..",
 "landscape","Features of the land pass before your eyes",
 "fortress","Imposing walls rise before you. The only entrance appears to be\n"+
        "the front gates- unfortunately they are closed.\n",
});
 
   }   }
 
init() {
  ::init();
add_action("use_knocker","use");
}
 
use_knocker(arg) {
  if(!arg) { write("Use what?\n"); return 1; }
  if(arg == "knocker") {
    say(TPN+" knocks on the door...\n"+"...and suddenly disappears!\n");
    write("You knock on the door...\n"+"...and suddenly disappear!\n");
  call_other(TP,"move_player",
    "into the ShadowFortress#players/snow/shadows/fort/recep_room");
  return 1;
  }
}
query_srealm() { return "shad"; }
