    inherit "obj/treasure";
      object fun;
    reset (arg) {
            if(arg) return;
            set_id("becomer");
            set_short("becomer");
            set_long("Become <str>  or revert <str>.\n");
            set_weight(1);
            set_value(0);
    }
        init() {
        ::init();
        add_action("become","become");
        add_action("revert","revert");
        }
become(str) {
        if(!str) {
        write("Become what?\n");
        return 1;
                }
        if(fun) {
write("You are already shadowed.  Revert if you want to change.\n");
return 1;
}
write("You become "+capitalize(str)+".\n");
say(this_player()->query_name()+
"'s form starts to melt and reshape into the likeness of "
+capitalize(str)+".\n");
    fun=clone_object("players/deathmonger/ASSASSIN/sh.c");
   fun->target_shadow(this_player());
   fun->set_boggle(str);
   return 1;
}
revert() {
write("You turn to normal.\n");
say(this_player()->query_name()+" reverts back to normal.\n");
   write("Ok.\n");
   fun->remove_target();
   return 1;
}
