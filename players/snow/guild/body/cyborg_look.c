#include "/players/snow/guild/def.h"

cyborg_look(str, remote) {
    object ob, ob_tmp;
    string item;
    object it;
    int max;
    if (!str) {
        if (call_other(this_player(), "query_brief")) {
            write(call_other(environment(TP), "short")); write("\n");
        } else {
           call_other(environment(TP), "long");
        }
        ob = first_inventory(environment(TP));
        max = 20;
        while(ob && max > 0) {
            if (ob != TP) {
                string short_str;
                short_str = call_other(ob, "short");
                if (short_str) {
                    max -= 1;
                    write(short_str + ".\n");
                    it = short_str;
                }
            }
            ob = next_inventory(ob);
        }
        present(GID, TP)->add_body_xp("eyes", 1);
        return 1;
    }
    if (sscanf(str, "at %s", item) == 1 || sscanf(str, "in %s", item) == 1) {
        item = lower_case(item);
        ob = present(item, this_player());
        if (!ob && call_other(environment(this_player()), "id", item))
            ob = environment(this_player());
        if (!ob)
            ob = present(item, environment(this_player()));
        if (!ob) {
            write("There is no " + item + " here.\n");
            return 1;
        }
        it = item;
        call_other(ob, "long", item);
        if(!ob->is_player() && living(ob)) say(TPN+" looks at "+ob->query_name()+"\n");
        if (!call_other(ob, "can_put_and_get", item))
            return 1;
        if (living(ob)) {
            object special;
            special = first_inventory(ob);
            while (special) {
                string extra_str;
                extra_str = call_other(special, "extra_look");
                if (extra_str)
                    write(extra_str + ".\n");
                special = next_inventory(special);
            }
        }
        ob_tmp = first_inventory(ob);
        while (ob_tmp && call_other(ob_tmp, "short") == 0)
            ob_tmp = next_inventory(ob_tmp);
        if (ob_tmp) {
            if (living(ob))
                write("\t" + capitalize(item) + " is carrying:\n");
            else
                write("\t" + capitalize(item) + " contains:\n");
        }
        max = 20;
        ob = first_inventory(ob);
        while (ob && max > 0) {
            string sh;
            sh = call_other(ob, "short");
            if (sh)
                write(sh + ".\n");
            ob = next_inventory(ob);
            max -= 1;
        }
        present(GID, TP)->add_body_xp("eyes", 1);
        return 1;
    }
    write("Look AT something, or what?\n");
    return 1;
}
