#include "std.h"
int door_is_open, door_is_locked;
object guard;

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
    if (!guard || !living(guard)) {
	object key, weapon;
        guard = clone_object("obj/monster");
        call_other(guard, "set_name", "guardronian");
     /* verte */
        guard->set_wc(14);
        guard->set_ac(8);
      /* end verte */
	call_other(guard, "set_level", 11);
	call_other(guard, "set_hp", 200);
	call_other(guard, "set_al", 100);
        call_other(guard, "set_short", "Guardronian");
        call_other(guard, "set_long",
"A rusted, but operational droid.  It still looks sturdy and tough.\n");
	move_object(guard, this_object());
	weapon = clone_object("obj/weapon");
         call_other(weapon, "set_name", "laser rifle");
        call_other(weapon, "set_short", "Laser Rifle");
	call_other(weapon, "set_long",
"An outstanding rifle-sleek and powerful. Used only by Guardronians.\n");
	call_other(weapon, "set_class", 15);
	call_other(weapon, "set_value",700);
	call_other(weapon, "set_weight", 3);
	transfer(weapon, guard);
        call_other(guard, "init_command", "wield rifle");
	key = clone_object("obj/treasure");
	call_other(key, "set_id", "key");
        call_other(key, "set_alias", "neon card");
        call_other(key, "set_short", "neon card");
        call_other(key, "set_long",
"Looks like a bank vault access card.\n");
	call_other(key, "set_value", 10);
	call_other(key, "set_weight", 1);
	transfer(key, guard);
    }
    door_is_open = 0; door_is_locked = 1;
}
	
#undef EXTRA_LONG
#define EXTRA_LONG\
    if (str == "counter") {\
	write("There is a sign  in the counter that says\n" +\
	    "CLOSED FOR RECONSTRUCTION\n");\
	return;\
    }\
    if (str == "door") {\
	if (door_is_open) {\
	    write("The door is open.\n");\
	    return;\
	}\
	write("The door is closed.\n");\
	return;\
    }

#undef EXTRA_INIT
#define EXTRA_INIT\
    add_action("open","open");\
    add_action("unlock","unlock");\
    add_action("east","east");

ONE_EXIT("players/cyrex/office","north",
         "The EDF bank",
         "You are in the bank which has long been abandoned.  However, there\n"+
         "is still a operational Guardronian unit here.  There might still be\n"+
         "something valuable left.  To the east is a low counter which is\n"+
         "covered with heavy iron bars.  On the wall beside the counter, a\n"+
         "door leads further east\n", 1)

id(str) {
    return str == "door" || str == "counter";
}

open(str) {
    if (str && str != "door")
	return 0;
    if (door_is_open)
	return 0;
    if (door_is_locked) {
	write("The door is locked.\n");
	return 1;
    }
    door_is_open = 1;
    write("Ok.\n");
    say(call_other(this_player(), "query_name") + " opened the door.\n");
    return 1;
}

unlock(str) {
    if (str && str != "door")
	return 0;
    if (door_is_open || !door_is_locked)
	return 0;
    if (!present("neon card", this_player())) {
        if (present("card", this_player()))
            write("You don't have the right card.\n");
	else
            write("You need an access card.\n");
	return 1;
    }
    door_is_locked = 0;
    write("ok.\n");
    say(call_other(this_player(), "query_name") + " unlocked the door.\n");
    return 1;
}

east() {
    if (!door_is_open) {
	write("The door is closed.\n");
	return 1;
    }
    if (guard && present(guard, this_object())) {
        write("The Guardronian zaps you!\n\n");
        write("You are sent flying across the room\n");
        write("You regain consciousness after a short while.\n");
	return 1;
   }
    call_other(this_player(), "move_player", "east#players/cyrex/vaultroom");
    return 1;
}

query_door() {
    return !door_is_open;
}

open_door_inside() {
    door_is_locked = 0;
    door_is_open = 1;
}

query_drop_castle() {
    return 1;
}
