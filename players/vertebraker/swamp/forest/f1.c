#include "../define.h"
inherit ROOM;

reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("Before a great chasm");
   set_long(
"     A deep, dark chasm extends in front of you for about a thousand\n"+
"feet straight to the north.  Mist rises up from beneath the pit, and\n"+
"while you wipe it away from your eyes, you spy a thin, dangerous\n"+
"looking bridge tied from this edge of the cliff across the chasm to\n"+
"the north.\n");
   add_item(({"dark chasm","pit","chasm"}),
      "A deep, dark chasm is fastened between the cliff you are standing\n"+
      " on and the other side.  There is a thin bridge that you could\n"+
      " possibly \"cross\"");
   add_exit(FOREST+"f2","east");
   add_item("bridge",
      "A thin, dangerous bridge creaks perilously from this side of\n"+
      " the cliff to the other.  You could \"cross\" it, if you have\n"+
      " the guts");
   add_item("cliff",
      "The cliff you are standing on ...\n"+
      " Whoa! It sure is a long way down...");
   add_item("mist","A veil of mist rises in front of you, blinding\n"+
      " you to the other side of the chasm"); 
   add_item("other cliff","The other cliff is veiled in a shadow of mist"); 
   set_chance(5);
   add_msg("The mist floats out above your head.....");
   add_msg("The mist subsides a bit, showing a few gaps\n"+
      " in the frail bridge."); }

init() {
   ::init();
   add_action("cross","cross"); }

cross(str) {
   if(!str) return 0; 
   if(str == "bridge" || str == "the bridge" || str == "wood bridge" || str == "rope bridge") {
      write("You wobble onto the bridge and start your ascent...\n");
      say(TPN+" wobbles onto the bridge.....\n");
      move_object(TP,FOREST+"bridge2");
      command("look",TP);
      return 1; }
}
