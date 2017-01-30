c_growl(str) {
object ob;
 if(!str)  {
write("You growl!\n");
say(tp+" growls!\n");
  return 1;
   }
  ob = present(str,environment(this_player()));
   str = capitalize(str);
   if(!ob) { write("Growl at who?\n");
     return 1;   }
write("You bare your teeth and growl at "+CAP+"!\n");
say(tp+" turns "+POSS+" attention to "+CAP+" and viciously growls at "+POS2+"!\n");
tell_object(ob, tp+" growls viciously at you!!!\n");
  return 1;
       }
