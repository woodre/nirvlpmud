/* Emotions for Bards */

sing1(str)  {
object ob;

  if(!str)  {
  write("You sing part of an old Irish love ballad.\n");
  say(tp+" sings part of an old Irish love ballad.\n"+
    "  You covertly wipe away a single tear.\n");
  return 1;
        }

  ob = present(str,ENV);

    if(!ob)  {
    write(CAP+" is not here to sing to.\n");
    return 1;
        }

  write("You sing "+CAP+" part of an old Irish love ballad.\n");
  say(tp+" sings "+CAP+" part of an old Irish love ballad.\n"+
    "  You covertly wipe away a single tear.\n",ob);
  tell_object(ob, tp+" sings you part of an old Irish love ballad.\n"+
    "  Your heart fills with longing.\n");

  return 1;
        }
