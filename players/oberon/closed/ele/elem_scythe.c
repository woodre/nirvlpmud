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
	set_type("scythe");
	weaponDesc = "A long, wicked-looking blade is strapped to a gnarled woodend handle.\n"+
		"The serrated blade holds a razor edge, while midway down the handle's\n"+
		"length, a short metal extension has been strapped to make swinging this\n"+
		"vicious weapon easier.  White flecks flicker about the weapon, and\n"+ 
		"swirls of blue and green dance up and down its form.";
}