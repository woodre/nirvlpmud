/*
 * Weapon thingie by Balowski/Rasmus
 * - Changed wear/break code somewhat so that class isn't truncated, etc
 * - Refined wear code with durability and other parameters
 * - Feeble attempts at prevent_wield and prevent_unwield
 * - Added locker saving code
 */
#include "/players/guilds/bards/bard_lib/lib.h"
#include "weapon.h"
#define SAFE_MAX 2000000000
inherit		ITEM;
static object	WieldedBy;
static mixed	HitFunc;
static string	*WornIn;
/*static mixed   WieldFunc;*/
string		*HitMsgs;
int		Class;
int		ClassLoss;
int		Hands;
/*
 * Type tells what kind of weapon we have (should combos be possible?)
 * "blunt" : club, mace, hammer
 * "pointed" : rapier, spear
 * "cutting" : sword, axe
 */
string		Type;
/*
 * Durability tells how long until the wc deteriorates
 * Misses count Class, hits count damage dealt
 * Fragility tells how high ClassLoss can go before weapon breaks
 * Reparable tells how many times a weapon can be repaired (-1 for infinite)
 */
int		Durability;
int		Fragility;
int		Reparable;
int		Wear;
status		Broken;
int		Hits, Inflicted;

void
create()
{
    ::create();
    set_name("sword");
    set_type("cutting");
    Hands = 1;
    Durability = 10000;
    Fragility = 3;
    Reparable = -1;
}

string
short()
{
    string tmp;
    if (!(tmp = ::short())) return 0;
    if (query_wielded()) {
	if (WornIn) {
	    int max, i;
	    tmp += " (wielded in ";
	    max = sizeof(WornIn);
	    for (i = 0; i < max; i++) {
		tmp += WornIn[i];
		if (i == max - 1) tmp += ")";
		else if (i == max - 2) tmp += " and ";
		else tmp += ", ";
	    }
	} else tmp += " (wielded)";
    }
    if (Broken) tmp += " [BROKEN]";
    if (this_player() && ((int) this_player()->query_level() > 30))
      tmp += "  < wc " + Class + "," + query_eff_wc() + " >";
    return tmp;
}

void
long(string id)
{
    ::long(id);
    if (!ClassLoss) write("It is like new.\n");
    else if (ClassLoss == 1) write("It has a few nicks.\n");
    else if (ClassLoss == 2) write("It has been around.\n");
    else if (ClassLoss == 3) write("It is in need of repair.\n");
    else write("It is ruined.\n");
    
    if (this_player()->query_level() > 100)
      write("Wear: " + Wear + "\tLoss: " + ClassLoss +
	    "\nHits: " + Hits + "\tInflicted: " + Inflicted + "\n");
}

int
query_value()
{
    int x;
    x = ::query_value();
    return Broken ? (x >> 2) : x;
}

void
set_type(string t)
{
    Type = t;
}

string
query_type()
{
    return Type;
}

void
set_class(int c)
{
    Class = c;
}

int
query_class()
{
    return Class;
}

void
set_durability(int d)
{
    Durability = d;
}

int
query_durability()
{
    return Durability;
}

void
set_reparable(int x)
{
    Reparable = x;
}

int
query_reparable()
{
    return Reparable;
}

void
set_fragility(int x)
{
    Fragility = x;
}

int
query_fragility()
{
    return Fragility;
}

void
set_hands(int x)
{
    Hands = x;
}

int
query_hands()
{
    return Hands;
}

void
set_hit_func(mixed f)
{
    HitFunc = f;
}

/* old query function */
int
weapon_class()
{
    return Class;
}

/* should have been query_broken.. orig was query_broke */
status query_broke()
{
    return Broken;
}

status query_wielded()
{
    return objectp(WieldedBy);
}

status query_offwielded()
{
    return (WornIn && member_array("left hand", WornIn) >= 0);
}

object query_wielded_by()
{
    return WieldedBy;
}

int
query_Wear()
{
    return Wear + ClassLoss*Durability;
}

mixed
query_eff_wc()
{
    if (!Hits) return 0;
    return Inflicted/Hits;
}

/*
 * drop/wield/unwield stuff
 */
int
drop(int silently)
{
    object wby;
    
    wby = WieldedBy;
    if (objectp(wby)) {
        /* if it's a player and he is alive, see if he can remove */
        if (wby->is_player() && !wby->query_ghost()
	&&  prevent_unwield(silently))
            return 1;

	if (!silently) tell_object(wby, "You drop your wielded weapon.\n");

	if (function_exists("offwield", wby)) {
	    if (query_offwielded()) {
		wby->stop_offwielding();
		if (query_hands() > 1) wby->stop_wielding();
	    }
	    else wby->stop_wielding();
	}
	else {
	    wby->stop_wielding(this_object());
	}
        ev_unwield();
    }
}

int
prevent_wield(object who)
{
    if (present("notweapon", who)) {
	write("You are unable to wield it for some reason.\n");
	return 1;
    }
}

int
prevent_unwield(int silently)
{
}

void
ev_wield(object who, string *limbs)
{
    WieldedBy = who;
    WornIn = limbs;
}

void
ev_unwield()
{
    /* watch out for endless loop */
    /*if (objectp(WieldedBy)) WieldedBy->stop_wielding(this_object());*/
    WornIn = WieldedBy = 0;
}

