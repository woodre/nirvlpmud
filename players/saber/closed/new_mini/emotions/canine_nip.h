c_nip(str) {
object ob;
 if(!str)  {
write("You knaw on your ankle.\n");
say(tp+" chews on "+POSS+" ankle.\n");
  return 1;
   }
  ob = present(str,environment(this_player()));
   str = capitalize(str);
   if(!ob) { write("Nip at who?\n");
     return 1;   }
write("You dance around "+CAP+" and nip at "+POS2+" ankle.\n");
say(tp+" dances around the room nipping at "+CAP+"'s ankle.\n");
tell_object(ob, tp+" lopes around your feet and nips at your ankles!\n");
  return 1;
       }
