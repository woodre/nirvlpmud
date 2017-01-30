#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

int light;

object ladder;

int UNLOCK;
int push;
int X;

reset(arg) {
  if(!present("creature")) {  
    move_object(clone_object("/players/brittany/kadath/NPC/rockworm.c"),this_object());
   }
   if(arg) return;
   set_light(1);   
   short_desc = MAG+"Kadath"+NORM;
   long_desc =
   "     The huge monstrous steps goes higher up into the tower.  An\n"+
   "outline of a door looks to be made into the ceiling.  On the wall\n"+
   "is another small clay sconce.\n";

   items = ({
         "ceiling","The ceiling is 50 feet high",
         "tower","The tower is huge and made of stone",
         "bas-relief","A small sculpture, with a figure projected slightly in the\n"+
         "background",
          "figure","A pictorial of a human form",
         "landing","The platform at the top of the steps",
         "platform","The landing at the top of the steps",
         "candle","A candle sits inside the clay sconce, maybe you could 'light' it",
         "latch","The latch is made of steel, maybe you can 'unlock' it",
         "steps","The stone steps are monstrous, nearly a yard high",
         "sconce","The clay sconce with a candle inside, is mounted on the wall maybe\n"+
         "you should 'light' it",
         "symbols","Some hieroglyeric symbols on the sconce",
         "door","A stone trapped door with a latch on it",
         "ladder","A metal ladder is leaning against the wall, maybe you can\n"+
         "'climb' up",
         "wall","A clay sconce is mounted on the wall",
          });

   dest_dir = ({
         "/players/brittany/kadath/k33.c","down",
          });
}
   
init() {
  ::init();
  add_action("unlock","unlock");
  add_action("push","push");
  add_action("push","open");
  add_action("climb","climb");
  add_action("light_candle","light");
  add_action("light_sconce","light");
 add_action("search","search");
}

light_candle(str) {
    if(!str || str != "candle") {
        notify_fail("What do you want to light?\n");
        return 0; 
    }
    write(
"     The candle flickers softly, and lights up the landing.  You\n"+
"see a ladder leaning against the wall.\n");
    return 1; 
}
light_sconce(str) {
    if(!str || str != "sconce") {
        notify_fail("What do you want to light?\n");
        return 0; }
    write(
"     The candle flickers softly, then lights up the stairs.  You\n"+
    "see a ladder leaning against the wall.\n");
   return 1; }
 


climb(str) {
  if(!str || str != "ladder") {
     notify_fail("Climb what?\n");
     return 0; 
  }
  if(!ladder) {
     write("You climb the ladder up to the stone door.\n");
     ladder = this_player();
     return 1; 
  }
  if(ladder == this_player()) {
    write("You climb back down the ladder.\n");
    ladder = 0;
    return 1;
  }
  write(ladder->query_name()+" is already up there.\n");
  return 1;
}


unlock(str) {

  if(str != "latch") {
    write("Unlock what?\n");
    return 1;
  }

  if(ladder != this_player()) {
    write("You can not reach the latch from here.\n");
    return 1; 
  }

  if(X==0) {
    write("You hear a loud CLICK!!  as the latch unlocks.  'Push' to open the door.\n");
    X++;
    return 1;
  }
}

push(str) {
  if(!str) {
    notify_fail("Push what?\n");
    return 0; 
  }
 
  if(X==0) {
    notify_fail("You try to push the door, but it is latched.\n");
    return 0; 
  }
 
  if(X==1) {
    write("You push and the door OPENS!\n"+
          "You move into a dark room.  Your vision blurs.\n\n"+
        "When your eyes focus you see that you are back in the Enchanted woods.\n\n");
    say(tpn+  " pushes the door and moves into the unknown.\n");
    tp->move_player("into the unknown#/players/brittany/kadath/k20.c");
    X ++;
    return 1; 
  }
 
  if(X==2) {
    notify_fail("The door is already open.\n");
    return 0; 
  }
}

exit() {
  if(this_player() == ladder)
    ladder = 0;
}

search(){
  notify_fail("You find nothing of interest.\n");
  return 0;
}
