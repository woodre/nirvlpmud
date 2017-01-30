#include "/players/maledicta/ansi.h"
#include "/players/maledicta/weapon/define.h"


main(object user, object wep, string name, string short){ 

if(random(100) > 10) return 0;

tell_object(user, 
"\t"+HIW+"Holding the "+name+" before you, you summon forth a\n\n"+
HIB+"                        CYCLONE OF FROST\n\n"+
HIW+"\t\t which engulf's "+ATTN+" with tendrils of pure pain!\n"+NORM);

tell_room(environment(user),
"\t"+HIW+USERN+" holds the "+name+" before"+
" "+USEROB+" summoning forth a\n\n"+
HIB+"                                        CYCLONE OF FROST\n\n"+
"\t\t"+HIW+"which engulf's "+ATTN+" with tendrils of pure pain!\n"+NORM, ({USER}));
return 7;
}

