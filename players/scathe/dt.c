inherit "obj/weapon";
string owner;

reset(arg){
   if(arg) return;
   ::reset(arg);
   set_name("storm bolter");
   set_alt_name("storm");
   set_alias("storm");
   set_short("Storm Bolter");
   set_long("This lightweight piece of hardware is the chosen weapon of all\n"+
      "marines, but only a few are worthy enough to hold one.\n");
   set_class(17);
   set_hit_func(this_object());
   set_weight(4);
   set_value(3000);
}
weapon_hit(attacker){
   if(random(10) < 3){
      say("Following fire!\n");
      write("Following FIRE!\n");
      if(attacker->query_hp()>40){
         attacker->hit_player(random(7));
      }
      this_player()->add_hit_point(-5);
   }
   if(random(100) < 30){
      write("Feel those explosive shells fly baby!\n");
      say("Explosive rounds rip and fly about the room.\n");
      return 7;
   }
}
