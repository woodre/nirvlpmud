inherit "/obj/treasure";
short() { return "A small key"; }
long() { write("     A small key to the house.\n"); }
id(str) { return str == "key" || str == "house_key"; }
