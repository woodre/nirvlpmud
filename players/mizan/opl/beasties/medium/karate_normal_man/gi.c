inherit "obj/armor";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_short("A white gi of the Karate Normal School");
    set_long("    This is a thick white, heavy cotton training gi for students of the\n"+
    "  infamous Karate Normal School. While its protective value when in a dojo\n"+
    "  is undisputed, you wonder whether this would be of any practical use in a\n"+
    "  typical life or death fight.\n");
    set_ac(2);
    set_weight(2);
    set_value(800);
    set_name("gi");
    set_type("armor");
}
