/* secret_police/interrogation_room.c */

#include "std.h"
#if 0
#include "../../../obj/door.h"
#else
#include "/obj/door.h"
#endif

object obj_1, obj_2;	/* Used by the MAKE_DOORS macro */
object spm, sps;

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);

extra_reset(arg) {
    object obj, key;

    if(!arg) {
	/* First reset */

#if 0 / * Rumplemintz */
	MAKE_DOORS("players/padrone/secret_police/interrogation_room", "west", "players/padrone/secret_police/cell", "east", "cell", "celldoor", "This is a thick and solid door with iron hinges.\n", 1, 1, 1)
#else
    obj_1 = clone_object("/obj/door");
    obj_1->set_dir("west");
    obj_1->set_door_room("/players/padrone/secret_police/interrogation_room");
    obj_1->set_type("cell");
    obj_1->set_code("celldoor");
    obj_1->set_door_long("This is a thick and solid door with iron hinges.\n");
    obj_1->set_closed(1);
    obj_1->set_locked(1);
    obj_1->set_can_lock(1);

    obj_2 = clone_object("/obj/door");
    obj_2->set_dir("east");
    obj_2->set_door_room("/players/padrone/secret_police/cell");
    obj_2->set_type("cell");
    obj_2->set_code("cellroom");
    obj_2->set_door_long("This is a thick and solid door with iron hinges.\n");
    obj_1->set_door(obj_2);
    obj_2->set_door(obj_1);
    move_object(obj_1, this_object());
    move_object(obj_2, "/players/padrone/secret_police/cell");
    obj_1->set_both_status();
#endif
    }
    else {
	obj_1->set_closed(1);
	obj_1->set_locked(1);
	obj_1->set_both_status();
    }

    if (!sps) {
#if 0 /* Rumplemintz */
	sps = clone_object("obj/monster_lars");
	sps->set_name("police sergeant");
	sps->set_alias("sergeant");
	sps->set_short("A police sergeant from the Secret Police");
	sps->set_long("This is a Secret Police sergeant.\n" +
		      "He looks big and ugly and brutal.\n");
	sps->set_level(5);
	sps->set_hp(200);
	sps->set_al(50);
	sps->set_male();
	sps->set_spell_mess1("The secret police sergeant kicks his opponent very hard.");
	sps->set_spell_mess2("The secret police sergeant kicks you very hard. You are hurt!");
	sps->set_chance(20);
	sps->set_spell_dam(10);
	sps->set_aggressive(1);

        move_object(sps, this_object());

	obj = clone_object("players/padrone/secret_police/membership");
	move_object(obj, sps);
	obj->set_name("sergeant");

	obj = clone_object("obj/weapon");
        obj->set_name("short sword");
        obj->set_alias("shortsword");
        obj->set_alt_name("sword");
        obj->set_class(15);
        obj->set_value(700);
        obj->set_weight(2);
        obj->set_short("A short sword");
        move_object(obj, sps);
	sps->init_command("wield short sword");

	MAKE_KEY(key, "cell", "celldoor")
        move_object(key, sps);
#else
    sps = clone_object("/players/padrone/secret_police/npc/sergeant");
    move_object(sps, this_object());
#endif

    }

    if (!spm) {
#if 0 /* Rumplemintz */
	spm = clone_object("obj/monster_lars");
	spm->set_name("policeman");
	spm->set_alias("secret policeman");
	spm->set_short("A policeman from the Secret Police");
	spm->set_long("This is a policeman from the Secret Police.\n" +
		       "What can he be doing in this shop?\n");
	spm->set_level(1);
	spm->set_al(60);
	spm->set_male();
	spm->set_spell_mess1("The secret policeman kicks his opponent very hard.");
	spm->set_spell_mess2("The secret policeman kicks you very hard. You are hurt!");
	spm->set_chance(10);
	spm->set_spell_dam(10);
	spm->set_aggressive(1);

        move_object(spm, this_object());

	obj = clone_object("players/padrone/secret_police/membership");
	move_object(obj, spm);
	obj->set_name("policeman");

	obj = clone_object("obj/weapon");
        obj->set_name("dagger");
        obj->set_class(6);
        obj->set_value(10);
        obj->set_weight(1);
        obj->set_short("A dagger");
        move_object(obj, spm);
	spm->init_command("wield dagger");
#else
    spm = clone_object("/players/padrone/secret_police/policeman");
    spm->setup_mob(1);
    move_object(spm, this_object());
#endif
    }
} /* extra_reset */

TWO_EXIT("players/padrone/secret_police/cell", "west",
	 "players/padrone/secret_police/hall", "east",
	 "The Secret Police interrogation room",
	 "You are in the Secret Police interrogation room,\n" +
	 "a small ugly room without any windows.\n", 1)

