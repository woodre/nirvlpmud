 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

set_name("Scimitar");
set_alias("scimitar");
set_short("Blackened scimitar");
set_long("The blade of this weapon has been burnished and scratched with a coal\n"+
         "like substance, so the blade does not reflect any light.\n");
set_class(16);
set_weight(2);
set_value(850);
}
