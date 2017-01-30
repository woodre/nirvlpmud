inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("halberd");
  set_alias("pole arm");
  set_short("A large halberd");
  set_long("Silvered and bright, this weapon has a heavy axe-like head attached\n"+
    "to a long pole. The deadly edge gleams menacingly.\n");
  set_class(17);
  set_weight(4);
  set_value(200);
  set_hit_func(this_object());
}

weapon_hit(attacker){
int X;
X = random(10);
if(X>8)  {
  say("The heavy blade cuts deeply into its opponent.\n");
  write("The heavy blade cuts deeply into its opponent.\n");
return 2;
  }
}