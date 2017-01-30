short() { return 0; }
long() { return 0; }
id(str) { return str == "logger pack"; }
get() { return 1; }
drop() { destruct(this_object()); return 0; }
