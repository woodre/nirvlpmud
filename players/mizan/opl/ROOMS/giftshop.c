inherit "/room/room.c";
#include "/obj/ansi.h"
#include "std_old.h"

object door1, door2;

void reset(int arg)
{
    if (arg) return;
    set_light(1);

    short_desc = "The Gift Shop of the OverPowerLord";
    long_desc =
        "    " + HIB + ">>>" + NORM + " " + HIY +
        "The Gift Shoppe of Goodliness" +
        NORM + " " + HIB + "<<<" + NORM + "\n" +
        "    There is an almost uncomfortably overwhelming aroma of manliness here\n" +
        "  in the gift shop of the OverPowerLord. It's a bit of a cross between a\n"+
        "  hardware, toy, smoke, and gun shop. You can buy or sell things here.\n" +
        "  Commands are: '"+HIW+"buy item"+NORM+"', '"+HIW+"sell item"+NORM+"', '"+HIW+"sell all"+NORM+"', '"+HIW+"list"+NORM+"', '"+HIW+"list weapons"+NORM+"'\n"+
        "  '"+HIW+"list armors"+NORM+"' and '"+HIW+"value item"+NORM+"'.\n"+
        "  There is a small path north, and some shimmering " +
        HIB+"blue light"+NORM+" blocking it.\n";

    dest_dir = ( {
        "players/mizan/opl/ROOMS/entrance.c", "east",
        "players/mizan/opl/ROOMS/shady.c", "south",
    });

    items = ( {

        "floor",
        "The floor is a frightening mess of caked over bubble gum, paint, blood,\n"+
        "and some other mysterious, unknown bodily fluids.\n",

        "light",
        "The shimmering blue light is similar to what you have seen in the shop\n"+
        "within the village spine. However it has a much stronger glow, and you\n"+
        "suspect it would hurt a lot more to bounce off this version than the\n"+
        "significantly dimmer version that you are used to seeing.\n",

        "path",
        "This is a path which is riddled with pain for those not authorized\n"+
        "to follow its structured way.\n",

    });

    if (!door1)
    {
        door1 = clone_object("obj/door");
        door1->set_dir("west");
        door1->set_door_room("/players/mizan/opl/ROOMS/secretshop");
        door1->set_type("secpass-a");
        door1->set_code("secretshopdoor");
        door1->set_door_long("This is a heavy steel door, several inches thick.\n");
        door1->set_locked(1);
        door1->set_closed(1);
        door1->set_can_lock(0);

        door2 = clone_object("obj/door");
        door2->set_dir("east");
        door2->set_door_room("/players/mizan/opl/ROOMS/giftshop");
        door2->set_type("secpass-a");
        door2->set_code("secretshopdoor");
        door2->set_door_long("This is a heavy steel door, several inches thick.\n");

        door1->set_door(door2);
        door2->set_door(door1);
        move_object(door1, this_object());
        move_object(door2, "/players/mizan/opl/ROOMS/secretshop");
        door1->set_both_status();
    }

    set_no_clean(1);
}

init()
{
    ::init();
    add_action("sell", "sell");
    add_action("value", "value");
    add_action("buy", "buy");
    add_action("north", "north");
    add_action("list", "list");
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

    if (!ob)
    {
        write("No such item (");
        write(item);
        write(") here.\n");
        return 1;
    }
    do_sell(ob);
    return 1;
}

do_sell(ob) {
    int value, do_destroy;
    value = ob->query_value(1);
    if (!value) value = ob->query_value();
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
    if (value > 600000)
        do_destroy = 1;
    if (ob->query_dest_flag()) do_destroy = 1;
    if (value > 1000) {
        write("The shop is low on money...\n");
        if (value < 1500) value = 1000;
        else value = 1000 + random(501);
    }
    write("You get ");
    write(value);
    write(" gold coins.\n");
    say(call_other(this_player(), "query_name", 0) + " sells " +
        call_other(ob, "short", 0) + ".\n");
    call_other(this_player(), "add_money", value);
    /* what does this do? add_worth(value, ob); */

    if (do_destroy)
    {
        write("The valuable item is hidden away.\n");
        destruct(ob);
        return 1;
    }

    call_other("players/mizan/opl/ROOMS/storeroom", "store", ob);
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
        if (call_other("players/mizan/opl/ROOMS/storeroom", "value", item))
            return 1;
        write("No such item (");
        write(item);
        write(") here\n");
        write("or in the store.\n");
        return 1;
    }
    value = name_of_item->query_value(1);
    if (!value)
        value = call_other(name_of_item, "query_value", 0);
    if (!value) {
        write(item);
        write(" has no value.\n");
        return 1;
    }
    write("You would get ");
    write(value);
    write(" gold coins.\n");
    return 1;
}

buy(item) {
    if (!item)
        return 0;
    call_other("players/mizan/opl/ROOMS/storeroom", "buy", item);
    return 1;
}

north() {
    if (call_other(this_player(), "query_level", 0) < 30) {
        write("A strong magic force stops you.\n");
        say(call_other(this_player(), "query_name", 0) +
            " tries to go through the field, but fails.\n");
        return 1;
    }
    write("You wriggle through the force field...\n");
    call_other(this_player(), "move_player", "north#players/mizan/opl/ROOMS/storeroom");
    return 1;
}

list(obj) {
    call_other("players/mizan/opl/ROOMS/storeroom", "inventory", obj);
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

query_drop_castle() {
    return 1;
}
