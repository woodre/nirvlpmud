inherit "obj/weapon";
int i;
reset(arg) {
   ::reset(arg);
   if(arg) return;
      set_alias("bow");
	set_short("A beautiful longbow (handmade)");
	set_long("A suprisingly beautiful bow!\n");
	set_class(18);
	set_weight(3);
	set_value(1000);
	set_name("bow");

      set_hit_func(this_object());
}
weapon_hit(attacker) {
  i=random(10);
  if (i>6) {

   say(this_player()->query_name()+" drives an arrow into your very soul\n");
	write("You severly wound your oppenant with your bow.\n");
  return 1;
    }
   return 0;
}
