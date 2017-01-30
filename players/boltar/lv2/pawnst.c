#define MAX_LIST	30

int value, pval,val2;
string name_of_item;
string var1, var2, var3;
object store1, store2, store3;

short() {
    return "store room for Boltar's shop";
}

init() {
    add_action("south","south");
}

inventory(str)
{
    object ob;
    string pl_nam, sernam, holdnam;
    int max;
    pl_nam = call_other(this_player(), "query_name",0);
    holdnam = pl_nam + "holder";
    sernam = present(holdnam);
    if (!str)
	str = "all";
    max = MAX_LIST;
    ob = first_inventory(sernam);
    while(ob && max > 0) {
	if (str == "all") {
	    list(ob);
	    max -= 1;
	}
	if (str == "weapons" && call_other(ob, "weapon_class", 0)) {
	    list(ob);
	    max -= 1;
	}
	if (str == "armors" && call_other(ob, "armor_class", 0)) {
	    list(ob);
	    max -= 1;
	}
	ob = next_inventory(ob);
    }
}

list(ob)
{
    int value;
    
    value = call_other(ob, "query_value", 0);
    val2 = value + (value/10);
    if (value) {
write(val2 + ":\t" + call_other(ob, "short") + ".\n");
    }
}

value(item) {
    name_of_item = present(item);
    if (!name_of_item) {
	return 0;
    }
    value = call_other(name_of_item, "query_value", 0);
    if (!value) {
	return 0;
    }
    write("The "); write(item); write(" would cost you ");
    write(value*2); write(" gold coins.\n");
    return 1;
}

buy(str) {
   string item, hold, hold2, tak;
     sscanf(str, "%s ?? %s",hold,item);
     tak = "@"+hold+":"+item;
     hold2 = present(hold);
     name_of_item = present(item, hold2);
    if (!name_of_item) {
write("That is not here to buy back.\n");
	return;
    }
    value = call_other(name_of_item, "query_value", 0);
    if (!value) {
	write("Item has no value.\n");
	return;
    }
    pval = value;
    if (pval > 1000) {
       pval = 1000;
       }
       value = pval + (pval/10);
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
write("I costs you "); write(value); write(" gold coins.\n");
    write("Ok.\n");
    say(call_other(this_player(), "query_name") + " repays his debt on " + item + ".\n");
}

south() {
    call_other(this_player(), "move_player", "leaves#players/boltar/lv2/wildwest3.c");
    return 1;
}

reset(arg) {
    if (!arg)
	set_light(1);
    if (!present("torch")) {
	object torch;
	torch = clone_object("obj/torch");
	call_other(torch, "set_name", "torch");
	call_other(torch, "set_fuel", 2000);
	call_other(torch, "set_weight", 1);
	move_object(torch, this_object());
    }
}

long()
{
    write("All things from the pawn shop are stored and sorted here here.\n");
}

store(item)
{
    object ob;
     string hold, pl_nam, hold2;
     pl_nam = call_other(this_player(), "query_name",0);
  hold = pl_nam+"holder";

     hold2 = present(hold);
     move_object(item, hold2);
	    return;
}

realm() { return "NT"; }
#define MAX_LIST	30

