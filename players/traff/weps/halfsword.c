inherit "obj/weapon";
int i;
reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_name("sword");
      set_alias("blade");
    set_short("A sword");
  set_long(
  "A small sword, yet as you hold it you get a feeling of power\n"+
  "When you think of the Halflings you have heard of, you can feel\n"+
  "the blade pulse in your hand.\n");
  set_read("Halfling's Bane - Forged by Azkar\n");
	set_class(16);
	set_weight(2);
	set_value(1000);

      set_hit_func(this_object());
}
weapon_hit(attacker) {
  if(call_other(attacker,"id","halfling")) {
    say(this_player()->query_name()+"'s blade rips deeply into the Halfling.\n");
    write("Your blade seems to lust for the halfling's blood!\n");
  return 5;
  }
  i=random(10);
  if (i>5) {

	say(this_player()->query_name()+"'s sword hits suprisingly hard!\n");
	write("You hit hard with your sword.\n");
  return 1;
    }
   return 0;
}
