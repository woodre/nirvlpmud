#define tp this_player()->query_name()
inherit "obj/treasure";

reset(arg)
{
	if (arg)
		return;
	set_id("instrument");
	set_short();
	set_long("");
	set_weight(0);
	set_value(0);
}

drop()
{
	return 1;
}
