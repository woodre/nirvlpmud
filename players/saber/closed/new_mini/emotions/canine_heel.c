c_heel(str) {
object ob;
 if(!str)  {
write("You sit down and pant.\n");
  return 1;
   }
  ob = present(str,environment(this_player()));
   str = capitalize(str);
   if(!ob) { write("Heel to?\n");
     return 1;   }
write("You sit at "+CAP+"'s left side.\n");
say(tp+" sits at "+CAP+"'s left side.\n");
tell_object(ob, tp+" sits at your left side and eyes the room!\n");
  return 1;
       }
