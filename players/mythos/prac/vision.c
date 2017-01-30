#define ep environment(this_object())
#define eep  environment(ep)
inherit "obj/treasure";
static string it;
object myself;

reset(arg) {
  if(arg) return;

  set_id("crystal");
  set_short("A Dark Crystal");
  set_long("The Crystal of Vision.\n");
  set_weight(0);
  set_value(0);
}


init() {
  ::init();
  add_action("vision","l");
  add_action("vision","look");
  }

static test() {
    if ((eep->set_light(0)) <= -2) {
	write("It is too dark.\n"+
	      "Seems this darkness is caused through some magical\n"+
	      "phenomenon, for even your Fae eyes can not pierce through.\n");
	return 1;
    }
    return 0;
}

vision(str, remote) {
    object ob, ob_tmp;
    string item;
    int max;
    if(test()) 
    return 1;
    if (!str) {
        if (remote && call_other(this_player(), "query_brief")) {
	    write(call_other(environment(environment()), "short")); write("\n");
	} else {
	    call_other(environment(this_player()), "long");
	}
	ob = first_inventory(environment(this_player()));
	max = 20;
	while(ob && max > 0) {
	    if (ob != this_player()) {
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
	return 1;
    }
    write("Look AT something, or what?\n");
    return 1;
}
