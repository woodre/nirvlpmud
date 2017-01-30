inherit "/obj/treasure.c";

id(str) { return str == "quest32n";}

drop() { destruct(this_object()); return 1; }

