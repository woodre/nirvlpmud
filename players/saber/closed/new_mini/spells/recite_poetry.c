/*
 *  The poetry command of the goths.  (v2.0)
 *
 */

recite_poetry(str)  {

  if(!str)  {
    write("What would you like to recite?\n");
    return 1;
        }

  tell_room(environment(this_player()), "\n"+tp+" recites\n\n"+
     "    \""+str+"\"\n\n");
  return 1;
        }
