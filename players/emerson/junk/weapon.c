inherit "obj/weapon.c";
reset(arg) {
    ::reset();
    if (arg) return;
    set_name("knife");
    set_alias("sword");
    set_short("A Carving Knife");
    set_long("A large sharp carving knife used for carving people\n");
    set_class(20);
    set_save_flag(0);
    set_weight(3);
    set_value(155000);
    set_hit_func(this_object());
}
weapon_hit(attacker){
   if(call_other(this_player(), "query_attrib", "str") > random(30)) {
      write("You start to slice up your foe like a Sunday Roast.\n");
      write("The Blade of the knife slices deeply into your opponent.\n");
      attacker->hit_player(15);
      return 1;
   }
   return;
}
