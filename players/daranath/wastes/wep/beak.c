 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

set_name("Beak of the Pheonix");
set_alias("beak");
set_short("Shiny black metal beak");
set_long("The dark metallic beak of a legendary Pheonix, this object has the\n"+
         "myth of drawing other Pheonix to it, once it was taken from a kill.\n"+
         "Just having it in your presence is always a risky proposition.\n");
set_class(18);
set_weight(1);
set_value(2000);
}
