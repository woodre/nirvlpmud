c_tail(str) {
object ob;
 if(!str)  {
write("You wag your tail.\n");
say(tp+" wags "+POSS+" tail.\n");
  return 1;
   }
  ob = present(str,environment(this_player()));
   str = capitalize(str);
   if(!ob) { write("Who??\n");
     return 1;   }
write("You stand next to "+CAP+" and beat them with your tail.\n");
say(tp+" stands next to "+CAP+" and swats them with "+POSS+" tail!\n");
tell_object(ob, tp+" runs around at your feet swatting you with "+POSS+" tail!\n");
  return 1;
       }
