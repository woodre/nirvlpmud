#include <ansi.h>
int loaded;

id(str) { return str == "aura" || str == "gen_wc_bonus"; }

void extra_look()
{
	if(environment() == this_player())
	{
		write("A bright "+HIR+"aura"+NORM+" pulses around you.\n");
	}
	else
	{
		write((string)environment()->query_name()+" has a bright "+HIR+"aura"+NORM+" pulsing around them.\n");
	}
}

int get() { return 1; }
int drop() { return 1; }

string query_auto_load()
{
	return "/players/shinshi/closed/objects/makoaura:0";
}

gen_wc_bonus(){
	if(environment()->query_real_name() == "mako" && environment()->query_attrib("dex") > random(70)){
		tell_object(environment(), "Your aura flashes brightly!\n");
		tell_room(environment(environment()), "\t"+BOLD+this_player()->query_name()+"'s aura flashes brightly and sends energy everywhere!\n"+NORM);
		return 5 + random(5);
		}
}

void init(){
	if(environment() && (string)environment()->query_real_name() != "mako")
		return destruct(this_object());
	else if(environment() && !loaded)
	{
		call_out("refresh_weps", 300);
		loaded = 1;
	}
	add_action("Talk", "say");
	add_action("Talk", "'");
}

void refresh_weps()
{
	object wep;
	
	if(!environment()) return destruct(this_object());
	
	if(wep = (object)environment()->query_weapon())
	{
		wep->set_hits(1);
		wep->set_misses(1);
	}
	
	if(wep = (object)environment()->query_second_weapon())
	{
		wep->set_hits(1);
		wep->set_misses(1);
	}
	
	call_out("refresh_weps", 300);
}

Talk(str){
	if(!str){
		write("Say what?\n");
		return 1;
	}
	write(BOLD+HIR+"Shardak commands: "+HIK+str+"\n"+NORM);
	say(BOLD+HIR+"Shardak commands: "+HIK+str+"\n"+NORM);
	return 1;
}