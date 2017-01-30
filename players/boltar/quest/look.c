look(str) {
   if (!str) {
   return 0;
  }
  if (str == "at nook" || str == "in nook"){
   write("You see a small point of light reflect back at you.\n");
   return 1;
  }
return 0;
}
