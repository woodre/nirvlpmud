#define tp this_player()->query_name()
blah!

inherit "obj/treasure";

reset(arg)
{
	if (arg)
		return;
	set_id("marker");
	set_short("A grave marker");
	set_long("The grave marker of a nameless creature.\n");
	set_weight(100);
	set_value(0);
   call_out("destroy_this", 1800);
}

destroy_this(){
 destruct(this_object());
 return 1;
 }

init()
{
	add_action("lay_flowers", "lay");
}

lay_flowers(str)
{
	if (str == "flowers") {
		write
			("You lay flowers down upon the grave of the unknown creature.\n"
			 + "Your soul feels lighter.\n");
		say(tp + " lays flowers at the grave of the unknown creature.\n");
		return 1;
	}
}

get()
{
	return 0;
}
