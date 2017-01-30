#define MAX_LIST        5

int value;
string name_of_item;

short() {
    return "store room for the starfleet surplus store";
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
    if (!present("dagger")) {
        object dagger,w_hit_dagger;
        dagger = clone_object("obj/weapon");
        w_hit_dagger = clone_object("players/rich/w_hit_dag.c");
        call_other(dagger, "set_name", "a klingon dagger");
        call_other(dagger, "set_class", 5);
        call_other(dagger, "set_weight", 1);
        call_other(dagger, "set_value", 30);
        call_other(dagger, "set_alt_name", "nasty");
        call_other(dagger, "set_alias", "dagger");
        call_other(dagger, "set_short", "a klingon dagger");
        call_other(dagger, "set_long", "a three pronged klingon dagger\n");
        call_other(dagger, "set_hit_func", w_hit_dagger);
        move_object(dagger, this_object());

  }
    if (!present("rifle")) {
        object phaserr,w_hit_pr;
        phaserr = clone_object("obj/weapon");
        w_hit_pr = clone_object("players/rich/w_hit_pr.c");
        call_other(phaserr, "set_name", "a phaser rifle");
        call_other(phaserr, "set_class", 25);
        call_other(phaserr, "set_weight", 4);
        call_other(phaserr, "set_value", 1125);
        call_other(phaserr, "set_alt_name", "rifle");
        call_other(phaserr, "set_alias", "hey_mon");
        call_other(phaserr, "set_short", "a phaser rifle");
        call_other(phaserr, "set_long", "a very nasty looking phaser\n");
        call_other(phaserr,"set_hit_func",w_hit_pr);
        move_object(phaserr, this_object());
    }
    if (!present("pistol")) {
        object phaserp,w_hit_pp;
        phaserp = clone_object("obj/weapon");
        w_hit_pp = clone_object("players/rich/w_hit_pp.c");
        call_other(phaserp, "set_name", "phaser pistol");
        call_other(phaserp, "set_class", 12);
        call_other(phaserp, "set_weight", 4);
        call_other(phaserp, "set_value", 950);
        call_other(phaserp, "set_alias", "pistol");
        call_other(phaserp, "set_short", "a phaser pistol");
        call_other(phaserp, "set_long", "a phaser pistol\n");
        call_other(phaserp, "set_hit_func", w_hit_pp);
        move_object(phaserp, this_object());
    }
    if (!present("phaser")) {
        object phaserh,w_hit_ph;
        phaserh = clone_object("obj/weapon");
        w_hit_ph = clone_object("players/rich/w_hit_ph.c");
        call_other(phaserh, "set_name", "hand phaser");
        call_other(phaserh, "set_class", 10);
        call_other(phaserh, "set_weight", 3);
        call_other(phaserh, "set_value", 800);
        call_other(phaserh, "set_alias", "phaser");
        call_other(phaserh, "set_short", "a hand phaser");
        call_other(phaserh, "set_long", "a hand phaser\n");
        call_other(phaserh,"set_hit_func",w_hit_ph);
        move_object(phaserh, this_object());
    }
    if (!present("whip")) {
        object whip,w_hit_whip;
        whip = clone_object("obj/weapon");
        w_hit_whip = clone_object("players/rich/w_hit_whip.c");
        call_other(whip, "set_name", "electric whip");
        call_other(whip, "set_class", 8);
        call_other(whip, "set_weight", 3);
        call_other(whip, "set_value", 650);
        call_other(whip, "set_alias", "whip");
        call_other(whip, "set_short", "an electric whip");
        call_other(whip, "set_long", "a Thringi electric whip\n");
        call_other(whip,"set_hit_func",w_hit_whip);
        move_object(whip, this_object());
    }
}

/* set_{class,weight,value,alt_name,alias,short,long,read,hit_func,wield_func}*/

reset(arg) {
  if(!arg)
  set_light(1);
}
long()
{
    write("All things from the starfleet surplus store are stored here.\n");
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
