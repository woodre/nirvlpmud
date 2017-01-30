/*
 *  The blade ability to fix a blade. (v2.0)
 *
 */

fix_blade(str)  {

  object ob;
  string qual;

  ob = present(str, this_player());
    if(!ob) ob = present(str, environment(this_player()));
      if(!ob)  {
      write("You cannot find the "+str+".\n");
      return 1;
        }

  if(ob->weapon_class() > 1)  {

  ob->fix_weapon();
  write("You repair the "+ob->short()+".\n");
  say(tp+" repairs the "+ob->short()+".\n");
  return 1;
        }

  write("This is not a weapon.\n");
  return 1;
        }
