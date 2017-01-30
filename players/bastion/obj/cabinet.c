int local_weight;
int cab_is_open;

init() {
    add_action("open","open");
    add_action("close","close");
}

id(str) {return (str=="cabinet" || str="china cabinet"); }

short() {
    return "a china cabinet";
}

long() {
    write("Through the glass front you see displayed elegant porcelain-ware\n"+
          "and crystal. The cabinet is currently "+
    if (cab_is_open)
	write("open.\n");
    else
	write("closed.\n");
}

query_value() { return 200; }

query_weight() { return 80; }

get() { return 1; }

can_put_and_get() { return cab_is_open; }

add_weight(arg) {
    if (arg + local_weight > 8)
	return 0;
    local_weight += arg;
}

close(str)
{
    if (!id(str))
        return 0;
    cab_is_open = 0;
    write("You close the cabinet.\n");
    return 1;
}

open(str)
{
    if (!id(str))
        return 0;
    cab_is_open = 1;
    write("You open the cabinet.\n");
    return 1;
}

reset(arg) {
    if (arg)
	return;
    cab_is_open = 0;
    if(!present("china", this_object()) {
        object china;
        china=clone_object("obj/treasure");
        china->set_name("china");
        china->set_id("china");
        china->set_alias("crystal");
        china->set_short("a set of china and crystal");
        china->set_long("The china and crystal appear equally fragile and "+
                        "valueable.\n");
        china->set_value(2000);
        china->set_weight(4); }
}
