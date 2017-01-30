/* Emotions for Bards */

scarf(str)  {
object ob;

 if(!str)  {
  write("You conjure a scarf from thin air.\n"+
     "  Aren't hidden pockets wonderful?\n");
  say(tp+" conjures a scarf from thin air.\n");
  return 1;
        }

 ob = present(str,ENV);

  if(!ob)  {
    write(CAP+" is not here.\n");
    return 1;
        }

  write("You conjure a scarf from behind "+CAP+"'s ear.\n"+
     "  Aren't hidden pockets wonderful?\n");
  say(tp+" conjures a scarf from behind "+CAP+"'s ear.  Wow!\n",ob);
  tell_object(ob, tp+" conjures a scarf from behind your ear.\n"+
     "  Hay, where did that come from?\n");

  return 1;
        }
