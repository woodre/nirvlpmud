#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/3rd/silence/rooms/silence.c";

reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
   "\n"+
   ""+GRN+"\t@@@@@@@@@@@"+NORM+"\n"+
   ""+GRN+"\t@"+CYN+"#"+GRN+"@@@"+YEL+"#####"+GRN+"@"+NORM+"\n"+
   ""+GRN+"\t@@@@"+YEL+"#"+GRN+"@@@@@@\n"+NORM+""+
   ""+RED+"\t$"+NORM+YEL+"#"+GRN+"@@"+YEL+"#####"+BLU+"X"+HIM+"~"+NORM+"\n"+
   ""+GRN+"\t@"+YEL+"####"+GRN+"@@@@"+YEL+"#"+HIM+"~"+NORM+"\n"+
   ""+GRN+"\t@@@@"+YEL+"######"+HIM+"~"+NORM+"\n"+
   ""+GRN+"\t@"+YEL+"#"+GRN+"@@@@@"+YEL+"#"+GRN+"@@@"+NORM+"\n"+
   ""+GRN+"\t@"+YEL+"#"+GRN+"@@@"+YEL+"##"+GRN+"@@@@"+NORM+"\n"+
   ""+GRN+"\t@@"+YEL+"#####"+GRN+"@@@@"+NORM+"\n"+
   ""+GRN+"\t@@@@@@@@@@@\n"+NORM+"";
   items = ({
         "path","A grassy path which looks well traveled over.\nThe path stretches west and south, making an\nabrupt stop back east as it meets the "+HIM+"Living Ooze"+NORM+"",
         "forest","A thick forest, full of trees",
         "walk","A narrow path stretching to the west, and south",
         "opening","It looks like a way out of the forest to the south",
         "ooze",""+HIM+"Purple ooze seemingly out of nowhere.  The ooze might be sticky to the touch.\nIt smells rotten and repugnant"+NORM+"",
         "living ooze",""+HIM+"Purple ooze seemingly out of nowhere.  The ooze might be sticky to the touch.\nIt smells rotten and repugnant"+NORM+"",
});
   
}

short(){ return ""+GRN+"Forest of Silence"+NORM+""; }

init(){
   ::init();
   add_action("the_key","key");
   add_action("search_me","search");
   add_action("east","east");
   add_action("west","west");
   add_action("north","north");
   add_action("south","south");
}

west(){
   write("You follow the path to the west.\n");
   this_player()->move_player("west#/players/jaraxle/3rd/silence/rooms/4I");
   return 1; }

south(){
   write("You follow the path to the south.\n");
   this_player()->move_player("south#/players/jaraxle/3rd/silence/rooms/5J");
   return 1; }

east(){ write("The "+HIM+"Living Ooze"+NORM+" blocks your way to the east.\n"); return 1; }

north(){ write("The trees block the path to the north.\n"); return 1; }

search_me(str){
   if(!str){
      write("The path is forced into a bend, trimmed on two sides\n"+
         "from the forest, and the "+HIM+"Living Ooze"+NORM+".  The path\n"+
         "forms a narrow walk to the west, and you see an\n"+
         "opening in the forest to the south.\n");
      return 1; }
   write("You search the "+str+" and find nothing of intrest.\n");
   return 1; }
