#include "/players/jareel/ansi.h"
#include "/players/jareel/GUILD/weapon/define.h"


main(object user, object wep, string name, string short){
int woop;
string mess;
if(random(100) > 10) return 0; 
if(!present(ATT, environment(USER))) return 0;
woop = random(25) + 1;
mess = wep->query_message_hit(woop);

tell_room(environment(user),
HIR+USERN+"'s form "+HBRED+" B L U R S "+NORM+HIR+"!"+NORM+"\n");
  wep->set_gen_bonus(woop);
  tell_object(USER,
	"You "+mess[1]+" "+ATT->query_name()+""+mess[0]+".\n");
  tell_object(ATT,
	USER->query_name()+" "+mess[1]+" you"+mess[0]+".\n");
  tell_room(environment(USER),
	USER->query_name()+" "+mess[1]+" "+ATT->query_name()+mess[0]+".\n",
	({USER, ATT}));
   return 0;
}

