inherit "/obj/weapon.c";
int i;
reset(arg) {
  ::reset(arg);
   if(arg) return;
   set_name("carbine");
   set_alias("carbine");
   set_short("A .50 caliber carbine");
   set_long("A lethal Chinese made .50 caliber carbine.\n");
   set_type("club");
   set_class(17);
   set_weight(3);
   set_value(1000);
   
   set_hit_func(this_object());
}
weapon_hit(attacker) {
   i=random(10);
   if (i>6) {
      
      say(this_player()->query_name()+"'s carbine hits hard!\n");
      write("You swing your carbine hard and jamming the butt against your enemy.\n");
      return random(10)+5;
   }
   return 0;
}
