shed(str)  {
object ob;
 if(!str)  {
  write("You meander about the room, shedding excess fur everywhere.\n");
  say(tp+" meanders about the room, shedding excess fur everywhere.\n");
  return 1;
   }
  ob = present(str,environment(this_player()));
   str = capitalize(str);
   if(!ob) { write("Shed on who?\n");
     return 1;   }
  write("You rub up against "+CAP+", covering "+OOBJ+" with fur.\n");
  say(tp+" rubs up against "+CAP+", covering "+OOBJ+" with fur.\n",ob);
  tell_object(ob, tp+" rubs up against you, covering you with fur.\n");
  return 1;
       }
