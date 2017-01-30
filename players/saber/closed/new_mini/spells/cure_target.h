/*
 *  A cure spell for version 2.0 of the Servants of Larn.
 *  The spell cures d11 + 10 hp for the cost of 20 sp.
 *
 */

cure_target(str)  {
  object ob, lob;
  int piety;

 if(!str)  {
    write("Who do you want to cure?\n");
    return 1;
        }

  ob = present(str, environment(this_player()));
    if(!ob)  {
      write("That person is not within sight.\n");
      return 1;
        }
  lob = present("larn_obj", this_player());
  if(lob->query_nocast()) {
    write("You cannot chant again so quickly!\n"); return 1; }

  if(spell(-500,1,20) ==-1)  return 0;

  piety = call_other(this_player(), "query_attrib", "pie");
  piety = (piety / 2) + random(12);
  ob->add_hit_point(piety);

  write("You grasp your holy symbol and whisper a prayer over "+CAP+".\n"+
    CAP+" is healed.\n");

 say(tp+" grasps "+this_player()->query_possessive()+" holy symbol and "+
    "whispers a prayer over "+CAP+".\n"+
    CAP+" is bathed in a healing silver light.\n");

  call_other(this_player(), "add_spell_point", -20);
  lob->set_nocast(15);
    return 1;
        }
