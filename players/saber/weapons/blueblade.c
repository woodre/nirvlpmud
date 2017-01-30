inherit "obj/weapon.c";

reset(arg) {
  ::reset(arg);
  if (arg) return;
  set_name("blueblade");
  set_alias("blade");
  set_type("sword");         /* set type added by Pavlik */
  set_short("A blue blade of fire");
  set_long("A long, thin blade forged from pure blue fire.\n");
  set_class(15);
  set_weight(2);
  set_value(700);
  /* hit changed to fire type by illarion in Dec 2004
  set_hit_func(this_object());
*/
  set_params("other|fire",0,"fire_hit");
}
fire_hit(attacker){
  if (random(10)>6) {
    say("The blue blade of fire blazes a trail of fury through its foe.\n"+
    "You smell something burning.\n");
    write("The blue blade of fire blazes a trail of fury through its foe.\n"+
    "You smell something burning.\n");
    return 5;
  }
}
