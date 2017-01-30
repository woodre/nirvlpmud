  inherit "obj/weapon.c";
  reset(arg) {
    ::reset(arg);
    if (arg) return;
     set_name("revenant blade");
    set_alias("blade");
    set_short("Revenant Blade");
    set_long("A blade forged from the vitality of it's maker.\n"+
           "It cleaves through your soul.\n");
    set_class(16);
    set_weight(3);
    set_value(800);
    set_hit_func(this_object());
 }
  weapon_hit(attacker){
  int W;
 W = random(12);
  if(W > 9)  {
   say("The revenant blade sends a spectral charge through its foe.\n"+
      "You feel the fear of the enemy.\n");
    write("The revenant blade sends a spectral charge through its foe.\n"+
   "You feel the fear of your enemy.\n");
  return 5;
      }
     return;
 }
