/*
 * A general purpose monster. Clone this object,
 * and call local functions to configure it.
 */
#include "/players/beck/Transformers/Decepticons/Guild/Object/living.h"
#include "clean.c"
#include "chat_include.c"
#include "catch_talk_include.c"


/*
 * The heart beat is always started in living.h when we are attacked.
 */

string short_desc, long_desc, alias, alt_name, race, hbflag,info;
int move_at_reset, aggressive, can_kill;
object kill_ob;
string *message_hit;
object desc_ob;

int heal_start;
int heal_rate;
int heal_intv;
int chat_chance;
int chat_nr;

int a_chat_chance;
int a_chat_nr;

string the_text;
int have_text;


object dead_ob;
object init_ob;

int random_pick;

int spell_chance, spell_dam_mon;
string spell_mess1, spell_mess2;
object me;

set_desc_ob(ob) { desc_ob = ob; }

valid_attack(ob)
{
    /* Don't attack other monsters unless specifically allowed to. */
    return (!call_other(ob, "query_npc", 0) || can_kill);
}




id(str) {
    if (desc_ob) return call_other(desc_ob,"monster_id",str);
    return str == alt_name || str == name || str == alias || str == race;
}

heart_beat()
{
    int c;

     
    already_fight = 0;
    /* If there is none here test_if_any_here will turn of heat_beat */
    if(!test_if_any_here()) {
	if(have_text && talk_done) {
	    have_text = 0;
           test_match(the_text);
	} else {
	    set_heart_beat(0);
	    return;
	}
    }
    if (kill_ob && present(kill_ob, environment(this_object()))) {
	if (random(2) == 1)
	    return;		/* Delay attack some */
	attack_object(kill_ob);
	kill_ob = 0;
	return;
    }
    if (attacker_ob && present(attacker_ob, environment(this_object())) &&
      spell_chance > random(100)) {
	say(spell_mess1 + "\n", attacker_ob);
	tell_object(attacker_ob, spell_mess2 + "\n");
	call_other(attacker_ob, "hit_player", random(spell_dam_mon));
    }
    attack();
    if (attacker_ob && whimpy && hit_point < max_hp/5)
	run_away();
    if(chat_nr > 0 || a_chat_nr > 0) {
	c = random(100);
	if(attacker_ob && a_chat_nr > 0) {
	    if(c < a_chat_chance){
		c = random(a_chat_nr);
                a_chat(c);
	    }
	} else {
	    if(c < chat_chance && chat_nr > 0){
		c = random(chat_nr);
                chat(c);
	    }
	}
    }
    if(have_text && talk_done) {
	have_text = 0;
        test_match(the_text);
    }
}

can_put_and_get(str)
{
    if (!str)
	return 0;
    return 1;
}

int busy_catch_tell;


/*
 * Call the following functions to setup the monster.
 * Call them in the order they appear.
 */




/*
 * Force the monster to do a command. The force_us() function isn't
 * always good, because it checks the level of the caller, and this function
 * can be called by a room.
 */
init_command(cmd) {
    command(cmd);
}

/* Load chat */

set_dead_ob(ob)
{
    dead_ob = ob;
}

second_life()
{
   if(dead_ob)
	call_other(dead_ob,"monster_died",this_object());
}

dumpa(str)
{
    string foo;
    if (sscanf(str, "players/%s", foo)) return 0;
    if(!str)
	str = "MONSTER_DUMP";
    save_object(str);
}

set_init_ob(ob)
{
    init_ob = ob;
}


init() {
  int ste,atc;

    if(this_player() == me)
	return;
    if(dead_ob)
	if(call_other(dead_ob,"monster_init",this_object()))
	    return;
    if (attacker_ob) {
	set_heart_beat(1); /* Turn on heart beat */
    }
    if(this_player() && !call_other(this_player(),"query_npc")) {
	set_heart_beat(1);
	if (aggressive == 1)
    {
     atc = random(50);
     ste = call_other(this_player(), "query_attrib", "ste");
     if (ste < atc)
	    kill_ob = this_player();
   }
    }
}

set_info(str) { info = str; }
set_hbflag(str) {hbflag = str; }
query_hbflag() {return hbflag;}
query_info() {return info; }
set_alt_name(n) { alt_name = n; }
set_gender(str) { gender = str;}
query_aggressive() { return aggressive;}
query_race() {return race;}
set_message_hit(arr) {
   message_hit=arr;
}

