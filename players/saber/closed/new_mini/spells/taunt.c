/*
 *  The taunt ability of the kender (version 2.0)
 *  This ability makes an NPC attack the kender.
 *  Because of their fury, their ac is decreased, and their wc is upped.
 *
 */

taunt(str)  {

  object ob;
  int temp, temp1;

  if(!str)  {
    write("Who do you want to taunt?\n");
    return 1;
        }

  ob = present(str, environment(this_player()));
  if(!ob) ob = present(str, this_player());
  if(!ob)  {
    write("There is no "+CAP+" here to taunt.\n");
    return 1;
        }

  if(!living(ob))  {
    say(tp+" makes a funny face at the "+str+".\n"+
      tp+" makes a snide comment about the "+str+".\n");
    write("You make snide comments and silly faces at the "+str+".\n");
    return 1;
        }

  if(ob->is_player())  {
    write("You wonder if "+CAP+" is a bastard, or just a product of selective"+
      " inbreeding...?\n");
    say(tp+" asks "+CAP+" if "+ob->query_pronoun()+" is a bastard...\n"+
      "...or just a product of selective inbreeding...\n", ob);
    tell_object(ob, tp+" asks you if you are a bastard...\n"+
      "...or just a product of selective inbreeding...?\n");

  return 1;
        }

  if(!ob->is_player())  {

    if(present("kender_taunt",ob))  {
      write(ob->short()+" is already pissed off!\n");
      return 1;
        }

    write("You make a silly face at "+CAP+".\n"+
      "You ask "+CAP+" if "+ob->query_pronoun()+" has heard of the concept "+
      "of bathing...?\n");
    say(tp+" asks "+CAP+" if "+ob->query_pronoun()+" has heard of the "+
      "concept of bathing...?\n");
    tell_room(environment(TP), "\n"+CAP+" howls wildly and rushes "+tp+".\n\n");

  if(living(ob))  ob->attack_object(this_player());
    temp = (ob->query_ac()) - 3;
    temp1 = (ob->query_wc()) + 2;
    ob->set_ac(temp);
    ob->set_wc(temp1);
  move_object(clone_object("/players/saber/closed/new_mini/kender_taunt.c"),ob);
  return 1;
        }

  write("You taunt the "+CAP+".\n");
  say(tp+" taunts the "+CAP+".\n");
    return 1;
        }
