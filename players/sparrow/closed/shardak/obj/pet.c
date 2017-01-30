/*
 * A familiar for Shardak's minion
 * Original by Dragnar, tampered with by Balowski
 */

#include "/players/balowski/lib.h"
#include "../def.h"
#include "/players/vertebraker/ansi.h"
#include "../macros.h"
#define capowner (string) Owner->query_name()
#define Room(m) tell_room(environment(), m)
#define BRING_RANK 8
#define BRING_COST 50
#define REMEMBER_COST 9
#define RETURN_COST 23
#define ROOM_VOID "/room/void"

inherit "/obj/monster";

static status following,
		    Busy;           /* Busy bringing or transporting */
static int      old_hp;         /* saved hps of owner (for shielding) */
int casted;
static object   bringer,        /* person being fetched */
		    Owner;          /* owner of dragon */
mapping         Memory;         /* remembered rooms */
static object   Bag;            /* saddle bag */
static object   SoarAbove;      /* The room the dragon is soaring above */
string          Allow;          /* person(s) allowed to mount dragon */
static status   stalking;

status
ShardakDragon()
{
    return 1;
}

mixed
Casted(mixed x)
{
  if(x)
    casted=1;
  else return casted;
}

mixed
set_follow(status x)
{
    /*
     * since hb is turned on again when dragon moves to
     * owner (happens in init), the hbflag only saves a little cpu
     */
    if (following = x)
	set_heart_beat(1);
    else
	set_heart_beat(0);
}

void
set_owner(object o, string nom)
{
    if (objectp(o)) {
	Owner = o;
	if (!nom)
	    nom = capitalize((string) o->query_real_name() + "'s dragon");
	else
	    set_short(capitalize(nom) + " the "+BOLD+BLK+"Black Dragon" + NORM + "");
	set_name(lower_case(nom));
    }
}

status
mountable(object who)
{
    return (!Busy && ((string) who->query_guild_name() == GUILDNAME ||
		      (string) who->query_real_name() == Allow));
}

void
MountedBy(object who)
{
    if (who == Owner) {
	write("You feel as one with the spirits as you climb upon the Dragon.\n");
	say(who->query_name() + " climbs upon the back of " +
	    who->query_possessive() + " dragon.\n", who);
    }
    else {
	write("You mount the dragon.\n");
	say(who->query_name() + " climbs upon the back of " + query_name() + ".\n",
	    who);
    }
}

object query_owner() { return Owner;}
status query_busy() { return Busy;}
status is_pet() { return 1;}    /* Nirvana standard. This obj is a pet */
string realm() { return "NT";}  /* Nirvana standard. No teleport to here */

void
remove_object(object by)
{
    if (Bag) destruct(Bag);
    destruct(this_object());
}

status
CheckBusy()
{
    if (Busy)
	write("The spirits within the dragon hiss: 'Not now, master.'\n");
    return Busy;
}

reset(x) { 
    if(x) return;
    if(root()) return;
    ::reset();
    msgin = "flies in";
    msgout = "flies";
    set_name("dragon");
    set_alias("black dragon");
    set_alt_name("dragon");
    set_short("A " + BOLD + BLK + "Black Dragon" + NORM);
     set_level(19);
    set_hp(430);
    max_spell = 250;
    spell_points = 63;
    set_al(-300);
    set_wc(23);
    set_ac(8);
    set_no_exp_value(1);
    set_dead_ob(this_object());
    set_can_kill(1);
    set_heal(2, 35);
    set_follow(1);
    if (!root()) {
	call_out("hb", 60);
	Memory = ([ ]);

	Bag = clone_object("/obj/container");
	Bag->set_name("bag");
	Bag->set_short("saddle bag");
	Bag->set_long("\
The saddle bag is crafted from tough brown hide and sown together\n\
with a coarse black thread.  It is fitted with an extraordinarily\n\
long leather strap.  There is a simple iron buckle on the bag.\n");
	Bag->set_weight(2);
	Bag->set_value(0);
	Bag->set_max_weight(10);
	Bag->set_can_open(1);
    }
}

status
presence()
{
    object ob;

    for (ob = first_inventory(this_object()); ob; ob = next_inventory(ob))
	if (living(ob)) break;
    return objectp(ob);
}

