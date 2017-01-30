inherit "obj/clean";

id(str) {
   return str == "book" || str == "book of swords";
}

short() { return "Book of Swords"; }

get() { 
   return 1;
}

init() {
   add_action("page","page");
}


page(str) {
   cat("/players/sandman/paladin/book/"+str);
   return 1;
}
