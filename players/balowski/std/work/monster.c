/*
 * A general purpose monster based on /obj/monster.c
 * 
 * Balowski@Nirvana
 */
#include "/players/balowski/lib.h"
#include <security.h>
inherit LIVING;
inherit OBJECT;
#include "talk.c"
#include "talkback.c"
#define WEAPON_CLASS_OF_HANDS 3

/* function prototypes */
status	test_if_any_here();
void	pick_any_obj();
string	query_hbflag();

/* variable declarations */
int	Aggressive, CanKill;
mixed	DeadOb, InitOb;
int	HealStart, HealRate, HealIntv;
int	RandomPick;
string	HBFlag;
static object	kill_ob;	/* somebody I'm about to attack */
static int	HitCount;	/* hit count */
static object	HitBy;		/* for multiple hit_player calls in 1 round */

void create()
{
    ::create();
    enable_commands();
    age = time();
    set_hands(({"right hand","left hand",}));
    set_primary_hand("right hand");
    HealIntv = 35;
    HealRate = 2;
}

status valid_attack(object ob)
{
    /* Don't attack other monsters unless specifically allowed to. */
    return (CanKill || !ob->query_npc());
}

void long(string str)
{
    string text;
    int health, hp, mhp;
    
    ::long(str);

    hp = query_hp();
    mhp = query_mhp();
    if (hp < mhp/10) {
	text = " is in very bad shape.\n";
    } else if (hp < mhp/5) {
	text = " is in bad shape.\n";
    } else if (hp < mhp/2) {
	text = " is somewhat hurt.\n";
    } else if (hp < mhp - 20) {
	text = " is slightly hurt.\n";
    } else {
	text = " is in good shape.\n";
    }
    write(capitalize(query_name()) + text);
}

void heart_beat()
{
    int c;

    HitBy = 0;
    HitCount = 1;
    AlreadyFought = 0;
    ActionPts += (c = query_level());
    if (ActionPts > c*3) ActionPts = c*3;

    if (!HealStart && query_hp() < query_mhp()) {
	call_out("autoheal_monster", HealIntv);
        HealStart = 1;
    }

    dotalk();
    dochat(objectp(query_attack()));
    
    /* If there is none here test_if_any_here will turn of heat_beat */
    if (!test_if_any_here()) {
	set_heart_beat(0);
	return;
    }
    if (kill_ob && present(kill_ob, environment())) {
	if (random(2) == 1) {	/* Delay attack some */
            tell_object(kill_ob, query_name() +
                        " is approaching you with murder in " +
                        query_possessive() + " eyes.\n");
	    attack_object(kill_ob);
	    kill_ob = 0;
	    return;
	}
    }
    /*if (Attacker && whimpy && query_hp() < whimpy) run_away();*/
    attack();
    if (RandomPick && random(100) < RandomPick) pick_any_obj();
}

void init()
{
    if (this_player() == this_object()) return;/* ? */
    if (InitOb && InitOb->monster_init(this_object())) return;
    if (this_player() && !this_player()->query_npc()) {
	set_heart_beat(1);
	if (random(Aggressive) > (int)this_player()->query_attrib("ste")) {
	    kill_ob = this_player();
	}
    }
}

int second_life()
{
    /* return !0 to prevent destruct */
    if (DeadOb) {
	string err; mixed x;
	/* danger-zone, I better catch */
	err = catch(x = (int) DeadOb->monster_died(this_object()));
	if (!err) return x;
    }
}

void autoheal_monster()
{
    heal_self(HealRate);
    if (HitPoints < MaxHit || SpellPoints < MaxSpell) {
	HealStart = 1;
	call_out("autoheal_monster", HealIntv);
    }
    else HealStart = 0;
}

