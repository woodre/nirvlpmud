inherit "room/room";
#include "/players/mouzar/misc/roomt.h"   
string open;
reset(arg){
 if(!arg){
  set_light(1);
  short_desc="Library & Study";
  long_desc="This spacious chamber is packed with floor-to-ceiling bookshelves, with\n"+
            "thousands of tomes on all aspects of the history and societies of\n"+
            "Empire, Myrindon, Tyr, and Stigia.  Maps, brass models of the movement\n"+
            "of the heavens, astrological charts showing the correspondence of body\n"+
            "parts to the heavenly spheres, and similar decorations fill the room.\n"+
            "The only way out is the door that you entered from.\n";
 }
}
init(){
  ::init();
     add_action("west","west");
     add_action("open","open");
}

open(str) {
    notify_fail("open what?\n");
    if (!str)
        return 0;
    if (str == "door") {
    write("The door opens without a sound.\n");
    say(RN + " open the door slowly.\n");
    open="yes";
   return 1;
   }
    return 1;
}
west() {
  if(open == "yes"){
    write("The door closes behind you!\n\n");
    ME->move_player("west#/players/mouzar/quest/lroom3");
    say("The door closes behind "+RN+"!\n");
    open == "no";
    return 1;
  }
  write("You run into the door!    OUCH!!\n");
  say(RN +" walks into a door!\n");
  return 1;
}
