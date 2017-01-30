#include "/players/jareel/ansi.h"
#include "/players/jareel/GUILD/weapon/define.h"


main(object user, object wep, string name, string short){
if(random(100) > 10) return 0; 
if(!present(ATT, environment(USER))) return 0;
if(ATT->query_sp() < 14) return 0;
 tell_object(user,
 BOLD+"The room darkens..."+NORM+"\n\n"+ 
 HIR+"           - "+HIW+":"+NORM+RED+"W I T C H"+HIW+" :: "+NORM+RED+"H U N T E R"+HIW+":"+HIR+" -"+NORM+"\n\n"+
 BOLD+"   "+ATTN+" is cut down by null magic!"+NORM+"\n");
 ATT->add_spell_point(-(random(10) + 4));
return 0;
}

