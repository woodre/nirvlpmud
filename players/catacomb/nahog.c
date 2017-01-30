inherit "obj/monster";
#include "/players/catacomb/misc/ansi.h"
#define TP this_player();

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("nahog");
  set_alt_name("man");
  set_short(HIY+"Nahog"+NORM+", the medicine man");
  set_long(
  "  This old man looks rather weak in his old age, but\n"+
  "don't underestimate him.  He has lived a life of hardship\n"+
  "watching his father die to an angry mob.  He has given up\n"+
  "the way of the sword and now stands here buying items from\n"+
  "adventurers to make his medicines.\n");

  set_level(20);
  set_hp(1000);
  set_al(1000);
  set_ac(20);
  set_aggressive(0);
  set_wc(30);
  set_chance(20);
  set_spell_dam(50);  
  set_spell_mess1(
    "Nahog "+BOLD+"SCREAMS"+NORM+" at his opponent.\n");
  set_spell_mess2(
    "Nahog "+BOLD+"SCREAMS"+NORM+" at you releasing a large\n"+
    "amount of his energy directly into you.\n"+
    "You fall to the ground from the power of Nahog's attack.\n");
}
init()
{
  add_action("sell", "sell");
  add_action("buy", "buy");
}

sell(item) 
{
    object ob;

    if (!item)
	return 0;
    if (item == "all") 
    {
	object next;
	ob = first_inventory(this_player());
	while(ob) 
      {
	    next = next_inventory(ob);
	    if (!ob->drop() && ob->query_value())
          {
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
    if (!ob) 
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
    value = ob->query_value();
    if (!value) 
    {
	write(ob->short() + " has no value.\n");
	return 1;
    }
    if (environment(ob) == this_player()) 
    {
        int weight;
	if (call_other(ob, "drop", 0)) 
      {
	    write("I can't take it from you!\n");
	    return 1;
	}
      weight = call_other(ob, "query_weight", 0);
	call_other(this_player(), "add_weight", - weight);
    }
    if (value > 6000)
	do_destroy = 1;
    if(ob->query_dest_flag()) do_destroy = 1;
    if (value > 1000) 
    {
	write("The shop is low on money...\n");
	value = 1000;
    }
    write("You get "); write(value); write(" gold coins.\n");
    say(call_other(this_player(), "query_name", 0) + " sells " +
	call_other(ob, "short", 0) + ".\n");
    call_other(this_player(), "add_money", value);
    if (do_destroy) 
    {
	write("The valuable item is hidden away.\n");
	destruct(ob);
	return 1;
    }
    /* added by Vertebraker [6.2.01] Oops ! */
else move_object(ob, "/players/catacomb/room_shop");
    /* added by Vertebraker [6.2.01] Oops! */
    return 1;
}
buy(item)
{
   write("Nahog tells you: Sorry I don't have anything for sale yet.\n");
   return 1;
}
