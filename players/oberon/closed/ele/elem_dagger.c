/* This sword is gained by completing the Elemental Test at extreme risk of death
 * if this weapon seems powerful for that, please try out the test. - Snow
 * changed everything to Damage Types [5.25.01] Vertebraker
 *
 * Changed by Oberon - 10.26.2016
 * - Merged Elemental weapons into elem_wep.c
 * - Individual files kept for backward compatability and for resource management.
*/
inherit "/players/oberon/closed/ele/elem_wep.c";
reset(arg) {
	::reset(arg);
	set_type("dagger");
	weaponDesc = "Barely a foot in length, this keen edged dagger is a beautiful work of\n"+
		"art.  The blade, fattened and serrated is a attached to a well crafted\n"+
		"grip and a spiked handguard.  Swirls of blue and green dance along the\n"+ 
		"dagger's form, and sparkling white flecks glimmer brightly about it.";
}