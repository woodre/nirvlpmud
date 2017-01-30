inherit "/obj/monster";
#include "/players/maledicta/ansi.h"
string master_name;
int self_damage, show_health;
int guard_delay;
object target;
object vheh;
int walk;
int Busy;
int no_allow_attack;

#define THEPET capitalize(the_short())
#define APET capitalize(a_short())

create()
{
	if (!root()) {
		object mark;
		mark = clone_object("/players/reflex/guilds/bards/bard_mark");
		move_object(mark, this_object());
		set_dead_ob(this_object());
		call_out("pet_follow", 6);
	}
}

reset(arg)
{
	::reset(arg);
	
	if (!arg) create();
}

init()
{
object gob;
	::init();
   if(!environment()) return;
  		add_action("bye", "bye");
		add_action("sic", "sic");
		add_action("munch", "munch");
		add_action("silence","silence");
		add_action("talk", "talk");
		add_action("give", "hand");
       add_action("guard", "guard");
}

monster_died()
{
	object ob;
	object gob;
	tell_room(environment(), die_sound());
	
	if (ob = query_master()) {
		ob->hit_player(self_damage);
		tell_room(environment(ob),
		ob->query_name() + " screams in pain.\n\n");
     if(gob = present("instrument", ob)){
       tell_object(ob, "It will now be 3 hours before you will be\n"+
                       "trusted to summon another "+query_name()+".\n");
        gob->set_pet_delay(5400, name);
        }
	}
	remove_call_out("pet_follow");
	return 0;
}

short(){ 
	if(environment())
	return short_desc+" named "+capitalize(alt_name)+""+
	       ", "+HIW+capitalize(master_name)+"'s Companion"+NORM;
}

heart_beat(){
	object ob;
	::heart_beat();
	
	if(guard_delay) guard_delay -= 1;
	if (ob = query_master()) {
		if(show_health && query_hp() < query_mhp() && query_attack()){
			tell_object(ob,
				HIM+query_name() + " "+HIW+"["+HIM+
				" "+(100 * query_hp() / query_mhp()) +
			"% "+HIW+"]\n"+NORM);
		}
	}
	if(query_hp() < query_mhp()) heal_self(3);
}


pet_follow()
{
	object ob;
	if(Busy) return call_out("pet_follow", 3);
	if (ob = query_master()) {
		if (!present(ob, environment())) {
			say(follow_sound());
			move_object(this_object(), environment(ob));
			if(walk)
			say(APET + " walks into the room.\n");
			else
			say(APET + " flies into the room.\n");
		}
		call_out("pet_follow", 5);
		} 
else {
		bye();
	}
}

is_pet()
{
	return 1;
}

/*
* special properties for the bard pets
*/
set_self_damage(dmg)
{
	self_damage = dmg;
}

set_show_health(show)
{
	show_health = show;
}

set_master_name(str)
{
	master_name = str;
}

query_master_name()
{
	return master_name;
}

query_master()
{
	string name;
	name = query_master_name();
	return name ? find_player(name) : 0;
}

a_short()
{
	return "a bard pet";
}

the_short()
{
	return "the bard pet";
}


/*
* functions to override for different output to the players
*/
follow_sound()
{
	if(walk)
	return (THEPET + " runs from the room after its friend.\n");
	else
	return (THEPET + " flies from the room after its friend.\n");
}

bye_sound()
{
	if(walk)
	return (THEPET + " runs off into the distance.\n");
	else
	return (THEPET + " flies off into the sky.\n");
}

die_sound()
{
	return (THEPET + " falls to the ground with a thud.\n\n");
}

sic_sound(str)
{
	if(walk)
	return (THEPET + " runs towards " + capitalize(str) + ".\n");
	else
	return (THEPET + " flies towards " + capitalize(str) + ".\n");
}

munch_sound()
{
	return (THEPET + " flies down to the corpse and plucks out its eyeballs.\n");
}

hand_sound(what, who_to)
{
	return (THEPET + " drops a " + what + " into " + capitalize(who_to) +
	"'s hand.\n");
}

bye2(){
	say(bye_sound());
	destruct(this_object());
	return 1;
}

bye()
{
	object ob;
	if(this_player())
	if(this_player()->is_player())
	if (this_player() != query_master()) return;
	
	if ((ob = query_master()) && present(ob, environment())) {
		say(THEPET + " looks over at " + ob->query_name() + " and nods.\n");
		/* transfer_all_to doesn't do weight adjustment */
		/*transfer_all_to(ob);*/
	}
	say(bye_sound());
	destruct(this_object());
	return 1;
}

sic(str)
{
	object ob;
	if (this_player() != query_master()) return;

	if(no_allow_attack){
		write("Your "+query_name()+" doesn't have the heart to fight!\n");
		return 1;
	}

	if(!str){ write("sic what?\n"); return 1; }
	
	ob = present(str, environment());
	if (!ob) {
		return 1;
	}
       if(attacker_ob) return;

	if (ob->is_player() || ob->is_pet() || !living(ob)) {
    write("Your "+query_name()+" cannot attack "+str+"!\n");
    return 1;
	}
	say(sic_sound(str));
	attack_object(ob);
	return 1;
}

