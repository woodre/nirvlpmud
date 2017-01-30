#include "/players/jaraxle/define.h"
inherit "/obj/treasure.c";

reset(arg){
   if(arg) return;
   set_alias("quilt");
   set_short("Boob Quilt");
   set_long(",8888M,,,,,888,,,,,,,88,,,8888888,,,,,,,,MmMMMMMMMMM\n"+
      ",8888M,,,,,,,88,,,,,,,,8,,,,,888888,,,M,,,,,MMMMMMMM\n"+
      ",888MM,,,,,,,,8,,,,,,,,,,,M,,,,8888,,,,M,,,,MMMMMMMM\n"+
      ",88,M,,,,,,,,,,8,,,,,,,,,,,M,,,8888,,,,,,M,,MMMMMMMM\n"+
      ",888,M,,,,,,,,,,,,,,,,,,,,,,M,8888,,,,,,,,,M,MMMMMMM\n"+
      "88,,M,,,,,,,,,,,,,,,,,,,,,,,MM,88,,,,,,,,,,,,MMMMMMM\n"+
      "88,,M,,,,,,,,,,o88o,,,,,,,,,,M,88,,,,,,,,,,,,,,MMMMM\n"+
      ",88,,M,,,,,,,,,88@@88,,,,,,,,,M,,88,,,,,,,,,,,,,,MMM\n"+
      ",88,,MM,,,,,,,,88@@88,,,,,,,,,M,,,8,,,,,,,,,,,,,,o8M\n"+
      ",,8,,MM,,,,,,,,,o88o,,,,,,,,,,M,,,,,,,,,,,,,,,,,88@@\n"+
      ",,,,,,MM,,,,,,,,,,,,,,,,,,,,,MM,,,,,,,,,,,,,,,,,88@@\n"+
      "M,,,,,,,MMM,,,,,,,,,,,,,,,,MM,,,MM,,,,,,,,,,,,,,,MMM\n"+
      "MM,,,,,,,,MMMM,,,,,,,,,,,MMMM,,,,,MM,,,,,,,,,,,,MMMM\n"+
      "MMM,,,,,,,,,MMMMMMMMMMMMMMM,,,,,,,,MMM,,,,,,,,MMMMMM\n"+
      "MMMMM,,,,,,,,,,,,MMMMMMM,,,,,,,,,,,,,,MMMMMMMMMMMMMM\n"+
      "MMM8MM,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,MMMMMMMMMMMM\n"+
      "          Boob Quilt hand made by Diabla\n");
   set_value(0);
   set_weight(0);
}
id(str){ return str == "boob quilt" || str == "frederick quilt" || str == "quilt"; }

void long(string arg)
{
   ::long(arg);
   if(this_player()->query_attrib("int") > random(100))
      return (write("You feel like "+HIW+"bury"+NORM+"ing your "+HIW+"face"+NORM+"\n"+
         HIW+"into"+NORM+" the "+HIW+"quilt"+NORM+".\n"));
}

query_auto_load() { return "/players/jaraxle/closed/magus.c:"; }

init(){
   add_action("cmd_bury","bury");
}

cmd_bury(str){
   
   if(!str) return (notify_fail("Bury what?\n"), 0);
   if(str == "face into quilt" || str == "face into boob quilt"){
      
      switch(random(3)){
         case 0: write("You bury your face into the quilt and moan happily.\n");
         say(TP->query_name()+" buries his face into a quilt and moans happily.\n");
         break;
         
         case 1: write("You squeal in delight as you bury your face into the quilt.\n");
         say(TP->query_name()+" squeals in delight as he buries his face into a quilt.\n");
         break;
         
         case 2: write("You make strange gurgle noises as you bury your face in the quilt.\n");
         say(TP->query_name()+" gurgles strangely as he buries his face into a quilt.\n");
         break;
      }
      
      return 1;
   }
   notify_fail("Bury face into quilt.\n"); return 0; }

drop(){ write("You don't want to drop your quilt.\n"); return 1; }
get(){ return 0; }

