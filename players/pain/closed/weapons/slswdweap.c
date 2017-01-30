inherit "obj/weapon";
int i;
reset(arg) {
   ::reset(arg);
   if(arg) return;
      set_alias("blade");
	set_short("A Blade of Terror");
	set_long("A terrifying looking weapon... it strikes terror in the hearts of your enemies\n");
	set_class(18);
	set_weight(3);
	set_value(300);
	set_name("Blade of Terror");

      set_hit_func(this_object());
}
weapon_hit(attacker) {
  i=random(10);
  if (i>6) {

	say(this_player()->query_name()+"'s blade whistles through the air towards " + this_player()->query_attacker() + "!\n");
	write("You terrify your opponent with your frightning weapon of Death.\n");
  return 1;
    }
   return 0;
}
