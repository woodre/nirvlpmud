/*
 * Generic creature thing. Based on /obj/living.c
 * renaming !static vars is a major compat buster
 */
#include <security.h>
#include "/players/balowski/lib.h"
#pragma strict_types
#pragma save_types
#define ALIGN_EXP_DIVISOR		1800
#define WA_FACTOR			3
#define EXP_DIVISOR			190
#define WEAPON_CLASS_OF_HANDS		3
#define ARMOUR_CLASS_OF_BARE		0
#define KILL_NEUTRAL_ALIGNMENT		10
#define ADJ_ALIGNMENT(al)		((-al - KILL_NEUTRAL_ALIGNMENT)/4)
#define NAME_OF_GHOST			"some mist"
inherit BASE;

/* variable declarations */
string	Gender;
string	Race;
int	MaxSpell, SpellPoints,
	MaxHit, HitPoints;
int	level, experience, alignment, money, age;
int	luck, is_invis, whimpy, ghost, dead;
status	frog, crime;
string	whimpy_dir;
string	msgin, msgout, mmsgout, mmsgin;
int	ActionPts;
static int	LocalWeight;
static object	Armour;
static int	ArmourClass;
static int	WeaponClass;
static mapping	Hands;
static mixed	Weapons;
static string	PrimaryHand;
static mixed	SpellOb, SpellName;
static int	AlreadyFought;
static object	Attacker;	/* first creature attacking us. */
static object	AltAttacker;	/* other creature attacking us. */
static object	Hunted, Hunter;
static int	HuntingTime;
static string	CurrentRoom;

/* function prototypes. *_name functions are virtual */
string		query_name();
string		query_real_name();
varargs int	query_invis(int level);
status		attack_object(object ob);
void		attacked_by(object ob);
void		set_ghost(int g);
void		stop_hunter();
varargs void	stop_fight(object who);
int		get_kill_bonus(object killer);
void		transfer_all_to(object dest);
status		valid_attack(object ob);
varargs mixed	query_wielded(string limb);

#define checked_say(s) if (query_invis() < INVIS_ACTION) say(s)
#define max(a,b) ((a > b) ? a : b)
#define min(a,b) ((a < b) ? a : b)
#define abs(a) ((a < 0) ? -a : a)

/*
 * This routine is called from objects that moves the player.
 * Special: direction "X" means teleport.
 */
varargs status
move_player(mixed dir_dest, string outmsg)
{
    string dir, msg;
    mixed dest;
    int is_light;

    dir = (outmsg || "X");
    if (stringp(dest = dir_dest)) {
	sscanf(dir_dest, "%s#%s", dir, dest);
    }
    if (!dest) {
	tell_object(this_object(), "Bad move.\n");
	return 0;
    }
    if (--HuntingTime == 0) {
	if (Hunter) Hunter->stop_hunter();
	Hunter = Hunted = 0;
    }
    if (Attacker && present(Attacker, environment())) {
	HuntingTime = 10;
	tell_object(this_object(), "You are now hunted by " +
		    Attacker->query_name() + ".\n");
	Hunter = Attacker;
    }

    if (environment()) is_light = set_light(0);
    if (is_light > 0) {
	msg = ghost ? NAME_OF_GHOST : query_name();
	if (dir == "X") {
	    if (query_invis() < INVIS_TELEPORT) {
		if (!mmsgout) mmsgout = "disappears in a puff of smoke";
		msg += " " + mmsgout + ".\n";
	    } else msg = 0;
	}
	else {
	    if (query_invis() < NO_MOVE) {
		if (!msgout) msgout = "leaves";
		msg += " " + msgout + " " + dir + ".\n";
	    } else msg = 0;
	}
	/* I never come here when environment is 0, but watch out.. */
	if (msg) tell_room(environment(), msg, ({this_object()}));
    }
    move_object(this_object(), dest);
    CurrentRoom = dest;

    is_light = set_light(0);
    if (is_light > 0) {
	msg = ghost ? NAME_OF_GHOST : query_name();
	if (dir == "X") {
	    if (query_invis() < INVIS_TELEPORT) {
		if (!mmsgin) mmsgin = "appears in a puff of smoke";
		msg += " " + mmsgin + ".\n";
	    } else msg = 0;
	}
	else {
	    if (query_invis() < NO_MOVE) {
		if (!msgin) msgin = "arrives";
		msg += " " + msgin + ".\n";
	    } else msg = 0;
	}
	if (msg) tell_room(environment(), msg, ({this_object()}));
    }
	    
    if (Hunted && present(Hunted, environment()))
	attack_object(Hunted);
    if (Hunter && present(Hunter, environment()))
	Hunter->attack_object(this_object());
}

