id(str) { return str=="lantern" || str=="magical lantern"; }
string amount_of_fuel;
string name;
string long_lit_desc;
string long_unlit_desc;
status is_lit;
int weight;

long() {
	if(is_lit) write("A magical lantern radiating light.\n"+
		"You can 'extinguish' it to save its magic powers.\n");
	else write("A magical lantern that you can 'light' to see in the dark.\n");
}

reset(arg) {
    if (arg)
	return;
	amount_of_fuel = 1000;
	name = "A magical lantern";
	weight = 0;
	is_lit = 1;
	set_light(1);
	set_heart_beat(1);
}

set_weight(w) { weight = w; }

query_weight() { return weight; }

short() {
    if (is_lit)
	return name + " (lighted)";
    if (amount_of_fuel == 0)
	return name + " (out of magic)";
    return name;
}

set_name(n) {
    name = n; 
    long_lit_desc = "A " + name + " (lit)\n";
    long_unlit_desc = "A " + name + "\n";
}
set_fuel(f) { amount_of_fuel = f; }

init() {
    add_action("light"); add_verb("light");
    add_action("extinguish"); add_verb("extinguish");
}

light(str) {
	if(!str) { return 0; }
	if(str == "lantern" || str == "magical lantern") {
    if (amount_of_fuel == 0) {
	write("The magical lantern is out of dark magic.\n");
	return 1;
    }
    if (is_lit) {
	write("It is already lighted.\n");
	return 1;
    }
    is_lit = 1;
    write("Your magical lantern begins to glow.\n");
    set_light(1);
    set_heart_beat(1);
    return 1;
	}
}

extinguish(str) {
	if(!str) { return 0; }
	if(str == "lantern" || str == "magical lantern") {
    if(!is_lit) {
	write("Your magical lantern has not been lighted.\n");
	return 1;
    }
    is_lit = 0;
	write("The magical lantern goes dark.\n");
    set_light(-1);
    set_heart_beat(0);
    return 1;
	}
}

heart_beat() {
    object ob;
    if (!is_lit)
	return;
    amount_of_fuel -= 1;
    if (amount_of_fuel > 0)
	return;
	say("The magical lantern goes dark.\n");
    set_heart_beat(0);
    is_lit = 0;
    set_light(-1);
    ob = environment();
    if (call_other(ob, "query_level"))
	call_other(ob, "add_weight", -weight);
    destruct(this_object());
}


query_value() {
    return amount_of_fuel/100 + 1;
}

get() { return 1; }

set_long_lit(str) { long_lit_desc = str; }
set_long_unlit(str) { long_unlit_desc = str; }
