#include "/players/hippo/bs.h"
inherit "obj/monster";
void reset(int arg){
   ::reset(arg);
     if(arg) return;
set_name("aqua_dynamica");
set_short("Hippo's mind");
set_long ("Hmm.. what did you expect to see, looking at a 'mind' ?\n"+
        "I don't think you can see them. They just exist, that is all.\n");
set_level(100);set_ac(1000);set_aggressive(0);
set_chat_chance(1);
   load_chat("Hippo's mind grins...\n");
   load_chat("Hey, man! Hurry up a bit!\n");
   load_chat("Can't you move faster?\n");
   load_chat("You are sure about your last move?\n");
   load_chat("Hmm.. I don't think you'll make it before reboot.\n");
}
