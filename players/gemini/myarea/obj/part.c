string part, name, owner, short, long, alias, alt_name;
string eating_mess, eater_mess;
int value, strength, weight;

reset(arg) {
    if (!arg) {
	weight = 1; 
	eater_mess = "You eat the body part, left here by a Tron warrior.\n";
	part = "penis";
	name = "some little boy";
	owner = "Michael Jackson";
    }
}

init() {
    add_action("eat", "eat");
}

id(str) {
    return  str == part || str == alt_name || str == alias || str == "head";
}

#if 0
prevent_insert() {
    write("You don't want to ruin " + short + ".\n");
    return 1;
}
#endif

short() { 
    if (!short)
	return "The "+part+" of "+name+" sliced off by a Tron warrior named: "+owner+"";
    return short;
}

long() {
    if (!long)
	return short() + ".\n";
    else
	return long;
}

get() { return 1; }

eat(str) {
    object tp;

    if (!str || present(str) != this_object())
	return 0;

    tp = this_player();
    if (tp->query_level() * 8 < strength) {
	write("\
You realize even before trying that you'll never be able to eat all this.\n");
	return 1;
    }
    if (!tp->eat_food(strength))
	return 1;
    tp->heal_self(5);

    write(eater_mess);
    if (eating_mess)
	say(this_player()->query_name() + eating_mess);
    else
	say(this_player()->query_name()+" gobbles "+(short ? short : name)+".\n");
    destruct(this_object());
    return 1;
}

min_cost() {
    return 4 * strength + (strength * strength) / 10;
}

set_name(n) { 
    name = n; }

set_short(s) { 
    short = s; }

set_long(l) { 
    long = l; }

set_value(v) { 
    value = v; }

set_weight(w) { 
    weight = w; }

set_strength(s) {
    strength = s; }

set_alias(a) { 
    alias = a; }

set_alt_name(an) { 
    alt_name = an; }

set_eating_mess(em) { 
    eating_mess = em; }

set_eater_mess(em) { 
    eater_mess = em; }

set_part(p){
  part = p; }
set_owner(o){
  owner = o; }
/*
 * Things that other objects might want to know.
 */

query_weight() { 
    return weight; }

query_value() { 
    if (value)
	return value; 
    else
	return min_cost();
}



