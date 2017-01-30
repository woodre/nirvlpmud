/*   
    Changelog:
    Wizardchild 7/23 (1995):
	heart_beat replaced with a repeating call_out
    Balowski 1996-03-25:
	removed call_out in root object and when carried by monsters
	(2 unnecessary repeating call_outs removed from the game)
    Feldegast 7/30/2000
   Added a delay between attacks so that players could not instablick monsters
*/
inherit "obj/weapon";


int flag;

void
reset(int arg) {
    if (arg) return;
    ::reset(arg);
    set_name("reaper");
    set_short("A Reaper");
    set_long(
"As you grasp the reaper in your hands, you get a disrupting feeling\n" +
"in your soul.  The wooden handle is spattered with blood and the blade\n" +
"appears to be broken in, but very sharp.  There are some words inscribed\n" +
"on the side that read, 'This reaper enables you to stab your opponent.\n" +
"However be warned, it takes a great deal of strength to use it'.\n");
    set_class(18);
    set_weight(3);
    set_value(3000);
    set_hit_func(this_object());
    set_wield_func(this_object());
    set_save_flag();
}

mixed
weapon_hit(object attacker) {
    if (random (100) < 30) {
	write("The handle of your reaper is soaked with more blood.\n");
	say(this_player()->query_name() + "'s reaper is soaked with " +
	    this_player()->query_possessive() + " opponent's blood.\n");
	return(random(6)+3);
    }
}

void
fake_beat() {
    if (environment() && living(environment())) {
	tell_object(environment(), "The reaper's blade glows a bright red.\n");
	call_out("fake_beat", random(965));
    }
}

mixed
wield(mixed x) {
    if (objectp(x) && this_player()->is_player()) {
	/* start fake_beat if wielded by a player */
	remove_call_out("fake_beat");
	call_out("fake_beat", random(965));
	return 1;
    }
    return ::wield(x);
}

void
init() {
    ::init();
    add_action("stab","stab");
}

status
stab(string str) {
    object attacker;

    if (str) return 0;
    if (!(attacker = (object) this_player()->query_attack())) {
	write("You are not attacking anything!\n");
	return 1;
    }
    if(flag) {
      notify_fail("You cannot stab again yet.\n");
      return 0;
    }
    if (attacker->is_player()) {
	write("You cannot stab a player!\n");
	return 1;
    }
    if(!wielded_by) {
      notify_fail("You are not wielding that weapon.\n");
      return 0;
    }
    this_player()->add_hit_point(-13);
/*  CHANGED from hit_player(30) by Saber   */
    attacker->hit_player(13);
    write("You stab your attacker in the guts with the reaper!\n");
    say(this_player()->query_name() + " stabs " +
	this_player()->query_possessive() + " enemy with the reaper.\n");
    flag=1;
    call_out("unset",3+random(5));
    return 1;
}

void unset() {
  flag=0;
}
