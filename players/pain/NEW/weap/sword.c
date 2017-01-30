inherit "players/pain/NEW/weap/p_weap.c";
int i;
reset(arg) {
   ::reset(arg);
   if(arg) return;
      	set_alias("sword");
	set_short("A steel sword");
	set_long("A rather handy steel sword from Bigelow.\n");
	set_class(15);
	set_weight(3);
	set_value(1000);
	set_name("sword");

      set_hit_func(this_object());
}
weapon_hit(attacker) {
  i=random(10);
  if (i>6) {

	say(this_player()->query_name()+"'s sword hits hard!\n");
	write("You swing your sword hard and it lands with a hard blow.\n");
  return random(3)+1;
    }
   return 0;
}
