 /* new_mark.c */
#define TP this_player()

id(str) { return str == "new_mark"; }
short() { return 0; }
long() { return 1; }
get() { return 0; }

reset(arg) {
   if(arg) return;

}

init() {
   add_action("new_mark", "new");
}

new_mark() {
   object new, old;
   string dum, dummer;
   old = present("shadow-mark", TP);
   if(!old) {
      write("What?  You don't have a shadow-mark!\n");
      return 1;
   }
   if(sscanf(file_name(old), "%s/testshadow%s", dum, dummer) == 2) {
      write("You already have a new mark.\n");
      return 1;
   }
   new = clone_object("/players/blue/closed/shadow/testshadow.c");
   if(!new) return 0;
   new->set_shxp_me(old->query_shadow_xp());
   new->set_shpoints(old->query_shpoints());
   write("You will have to reset your monitor and your drain.\n");
   destruct(old);
   move_object(new, TP);
   return 1;
}