/* called from living when another weapon is being wielded */
void
un_wield(int dead)
{
    ev_unwield();
}

mixed
hit(object attacker)
{
    mixed x;
    if (HitFunc)
      x = (mixed) HitFunc->weapon_hit(attacker);
    return intp(x) ? x - ClassLoss : x;
}

void
re_break()
{
    Broken = 1;
    ClassLoss = 2*Class/3;
}

void
weapon_breaks()
{
    if (Broken) return;
    if (WieldedBy) tell_object(WieldedBy, "Your weapon BREAKS!\n");
    re_break();
}

status
sharpen_weapon()
{
    if (Broken) return 0;
    ClassLoss = 0;
    Wear = Wear >> 1;
    if (Reparable > 0 && !random(4)) Reparable--;
    return 1;
}
    
status
fix_weapon()
{
    if (!Broken || !Reparable) return 0;
    Broken = 0;
    Wear = Wear >> 1;
    ClassLoss = 0;
    if (Reparable > 0) Reparable--;
    return 1;
}

void
wear_and_tear(int amt)
{
    Wear += amt;
    if (Wear >= Durability) {
	Wear -= Durability;
	ClassLoss++;
	if (ClassLoss > Fragility) weapon_breaks();
	else tell_object(WieldedBy, "Your weapon was slightly damaged.\n");
    }
}

void
count_misses()
{
    wear_and_tear(Class);
    Hits++;
}

void
count_hit_made(int dam)
{
    wear_and_tear(dam);
    Hits++;
    Inflicted += dam;
    /* assuming that avg(dam) >> 1, protect Inflicted (& Hits) from overflow */
    if (Inflicted > SAFE_MAX) {
	Inflicted >>= 1;
	Hits >>= 1;
    }
}

/* old stuff - called from living.c */
#if 0
int
query_wear()
{
    /* place durability code here? */
    return (27*misses + 8*hits)/18;
}
#endif

mixed
locker_arg(int mix)
{
    if (mix) {
#if 1
	mixed *al;
	al = ::locker_arg(mix);
	return order_alist(
	al[0]+({ "Class", "ClassLoss", "Type", "Durability", "Fragility",
	         "Reparable", "Wear", "Broken", "Hits", "Inflicted", }),
        al[1]+({ Class, ClassLoss, Type, Durability, Fragility,
	         Reparable, Wear, Broken, Hits, Inflicted, })
			   );
#else
      return ({ ({ Class, ClassLoss, Type, Durability, Fragility, Reparable,
	           Wear, Broken, Hits, Inflicted, }),
	           ::locker_arg(mix), });
#endif
    }

    return Class +" "+ ClassLoss +" "+ Type +" "+ Durability +" "+
           Fragility +" "+ Reparable +" "+
           Wear +" "+ Broken +" "+ Hits +" "+ Inflicted +" "+
           ::locker_arg(mix);
}

void
locker_init(mixed arg)
{
    mixed b;
    
    if (pointerp(arg)) {
	if (sizeof(arg[0]) == sizeof(arg[1])) {
	    b = arg = order_alist(arg);
	    ClassLoss = assoc("ClassLoss", arg);
	    Reparable = assoc("Reparable", arg, 1);
	    Wear = assoc("Wear", arg);
	    Broken = assoc("Broken", arg);
	    /* the remaining vars are constants (?) */
	    Class = assoc("Class", arg);
	    Type = assoc("Type", arg, "blunt");
	    Durability = assoc("Durability", arg, 5000);
	    Fragility = assoc("Fragility", arg, 3);
	    Hits = assoc("Hits", arg);
	    Inflicted = assoc("Inflicted", arg);
	}
	else {
	mixed a;
	a = arg[0]; b = arg[1];
	Class = a[0]; ClassLoss = a[1]; Type = a[2];
	Durability = a[3]; Fragility = a[4]; Reparable = a[5];
	Wear = a[6]; Broken = a[7];
	Hits = a[8]; Inflicted = a[9];
	}
    }
    else if (stringp(arg)) {
	int a0, a1, a3, a4, a5, a6, a7, a8, a9;
	string a2;

	if (sscanf(arg, "%d %d %s %d %d %d %d %d %d %d %s",
		   a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, b) >= 10) {
	    Class = a0; ClassLoss = a1; Type = a2;
	    Durability = a3; Fragility = a4; Reparable = a5;
	    Wear = a6; Broken = a7;
	    Hits = a8; Inflicted = a9;
	}
    }
    ::locker_init(b);
}

void
set_message_hit(string *arr)
{
    if (pointerp(arr) && sizeof(arr) == 14) {
	HitMsgs = arr;
    }
}

string *
query_message_hit(int dam)
{
    if (!HitMsgs) return 0;
    
    switch (dam) {
    case 20..29:
	return ({ HitMsgs[3], HitMsgs[2]});
    case 10..19:
	return ({ HitMsgs[5], HitMsgs[4]});
    case  9.. 5:
	return ({ HitMsgs[7], HitMsgs[6]});
    case  3.. 4:
	return ({ HitMsgs[9], HitMsgs[8]});
    case      2:
	return ({ HitMsgs[11], HitMsgs[10]});
    default:
	if (dam > 0) return ({ HitMsgs[1], HitMsgs[0]});
	/* fall-through to lowest possible for negative dam */
    case      1:
	return ({ HitMsgs[13], HitMsgs[12]});
    }
}

#include "weapverb.c"
