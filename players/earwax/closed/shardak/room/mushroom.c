/*
 * This is the room where the actual growing and brewing of
 * healing items are taking place.
 * November 2000: updated to use /obj/generic_heal [../doc/imp_heals]
 */
#pragma strict_types
#include "/players/balowski/lib.h"
#include "../include/def.h"
#include "../include/ansi.h"
inherit ROOM;

int             LastGrow;
mapping         Stock;

void
create()
{
    ::create();
    set_no_clean(1);
    set_short("A storage room");
    set_long("Storage room for magic healing.\n");
    set_light(1);
    Stock = ([
        "mushroom" : 8,
        "toadstool" : 8,
       "elixer of life" : 6,
    ]);
    LastGrow = (int) "/room/church"->query_reboot_time();
    if (!LastGrow) LastGrow = time();
}

void
evGrow()
{
    int passed, mush, toad;

    passed = (time() - LastGrow) / 300;
    if (passed < 1) return;

    LastGrow += passed * 300;
    mush = (Stock["mushroom"] += passed - random(passed/3 + 1));
    toad = (Stock["toadstool"] += passed - random(passed/2 + 1));
    if (mush > 5) {
        Stock["basket of mushrooms"] += mush / 5;
        Stock["mushroom"] = mush % 5;
    }
    if (toad > 5) {
        Stock["basket of toadstools"] += toad / 5;
        Stock["toadstool"] = toad % 5;
    }
}

object
clone(string what)
{
    object ob;

    switch (what) {
        case "mushroom":
            ob = clone_object(STDDIR+"heal");
            ob->set_name("mushroom");
            ob->set_short(YEL+"A mushroom"+NORM);
            ob->set_long(YEL+"\
The yellow mushroom has been neatly prepared and is delicious\n\
looking. It is told to have both healing and satiating effects.\n"+NORM);
            ob->set_type("bite of mushroom");
            ob->set_msg("You eat a mushroom.\n");
            ob->set_msg2(" eats a mushroom.\n");
            ob->add_cmd("eat");
            ob->add_cmd("bite");
            ob->set_charges(1);
            ob->set_stuff(12);
            ob->set_heal(32,32);
            ob->set_value(256);
            break;

        case "toadstool":
            ob = clone_object(STDDIR+"heal");
            ob->set_name("toadstool");
            ob->set_short(HIK+"A toadstool"+NORM);
            ob->set_long(HIK+"\
The grey toadstool is covered with a thin layer of white mucilage,\n\
giving it a silvery tinge. It is still dirty and not very appetizing.\n\
It is told to have both healing and intoxicating effects.\n"+NORM);
            ob->set_type("bite of toadstool");
            ob->set_verb("eat");
            ob->set_msg("You eat the toadstool.\n");
            ob->set_msg2(" eats a toadstool.\n");
            ob->add_cmd("eat");
            ob->add_cmd("bite");
            ob->set_charges(1);
            ob->set_intox(6);
            ob->set_stuff(4);
            ob->set_heal(32,32);
            ob->set_value(352);
            break;

        case "basket of mushrooms":
            ob = clone_object(STDDIR+"heal");
            ob->set_name("basket");
            ob->add_alias("basket of mushrooms");
            ob->add_alias("mushrooms");
            ob->add_alias("mushroom");
            ob->set_short(YEL+"A basket of mushrooms"+NORM);
            ob->set_long(YEL+"\
A basket woven from even strands of bark. It is made for carrying\n\
the yellow toadstools that are told to bring you good health.\n"+NORM);
            ob->set_msg("You feel around in the basket and take out a mushroom.\n"+
                        "You devour it quickly.\n");
            ob->set_msg2(" takes a mushroom from a basket and eats it.\n");
            ob->set_type("mushrooms");
            ob->add_cmd("eat");
            ob->add_cmd("devour");
            ob->add_cmd("bite");
            ob->set_charges(5);
            ob->set_stuff(12);
            ob->set_heal(32,32);
            ob->set_value(256);
            break;

        case "basket of toadstools":
            ob = clone_object(STDDIR+"heal");
            ob->set_name("basket");
            ob->add_alias("basket of toadstools");
            ob->add_alias("toadstools");
            ob->add_alias("toadstool");
            ob->set_short(HIK+"A basket of toadstools"+NORM);
            ob->set_long(HIK+"\
A basket woven from even strands of bark. It is made for carrying\n\
the iron-grey toadstools that are told to have both healing and\n\
intoxicating effects.\n"+NORM);
            ob->set_type("toadstools");
            ob->add_cmd("eat");
            ob->add_cmd("bite");
            ob->add_cmd("devour");
            ob->set_msg("You take a toadstool from the basket and eat it.\n");
            ob->set_msg2(" takes a toadstool from a basket and eats it.\n");
            ob->set_charges(5);
            ob->set_intox(6);
            ob->set_stuff(4);
            ob->set_heal(32,32);
            ob->set_value(352);
            break;

        case "elixir of life":
            ob = clone_object(STDDIR+"heal");
            ob->set_name("vial");
            ob->add_alias("vial of elixir");
            ob->add_alias("elixir of life");
            ob->add_alias("elixir");
            ob->set_short("A vial of "+YEL+"elixir"+NORM);
            ob->set_long(YEL+"\
The frail glass vial contains a thick brown liquid. The imp has\n\
successfully extracted some of the healing components from the fungi\n\
and mixed them into this uninviting elixir.\n"+NORM);
            ob->set_type("drinks");
            ob->add_cmd("drink");
            ob->add_cmd("sip");
            ob->set_msg("You take a long drink from the elixir of life...\n"+
                        "You can feel your wounds begin to close.\n");
            ob->set_msg2(" drinks from an elixir of life.\n");
            ob->set_charges(5);
            ob->set_heal(35,35);
            ob->set_soak(10);
            ob->set_value(420);
            break;
    }
    return ob;
}

int
priceof(string item)
{
    switch (item) {
        case "mushroom": return 256;
        case "basket of toadstools": return 1760;
        case "toadstool": return 352;
        case "basket of mushrooms": return 1280;
        case "elixir of life": return 2100;
        default: return 10000;
    }
}

int
cmd_list()
{
    string *items;
    int i, x;

    evGrow();
    i = sizeof(items = keys(Stock));
    if (!i) return 0;
    
    while (i--) {
        if (!Stock[items[i]])
            continue;
        else if (!x++)
            write("Price  Stock  Item\n");

        write(pad(priceof(items[i]), -5));
        write("  ");
        write(pad(Stock[items[i]], -5));
        write("  ");
        write(items[i]);
        write("\n");
    }
    return x;
}

int
cmd_buy(string what)
{
    int value;
    object ob;

    evGrow();
    if (!what || !Stock[what])
        return 0;       /* not found */

    value = priceof(what);
    if (value > (int) this_player()->query_money())
        return -2;      /* can't afford */

    if (!(ob = clone(what)))
        return -1;

    if (transfer(ob, this_player())) {
        destruct(ob);
        return -3;      /* can't transfer (carry) */
    }

    this_player()->add_money(-value);
    Stock[what] -= 1;
    return value;               /* okay */
}