int
monster_died(object monster)
{
    /* move players out rather than to corpse */
    /* players are already moved to corpse at this point in time */
    object ob, next, corpse;

    if (!(corpse = present("corpse", environment()))) return 0;
    next = first_inventory(corpse);
    while (ob = next) {
	next = next_inventory(ob);
	if (ob->is_player()) {
	    tell_object(ob, "The dragon's dying twitch throw you off its back.\n");
	    move_object(ob, environment());
	}
    }
    move_object(Bag, corpse);
    return 0;   /* allow destruct */
}

void
hb()
{
    if (Owner || presence())
	call_out("hb", 300);
    else {
	say(query_name() +
	    " loses its form and the spirits descend back to the underworld.\n");
	remove_object(this_object());
    }
}

void
AdjustOwnerHps(int dhps)
{
    old_hp += dhps;
}

void
heart_beat()
{
    int damage, new_hp;
    object opp;

    casted=0;
    ::heart_beat();
    if (!Owner) return;
    if (following && !mounted && !Busy && !present(Owner, environment())) {
	tell_room(environment(), query_name() + " flies out of the room.\n");
	move_object(this_object(), environment(Owner));
        if(environment())
	tell_room(environment(), query_name() + " flies into the room.\n");
    }
    else if (!query_attack() &&
	     present(Owner, environment()) &&
	     (opp = (object) Owner->query_attack()) &&
             !opp->is_player() &&
	     present(opp, environment()))
    {
	/*
	 * The dragon takes some of the damage dealt to the owner player.
	 * Under special circumstances, the code won't work as intended
	 * (if old_hp comes out of sync).
	 */
	new_hp = (int) Owner->query_hp();
	damage = (old_hp - new_hp) >> 2;
	if (damage > 0) {
	    Owner->add_hit_point(damage);
	    new_hp += damage;
	    tell_object(Owner, "Your dragon takes " + damage +
			       " pts of damage for you.\n");
	    hit_player(damage);
	}
	old_hp = new_hp;
    }
}

status
SubSharedSps(int x)
{
    int osp;    /* sps that dragon is missing - will be taken from Owner */

    if (query_sp() < x) {
        osp = (x-(int)query_sp());
	if ((int) Owner->query_sp() < osp) return 0;
        spell_points += (int)query_sp();

	Owner->add_spell_point(-osp);
    }
    else spell_points -= x;
    return 1;
}

mixed
hit(object victim)
{
    int osp;

    if (!Owner || !victim) return 0;
    switch (random(4)) {
	case 1:
	    if (!interactive(victim) && !SubSharedSps(6)) break;
	    tell_object(victim, query_name() + " rakes you with its long claws.\n\n");
	    say(query_name() + " lunges on " +
		victim->query_name() + " and claws " +
		victim->query_objective() + " into a bloody mess.\n\n",
		victim);

	    return 13;

	case 2:
	    if (!interactive(victim) && !SubSharedSps(8)) break;
	    tell_object(victim, "The fiery breath of " + query_name() + " engulf you.\n\n");
	    say(query_name() + " opens the valves to its inner furnace and exhales.\n" +
		victim->query_name() + " is engulfed in an inferno of burning vapours.\n\n",
		victim);
	    return 17;

	case 3:
	    /* freebie */
	    tell_object(victim, query_name() + " strikes you with its tail.\n\n");
	    say(query_name() + " strikes " + victim->query_name() +
		" with its spiked tail.\n\n",
		victim);
	    return 10;

	default:
	    if (!SubSharedSps(1)) return "miss";
    }
}

void
long(string str)
{
    object ob, env;
    string sh;

    if (!str) { /* when sitting on top of dragon */
	env = SoarAbove || environment();
	/* this is cheaper than moving tp to env and forcing look */
	write("From the dragon's back you see:\n");
	env->long();
	for (ob = first_inventory(env); ob; ob = next_inventory(ob))
	    if (ob != this_object() && (sh = (string) ob->short())) {
		write(sh + ".\n");
	}
	write("\n");
	return;
    }
    if (this_player() != Owner) {
	write("\
This is a huge black dragon with blood red eyes.  It has enormous\n\
wings to carry it's muscular form.  As you look into it, you can\n\
see the movement of the spirits that make up its existance.  It has\n\
a saddle bag strapped to its back.\n");
    }
    else {
	write("\
This dragon is the most powerful creature you have ever laid your\n\
eyes upon.  Its blood red eyes seem to stare right through your soul.\n\
The scales that protect its body are jet black.  If you turn your\n\
head and look at the dragon from the corner of your eye, you can\n\
catch movement of the spirits inside the huge beast.\n");
	write("[HPS: " + query_hp() + "] [FLAME: " + query_sp() + "]\n");
    }
}

