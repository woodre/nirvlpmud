/*
 * This is a genereal purpose object tracer.
 * It can be used to find objects, list info about them,
 * and walk up and down the inventory lists.
 */

string var1, var2, var3;
object store1, store2, store3;

init() {
    if (call_other(this_player(), "query_level") >= 20) {
	add_action("i_dump"); add_verb("i_dump");
	add_action("i_destruct"); add_verb("i_destruct");
	add_action("i_call"); add_verb("i_call");
	add_action("i_tell"); add_verb("i_tell");
	add_action("i_trans"); add_verb("i_trans");
	add_action("i_set"); add_verb("i_set");
    }
}

static i_dump(str) {
    int tmp;
    object ob;
    string flag, path;

    if (str == 0) {
	write("All variables:\n");
	if (var1) {
	    write(var1 + ":\t"); write(store1); write("\n");
	}
	if (var2) {
	    write(var2 + ":\t"); write(store2); write("\n");
	}
	if (var3) {
	    write(var3 + ":\t"); write(store3); write("\n");
	}
	return 1;
    }
    if (sscanf(str, "%s %s", path, flag) != 2)
	path = str;
    ob = parse_list(0, path);
    if (ob == 0)
	return 0;
    if (flag == "list") {
	int i;
	ob = first_inventory(ob);
	while(ob) {
	    i += 1;
	    write(i + ":\t");
	    write(ob);
	    write("\t" + call_other(ob, "short") + "\n");
	    ob = next_inventory(ob);
	}
	return 1;
    }
    write(ob); write(":\n");
    write(call_other(ob, "short"));
    if (living(ob))
	write("(living)\n");
    if (call_other(ob, "query_npc"))
	write("(NPC)");
    write("\n");
    tmp = call_other(ob, "query_value");
    if (tmp)
	write("Value:\t" + tmp + "\n");
    tmp = call_other(ob, "query_weight");
    if (tmp)
	write("Weight:\t" + tmp + "\n");
    tmp = creator(ob);
    if (tmp)
	write("Creator:\t" + tmp + "\n");
    return 1;
}

id(str) {
    return str == "tracer" || str == "debug";
}

short() {
    return "General purpose object tracer";
}

long() {
    write("Commands available:\n");
    write("i_dump item list\n");
    write("i_dump item\n");
    write("i_destruct item\n");
    write("i_call item 'function'\n");
    write("i_call item 'function' 'argument'\n");
    write("i_tell item 'str'\n");
    write("i_trans item\n");
    write("i_set var item\n");
    write("An item is a list separated by ':'. An item in that list can be\n");
    write("@name\tName of a player or monster.\n");
    write("\"str\"\tShot description of an item.\n");
    write("/obj\tName of an object or room.\n");
    write("$var\tContents of a variable.\n");
    write("here\tThis room.\n");
    write("#num\tObject number 'num'.\n");
    write("id\tName of an item.\n");
    write("Example: take a bag from a player named foul:\n");
    write("i_trans @foul:bag\n");
}

get() { return 1;}

query_value() {
    return 10;
}

static i_destruct(str) {
    object ob;
    ob = parse_list(0, str);
    if (!ob)
	return 0;
    destruct(ob);
    write("Ok.\n");
    return 1;
}

static i_call(str) {
    string with, what, item;
    int iwhat;
    object ob;

    if (!str)
        return 0;
    if (sscanf(str, "%s %s %d", item, with, what) == 3)
        iwhat = 1;
    else if (sscanf(str, "%s %s %s", item, with, what) != 3) {
	if (sscanf(str, "%s %s", item, with) == 2)
	    iwhat = 0;
	else
	    return 0;
    }
    ob = parse_list(0, item);
    if (!ob)
	return 0;
    write("Got: "); write(call_other(ob, with, what)); write("\n");
    say(call_other(this_player(), "query_name") +
	" patched the internals of " + call_other(ob, "short") + ".\n");
    return 1;
}

static i_tell(str) {
    string item, what;
    object ob;
    if (!str)
	return 0;
    if (sscanf(str, "%s %s", item, what) != 2)
	return 0;
    ob = parse_list(0, item);
    if (!ob)
	return 0;
    if (!living(ob)) {
	write("Not a living object.\n");
	return 1;
    }
    tell_object(ob, call_other(this_player(), "query_name") +
		" tells you: " + what + "\n");
    return 1;
}

static i_trans(str) {
    object mark;

    if (!str)
	return 0;
    mark = parse_list(0, str);
    if (!mark)
	return 0;
    if (call_other(mark, "get")) {
	if (transfer(mark, this_player()) != 0) {
	    write("Failure.\n");
	    return 1;
	}
    } else {
	move_object(mark, environment(this_player()));
    }
    write("Ok.\n");
    return 1;
}

static find_item(prev, str) {
    object ob;
    string tmp;

    if (str == "here")
	return environment(this_player());
    if (str == "^")
	return environment(prev);
    if (sscanf(str, "@%s", tmp) == 1)
	return find_living(tmp);
    if (sscanf(str, "/%s", tmp) == 1)
	return find_object(tmp);
    if (sscanf(str, "$%s", tmp) == 1) {
	if (tmp == var1)
	    return store1;
	if (tmp == var2)
	    return store2;
	if (tmp == var3)
	    return store3;
	return 0;
    }
    if (prev == 0)
	prev = environment(this_player());
    if (sscanf(str, "\"%s\"", tmp) == 1) {
	ob = first_inventory(prev);
	while(ob && call_other(ob, "short") != tmp) {
	    ob = next_inventory(ob);
	}
	return ob;
    }
    if (sscanf(str, "#%d", tmp) == 1) {
	if (prev == 0)
	    return 0;
	ob = first_inventory(prev);
	while(tmp > 1) {
	    tmp -= 1;
	    if (ob == 0)
		return 0;
	    ob = next_inventory(ob);
	}
	return ob;
    }
    return present(str, prev);
}

static parse_list(prev, str) {
    string tmp, rest;
    if (prev == 0)
	prev = environment(this_player());
    while(prev && str) {
	if (sscanf(str, "%s:%s", tmp, rest) == 2) {
	    prev = find_item(prev, tmp);
	    str = rest;
	    disp(prev);
	    continue;
	}
	prev = find_item(prev, str);
	disp(prev);
	break;
    }
    return prev;
}

static disp(ob) {
    write(ob); write("\n");
}

i_set(str) {
    object ob;
    string item, var;

    if (!str)
	return 0;
    if (sscanf(str, "%s %s", var, item) != 2)
	return 0;
    ob = parse_list(0, item);
    if (!ob)
	return 0;
    if (var1 == 0 || var1 == var) {
	var1 = var;
	store1 = ob;
	return 1;
    }
    if (var2 == 0 || var2 == var) {
	var2 = var;
	store2 = ob;
	return 1;
    }
    if (var3 == 0 || var3 == var) {
	var3 = var;
	store3 = ob;
	return 1;
    }
    write("Too many variables.\n");
    return 1;
}
