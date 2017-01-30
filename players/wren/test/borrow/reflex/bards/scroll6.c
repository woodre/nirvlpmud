#define tp this_player()->query_name()
inherit "obj/treasure";

reset(arg)
{
	if (arg)
		return;
	set_id("scroll");
	set_short("A scroll of teleportation");
	set_long
		("A scroll to <read> which will take you to the faerie court.\n");
	set_weight(0);
	set_value(0);
}

init()
{
	add_action("read", "read");
}

read(str)
{
	if (str == "scroll") {
		say(tp + " slowly fades away.\n");
		write("You feel yourself fading away from reality.\n\n\n\n" +
			  "You are somewhere new...\n\n\n");
		move_object(this_player(),
					"/players/reflex/guilds/bards/bardrooms/faerie_q.c");
		destruct(this_object());
		return 1;
	}
}
