 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

set_name("blade staff");
set_alias("staff");
set_alt_name("bladestaff");
set_short("Bladestaff");
set_long("Half quarterstaff, half longsword, the Bladestaff is a combination slashing\n"+
         "and bludgeoning weapon. It takes a great amount of skill to use\n"+
         "it properly.\n");
set_class(17);
set_weight(1);
set_value(650);
}
