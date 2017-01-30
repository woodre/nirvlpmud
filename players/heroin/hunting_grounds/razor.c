inherit "obj/weapon";
int i;
reset(arg) {
   ::reset(arg);
   if(arg) return;
set_name("razor");
      set_alias("razor");
	set_short("A straight razor");
	set_long("You know a razor-need a shave?\n");
	set_class(18);
	set_weight(3);
	set_value(1000);

      set_hit_func(this_object());
}
weapon_hit(attacker) {
  i=random(100);
if (i>5) {

	say(this_player()->query_name()+"'s feels so good..ya might want to do more than trim whiskers\n");
	write("You look ammazingly like zorro-OUCH.\n");
  return 2;
    }
   return 0;
}
