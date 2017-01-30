#include "/players/jareel/ansi.h"
#include "/players/jareel/GUILD/weapon/define.h"


main(object user, object wep, string name, string short){
int cost;
if(random(100) > 15) return 0; 
if(!present(ATT, environment(USER))) return 0;
tell_object(USER, "Your "+short+" shimmers as it hits "+ATTN+"!\n\n"+
                  HIW+"     ~ ~ ~ "+HIR+"R E V E "+NORM+RED+"R S E"+NORM+BOLD+" ~~~"+NORM+"\n\n"+
                  ATTN+" shudders as energy passes to you!\n");
tell_object(ATT, HIW+"You shudder as energy passes from you to "+USERN+"!\n"+NORM);
cost = random(10) + 5;
ATT->add_spell_point(-cost);
USER->add_spell_point(cost);
   return 0;
}

