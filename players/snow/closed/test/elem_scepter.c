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
	set_type("scepter");
	weaponDesc = "Just over two feet long, a teardrop shaped gem - swirling blue, green,\n"+
		"and white in color - tops a long wooden shaft.  Spriling down it in a\n"+
		"criss cross pattern, metal bands reinforce the scepter, making it a\n"+
		"formidable weapon.  The gem glows with a pulsing energy which sears\n"+
		"the surrounding air.";
}