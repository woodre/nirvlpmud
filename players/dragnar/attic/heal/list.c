id(str) { return str=="list"; }
reset() {}
short() {
	return "A list of items";
}
long() {
	write("Type read list to see the healing items and what they do.\n");
}
init() {
	add_action("read","read");
}
read(str) {
	if(str=="list") {
	write("This is a list of items available at Dragnar's shop in the wastelands:\n\n"+
"1. magical healer -> lets you set the hit points, and when your hit points\n"+
"		fall below that number you are healed automatically.\n"+
"2. pack of healing -> lets you set the hit points and then it heals you\n"+
"		that amount randomly every round.\n"+
"3. pitcher of cisco -> full heal\n"+
"4. fire water -> alcohol healing\n"+
"5. 12 pack bud -> alcohol healing\n"+
"6. 12 pack beast -> alchohol healing\n"+
"7. vodka -> alcohol healing\n"+
"8. hotdog -> saturation healing\n"+
"9. snapple -> thirst healing\n"+
"10. hamburger -> heals 25 with no intox,saturation, or thirst\n"+
"11. double burger -> heals 50 with no intox,saturation, or thirst\n"+
"12. coffee -> anti-intox\n"+
"13. speed -> anti-satiation\n"+
"14. pretzels -> anti-thirst\n"+
"15. can of beer -> single serving of alcohol healing\n\n"+
"NOTE: If something is more expensive it either heals you more or\n"+
"gives you less intox than something less expensive.  Hope you enjoy\n"+
"the products, any ideas mail dragnar. Wastelands are s,5e,3n,2w from church.\n");
	return 1;
	}
}
get() { return 1; }
