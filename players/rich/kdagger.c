inherit "obj/weapon.c";

  reset(arg) {
   ::reset(arg);
      set_name("klingon dagger");
      set_alias("dagger");
      set_short("A klingon Dagger");
      set_long("A three pronged knife that looks as if it was meant to kill.\n");
      set_value(30);
      set_weight(2);
      set_class(5);
      set_hit_func();
weapon_hit() {
   if (call_other(environment(this_player()), "query_realm")=="enterprise") {
    write("You watch as your blade splits into three prongs,\n");
    write("and slams deep into your opponent!!!\n");
    return 7;
  }
 }
