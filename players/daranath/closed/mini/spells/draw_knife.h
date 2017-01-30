/*
 *  The blade ability to get a dueling knife.  (v2.0)
 *
 */

draw_knife()  {

  object ob;

  if(present("blade_knife", this_player()))  {
    write("You slide your dueling knife into it's sheath.\n");
    say(tp+" slides "+POSS+" dueling knife into it's sheath.\n");
    ob = present("blade_knife", this_player());
    destruct(ob);
  return 1;
        }

  move_object(clone_object("/players/saber/closed/new_mini/blade_knife.c"),this_player());
  write("You withdraw your dueling knife and twirl it between your fingers.\n");
  say(tp+" withdraws "+POSS+" dueling knife and twirls it between "+POSS+" fingers.\n");
  return 1;
        }