/*
 * Do luck and armour class things and return the damage left
 * I have swapped some things, luck comes before armour class now
 * I don't really have an idea what the zap arg is for..
 */
static int
protection_bonus(int dam, int ac, mixed zap) {
    int lucky;
    
    lucky = random(500);
    /* // ought to be query_attrib("luck") */
    if (lucky < luck) {
	tell_object(this_object(), "Your luck comes through for you.\n");
	if (luck < 12) dam = dam/2;
	else if (luck < 16) dam = dam/3;
	else dam = dam/5;
    }
    if (lucky > 494) {
	dam = dam*5/3;
	/* // remember to bug Boltar about this.. missing "if (Attacker)" */
	if (Attacker)
	  tell_object(this_object(), Attacker->query_name() +
		      " hits you with a crushing blow.\n");
    }
    dam -= random(ac + 1);
    return dam;
}

/*
 * Give some more experience for staying in your alignment
 * All the following basically works out to
 * exp_bonus = abs(monster's align - player's align)/75000 * exp;
 * Of course we can't just say that because of underflow problems.
 */
int
get_kill_bonus(object killer)
{
    int wa_bonus, exp_diff, exp_bonus, base_bonus;
    
    if (experience > 1000000) experience = 1000000; /* for npcs */

    exp_diff = alignment - (int) killer->query_alignment();
    if (exp_diff < 0)
      exp_diff = -exp_diff;   /* Get absolute value */
    exp_diff /= 10;   /* Scale this down so we don't overflow! */

    exp_bonus = experience / 100;
    exp_bonus *= exp_diff;
    exp_bonus /= ALIGN_EXP_DIVISOR;

    /* Base bonus regardless of alignment is experience/75 */
    base_bonus = experience/EXP_DIVISOR;
    /* Don't let the alignment bonus exceed 1/2 the base bonus */
    if (exp_bonus > base_bonus/2)
      exp_bonus = base_bonus/2;
    exp_bonus += base_bonus;
    wa_bonus = WeaponClass * ArmourClass * WA_FACTOR;
    if (wa_bonus > base_bonus/3)
      wa_bonus = base_bonus/3;
    exp_bonus += wa_bonus;
    
    return exp_bonus;
}

/*
 * This function is called from other players when they want to make
 * damage to us. We return how much damage we received, which will
 * change the attackers score. This routine is probably called from
 * heart_beat() from another player.
 */
varargs int
hit_player(int dam, mixed zap)
{
    if (this_player() &&
	this_player() != this_object() &&
	this_player()->query_level() < EXPLORE) {
	/* -= Protection =- */  
	if (this_player()->is_player() &&
	    (object)this_player()->query_attack() != this_object() &&
	    !this_player()->valid_attack(this_object()))
	{ /* bad attack, could be logged */
	    write("Your attack fails.\n");
	    return 0;
	}
	if (!Attacker || !AltAttacker) attacked_by(this_player());
	/* -= Crime =- */
	if (this_object()->crime_to_attack() && !this_player()->query_crime())
	  this_player()->set_crime();
    }
    
    dam = protection_bonus(dam, ArmourClass, zap);
    if (HitPoints < 0) {
	if (dam <= 0) dam = 1;
	HitPoints = 0;
    }
    else {
	if (dam <= 0) return 0;
	dam = min(dam, HitPoints + 1);
    }
    HitPoints -= dam;

    if (HitPoints < 0) {	/* We died ! */
	object corpse;
	say(query_name() + " died.\n");
	set_ghost(1);
	HitPoints = max(10, MaxHit/3);
	if (Hunter) Hunter->stop_hunter();
	Hunter = Hunted = 0;
	
	corpse = clone_object("obj/corpse");
	corpse->set_name(query_real_name());
	corpse->set_corpse_level(level);
	move_object(corpse, environment());
	transfer_all_to(corpse);

	/* The player killing us will update his alignment */
	/* and experience if he exists. */
	if (Attacker) {
	    object party;
	    int exp_bonus;

	    Attacker->add_alignment(ADJ_ALIGNMENT(alignment));
	    exp_bonus = get_kill_bonus(Attacker);
	    if (party = present("party object", Attacker)) {
		exp_bonus = 24*exp_bonus/30;
		party->share_exp(exp_bonus);
	    }
	    else
	      Attacker->add_exp(exp_bonus);
	}
	Attacker = AltAttacker = 0;
	if (!this_object()->second_life())
	  destruct(this_object());
    }
    return dam;
}

