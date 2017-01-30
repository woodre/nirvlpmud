inherit "/obj/treasure";
short() { return "A merchant key"; }
long() { write("     A small merchant key to the shop's back door.\n"); }
id(str) { return str == "key" || str == "merchant_key"; }
