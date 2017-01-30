string name, alias, short_desc, long_desc, value, weight, info;
string type;
int worn, ac;
object worn_by;
object next;

reset(arg)
{
    if(arg)
	return;
    type = "armor";
}

link(ob)
{
    next = ob;
}

remove_link(str)
{
    object ob;

    if (str == "body armor") {
	ob = next;
	next = 0;
	return ob;
    }
    if (next)
	next = call_other(next, "remove_link", str);
    return this_object();
}

init() {
    add_action("wear","wear");
    add_action("remove","remove");
}

rec_short()
{
    if (next)
	return name + ", " + call_other(next, "rec_short");
    return name;
}

short() {
    test_wear();
    if (worn)
	return short_desc + " (worn)";
    return short_desc;
}

long(str) {
    write(long_desc);
}

id(str)
{
    return str == name || str == alias || str == type;
}

test_type(str)
{
    if(str == type)
	return this_object();
    if(next)
	return call_other(next, "test_type", str);
    return 0;
}

tot_ac()
{
    if (next)
	return ac + call_other(next, "tot_ac");
    return ac;
}

query_type() { return type; }

query_value() { return value; }

query_worn() { test_wear(); return worn; }

query_name() { return name; }

armor_class() { return ac; }

wear(str)
{
    object ob;

    if (!id(str))
	return 0;
    if (environment() != this_player()) {
	write("You must get it first!\n");
	return 1;
    }
    test_wear();
    if (worn) {
	write("You're already wearing it!\n");
	return 1;
    }
    next = 0;
    ob = call_other(this_player(), "wear", this_object());
    if(!ob) {
	worn_by = this_player();
	worn = 1;
	return 1;
    }
    write("You already have an armor of class " + type + ".\n");
write("Worn armor " + call_other(ob,"short") + ".\n");
    return 1;
}

get() { return 1; }

drop(silently) {
    test_wear();
    if (worn) {
	call_other(worn_by, "stop_wearing",name);
	worn = 0;
	worn_by = 0;
	if (!silently)
	    write("You drop your worn armor.\n");
    }
    return 0;
}

remove(str) {
    if (!id(str))
	return 0;
    test_wear();
    if (!worn) {
	return 0;
    }
    call_other(worn_by, "stop_wearing",name);
    worn_by = 0;
    worn = 0;
    return 1;
}

query_weight() { return weight; }

set_name(n) { name = "body armor"; }
set_short(s) { short_desc = "Body Armor"; }
set_value(v) { value = 1250; }
set_weight(w) { weight = 5; }
set_ac(a) { ac = 5; }
set_alias(a) { alias = "body"; }
set_long(l) { long_desc = "A person body shield"; }
set_type(t) { type = "armor"; }


test_wear() {
    if (environment() == worn_by)
        return;
    if (worn_by)
        call_other(worn_by, "stop_wearing", name);
    worn_by = 0;
    worn = 0;
}
