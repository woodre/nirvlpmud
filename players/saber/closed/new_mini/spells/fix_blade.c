/*
 *  The blade ability to fix a blade. (v2.0)
 *
 */

fix_blade(str)  {

  object ob;
  string qual;

  if(this_player()->query_money() < 800){
    write("You don't have the money to pay 800 coins?\n"+
          "Loser.\n");
    return 1;
  }
  if(!str) { write("Fix what ? \n"); return 1; }
  ob = present(str, this_player());
    if(!ob) ob = present(str, environment(this_player()));
      if(!ob)  {
      write("You cannot find the "+str+".\n");
      return 1;
        }

  if(ob->weapon_class() > 1)  {

  this_player()->add_money(-800);
  ob->fix_weapon();
  write("You repair the "+ob->short()+".\n");
  say(tp+" repairs the "+ob->short()+".\n");
  return 1;
        }

  write("This is not a weapon.\n");
  return 1;
        }
