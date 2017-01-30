#include "../define.h"
inherit SWAMP
reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_long(
"     Sounds of animal chatter and life spin around in your head as you\n"+
"descend deeper into the swamp country.  Vermin crawl over your feet as\n"+
"you step, and a putrid stench arises from beneath the murky waters.\n"+
"You feel as though you are in no-man's land on the brink of insanity.\n");
   add_listen("main","You hear the sounds of animal chatter.");
   add_listen("sounds","Chirp! CREAK! CROAK! Squawk!");
   add_listen("chatter","Chirp!  CREAK!  CROAK!  Squawk!");
   add_item("vermin","Small rats and snakes");
   add_item("rats","Tiny blackish brown rodents\nthat crawl speedily through the slick muck");
   add_item("snakes","Small green snakes that dart beneath the waters");
   add_item("waters","Murky and deep");
   add_exit(ROOMS+"s24","west");
   add_exit(ROOMS+"s10","northeast");
   add_exit(ROOMS+"s2","south");
}
