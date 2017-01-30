#include "/players/snow/guild/def.h"

cyborg_get(str) {
    string item;
    string container;
    object item_o;
    object container_o;
    object it;


    if (!str) {
        write("Get what?\n");
        return 1;
    }
    if (TP->query_ghost()) {
        write("Your incorporeal hand passes right through it.\n");
        return 1;
    }
    if (str == "all") {
      get_all(ENV(TP));
        return 1;
    }
    if (sscanf(str, "%s from %s", item, container) != 2) {
        pick_item(str);
        return 1;
    }
     container_o = present(lower_case(container), environment(TP));
    if(!container_o) container_o = present(lower_case(container), TP);
    if (!container_o) {
        write("There is no " + container + " here.\n");
        return 1;
    }
    if (!call_other(container_o, "can_put_and_get", 0)) {
        write("You can't do that!\n");
        return 1;
    }
    if (item == "all") {
        get_all(container_o);
        return 1;
    }
    item_o = present(item, container_o);
    if (item_o) {
        if (call_other(item_o, "id", item)) {
            int weight;
            if (living(container_o) &&
                call_other(item_o, "drop", 1)) {
                write("You can not take " + item + " from " +
                      container + ".\n");
                return 1;
            }
            if (!call_other(item_o, "get", item)) {
                write("You can not take " + item + " from " +
                      container + ".\n");
                return 1;
            }
            weight = call_other(item_o, "query_weight");
            if (!TP->add_weight(weight)) {
                write("You can not carry more.\n");
                return 1;
            }
            call_other(container_o, "add_weight", -weight);
            move_object(item_o, TP);
            it = item;
            write("Ok.\n");
            say(TPN + " takes " + item + " from " + container + ".\n");
            present(GID, TP)->add_body_xp("eyes", 1);
            return 1;
        }
    }
    write("There is no " + item + " in the " + container + ".\n");
    return 1;
}

static pick_item(obj) {
    object ob, it;
    int i;

    obj = lower_case(obj);
    ob = present(obj, environment(this_player()));
    if (!ob) {
        write("That is not here.\n");
        return 1;
    }
    if (TP->query_ghost()) {
        write("You fail.\n");
        return 1;
    }
    if (environment(ob) == TP) {
        write("You already have it!\n");
        return 1;
    }
    if (!call_other(ob, "get")) {
        write("You can not take that!\n");
        return 1;
    }
    i = call_other(ob, "query_weight");
    if (TP->add_weight(i)) {
        move_object(ob, TP);
        say(TPN+ " takes " + obj + ".\n");
        it = obj;
        write("You take "+obj+".\n");
        present(GID, TP)->add_body_xp("eyes", 1);
        return 1;
    }
    write("You can't carry that much.\n");
    return 1;
}

static get_all(from) {
    object ob, next_ob;
    object it;

    ob = first_inventory(from);
    while(ob) {
        string item;
        next_ob = next_inventory(ob);
        item = call_other(ob, "short");
        if ((item && call_other(ob, "get"))) {
            int weight;
            if (!living(from) || !call_other(ob, "drop", 1)) {
                if (!call_other(ob, "id", "soul")) {
                    weight = call_other(ob, "query_weight");
                    if (TP->add_weight(weight)) {
                        write(item + ": Ok.\n");
                        call_other(from,"add_weight",-weight);
                           move_object(ob, TP);
                        say(TPN + " takes: " + item + ".\n");
                    } else {
                        write(item + ": Too heavy.\n");
                    }
                }
            }
            it = item;
        }
        ob = next_ob;
    }
}
