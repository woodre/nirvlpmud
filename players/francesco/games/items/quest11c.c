inherit "/obj/treasure.c";

id(str) { return str == "quest11c";}

drop() { destruct(this_object()); return 1; }

