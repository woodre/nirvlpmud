 inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
   set_name("spiked club");
    set_alias("club");
    set_type("club");         /* set type added by Pavlik */
   set_short("A spiked wooden club");
   set_long("A large wooden club with sharp metal spikes\n");
    set_class(12);
    set_weight(3);
    set_value(150);
}