void
magic_attack(object victim)
{
    int damage, tmp;
    if (objectp(SpellOb)) {
	damage = (int) call_other(SpellOb, SpellName, victim);
	SpellOb = SpellName = 0;
	if (damage > 0) {
	    tmp = (int)victim->hit_player(damage);
	    experience += tmp;
	}
    }
}

void
unarmed_attack(object victim)
{
    int tmp, whit, damage;
    string aname;

    damage = WeaponClass;
    damage = random(damage - (int) this_object()->query_intoxination()/5);
	
    /* deal the damage */
    if (damage > 0) {
	tmp = (int)victim->hit_player(damage);
	experience += tmp;
    }

    /* Does the enemy still live ? */
    if (victim && !victim->query_ghost()) {
	string what, how, uwhat;

	aname = (string)victim->query_name();
	switch (tmp) {
	  case 20..29:
	    how = " with a bone crushing sound";
	    what = "smashes"; uwhat = "smash";
	    break;
	  case 10..19:
	    how = " very hard";
	    what = "hits"; uwhat = "hit";
	    break;
	  case 5..9:
	    how = " hard";
	    what = "hits"; uwhat = "hit";
	    break;
	  case 3..4:
	    how = "";
	    what = "hits"; uwhat = "hit";
	    break;
	  case 2:
	    how = "";
	    what = "grazes"; uwhat = "graze";
	    break;
	  case 1:
	    how = " in the stomach";
	    what = "tickles"; uwhat = "tickle";
	    break;
	  default:
	    if (tmp < 1) {
		how = "";
		what = "misses"; uwhat = "miss";
	    }
	    else {
		how = " to small fragments";
		what = "massacres"; uwhat = "massacre";
	    }
	}
	tell_object(this_object(), "You " + what + " " + aname + how + ".\n");
	tell_object(victim, query_name() + " " + what + " you" + how + ".\n");
	say(query_name() + " " + what + " " + aname + how + ".\n", victim);
    }
}

void
armed_attack(object victim, object weapon)
{
    int tmp, whit, damage;
    string aname;

    damage = WeaponClass;
    if (weapon) {
	damage = (int) weapon->weapon_class();
	whit = (mixed) weapon->hit(Attacker);
	if (intp(whit)) damage += whit;
	else damage = 0;
    }
    damage = random(damage - (int) this_object()->query_intoxination()/5);
	
    /* deal the damage */
    if (damage > 0) {
	tmp = (int)victim->hit_player(damage);
	experience += tmp;
    }

    /* Does the enemy still live ? */
    if (victim && !victim->query_ghost()) {
	string what, how, uwhat;

	aname = (string)victim->query_name();
	switch (tmp) {
	  case 20..29:
	    how = " with a bone crushing sound";
	    what = "smashes"; uwhat = "smash";
	    break;
	  case 10..19:
	    how = " very hard";
	    what = "hits"; uwhat = "hit";
	    break;
	  case 5..9:
	    how = " hard";
	    what = "hits"; uwhat = "hit";
	    break;
	  case 3..4:
	    how = "";
	    what = "hits"; uwhat = "hit";
	    break;
	  case 2:
	    how = "";
	    what = "grazes"; uwhat = "graze";
	    break;
	  case 1:
	    how = " in the stomach";
	    what = "tickles"; uwhat = "tickle";
	    break;
	  default:
	    if (tmp < 1) {
		how = "";
		what = "misses"; uwhat = "miss";
	    }
	    else {
		how = " to small fragments";
		what = "massacres"; uwhat = "massacre";
	    }
	}
	tell_object(this_object(), "You " + what + " " + aname + how + ".\n");
	tell_object(victim, query_name() + " " + what + " you" + how + ".\n");
	say(query_name() + " " + what + " " + aname + how + ".\n", victim);
    }
}

/*
 * Return true if there still is a fight. (called recursively)
 */
