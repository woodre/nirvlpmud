inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("sword of speed");
  set_alias("short sword");
  set_short("A silvered sword");
  set_long("A small, light sword. It hums with power.\n");
  set_class(16);
  set_weight(8);
  set_value(200);
  set_hit_func(this_object());
}

weapon_hit(attacker){
int X;
X = random(10);
if(X>8)  {
  say("The sword leaps to attack again.\n");
  write("The sword leaps to attack again.\n");
  hit(attacker);
  this_player()->attack();
  return;
  }
}