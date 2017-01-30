inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("club");
  set_alias("stone club");
  set_short("A stone club");
  set_long("A huge stone club, it looks very heavy.\n");
  set_class(14);
  set_weight(8);
  set_value(200);
  set_hit_func(this_object());
}

weapon_hit(attacker){
int X;
X = random(10);
if(X>8)  {
  say("The heavy club crushes its opponent.\n");
  write("The heavy club crushes its opponent.\n");
return 4;
  }
}