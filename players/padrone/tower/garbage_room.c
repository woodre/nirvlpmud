/* This room contains parodies of some well-known monsters and objects */

#include "std.h"
#include "../config.h"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

object dragon, bralrog, demoon, sirpit, creature, knight, vumpire;
object boomsgiver, guttripper, excalibor;
object amulet1, amulet2;  /* Rumplemintz */

#if 0 /* not needed */
nerd_monster(name, alias, short_desc, long_desc) {
    object temp;

    temp = clone_object("obj/monster_lars");
    temp->set_name(name);
    temp->set_alias(alias);
    temp->set_level(1);
    temp->set_hp(30);
    temp->set_wc(2);
    temp->set_al(0);
    temp->set_short(short_desc);
    temp->set_long(long_desc);
    temp->set_aggressive(0);
    temp->set_spell_mess1("The " + name + " says: Help! Help!");
    temp->set_spell_mess2("The " + name + " says: Help! Help!");
    temp->set_chance(30);
    move_object(temp, this_object());
    return temp;
} /* nerd_monster */

nerd_weapon(name, alias, short_desc, long_desc) {
    object temp;

    temp = clone_object("obj/weapon");
    temp->set_name(name);
    temp->set_alias(alias);
    temp->set_short(short_desc);
    temp->set_long(long_desc);
    temp->set_class(2);
    temp->set_value(20);
    temp->set_weight(2);
    return temp;
} /* nerd_weapon */

nerd_treasure(name, alias, short_desc, long_desc) {
    object temp;

    temp = clone_object("obj/treasure");
    temp->set_id(name);
    temp->set_alias(alias);
    temp->set_short(short_desc);
    temp->set_long(long_desc);
    temp->set_value(10);
    temp->set_weight(1);
    move_object(temp, this_object());
    return temp;
} /* nerd_treasure */
#endif

extra_reset() {
    object junk_cmd;

    if (!dragon)
#if 0 /* Rumplemintz */
        dragon = nerd_monster("clesetial dragon", "dragon", "Palading the clesetial dragon",
			      "This monster looks almost, but not quite, like a celestial dragon.\n");
#else
  {
    dragon = clone_object("/players/padrone/tower/npc/garbage_mon");
    dragon->set_type("dragon");
    move_object(dragon, this_object());
  }
#endif
    if (!bralrog)
#if 0 /* Rumplemintz */
        bralrog = nerd_monster("bralrog", "demon", "A bralrog",
			      "This monster looks almost, but not quite, like a balrog.\n");
#else
  {
    bralrog = clone_object("/players/padrone/tower/npc/garbage_mon");
    bralrog->set_type("bralrog");
    move_object(bralrog, this_object());
  }
#endif

    if (!demoon)
#if 0 /* Rumplemintz */
	demoon = nerd_monster("demoon", "demon", "A summoned demoon is here",
			     "This monster looks almost, but not quite, like a demon.\n");
#else
  {
    demoon = clone_object("/players/padrone/tower/npc/garbage_mon");
    demoon->set_type("demoon");
    move_object(demoon, this_object());
  }
#endif

    if (!sirpit) {
#if 0 /* Rumplemintz */
	sirpit = nerd_monster("evil sirpit", "sirpit", "An evil sirpit",
			      "This monster looks almost, but not quite, like an evil spirit.\n");
	boomsgiver = nerd_weapon("boomsgiver", "sword", "Boomsgiver",
				 "This is not a very powerful sword. You feel no magic aura surrounding it.\n" +
				 "There is nothing written on it.\n");
#else
    sirpit = clone_object("/players/padrone/tower/npc/garbage_mon");
    sirpit->set_type("sirpit");
    boomsgiver = clone_object("/players/padrone/tower/npc/obj/garbage_wep");
    boomsgiver->set_type("boomsgiver");
    move_object(sirpit, this_object());
#endif
	move_object(boomsgiver, sirpit);
    }

    if (!creature) {
#if 0 /* Rumplemintz */
	creature = nerd_monster("laughsome creature", "creature", "A laughsome creature",
				"This monster looks almost, but not quite, like a loathsome creature.\n");
	guttripper = nerd_weapon("guttripper", "Guttripper", "Guttripper",
				"You can only guess what strange deeds this nice tool was used for.\n" +
				"It should serve very badly as a weapon though.\n");
#else
    creature = clone_object("/players/padrone/tower/npc/garbage_mon");
    creature->set_type("creature");
    guttripper = clone_object("/players/padrone/tower/npc/obj/garbage_wep");
    guttripper->set_type("guttripper");
    move_object(creature, this_object());
#endif
	move_object(guttripper, creature);
	call_other(creature,"init_command", "wield guttripper");
    }

    if (!knight) {
#if 0 /* Rumplemintz */
	knight = nerd_monster("block knight", "knight", "A block knight",
			      "This monster looks almost, but not quite, like a black knight.\n");
	excalibor = nerd_weapon("excalibor", "sword", "Excalibor",
				"How strange, to make a sword of rubber!\n");
#else
    knight = clone_object("/players/padrone/tower/npc/garbage_mon");
    knight->set_type("knight");
    excalibor = clone_object("/players/padrone/tower/npc/obj/garbage_wep");
    excalibor->set_type("excalibor");
    move_object(knight, this_object());
#endif
	move_object(excalibor, knight);
	call_other(knight,"init_command", "wield excalibor");
    }

    if (!vumpire)
#if 0 /* Rumplemintz */
	vumpire = nerd_monster("vumpire", "vumpire", "A vumpire",
			       "This monster looks almost, but not quite, like a vampire.\n");
#else
  {
    vumpire = clone_object("/players/padrone/tower/npc/garbage_mon");
    vumpire->set_type("vumpire");
    move_object(vumpire, this_object());
  }
#endif

#ifndef GENESIS
    /* For some reason, Lars didn't like my defective emote command. Pout. */
    if (!present("defective force command", this_object())) {
	junk_cmd = clone_object("players/padrone/obj/def_force");
	move_object(junk_cmd, this_object());
    }
    if (!present("defective emote command", this_object())) {
	junk_cmd = clone_object("players/padrone/obj/def_emote");
	move_object(junk_cmd, this_object());
    }
#endif

    if (!present("amulet", this_object())) {
#if 0 /* Rumplemintz */
	nerd_treasure("small non-magical amulet", "amulet",
		      "A small non-magical amulet",
		      "A small non-magical amulet.\n");
	nerd_treasure("large non-magical amulet", "amulet",
		      "A large non-magical amulet",
		      "A large non-magical amulet.\n");
#else
    amulet1 = clone_object("/players/padrone/tower/npc/obj/garbage_obj");
    amulet1->set_type("small non-magical amulet");
    move_object(amulet1, this_object());
    amulet2 = clone_object("/players/padrone/tower/npc/obj/garbage_obj");
    amulet2->set_type("large non-magical amulet");
    move_object(amulet2, this_object());
#endif
    }

} /* extra_reset */


ONE_EXIT("players/padrone/tower/lab", "west",
	 "Garbage room",
	 "You are standing in a small, windowless room.\n" +
	 "This is the Wizard's garbage room, where he hides\n" +
	 "the results of his failed experiments.\n", 1)

