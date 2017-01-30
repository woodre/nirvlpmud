int w;
 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("silver short sword");
    set_alias("short sword");
    set_type("sword");
    set_short("A silver short sword");
    set_long("The silver short sword is an exquisite weapon of both\n"+
             "high value and fighting quality.\n");
    set_class(15);
    set_weight(2);
    set_value(700);
    set_hit_func(this_object());
}
weapon_hit(attacker){
   w=random(10);
   if (w>6) {
  say("The silver short sword cuts deeply into its foe.");
  write("The silver short sword cuts deeply into your foe.");
return 2;
    }
    return;
}