/*
int protection_bonus(int dam, int ac, mixed zap) {
    if(!zap) zap = Attacker;
    if (zap && zap->query_level() < EXPLORE) {
	if (dam > 55) dam = random(30);
	else if (dam > 50) dam = 50;
    }
    if (this_player()) { 
	if (HitBy == this_player()) {
	    if (++HitCount > 2)
	      dam = dam/(HitCount + 2);
	}
	HitBy = this_player();
    }
    return ::protection_bonus(dam, ac, zap);
}

*/
int protection_bonus(int dam, int ac, mixed zap) { return ::protection_bonus(dam, ac, zap); }
status test_if_any_here()
{
    object ob;
    if (!environment()) return 0;
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

void pick_any_obj() {
    object ob, next;

    next = first_inventory(environment());
    while (ob = next) {
	next = next_inventory(ob);
	if (ob->get() && ob->short()) {
	    if (transfer(ob, this_object())) {
		say(query_name() + " tries to take " + ob->short() + " but fails.\n");
		return;
	    }
	    say(query_name() + " takes " + ob->short() + ".\n");
	    if (ob->weapon_class()) ob->wield(ob->query_name());
	    else if (ob->armor_class()) ob->wear(ob->query_name());
	    return;
	}
    }
}

/*
 * Call the following functions to setup the monster.
 * call set_name and set_level first!
 */
void set_name(string n)
{
    ::set_name(n);
    set_living_name(query_real_name());
    if (!query_short()) set_short(n);
    if (!query_long()) set_long("You see nothing special.\n");
}

void set_al(int al) { alignment = al;}
void set_wc(int wc) { if (wc > WeaponClass) WeaponClass = wc;}
void set_ac(int ac) { ArmourClass = ac;}
void set_aggressive(int a) { Aggressive = a;}
void set_can_kill(int a) { CanKill = a;}
void set_frog() { frog = 1;}
void set_whimpy(int w) { whimpy = w;}
void init_command(string cmd) { command(cmd);}
void set_dead_ob(mixed ob) { DeadOb = ob;}
void set_random_pick(int r) { RandomPick = r;}
void set_init_ob(mixed ob) { InitOb = ob;}
void set_hbflag(string str) { HBFlag = str;}
void set_gender(string str) { Gender = str;}
void set_ep(int ep) { experience = ep; }
void set_heal(int hr, int hi) { HealRate = hr; HealIntv = hi;}

string	query_hbflag() { return HBFlag;}
int	query_aggressive() { return Aggressive;}
status	query_npc() { return 1;}
int	query_attrib(string attr) { return query_level();}

status  get() {return 0;}
status  can_put_and_get(string str) {return str != 0;}
int     query_value() {return 0;}

/* some punks access set_hp/sp to deal damage */
/* only allow hp lowering before I am moved somewhere */
void set_hp(int hp)
{
    if (hp < query_hp() && environment()) return;
    HitPoints = MaxHit = hp;
}

void set_sp(int sp)
{
    if (sp < query_sp() && environment()) return;
    SpellPoints = MaxSpell = sp;
}

/* other things I do not appreciate done to my monsters */
/* I might want to filter attackers during combat instead (?) */
void attacked_by(object ob)
{
    if (ob != this_object()) ::attacked_by(ob);
}

int attack_object(object ob)
{
    if (ob != this_object()) ::attack_object(ob);
}

/*
 * Super set level. Sets hp/sp/ac/wc according to rules
 * spell_points are not in rules, but they are set to the same as hps
 */
void
set_level(int l)
{
    if (l < 1) return;
    ::set_level(l);
    
    switch (l) {
     case  1: set_hp(15);  set_wc(5);  set_ac(3); break;
     case  2: set_hp(30);  set_wc(6);  set_ac(3); break;
     case  3: set_hp(45);  set_wc(7);  set_ac(4); break;
     case  4: set_hp(60);  set_wc(8);  set_ac(4); break;
     case  5: set_hp(75);  set_wc(9);  set_ac(5); break;
     case  6: set_hp(90);  set_wc(10); set_ac(5); break;
     case  7: set_hp(105); set_wc(11); set_ac(6); break;
     case  8: set_hp(120); set_wc(12); set_ac(7); break;
     case  9: set_hp(135); set_wc(13); set_ac(7); break;
     case 10: set_hp(150); set_wc(14); set_ac(8); break;
     case 11: set_hp(165); set_wc(15); set_ac(9); break;
     case 12: set_hp(180); set_wc(16); set_ac(9); break;
     case 13: set_hp(195); set_wc(17); set_ac(10); break;
     case 14: set_hp(210); set_wc(18); set_ac(11); break;
     case 15: set_hp(225); set_wc(20); set_ac(12); break;
	
     case 16: set_hp(400); set_wc(22); set_ac(13); break;
     case 17: set_hp(425); set_wc(24); set_ac(14); break;
     case 18: set_hp(450); set_wc(26); set_ac(15); break;
     case 19: set_hp(475); set_wc(28); set_ac(16); break;
     default: set_hp(l*25); set_wc(3*l >> 1); set_ac(l - 3); break;
    }
    set_sp(query_hp());
    experience = (int) "room/adv_guild"->query_cost(l - 1);
}
