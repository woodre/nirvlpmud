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
	set_type("spear");
	weaponDesc = "Each over a foot from base to tip, two sharp arrow-shaped spearheads\n"+  
		"are attached - one to each end - to a metallic shaft several feet long\n"+ 
		"with thongs of dark leather.  The smooth, conical points look strong\n"+
		"enough to pierce flesh, bone, and armor, while the weapon looks nicely\n"+
		"balanced with the dual spearheads.  Swirls of blue and green move about\n"+ 
		"the spear's span, and white flecks twinkle and shine about it.";
}