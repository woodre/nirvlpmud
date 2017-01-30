inherit "/obj/treasure";
short() { return "A piece of metal"; }
long() { write("     A piece of metal shaped like a key.\n"); }
id(str) { return str == "key" || str == "metal"; }
