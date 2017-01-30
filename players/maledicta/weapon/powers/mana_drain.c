#include "/players/maledicta/ansi.h"
#include "/players/maledicta/weapon/define.h"


main(object user, object wep, string name, string short){
if(random(100) > 10) return 0; 
if(!present(ATT, environment(USER))) return 0;
if(ATT->query_sp() < 8) return 0;
 tell_object(user,
 "Your "+name+" pulls at reality...\n\n"+
 HIW+"    [ "+NORM+GRN+"M A N A  "+HIW+"~"+NORM+GRN+"o"+HIW+"~  "+NORM+GRN+"D R A I N "+HIW+"]"+NORM+"\n\n"+
 "  "+ATTN+" looks weakened...\n");
 ATT->add_spell_point(-(random(6) + 2));
return 0;
}

