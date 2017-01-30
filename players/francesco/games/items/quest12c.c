inherit "/obj/treasure.c";

id(str) { return str == "quest12c";}

drop() { destruct(this_object()); return 1; }