munch()
{
	object corpse;
	int heal;
	if (this_player() != query_master()) return;
	if(no_allow_attack){
		write("Your "+query_name()+" is a vegetarian!\n");
		return 1;
	}
	corpse = present("corpse", environment());
	if (!corpse) {
		notify_fail("There is no corpse here.\n");
		return 0;
	}
	if (!(heal = corpse->heal_value())) {
		write("The corpse is devoid of energy.\n");
		return 1;
	}
	say(munch_sound());
	destruct(corpse);
	heal_self(heal);
	return 1;
}

talk()
{
	if (this_player() != query_master()) return;

	set_chat_chance(5);
	write("You look over at your " + query_real_name() + " and smile.\n");
	return 1;
}

silence()
{
	if (this_player() != query_master()) return;

	set_chat_chance(0);
	write("You look over at your " + query_real_name() + " and shake your head.\n");
	return 1;
}

/***** BORROWED CODE - THANKS TO ALL WHO HAVE PROVIDED IT. ***/
give(str) {
	object item;
	string what,who;
	if (this_player() != query_master()) return;
    if(walk) return;
	if(!str) return 0;
	if(sscanf(str,"%s to %s",what,who) != 2){
		notify_fail("Have your " + query_name() + " take what to whom?\n");
		return 0;
	}
	item = present(what,this_player());
	target = find_player(who);
	if(!item) { write("You do not have that!\n"); return 0; }
	if(!target) { write("That person is not in game.\n"); return 0; }
	if(target->query_invis()) { write("That person is not in game.\n"); return 0; }
	if(environment(target)->realm() == "NT" ||
		environment(this_player())->realm() == "NT") {
		write("Something is preventing your " + query_name() + " from doing that.\n");
	return 1; }
	if(item->drop() || item->query_auto_load() || !item->get() ||
		item->namer() == "cold" ||
		!item->query_weight()) {
		write("You may not send this item.\n");
	return 1; }
	if(item->armor_class() && item->query_worn()) { command("remove "+what,this_player()); }
	if(item->weapon_class() && item == this_player()->query_weapon()) { command("unwield "+what,this_player()); }
	tell_room(environment(this_player()),
		capitalize(query_master_name()) +" hands "+query_name()+" an item.\n"+
	capitalize(query_master_name()) +"'s "+query_name()+" flies off into the air.\n\n\n");
	
	move_object(this_object(), "/players/vertebraker/closed/mythos_pet_room");
	vheh = clone_object("/players/vertebraker/closed/mythos_pet_ask");
	move_object(vheh, target);
   Busy = 1;
	vheh->ask_me_foo(this_object(), item, target);
	transfer(item, "/players/vertebraker/closed/mythos_pet_room");
	return 1;
}

okay_do_da_ting(stuff, target) {
object ob;

if (ob = query_master()) {
    if(environment(ob)) tell_room(environment(ob),
    ob->query_name()+"'s "+query_name()+" flies into the room.\n");
  tell_room(environment(target), short() + " flies into the room.\n");
  tell_room(environment(target),
    short()+" gives something to "+target->query_name()+".\n"+
    short()+" flies off into the sky.\n");
  if(ob && stuff && stuff->short())
  tell_object(target,"You recieve a "+stuff->short()+" from "+ob->query_name()+"\n");
  if(stuff)
  move_object(stuff, target);
   Busy = 0;
   return 1;
   }
bye();
return 1;
}

guard()
{
	object ob;
	string temp;
	int temp2;
	if (this_player() != query_master()) return;
	
	ob = query_attack();
	if(guard_delay){
    write("You cannot do that again so soon!\n");
    return 1;
    }
	if (!ob || !(ob->is_player() || ob->is_pet())) {
		write("Your " + query_real_name() + " is not under attack by a player or pet or kid.\n");
		return 1;
	}
	
	temp = ob->query_name();
	
	tell_room(environment(),
		"\n\nThere is a bedazzling flash of illumination as the slim figure of a woman\n"
		+ "materializes in the air above you.\n\n" +
	"The woman speaks\n\n");
	tell_room(environment(),
		"       \"\I am Crysea, goddess who watches over animals.\"\n\n"
		+
		"       \"\This " + query_real_name() + " is under my protection.\"\n\n" +
		"Crysea points at " + capitalize(temp) +
	" as her eyes flash.\n\n");
	
	if (ob->is_player()) {
		temp2 = (ob->query_hp() / 4);
		ob->heal_self(-temp2);
		tell_room(environment(this_object()),
			capitalize(temp) +
		" is struck by a blazing bolt of lightning.\n");
	}
	
	if (ob->is_pet()) {
		temp2 = (ob->query_hp() / 2);
		ob->add_hit_point(-temp2);
		tell_room(environment(this_object()),
			capitalize(temp) +
		" is struck by an inferno of fire which rages down from the sky.\n");
	}
	guard_delay = 5;
	tell_room(environment(), "\nThe goddess is gone.\n");
	return 1;
}

bard_pet(){ return 1; }

query_owner(){ 
object ob;
if(ob = query_master()) return ob;
}

NotBusy() { Busy = 0; }

