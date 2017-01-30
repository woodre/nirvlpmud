/* Emotions for Bards */

sparkle(str)  {
object ob;

  if(!str)  {
  write("You look up with a "+HIY+BOLD+"sparkle"+NORM+" in your eyes.\n");
  say(tp+" looks up with a "+HIY+BOLD+"sparkle"+NORM+" in "+POSS+" eyes.\n");
  return 1;
        }

  ob = present(str, ENV);

    if(!ob)  {
    write(CAP+" is not here to look at.\n");
    return 1;
        }

  write("You look up at "+CAP+" with a "+HIY+BOLD+"sparkle"+NORM+" in your eyes.\n");
  say(tp+" looks up at "+CAP+" with a "+HIY+BOLD+"sparkle"+NORM+" in "+POSS+" eyes.\n",ob);
  tell_object(ob, tp+" looks up at you with a "+HIY+BOLD+"sparkle"+NORM+" in "+POSS+" eyes.\n");
  return 1;
        }
