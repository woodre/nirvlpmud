inherit "/obj/treasure.c";

id(str) { return str == "quest21n";}

drop() { destruct(this_object()); return 1; }
