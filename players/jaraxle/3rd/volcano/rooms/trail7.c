/* 03/14/06 Earwax: Closed this area, needs to be recoded for efficiency */
/*  10/08/06 - Rumplemintz
      Moved inherit above #include statement
      Changed CAVE from int to string and moved definition to top of enter() function
*/

inherit "/players/jaraxle/room2.c";
#include "/players/jaraxle/define.h"
int i;
reset(arg) {
   if(arg) return;
   set_light(1);
  long_desc =
   "\n"+
   ""+GRN+"\t@@@@@@@@@@@\n"+
   "\t@@@@@@@@@@@\n"+
   "\t@@@@"+YEL+"##"+GRN+"@@@@@\n"+
   "\t@@@"+YEL+"#"+RED+"**"+YEL+"#"+GRN+"@@@@\n"+
   ""+YEL+"\t####"+NORM+RED+"**"+YEL+"#"+GRN+"@@@@\n"+
   "\t@@@"+YEL+"#"+NORM+RED+"**"+YEL+"#"+GRN+"@@@@\n"+
   "\t@@@@"+YEL+"#"+HIB+"X"+NORM+GRN+"@@@@@\n"+
   "\t@@@@@@@@@@@\n"+
   "\t@@@@@@@@@@@\n"+
   "\t@@@@@@@@@@@"+NORM+"\n";
items = ({ 
  "trees","Thick trunks reach high up sprouting with abuntant amounts of foliage\nThe trees bar passage in any direction around the path",
  "opening","A dark opening in the mountainside you can "+HIW+"enter"+NORM+"",
  "mountain","The mountain rises high above.\nThe mountains girth prohibits viewing anything around it.\nThere is a trail following around the base of the mountain",
  "base","The wide base of the mountain is a dark, burned orange color.\nA smooth trail follows it around to the northeast and south",
  "forest","The forest follows on the left edge of the trail.\nThe trees have grown very close together, prohibiting venture into the forest from here",
  "trail","A smooth sandy trail follows closely around the base of the mountain\nThe trail leads west and northeast",
         "cave","A dark cave dug out from the mountainside.\nYou can "+HIW+"enter"+NORM+" this cave",
});
for(i = 0; i < 0 + random(3); i++)
   {
    MOCO("/players/jaraxle/3rd/volcano/mons/snake.c"),TO);
}

}
         
short(){ return "Third Earth"; }

init(){
   ::init();
   
   add_action("enter","enter");
   add_action("north","north");
   add_action("south","south");
   add_action("the_key","key");
   add_action("west","west");
   add_action("east","east");
   add_action("northeast","northeast");
   add_action("search_me","search");
}

west(){
write("You follow the path to the west.\n");
   TP->move_player("west#/players/jaraxle/3rd/volcano/rooms/trail8.c");
return 1; }

northeast(){
write("You follow the path to the northeast.\n");
   TP->move_player("east#/players/jaraxle/3rd/volcano/rooms/trail6.c");
return 1; }

north(){ write("The volcano blocks you in from the north.\n"); return 1; }
south(){ write("The forest blocks you in from the south.\n"); return 1; }
east(){ write("The forest blocks you in from the east.\n"); return 1; }

enter(arg){ 
  string CAVE;
   if(arg == "cave"){
/*
     write("This area has been closed for maintenance.\nSorry for the inconvenience -Earwax\n");
     return 1;
*/
      switch(random(3)){
         case 1: CAVE = "bravely"; break; case 2: CAVE = "cautiously"; break; case 0: CAVE = "carefully"; break; }
      write("\nYou "+CAVE+" enter the cave.\n");
      TP->move_player("into the volcano#/players/jaraxle/3rd/volcano/rooms/e_cave.c");
      return 1; }
   notify_fail("Enter what?\n");
   return 0;
}


search_me(arg){
if(!arg){
  write("A short, flat trail follows close to the volcanoside.  The forest\n"+
        "trees grow along the trail, barracading it into the volcano base.\n"+
        "The volcano emits heat from behind the rock base.  There is a dark\n"+
        "opening on the side of the volcano.\n");
return 1; }
  write("You search "+arg+" and find nothing of intrest.\n");
   return 1; }

the_key(){
   write("\n"+
      BLU+"\tX"+NORM+" = You are here!\n"+
      GRN+"\t@"+NORM+" = Trees (impassable)\n"+
      YEL+"\t#"+NORM+" = Walkable Path\n"+
      RED+"\t*"+NORM+" = Volcano\n"+
      RED+"\t$"+NORM+" = Further Access Denied!\n");
   return 1; }
