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
	set_type("sword");
	weaponDesc = "A finely crafted sword, a keen blade of the most superb steel extends\n"+ 
		"four feet from the beautifully adorned grip and pommel.  Swirls of\n"+ 
		"blue and green dance along the sword, while flecks of sparkling white\n"+
		"glimmer brightly.";
}