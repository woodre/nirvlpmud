c_grin(str) {
object ob;
 if(!str)  {
write("You grin, showing your canine fangs.\n");
say(tp+" grins, showing "+POSS+" canine fangs!\n");
  return 1;
   }
  ob = present(str,environment(this_player()));
   str = capitalize(str);
if(!ob) { write("Grin at who?\n");
     return 1;   }
write("You grin at "+CAP+", showing your canine fangs.\n");
say(tp+" grins at "+CAP+", showing "+POSS+" canine fangs.\n",ob);
tell_object(ob, tp+" grins at you, showing "+POSS+" canine fangs.\n");
  return 1;
       }
