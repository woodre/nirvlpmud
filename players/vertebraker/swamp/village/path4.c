#include "../define.h"
int open,knocks;

inherit ROOM;

reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("A village pathway");
   set_long(
"     As you wander through the village, taking in the sights and sounds,\n"+
"you notice a small ramshackle hut south from where you are. Tufts of\n"+
"billowy black smoke puff from the darkened chimney at the top of the\n"+
"hut, and a small wooden door leads inside.  North you see a small,\n"+
"shallow pool amidst all this.\n");
   add_item(({"pool","shallow pool"}),"A shallow pool lies to the north, inviting you\n"+
      "to swim within its depths");
   add_item(({"smoke","black smoke","tufts"}),"Black puffs of smoke emit from the chimney");
   add_item("chimney","A dark stone chimney rises from the small hut");
   add_item("hut","A small, gloomy hut.\nA small sign rests on its side");
   add_item("sign","Perhaps you should read this");
   add_item("door","A small wooden door");
   add_item("sights","Not really that much to see");
   add_listen("sounds","Silence is golden."); 
   add_exit("/players/vertebraker/swamp/village/pool","north"); 
   if(random(2)) add_object(NPC_DIR+"villager");
   add_exit("/players/vertebraker/swamp/village/path5","east");
   add_exit("/players/vertebraker/swamp/village/jhut","south"); 
   add_exit("/players/vertebraker/swamp/village/path3","northwest"); }

init() {
   ::init();
   add_action("read","read");
   add_action("knock","knock");
   add_action("open","open");
   add_action("south","south"); }

south() {
   if(TP->query_npc()) return 1;
   if(!open && !TP->query_npc()) {
      write("You clunk your head against the door!\n");
      say(TPN+" clunks "+POS+" head against the door!\n");
      return 1; }
   write("You step into the small hut.\n");
   open = 0;
}

open(str) {
   if(str == "door") {
      if(open) {
         write("It is already open.\n");
         return 1; }
      write("The door has been latched from the inside.\n");
      return 1; }
}

read(str) {
   if(str == "sign" || str == "door") {
      write("\n\nKnock three times and you shall be allowed entrance.\n\n-Juribel\n");
      return 1; }
}

knock() {
   write("You knock on the door.\n");
   say(TPN+" knocks on the door.\n");
   knocks += 1;
   if(knocks == 3) call_out("come_in",5);
   return 1; }

come_in() {
   tell_room(TO,"The door flies open!\nYou hear a voice call, \"Oh.  Come in!\"\n");
   knocks = 0;
   open = 1;
   return 1; }
