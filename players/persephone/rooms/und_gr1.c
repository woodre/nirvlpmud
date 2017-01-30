inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
string nodig;
object lads;
reset(int arg){
 if (arg) return;
  nodig="yes";
  set_light(0);
  short_desc="Refuse Pit";
  long_desc="This is a large refuse pit full of sewerage and other unmentionable\n" +
            "things. leaning against the north wall is an old iron ladder\n" +
            "and a big spade. To the west you see a disgusting tunnel while directly\n" +
            "above you is a large hatch which you just might be able to open.\n" +
            "\n";
  items=({"sewerage","Sewerage you know human excrement. but something does\n" +
                     "does seem strange maybe you should dig and find out",
          "walls","The walls are covered in some sort of slippery slime",
          "slime","This stuff is really revolting and has a foul smell",
          "floor","You cannot see the floor but you hope it is down there somewhere",
          "ladder","The ladder is covered in rust and looks very dangerous",
          "hatch","The hatch appears to be firmly shut and you do not think\n" +
                  "can open it",
        });
  dest_dir=({"players/persephone/rooms/pit3","west",
           });
}
init(){
 ::init();
  add_action("dig1","dig");
  add_action("climb1","climb");
  add_action("force1","force");
  add_action("force1","open");
}
dig(str){
 if (str=="sewerage"||str=="slime"){
  if(nodig=="yes"){
   write("You begin to dig down into the sewage and slime coming\n" +
         "to a drain. allowing all the filth to flow out of the room\n\n");
   say(CAPTPLNM + " digs through the muck allowing it to drain\n");
   nodig="no";
   return 1;
  }
  write("There is nothing really to dig unless you want to try and\n" +
        "dig through the grate in the floor\n\n");
  say(CAPTPLNM + " tries to dig the thin air.");
  return 1;
 }
 write("What do you want to dig\n\n");
 return 1;
}
climb1(str){
 if(str=="ladder"){
  write("You carefully climb up the ladder but are stopped by\n" +
        "a closed trap door stop you perhaps you should open it\n\n");
  say (CAPTPLNM + " begins to climb up the ladder but comes to\n" +
       "a sudden stop\n");
  lads=TPL;
  return 1;
 }
 write("what are you trying to climb?\n");
 say(CAPTPLNM + "looks like he wants to climb something\n");
 return 1;
}
force1(str){
 if(lads==TPL){
  if(str=="hatch"||str=="door"){
   write("You manage to open the hatch far enough so you can slide\n" +
         "under it\n\n");
   TPL->move_player("sliding through a hatch up#" + "players/persephone/rooms/sto");
   return 1;
  }
  write("You cannot shift the hatch from here\n");
  say(CAPTPLNM + " tries to open the hatch but is to short\n" +
      "maybe they should try the ladder\n\n");
  return 1;
 }
 write("what do you want to open?");
 return 1;
}

