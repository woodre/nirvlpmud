 inherit "obj/weapon.c";
  reset(arg) {
    ::reset(arg);
    if (arg) return;
      set_name("longknife");
    set_alias("knife");
    set_short("A longknife");
    set_long("A knife with a very long blade.\n");
    set_class(15);
    set_weight(2);
    set_value(450);
 }
