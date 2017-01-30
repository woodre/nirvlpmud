inherit "obj/weapon";
int i;
reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_name("wooden mug");
      set_alias("mug");
    set_short("A Wooden Mug");
  set_long("A large, heavy, wooden mug, with a rope handel.\n");
set_read("Olaf's wood products\n");
	set_class(7);
	set_weight(1);
	set_value(100);

      set_hit_func(this_object());
}
weapon_hit(attacker) {
  i=random(10);
  if (i>5) {

	say(this_player()->query_name()+"'s mug hits suprisingly hard!\n");
	write("You hit hard with your mug.\n");
  return 1;
    }
   return 0;
}
