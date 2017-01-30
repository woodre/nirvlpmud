/*
    Changelog:
    Wizardchild 7/23 (1995)
	heart_beat replaced with repeating call_out
    Balowski 1996-03-25
	* no call_out in root object, only if wielded by player
	  (that's a couple of call_outs saved, wizboy :-7 )
	* Removed the cloning back and forth of swordinvis.c
*/
#include <ansi.h>
inherit "obj/weapon";

void
reset(int arg) {
    if (arg) return;
    ::reset(arg);
    set_name("katana");
    SetMultipleIds(({"ninja katana"}));
    set_alt_name("sword");
   set_short(RED+"Ancient ninja katana"+NORM);
    set_long(
"You can feel the power of the ancients as you hold this sword in\n" +
"your hand.  As you swing it back and forth it seems to fill your\n" +
"soul with evil.  Only death can break the bond of evil.  It is so\n" +
"powerful you can type 'weapinvis' to make it invisible and weapvis\n" +
"to make it turn visible again.\n");
    set_class(18);
    set_weight(2);
    set_value(5000);
    set_hit_func(this_object());
    set_wield_func(this_object());
}

query_wear() { int wear; wear = hits/100; return wear; }

clean_up() { return 0; }

mixed
wield(mixed x) {
    if (objectp(x)) {
	remove_call_out("fake_beat");
	call_out("fake_beat", random(990));
	return 1;
    }
    else return ::wield(x);
}

void
fake_beat() {
    if (environment() && environment()->is_player()) {
	tell_object(environment(),
		HIR+"Your Katana vibrates in your hand as it looks for blood.\n"+NORM);
	say(environment()->query_name() +
		"'s Katana vibrates lusting for more blood.\n", environment());
	call_out("fake_beat", random(990));
    }
}

mixed
weapon_hit(object attacker) {
    if (random (100) < 35) {
	write(HIR+"Your sword feeds on the blood of your foe.\n"+NORM);
	say(this_player()->query_name() +
	    "'s sword feeds on the blood of its foe.\n");
	return random(5);
   }
}

init() {
    ::init();
    add_action("weapinvis", "weapinvis");
    add_action("weapvis", "weapvis");
}

weapvis() {
    if (query_info() != "invisible") return 0;
    set_short(RED+"Ancient ninja katana"+NORM);
    set_long(
"You can feel the power of the ancients as you hold this sword in\n" +
"your hand.  As you swing it back and forth it seems to fill your\n" +
"soul with evil.  Only death can break the bond of evil.  It is so\n" +
"powerful you can type 'weapinvis' to make it invisible and weapvis\n" +
"to make it turn visible again.\n");
    set_info(0);
    write("The katana turns visible again.\n");
    return 1;
}

weapinvis() {
    if (query_info() == "invisible") return 0;
    set_short(0);
    set_long("This is your invisible Katana.  Type 'weapvis' to make it reappear.\n");
    set_info("invisible");
    write("The sword begins to turn a bright red and then fades from view...\n");
    return 1;
}
