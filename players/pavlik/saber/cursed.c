int w;
 inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("crystal sword");
    set_alias("sword");
    set_type("sword");         /* set type added by Pavlik */
    set_short("The Crystal sword");
    set_long("The crystal sword of Nu Nuth.\n");
    set_class(17);
    set_weight(2);
    set_value(700);
    set_hit_func(this_object());
}
weapon_hit(attacker){
   w=random(10);
   if (w>6) {
  say("The crystal sword breaks!\n");
  write("Your sword breaks!\n");
  call_other(this_object(), "weapon_breaks", 1 );
  return 1;
    }
    return;
}
