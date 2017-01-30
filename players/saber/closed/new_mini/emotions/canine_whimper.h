c_whimper(str) {
object ob;
 if(!str)  {
write("You whine.\n");
say(tp+" whines.\n");
  return 1;
   }
  ob = present(str,environment(this_player()));
write("You look into "+CAP+"'s eyes and whine.\n");
say(tp+" looks up at "+CAP+" and whines.\n");
tell_object(ob, tp+" looks at you with "+POSS+" puppy dog eyes and begins to whine.\n");
  return 1;
       }
