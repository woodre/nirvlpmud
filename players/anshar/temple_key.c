inherit "/obj/treasure";
short() { return "A shiny key"; }
long() { write(" A small shiny key to the temple.\n");}
id(str) { return str == "key" || str == "temple_key"; }
