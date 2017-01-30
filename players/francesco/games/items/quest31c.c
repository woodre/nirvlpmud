inherit "/obj/treasure.c";

id(str) { return str == "quest31c";}

drop() { destruct(this_object()); return 1; }

