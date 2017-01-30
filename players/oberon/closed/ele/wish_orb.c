/*
 * Changed by Oberon - 10.26.16
 * Changed the weapon cloning to handle new elem_wep.c
*/
inherit "/obj/treasure.c";

#define LOC "/players/oberon/closed/ele/"
#if 0
#define LOC "/players/snow/closed/test/"
#endif

reset() {
	set_id("orb");
	set_alias("orb of wishes");
	set_short("Orb of Wishes");
	set_long("\n\tYou gaze upon the fabled Orb of Wishes.\n"+
		"It is a small spherical object seemingly made of coherent quicksilver.\n"+
		"As you peer into it, a voice echoes in your mind:\n\n"+
		"\tYou, valiant one, may wish for any of the following:\n\n"+
		"\tWeapons:\n"+
		"\taxe, sword, hammer, mace, staff, dagger, whip, pike, spear,\n"+
		"\tscepter, or scythe.\n\n"+
		"\tArmors:\n"+
		"\tamulet, helm, gauntlets, boots, cloak, neckguard, shorts, ring,\n"+
		"\tbelt, earring, or shield.\n\n"+
		"\tMisc:\n"+
		"\tcoins, or experience.\n\n"+
		"\tDo this by commanding: wish <choice>.\n"+
		"\tYou have one wish. Choose well.\n\n");
	set_weight(1);
}

init() {
	::init();
	add_action("do_wish","wish");
}

do_wish(string str) {
	object ob;
	if(!str) {
		notify_fail("..*.. wish <axe, sword, hammer, mace, dagger, whip, staff, pike, spear,\n"+
					"            scepter, scythe, armor, coins, or experience>\n");
		return 0;
	}
	write_file("/players/snow/closed/test/prizes", ctime(time())+" "+this_player()->query_real_name()+" "+str+"\n");
	if(str != "axe" && str != "sword" && str != "amulet" && str != "coins" && 
		str != "experience" && str != "mace" && str != "hammer" && str != "dagger" && 
		str != "whip" && str != "staff" && str != "pike" && str != "spear" && 
		str != "scepter" && str != "scythe" && str != "boots" && str != "helm" &&
		str != "shield" && str != "cloak" && str != "neckguard" && str != "gauntlets" &&
		str != "belt" && str != "ring" && str!= "earring" && str!= "shorts"
	) {
		notify_fail("You may wish for an axe, sword, hammer, dagger, staff, mace, whip,\n"+
					"pike, spear, scepter, scythe, amulet, boots, cloak, shield, helm,\n"+
					"gauntlets, neckguard, shorts, ring, belt, earring, coins, \n"+
					"or experience.\n");
		return 0;
	}
	
	if (str == "axe" ||
		str == "dagger" ||
		str == "hammer" ||
		str == "mace" ||
		str == "pike" ||
		str == "scepter" ||
		str == "scythe" ||
		str == "spear" ||
		str == "staff" ||
		str == "sword" ||
		str == "whip"
	) {
		ob = clone_object(LOC+"elem_"+str+".c");
		write("A weapon of might is the reward of your wish!\n");
	}
	
	if(str == "amulet") {
		ob = clone_object("/players/snow/closed/test/amulet.c");
		write("Armor of might is the reward of your wish!\n");
	}
	if(str == "boots") {
		ob = clone_object("/players/snow/closed/test/boots.c");
		write("Armor of might is the reward of your wish!\n");
	}
	if(str == "cloak") {
		ob = clone_object("/players/snow/closed/test/cloak.c");
		write("Armor of might is the reward of your wish!\n");
	}
	if(str == "gauntlets") {
		ob = clone_object("/players/snow/closed/test/gauntlets.c");
		write("Armor of might is the reward of your wish!\n");
	}
	if(str == "shield") {
		ob = clone_object("/players/snow/closed/test/shield.c");
		write("Armor of might is the reward of your wish!\n");
	}
	if(str == "helm") {
		ob = clone_object("/players/snow/closed/test/helm.c");
		write("Armor of might is the reward of your wish!\n");
	}
	if(str == "neckguard") {
		ob = clone_object("/players/snow/closed/test/neckguard.c");
		write("Armor of might is the reward of your wish!\n");
	}
	if(str == "belt") {
		ob = clone_object("/players/snow/closed/test/belt.c");
		write("Armor of might is the reward of your wish!\n");
	}
	if(str == "ring") {
		ob = clone_object("/players/snow/closed/test/ring.c");
		write("Armor of might is the reward of your wish!\n");
	}
	if(str == "shorts") {
		ob = clone_object("/players/snow/closed/test/shorts.c");
		write("Armor of might is the reward of your wish!\n");
	}
	if(str == "earring") {
		ob = clone_object("/players/snow/closed/test/earring.c");
		write("Armor of might is the reward of your wish!\n");
	}
	if(str == "coins") {
		this_player()->add_money(80000);
		write("A fabulous wealth is the reward of your wish!\n");
	}
	if(str == "experience") {
		this_player()->add_exp(100000);
		write("A bonus in experience is the reward of your wish!\n");
	}
	if(ob) move_object(ob, this_player());
	move_object(this_player(), "/players/snow/gate.c");
	command("look", this_player());
	destruct(this_object());
	return 1;
}
