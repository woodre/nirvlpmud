inherit "obj/weapon.c";
reset(arg){
      set_name("Troll Axe");
      set_alias("axe");
      set_short("axe");
      set_class(10);
      set_weight(3);
      set_value(800);
      set_hit_func(this_object());
}
weapon_hit(attacker)
{
int n;
n =random(10);
if(n<4){
write("The axe slices through you body...!..leaving a trail of blood...!!!\n");
return n;
}
return 0;
}
