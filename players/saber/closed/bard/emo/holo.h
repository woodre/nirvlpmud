/* Emotions for Bards */

holo(str)  {
object ob;

  if(!str)  {
  write("You look up with "+BOLD+"dark holocaust eyes"+NORM+".\n");
  say(tp+" looks up with "+BOLD+"dark holocaust eyes"+NORM+".\n");
  return 1;
        }

  ob = present(str,ENV);

    if(!ob)  {
    write(CAP+" is not here to look at.\n");
    return 1;
        }

  write("You look up at "+CAP+" with "+BOLD+"dark holocaust eyes"+NORM+".\n");
  say(tp+" looks up at "+CAP+" with "+BOLD+"dark holocaust eyes"+NORM+".\n",ob);
  tell_object(ob, tp+" looks up at you with "+BOLD+"dark holocaust eyes"+NORM+".\n");

  return 1;
        }
