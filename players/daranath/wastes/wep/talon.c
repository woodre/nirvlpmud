 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

set_name("Eagle talon");
set_alias("talon");
set_short("Giant Eagle's talon");
set_long("The talon of the giant eagle that lives in the vicinity of the\n"+
         "Gundar Plateau, it would make an excellent weapon.\n");
set_class(16);
set_weight(1);
set_value(750);
}
