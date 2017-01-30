/*
 *  The gypsy curse ability.  (v2.0)
 *
 */

curse(str)  {
  object ob, check_ob;
  int temp, temp1, temp2, ac, wc;

  if(!str)  {
    write("What do you want to curse?\n");
    return 1;
        }

  ob = present(str, environment(TP));

  if(!ob)  ob = present(str, TP);
  if(!ob)  {
    write("There is no "+CAP+" here to curse.\n");
    return 1;
        }

  if(spell(-3000,1,20)  == -1)  return 0;

  if(ob->is_player())  {
    say("\n"+tp+" invokes a Gypsy curse upon "+CAP+".\n\n");
    write("You invoke a Gypsy curse upon "+CAP+".\n\n");
    tell_object(ob, "\nYou feel very strange.\n");
    return 1;
        }

  if(!living(ob))  {
    temp2 = ob->query_weight() + random(6);
    temp1 = ob->weapon_class() - random(6);
    temp  = ob->armor_class()  - random(3);
    call_other(ob, "set_class" , temp1);
    call_other(ob, "set_ac"    , temp );
    call_other(ob, "set_weight", temp2);
    write("You call upon your Gypsy powers to curse the "+CAP+".\n"+
      "\nThe "+CAP+" has been cursed!\n");
    say(tp+" whispers strange invocations over the "+CAP+".\n");
    call_other(TP, "add_spell_point", -20);
    return 1;
        }

  if(ob->query_npc())  {
  if(present("gypsy_curse", ob))  {
      write("The "+CAP+" has already been cursed...\n");
      return 1;
        }
    write("You cast a curse upon "+ob->short()+".\n"+
      ob->short()+" has been cursed...\n");
    say(tp+" casts a Gypsy curse upon the "+ob->short()+".\n"+
     "\n"+ob->short()+" looks pale.\n");
    tell_room(environment(TP),
      ob->short()+" holws in pain and attacks "+tp+".\n");
    if(living(ob))  ob->attack_object(TP);
    temp  = ob->query_ac() - 1;
    temp1 = ob->query_wc() - 1;
    ob->set_ac(temp);
    ob->set_wc(temp1);
    check_ob = clone_object("/players/saber/closed/new_mini/gypsy_curse.c");
    move_object(check_ob, ob);
    call_other(TP, "add_spell_point", -20);
    return 1;
        }

  write("You curse the "+CAP+".\n");
    say(tp+" curses the "+CAP+".\n");
    return 1;
        }
