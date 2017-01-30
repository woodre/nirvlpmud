/*
 *  The goth ability to dance.  (v2.0)
 *
 */

dance()  {

  object ob;

  if(present("gothic_dance", TP))  {
    write("You decide its just not worth it, and stop dancing.\n");
    say(tp+" looks glum and stops dancing.\n");
    command("remove gothic_dance", this_player());
      ob = present("gothic_dance", TP);
      destruct(ob);
      return 1;
        }

  else  {

  if(spell(-3000,1,20) ==-1)  return 0;

  move_object(clone_object("/players/saber/closed/new_mini/gothic_dance.c"),TP);
  write("You begin to dance slowly.\n");
  say(tp+" begins a slow, spiraling dance.\n");
  command("wear gothic_dance", this_player());
  return 1;
        }
        }
