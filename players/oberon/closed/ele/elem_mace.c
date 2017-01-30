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
	set_type("mace");
	weaponDesc = "A large, spherical mass of metal, this mace looks quite menacing.  Its\n"+
		"round head is covered in vicious looking pointed triangular spikes and\n"+ 
		"its three foot long metal shaft has a carved wooden handle and studded\n"+
		"grip.  Swirls of blue and green flow up and down the mace; glimmering\n"+ 
		"white flecks twinkle about it.";
}