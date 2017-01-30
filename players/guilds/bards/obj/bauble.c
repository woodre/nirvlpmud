#define tp this_player()->query_name()
inherit "obj/treasure";

reset(arg)
{
	if (arg)
		return;
	set_id("bauble");
	set_short("A small crimson bauble");
	set_long("A small bauble, glowing with a soft crimson light.\n");
        set_weight(1);
	set_value(0);
}

init()
{
	add_action("peg", "peg");
}

peg(str)
{
	object ob;

	if (!str) {
		write("Who do you want to peg?\n");
		return 1;
	}
	ob = present(str, environment(this_player()));
	if (!ob) {
		write("There is no " + str + " here to peg.\n");
		return 1;
	}
	if (this_player()->query_guild_name() == "bard"
		|| this_player()->query_name() == "saber") {
		write("You bounce a small crimson bauble off of " +
			  capitalize(str) + "'s head.\n");
		say(tp + " bounces a small crimson bauble off of " +
			capitalize(str) + "'s head.\n");
		tell_object(ob, "Ouch!\n");
		move_object(this_object(), environment(this_player()));
		return 1;
	}
}
