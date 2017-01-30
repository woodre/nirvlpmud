id(str) { return str == "wand of wonder" || str == "wand"; }

short() {
   return "Wand of Wonder";
}

long() {
   write("This is a slim metalic wand that gives off a greenish hue.\n");
}

get() {
   return 1;
}

init() {
   add_action("wave","wave");
}

wave(str) {
   string target;
   int i;
   if(!str || sscanf(str, "at %s", target) == 1) {
      write("Usage: wave at <monster>\n");
      return 1;
   }
   if(!present(target)) {
      write(capitalize(target) + "is not here.\n");
      return 1;
   }
   i = random(11);
   if(i == 1) {
