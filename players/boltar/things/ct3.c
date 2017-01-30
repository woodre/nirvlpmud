#include "living.h"
int busy;
object myself;
string it;

id(str) {
   return str == "ct";
}
 reset(arg) {
   if (arg)
  return;

    cap_name = "Ct";
    name = "ct";
    level = 3;
    experience = 0;
    max_hp = 9;
    hit_point = 9;
    weapon_class = 0;
    armor_class = 0;
    is_npc = 1;
    alignment = 60;
    myself=this_object();
   enable_commands();
}

look(str, remote) {
    object ob, ob_tmp;
    string item;
    int max;
    if (this_object()->test_dark())
	return 1;
    if (!str) {
        if (remote && call_other(this_object(), "query_brief")) {
	    write(call_other(environment(), "short")); write("\n");
	} else {
	    call_other(environment(), "long");
	}
	ob = first_inventory(environment());
	max = MAX_LIST;
	while(ob && max > 0) {
	    if (ob != myself) {
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
	return 1;
    }
    if (sscanf(str, "at %s", item) == 1 || sscanf(str, "in %s", item) == 1) {
	item = lower_case(item);
	ob = present(item, this_object());
	if (!ob && call_other(environment(this_object()), "id", item))
	    ob = environment(this_object());
	if (!ob)
	    ob = present(item, environment(this_object()));
	if (!ob) {
	    write("There is no " + item + " here.\n");
	    return 1;
	}
	it = item;
	call_other(ob, "long", item);
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
	max = MAX_LIST;
	ob = first_inventory(ob);
	while (ob && max > 0) {
	    string sh;
	    sh = call_other(ob, "short");
	    if (sh)
		write(sh + ".\n");
	    ob = next_inventory(ob);
	    max -= 1;
	}
	return 1;
    }
    write("Look AT something, or what?\n");
    return 1;
}

