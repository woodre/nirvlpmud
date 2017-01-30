inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
int q;
reset(arg) {
    if(arg) return;
    set_light(1);
     set_search(""+BOLD+"You notice a sign."+NORM+"\n");
short_desc=(""+RED+"The Mall Pawn Shop"+NORM+"");
long_desc=
"This is the mall pawn shop.  People come here to sell\n"+
"their stuff for quick cash and to find good bargains.\n"+
"There is a "+CYN+"sign"+NORM+" on the counter.\n"+
"You may: 'buy item', 'sell item', 'sell all', 'list',\n"+
"'list weapons', 'list armors' and 'value item'.\n";
items = ({
"sign","You could read the sign",
});

dest_dir = ({
"/players/jenny/bundy/rooms/m3c","west",
});
}
init() { 
    ::init(); 
   this_player()->set_fight_area();
   add_action("sell","sell");
    add_action("value","value");
    add_action("buy","buy");
    add_action("north","north");
    add_action("list","list");
add_action("sign","read");
}
sign(arg) { 
if(!arg) { return 0; }
if(arg == "sign") {

write(""+BLU+"    **************************************************"+NORM+"\n"+
""+BLU+"    *                                                *"+NORM+"\n"+
""+BLU+"    *              "+NORM+""+RED+"WE DO NOT ACCEPT"+NORM+""+BLU+"                  *"+NORM+"\n"+
""+BLU+"    *              "+NORM+""+RED+"   CHECKS FROM  "+NORM+""+BLU+"                  *"+NORM+"\n"+
""+BLU+"    *                                                *"+NORM+"\n"+
""+BLU+"    *              "+NORM+""+RED+"    AL BUNDY    "+NORM+""+BLU+"                  *"+NORM+"\n"+

""+BLU+"    *                                                *"+NORM+"\n"+
""+BLU+"    **************************************************"+NORM+"\n");
 return 1;
}
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
q = 1000+random(400);
    if (value > 1000 && value < q) {
   write("The shop is low on money . .\n");
value = value;
}
    if (value > 1000 && value > (q-1)) {
        write("The shop is low on money...\n");
        value = q;
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
    call_other("room/store", "store", ob);
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
        if (call_other("room/store", "value", item))
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
    call_other("room/store", "buy", item);
    return 1;
}
north() {
    if (call_other(this_player(), "query_level", 0) < 30) {
        write("A strong magic force stops you.\n");
        say(call_other(this_player(), "query_name", 0) +
            " tries to go north, but is stopped by the clerk.\n");
        return 1;
    }
    write("You wriggle through the force field...\n");
    call_other(this_player(), "move_player", "north#room/store");
    return 1;
}
list(obj) {
    call_other("room/store", "inventory", obj);
    return 1;
}
find_item_in_player(i)
{
    object ob;
    ob = first_inventory(this_player());
    while(ob) {
           return ob;
        ob = next_inventory(ob);
    }
    return 0;
}