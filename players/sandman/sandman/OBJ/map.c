id(str) { return str == "map" || str == "old map"; }

short() {
   return "An old map";
}

long() {
   write("It looks to be an old dusty map, maybe you could read it.\n");
}

init() {
   add_action("read","read");
}

read(str) {
   if(str == "map") {
      cat("/players/sandman/OBJ/maptxt1");
      return 1;
   }
}

get() {
   return 1;
}
