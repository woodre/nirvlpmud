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
	set_type("staff");
	weaponDesc = "A well made staff, an inch in diameter and six feet in length, has been\n"+
		"carved from a solid material, and is extremely smooth.  Swirls of blue\n"+ 
		"and green dance along the staff's length, while flecks of sparkling\n"+ 
		"white glimmer brightly around it.";
}