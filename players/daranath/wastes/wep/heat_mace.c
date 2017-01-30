 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

set_name("Heated Mace");
set_alias("mace");
set_short("Heated metal heavy Mace");
set_long("Created of the same process the metal spear was, the mace is immune\n"+
         "to the heat decaying effects of the lava in the area.\n");
set_class(17);
set_weight(2);
set_value(650);
}
