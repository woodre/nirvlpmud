 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

set_name("Heated Sword");
set_alias("sword");
set_short("Heated metal sword");
set_long("Created of the same process the metal spear was, the sword is immune\n"+
         "to the heat decaying effects of the lava in the area.\n");
set_class(16);
set_weight(1);
set_value(450);
}
