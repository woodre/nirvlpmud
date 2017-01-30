c_bump(str) {
object ob;
 if(!str)  {
  return 1;
   }
  ob = present(str,environment(this_player()));
   str = capitalize(str);
   if(!ob) { write("Bump who?\n");
     return 1;   }
write("You slowly walk up to "+CAP+" and bump "+POSS+" with your head.\n");
say(tp+" slowly walks up to "+CAP+" and bumps into "+POSS+" leg!\n");
tell_object(ob, tp+" slowly walks up to you and bumps your leg with "+POSS+" head!\n");
  return 1;
       }