status
attack()
{
    int aghost;
    string aname;
    object *weapons;

    if (!Attacker) return (SpellOb = 0);
    /* never fight a disconnected player */
    if (Attacker->is_player() && !interactive(Attacker)) {
	stop_fight(Attacker);
	return attack();
    }
    if (present(Attacker, environment())) {
	aname = (string)Attacker->query_name();
	aghost = (int)Attacker->query_ghost();
    }
    else {
	if (Hunter) {	/* don't hunt if being hunted */
	    tell_object(this_object(), "You are now hunting " +	aname + ".\n");
	    Hunted = Attacker;
	    HuntingTime = 10;
	}
    }
    /* we don't want to fight Attacker if: !name or ghost or !present */
    if (!aname || aghost) {
	stop_fight(Attacker);
	if (attack()) {
	    if (Attacker) tell_object(this_object(), "You turn to attack " +
				      Attacker->query_name() + ".\n");
	    return 1;
	}
	return 0;
    }
    Attacker->attacked_by(this_object());
    
    if (SpellOb) {
	magic_attack(Attacker);
    }
    else if (weapons = query_wielded()) {
	int i;
	i = sizeof(weapons);
	while (i--) {
	    if (weapons[i]) {
		armed_attack(Attacker, weapons[i]);
		ActionPts -= 15;
	    }
	    if (ActionPts < 15 || !Attacker || Attacker->query_ghost()) break;
	}
    }
    else {
	unarmed_attack(Attacker);
    }

    if (!Attacker || Attacker->query_ghost()) {
	tell_object(this_object(), "You killed " + aname + ".\n");
	Attacker = AltAttacker;
	AltAttacker = 0;
    }
    AlreadyFought = 1;
    return objectp(Attacker);
}

/*
 * This routine is called when we are attacked by somebody.
 */
void
attacked_by(object ob) {
    if (!Attacker) {
	Attacker = ob;
	set_heart_beat(1);
	return;
    }
    if (!AltAttacker) {
	AltAttacker = ob;
	return;
    }
}

varargs void
stop_fight(object who) {
    if (who) {
	if (who == Attacker) {
	    Attacker = AltAttacker;
	    AltAttacker = 0;
	}
	else if (who == AltAttacker) {
	    AltAttacker = 0;
	}
    }
    else {
	Attacker = AltAttacker;
	AltAttacker = 0;
    }
}

void
stop_hunter()
{
    Hunter = 0;
    tell_object(this_object(), "You are no longer hunted.\n");
}

status
attack_object(object ob)
{
    if (!ob) {
	stop_hunter();
	return 0;
    }
    if (ob->query_ghost())
	return 0;
    if (!this_object()->valid_attack(ob)) {
	return 0;
    }
    set_heart_beat(1);		/* For monsters, start the heart beat */
    SpellOb = SpellName = 0;	/* Zero these out just in case */

    if (Attacker == ob) {
	attack();
	return 1;
    }
    if (AltAttacker == ob) {
	AltAttacker = Attacker;
	Attacker = ob;
	attack();
	return 1;
    }
    Attacker = ob;
    attack();
    return 1;
}

status
xspell_object(object ob, string name)
{
    if (!valid_attack(ob)) {
	write("You can't attack " + ob->query_name() + "!\n");
	return 0;
    }
    SpellOb = ob;
    SpellName = name;
    Attacker = ob;
    return 1;
}

void
run_away() {
    object here;
    int i, j;
    string *dirs;

    here = environment();
    dirs = ({"east","west","north","south","up","down","in","out",
	     "northeast","northwest","southeast","southwest",});
    i = 12;		/* max attempts */
    j = random(sizeof(dirs)); /* seed */
    while (i-- && here == environment()) {
	command(dirs[j++]);
	if (j > sizeof(dirs)) j = 0;
    }

    if (here == environment()) {
	say(query_name() + " tried, but failed to run away.\n", this_object());
	tell_object(this_object(),
		    "Your legs tried to run away, but failed.\n");
    } else {
	tell_object(this_object(), "Your legs run away with you!\n");
    }
}

void
drop_all_money(status verbose) {
    object mon;

    if (!money) return;
    mon = clone_object("obj/money");
    mon->set_money(money);
    move_object(mon, environment());
    if (verbose) {
	checked_say(query_name() + " drops " + money + " gold coins.\n");
	tell_object(this_object(), "You drop " + money + " gold coins.\n");
    }
    money = 0;
}

