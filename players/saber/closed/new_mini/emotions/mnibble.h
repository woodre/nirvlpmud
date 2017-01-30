nibble(str)  {
object ob;
 if(!str)  {
  write("You nibble on your tail.\n");
  say(tp+" nibbles on "+POSS+" tail.\n");
  return 1;
   }
  ob = present(str,environment(this_player()));
   str = capitalize(str);
   if(!ob) { write("Nibble on who?\n");
     return 1;   }
  write("You nibble with your little kitty teeth upon "+CAP+".\n");
  say(tp+" nibbles with "+POSS+" little kitty teeth upon "+CAP+".\n",ob);
  tell_object(ob, tp+" nibbles with "+POSS+" little kitty teeth upon you.\n");
  return 1;
       }
