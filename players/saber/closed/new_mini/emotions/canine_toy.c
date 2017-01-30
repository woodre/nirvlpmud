c_toy(str) {
object ob;
 if(!str)  {
write("You drop your chew toy to the ground.\n");
say(tp+" drops "+POSS+" chew toy to the ground and frowns.\n");
  return 1;
   }
  ob = present(str,environment(this_player()));
   str = capitalize(str);
   if(!ob) { write("No one wants to play with you right now?\n");
     return 1;   }
write("You drop your chew toy at "+CAP+"'s feet and grin.\n");
say(tp+" looks at you and back at the chew toy and whines.\n");
tell_object(ob, tp+" looks at you and back to the chew toy and whines.\n");
  return 1;
       }
