inherit "room/room";
#include "definitions.h"

int itemtake;
int presentsword;
int presentarmor;

void init() {
     write("You descend the stairs and enter a small room.\n");
     add_action("take","take");
     add_action("search","search");
     ::init();
}

reset(arg) {

itemtake = 0;
presentarmor = 1;
presentsword = 1;

        if(!arg) {
        set_light(1);
        short_desc=("Archive of the Lost Artifacts");
        long_desc=
"       Finally you have reached the Archive of Lost Artifacts.  \n"+
"As you look around, you see a fantastic white marbled room.  \n"+
"The walls emit a mystical bright light, which pierces your \n"+
"now light-sensitive eyes.  At opposite ends, in the center of the\n"+
"two side walls, two huge metal claws rest slightly closed.  \n"+
"One claw is made of copper, the other of lead.\n";

   dest_dir=({
   CASTLEROOM+"/firelord.c","up"  ,
            });

   items=({
   "marble","     The marble walls form perfect right angles to eachother",
   "walls","     The walls seem strangely enchanted",
   "claws","     Which claw, the copper or lead claw?",
   "claw","     Which claw, the copper or lead claw?",
   "lead claw","     The lead claw looks interesting, there may be more to it",
   "copper claw","     The copper claw looks interesting, there may be more to it",
         });
   }   }

int take (string str) {
if (!str) {
   write("What do you take?\n");
   return 1;}
if ((str=="claw") || (str == "claws")) {
   write("Perhaps you should get what's in the claws instead.\n");
   return 1;}
if (str == "sword") {
   if (presentsword == 1) {
   presentsword = 0;
   write("As you reach towards the claw, it opens....\n\n");
   write("A flaming sword slips out of its grasp!\n\n");
   move_object(clone_object(CASTLEOBJECT+"/firesword.c"), this_object());
   itemtake++;
   return 1;}
 return 0;}

if (str == "armor") {
   if (presentarmor == 1) {
   presentarmor = 0;
   write("As you reach towards the claw, it opens....\n\n");
   write("A shining suit of armor falls out of its grasp!\n\n");
   move_object(clone_object(CASTLEOBJECT+"/armageddon.c"),this_object());
   itemtake++;
   return 1;}
 return 0;}
return 0;
}

search(string str) {
  if(!str) return 0;
  if(str == "claws" || str == "claw") {
    write("Which claw, copper or lead.\n");
    return 1; }
  if(str == "copper claw") {
    if(presentsword) write("There is a sword inside the claw.\n");
    else write("The claw is open and empty.\n");
    return 1; }
  if(str == "lead claw") {
    if(presentarmor) write("There is a suit of armor inside the claw.\n");
    else write("The claw is open and empty.\n");
    return 1; }
  return 0;
}
