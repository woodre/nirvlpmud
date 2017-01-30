inherit "obj/weapon";
int i;
reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_name("wooden tray");
      set_alias("tray");
    set_short("A Wooden Tray");
  set_long("A large, heavy, wooden tray, with a rope handel.\n");
set_read("Olaf's wood products\n");
	set_class(7);
	set_weight(2);
	set_value(100);

      set_hit_func(this_object());
}
weapon_hit(attacker) {
  i=random(10);
  if (i>5) {

    say(this_player()->query_name()+"'s tray hits hard!\n*THUNK!*\n");
	write("You hit hard with your tray.\n");
  return 1;
    }
   return 0;
}
