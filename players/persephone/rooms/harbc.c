#include "/players/persephone/rooms.h"
inherit "/players/persephone/closed/thingys.c";
reset (arg){
  if(!present("joe")){
    move_object(clone_object("players/persephone/monster/joe"), TOB);
  }
 if (!arg) {
  set_light(1);
  short_desc="Harbour's Edge";
  long_desc="The Harbour seems to come to sudden end here and directly to your West\n" +
            "you can see a huge wasteland which looks inpenetrable. Back to the east\n" +
            "you see the center of the harbour while to the south you see an old\n" +
            "road lead to the center of Stormhold. To the Northeast is a wharf\n" +
            "however there is a large fence in front of it.  \n";
  items=({"harbour","What do you mean harbour? I would have thought everyone new what\n" +
                    "a harbour was. Well actually it is where ships come to supply\n" +
                    "the town but in the case of Stormhold it is a haven for pirates",
          "wasteland","A huge desolate tract of land that looks totally inhospitable\n" +
                      "and by all appearences you would not be able to go there",
          "fence","This is an extremely tall wire fence that blocks off the wharf.\n" +
                  "The fence appears to have a large sign on it",
           "wharf","This wharf is well a wharf where ships come to berth or dock\n" +
                   "however it looks totally unsafe to walk on but there does appear\n" +
                   "to be a large ship docked against it.",
           "road","This road looks very poorly maintained and seems to be totally\n" +
                  "desolate",
            "Stormhold","From what you can remember while you were at school Stormhold\n" +
                        "was once the Idyllic Capital of Nirvana but has now been\n" +
                        "conquered by Pirates",
           "sign","A very large sign with big letters. You feel you should read the\n" +
                  "sign as it might reveal some valuable information",
  });
  dest_dir=({"players/persephone/rooms/harbb","west",
            "players/persephone/rooms/road3a","south",
  });
 }
}
realm(){ return "NT"; }
init(){
 ::init();
  add_action("read1","read");
  add_action("climb1","climb");
}
read1(str){
 if(str=="sign"){
  write("             Secured Area Trespassers are not allowed\n" +
        "             if you ignore this sign and try to enter\n" +
        "             great harm will confront you\n\n");
  say(CAPTPLNM + " reads the old but important sign\n");
  return 1;
 }
 write("Specify what you want to read!!!!!!!!!!!!\n\n");
 return 1;
}
climb1(str){
 if(str=="fence"||str=="mesh"){
  write("You foolishly try to climb the fence to enter the secured area\n" +
        "and are attacked by a swarm of Killer Wasps\n\n");
  say(CAPTPLNM + " attempts to climb the fence but falls in agony\n");
  return 1;
 }
 write("You would not be foolish enough to climb the fence would you\n\n");
 return 1;
}
