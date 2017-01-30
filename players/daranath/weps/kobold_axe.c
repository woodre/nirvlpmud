 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("axe");
    set_alias("kobold axe");
    set_short("A double handed battle axe");
    set_long("The double handed battle axe is covered in blood, both old\n"+
             "and new. The wooden shaft looks chewed upon in several\n"+
             "places. It is a deadly weapon.\n");
    set_class(14);
    set_weight(2);
    set_value(300);
}
