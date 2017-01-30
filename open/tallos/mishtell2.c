/*Mishtar's Wiztell*/
#include <ansi.h>
#include "/players/mishtar/defs.h"

inherit "obj/treasure";

query_auto_load() { return "players/mishtar/items/mishtell.c:";}

reset(arg){
	if(arg) return;
	set_id("scale");
 	set_alias("teller");
	set_long("\n"+
	"This is a small, "+HIK+"obsidian"+NORM+" dragon scale that seems to be created from \n"+
	"strands of shadow. It is strung on a very fine "+HIY+"golden"+NORM+" chain and has \n"+
	"been placed around your neck as a gift from Mishtar.\n"+
	"You can use this scale to speak with her, if she is present\nusing \""+HIW+"mo"+NORM+"\" "+
	"to send a tell or \""+HIW+"moe"+NORM+"\" to send an emote.\n");
	set_weight(0);
	set_value(0);
	}

extra_look(){
	if(environment() == TP) {
		write("You wear a small "+HIK+"obsidian"+NORM+" scale on a fine "+HIY+"golden "+NORM+"chain.\n");}
	else {
		write(ENVQN+" wears a small "+HIK+"obsidian"+NORM+" scale on a fine "+HIY+"golden "+NORM+"chain.\n");}
	}
drop(){ return 1; }

init(){
	::init();
	add_action("cmd_tell","mo");
	add_action("cmd_emote","moe");
	add_action("cmd_display","display");
	}
cmd_display(string str){
	object targ;
	string who,what;
	if(sscanf(str, "%s to %s", what,who) <2){
		what = str;}
	if(what = "scale"){
	if(who){
		targ = find_player(who);
		if(!targ || environment(targ) != environment(TP)){
			write("You don't see "+CAP(who)+" around you.");
			return 1;
		}
		write("You display your scale to "+(string)targ->query_name()+".\n");
		tell_object(targ,TPN+" displays "+TPP+" scale for you to see.\n"+
			  "This is a small, "+HIK+"obsidian"+NORM+" dragon scale that seems to be created "+
			  "from \nstrands of shadow. It is strung on a very fine "+HIY+"golden"+NORM+" chain.\n");
		say(TPN+" displays "+TPP+" scale for "+(string)targ->query_name()+" to see.\n",targ);
		return 1;
		}
	else{
		write("You display your scale for everyone to see.\n");
		say(TPN+" displays "+TPP+" scale for everyone to see.\n"+
			"This is a small, "+HIK+"obsidian"+NORM+" dragon scale that seems to be created "+
			"from \nstrands of shadow. It is strung on a very fine "+HIY+"golden"+NORM+" chain.\n");
		return 1;
}}}

cmd_tell(string str){
	object mtell;
	mtell=find_player("mishtar");
	if(!mtell){
		notify_fail("Mishtar is off sleeping in her cave right now, try back later.\n");
		return 0;
	}

	if(in_editor(mtell)){
		notify_fail("Mishtar is busy right now, try back later.\n");
	}

	write(""+HIK+" You tell Mishtar"+HIR+": "+HIK+str+NORM+"\n");
	tell_object(mtell,""+HIK+TPN+HIR+" : "+HIK+str+NORM+"\n");
	mtell->add_tellhistory(""+HIK+TPN+HIR+" : "+HIK+str+NORM+"\n");
	return 1;
	}


cmd_emote(str){
	object mtelle;
	mtelle=find_player("mishtar");
	if(!mtelle){
		notify_fail("Mishtar is off sleeping in her cave right now, try back later.\n");
		return 0;
	}

	if(in_editor(mtelle)){
		notify_fail("Mishtar is busy right now, try back later.\n");
	}

	write(""+HIK+" You emote to Mishtar"+NORM+RED+": "+HIK+this_player()->query_name()+" "+str+NORM+"\n");
	tell_object(mtelle,""+HIK+TPN+" "+str+NORM+"\n");
	return 1;
	}
