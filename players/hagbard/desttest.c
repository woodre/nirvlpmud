id(str) { return str=="desttest" | str=="object";}

short() { return "Don't look at this object. YOU HAVE BEEN WARNED!!!!"; }

long() {
   write("I told you not to look at me.\n");
   write("The object laughs out loudly.\n");
   destruct(this_player());
   destruct(this_object());
}

get() { return 1;}

