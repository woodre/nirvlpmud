#include "/players/maledicta/ansi.h"
#include "/players/maledicta/weapon/define.h"


main(object user, object wep, string name, string short){
if(random(100) > 50) return 0; 
if(!present(ATT, environment(USER))) return 0;
if(ATT->is_player()) return 0;
if(ATT->query_hp() < 20) return 0;
if(!undead_check(ATT)) return 0;
ATT->heal_self(-(random(6) + 2));
tell_object(user,
HIW+"Your "+name+" trembles in anticipation..."+NORM+"\n\n"+
BOLD+"      [ "+HIR+"G"+NORM+BOLD+" ] I A N T   [ "+HIR+"S"+NORM+BOLD+" ] L A Y E R"+NORM+"\n\n"+
HIW+ATTN+" sizzles as your "+name+" "+HIR+"-C U T S-"+NORM+HIW+" Deep!"+NORM+"\n");
return 0;
}

undead_check(ob){
if(call_other(ob,"id", "giant") || call_other(ob, "id", "ogre") ||
   call_other(ob, "id", "ettin") || call_other(ob, "id", "titan"))
   return 1;
else return 0;
}    
