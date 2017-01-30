inherit "/obj/treasure";
short() { return "A gold key"; }
long() { write("     A gold key, that might be of some value.\n"); }
id(str) { return str == "key" || str == "gold_key"; }
