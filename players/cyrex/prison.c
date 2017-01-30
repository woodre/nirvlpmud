short() {
   return "Cyrex's prison";
}

long() {
   write("You are in Cyrex's prison.\n");
   write("There is no escape.\n\n");
}

reset(arg) {
   if (arg)
      return;
   set_light(1);
}

init() {
   add_action("quit"); add_xverb("");
}

quit(){
if(this_player()->query_real_name() != "cyrex")
      {
      long();
      write("You are not permitted to do that action here.\n");
      return 1;
   }
   return 0;
}
