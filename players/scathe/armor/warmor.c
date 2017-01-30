inherit "obj/armor";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_short("Warrior Plate");
    set_long("\
Shiny plate that is very strong, and seems to glow a little, as if\n\
it had an enchantment on it.\n");
    set_ac(4);
    set_weight(3);
    set_value(4000);
    set_name("plate");
    set_type("armor");
}
