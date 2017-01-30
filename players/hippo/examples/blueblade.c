int w;
 inherit "obj/weapon.c";
 reset(arg) {
    ::reset();
    if (arg) return;
   set_name("blueblade");
    set_alias("blade");
    set_short("A blue blade of fire");
    set_long("A long, thin blade forged from prue blue fire.\n");
    set_class(15);
    set_weight(2);
    set_value(700);
    set_hit_func(this_object());
}
weapon_hit(attacker){
   w=random(10);
   if (w>6) {
 say("The blue blade of fire blazes a trail of fury through its foe.\n"+
  "You smell something burning.\n");
  write("The blue blade of fire blazes a trail of fury through its foe.\n"+
  "You smell something burning.\n");
return 5;
    }
    return;
}
