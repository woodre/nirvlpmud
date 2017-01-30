/*
 * SUMMON spell for the Shardak guild
 * by Drag and Bal
 */
#pragma strict_types
#include "../std.h"
#include "../def.h"
#include "../tasks.h"
#include "../macros.h"
inherit CMD;

#define COST 100

status
SummonDragon()
{
    object dragon;
    string nom;

    needrank(5);
    needtask(DRAGON_TASK);
    if (environment(this_player())->realm()) {
	write("Anti-magic prevents your summoning at this place.\n");
	return 1;
    }
    if ((dragon = (object) previous_object()->Dragon())) {
	if (present(dragon, environment(this_player()))) {
	    write("You already have a dragon.\n");
	    return 1;
	}
	if (dragon->query_busy()) {
	    write("Your dragon is busy at the moment.\n");
	    return 1;
	}
	tell_room(environment(dragon), "The dragon takes off into the sky.\n");
	move_object(dragon, environment(this_player()));

	write("Your dragon swoops down from the sky.\n");
	say(capname + "'s dragon swoops down from the sky.\n");
	return 1;
    }

    needmana(COST);
    dragon = clone_object(OBJDIR + "pet");
    nom = (string) previous_object()->DragonName();
    dragon->set_owner(this_player(), nom);
    previous_object()->Dragon(dragon);
    this_player()->add_spell_point(-COST);

    write("\
You summon the spirits of past warriors and they form into a dragon.\n");
    say(capname + " forms a dragon from the spirits of past warriors.\n",
	this_player());
    if (nom) {
	write("Your dragon bears the name " + dragon->query_name() + ".\n");
	say("The dragon bears the name " + dragon->query_name() + ".\n");
    }
    move_object(dragon, environment(this_player()));
    return 1;
}

status
SummonSpinal()
{
    object bones;
    int lvl;

    needrank(7);
    needtask(CHILD_TASK);

    if (!(bones = present("pile of bones", environment(this_player())))) {
	this_player()->add_spell_point(-10);
	write("There are no bones for Spinal to take residence in.\nYour spell fails.\n");
	return 1;
    }
    if (living(bones)) {        /* sounds silly, doesn't it? */
	write("The bones are already occupied by another presence.\n");
	return 1;
    }
    lvl = (int) bones->query_value();
    if (lvl < 1) lvl = 1;
    else if (lvl > 20) lvl = 20 + random(lvl - 20);
    needmana(5*lvl);

    write("\
Speaking the magic words you invite Spinal to take residence in\n\
the pile of bones. Slowly they fit together again and come alive.\n");
    say(this_player()->query_name() + "\
 makes some arcane gestures over the pile of bones. As " +
this_player()->query_pronoun() + "\n\
mutters some incomprehensible words, the bones start to rattle.\n");

    this_player()->add_spell_point(-5*lvl);
    call_out("AwakeSpinal", 2, this_player());
    return 1;
}

void
AwakeSpinal(object summoner)
{
    object dead, bones;
    int lvl;

    if (!summoner) return;
    
    /* 
     * since 3.1.2-DR does not support more than 1 extra arg for
     * call_outs, I have to duplicate some code. Argh! :-)
     */
    bones = present("pile of bones", environment(summoner));
    if (!bones || !present(bones, environment(summoner))) {
	tell_object(summoner, "The bones are gone!\n");
	return;
    }

    lvl = (int) bones->query_value();
    if (lvl < 1) lvl = 1;
    else if (lvl > 20) lvl = 20 + random(lvl - 20);

    dead = clone_object(OBJDIR + "skeleton");
    dead->set_owner(summoner);
    dead->set_name("Spinal");
    dead->set_short("Spinal, the Skeleton Warrior");
    dead->set_long("\
The spirits of Spinal have taken residence in this frail set of pale\n\
bones to bring death to living creatures. Spinal staggers to a halt\n\
and turns its dreadful grin towards you. Two tiny green dots of light\n\
sparkle in the black eye sockets.\n");
    dead->set_level(lvl);
    dead->set_ep(0);
    dead->set_al(-350);         /* black knight range */
    dead->set_wc(3);            /* bare handed */
    dead->set_ac(0);
    dead->set_hp(lvl*5 - random(lvl));

    tell_object(summoner, "Spinal rises from the ground to serve you.\n");
    say("Spinal, the Skeleton Warrior rises from the ground.\n", summoner);
    destruct(bones);
    move_object(dead, environment(summoner));
}

status
SummonShardak()
{
    string loc;
    object fiend, enemy;
    
    loc = file_name(environment(this_player()));
    if (PATH != loc[0..strlen(PATH) - 1]
    ||  (loc == PATH + "cave") || (loc == PATH + "pit")) {
	write("Nothing happens.\n");
	return 1;
    }
    needmana(umsp >> 1);
    (PATH + "shardak")->load();
    fiend = find_object(PATH + "shardak");
    if (!fiend || fiend->query_ghost()) {
	write("Shardak was banished from the realm of the living. You cannot summon him.\n");
	return 1;
    }
    enemy = (object) this_player()->query_attack();
    if (!enemy || !interactive(enemy) || servant(enemy)) {
	write("Shardak sends a message to your mind: Handle it yourself.\n");
	return 1;
    }
    if (fiend->query_attack()) {
	write("Shardak sends a message to your mind: I am already engaged.\n");
	return 1;
    }

    if (!present(fiend, environment(this_player())))
      fiend->move_player("X#" + loc);
    fiend->attack_object(enemy);
    this_player()->add_spell_point(umsp >> 1);
    return 1;
}

status
main(string arg)
{
    if (!arg)
      return (notify_fail("Summon what?\n"), 0);
    if (!environment(this_player()))
      return (notify_fail("You are nowhere.\n"), 0);

    switch (lower_case(arg)) {
    case "dragon":
	return SummonDragon();
    case "spinal":
	return SummonSpinal();
    case "shardak":
	return SummonShardak();
    default:
	notify_fail("Summon what?\n");
	return 0;
    }
}
