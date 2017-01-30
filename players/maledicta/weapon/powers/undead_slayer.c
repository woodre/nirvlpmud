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
HIW+"Your "+name+" trembles in anticipation..."+NORM+"\n"+
BOLD+"      [ "+HIR+"U"+NORM+BOLD+" ] N D E A D   [ "+HIR+"S"+NORM+BOLD+" ] L A Y E R"+NORM+"\n\n"+
HIW+ATTN+" sizzles as your "+name+" "+HIR+"-C U T S-"+NORM+HIW+" Deep!"+NORM+"\n");
return 0;
}

undead_check(ob){
if(call_other(ob,"id", "undead") || call_other(ob, "id", "skeleton") ||
   call_other(ob, "id", "spirit") || call_other(ob, "id", "wraith") ||
   call_other(ob, "id", "dracula") || call_other(ob, "id", "vampire") ||
   call_other(ob, "id", "zombie") || call_other(ob, "id", "banshee") ||
   call_other(ob, "id", "ghost") || call_other(ob, "id", "revenant") ||
   call_other(ob, "id", "mummy") || call_other(ob, "id", "dracolich") ||
   call_other(ob, "id", "lich") || call_other(ob, "id", "ghoul") ||
   call_other(ob, "id", "frankenstein") || call_other(ob, "id", "corpse"))
   return 1;
else return 0;
}    