init()
{
    ::init();

    if (present(this_player(), this_object())) {
	/* commands available when mounted */
	add_action("cmdSoar", "soar");
	add_action("cmdLand", "land");
	add_action("cmdDismount", "dismount");
	add_action("cmdDrop", "drop");
	if (this_player() == Owner) {
	    add_action("cmdSay", "say");
	    add_action("cmdSay"); add_xverb("'");
            mounted = 1;
	}
    }
    else {
	/* commands available when not mounted */
	add_action("cmdClimb", "climb");
	add_action("cmdMount", "mount");
	if (this_player() == Owner) {
	    mounted = 0;
            add_action("cmdFollow", "dfollow");
	    add_action("cmdRelease", "release");
	    add_action("cmdBring", "bring");
	    add_action("cmdTransport", "transport");
	    add_action("cmdFeed", "feed");
	}
    }
    if (this_player() == Owner) {
	add_action("cmdRemember", "remember");
	add_action("cmdReturn", "return");
	add_action("cmdBag", "bag");
	add_action("cmdUnbag", "unbag");
	add_action("cmdAllow", "allow");
	add_action("cmdStalk","dstalk");
    }
}

void
catch_tell(string str)
{
    if (!this_player() || !present(this_player(), this_object()))
        tell_room(this_object(), str);
}

status
cmdDrop()
{
    if (!present(this_player(), this_object()))
	return 0;

    write("The spirits in the dragon hiss: 'You can't do that while mounted, master.'\n");
    return 1;
}

status
cmdSay(string str)
{
    if (!present(this_player(), this_object()))
	return 0;

    if (!str) {
	write("Say what?\n");
	return 1;
    }
    Room(this_player()->query_name() + " says from atop " +
	this_player()->query_possessive() + " dragon: '" + str + "'\n\n");
    write("You say: " + str + "\n");
    return 1;
}

status
cmdRelease(string arg)
{
    if (arg != "dragon") {
	notify_fail("Release what?\n");
	return 0;
    }
    if (CheckBusy()) return 1;
    if (present(this_player(), this_object())) {
	write("You cannot release the spirits while riding the Dragon.\n");
	return 1;
    }
    if (first_inventory(this_object())) {
	write("The dragon is still carrying cargo.\n");
	return 1;
    }
    say("The sky turns black as " + capowner +
	" releases the spirits within the dragon.\n");
    remove_object(this_object());
    return 1;
}

status
cmdFollow(string arg)
{
    if (arg) return 0;
    set_follow(!following);     /* toggle follow state */

    if (following)
	write("The spirits in the dragon say: 'We will follow you now, master.'\n");
    else
	write("The spirits in the dragon say: 'We will no longer follow you, master.'\n");
    return 1;
}

status
cmdDismount()
{
    if (!present(this_player(), this_object())) {
	notify_fail("You are not on the Dragon.\n");
	return 0;
    }
    if (CheckBusy()) return 1;
    if (this_player() == Owner) {
	write("You feel cold enter your soul as you break the bond with the spirits.\n");
	Room(capowner + " climbs down from " +
		this_player()->query_possessive() + " dragon's back.\n");
	mounted = 0;
    }
    else
	Room(this_player()->query_name() + " climbs down from the back of " + 
		query_name() + ".\n");

    move_object(this_player(), environment());
    if (following)
	set_heart_beat(1);
    return 1;
}

status
cmdFeed(string arg)
{
    object corpse;

    if(!arg) return 0;
    if (environment(this_object())->pk_tourney()) {
        notify_fail("The Spirits in the dragon hiss: 'We can't do that here master.'\n");
        return 0;
    }
    if (present(arg, environment()) != this_object()) {
	notify_fail("Who do you wish to feed?\n");
	return 0;
    }
    if (CheckBusy()) return 1;
    if (!(corpse = present("corpse", environment()))) {
	write("The Spirits in the dragon hiss: 'There is no corpse here master.'\n");
	return 1;
    }
    say("The dragon devours a corpse at " + capowner + "'s command.\n",
	this_player());
    write("Your dragon devours " + corpse->short() + ".\n");

    heal_self(corpse->heal_value());
    destruct(corpse);
    return 1;
}

