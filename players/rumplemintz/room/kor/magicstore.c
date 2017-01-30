#define MAX_LIST        30

int value;
string name_of_item;

short() {
    return "store room for Kor magic shop";
}

inventory(str)
{
    object ob;
    int max;
    if (!str)
        str = "all";
    max = MAX_LIST;
    ob = first_inventory(this_object());
    while(ob && max > 0) {
        if (str == "all") {
            list(ob);
            max -= 1;
	}
        ob = next_inventory(ob);
    }
}

list(ob)
{
    int value;
    value = call_other(ob, "query_value");
    if (value) {
        write(value+":\t"+call_other(ob,"short")+".\n");
    }
}

buy(item) {
    name_of_item = present(item);
    if (!name_of_item) {
        write("No such item in the store.\n");
        return;
    }
    value = call_other(name_of_item, "query_value", 0);
    if (!value) {
        write("Item has no value.\n");
        return;
    }
    value *= 1;
    if (call_other(this_player(), "query_money", 0) < value) {
        write("It would cost you ");
        write(value); write(" gold coins, which you don't have.\n");
        return;
    }
    if (!call_other(this_player(), "add_weight",
                    call_other(name_of_item, "query_weight"))) {
        write("You can't carry that much.\n");
        return;
    }
    call_other(this_player(), "add_money", 0 - value);
    move_object(name_of_item, this_player());
    write("Ok.\n");
    say(call_other(this_player(), "query_name") + " buys " + item + ".\n");
}

fill()
{
    if(!present("heal")) {
        object healspell;
        healspell = clone_object("players/rumplemintz/magic/heal");
        move_object(healspell, this_object());
    }
    if(!present("scroll of teleport")) {
       object teleport_scroll;
       teleport_scroll = clone_object("players/rumplemintz/magic/teleport_scroll");
       move_object(teleport_scroll, this_object());
    }
/*
    if(!present("scroll of identify")) {
      object identify_scroll;
      identify_scroll = clone_object("players/rumplemintz/magic/identify_scroll");
      move_object(identify_scroll, this_object());
    } */
}

/* set_{class,weight,value,alt_name,alias,short,long,read,hit_func,wield_func}*/
reset(arg) {
/*
   if(!present("scroll of identify")) {
      object identify_scroll;
      int i;
      while(i < 3) {
         i = i + 1;
         identify_scroll = clone_object("players/rumplemintz/magic/identify_scroll");
         move_object(identify_scroll, this_object());
      }
   }
*/
   if(arg) return;
   set_light(1);
}

long()
{
    write("All things from the magic shop are stored here.\n");
}
