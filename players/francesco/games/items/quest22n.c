inherit "/obj/treasure.c";

id(str) { return str == "quest22n";}

drop() { destruct(this_object()); return 1; }

