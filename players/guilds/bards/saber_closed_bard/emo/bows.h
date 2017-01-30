/* Emotions for Bards */

bows(str)  {
object ob;

  if(!str)  {
  write("You make an elaborate bow.\n");
  say(tp+" makes an elaborate bow.\n");
  return 1;
        }

  ob = present(str,ENV);

    if(!ob)  {
    write(CAP+" is not here to bow to.\n");
    return 1;
        }

  write("You make an elaborate bow to "+CAP+".\n");
  say(tp+" makes an elaborate bow to "+CAP+".\n",ob);
  tell_object(ob, tp+" makes an elaborate bow to you.\n");
  
  return 1;
        }
