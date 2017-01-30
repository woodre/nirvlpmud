inherit "obj/weapon";
int i;
reset(arg) {
   ::reset(arg);
   if(arg) return;
      set_alias("sword");
      set_short("A duck sword");
  set_long("This sword is made of pure bone honed with fine detail.\n");
      set_class(13);
      set_weight(4);
      set_value(852);
      set_name("A Duck Sword");
      set_hit_func(this_object());
}
weapon_hit(attacker) {
   i=random(20);
   if (i<9) {
say(this_player()->query_name()+" smashes down his opponent with a quack!\n");
   write("You smash down your opponent with a quack!\n");
   }
   return 3;
}
