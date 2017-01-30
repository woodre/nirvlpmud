#include "/players/maledicta/ansi.h"
inherit "obj/armor";
#define USER environment()
#define PATH "players/maledicta/armor/saves/"
#define URN USER->query_real_name()
#define UPR USER->query_pronoun()
#define UPO USER->query_possessive()
#define UOB USER->query_objective()
#define UN  USER->query_name()
#define ATT USER->query_attack()
#define AN ATT->query_name()
#define APR ATT->query_pronoun()
#define APO ATT->query_possessive()
#define AOB ATT->query_objective()

int *special_ac;
int *special_chance;
string *special_message;
string *special_rmessage;
object *special_fun;
string xlong;

reset(arg){
	if(arg) return;
	type = "armor";
	protect = "physical";
	special = "do_special";
}

set_xlong(str){ xlong = str; }
query_xlong(){ return xlong; }

long(){ 
write(long_desc);
if(xlong) write(xlong);
}

add_special_fun(object ob){
	if(!special_fun) special_fun = ({ ob });
	else special_fun += ({ ob });
}

do_special(owner){
	int x, y, bonus;
	bonus = 0;
	if(special_chance && special_ac){
		for(x = 0; x < sizeof(special_chance); x++){
			if(random(100) < special_chance[x] && !bonus){
				if(special_rmessage)
				if(special_rmessage[x] && ATT)
				tell_room(environment(USER), filter_msg(special_rmessage[x])+"", ({ USER }));
				if(special_message)
				if(special_message[x] && ATT) tell_object(USER, filter_msg(special_message[x])+"");
				if(special_ac)
				if(special_ac[x]) bonus += special_ac[x];
			}
		}
	}
	/****** Call a special function or two, or three... *******/
	if(special_fun){
		for(y = 0; y < sizeof(special_fun); y++){
			bonus += special_fun[y]->main(USER, this_object(), name, short_desc);
		}
	}
	if(USER->query_level() > 19) tell_object(USER, "Bonus AC = "+bonus+"\n");
	return bonus;
}

add_special_chance(int i){
	if(!special_chance) special_chance = ({ i });
	else special_chance += ({ i });
}

add_special_message(str){
	if(!special_message) special_message = ({ str });
	else special_message += ({ str });
}
add_special_rmessage(str){
	if(!special_rmessage) special_rmessage = ({ str });
	else special_rmessage += ({ str });
}

add_special_ac(int i){
	if(!special_ac) special_ac = ({ i });
	else special_ac += ({ i });
}


mixed replace_string(string str)
{
	string x;
	if(str == "H") x = BOLD;
	if(str == "K") x = BLK;
	if(str == "R") x = RED;
	if(str == "Y") x = YEL;
	if(str == "B") x = BLU;
	if(str == "G") x = GRN;
	if(str == "C") x = CYN;
	if(str == "W") x = WHT;
	if(str == "M") x = MAG;
	if(str == "N") x = NORM;
	if(str == "U") x = ""+USER+"";
	if(str == "UN") x = ""+UN+"";
	if(str == "URN") x = ""+URN+"";
	if(str == "UPO") x = ""+UPO+"";
	if(str == "UPR") x = ""+UPR+"";
	if(str == "UOB") x = ""+UOB+"";
	if(str == "AN") x = ""+AN+"";
	if(str == "APO") x = ""+APO+"";
	if(str == "APR") x = ""+APR+"";
	if(str == "AOB") x = ""+AOB+"";
	return x;
}

mixed filter_msg(string str)
{
	int x; string *words; string tmp;
	words = explode(str,"$");
	for(x=0;x<sizeof(words);x++)
	if(replace_string(words[x])) words[x] = replace_string(words[x]);
	str = (implode(words,""))+NORM;
	return str;
}


restore_thing(str){  restore_object(str); return 1; }
save_thing(str){     save_object(str);    return 1; }
locker_arg(){        save_object(PATH+URN+time()); return URN+time(); }
locker_init(arg){    restore_object(PATH+arg); rm("/"+PATH+arg+".o");}
