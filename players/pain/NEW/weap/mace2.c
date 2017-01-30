inherit "players/pain/NEW/weap/p_weap.c";
int i;
reset(arg) {
   ::reset(arg);
   if(arg) return;
	set_name("mace");
      	set_alias("mace");
	set_short("A huge iron mace");
	set_long("A large, surprisingly wieldy iron orc mace.\n");
	set_class(18);
	set_weight(3);
	set_value(2500);

      set_hit_func(this_object());
}
weapon_hit(attacker) {
  i=random(10);
  if (i>6) {

	say(this_player()->query_name()+"'s mace hits "+attacker->query_name()+
	    " with a sickening thud!\n");
	write("You swing your mace hard and it lands with a crushing blow.\n");
  return random(5)+2;
    }
   return 0;
}
