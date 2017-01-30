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
	set_type("pike");
	weaponDesc = "The pike, made from a straight lengthy rod is smooth and unblemished.\n"+  
		"In several places along its length, straps of leather are wrapped\n"+ 
		"around it to form handholds, and at its tip, an axe-like blade is\n"+ 
		"attached with tightly tied hemp.  The curved blade has several notches\n"+
		"along its wide sweeping arch, and the very end of it holds a sharp\n"+ 
		"point.  Blue and green swirls spiral up the weapon as white dust seems\n"+ 
		"to flutter about the weapon.";
}