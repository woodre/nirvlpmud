#include "std.h"
int door_is_open, door_is_locked;
object guard, key, weapon;

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
     int i;
     i = 0;
    if (!guard || !living(guard)) {
     while(i<4){
     i += 1;
        guard = clone_object("obj/monster");
        call_other(guard, "set_name", "mummy");
	call_other(guard, "set_level", 11);
	call_other(guard, "set_hp", 165);
	call_other(guard, "set_al", -150);
        call_other(guard, "set_wc", 15);
        call_other(guard, "set_ac", 9);
        call_other(guard, "set_short", "A huge mummy");
        call_other(guard, "set_long", "This mummy is guarding the\n"+
                  "secret of the crypt.\n");
     guard->set_aggressive(1);
	move_object(guard, this_object());
	weapon = clone_object("obj/weapon");
	call_other(weapon, "set_name", "shortsword");
	call_other(weapon, "set_short", "A shortsword");
	call_other(weapon, "set_alias", "sword");
	call_other(weapon, "set_long",
"It is proffesional looking short sword, used by warriors and guards");
	call_other(weapon, "set_class", 15);
	call_other(weapon, "set_value",500);
	call_other(weapon, "set_weight", 3);
	key = clone_object("obj/treasure");
	call_other(key, "set_id", "key");
	call_other(key, "set_alias", "green key");
	call_other(key, "set_short", "A green key");
	call_other(key, "set_value", 10);
	call_other(key, "set_weight", 1);
	transfer(key, guard);
    }
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

ONE_EXIT("players/deathmonger/CASTLE/pyramid/golems","west",
	 "The crypt",
         "You enter the crypt, which is a huge room with a high ceiling\n"+
         "with tombs lining the sides of the room.  Suddenly, several\n"+
         "mummies emerge from their tombs.\n",

1)
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
    if (!present("green key", this_player())) {
	if (present("key", this_player()))
	    write("You don't have the right key.\n");
	else
	    write("You need a key.\n");
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
	write("The mummy bars the way.\n");
	return 1;
   }
    call_other(this_player(), "move_player", 
      "east#players/deathmonger/CASTLE/pyramid/vault");
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
