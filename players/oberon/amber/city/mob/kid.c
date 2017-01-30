#include <ansi.h>
inherit "/obj/monster";

int GENDER;

reset(arg) {
	::reset(arg);
	if(arg) return;
	GENDER = random(2);

	set_name("child");
	set_race("human");
	set_short("A "+((GENDER)?"Male":"Female")+" Child");
	set_long("One of Amber's many citizens.\n");
	set_gender(((GENDER)?"male":"female"));
	set_level(12);
	add_money(300+random(500));
	set_aggressive(0);
	set_al(0);
	

	wander = 1; /* whether we wander or not */
	wander_interval = 3; /* how often we move */
	wander_count = 10; /* count heartbeats until next wander */
	wander_realm = "/players/oberon/amber/city/rooms/"; /* base file path we are allowed to wander */
}

init() {
	::init();
}

heart_beat() {
	::heart_beat();
}
