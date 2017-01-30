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
  ""+RED+"\t$"+NORM+YEL+"#"+GRN+"@@"+YEL+"######"+HIM+"~"+NORM+"\n"+
   ""+GRN+"\t@"+YEL+"####"+GRN+"@@@@"+YEL+"#"+HIM+"~"+NORM+"\n"+
   ""+GRN+"\t@@@@"+YEL+"#"+BLU+"X"+YEL+"####"+HIM+"~"+NORM+"\n"+
   ""+GRN+"\t@"+YEL+"#"+GRN+"@@@@@"+YEL+"#"+GRN+"@@@"+NORM+"\n"+
   ""+GRN+"\t@"+YEL+"#"+GRN+"@@@"+YEL+"##"+GRN+"@@@@"+NORM+"\n"+
   ""+GRN+"\t@@"+YEL+"#####"+GRN+"@@@@"+NORM+"\n"+
   ""+GRN+"\t@@@@@@@@@@@\n"+NORM+"";
   items = ({
         "path","A grassy path which looks well traveled over.\nThe path stretches west and south, making an\nabrupt stop back east as it meets the "+HIM+"Living Ooze"+NORM+"",
         "forest","A thick forest, full of trees",
});
   
}

short(){ return ""+GRN+"Forest of Silence"+NORM+""; }

init(){
   ::init();
   add_action("search_me","search");
   add_action("east","east");
   add_action("west","west");
   add_action("north","north");
   add_action("south","south");
}

west(){
write("You follow the path to the west.\n");
this_player()->move_player("west#/players/jaraxle/3rd/silence/rooms/6E");
   return 1; }

south(){
write("The trees block the path to the south.\n"); 
return 1; }

east(){
write("You follow the path to the east.\n");
this_player()->move_player("east#/players/jaraxle/3rd/silence/rooms/6G");
return 1; }

north(){ write("The trees block the path to the north.\n"); return 1; }


search_me(str){
   if(!str){
      write("You stand at the beginning of a soft, grassy path.\n"+
         "The colorful forest looms around the path underfoot.\n");
      return 1; }
   write("You search the "+str+" and find nothing of intrest.\n");
   return 1; }
