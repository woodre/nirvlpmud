/*  10/08/06 - Rumplemintz
      Moved inherit above #include
      Removed count_hits function
*/

inherit "/obj/weapon";
#include <ansi.h>

int time_delay;
int two_handed_wield;
int two_handed_wep;
int no_break;
int *special_damage;
int *special_chance;
string *special_message;
string *special_rmessage;
object *special_fun;
int yup;

#define USER environment()
#define UPR USER->query_pronoun()
#define UPO USER->query_possessive()
#define UOB USER->query_objective()
#define UN  USER->query_name()
#define URN USER->query_real_name()
#define ATT USER->query_attack()
#define AN ATT->query_name()
#define APR ATT->query_pronoun()
#define APO ATT->query_possessive()
#define AOB ATT->query_objective()

add_special_fun(object ob){
    yup = 1;
    if(!special_fun) special_fun = ({ ob });
    else special_fun += ({ ob });
}

set_time_delay(int i){ time_delay = i; }
query_time_delay(){ return time_delay; }

weapon_breaks()
{
    if(no_break) return;
    else return ::weapon_breaks();
}

long(str)
{
    ::long(str);
    if(no_break)
    {
	write("This weapon is unbreakable.\n");
    }
}

set_hits(x)
{
    if(no_break) return;
    else return ::set_hits(x);
}

set_misses(x)
{
    if(no_break) return;
    else return ::set_misses(x);
}

add_wear(x)
{
    if(no_break) return;
    else return ::add_wear(x);
}

hit(attacker)
{
    int retVal, bonus, x, y;

    retVal = ::hit(attacker);
    bonus = retVal;

    if(special_chance && special_message && special_damage)
    {
	for(x = 0; x < sizeof(special_chance); x++)
	{
	    if(random(100) < special_chance[x] && !bonus)
	    {
		if(special_rmessage[x] && ATT)
		    tell_room(environment(USER),
		      filter_msg(special_rmessage[x])+"", ({ USER }));
		if(special_message[x] && ATT)
		    tell_object(USER, filter_msg(special_message[x])+"");
		if(special_damage[x])
		    bonus += special_damage[x];
	    }
	}
    }
    if(special_fun)
    {
	for(y = 0; y < sizeof(special_fun); y++)
	{
	    if(ATT)
	    {
		if(exists(special_fun[y]) && ATT->query_hp() > 0)
		{
		    bonus += special_fun[y]->main(USER, this_object(), name_of_weapon, short_desc);
		}
	    }
	}
    }
    return bonus;
}

add_special_chance(int i){
    yup = 1;
    if(!special_chance) special_chance = ({ i });
    else special_chance += ({ i });
}

add_special_message(str){
    yup = 1;
    if(!special_message) special_message = ({ str });
    else special_message += ({ str });
}
add_special_rmessage(str){
    yup = 1;
    if(!special_rmessage) special_rmessage = ({ str });
    else special_rmessage += ({ str });
}

add_special_damage(int i){
    yup = 1;
    if(!special_damage) special_damage = ({ i });
    else special_damage += ({ i });
}


set_two_handed_wield(int i){ two_handed_wield = i; }
query_two_handed_wield(){ return two_handed_wield; }
set_two_handed_wep(int i){ yup = 1; two_handed_wep = i; }
query_two_handed_wep(){ return two_handed_wep; }
set_no_break(int i){ no_break = i; }
query_no_break(){ return no_break; }

replace_string(str)
{
    string x;
    if(str == "H") x = BOLD;
    else if(str == "K") x = BLK;
    else if(str == "R") x = RED;
    else if(str == "Y") x = YEL;
    else if(str == "B") x = BLU;
    else if(str == "G") x = GRN;
    else if(str == "C") x = CYN;
    else if(str == "W") x = WHT;
    else if(str == "M") x = MAG;
    else if(str == "N") x = NORM;
    else if(str == "U") x = ""+USER+"";
    else if(str == "UN") x = ""+UN+"";
    else if(str == "URN") x = ""+URN+"";
    else if(str == "UPO") x = ""+UPO+"";
    else if(str == "UPR") x = ""+UPR+"";
    else if(str == "UOB") x = ""+UOB+"";
    else if(str == "AN") x = ""+AN+"";
    else if(str == "APO") x = ""+APO+"";
    else if(str == "APR") x = ""+APR+"";
    else if(str == "AOB") x = ""+AOB+"";
    return x;
}

filter_msg(str)
{
    int x; string *words; string tmp;
    words = explode(str,"$");
    for(x=0;x<sizeof(words);x++)
	if(replace_string(words[x])) words[x] = replace_string(words[x]);
    str = (implode(words,""))+NORM;
    return str;
}

/*
count_hits(x) {
    if(no_break) return;
    else return ::count_hits(x);
}
*/

count_misses(x) {
    if(no_break) return;
    else return ::count_misses(x);
}
