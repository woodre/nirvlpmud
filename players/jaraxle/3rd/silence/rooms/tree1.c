#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/3rd/silence/rooms/silence.c";

reset(arg) {
   if(arg) return;
   set_light(1);
   
   long_desc =
"\n"+
   ""+GRN+"\t@@      @@\n"+
   "\t@@      @@\n"+
   "\t@@      @@\n"+
   "\t@@      @@\n"+
   "\t@@      @@"+NORM+"\n";
   items = ({
    "trees","Two giant oak trees, on each side of you",
    "forest","A thick forest to the north",
    "path","You can see the path to the south",
});
   MOCO("/players/jaraxle/3rd/silence/mon/baby.c"),TO);
MOCO("/players/jaraxle/3rd/silence/mon/g_fairy.c"),TO);
MOCO("/players/jaraxle/3rd/silence/mon/baby.c"),TO);

}
short(){ return ""+GRN+"Forest of Silence "+HIG+"("+NORM+GRN+"between the trees"+HIG+")"+NORM+""; }
init(){
   ::init();
   add_action("search_me","search");
   add_action("east","east");
   add_action("west","west");
   add_action("north","north");
   add_action("south","south");
}
north(){ write("The trees block you in to the north.\n"); return 1; }
east(){ write("The trees block you in to the east.\n"); return 1; }
west(){ write("The trees block you in to the west.\n"); return 1; }
south(){
write("You step out from the trees, and back onto the path.\n");
this_player()->move_player("south#/players/jaraxle/3rd/silence/rooms/4I");
return 1; }
search_me(str){
   if(!str){
   write("You're standing between two hulking trees.\n"+
    "A forest of thinner trees blocks you in from\n"+
    "the north. You can walk back south onto the path.\n");
      return 1; }
   write("You search the "+str+" and find nothing of intrest.\n");
   return 1; }
