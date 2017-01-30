inherit "obj/weapon.c";
reset(arg){
object sword;
       set_name("Grimdale...The Shadowsword...");
      set_alias("sword");
set_short("Grimdale...The Shadowsword...");
       set_long("A Large Dark Misty Sword with Red Decore...\n"+
              "There is a Slight Mist around the Blade...\n");
      set_class(18);
      set_weight(4);
      set_value(9000);
      set_hit_func(this_object());
}
weapon_hit(attacker)
{
int n;
n =random(10);
if(n>6){
       write("The Sword Slices the Air leaving a Trail of Dark Mist....\n");
return n-3;
}
return 0;
}
