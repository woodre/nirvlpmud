#include "/players/jareel/ansi.h"
#include "/players/jareel/GUILD/weapon/define.h"


main(object user, object wep, string name, string short){
if(random(100) > 5) return 0; 
if(!present(ATT, environment(USER))) return 0;
if(ATT->is_player()) return 0;
if(ATT->query_wc() < 10) return 0;
    tell_object(user,
    HIW+"Your "+name+" slices into "+ATTN+"...\n"+
    ATTN+" falls back, weakened...\n"+NORM);
    ATT->set_wc(ATT->query_wc() - 1);
return 0;
}
