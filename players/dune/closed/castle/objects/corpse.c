inherit "obj/clean";


id(str) { return str == "corpse" || str == "gnome" || str == "body"; }
get() { return 1; }
drop() { return 0; }
query_weight() { return 10; }
query_value() { return 0; }

short() { return "A freshly killed corpse"; }

long() { write(
"     The corpse is of a rather well-built gnome. A mace in the head\n"+
"must have done the trick. Whatever killed it did so swiftly and with\n"+
"no mercy. Besides, the gnome does not seem of the fighter type.\n"+
"The gnome seems to be a commoner, perhaps hunting for dinner.\n"); }
