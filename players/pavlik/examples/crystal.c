#include "/players/balowski/lib.h"
#include "/players/reflex/include/ansi.h"
inherit WEAPON;

void create() {
    ::create();

    set_name("sword");
    set_ids(({ "crystal sword", }));
    set_short(BOLD+BLU+"Crystal Sword"+NORM);
    set_long(
	"A gleaming sword made of pure crystal.  The edges are so sharp\n"+
	"you could split a hair, and the weight is perfectly balanced.\n"+
	"You can hardly believe this sword, it is flawless.\n"
	);
    set_value(11000);
    set_weight(4);
    set_type("sharp");
    set_class(18);
    set_durability(100000);
    set_fragility(3);
    set_reparable(3);
    set_hit_func(this_object());
    set_hands(1);
}

mixed weapon_hit(object victim) {
    object master;
    
    master = query_wielded_by();
    if ((string) victim->query_race() == "smurf") {
        tell_object(master, "You cannot harm smurfs with this sword!\n");
        return "miss";
    }

    if (random(100) < 33) {
        tell_object(master, 
	"Your sword glows!"+NORM+"\n\n"+
	""+BLU+"You cut cleanly through your foe."+NORM+"\n"+
	"You feel a surge of "+BLU+BOLD+"POWER"+NORM+"!\n"+
	"The sword returns to normal...\n"
	);
        tell_object(victim, master->query_name() +
        "'s sword begins to glow!\n"+
	"Their eyes gleam and they glow with a pale "+BOLD+BLU+"FIRE"+NORM+"!\n"+
	"The fire dies out...\n"
	);
        say(master->query_name() + 
	"'s sword begins to glow!\n"+
	"Their eyes gleam and they glow with a pale "+BOLD+BLU+"FIRE"+NORM+"!\n"+
	"The fire dies out...\n",
            victim);
        return 2;
    }
}