/*
 * Sub functions for 'transport'
 */
void
gototarget(object target, object thingy)
{
    move_object(this_object(), environment(target));
    say(query_name() + " swoops down from the sky.\n");

    if (!transfer(thingy, target))
	say("The spirits within the dragon transport " + thingy->short() +
	    " to " + target->query_name() + ".\n");
    else
	tell_object(Owner, "\
Your dragon sends you a mental message: 'The transport failed, master.'\n");

    call_out("backtoowner", 30);
}

void
backtoowner()
{
    say(query_name() + " jumps into the air, and flys off into the sky.\n");
    move_object(this_object(), environment(Owner));
    say(query_name() + " swoops down from the sky.\n");
    Busy = 0;
}

status
cmdTransport(string str)
{
    string          who, what;
    object          target, thingy;

    if (!str || sscanf(str, "%s %s", what, who) != 2) {
	notify_fail("\n\
The spirits within the dragon hiss: 'What do you want to fly and to\n\
who, master?'\n");
	return 0;
    }
    if (CheckBusy()) return 1;
    if (presence()) {
	write("The spirits within the dragon hiss: 'Not while we are mounted, master.'\n");
	return 1;
    }
    if (!(target = find_player(who)) || !environment(target) || inwizible(target)) {
	write("The spirits within the dragon hiss: 'We can't find " +
	      capitalize(who) + ", master.'\n");
	return 1;
    }
    /* avoid any sillyness */
    if (present(target, environment()) || present(target, this_object())) {
	say(query_name() + " snorts and breathes a ring of smoke.\n");
	write("Your dragon snorts and breathes a ring of smoke.\n");
	return 1;
    }
    if (environment(target)->realm() || environment(target)->query_lock()) {
	write("\
The spirits in the dragon hiss: 'Magik prevents us from doing so.'\n");
	return 1;
    }
    if (!(thingy = present(what, this_player()))) {
	write("The spirits within the dragon hiss: 'You do not have a " + what + ", master.'\n");
	return 1;
    }
    say(query_name() + " flies off into the sky.\n");
    Busy = 1;
    gototarget(target, thingy);
    return 1;
}

status
cmdBring(string str)
{
    needrank(BRING_RANK);
    needmana(BRING_COST);
    if (!str) {
	notify_fail("The spirits within the dragon hiss: 'Who do you wish to bring, master?'\n");
	return 0;
    }
    if (CheckBusy()) return 1;
    if (presence()) {
	write("The spirits within the dragon hiss: 'Not while we are mounted, master.'\n");
	return 1;
    }
    if (!(bringer = find_player(str)) || !environment(bringer)) {
	write("The spirits within the dragon hiss: 'We can not find " + capitalize(str) +
	      ", master.'\n");
	return 1;
    }
    /* avoid any sillyness */
    if (present(bringer, environment()) || present(bringer, this_object())) {
	write("Your dragon snorts, and breathes a ring of smoke.\n");
	return 1;
    }
    if (environment(bringer)->realm() || environment(bringer)->query_lock()) {
	write("\
The spirits in the dragon hiss: 'Magik prevents us from doing so.'\n");
	return 1;
    }

    Busy = 1;
    say(query_name() + " flies into the sky.\n");
    move_object(this_object(), environment(bringer));
    say("A huge black dragon swoops down from the sky.\n");
    tell_object(bringer, "The spirits within the dragon hiss: '" + capowner +
			 " wishes to summon you.\nType 'climb on dragon'" +
			 " if you wish for us to take you there.\n");
    call_out("bring_failure", 35);
    return 1;
}

status
cmdClimb(string str)
{
    if (!Owner || this_player() != bringer || str != "on dragon")
	return 0;

    Owner->add_spell_point(-BRING_COST);
    move_object(this_player(), this_object());
    write("You climb onto the back of " + query_name() + ".\n");
    command("glance", this_player());
    Room(this_player()->query_name() + " climbs onto the back of " + query_name() + ".\n");
    remove_call_out("bring_failure");
    call_out("deliverbringer", 2);
    return 1;
}

