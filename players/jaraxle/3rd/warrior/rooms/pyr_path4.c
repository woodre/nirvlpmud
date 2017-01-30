#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room2.c";

reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
   "\n"+
   ""+GRN+"\t@@@@@"+YEL+"#"+GRN+"@@@@@\n"+
   "\t@@@@@"+YEL+"#"+GRN+"@@@@@\n"+
   "\t@@@@@"+YEL+"#"+NORM+GRN+"@@@@@\n"+
   "\t@@"+BLK+".--"+HIB+"X"+NORM+BLK+"--."+GRN+"@@\n"+
   "\t@@"+BLK+"|\\   /|"+GRN+"@@\n"+
   "\t@@"+BLK+"| \\_/ |"+GRN+"@@\n"+
   "\t@@"+BLK+"| / \\ |"+GRN+"@@\n"+
   "\t@@"+BLK+"|/___\\|"+GRN+"@@\n"+ 
   "\t@@@@@@@@@@@\n"+
   "\t@@@@@@@@@@@"+NORM+"\n";
   items = ({
  "path","A dirt path leads through the forest",
  "pyramid","A looming "+BLK+"Dark Pyramid"+NORM+" at the end of the forest",
  "forest","All of the foliage in the area seems from death, to near death",
  "trees","Large oak trees that bend away from the pyramid",
  "ground","As the forest reaches the pyramid, the grass stops growing",
  "aura","A wavy aura around the pyramid",
  "doorway","A dark doorway at the base of a pyramid you can "+BLK+BOLD+"enter"+NORM+"",
});
   
}

short(){ return "Third Earth"; }
init() {
   
   ::init();
   
   add_action("the_key","key");
   add_action("west","west");
   add_action("north","north");
   add_action("south","south");
   add_action("east","east");
   add_action("search_me","search");
   add_action("enter","enter");
}

north(){
   write("You follow the path to the north.\n");
   TP->move_player("north#/players/jaraxle/3rd/warrior/rooms/pyr_path3");
   return 1; }

south(){ write("The pyramid blocks you in from the south.\n"); return 1; }

east(){ write("The forest blocks you in from the east.\n"); return 1; }
west(){ write("The forest blocks you in from the west.\n"); return 1; }

enter(arg){
   if(arg == "doorway" || arg == "pyramid") {
      write("\n[ "+HIC+"Do not forget the "+HIW+"<"+HIG+"j_help"+HIW+">"+HIC+" commands work everywhere . . ."+NORM+" ]\n");
      write(BLK+BOLD+"\n\tEvil"+NORM+" invades your body as you enter the pyramid.\n");
      this_player()->move_player("into the pyramid#/players/jaraxle/3rd/pyramid/rooms/room");
      return 1; }
   notify_fail("Enter what?\n"); return 0; }

search_me(arg){
   if(!arg){
      write("The path ends abruptly at the base of the "+BLK+"Dark Pyramid"+NORM+".\n"+
         "The trees of the forest wilt heavily away from the pyramid\n"+
         "and the ground is grass free.  An aura of great evil can be\n"+
         "felt spewing from an open doorway of the pyramid.\n");
      return 1; }
   write("You search the "+arg+" and find nothing of intrest.\n");
   return 1; }

the_key(){
   write("\n"+
      BLU+"\tX"+NORM+" = You are here!\n"+
      GRN+"\t@"+NORM+" = Trees (impassable)\n"+
      YEL+"\t#"+NORM+" = Walkable Path\n"+
      RED+"\t$"+NORM+" = Further Access Denied!\n");
   return 1; }
