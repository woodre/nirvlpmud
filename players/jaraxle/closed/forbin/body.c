inherit "/obj/corpse";
#include "/players/jaraxle/define.h"

int x;
reset(arg){
   ::reset(arg);
   if(arg) return;
   x = 0;
}

search(str){
   if(str == "corpse")
      {
      object tenticle;
      int i;
      
      tenticle = "/players/jaraxle/closed/forbin/tenticle.c";
      if(x >= 1){ write("You find nothing in the corpse.\n"); return 1; }
      for(i = 0; i < 1 + random(6); i++){
      MOCO(tenticle),environment(TO));
      }
      write("You search the corpse, easilly pulling off parts of the\nChampion's body.\n");
      MOCO("/players/jaraxle/closed/forbin/brain.c"),environment(TO));
      MOCO("/players/jaraxle/closed/forbin/heart.c"),environment(TO));
      MOCO("/players/jaraxle/closed/forbin/lhand.c"),environment(TO));
      MOCO("/players/jaraxle/closed/forbin/rfoot.c"),environment(TO));
      MOCO("/players/jaraxle/closed/forbin/lfoot.c"),environment(TO));
         x+=1;
      return 1;
   }
   ::search(str);
}

