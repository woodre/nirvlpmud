inherit "/obj/treasure.c";

id(str) { return str == "quest31n";}

drop() { destruct(this_object()); return 1; }

