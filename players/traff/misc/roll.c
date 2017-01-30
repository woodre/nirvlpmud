/* Its a heal, uses stuff, heals for 15.  Player must find clues
   to get it, and may only get 1 per player per reboot. */
inherit"obj/food";
reset(arg) {
::reset(arg);
if(!arg) {
	set_name("roll");
	set_short("A hot roll");
    set_long("Fresh from the oven and golden brown on top, this hot\n"+
    "dinner roll looks delicious.\n");
    set_eater_mess("The warm bread tastes excellent!\nAhhhhhhh!\n");
    set_eating_mess(" crams down a hot roll!  It sure looked good.\n");
	set_strength(15);
	set_value(15);
}
}

is_heal() { return "stuff"; }

query_potence() { return 15; }
