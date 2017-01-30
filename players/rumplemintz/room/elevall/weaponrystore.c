#define MAX_LIST        30

int value;
string name_of_item;

short() {
    return "store room for the weapon store";
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
    if (!present("dagger")) {
        object dagger;
        dagger = clone_object("players/rumplemintz/weapon/dagger");
        dagger->set_long("You see a finely crafted dagger.\n");
        move_object(dagger, this_object());
    }
    if (!present("shortsword")) {
        object shortsword;
        shortsword = clone_object("players/rumplemintz/weapon/shortsword");
        shortsword->set_long("You see finely crafted blade.\n");
        move_object(shortsword, this_object());
    }
    if (!present("club")) {
         object club;
         club = clone_object("players/rumplemintz/weapon/club");
         club->set_long("You see a sturdy club.\n");
         move_object(club, this_object());
    }
    if (!present("longsword")) {
        object longsword;
        longsword = clone_object("players/rumplemintz/weapon/longsword");
        longsword->set_long("You see a sharp battleworthy longsword.\n");
        move_object(longsword, this_object());
    }
    if (!present("maul")) {
        object maul;
        maul = clone_object("players/rumplemintz/weapon/maul");
        maul->set_long("You see a dangerous looking maul.\n");
        move_object(maul, this_object());
    }
    if (!present("greatsword")) {
        object gsword;
        gsword = clone_object("players/rumplemintz/weapon/greatsword");
        gsword->set_long("You see a very big and deadly sword.\n");
        move_object(gsword, this_object());
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
