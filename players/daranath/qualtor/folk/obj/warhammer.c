int w;
 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

set_name("heavy warhammer");
set_alias("warhammer");
set_type("warhammer");
set_short("A heavy warhammer");
set_long("A massive warhammer, it almost seems too heavy to be an\n"+
         "effective weapon.\n");
set_class(14);
set_weight(1);
set_value(150);
}
