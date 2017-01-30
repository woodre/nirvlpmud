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
	set_type("axe");
	weaponDesc = "A suberbly crafted weapon, the twin blades of the axe are perfectly\n"+ 
		"symmetrical, each curving smoothly with a razor sharp edge.  A thick\n"+ 
		"three and a half foot handle joins the two blades together, while a\n"+ 
		"strap of leather is wound around the base as a grip.  Swirls of blue\n"+ 
		"and green dance along the axe, while flecks of sparkling white\n"+ 
		"glimmer brightly around it.";
}