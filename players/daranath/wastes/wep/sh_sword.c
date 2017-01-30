 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

set_name("sword");
set_alias("short");
set_short("A short sword");
set_long("Well used and poorly maintained, this short sword might be worth\n"+
         "a couple of coins to someone.\n");
set_class(11);
set_weight(1);
set_value(75);
}
