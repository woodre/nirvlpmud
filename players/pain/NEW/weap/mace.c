inherit "players/pain/NEW/weap/p_weap.c";
int i;
reset(arg) {
   ::reset(arg);
   if(arg) return;
      	set_alias("mace");
	set_name("mace");
	set_short("A large iron mace");
	set_long("A large, surprisingly wieldy iron orc mace.\n");
	set_class(16);
	set_weight(3);
	set_value(1000);

      set_hit_func(this_object());
}
weapon_hit(attacker) {
  i=random(10);
  if (i>6) {

	say(this_player()->query_name()+"'s mace hits suprisingly hard!\n");
	write("You swing your mace hard and it lands with a crushing blow.\n");
  return random(4)+1;
    }
   return 0;
}
