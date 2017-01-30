inherit "/obj/treasure";
short() { return "A small key"; }
long() { write("     A small key to the castle door.\n"); }
id(str) { return str == "key" || str == "castle_key"; }
