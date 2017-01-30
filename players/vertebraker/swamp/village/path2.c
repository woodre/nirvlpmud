#include "../define.h"
inherit ROOM;
int open;

reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("A village pathway");
   set_long(
"     A small hut sits to the west of you, with a small rickety sign\n"+
"just outside of it.  A lazy little hammock has been extended from a\n"+
"few trees, and a few worried villagers walk by, apparently looking for\n"+
"something and yelling to passersby.  The dark reaches of the forest\n"+
"stand to the northwest.\n");
   add_item(({"hut","small hut"}),"A small little wooden hut.\n"+
      "Twin doors open into the establishment");
   add_item(({"doors","door","twin doors"}),
      "Twin doors allow entrance into the small hut.\n"+
      "You just need to open them");
   set_chance(5);
   add_msg("\"Hey Ralsz?  Report to Juribel...\"");
   add_msg("\"CELIA?!?!??!!\"");
   add_msg("\"ceeeeliaaaaa!\"");
   add_msg("A man pushes his way in front of you.");
   add_msg("A guard scours the area and moves on.");
   add_item(({"sign","rickety sign"}),
      "A small wooden sign that you can \"read\"");
   add_item("hammock","A lazy little hammock is tied to two trees here");
   add_item("trees","These tall trees hold up a small hammock");
   add_item("villagers","A few scattered villagers walk by,\n"+
      "appearing to be looking for something? ..");
   add_object(NPC_DIR+"villager");
   add_exit(VILLAGE+"path1","northwest");
   add_exit(VILLAGE+"shop","west");
   add_exit(VILLAGE+"path3","southeast"); }

init() {
   ::init();
   add_action("open","open");
   add_action("close","close");
   add_action("west","west");
   add_action("read","read"); }

read(str) {
   if(str == "sign" || str == "rickety sign" || str == "the sign") {
      write(
         "\n\n\tEst. 2000\n\t\tSardka's Fine Jewelry\n\n\n");
      say(TPN+" reads the sign.\n");
      return 1; }
}

west() {
   if(!open) {
      write("The doors are not open...\n");
      return 1; } }

open(str) {
   if(open) {
      FAIL("The doors are already open...\n");
      return 0; }
   if(str == "door" || str == "doors" || str == "twin doors") {
      write("You open up the twin doors...\n");
      say(TPN+" opens up the twin doors...\n");
      open = 1;
      return 1; }
}

close(str) {
   if(!open) {
      FAIL("The doors are already closed...\n");
      return 0; }
   if(str == "door" || str == "doors" || str == "twin doors") {
      write("You close up the twin doors...\n");
      say(TPN+" closes the twin doors...\n");
      open = 0;
      return 1; }
}
