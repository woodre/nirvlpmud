inherit "obj/weapon";

int missiles;

void
reset(int arg) {
    ::reset(arg);
    if (arg) return;
    missiles = 5;
    set_name("launcher");
    set_short("Missile launcher");
    set_long(
"This is a huge weapon that holds missiles that you can 'launch'.\n" +
"The missiles look like they could do a lot of damage but might hurt\n"+
"a little just from the impact of launching one.  It feels extremly\n"+
"heavy.  There is room for 5 missiles in the chamber.\n");
    set_class(15);
    set_value(2000);
    set_weight(8);
    set_save_flag();
}

void
init() {
    ::init();
    add_action("cmd_launch","launch");
}

status
cmd_launch(string s) {
    object attacker;
    
    if (this_object() != (object) this_player()->query_weapon()) {
	write("You must be wielding the launcher to launch a missile.\n");
	return 1;
    }
    if (!(attacker = (object) this_player()->query_attack())) {
	write("You are not attacking anybody!\n");
	return 1;
    }
    missiles--;
    write("You fire a missile at " + attacker->query_name() +
	".\nThere are " + missiles + " left.\n");
    say(this_player()->query_name() + " fires a missile at " +
	attacker->query_name() + ".\n");
    tell_object(attacker, "You are hit by a missile!\n");

    attacker->hit_player(20);
    this_player()->heal_self(-10);
    if (missiles < 1) {
	write("The last missile causes the launcher to explode!\n");
	if (this_player()) this_player()->stop_wielding();
	destruct(this_object());
    }
    return 1;
}
