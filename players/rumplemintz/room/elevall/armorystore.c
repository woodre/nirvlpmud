#define MAX_LIST        30

int value;
string name_of_item;

short() {
    return "store room for the armory";
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
    value = call_other(ob, "query_value");
    if (value) {
        write(value*2 + ":\t" + call_other(ob, "short") + ".\n");
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
    value *= 2;
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
    if (!present("leather armor")) {
        object leather;
        leather = clone_object("players/rumplemintz/armor/leather_armor");
        move_object(leather, this_object());
    }
    if (!present("ring mail")) {
        object ringmail;
        ringmail = clone_object("players/rumplemintz/armor/ring_mail");
        move_object(ringmail, this_object());
    }
    if (!present("scale mail")) {
        object scalemail;
        scalemail = clone_object("players/rumplemintz/armor/scale_mail");
        move_object(scalemail, this_object());
    }
    if (!present("chain mail")) {
        object chainmail;
        chainmail = clone_object("players/rumplemintz/armor/chain_mail");
        move_object(chainmail, this_object());
    }
    if (!present("medium shield")) {
        object shield;
        shield = clone_object("players/rumplemintz/armor/medium_shield");
        move_object(shield, this_object());
    }
    if (!present("metal helmet")) {
        object helmet;
        helmet = clone_object("players/rumplemintz/armor/metal_helmet");
        move_object(helmet, this_object());
    }
}

/* set_{class,weight,value,alt_name,alias,short,long,read,hit_func,wield_func}*/
reset(arg) {
    if (!arg)
        set_light(1);
}

long()
{
    write("All things from the smithy are stored here.\n");
}

store(item)
{
    string short_desc;
    object ob;

    short_desc = call_other(item, "short");
    ob = first_inventory(this_object());
    while(ob) {
        if (call_other(ob, "short") == short_desc) {
            /* Move it before destruct, because the weight
               has already been compensated for. */
            move_object(item, this_object());
            destruct(item);
            return;
	}
        ob = next_inventory(ob);
    }
    move_object(item, this_object());
}
