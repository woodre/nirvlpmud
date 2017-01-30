#define DECAY_TIME	100

string name;
int corpse_level,decay;

prevent_insert() {
    write("The corpse is too big.\n");
    return 1;
}

init() {
    add_action("search","search");
    if(!name)
      set_name("noone");
}

reset() {
    set_heart_beat(1);
}

set_name(n)
{
    name = n;
    decay = DECAY_TIME;
}

short() {
    if(!name)
    set_name("noone");
    if (decay < 20)
	return "the somewhat decayed remains of " + capitalize(name);
    return "corpse of " + capitalize(name);
}

long() {
    write("This is the dead body of " + capitalize(name) + ".\n");
}

id(str) {
    return str == "corpse" || str == "corpse of " + name ||
	str == "remains";
}

heart_beat()
{
    decay -= 1;
    if (decay > 0)
	return;
    destruct(this_object());
}

can_put_and_get() { return 1; }

search(str)
{
    object ob;
    if (!str || !id(str))
	return 0;
    write("You search " + str + ", and find:\n");
    say(call_other(this_player(), "query_name") + " searches " + str + ".\n");
    if ( ! search_obj(this_object()))
    {
	write("\tNothing.\n");
    }
    else
    {
	write("\n");
    }
    return 1;
}

search_obj(cont)
{
    object ob;
    int total;
    string item;

    if (!call_other(cont, "can_put_and_get"))
	return 0;
    ob = first_inventory(cont);
    while(ob) {
	total += 1;
	item = call_other(ob, "short");
	write(item + ", ");
	ob = next_inventory(ob);
    }
    return total;
}

get() {
    return 1;
}

query_weight() {
    return 5;
}
set_corpse_level(arg) {
          corpse_level = arg;
           return 1;
}
heal_value() {
int heal;
     heal = 9*corpse_level/10;
return heal;
}
