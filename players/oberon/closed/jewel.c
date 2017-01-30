#include "/obj/ansi.h"
inherit "obj/armor";

#define CAP capitalize
int result;
string ploc;

reset(arg) {
	::reset(arg);
	if(arg) return;
	set_alias("jewel");
	set_short(""+BOLD+"The Jewel of Judgement"+NORM+"");
	set_long("This is the Legendary Jewel of Judgement.\n");
	set_type("amulet");
	set_weight(1);
	set_value(0);
	set_name(""+BOLD+"Jewel of Judgment"+NORM+"");
}

init() {
	::init();
	if(this_player()->query_real_name() != "oberon") {
		write("The Jewel of Judgement flashes and disappears.\n");
		destruct(this_object());
		return 1;
	}
	add_action("amber_update","upd_amber");
add_action("cmd_checkguild","checkguild");
	add_action("cmd_chdir","chdir");
	add_action("ptest","ptest");
	add_action("cmd_idlers","idlers");
	add_action("cmd_drop","drop");
	add_action("change_elemwep","otest");
	add_action("localcmds","otest2");
	add_action("cmd_dispcolors","colors");
}

cmd_dispcolors() {
	write("Colors:\n");
	write(HIW+"HIW"+NORM+"\n");
	write(WHT+"WHT"+NORM+"\n");
	write(HIG+"HIG"+NORM+"\n");
	write(HIY+"HIY"+NORM+"\n");
	write(HIC+"HIC"+NORM+"\n");
	write(HIB+"HIB"+NORM+"\n");
	write(HIR+"HIR"+NORM+"\n");
	write(HIM+"HIM"+NORM+"\n");
	return 1;
}

cmd_checkguild(arg) {
	string *gnames;
	int siz;
	gnames = find_player(arg)->query_prestige_guilds();
	siz = sizeof(gnames);
	while(siz--) {
		write("\t"+gnames[siz]+"\n");
	}
	return 1;
}

change_elemwep(arg) {
	object elemwep;
	elemwep = clone_object("/players/oberon/closed/ele/elem_wep.c");
	elemwep->change_type(arg);
	move_object(elemwep, environment());
	write("Cloned elemental "+arg+"\n");
	return 1;
}

localcmds(arg) {
	string *verbs, pname;
	int i, x;
	if(arg) {
		pname = arg;
		write("Target: "+pname+"\n");
	}
	verbs = query_actions(this_player(), 9);
	for(i=0;i<sizeof(verbs);i++) {
		write((string)verbs[i]+":\t\t");
		i++;
		write((string)verbs[i]+"\n");
	}
	return 1;
}

cmd_test(arg) {
	object masons;
	masons = find_object("players/angel/masons/mgob#3724");
	masons->set_glevel(30);
	write("Complete.\n");
	return 1;
}

cmd_drop(arg) {
	if(arg=="jewel" || arg=="all") {
		write("The Jewel of Judgement flashes bright white and explodes!\n");
		destruct(this_object());
		return 1;
	}
}

cmd_chdir(arg) {
	switch(arg) {
		case "amber": command("cd ~/amber/city", this_player()); break;
		case "amberr": command("cd ~/amber/city/rooms", this_player()); break;
		case "ambero": command("cd ~/amber/city/obj", this_player()); break;
		case "amberm": command("cd ~/amber/city/mob", this_player()); break;
		default: break;
	}
	return 1;
}

amber_update(arg) {
	switch(arg) {
		case "obj":
			command("upd_dir /players/oberon/amber/city/obj/", this_player());
			write("Amber Objects Updated.\n");
			break;
		case "mob":
			command("upd_dir /players/oberon/amber/city/mob/", this_player());
			write("Amber Mobs Updated.\n");
			break;
		case "room":
			ploc = basename(environment(this_player()));
			command("upd_dir /players/oberon/amber/city/rooms/", this_player());
			move_object(this_player(), ploc);
			write("Amber Rooms Updated.\n");
			break;
		default:
			ploc = basename(environment(this_player()));
			command("upd_dir /players/oberon/amber/city/obj/", this_player());
			command("upd_dir /players/oberon/amber/city/mob/", this_player());
			command("upd_dir /players/oberon/amber/city/rooms/", this_player());
			move_object(this_player(), ploc);
			write("Amber Updated.\n");
			break;
	}
	return 1;
}

ptest(str) {
	string who, what;
	int amount;
	int getLevel;
	object target;
	if(!str) return 0;
	if(sscanf(str, "%s %s %d", who, what, amount) != 3) return 0;
	if(!find_player(who)) {
		write("Target is not in play.");
		return 1;
	}
	target = find_player(who);
	if(!target) {
		write("Target not found Gnar.");
		return 1;
	}
	if(what == "report") {
		getLevel = target->query_prestige_level();
		write("Prestige Report for: "+who+".\n");
		write("Level:\t"+getLevel+".\n");
		write("Points:\t"+target->query_prestige_skillpt()+".\n");
	}
	else if(what == "level")
		target->set_prestige_level(amount);
	else if(what == "points")
		target->set_prestige_skillpt(amount);
	else
		target->set_prestige_skill(what,amount);
	
	write("You have set "+who+"'s "+what+" to "+amount+".\n");
	return 1;
}

cmd_idlers(arg) {
	object *us;
	int x, a, time, mins, hours;
	string stime, name, tmp;
	us = users();
	write("    NAME        TIME IDLE\n"+
		"================================\n");
	for(x = 0; x < sizeof(us); x++) {
		if(us[x]->query_invis())
			name = "("+CAP(us[x]->query_real_name())+")";
		else
			name = CAP(us[x]->query_real_name());
		time = query_idle(us[x]); stime = time + " seconds";
		if(time > 60) {
			mins = time / 60; time = time - (mins * 60);
			stime = mins+" minutes "+time+" seconds";
		}
		if(mins > 59) {
			hours = mins / 60; mins = mins - (hours * 60);
			stime = hours+" hours "+mins+" minutes "+time+" seconds";
		}
		if(x < 9) write(" ");
		write((x+1)+". "+name);
		for(a = 12; a > strlen(name); a--) write(" ");
		if (arg) write(stime+" ("+efun::query_ip_number(us[x])+")\n");
		else write(stime+"\n");
	}
	return 1;
}
