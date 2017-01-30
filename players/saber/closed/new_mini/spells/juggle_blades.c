/*
 *  The blade juggle ability of the blades.  (v2.0)
 *
 */

juggle_blades(str)  {
  string blade1, blade2, blade3;
  object BLADE1, BLADE2, BLADE3;
  string BLADE;
  int i, bad_count;

  if(present("blade_twirl", this_player()))  {
    write("You stop juggling your weapons.\n");
    say(tp+" stops juggling "+POSS+" weapons.\n");
    BLADE1 = present("blade_twirl", this_player());
    destruct(BLADE1);
    return 1;
        }

  if(!str || sscanf(str, "%s %s %s", blade1, blade2, blade3) !=3)  {
    write("What weapons do you want to juggle?\n"+
          "Syntax: juggle_blades <blade> <blade> <blade>\n");
    return 1;
        }

  if(spell(-3000,1,25) ==-1) return 0;

  BLADE1 = present(blade1, this_player());
  BLADE2 = present(blade2, this_player());
  BLADE3 = present(blade3, this_player());

  if(!BLADE1 || !BLADE2 || !BLADE3)  {
    write("You don't have a "+blade1+", a "+blade2+" and a "+blade3+".\n");
    return 1;
        }

  for(i=0; i<2; i++)  {
  object ob;
  if(i == 0)  ob = BLADE1;
  if(i == 1)  ob = BLADE2;
  if(i == 2)  ob = BLADE3;

  if(ob->weapon_class() < 1)  {
  write("The "+ob->short()+" is not a blade.\n");
  bad_count = bad_count + 1;
        }

  i++;
        }

  if(bad_count > 1)  {
    write("\nYou need three weapons to juggle.\n");
    return 1;
        }

  say("\n"+
    tp+" begins to juggle "+BLADE1->short()+"\n"+
    tp+" begins to juggle "+BLADE2->short()+"\n"+
    tp+" begins to juggle "+BLADE3->short()+"\n");
  write("\n"+
    "You begin to juggle "+BLADE1->short()+"\n"+
    "You begin to juggle "+BLADE2->short()+"\n"+
    "You begin to juggle "+BLADE3->short()+"\n");

  BLADE = clone_object("/players/saber/closed/new_mini/blade_switch.c");
  BLADE->set_one(BLADE1->query_name());
  BLADE->set_two(BLADE2->query_name());
  BLADE->set_three(BLADE3->query_name());
  move_object(BLADE, this_player());

  call_other(this_player(), "add_spell_point", -25);
  return 1;
        }

