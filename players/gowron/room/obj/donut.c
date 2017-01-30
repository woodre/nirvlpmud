int donuts;
id(str) { return str == "donuts"; }
long() { 
	write(format("A box of donuts..  Probably came from the "
	             +"Headquarters of the Springfield Police Dept.\n"+
		      "There are "+donuts+" left.\n", 75)); 
	} 
query_value() { return 100*donuts; }
short() { return "A box of donuts"; }
query_weight() { 
	if (donuts < 3) 
	   return 1;
	if (donuts < 6)
           return 2;
	if (donuts < 8)
           return 3;
	else
	   return 4;
}
query_save_flag() { return 1; }
get() { return 1; }
drop() { return 0; }
reset(arg) {
	if (arg) return;
	donuts = 4;
}
init() {
	add_action("eat_donut", "eat");
}
eat_donut(str) {
	if (!str)
	   return 0;
	if (!(str == "donut"))
	   return 0;
	if (!this_player()->eat_food(14)) 
	   return 0;
	this_player()->heal_self(40+random(7));
        donuts--;
	write("Donuts... is there anything they can't do?\n");
	write("		-Homer J. Simpson\n");
	if (donuts == 0) {
	   write("You ate the last one...\n");
	   destruct(this_object());
	}
	else
	   write("There are "+donuts+" left.\n");
	return 1;
}