status
frog_curse(int curse) {
    if (curse) {
	if (!frog) tell_object(this_object(), "You turn into a frog !\n");
	frog = 1;
	return 1;
    }
    if (frog) tell_object(this_object(), "You turn HUMAN again.\n");
    frog = 0;
    return 0;
}

varargs int
query_invis(int num) {
    if (!num) {
	return is_invis;
    } else {
	if (level <= num || num >= ALL_POWER) {
	    return -is_invis;
	} else { return is_invis;}
    }
}

string query_gender_string() {return Gender;}
string query_pronoun() {return
    (Gender == "male") ? "he" :
    (Gender == "female") ? "she" : "it";
}
string query_possessive() {return
    (Gender == "male") ? "his" :
    (Gender == "female") ? "her" : "its";
}
string query_objective() {return
    (Gender == "male") ? "him" :
    (Gender == "female") ? "her" : "it";
}

int     query_hp() {return HitPoints;}
int     query_sp() {return SpellPoints;}
int     query_msp() {return MaxSpell;}
int     query_mhp() {return MaxHit;}
int     query_wc() {return WeaponClass;}
int     query_ac() {return ArmourClass;}
varargs object  query_weapon(string hand) {return Hands[(hand || PrimaryHand)];}
object  query_hunted() {return Hunted;}
int     query_wimpy() {return whimpy;}
string	query_current_room() {return CurrentRoom;}
int     query_money() {return money;}
int     query_exp() {return experience;}
status  query_frog() {return frog;}
status  query_ghost() {return ghost;}
mixed   query_attack() {return Attacker;}
int     query_alignment() {return alignment;}
int     query_level() {return level;}
string	query_race() {return Race;}
int     query_age() {return ((time() - age) >> 1);}

void	set_race(string r) { Race = r;}
void    set_ghost(int g) { ghost = g;}
void	set_level(int l) { level = l;}
void    add_money(int m) { money = money + m;}

void
set_env(string s, mixed x)
{
    switch (s) {
    case "msgout" : msgout = x; break;
    case "msgin"  : msgin = x; break;
    case "mmsgout": mmsgout = x; break;
    case "mmsgin" : mmsgin = x; break;
    }
}

/* // remember this needs work */
status
add_weight(int w)
{
    if (w + LocalWeight > level + 10 && level < 20)
	return 0;
    LocalWeight += w;
    return 1;
}

void heal_self(int h) {
    HitPoints = min(HitPoints + h, MaxHit);
    SpellPoints = min(SpellPoints + h, MaxSpell);
    if (h < 0) hit_player(0);
}

void add_spell_point(int h) {
    SpellPoints = min(SpellPoints + h, MaxSpell);
}

void
transfer_all_to(object dest)
{
    object ob;
    object next_ob;

    if (!dest) return 0;
    next_ob = first_inventory(this_object());
    while (ob = next_ob) {
	next_ob = next_inventory(ob);
	if (!call_other(ob, "drop", 1))
	  if(ob)
	    move_object(ob, dest);
    }
    LocalWeight = 0;
    if (money > 0) {
	ob = clone_object("obj/money");
	ob->set_money(money);
	move_object(ob, dest);
	money = 0;
    }
}

/* Wield a weapon. */
varargs void
stop_wielding(object w) {
    string *ks; int i;

    if (!w) {
	w = previous_object();
	if (!w) return;
    }

    i = sizeof(ks = m_indices(Hands));
    while (i--) {
	if (Hands[ks[i]] == w) {
	    Hands[ks[i]] = 0;
	    if (ks[i] == PrimaryHand) WeaponClass = WEAPON_CLASS_OF_HANDS;
	}
    }
    w->un_wield(dead);

    if (pointerp(Weapons)) Weapons -= ({ w });
    else Weapons = 0;
}

/*
 * this only supports one handed weapons
 */
varargs void
wield(object weapon, string *hands)
{
    object w;
    int i;

    if (!hands) {
	if (Hands[PrimaryHand]) {
	    hands = m_indices(Hands) - ({ PrimaryHand });
	    if (sizeof(hands)) hands = hands[0..0];
	    else hands = ({ PrimaryHand });
	}
	else hands = ({ PrimaryHand });
    }
    i = sizeof(hands);
    while (i--) {
	if (w = Hands[hands[i]]) stop_wielding(w);
	Hands[hands[i]] = weapon;
	if (hands[i] == PrimaryHand) WeaponClass = (int)weapon->weapon_class();
    }
    if (!Weapons) Weapons = ({ weapon });
    else if (pointerp(Weapons)) Weapons += ({ weapon });

    say(query_name() + " wields " + (string)weapon->query_name() + ".\n");
    write("Ok.\n");
}

