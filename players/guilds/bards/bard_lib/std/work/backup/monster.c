/*
 * A general purpose monster. Clone this object,
 * and call local functions to configure it.
 */
#include "/players/guilds/bards/bard_lib/lib.h"
#include <security.h>
inherit "/players/guilds/bards/bard_lib/std/work/living";
#include "/obj/chat_include.c"
#include "/obj/catch_talk_include.c"
#define WEAPON_CLASS_OF_HANDS 3

string	short_desc, long_desc, alias, alt_name, hbflag, info;
int	move_at_reset, aggressive, can_kill;
mixed	desc_ob, dead_ob, init_ob;
int	heal_start, heal_rate, heal_intv;
int	chat_chance;
int	a_chat_chance;
int	random_pick;
int 	spell_chance, spell_dam;
string	spell_mess1, spell_mess2;
string	the_text;
int	have_text;
int	busy_catch_tell;
static object	kill_ob;	/* somebody I'm about to attack */
static int	HitCount;	/* hit count */
static object	HitBy;		/* for multiple hit_player calls in one round. */


valid_attack(ob)
{
    /* Don't attack other monsters unless specifically allowed to. */
    return (!call_other(ob, "query_npc", 0) || can_kill);
}

reset(arg)
{
    if (arg) {
	if (move_at_reset)
	  random_move();
	return;
    }
    enable_commands();
    is_npc = 1;
}

random_move()
{
    int n;
    n = random(4);
    if (n == 0)
	command("west");
    else if (n == 1)
	command("east");
    else if (n == 2)
	command("south");
    else if (n == 3)
	command("north");
}

short() {
    if (desc_ob) return call_other(desc_ob,"monster_short",0);
    return short_desc;
}

void
long(string str) {
    string gender;
    int hp, mhp;
    
    if (desc_ob) {
        desc_ob->monster_long();
	return;
    }
    if (short_desc && (gender = query_gender_string()))
      write(short_desc + " (" + gender + ")\n");
    write (long_desc);
    hp = query_hp(); mhp = query_mhp();
    if (hp < mhp/10) {
	write(query_name() + " is in very bad shape.\n");
	return;
    }
    if (hp < mhp/5) {
	write(query_name() + " is in bad shape.\n");
	return;
    }
    if (hp < mhp/2) {
	write(query_name() + " is somewhat hurt.\n");
	return;
    }
    if (hp < mhp - 20) {
	write(query_name() + " is slightly hurt.\n");
	return;
    }
    write(query_name() + " is in good shape.\n");
}

id(str) {
    if (desc_ob) return call_other(desc_ob,"monster_id",str);
    return str == alt_name || str == query_real_name() || str == alias;
}

