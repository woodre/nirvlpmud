inherit "/obj/treasure.c";
#include "/players/fred/ansi.h"

reset (arg) {
 set_id("room_chat_device");
 call_out("chatter", 30+random(100));
}

chatter(){
 int x;
 string mess;
 x = random(4);
 switch(x){
   case 0: mess = "Wind whips around you"; break;
   case 1: mess = "Small rain drops fall from above"; break;
   case 2: mess = "You hear voices from the west"; break;
   case 3: mess = "Thunder rolls off in the distance"; break;
   }
 tell_room(environment(this_object()),
   mess+".\n");
 call_out("chatter", 30+random(100));
}

get() { return; }
