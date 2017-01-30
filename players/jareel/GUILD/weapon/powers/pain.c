#include "/players/jareel/ansi.h"
#include "/players/jareel/GUILD/weapon/define.h"


main(object user, object wep, string name, string short){
if(random(100) > 5) return 0; 
if(!present(ATT, environment(USER))) return 0;
if(ATT->is_player()) return 0;
if(ATT->query_wc() < 10 || ATT->query_ac() < 6) return 0;
    tell_object(user,
    "Your "+name+" shimmers with power...\n\n"+
    BOLD+"       !!! "+HIM+"CURSE OF PAIN"+NORM+BOLD+" !!! "+NORM+"\n\n"+  
    ATTN+" falls back, screaming and stumbling about in pain!\n");
    
    ATT->set_wc(ATT->query_wc() - 1);
    ATT->set_ac(ATT->query_ac() - 1);
return 0;
}