heart_beat()
{
    int c;

    age += 1;
    if (!heal_start && query_hp() < query_mhp()) {
	call_out("autoheal_monster", heal_intv);
        heal_start = 1;
    }

    HitBy = 0;
    HitCount = 1;
    AlreadyFought = 0;
    /* If there is none here test_if_any_here will turn of heat_beat */
    if (!test_if_any_here()) {
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
    if (Attacker && present(Attacker, environment()) &&
	spell_chance > random(100))
    {
	say(spell_mess1 + "\n", Attacker);
	tell_object(Attacker, spell_mess2 + "\n");
	call_other(Attacker, "hit_player", random(spell_dam));
    }
    attack();
    if (Attacker && whimpy && query_hp() < query_mhp()/5)
      run_away();
    if(chat_nr > 0 || a_chat_nr > 0) {
	c = random(100);
	if(Attacker && a_chat_nr > 0) {
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
    if(random_pick) {
	c = random(100);
	if(c < random_pick)
	  pick_any_obj();
    }
    if(have_text && talk_done) {
	have_text = 0;
        test_match(the_text);
    }
}

catch_tell(str) {
    string who;

    if (busy_catch_tell)    /* Should not happen, but does! */
	return;
    busy_catch_tell = 1;
    if(talk_done) {
	if(have_text) {
	    who = the_text;
	    the_text = str;
	    have_text = 1;
            test_match(the_text);
	} else {
	    the_text = str;
	    have_text = 1;
	}
    }
    busy_catch_tell = 0;
}

int
second_life() {
    if (dead_ob)
      return (int) call_other(dead_ob,"monster_died",this_object());
}

pick_any_obj() {
    object ob;
    int weight;

    ob = first_inventory(environment(this_object()));
    while(ob) {
	if (call_other(ob, "get", 0) && call_other(ob, "short")) {
	    weight = call_other(ob, "query_weight", 0);
	    if (!add_weight(weight)) {
		say(query_name() + " tries to take " + ob->short() +
		    " but fails.\n");
		return;
	    }
	    move_object(ob, this_object());
	    say(query_name() + " takes " + call_other(ob, "short", 0) + ".\n");
	    if (call_other(ob, "weapon_class", 0))
		call_other(ob, "wield", call_other(ob,"query_name"));
	    else if (call_other(ob, "armor_class", 0))
		call_other(ob, "wear", call_other(ob,"query_name"));
	    return;
	}
	ob = next_inventory(ob);
    }
}

dumpa(str) {
    string foo;
    if (sscanf(str, "players/%s", foo)) return 0;
    if (!str)
      str = "MONSTER_DUMP";
    save_object(str);
}

void init() {
    int ste,atc;

    if (this_player() == this_object())
      return;
    if (init_ob)
      if(call_other(init_ob,"monster_init",this_object()))
	return;
    if (Attacker) {
	set_heart_beat(1); /* Turn on heart beat */
    }
    if (this_player() && !call_other(this_player(),"query_npc")) {
	set_heart_beat(1);
	if (aggressive == 1) {
	    atc = random(50);
	    ste = call_other(this_player(), "query_attrib", "ste");
	    if (ste < atc)
	      kill_ob = this_player();
	}
    }
}

void
autoheal_monster() {
    heal_self(heal_rate);
    if (HitPoints < MaxHit || SpellPoints < MaxSpell)
      call_out("autoheal_monster", heal_intv);
    else heal_start = 0;
}


/*
 * If no one is here (except ourself), then turn off the heart beat.
 */

test_if_any_here()
{
    object ob;
    if (!environment(this_object())) return 0;
    if (query_hbflag() == "hbstayon") return 1;
    if (Attacker)
      if (Attacker->query_player_shell()) return 1;
    
    ob = first_inventory(environment());
    while (ob) {
	if (interactive(ob)) break;
	ob = next_inventory(ob);
    }
    return objectp(ob);
}

/*
 * Call the following functions to setup the monster.
 * Call them in the order they appear.
 */
set_name(n) {
    Name = n;
    set_living_name(n);
    CapName = capitalize(n);
    if (!short_desc)
      short_desc = CapName;
    if (!long_desc)
      long_desc = "You see nothing special.\n";
}

set_level(l) {
    level = l;
    if (!WeaponClass)
      WeaponClass = WEAPON_CLASS_OF_HANDS;
    if (!HitPoints)
      HitPoints = 50 + (level - 1) * 8;	/* Same as a player */
    MaxHit = HitPoints;
    if (!experience)
      experience = call_other("room/adv_guild", "query_cost", l-1);
    if (!heal_intv) {
	heal_intv = 35;
	heal_rate = 2;
    }
}

void set_al(int al) {
    /* Limit alignment to keep wizards from making their monsters worth
       much too much */
    if (al > 1000)
	al = 1000;
    if (al < -1000)
	al = -1000;
    alignment = al;
}

void set_short(string sh) {
    short_desc = sh;
    if (!long_desc) long_desc = short_desc + "\n";
}
void set_long(string lo) { long_desc = lo;}
void set_desc_ob(mixed ob) { desc_ob = ob; }
void set_wc(int wc) { WeaponClass = wc;}
void set_ac(int ac) { ArmourClass = ac;}
void set_move_at_reset() { move_at_reset = 1;}
void set_aggressive(int a) { aggressive = a;}
void set_can_kill(int a) { can_kill = a;}
void set_chance(int c) { spell_chance = c;}/* chance of casting a spell. */
void set_spell_mess1(string m) { spell_mess1 = m;}
void set_spell_mess2(string m) { spell_mess2 = m;}/* Message to the victim. */
void set_spell_dam(int d) { spell_dam = d;}
void set_frog() { frog = 1;}
void set_whimpy(int w) { whimpy = w;}
void init_command(string cmd) { command(cmd);}
void set_chat_chance(int c) { chat_chance = c;}
void set_a_chat_chance(int c) { a_chat_chance = c;}
void set_dead_ob(mixed ob) { dead_ob = ob;}
void set_random_pick(int r) { random_pick = r;}
void set_init_ob(mixed ob) { init_ob = ob;}
void set_info(string str) { info = str;}
void set_hbflag(string str) { hbflag = str;}
void set_gender(string str) { Gender = str;}
void set_alt_name(string n) { alt_name = n;}
void set_alias(string a) { alias = a; }
void set_hp(int hp) { HitPoints = MaxHit = hp;}
void set_sp(int sp) { SpellPoints = MaxSpell = sp;}
void set_ep(int ep) { experience = ep; }
void set_heal(int hr, int hi) { heal_rate = hr; heal_intv = hi;}

string query_hbflag() { return hbflag;}
string query_info() { return info;}
int query_aggressive() { return aggressive;}
status query_npc() { return 1;}

int protection_bonus(int dam, int ac, mixed zap) {
    /* PUT a cap on damage a player can do in one hit. */
    if (!zap) zap = Attacker; /* what is this zap? */
    if (zap && zap->query_level() < EXPLORE) {
	if (dam > 55) dam = random(30);
	else if (dam > 50) dam = 50;
    }
    /* penalize multiple calls to hit_player() by the same player in one hb */
    if (this_player()) { 
	if (HitBy == this_player()) {
	    if (++HitCount > 2)
	      dam = dam/(HitCount + 2);
	}
	HitBy = this_player();
    }
    return ::protection_bonus(dam, ac, zap);
}
