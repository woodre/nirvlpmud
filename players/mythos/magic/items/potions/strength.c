/* example potion - strength */

inherit "players/mythos/magic/potion";

reset(arg) {
	::reset(arg);
	if(arg) return;
	name = "strength";
	handle = "potion of strength";
	alias = "strength potion";
	charges = 1;
	maxcharges = 1;
	weight = 2;
	value = 250;
	weightchange = 1;
	chargeshowshort = 0;
	short_desc = "A Potion of Strength";
	long_desc = "A clear liquid swirls around in the flask.\n"+
	            "This potion will increase your strength temporarily.";
	msg1 = "You drink the potion of strength.";
	msg2 = "drinks a potion.";
}

effect() {
  tell_object(user,"You feel stronger.  You think your blows against an enemy will do more damage.\n");
  move_object(clone_object("/players/mythos/magic/items/potions/str_ob.c"),user);
return 1;}