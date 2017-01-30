#include "/players/beck/esc.h"
#include "/players/beck/MortalKombat/MKSymbol3.h"
id(str){ return str == "statue" || str == "monk" || str == "light"; }
short(){ return "A statue of a monk from the Temple of Light"; }
long(){ write("This statue is made of solid jade.\n"+
   "It looks just like a monk from the Temple of Light.\n"+
   "If you stick around a while it may inform you of something.\n"+
   "Ask Dragnar or Beck ONLY for information.\n"+
   "Do not ask other wizards for info on this...They do not know!\n"+
   "");
   return 1;
}
get(){ return 0; }
drop(){ return 1; }

reset(){
   call_out("message1",60);
}

message1(){
   tell_room(environment(this_object()),
      "The monk suddenly comes to life!\n");
   call_out("message2",10);
}
message2(){
   tell_room(environment(this_object()),
      "He gestures, and a screen appears with the following:\n");
   call_out("message3",20);
}
message3(){
   tell_room(environment(this_object()),
      "In each of us, there burns the fury of a warrior...\n");
   call_out("message4",10);
}
message4(){
   tell_room(environment(this_object()),
      "Every generation, a few are chosen to prove it...\n");
   call_out("message5",10);
}
message5(){
   tell_room(environment(this_object()),
      "And defend our world from Shang Tsung and the armies of darkness...\n");
   call_out("message6",10);
}
message6(){
   tell_room(environment(this_object()),
      "In an ancient Tournament...\n");
   call_out("message7",10);
}
message7(){
   tell_room(environment(this_object()),
      "Where one more victory, and our world is their's...\n");
   call_out("message8",10);
}
message8(){
   tell_room(environment(this_object()),
      "TEST YOUR MIGHT!\n");
   call_out("message9",20);
}
message9(){
   tell_room(environment(this_object()),
      "In association with Nirvana Entertainment...\n");
   call_out("message10",10);
}
message10(){
   tell_room(environment(this_object()),
      "A Dragnar and Beck production...\n");
   call_out("message11",15);
}
message11(){
   WriteMKSymbol();
   tell_room(environment(this_object()),"                            MORTAL KOMBAT\n");
   call_out("message12",10);
}
message12(){
   tell_room(environment(this_object()),
"Kombat has Begun!\n"+
"Seek out a great Martial Arts master to learn how to enter!\n");
   call_out("message13",10);
}
message13(){
   tell_room(environment(this_object()),
      "The monk turns back to jade.\n");
   call_out("message1",10000);
}
