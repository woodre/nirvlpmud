inherit "/room/room";
#include <ansi.h>
#include "../../defs.h"

reset(arg)
{
::reset(arg);

if(arg) return;
	set_light(1);
	short_desc = HIK+"The Rogue Bazaar"+NORM;
	long_desc = 
	"This is a rather large room with many different shelves\n"+
	"and bookcases that are loaded with items from previous\n"+
	"sales. The only source of light is coming from a tiny\n"+
	"candle on the counter.\n";
	
items =

({
	"shelves",
	"The shelves are packed with previous sales",
	"bookcases",
	"The bookcases contain old books and other previous sales",
	"light",
	"The only source of light is from a tiny candle",
	"candle",
	"The candle is burning brightly but does not burn down",
	"counter",
	"A sturdy wooden counter made of oak",
	"books",
	"The old books look very worn",
	});
	
dest_dir =
   ({
      HALLRMS+"entrance.c", "west",
   });

}

realm(){ return "NT"; }
query_no_fight(){ return 1; }

init(){
	::init();
	
	add_action("sell", "sell");
    add_action("value", "value");
    add_action("buy", "buy");
    add_action("north", "north");
    add_action("list", "list");
    add_action("ask", "ask");
    add_action("purchase", "purchase");
}

north()
{
    if(this_player()->query_level() < 30)
    {
	    write("A strong magic force stops you.\n");
	    return 1;
    }
    move_object(this_player(), HALLRMS+"storage.c");
    write("You wriggle through the force field...\n");
    command("look", this_player());
    return 1;
}

sell(item)
{
	object ob, next;
	if(!item)
	{
		return 1;
	}
	
	if(item == "all")
	{
		ob = first_inventory(this_player());
		while(ob)
		{
			next = next_inventory(ob);
			if(!ob->drop() && ob->query_value()) {
				write(ob->short()+":\t");
				do_sell(ob);
			}
			ob = next;
		}
		write("Ok.\n");
		return 1;
	}
	ob = present(item, this_player());
	if(!ob)
	ob = present(item, this_object());
	if(!ob)
	{
		write("No such item ("); write(item); write(") here.\n");
		return 1;
	}
	do_sell(ob);
	return 1;
}

do_sell(ob)
{
	int value, do_destroy;
	value = ob->query_value(1);
	if(!value) value = ob->query_value();
	if(!value)
	{
		write(ob->short()+" has no value.\n");
		return 1;
	}
	if(environment(ob) == this_player())
	{
		int weight;
		if(call_other(ob, "drop", 0))
		{
			write("I can't take it from you!\n");
			return 1;
		}
		weight = call_other(ob, "query_weight", 0);
		call_other(this_player(), "add_weight", -weight);
	}
	
	if(value > 600000)
	do_destroy = 1;
	if(ob->query_dest_flag()) do_destroy = 1;
	if(value > 1000)
	{
		write("The shop is low on money...\n");
		if(value < 1500) value = 1000;
		else value = 1000 + random(501);
	}
	write("You get "); write(value); write(" golden coins.\n");
	say(call_other(this_player(), "query_name", 0) + " sells " + call_other(ob, "short", 0) + ".\n");
	call_other(this_player(), "add_money", value);
	if(do_destroy)
	{
		write("The valuable item is hidden away.\n");
		destruct(ob);
		return 1;
	}
	call_other("/players/shinshi/closed/rogue/hall/rooms/storage", "store", ob);
	return 1;
}

value(item) {
    int value;
    string name_of_item;

    if (!item)
  return 0;
    name_of_item = present(item);
    if (!name_of_item)
      name_of_item = find_item_in_player(item);
    if (!name_of_item) {
  if (call_other(HALLRMS+"storage", "value", item))
      return 1;
  write("No such item ("); write(item); write(") here\n");
  write("or in the store.\n");
  return 1;
    }
    value = name_of_item->query_value(1);
    if(!value)
    value = call_other(name_of_item, "query_value", 0);
    if (!value) {
  write(item); write(" has no value.\n");
  return 1;
    }
    write("You would get "); write(value); write(" gold coins.\n");
    return 1;
}

find_item_in_player(i)
{
    object ob;

    ob = first_inventory(this_player());
    while(ob) {
        if (call_other(ob, "id", i))
      return ob;
  ob = next_inventory(ob);
    }
    return 0;
}

buy(item) {
    if (!item)
        return 0;
    call_other(HALLRMS+"storage", "buy", item);
    return 1;
}

list(obj) {
    call_other(HALLRMS+"storage", "inventory", obj);
    return 1;
}

ask(str)
{
	if(!str)
	{
		write("What would you like to ask Drak'Ganoth about?\n");
		return 1;
	}
	
	if(str != "about poisons")
	{
		write("You can only ask Drak'Ganoth 'about poisons'.\n");
		return 1;
	}
	
	if(str == "about poisons")
	{
		write(HIK+"Drak'Ganoth informs you that he has "+HIR+"ONE"+HIK+" poison available. You may 'purchase' it.\n"+NORM);
		return 1;
	}
	return 1;
}

purchase(str)
{
	int cost;
	object poison;
	
	if(!str)
	{
		write("You can only purchase poison.\n");
		return 1;
	}
	
	if(str != "poison")
	{
		write("You can only purchase poison.\n");
		return 1;
	}
	cost = 1000;
	poison = clone_object(OBJPATH+"poisonobj.c");
	
	if(str == "poison")
	{
		if(this_player()->query_money() < cost){
			write("Drak'Ganoth laughs at you for not having enough money!\n");
			return 1;
		}
		
		if(!this_player()->add_weight(1)){
			write("Drak'Ganoth laughs at you for not being able to carry the poison!\n");
			return 1;
		}
		
		this_player()->add_money(-cost);
		tell_object(this_player(), "Drak'Ganoth takes your money and hands you the poison.\n");
		move_object(poison, this_player());
		return 1;
	}
	return 1;
}