void
deliverbringer()
{
    tell_object(bringer, "\
You feel the powerful muscles under you as the dragon jumps,\n\
and begins to fly.\n");
    Room("The dragon flies back to its master.\n");
    move_object(this_object(), ROOM_VOID);
    call_out("flying", 4);
}

void
flying()
{
    tell_object(bringer, "\
You are flying at an incredible speed.  The wind is making your eyes\n\
water and is making you feel very unsafe.  The land below you looks\n\
so small that you cannot tell where you are going.  Suddenly, the\n\
dragon begins to slow down and begins descending.\n");
    call_out("land", 2);
}

void
land()
{
    tell_object(bringer, "The dragon spreads its wings and lands next to its master.\n");
    move_object(this_object(), environment(Owner));
    say("A large black dragon drops from the sky and lands next to its master.\n",
	bringer);
    call_out("dropoff", 3);
}

void
dropoff()
{
    tell_object(bringer, "\
Still in awe of the flight, you slide off the dragon's back.\n");
    say(bringer->query_name() + " slides from the back of " + query_name() + ".\n");
    move_object(bringer, environment());
    command("glance", bringer);
    Busy = 0;
    bringer = 0;
}

void
bring_failure()
{
    if (bringer)
	tell_object(bringer, "\
The spirits within the dragon hiss: 'You have failed to accept the summoning.'\n");

    say("The dragon jumps up, and flies off into the sky.\n");
    move_object(this_object(), environment(Owner));
    say("A huge black dragon swoops down and lands next to its master.\n");
    tell_object(Owner, "\
The spirits hiss: 'Your summoning was not responded to, master.'\n");
    Busy = 0;
    bringer = 0;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * <remember> and <return to> commands
 */
status
cmdRemember(string alias)
{
    string *ks; int i;

    if (this_player() != Owner) return 0;
    if (CheckBusy()) return 1;

    if (!alias) {
	if (i = sizeof(ks = m_indices(Memory))) {
	    write("\
The spirits in the dragon hiss: 'These are the locations we remember,\n\
master: ");
	    while (i--) {
		write(ks[i]);
		if (i == 1) write(" and ");
		else if (i) write(", ");
	    }
	    write(".'\n");
	}
	else
	    write("\
The spirits in the dragon hiss: 'You have not told us to remember, master.'\n");
	return 1;
    }

    needmana(REMEMBER_COST);
    if (!Memory[alias]
    && (sizeof(Memory) >= ((int) this_player()->query_guild_rank() - 4))) {
	write("\
The spirits in the dragon hiss: 'We cannot remember more locations, master.'\n");
	return 1;
    }
    if (environment()->realm() || !root(environment())) {
	write("\
The spirits in the dragon hiss: 'It is not possible for us to remember\n\
this location, master.'\n");
	return 1;
    }
    write("\
The spirits in the dragon hiss: 'We will remember our current location\n\
as \"" + alias + "\", master.'\n");
    Memory[alias] = file_name(environment());
    this_player()->add_spell_point(-REMEMBER_COST);
    return 1;
}

status
cmdReturn(string str)
{
    string alias, loc;

    if (!str || !sscanf(str, "to %s", alias)) {
	notify_fail("Return to where?\n");
	return 0;
    }
    if (CheckBusy()) return 1;
    needmana(RETURN_COST);
    if (environment()->realm()) {
	write("\
The spirits in the dragon hiss: 'We cannot fly away from this place, master.'\n");
	return 1;
    }
    if (!(loc = Memory[alias])) {
	write("\
The spirits in the dragon hiss: 'We do not remember such a place, master.'\n"); 
	return 1;
    }
    tell_room(this_object(), "\
You feel the powerful muscles under you as the dragon jumps,\n\
and flies back to the location remembered as \"" + alias + "\".\n");
    move_object(this_object(), loc);
    tell_room(environment(), short() + " swoops down from the sky.\n");
    long(0);

    m_delete(Memory, alias);
    this_player()->add_spell_point(-RETURN_COST);
    return 1;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * <bag> and <unbag> commands
 */
status
cmdBag(string arg)
{
    object ob;
    string sh;

    if (this_player() != Owner) return 0;
    if (!arg) {
	if (ob = first_inventory(Bag)) {
	    write("The dragon's saddle bag contains:\n");
	    while (ob) {
		if (sh = (string) ob->short()) write(sh + ".\n");
		ob = next_inventory(ob);
	    }
	}
	else write("The dragon's saddle bag is empty.\n");
	return 1;
    }
    if (!(ob = present(arg, this_player()))) {
	notify_fail("Bag what?\n");
	return 0;
    }
    switch (transfer(ob, Bag)) { 
    case 0:
	write("You stow the item in your Dragon's saddle bag.\n");
	say(Owner->query_name() + " stows something in " +
	    Owner->query_possessive() + " Dragon's saddle bag.\n",
	    Owner);
	break;
    default:
	write("You fail.\n");
    }
    return 1;
}

status
cmdUnbag(string arg)
{
    object ob, next;
    string sh;
    int hits;

    if (this_player() != Owner) return 0;
    if (!arg) return (notify_fail("Unbag what?\n"), 0);
    
    if (arg == "all") {
	next = first_inventory(Bag);
	if (!next) return (write("There is nothing in the saddle bag.\n"), 1);
    }
    else {
	next = present(arg, Bag);
	if (!next) return (notify_fail("Unbag what?\n"), 0);
    }
    
    while (ob = next) {
	next = (arg == "all") ? next_inventory(ob) : 0;
	sh = (string)ob->short() || "item";

	switch (transfer(ob, this_player())) { 
	  case 0:
	    hits++;
	    write("You fetch the " + sh + " from your Dragon's saddle bag.\n");
	    break;
	  default:
	    write("You fail to fetch the " + sh + ".\n");
	}
    }
    if (hits == 1) {
	say(Owner->query_name() + " fetches something from " +
	    Owner->query_possessive() + " Dragon's saddle bag.\n",
	    Owner);
    } else if (hits > 1) {
	say(Owner->query_name() + " fetches some things from " +
	    Owner->query_possessive() + " Dragon's saddle bag.\n",
	    Owner);
    }
    return 1;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * *
 * <soar> and <land> commands
 */
status
cmdSoar(string str)
{
    if (str || SoarAbove || this_player() != Owner)
	return 0;
    if (CheckBusy()) return 1;
    if (query_sp() < 1) {
	write("The spirits within the dragon hiss: 'We need more power, master.'\n");
	return 1;
    }
    SoarAbove = environment();
    move_object(this_object(), ROOM_VOID);

    tell_room(this_object(), "\
You feel the powerful muscles under you as the dragon takes off and\n\
ascends into the sky above.\n");
    tell_room(SoarAbove,
	      query_name() + " takes off and ascends steeply into the sky above.\n");
    call_out("evSoaring", 10);
    Busy = 1;
    return 1;
}

status
cmdLand(string str)
{
    if (str || !SoarAbove)
	return 0;
    move_object(this_object(), SoarAbove);
    tell_room(this_object(), "The dragon dives down and lands on the ground.\n");
    tell_room(SoarAbove, "A large dragon dives down from the sky and lands right next to you.\n");
    SoarAbove = 0;
    remove_call_out("evSoaring");
    Busy = 0;
    return 1;
}

void
evSoaring()
{
    spell_points -= 5;
    if (query_sp() < 1) {
	tell_room(this_object(), "The dragon begins to stall and glides down to the ground.\n");
	cmdLand(0);
    }
    else {
	if (random(2))
	    tell_room(SoarAbove, "High above a huge dragon soars.\n");
	else if (random(2))
	    tell_room(SoarAbove, "A dragon circles in the sky above you.\n");
	tell_room(this_object(), "The dragon circles..\n");
	call_out("evSoaring", 35);
    }
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * *
 * <allow %s to mount> command
 */
status
cmdAllow(string str)
{
    string name;
    object ob;

    if (!str || !sscanf(str, "%s to mount", name)) {
	notify_fail("Allow who to mount?\n");
	return 0;
    }
    if (!(ob = find_player(name)) || inwizible(ob)) {
	write("The spirits within the dragon hiss: 'We know of no such person, master.'\n");
	return 1;
    }
    Allow = (string) ob->query_real_name();
    write("The spirits within the dragon hiss: 'We will allow " +
	ob->query_objective() + " to mount us, master.'\n");
    return 1;
}

status
cmdMount(string arg)
{
    return (status) call_other(BINDIR + "mount", "main", arg);
}

add_spell_point(x) { if((spell_points += x) > max_spell) spell_points = max_spell; }

query_following() { return following; }
