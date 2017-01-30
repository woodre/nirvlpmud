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
	set_type("hammer");
	weaponDesc = "The hammer is a simple, yet deadly weapon.  Its long, slightly curved\n"+ 
		"wooden handle passes through a large cube of stone.  The head of the\n"+    
		"hammer is perfectly smooth on all sides, and is held in place by a\n"+
		"metal wedge.  Swirls of blue and green dance up and down the leather\n"+
		"clad handle of the hammer, and white flecks twinkle about its length.";
}