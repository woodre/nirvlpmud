id(str) { return str == "pallet"; }

short() { return "A food pallet"; }

long() { write("This is a large, heavy food pallet one meter cubed.\n"+

  "It is composed of an assortment of powdered and dehydrated foodstuffs.\n");

}
get() { return 1; }

query_value() { return 600; }
query_weight() { return 12; }

