/*All Legends are Manually placed in Tablet, not sure how I would code it to auto make it, and the area itself
requires upkeep so not sure its nessasary to make it auto work.  A player who reaches Legend status, will need 
to prove they are legends, MK SCAR, or Tablet in guild, Or a guild object that records kills.*/
#include "/players/jareel/define.h"
inherit "obj/treasure.c";

     reset(arg){
     
     if(arg) return;
     no_clean = 1;
     set_short(BOLD+"The Tablet of Legends"+NORM);
     set_alias("tablet");
     set_long("\n"+BOLD+
       "                  |===========================================|\n"+
       "                    "+NORM+RED+"<<<"+NORM+BOLD+"+100 Legends"+NORM+RED+">>>     <<<"+NORM+BOLD+"PK Legends"+NORM+RED+">>>"+NORM+BOLD+"\n"+
       "\n"+   
       "                      Stone("+BLU+"Knight"+NORM+BOLD+")       \n"+
       "                      Konya("+RED+"Cyber"+NORM+BOLD+")\n"+
       "                      Justin("+BLU+"Knight"+NORM+BOLD+")\n"+
       "                      Bone("+RED+"V"+BLK+"ampire"+NORM+BOLD+")\n"+
       "                      Cooper("+NORM+GRN+"Ranger"+NORM+BOLD+")\n"+
       "                      Magus("+RED+"V"+BLK+"ampire"+NORM+BOLD+")\n"+
       "                      Breeti("+YEL+"Polymorph"+NORM+BOLD+")\n"+
       "                      Hardly("+HIK+"Black Circle"+NORM+BOLD+")\n"+
       "                      Tweak("+YEL+"Polymorph"+NORM+BOLD+")\n"+
       "                      Sparkle("+NORM+RED+"A"+HIK+"nti"+HIR+"-"+NORM+RED+"P"+HIK+"aladin"+NORM+BOLD+")\n"+
       "                      Preston("+BOLD+RED+"Dervish"+NORM+BOLD+")\n"+
       "                      Humble("+BOLD+RED+"Dervish"+NORM+BOLD+")\n"+
       "                      Hoyle("+NORM+GRN+"Ranger"+NORM+BOLD+")\n"+
       "                      Bleh("+HIK+"Black Circle"+NORM+BOLD+")\n"+
       "                      Entreri("+BOLD+RED+"Dervish"+NORM+BOLD+")\n"+
       "                      Shadowraith("+HIK+"Dark Order"+NORM+BOLD+")\n"+
       "                      Pike("+RED+"Cyber"+NORM+BOLD+")\n"+
       "\n\n"+NORM);
     set_read("\n"+BOLD+
       "                  |===========================================|\n"+
       "                    "+NORM+RED+"<<<"+NORM+BOLD+"+100 Legends"+NORM+RED+">>>     <<<"+NORM+BOLD+"PK Legends"+NORM+RED+">>>"+NORM+BOLD+"\n"+
       "\n"+
       "                      Stone("+BLU+"Knight"+NORM+BOLD+")\n"+
       "                      Konya("+RED+"Cyber"+NORM+BOLD+")\n"+
       "                      Justin("+BLU+"Knight"+NORM+BOLD+")\n"+
       "                      Bone("+RED+"V"+BLK+"ampire"+NORM+BOLD+")\n"+
       "                      Cooper("+NORM+GRN+"Ranger"+NORM+BOLD+")\n"+
       "                      Magus("+RED+"V"+BLK+"ampire"+NORM+BOLD+")\n"+
       "                      Breeti("+YEL+"Polymorph"+NORM+BOLD+")\n"+
       "                      Hardly("+HIK+"Black Circle"+NORM+BOLD+")\n"+
       "                      Tweak("+YEL+"Polymorph"+NORM+BOLD+")\n"+
       "                      Sparkle("+NORM+RED+"A"+HIK+"nti"+HIR+"-"+NORM+RED+"P"+HIK+"aladin"+NORM+BOLD+")\n"+
       "                      Preston("+BOLD+RED+"Dervish"+NORM+BOLD+")\n"+
       "                      Humble("+BOLD+RED+"Dervish"+NORM+BOLD+")\n"+
       "                      Hoyle("+NORM+GRN+"Ranger"+NORM+BOLD+")\n"+
       "                      Bleh("+HIK+"Black Circle"+NORM+BOLD+")\n"+
       "                      Entreri("+BOLD+RED+"Dervish"+NORM+BOLD+")\n"+
       "                      Shadowraith("+HIK+"Dark Order"+NORM+BOLD+")\n"+
       "                      Pike("+RED+"Cyber"+NORM+BOLD+")\n"+
       "\n\n"+NORM);
     }

get() { return 0;
}
