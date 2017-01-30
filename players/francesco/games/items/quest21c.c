inherit "/obj/treasure.c";

id(str) { return str == "quest21c";}

drop() { destruct(this_object()); return 1; }

