inherit "/obj/treasure.c";

reset (arg) {
	set_id("blood");
	set_short("Lizard's blood");
	set_long(
      "  Some of the life-force of the lizards of the Durkor cavern.\n"+
      "The lizards are very poisonous but for some reason their blood\n"+ 
      "is not tainted.\n");
      set_weight(1);
      set_value(1000);
}

