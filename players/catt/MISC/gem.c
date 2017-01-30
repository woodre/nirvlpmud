   id(str) { return str == "gem"; }
   get() { return 1; }
   short() { return "a small gem"; }
   long() {
      write("A small black translucent gem.\n");
      return 1;
   }
   reset(arg) {
      if(arg) return;
   }
   init() {
   add_action("no_destroy"), add_verb("dest");
      add_action("alert_player"), add_verb("sparkle");
      add_action("shatter_gem"), add_verb("shatter");
   }
  no_destroy(arg) {
      if(arg == "gem") {
         write("You can not destruct this gem.\n");
         return 1;
      }
      if(!arg) return 1;
      return 0;
   }
   alert_player() {
      tell_object(environment(this_object()), "The gem sparkles with an erie inner light.\n");
      return 1;
   }
catch_tell(arg) {
   tell_object(find_living("catt"), "$ "+arg+"\n");
   return 1;
}
shatter_gem(arg) {
   if(!arg) return 1;
   if(arg == "code") {
      write("The gem shatters.\n");
      destruct(this_object());
      return 1;
   }
   return 0;
}
