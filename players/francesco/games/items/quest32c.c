inherit "/obj/treasure.c";

id(str) { return str == "quest32c";}

drop() { destruct(this_object()); return 1; }

