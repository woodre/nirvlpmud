inherit "obj/clean";

id(str) {
   return str == "book" || str == "hymnal";
}

short() { return "A hymnal"; }

long() {
   write("This is an old tome that chronicals the most dire prophesies\n");
   write("of the priesthood of Azrah.\n");
   write("To read type 'page 1' or 'page 2', ect.\n");
}

get() {
   return 1;
}

value() {
   return 100;
}

init() {
   add_action("page","page");
}

page(str) {
   if(str == "1") {
      cat("/players/sandman/OBJ/page1");
      return 1;
   }
   if(str == "2") {
      cat("/players/sandman/OBJ/page2");
      return 1;
   }
   write("No such page\n");
   return 1;
}
