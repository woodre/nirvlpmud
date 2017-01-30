/************************************/
/*    Owner:      Vital@Nirvana     */
/*    Created:    12/18/00          */
/*    Modified:   8/20/01           */
/*    Realm:      Acadie            */
/************************************/

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"                    /*color header*/
#include "/players/vital/dest/include/dest.h"

inherit "room/room";

reset(arg) {
  if(!arg) {

set_light(1);

short_desc = "Acadie Shop";
long_desc =
    "  An Acadie Shop\n\
The shop has a strange material for floors and shelves. The \n\
light is provided by small globes mounted along the ceiling. \n\
All of the merchandise is neatly arranged and everything is \n\
in its place. There is a large sign along the back wall.\n ";

items = ({
    "shop",
    "The shop has a strange material for floors and shelves. The \n\
light is provided by small globes mounted along the ceiling. \n\
All of the merchandise is neatly arranged and everything is \n\
in its place. There is a large sign along the back wall.\n ",
    "material",
    "The strange material is wood. It seems like a ludicrous waste \n\
of precious resources, if it were not for the fact that this \n\
planet has plentiful forested areas",
    "floors",
    "The dark, brown floorboards are sturdy beneath your feet",
    "shelves",
    "The shelves are organized and surprisingly full",
    "light",
    "The light is provided by the strange glowing globes on the ceiling",
    "globes",
    "They glow with a natural light, but it has a light blue tint to it",
    "merchandise",
    "The shelves are full of various things. The shopkeeper deals \n\
in many different things",
    "everything",
    "The shelves are full of various things. The shopkeeper deals \n\
in many different things",
    "sign",
    "Perhaps if you were to \'read\' the sign, you could learn more",
    "wall",
    "The wall is composed of stone that must come from a nearby quarry"
});

dest_dir = ({
    ACADIE+"room/sidewalk3.c","out",
});

  }
}

init() {
    ::init();
    add_action("search_me","search");
    add_action("sell","sell");
    add_action("value","value");
    add_action("buy","buy");
    add_action("list","list");
    add_action("read_me", "read");
}

read_me(str) {
    if(!str || str != "sign") {
        notify_fail("You have to \'read sign'\ to see what is on it.\n");
        return 0;
    }
    else if(str == "sign"); {
        write("\nYou can \'buy\', \'sell\', \'value\', or \'list\' things here in the shop.\n");
    }
    return 1;
}

search_me(str) {
    if(!str) {
        notify_fail("What are trying to search?\n");
        return 0;
    }
    switch(str) {
        case "floor":
            write("The boards of the floor are solid and well fitted.\n");
            break;
        case "shelves":
            write("The search the shelves looking for something you need.\n");
            break;
        case "walls":
            write("The walls are sturdy and the seams are well fitted.\n");
            break;
        default: write("You furiously search the "+str+" but find nothing.\n");
    }
}

sell(string item) {
    object ob;

    if (!item) {
        notify_fail("What are you trying to sell?\n");
        return 0;
    }
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
        write("Ok All items have been sold.\n");
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
    add_worth(value, ob);
    if (do_destroy) {
        write("The valuable item is hidden away.\n");
        destruct(ob);
        return 1;
    }
    call_other("/players/vital/closed/std/store", "store", ob);
    return 1;
}

value(string item) {
    int value;
    string name_of_item;

    if (!item)
    return 0;
    name_of_item = present(item);
    if (!name_of_item)
      name_of_item = find_item_in_player(item);
    if (!name_of_item) {
        if (call_other("/players/vital/closed/std/store", "value", item))
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
    call_other("/players/vital/closed/std/store", "buy", item);
    return 1;
}

list(obj) {
    call_other("/players/vital/closed/std/store", "inventory", obj);
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
