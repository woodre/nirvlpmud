/*
 * Kept in a separate file so the weapon won't lose its special if saved
 */
#pragma strict_types
inherit "obj/weapon";

void reset(int arg) {
    ::reset(arg);
    if(arg) return;
    set_name("Warrior's Blade");
    set_alias("blade");
    set_short("The Vanquisher");
    set_long("A finely made blade, it is a light weapon that is very sharp.\n");
    set_class(18);
    set_hit_func(this_object());
    set_weight(2);
    set_value(7000);
}

mixed weapon_hit(object opponent) {
    if (random(80) < 20) {
        write("The blade effortlessly glides through your opponent.\n");
        say(this_player()->query_name()+"'s blade blurs as it slashes through its target.\n");
        return 1;
    }
}
