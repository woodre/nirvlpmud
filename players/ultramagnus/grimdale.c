inherit "obj/weapon.c";
reset(arg){
object sword;
       set_name("Grimdale...The Shadowsword...");
      set_alias("sword");
set_short("Grimdale...The Shadowsword...");
       set_long("A Large Dark Misty Sword with Red Decore...\n"+
              "There is a Slight Mist around the Blade...\n");
      set_class(15);
      set_weight(2);
      set_value(8000);
      set_hit_func(this_object());
}
weapon_hit(attacker)
{
int n;
n =random(5);
if(n>3){
       write("The Sword Slices the Air leaving a Trail of Dark Mist....\n");
return n;
}
return 0;
}
