#include "/players/jareel/ansi.h"
#include "/players/jareel/GUILD/weapon/define.h"


main(object user, object wep, string name, string short){
if(random(100) > 10) return 0; 
if(!present(ATT, environment(USER))) return 0;
if(ATT->is_player()) return 0;
tell_object(user,
"Your "+name+" "+HIY+"glows"+NORM+" softly...\n"+
"The glow spreads over "+ATTN+".\n");
switch(ATT->query_level()){
 case 20..1000: ATT->add_money(30 + random(10)); break;
 case 14..19:   ATT->add_money(20 + random(10)); break;
 case 7..13:    ATT->add_money(10 + random(10)); break;
 case 1..6:     ATT->add_money(5 + random(10)); break;
 default:       ATT->add_money(5 + random(10)); break;
 }
return 0;
}

