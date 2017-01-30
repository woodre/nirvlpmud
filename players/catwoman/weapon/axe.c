inherit "obj/weapon";



reset(x) {
  ::reset(x);
  if (!x) {
    set_name("axe");
    set_alias("axe");
    set_short("A bloody axe");
    set_class(15);
    set_value(1200);
    set_weight(3);
    set_hit_func(this_object());
  }
}

weapon_hit(attacker) {
	string align;
	write("The axe cuts deep and blood squirts everywhere.\n");
	say("You see a hunk of flesh go flying by.\n SPLAT the flesh hits the ground.\n");
	return 1;
}


