#include "std_old.h"
inherit "obj/container.c";

#define TO this_object()

reset(arg)
{
	::reset(arg);
	if (arg)
		return;

	set_name("pouch");
	set_short("A bard pouch");
	set_long("A small leather pouch of beautiful detail and workmanship.\n"
			 +
			 "It has a strap so that you may wear it over your shoulder\n"
			 +
			 "or attach it to your belt.  The pouch is extremely light.\n"
			 + "Type 'help_pouch' for a list of bard pouch commands.\n");
	set_weight(1);
	set_value(150);
	set_max_weight(25);
}

init()
{
	::init();
	if (this_player()->query_guild_name() == "bard" ||
		this_player()->query_guild_name() == "paladin") {
		add_action("help_pouch", "help_pouch");
		add_action("sell", "sell");
		add_action("check", "check");
	}
}

sell(item)
{
	object ob;

	if (!item)
		return 0;
	if (item == "all") {
		object next;

		ob = first_inventory(this_player());
		while (ob) {
			next = next_inventory(ob);
			if (!ob->drop() && ob->query_value()) {
				write(ob->short() + ":\t");
				do_sell(ob);
			}
			ob = next;
		}
		write("Ok.\n");
		return 1;
	}
	ob = present(item, this_player());
	if (!ob)
		ob = present(item, this_object());
	if (!ob) {
		write("No such item (");
		write(item);
		write(") here.\n");
		return 1;
	}
	do_sell(ob);
	return 1;
}

do_sell(ob)
{
	int value, do_destroy;

	value = ob->query_value();
	if (!value) {
		write(ob->short() + " has no value.\n");
		return 1;
	}
	if (environment(ob) == this_player()) {
		int weight;

		if (call_other(ob, "drop", 0)) {
			write("I can't take it from you!\n");
			return 1;
		}
		weight = call_other(ob, "query_weight", 0);
		call_other(this_player(), "add_weight", -weight);
	}
	if (value > 6000 || value < 50)
		do_destroy = 1;
	if (value > 1000) {
		write("The bards guild only has so much money, you know...\n");
		value = 1000 + random(100);
	}
	write("You get ");
	write(value);
	write(" gold coins.\n");
	say(call_other(this_player(), "query_name", 0) + " sells " +
		call_other(ob, "short", 0) + ".\n");
	call_other(this_player(), "add_money", value);
	if (do_destroy) {
		write("This item is placed in the back store room of the shop.\n");
		destruct(ob);
		return 1;
	}
	call_other("/players/saber/food/store2.c", "store", ob);
	return 1;
}

check(obj)
{
	call_other("/players/saber/food/store2.c", "inventory", obj);
	return 1;
}

find_item_in_player(i)
{
	object ob;

	ob = first_inventory(this_player());
	while (ob) {
		if (call_other(ob, "id", i))
			return ob;
		ob = next_inventory(ob);
	}
	return 0;
}

help_pouch()
{
	write("With the bardic pouch you may:\n" +
		  "   Sell an item.\n   Check whats in the shops of Ryllian.\n\n");
	return 1;
}

query_save_flag()
{
	return 0;
}
