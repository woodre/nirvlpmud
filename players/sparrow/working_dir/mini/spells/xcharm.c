/*
 *  The ability of Succubi (version 2.0) to charm a creature away from
 *    their hostile ways...  ;)
 *
 */

xcharm(str)  {

  object ob;

  if(spell(-2000,1,25) ==-1)  return 0;

  if(!str)  {
    write("Try to charm who?\n");
    return 1;
        }

  ob = present(str, environment(this_player()));

  if(!ob)  {
    write(CAP+" is not here for you to charm.\n");
    return 1;
        }

  if(!living(ob))  {
    write("You want to try to charm a "+str+"...?\n");
    return 1;
        }

  write("\nYou place your hand lightly upon "+CAP+" and ask "+
    ob->query_objective()+":\n");

  say(tp+" places her hand lightly upon "+CAP+" and asks "+
    ob->query_objective()+":\n");

  tell_room(environment(TP), "    Will you *please* stop fighting...?\n\n");

  ob->stop_fight();
  ob->stop_fight();
  ob->stop_hunter();
  TP->stop_fight();
  TP->stop_fight();
  TP->stop_hunter();

  call_other(this_player(), "add_spell_point", -25);

  tell_room(environment(this_player()), CAP+" stops fighting.\n\n");
  return 1;
        }
