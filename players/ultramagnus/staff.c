inherit "obj/weapon.c";
reset(arg){
object staff;
       set_name("staff");
      set_alias("staff");
       set_short("An Old Long Staff");
       set_long("An Old Long Staff...\n"+
              "It looks very firm...\n");
      set_class(16);
      set_weight(3);
      set_value(5000);
      set_hit_func(this_object());
}
weapon_hit(attacker)
{
int n;
n =random(10);
if(n>6){
   write("The Staff Sparkles in your Hands...!!\n");
return n-3;
}
return 0;
}
