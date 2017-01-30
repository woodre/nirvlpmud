
string amount_of_fuel;
string name;
status is_lighted;
int weight;

long() {
   write("This orb has been enhanced with the powers of light.\n");
   write("To use its magic, you must 'illuminate orb'.\n");
}

reset(arg) {
    if (arg)
        return;
    amount_of_fuel = 4000; name = "orb"; is_lighted = 0; weight = 1;
}

set_weight(w) { weight = w; }

query_weight() { return weight; }

short() {
  if (is_lighted)
return "Orb of light (glowing)";
return "Orb of light";
}

set_name(n) { name = n; }
set_fuel(f) { amount_of_fuel = f; }

init() {
    add_action("light", "illuminate");
}

light(str) {
    if (!str || str != name)
        return 0;
    if (is_lighted) {
        write("It is already illuminating the powers of light!\n");
        return 1;
    }
    is_lighted = 1;
    call_out("out_of_fuel", amount_of_fuel * 2);
    if (set_light(10) == 10) {
        write("You can see clearly again.\n");
        say(call_other(this_player(), "query_name") +
            "'s " + name + " glows vigorously!\n");
    } else
        write("The Orb of light glows vigorously!\n");
    amount_of_fuel = 0;
    return 1;
}

out_of_fuel() {
    object ob;
    if (set_light(-1) == 0)
        say("There is darkness as the " + name + "'s energy is depleted.\n");
    else
        say("The " + name + " fades away.\n");
    ob = environment(this_object());
    if (living(ob))
        call_other(ob, "add_weight", -weight);
    destruct(this_object());
}

id(str) {
    return str == name;
}

query_value() {
    return 1250;
}

get() { return 1; }

drop() {
write("The orb vanishes with a soft flash of light as you drop it.\n");
say("A glowing orb vanishes with a soft flash of light as " +this_player()->
query_name() + " drops it.\n");
destruct(this_object());
return 1;
}
