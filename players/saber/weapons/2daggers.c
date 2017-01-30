 inherit "obj/weapon.c";
 reset(arg) {
   ::reset(arg);
    if (arg) return;
      set_name("two daggers");
    set_alias("daggers");
    set_type("dagger");		/* set type added by Pavlik */
   set_alt_name("dagger");
      set_short("A pair of daggers");
      set_long("A pair of sharp steel daggers.\n");
    set_class(12);
    set_weight(2);
    set_value(150);
}
