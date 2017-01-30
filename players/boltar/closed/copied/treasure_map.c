string short_desc;
string long_desc;
string dest;

string t_short;
string t_long;
int t_value;
int t_weight;
string t_name, t_alias_name;
string t_read_msg;
object treasure;

init() {
    add_action("dig"); add_verb("dig");
    add_action("read"); add_verb("read");
}
    
id(str) { return str == "map";}

long() { write(long_desc);}

short() { return short_desc;}

set_short(sh) { short_desc = sh; long_desc = short_desc + "\n";}

set_long(long) { long_desc = long; }

set_dest(str) { dest = str; }

set_t_name(str) { t_name = str; }

set_t_short(str) { t_short = str; }

set_t_value(n) { t_value = n; }

/* optional values */

set_t_long(str) { t_long = str; }

set_t_weight(n) { t_weight = n; }

set_t_alias_name(str) { t_alias_name = str; }

set_t_read_msg(str) { t_read_msg = str; }

/* end of optional values */

get() { return 1;}

dig() {
    if (environment(this_player()) != find_object(dest)) {
        write("This is not the right spot.\n");
	return 1;
	}
    write("You found the treasure!\n");
    treasure = clone_object("obj/treasure");
    call_other(treasure,"set_id",t_name);
    call_other(treasure,"set_short",t_short);
    call_other(treasure,"set_value",t_value);
    if (t_alias_name)
        call_other(treasure,"set_alias",t_alias_name);
    if (t_long)
        call_other(treasure,"set_long",t_long);
    if (t_weight)
        call_other(treasure,"set_weight",t_weight);
    if (t_read_msg)
        call_other(treasure,"set_read",t_read_msg);
    move_object(treasure,find_object(dest));
    destruct(this_object());
    return 1;
}

read(str) {
    if (!id(str))
        return 0;
    write(long_desc);
    return 1;
}
