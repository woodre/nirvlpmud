#include "std_old.h"
#include "/players/jaraxle/define.h"
inherit "obj/monster.c";
reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return; 
set_name("Niala");
set_alias("niala");
set_race("human");
set_short("Niala");
set_long(
  "Niala is a short, rather heavy set human female.\nShe has an assortment of string necklaces around her thick neck.\n");

set_level(1);
set_hp(500+random(500));
set_al(0);
set_wc(20);
set_ac(50);
set_aggressive(0);
set_chat_chance(3);
  load_chat("Niala preaches: You will not find a better deal than this!\n");
set_a_chat_chance(15);
  load_a_chat("Niala smacks you with a fat hand!\n");

 set_chance(20);
   set_spell_dam(30+random(36));
   
   set_spell_mess1(
"\n\nNiala smacks you with a coin purse.\n");
   set_spell_mess2(
"\n\nNiala smacks you with a coin purse.\n");
gold = clone_object("obj/money");
gold->set_money(10+random(10));
move_object(gold,this_object());
}

 init() {

   ::init();
    add_action("sell","sell");
    add_action("value","value");
    add_action("buy","buy");
    add_action("list","list");
}

sell(item) {
    object ob;

    if (!item)
        return 0;
    if (item == "all") {
        object next;
        ob = first_inventory(this_player());
        while(ob) {
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
        write("No such item ("); write(item); write(") here.\n");
        return 1;
    }
    do_sell(ob);
    return 1;
}

do_sell(ob) {
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
        call_other(this_player(), "add_weight", - weight);
    }
    if (value > 6000)
        do_destroy = 1;
    if(ob->query_dest_flag()) do_destroy = 1;
    if (value > 1000) {
        write("The shop is low on money...\n");
        value = 1000;
    }
    write("You get "); write(value); write(" gold coins.\n");
    say(call_other(this_player(), "query_name", 0) + " sells " +
        call_other(ob, "short", 0) + ".\n");
    call_other(this_player(), "add_money", value);
    if (do_destroy) {
    write("The valuable item is hidden away.\n");
        destruct(ob);
        return 1;
    }
    call_other("/players/jaraxle/3rd/warrior/rooms/hut_store", "store", ob);
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
        if (call_other("/players/jaraxle/3rd/warrior/rooms/hut_store.c", "value", item))
            return 1;
        write("No such item ("); write(item); write(") here\n");
        write("or in the store.\n");
        return 1;
    }
    value = call_other(name_of_item, "query_value", 0);
    if (!value) {
        write(item); write(" has no value.\n");
        return 1;
    }
    write("You would get "); write(value); write(" gold coins.\n");
    return 1;
}

buy(item) {
    if (!item)
        return 0;
    call_other("/players/jaraxle/3rd/warrior/rooms/hut_store.c", "buy", item);
    return 1;
}

list(obj) {
    call_other("/players/jaraxle/3rd/warrior/rooms/hut_store.c", "inventory", obj);
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

query_drop_castle() {
    return 1;
}

