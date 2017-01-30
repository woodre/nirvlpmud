 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

set_name("sword");
set_alias("bastard");
set_short("A massive bastard sword");
set_long("A huge bastard sword, most races would need two hands just to wield\n"+
     "the weapon, much less use it during a fight.\n");
set_class(17);
set_weight(2);
set_value(350);
}
