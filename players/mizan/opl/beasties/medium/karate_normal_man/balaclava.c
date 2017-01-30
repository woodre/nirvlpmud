inherit "obj/armor";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_short("A white balaclava facemask");
    set_long("This is a loose-fitting cotton facemask designed for use in basic ninja\n"+
    "training operations and bank robberies. It has three cutouts for the eyes\n"+
    "and appears comfortable, but smells like rotting potatoes for some reason.\n");
    set_ac(0);
    set_weight(1);
    set_value(400);
    set_name("balaclava");
    set_alias("facemask");
    set_type("helmet");
}
