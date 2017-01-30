inherit "obj/treasure";
reset(arg){ if(arg) return; }
short(){ return "Blah";}
long(){ return short();}
init(){
  add_action("res", "res");
}
res(str) {
   object victim;
   if (!str) {
      write("Resurrect whom?\n");
      return 1;
   }
   victim = present("ghost of "+str, environment(this_player()));
   if (!victim) {
      write("Your person is not here.\n");
      return 1;
   }
   if (!living(victim) || victim->query_npc()) {
      write("You find you cannot cast your spell on that.\n");
      return 1;
   }
   if(victim->query_hold() == "FAKE") {
     write(str+" is not really dead.\n");
     return 1;
    }
   if (!victim->query_ghost()) {
      write("You cannot cast a resurrection spell on something that is alive.\n"
);
      return 1;
   }
   write("You shudder as the mystical words of the resurrection spell\n"+
      "pass your lips. You feel a rush through you as the spell takes effect.\n"
);
   say(this_player()->query_name() + " focuses a resurrection spell on "+ str+".\n"+
      "You feel powerful forces at play here.\n");
   call_other(victim, "remove_ghost", 0);
   victim->add_exp(victim->query_exp()/6);
   write("Ok.\n");
   return 1;
}
