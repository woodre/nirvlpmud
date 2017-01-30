 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

set_name("Scimitar");
set_alias("scimitar");
set_short("Glowing scimitar");
set_long("The blade of this scimitar glows of its own willpower, sheding light\n"+
         "within the area of effect.\n");
set_class(17);
set_weight(2);
set_value(900);
}
