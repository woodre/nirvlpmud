inherit "/obj/treasure.c";

id(str) { return str == "quest22c";}

drop() { destruct(this_object()); return 1; }

