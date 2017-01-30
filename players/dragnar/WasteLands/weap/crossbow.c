inherit "obj/weapon";

void
reset(int arg) {
    ::reset(arg);
    if (arg) return;
    set_name("crossbow");
    set_alias("bow");
    set_short("Crossbow");
    set_long(
"The bow is pure black with black arrows; the only other color is\n"+
"the silver from the deadly tips of the arrows.\n");
    set_class(15);
    set_value(1000);
    set_weight(3);
}
