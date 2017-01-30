 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("spear");
    set_alias("silver spear");
    set_short("A shining silver spear"),
    set_long("Light flashes off the hilt of the spear as you look upon\n"+
             "it. The silver of the blade gleams sharply making it look\n"+
             "more dangerous then it truely is.\n");
    set_class(17);
    set_weight(3);
    set_value(2200);
}
