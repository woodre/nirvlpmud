#include "/players/jaraxle/ansi.h"
#include "/players/jaraxle/closed/weapon/define.h"


main(object user, object wep, string name, string short){
if(random(100) > 2) return 0; 
if(!present(ATT, environment(USER))) return 0;
if(ATT->is_player()) return 0;
if(ATT->query_ac() < 6) return 0;
    tell_object(user,
    HIW+"Your "+name+" slices into "+ATTN+"...\n"+
    ATTN+" falls back, confused and stumbling about...\n"+NORM);
    ATT->set_ac(ATT->query_ac() - 1);
return 0;
}

