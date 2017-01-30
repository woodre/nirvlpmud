/* This sword is gained by completing the Elemental Test at extreme risk of death
 * if this weapon seems powerful for that, please try out the test. - Snow
 * changed everything to Damage Types [5.25.01] Vertebraker
 *
 * Changed by Oberon - 10.26.2016
 * - Merged Elemental weapons into elem_wep.c
 * - Individual files kept for backward compatability and for resource management.
*/
inherit "/players/snow/closed/test/elem_wep.c";
reset(arg) {
	::reset(arg);
	set_type("whip");
	weaponDesc = "A metallic looking cord of six feet or so is attached to a foot long\n"+
		"handle of metal.  The thick cord splits at the end, and each strand is\n"+
		"tipped with a razor sharp barb.  Blue and green streaks swirl the\n"+ 
		"length of the whip, while white dots glimmer around it.";
}