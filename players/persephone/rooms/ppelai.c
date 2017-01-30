inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset(int arg){
if(!present("Purple")) {
  move_object(clone_object("players/persephone/monsters/ppeat"), TOB);
 }
 if (!arg) {
  set_light(1);
  short_desc="Small Alcove";
  long_desc="You definately should not have entered this alcove as it is\n" +
            "the home of The Purple People Eater. Your only hope\n" +
            "now is that he is not home. All around you are the remains of\n" +
            "of some of his unfortunate victims. The only exit appears to\n" +
            "be south out the crack.\n" +
            "\n";
  items=({"alcove","The alcove is extremely forlorn and you really do not want\n" +
                   "to stay in here long",
          "floor","The floor is a hideous puce with many shrunken skulls\n" +
                  "lying around you guess that is all that remains of The\n" +
                  "Purple People Eater's last victims",
          "skulls","They are definitely human and shrunken",
          "bones","They are human bones and look as if they have been used\n" +
                  "for toothpicks",
          "walls","The walls are totally barren exept for the crack in the\n" +
                  "south wall that you entered through and a chest\n" +
                  "placed against the east wall",
          "ceiling","There are large Stalagtites hanging down from it",
          "chest","The chest appears unlocked perhaps you can open it",
          "stalagtites","They are sharp and appear to be made of limestone",
        });
  dest_dir=({"players/persephone/rooms/pit2","out",
           });
 }
}
realm() { return "NT"; }
init(){
 ::init();
  add_action("open1","open");
  add_action("peace","peace");
  add_action("peace","fog");
  add_action("peace","calm");
  add_action("call","call");
  add_action("call","pearl");
  add_action("call","change");
  add_action("call","ghoul");
  add_action("attack","attack");
  add_action("quit","quit");
  add_action("stun","stun");
  add_action("shelter","shelter");
  add_action("death","death");
  add_action("levitate","levitate");
  add_action("adren","adren");
  add_action("recall","recall");
  add_action("swarm","swarm");
}
open1(str){
 if(str=="chest" || str=="box"){
  write("Carefully you open up the chest and find a vast treasure of bones\n");
  say(CAPTPLNM + " opens the chest\n");
  return 1;
 }
}
peace(arg){
 if(!arg){
  write("The Purple People Eater continues to fight ignoring your peace spell.\n\n");
 return 1;
 }
 if(arg){
  write("The Purple People Eater continues to fight ignoring your peace spell.\n\n");
 return 1;
 }
}
attack(arg){
 if(!arg){
  write("Your Falcon refuses to attack\n\n");
 return 1;
 }
 if(arg){
  write("Your Falcon refuses to attack\n\n");
 return 1;
 }
}
quit(arg){
 if(!arg){
  write("You really do not want to quit here\n\n");
 return 1;
 }
 if(arg){
  write("You really do not want to quit here\n\n");
 return 1;
 }
}
call(arg){
 if(!arg){
  write("No matter how hard you call your pet does not respond\n\n");
 return 1;
 }
 if(arg){
  write("No matter how hard you call your pet does not respond\n\n");
 return 1;
 }
}
stun(arg){
 if(!arg){
  write("The Purple People Eater shrugs off your stun!\n\n");
 return 1;
 }
 if(arg){
  write("The Purple People Eater shrugs off your stun!\n\n");
 return 1;
 }
}
shelter(arg){
 if(!arg){
  write("You seem unable to erect your shelter in this environment\n\n");
 return 1;
 }
 if(arg){
  write("You seem unable to erect your shelter in this environment\n\n");
 return 1;
 }
}
death(arg){
 if(!arg){
  write("The Purple People Eater shrugs off your puny death spell\n\n");
 return 1;
 }
 if(arg){
  write("The Purple People Eater shrugs off your puny death spell\n\n");
 return 1;
 }
}
levitate(arg){
 if(!arg){
  write("Your spell seems to fail no matter what you do\n\n");
 return 1;
 }
 if(arg){
  write("Your spell seems to fail no matter what you do\n\n");
 return 1;
 }
}
adren(arg){
 if(!arg){
  write("You cannot get your adrenillin pumping\n\n");
 return 1;
 }
 if(arg){
  write("You cannot get your adrenillin pumping\n\n");
 return 1;
 }
}
recall(arg){
 if(!arg){
  write("You cannot remember what you were trying to recall\n\n");
 return 1;
 }
 if(arg){
  write("You cannot remember what you were trying to recall\n\n");
 return 1;
 }
}
swarm(arg){
 if(!arg){
  write("The swarm flies about lazily\n\n");
 return 1;
 }
 if(arg){
  write("The swarm flies about lazily\n\n");
 return 1;
 }
}

