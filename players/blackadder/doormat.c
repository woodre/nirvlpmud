reset(arg) {
}

long(str) {
   if (str == "feet") {
      write("They look a bit muddy to me!\n");
      return;
   }
   write("A floor mat with the word WELCOME emblazoned upon it.\n");
}

short() {
   return "A doormat";
}

init() {
   add_action("wipe","wipe");
}

wipe(str) {
   if (!id(str))
      return 0;
   write("The mat says: Thank you for fulfilling my purpose in life!\n");
   return 1;
}
id(str) {
   return str == "feet" || str == "doormat" || str == "mat";
}

