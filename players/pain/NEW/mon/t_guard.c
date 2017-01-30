inherit "obj/monster";

reset(arg)
{
  object weapon, armor;
  ::reset(arg);
  if(arg) return;
	set_name("guard");
	set_race("human");
	set_alias("guard");
	set_short("A Town Guard");
	set_long("The Town Guard watches over the various shops and people\n"+
		"of Bigelow. He is a proud man and is happy to help his\n"+
		"fellow citizens. He wears the colors of Bigelow, and the\n"+
		"blue tunic looks quite dashing indeed.\n");
	set_level(18);
	set_hp(300+random(200));
	set_al(-150);
	set_aggressive(0);
	armor = clone_object("players/pain/NEW/arm/tunic.c");
	move_object(armor,this_object());
	init_command("wear tunic");
	set_wc(26);
        set_ac(15);
}
