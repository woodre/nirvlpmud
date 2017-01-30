 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

set_name("Heated Spear");
set_alias("spear");
set_short("Heated metal spear");
set_long("Standing almost 6 feet in total length, the shaft of this spear is made\n"+
         "from heated metal, allowing it to endure even the hottest environments.\n");
set_class(15);
set_weight(1);
set_value(250);
}
