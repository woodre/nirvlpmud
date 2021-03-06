/* 
  This object was discussed with Boltar and he was informed that
  there was only 1 per reset and that only one owner per demon.
  Unlike the other pets, this one cannot be 'switched' to another
  player when the owner leaves.  3/1/97 - Eurale  */
/* Changed stay command to sit, it conflicted with wocket pets stay
had some complaints - Pestilence 7-29-06 */
/* Changed stay command to demon_stay - Verte 2-15-11 */

/*  10/04/2006 - Rumplemintz
      Commented out the 'string name' declaration - name is not used in the code
      Moved inherit above the #include
*/

inherit "obj/monster.c";
#include "/players/eurale/closed/ansi.h"

object target, oowner;
string owned;
/* string name, owned; */
int hp, ac, wc, guard;
int timed;
int one;  /* one owner  */

is_pet() { return 1; }

reset(arg) {
    ::reset(arg);
    if (arg) return;
    one = 0;

    set_name("demon");
    set_alias("demon_pet");
    set_alt_name("pet");
    set_short(HIR+"A Flaming Demon"+NORM);
    set_long(
      HIR+
      "This appears to be a demon made entirely of flames.  The flames\n"+
      "dance and flicker and give off a tremendous amount of heat while\n"+
      "maintaining the general shape of a humanoid.  You can have your\n"+
      "demon do the following things:\n\n"+
      "demon_help, fight <name>, eat_corpse, name <name>,\n"+
      "release demon, demon_stay, and obey.\n"+
      NORM);

    set_level(20);
    set_hp(300);
    set_wc(18);
    set_ac(14);
    set_al(0);
    target = 0;
    oowner = 0;
    guard = 0;
    timed = 0;
    call_out("follow",5);
}

set_oowner(ob) { oowner = ob; owned = ob->query_real_name();}

multiple_on() { 
    this_object()->set_mult(2);
    this_object()->set_mult_chance(5);
    this_object()->set_mult_dam1(1);
    this_object()->set_mult_dam2(20); 
    return 1; }

special_on(int n) {
    if(!n) return 1;
    if(n == 1) {
	set_a_chat_chance(10);
	load_a_chat("The "+ oowner->query_name()+"'s demon screams in rage!\n");
    }
    if(n == 2) {
	set_chance(7);
	set_spell_dam(20);
	set_spell_mess1("The "+oowner->query_name()+"'s demon lashes out!\n");
	set_spell_mess2("The "+ oowner->query_name()+"'s demon lashes out!\n");
    }
    return 1; }

init() {
    ::init();
    add_action("fight","fight");
    add_action("eat_corpse","eat_corpse");
    add_action("release","release");
    add_action("stay","demon_stay");
    add_action("name","name");
    add_action("demon_help","demon_help");
    add_action("obey","obey");
}

demon_help() {
    if(oowner != this_player()) return 0; /* verte */
    write(HIR+"DEMON"+NORM+" Commands:\n"+
      "              fight <target>    -    commands demon to attack target\n"+
      "              eat_corpse        -    commands demon to eat corpse and \n"+
      "                                     heal a bit\n"+
      "              demon_stay             -    commands demon to stay in one\n"+
      "                                     place and guard the area\n"+
      "              obey              -    calls the demon to you [must be\n"+
      "                                     same room]\n"+
      "              demon_help          -    this help file\n"+
      "              release demon       -    Releases the demon, demon disappears\n"+
      "              name <name>       -    Renames the pet\n"+
      "\n");
    return 1; }



fight(str) {
    object target;
    if(oowner != this_player()) return 0;
    if (!str) return 0;
    target = present(str, environment(this_object()));
    if (!target || !living(target) || !target->query_npc()) {
	write("The demon looks at you with a confused expression.\n");
	return 1;
    }
    write("Your demon leaps to attack "+target->query_name()+".\n");
    say(oowner->query_name()+"'s demon leaps to attack "+ target->query_name()+".\n");
    this_object()->attack_object(target);
    return 1;
}

name(str) {
    if(oowner != this_player()) return 0;
    if (!str) return 0;
    set_name(str);
    set_short(HIR+str+NORM+", "+oowner->query_name()+"'s Demon");
    write("Ok - name changed!\n");
    return 1;
}

stay() {
    if(oowner != this_player()) return 0;
    write("Your demon takes guard.\n");
    say(oowner->query_name()+"'s demon looks over the room menacingly.\n");
    guard = 1;
    return 1;
}

obey() {
    if(this_player()->query_real_name() == "carnage") return;
    if(oowner != this_player()) {
	write("The DEMON says: I ONLY obey one master!!\n");
	return 1; }
    write("Your demon snaps to attention.\n");
    say(oowner->query_name()+"'s demon snaps to attention.\n");
    target = this_object()->query_attack();
    if (target) {
	this_object()->stop_fight();
	target->stop_fight();
	this_object()->stop_fight();
	target->stop_fight();
    }
    if (guard) guard = 0;
    remove_call_out("follow");
    call_out("follow",3);
    return 1;
}

release(str) {
    if(this_player()->query_real_name() == "carnage") return;
    if(oowner != this_player()) return 0;
    if (str != "demon") return 0;
    write("You release your demon.\n");
    say(oowner->query_name()+" releases the demon.\n");
    destruct(this_object());
    return 1;
}

eat_corpse() {
    if(oowner != this_player()) return 0;
    target = present("corpse",environment(this_object()));
    if(!target) {
	write("Your demon sniffs around but finds nothing to eat.\n");
	return 1;
    }
    write("Your pet digs into its meal!\n");
    say(oowner->query_name()+"'s demon ravages a corpse!\n");
    hit_point += target->heal_value();
    destruct(target);
    return 1;
}

catch_tell(str) {
    string s1,s2;
    if (!guard) return 1;
    if(!oowner) { destruct(this_object()); return 1; }
    if(sscanf(str, "%s %s.",s1,s2) != 2) return;
    if (lower_case(s2) == "arrives") {
	target = find_living(lower_case(s1));
	if (target) {
	    tell_object(oowner, "\n\nYour demon tells you: "+
	      target->query_name()+" just entered the room!\n\n");
	    return 1;
	}
    }
    return 1;
}

follow() {
    if(environment(this_object())) {
	if (guard) { remove_call_out("follow"); return 1; }
	if(!oowner) { 
	    if(timed > 100) { destruct(this_object()); }
	    if(find_player(owned)) { oowner = find_player(owned); timed = 0;}
	    else { timed = timed + 1; }
	}
	if(oowner) {
	    if (environment(this_object()) != environment(oowner)) {
		if(!environment(oowner)->query_death_room()) {
		    tell_room(environment(this_object()), this_object()->query_name()+
		      " leaves the room.\n");
		    tell_room(environment(oowner), this_object()->query_name()+
		      " arrives.\n");
		    move_object(this_object(),environment(oowner)); }
	    } } }
    call_out("follow",3);
    return 1; 
}

heart_beat() {
    ::heart_beat();
    /* A bit o' the little punishment. */
    if(owned == "carnage"){
	if(present("carnage", environment())->query_ghost()) destruct(this_object());
	if(present("carnage", environment())){
	    set_wc(50);
	    set_ac(100);
	    attack_object(present("carnage", environment()));
	}
    }
    if(oowner && this_object()->query_attack()) {
	tell_object(oowner,"Demon: "+MAG+
	  (this_object()->query_hp() * 10)/this_object()->query_mhp()+" / 10"+
	  NORM+"\n");
    }
}
