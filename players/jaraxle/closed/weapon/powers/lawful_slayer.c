#include "/players/jaraxle/ansi.h"
#include "/players/jaraxle/closed/weapon/define.h"


main(object user, object wep, string name, string short){
if(random(100) > 15) return 0; 
if(!present(ATT, environment(USER))) return 0;
if(ATT->is_player()) return 0;
if(ATT->query_hp() < 20) return 0;
if(ATT->query_alignment() < 40) return 0;
ATT->heal_self(-(random(6) + 2));
tell_object(user,
HIW+"Your "+name+" trembles in anticipation..."+NORM+"\n"+
BOLD+"      [ "+HIG+"L"+NORM+BOLD+" ] A W F U L   [ "+HIG+"S"+NORM+BOLD+" ] L A Y E R"+NORM+"\n\n"+
HIW+ATTN+" sizzles as your "+name+" "+HIR+"-C U T S-"+NORM+HIW+" Deep!"+NORM+"\n");
return 0;
}

