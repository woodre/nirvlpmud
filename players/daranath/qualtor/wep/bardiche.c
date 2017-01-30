int w;
 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("bardiche");
    set_alias("battleaxe");
    set_type("axe");
    set_short("A wicked bardiche");
    set_long("The bardiche is a two handed poleaxe that was used mainly\n"+
             "by the guardsmen before Qual'tors fall.\n");
    set_class(16);
    set_weight(3);
    set_value(1200);
    set_hit_func(this_object());
}
weapon_hit(attacker){
   w=random(10);
   if (w>6) {
  say("The bardiche cuts deeply into its foe.");
  write("The bardiche cuts deeply into your foe.");
return 4;
    }
    return;
}
