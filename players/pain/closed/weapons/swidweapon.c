inherit "obj/weapon";
int i;
reset(arg) {
   ::reset(arg);
   if(arg) return;
      set_alias("ego");
	set_short("Swid's HUGE ego");
	set_long("A suprisingly HUGE ego!\n");
	set_class(18);
	set_weight(3);
	set_value(1000);
	set_name("Swid's EGO");

      set_hit_func(this_object());
}
weapon_hit(attacker) {
  i=random(10);
  if (i>6) {

	say(this_player()->query_name()+"'s ego envelopes you making you feel much weaker!\n");
	write("You hit hard with your Monsterous EGO.\n");
  return 1;
    }
   return 0;
}
