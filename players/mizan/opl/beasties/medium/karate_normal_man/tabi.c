inherit "obj/armor";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_short("A pair of white tabi boots");
    set_long("    This is a lightweight pair of tabi boots, made of some canvas\n"+
    "  type of material. They seem comfortable enough, but their protective\n"+
    "  value remains to be seen...\n");
    set_ac(0);
    set_weight(2);
    set_value(800);
    set_name("tabi");
    set_type("boots");
}
