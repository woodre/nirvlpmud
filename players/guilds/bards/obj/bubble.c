#define tp this_player()->query_name()
inherit "obj/treasure";

reset(arg)
{
	if (arg)
		return;
	set_id("bubble");
	set_short("A luminous blue bubble");
	set_long("A small, luminous blue bubble.\n" +
			 "It is glowing with the intensity of a torch.\n");
        set_weight(1);
	set_value(0);
	set_light(1);
}
