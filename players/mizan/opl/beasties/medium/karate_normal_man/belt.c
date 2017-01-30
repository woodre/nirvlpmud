inherit "obj/armor";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_short("A red canvas belt");
    set_long("    This is a simple canvas belt. It is meant to be tied around the\n"+
    "  waist as there is no buckle or clasp holes. A label on the back face of\n"+
    "  belt prominently reads: 'Made in China'.\n");
    set_ac(0);
    set_weight(1);
    set_value(300);
    set_name("belt");
    set_type("belt");
}
