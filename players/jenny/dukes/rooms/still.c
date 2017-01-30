inherit "/players/jenny/room";
#include "/players/jenny/define.h"
int amt;
reset(arg) {
   amt = 1+random(2);
   if(arg) return;
   set_light(1);
   set_search(BOLD+"You find some jugs next to the still."+NORM);
   short_desc=(BOLD+"An old still"+NORM);
   long_desc=
   "You have reached a secluded clearing, hidden from the\n"+
   "road by all the trees.  A still, which is used to make\n"+
   "moonshine, sits on the ground in front of you.  Judging\n"+
   "by the well trampled grass, it looks as if this place is\n"+
   "still used quite often.\n";
   items = ({
         "trees","A dense layer of cottonwood, oak, and willow trees",
         "grass","The grass is trampled into the ground",
         "still","This still is used to make some of Hazzard's best moonshine.\n"+
         "It is owned by Boss Hogg.  There might be some moonshine\n"+
         "left in the still.  You might be able to "+MAG+"bottle shine"+NORM+"",
         "jugs","These jugs are used to bottle moonshine",
         "jug","These jugs are used to bottle moonshine",
});
   dest_dir = ({
         "/players/jenny/dukes/rooms/dr1","path",
});
}
init() { 
   ::init();
   add_action("shine","bottle");
}
shine(arg)  {
   if(!arg) { write("Bottle what?\n"); return 1; }
   if(arg != "shine") { write("Bottle what?\n"); return 1; }
   if(arg == "shine" && amt > 0) {
      if(!this_player()->add_weight(2)) {
         write("You can't carry that.\n");
         return 1; }
      write(BOLD+"You fill a jug up with shine from the still."+NORM+"\n");
      MOCO("/players/jenny/dukes/items/shine.c"),TP);
amt = amt - 1;
return 1;  }
if(amt < 1) {
write(BOLD+"The still is empty."+NORM+"\n");
return 1;  }
}
