/* Emotions for Bards */

handkiss(str)  {
object ob;

  if(!str)  {
  write("Whose hand do you want to kiss?\n");
  return 1;
        }

  ob = present(str,ENV);

    if(!ob)  {
    write(CAP+" is not here to have their hand kissed.\n");
    return 1;
        }

  write("Bowing slightly, you kiss "+CAP+"'s hand.\n");
  say(tp+" bows slightly, takes the hand of "+CAP+" and kisses it lightly.\n",ob);
  tell_object(ob, tp+" bows slightly, takes your hand and kisses it lightly.\n");

  return 1;
        }

