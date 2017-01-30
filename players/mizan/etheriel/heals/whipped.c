inherit"obj/food";
reset(arg) {
::reset(arg);
if(!arg) {
	set_name("can");
	set_short("A can of whipped cream");
	set_eater_mess("FZZZZZZZZZOOHHHHT! (Most people don't eat whipped cream straight...)\n");
	set_eating_mess(" jets himself with a dosage of whipped cream!\n");
	set_strength(2);
	}
}