/* Wear some armor. */
mixed
wear(object armour) {
    object old;

    if (Armour) {
	if (old = (object)Armour->test_type(armour->query_type()))
	  return old;
	armour->link(Armour);
    }
    Armour = armour;
    ArmourClass = (int)Armour->tot_ac();
    say(query_name() + " wears " + armour->query_name() + ".\n");
    write("Ok.\n");
}

void
stop_wearing(string name)
{
    if (!Armour) {
	write("This is a bug, no Armour\n");
	return;
    }
    Armour = (object)Armour->remove_link(name);
    if (Armour && objectp(Armour)) {
	ArmourClass = (int)Armour->tot_ac();
    }
    else {
	ArmourClass = 0;
	Armour = 0;
    }
    if (!dead) say(query_name() + " removes " + name + ".\n");
    write("Ok.\n");
}

void
show_age() {
    int i, t;

    write("age:\t");
    i = query_age();
    if (t = i/43200) {
	write(t + " days ");
	i %= 43200;
    }
    if (t = i/1800) {
	write(t + " hours ");
	i %= 1800;
    }
    if (t = i/30) {
	write(t + " minutes ");
	i %= 30;
    }
    write(i*2 + " seconds.\n");
}

void
show_stats() {
    string *ks; int i; object w;

    write(this_object()->short() + "\nlevel: " + level + "+" +
	  this_object()->query_extra_level());
    write("\nghost: " + ghost + "\n");
    if (query_invis()) write("invis: " + is_invis + "\n");
    if ((int)this_player()->query_level() > STAT) {
	write("hp: " + HitPoints + "\n");
	write("spell: " + SpellPoints + "\n");
    }
    write("max hp: " + MaxHit + "\n");
    write("max spell: " + MaxSpell + "\n");
    write("experience: "+ experience + "\n");
    write("coins: "+ money + "\n");
    write("align: \t" + alignment + "\n");
    write("gender: \t" + query_gender_string() + "\n");

    write("armor class: " + ArmourClass);
    if (Armour) write("\narmor: " + (string)Armour->rec_short());
    write("\nweapon class: \t" + WeaponClass);
    write("\nWeapons:\n");
    i = sizeof(ks = keys(Hands));
    while (i--) {
	w = Hands[ks[i]];
	write("  " + ks[i] + ": " +
	      (w ? ((string) w->query_name() + " (" + file_name(w) + ")\n")
		 : "none\n"));
    }
    write("intoxinated:  " + this_object()->query_intoxination());
    write("\ncarry: \t" + LocalWeight);

    if (Attacker) write("\nattack:  " + (string)Attacker->query_name());
    if (AltAttacker) write("\nalt attack:  " + (string)AltAttacker->query_name());
    write("\n"); show_age();
    if (environment()) write("room: " + file_name(environment()) + "\n");
    else write("room: No environment\n");
    write("this_object(): " + file_name(this_object()) + "\n");
    write("Creator: " + creator(this_object()) + "\n");
}

/* some wielding limb code */
void set_hands(string *hands) {
    int i;
    if (!(i = sizeof(hands))) return;
    Hands = ([ ]);
    while (i--) Hands[hands[i]] = 0;
}

void set_primary_hand(string hand) {
    PrimaryHand = hand;
}

string query_primary_hand() {
    return PrimaryHand;
}

string *query_hands() {
    return m_indices(Hands);
}

varargs mixed query_wielded(string limb) {
    return limb ? Hands[limb] : Weapons;
}

status query_not_wielded(string limb) {
    return !Hands[limb];
}

string *query_free_hands() {
    return filter_array(query_hands(), "query_not_wielded", this_object());
}

mixed query_can_wield(object ob, string *limbs) {
    int i;
    string *hands;

    i = sizeof(limbs);
    hands = query_hands();
    while (i--) {
	if (member_array(limbs[i], hands) < 0)
	  return "You have no " + limbs[i] + ".\n";
	if (query_wielded(limbs[i]))
	  return "You are already using your " + limbs[i] + ".\n";
    }
    return 1;
}

int query_save_flag() { return 1;}
