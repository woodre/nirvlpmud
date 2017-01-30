#include "/players/maledicta/ansi.h"
#define ATT ppl[i]->query_attack()
#define ATTN ATT->query_name()
#define vis this_player()->query_invis()
get(){ return 1; }
drop(){ return 1; }

query_weight(){ return 0; }
query_value(){ return 0; }

short(){ return "Wiztell"; }
long(){
	write(
	"To use, type 'tell <who> <what>'\n");
	return 1;
}

id(str){ return str == "wiztell"; }

init(){
	if(!environment()) return;
	if(!living(environment())) return;
	if(environment()->query_level() < 21){ destruct(this_object()); return 1; }
	add_action("tell_cmd", "tell");
	add_action("say_cmd", "say");
	add_action("say_cmd"); add_xverb("'");
	add_action("say_cmd", "'");
	add_action("whonew", "who3");
}

whonew(){
	object* ppl;
	int i;
	ppl = users();
	write(
	"Name:         HP:         Money:      Experience:    Level:    Fighting:\n");
	
	for(i = 0; i < sizeof(ppl); i++){
		if(ppl[i]->query_level() > 500000 && ppl[i]->query_invis()) continue;
		tell_object(this_player(),
		pad(ppl[i]->query_real_name()+"           ", 14));
		tell_object(this_player(),
		pad(ppl[i]->query_hp()+"/"+ppl[i]->query_mhp()+"    ", 12));
		tell_object(this_player(),
		pad(ppl[i]->query_money()+"           ", 12));
		tell_object(this_player(), pad(ppl[i]->query_exp()+"         ", 15));
		if(ppl[i]->query_extra_level()){
			tell_object(this_player(),
			pad(ppl[i]->query_level()+"+"+ppl[i]->query_extra_level()+"      ", 10));
		}
		else{
			tell_object(this_player(),
			pad(ppl[i]->query_level()+"        ", 10));
		}
		if(ATT){
			tell_object(this_player(),
			ATTN+" ["+ATT->query_hp()+"/"+ATT->query_mhp()+"]\n");
		}
		else{
			tell_object(this_player(),
			"Not fighting.\n");
		}
		
	}
	return 1;
}

say_cmd(str){
	string name;
	
	if(!str) return 0;
	if(vis) name = (string)this_player()->query_real_name();
	else name = "someone";
	tell_room(environment(this_player()), capitalize(name)+" says: "+str+"\n");
return 1; }

status tell_cmd(string str) {
	string swhat, swho;
	string me;
	object who;
	if(!str){ write("Usage:  'tell <who> <what>'\n");  return 1; }
	if(!sscanf(str, "%s %s", swho, swhat)) {
	write("Usage:  'tell <who> <what>'\n");   return 1; }
	who = find_player(swho);
	me = (string)this_player()->query_real_name();
	if(!who){    write("That person isn't currently logged on.\n");  return 1; }
	who->add_tellhistory(capitalize(me)+" told you: " + swhat);
	tell_object(who,
	HIW+capitalize(me)+" tells you: "+NORM+HIB+swhat+NORM+"\n");
	write("You tell "+capitalize(swho)+": "+swhat+"\n");
	return 1;
}

