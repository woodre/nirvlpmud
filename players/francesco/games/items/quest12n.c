inherit "/obj/treasure.c";

id(str) { return str == "quest12n";}

drop() { destruct(this_object()); return 1; }
