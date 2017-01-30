#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/3rd/silence/rooms/silence.c";

reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
   "\n"+
   ""+GRN+"\t@@@@@@@@@@@"+NORM+"\n"+
  ""+GRN+"\t@"+CYN+"#"+GRN+"@@@"+YEL+"#####"+GRN+"@"+NORM+"\n"+
   ""+GRN+"\t@@@@"+BLU+"X"+GRN+"@@@@@@\n"+NORM+""+
    ""+RED+"\t$"+NORM+YEL+"#"+GRN+"@@"+YEL+"######"+HIM+"~"+NORM+"\n"+
   ""+GRN+"\t@"+YEL+"####"+GRN+"@@@@"+YEL+"#"+HIM+"~"+NORM+"\n"+
   ""+GRN+"\t@@@@"+YEL+"######"+HIM+"~"+NORM+"\n"+
  ""+GRN+"\t@"+YEL+"#"+GRN+"@@@@@"+YEL+"#"+GRN+"@@@"+NORM+"\n"+
   ""+GRN+"\t@"+YEL+"#"+GRN+"@@@"+YEL+"##"+GRN+"@@@@"+NORM+"\n"+
   ""+GRN+"\t@@"+YEL+"#####"+GRN+"@@@@"+NORM+"\n"+
   ""+GRN+"\t@@@@@@@@@@@\n"+NORM+"";
   items = ({
         "path","A grassy path which looks hardly traveled over.\nThe path stretches south and northeast",
        "meadow","A small open meadow of grass",
      "opening","A this break in the trees to the northeast",
         "forest","A thick forest, full of trees",
        "trees","Thick trees surrounding the meadow",
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
    add_action("northeast","northeast");
}

west(){
   write("The trees block the path to the west.\n"); 
   return 1; }

south(){
   write("You follow the path to the south.\n");
   this_player()->move_player("south#/players/jaraxle/3rd/silence/rooms/4E");
   return 1; }

east(){
   write("The trees block the path to the east.\n"); 
return 1; }

north(){
   write("The trees block the path to the north.\n"); 
return 1; }

northeast(){
   write("You follow the path to the northeast.\n");
   this_player()->move_player("north#/players/jaraxle/3rd/silence/rooms/2F");
   return 1; }


search_me(str){
   if(!str){
write("You come to a small meadow surrounded by trees\n"+
      "on all but the southern side of this path.  A\n"+
      "small opening between two trees to the northeast\n"+
      "looks large enough for you to wander into.\n");
      return 1; }
   write("You search the "+str+" and find nothing of intrest.\n");
   return 1; }
