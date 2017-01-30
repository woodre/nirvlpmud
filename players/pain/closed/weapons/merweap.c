inherit "obj/weapon";
int i;
reset(arg) {
   ::reset(arg);
   if(arg) return;
      set_alias("blade");
	set_short("A Blade of Suffering");
   set_long("This weapon makes women weep and men cower in shame, it is a blade of suffering\n"+
   "It is a widowmaker, a very powerful weapon when wielded properly.\n");
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
	write("You strike fear in the heart of your opponent with your terrifying weapon of Destruction.\n");
  return 1;
    }
   return 0;
}
