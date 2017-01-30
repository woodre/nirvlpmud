inherit "/obj/treasure.c";

id(str) { return str == "quest11n";}

drop() { destruct(this_object()); return 1; }

