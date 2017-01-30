id(str) { return str == "rose"; }
reset() {}
long() { write("It's a red rose. A present from Hurtbrain. :)\n"); }
short() { return "A red rose"; }
get()  { return 1; }
drop() { write("As you drop it, the rose vanishes in the air\n"); destruct(this_object()); return 1; }
