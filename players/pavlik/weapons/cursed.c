inherit "obj/weapon";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_alias("sword");
  set_type("sword");
  set_name("a longsword");
  set_short("Longsword");
  set_long(
	"This is the famous blade of the Bengal.  Its cold steel"+
	"blade slides willing into the life of it's oppenent.\n");
  set_class(16);
  set_weight(1);
  set_value(600);
  set_hit_func(this_object());
}

weapon_hit(attacker) {
  int i;

  i = random(50);

  if (i>33) {
	say(this_player()->query_name()+" slips and cuts themself with thier own sword!\n");
	write("You slice the enemy to pieces with this awesome weapon!\n");
	this_player()->heal_self(-random(10));
  }
  return 0;
}

