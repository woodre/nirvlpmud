#include <ansi.h>
int loaded;

id(str) { return str == "aura" || str == "gen_wc_bonus"; }

void extra_look()
{
	if(environment() == this_player())
	{
		write("The aura of "+HIR+"CHAMPIONS"+NORM+" surrounds you!\n");
	}
	else
	{
		write((string)environment()->query_name()+" has the aura of "+HIR+"CHAMPIONS"+NORM+" pulsating around "+possessive(environment())+NORM+" body\n");
	}
}

int get() { return 1; }
int drop() { return 1; }

string query_auto_load()
{
	return "/players/shinshi/closed/objects/symbioaura:0";
}

gen_wc_bonus(){
	if(environment()->query_real_name() == "symbio" && environment()->query_attrib("dex") > random(70)){
		tell_object(environment(), "Your aura flashes brightly!\n");
		tell_room(environment(environment()), "\t"+BOLD+this_player()->query_name()+"'s aura flashes brightly and sends energy everywhere!\n"+NORM);
		return 5 + random(5);
		}
}

void init(){
	if(environment() && (string)environment()->query_real_name() != "symbio")
		return destruct(this_object());
	else if(environment() && !loaded)
	{
		call_out("heal_self", 3);
		loaded = 1;
	}
}

void heal_self()
{
	int heal;
	
	if(!environment()) return destruct(this_object());
	
	heal = random(100);
	
	if(heal > environment()->query_attrib("str")){
		environment()->heal_self(5 + random(5));
	}
	call_out("heal_self", 3);
}