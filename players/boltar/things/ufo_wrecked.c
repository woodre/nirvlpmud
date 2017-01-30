inherit "obj/container";

int c,lid;
object table,abducted;

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_long("This is a classic 1950s silver disc shaped flying saucer.\n"+
             "(Think of a small version of the one from The day the\n"+
             "earth stood still.) There is a large window in the front and\n"+
             "three chairs in a triangle shape. (think cylons in the\n"+
             "original battlestar galatica series) There is a medical\n"+
             "medical table in the back of the ship and a hatch.\n"+
             "It's horribly wrecked, with half of it blown apart.\n");
	set_short("A silver colored disc shaped craft (WRECKED)");
	set_name("flying disc");
	set_weight(30000);
	set_max_weight(50);
	set_value(12);
        lid = 1;
    }
}
