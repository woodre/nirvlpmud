inherit "/players/jaraxle/3rd/silence/rooms/no_exit.c";
#include "/players/jaraxle/define.h"

reset(arg) {
   if(arg) return;
   set_light(1);
   
   long_desc =
   "\n"+
   ""+GRN+"\t***********\n"+NORM+""+
   ""+GRN+"\t*"+YEL+"^^^^^^^^^"+GRN+"*\n"+NORM+""+
   ""+GRN+"\t*"+YEL+"^^^^^^^^^"+GRN+"*\n"+NORM+""+
   ""+GRN+"\t*"+YEL+"^^^^^^^^^"+GRN+"*\n"+NORM+""+
   ""+GRN+"\t***********\n"+NORM+"";
   items = ({
         "dirt","Solid, dark brown dirt which has been packed over the years into a hard clay",
         "clay","Dark brown dirt which has been packed solid",
         "fire","A small log fire which burns effortlessly",
         "shelves","Small holes in the walls made into shelves.\nUnique items can be seen on the shelves",
         "unique items","Items of a foreign nature.  They look like some sort of tools",
         "tools","Minature tools, too small for you to use",
});
   
   dest_dir = ({
         "/players/jaraxle/3rd/silence/rooms/6J","out",
});

MOCO("/players/jaraxle/3rd/silence/mon/baby.c"),TO);
MOCO("/players/jaraxle/3rd/silence/mon/baby.c"),TO);
MOCO("/players/jaraxle/3rd/silence/mon/baby.c"),TO);
MOCO("/players/jaraxle/3rd/silence/mon/baby.c"),TO);

}

short(){ return ""+GRN+"Forest of Silence "+HIG+"("+NORM+GRN+"mound"+HIG+")"+NORM+""; }
init(){
   ::init();
   add_action("search_me","search");
}

search_me(str){
   if(!str){
      write("You're standing on hard packed dirt that makes a small room inside the mound.\nYou see a small fire roasting calmly in the center of the room.\nSmall shelves are dug into the dirt packed walls.\n");
      return 1; }
   if(str == "shelves"){
      write("You search the shelves but find nothing of value.\n");
      return 1; }
   write("You search "+str+" but find nothing.\n");
   return 1; }
