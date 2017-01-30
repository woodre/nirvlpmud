#include "/players/snow/guild/def.h"

cyborg_put(str) {
    int i;
    string item;
    string container;
    object item_o;
    object container_o;
    object it;

    if (!str) { notify_fail("Put what?\n"); return 0; }
    if (sscanf(str, "%s in %s", item, container) != 2) {
        write("Put what?\n");
        return 1;
    }
    container = lower_case(container);
    container_o = present(container, this_player());
    if (!container_o)
        container_o = present(container, environment(this_player()));
    if (!container_o) {
        write("There is no " + container + " here!\n");
        return 1;
    }
    if (!call_other(container_o, "can_put_and_get", 0)) {
        write("You can't do that.\n");
        return 1;
    }
    item = lower_case(item);
    item_o = present(item, this_player());
    if (!item_o) {
        write("You have no " + item + "!\n");
        return 1;
    }
    if (item_o == container_o) {
      notify_fail("You can't put something in itself!\n");
        return 0; }
    if (call_other(item_o, "prevent_insert"))
        return 1;
    if (call_other(item_o, "drop", 0))
        return 1;
    if (!item_o)
        return 1;
    i = call_other(item_o, "query_weight");
    if (call_other(container_o, "add_weight", i)) {
        /* Remove the weight from the previous container. */
        call_other(environment(item_o), "add_weight", -i);
        move_object(item_o, container_o);
        say(TPN + " puts the " + item + " in the " + container + ".\n");
        write("Ok.\n");
        it = item;
        present(GID, TP)->add_body_xp("eyes", 1);
        return 1;
    }
    write("There is not room for more.\n");
    return 1;
}
