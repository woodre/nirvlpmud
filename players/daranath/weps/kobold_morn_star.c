 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("star");
    set_alias("kobold morning star");
   set_alt_name("morning star");
    set_short("A wicked morning star");
   set_long("A wooden club with spikes protruding from one end of it.\n");
    set_class(10);
    set_weight(2);
    set_value(350);
}
