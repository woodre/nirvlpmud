/*
 *  The blade ability to judge weapons. (v. 2.0);
 *
 */

value_weapon(str)  {

  object ob;
  string qual;

  if(!str) return 0;
  ob = present(str, this_player());
    if(!ob)  ob = present(str, environment(this_player()));
      if(!ob)  {
      write("You do not have a "+CAP+".\n");
      return 1;
        }

  if(spell(-3000,1,20) ==-1) return 0;

  if(ob->weapon_class() > 1)  {
  write(ob->short()+" is worth "+ob->query_value()+" golden coins.\n");
  say(tp+" looks at the "+ob->short()+".\n");
if(ob->weapon_class() > 19)  qual = "is a weapon of godlike power!!";
if(ob->weapon_class() < 20)  qual = "is a superb weapon!";
if(ob-> weapon_class() < 17) qual = "is a deadly weapon!";
if(ob->weapon_class() < 15)  qual = "is an excellent weapon!";
if(ob-> weapon_class() < 13) qual = "is a good weapon.";
if(ob->weapon_class() < 10)  qual = "is a decent weapon.";
if(ob->weapon_class() < 7)   qual = "is a poor choice for a weapon...";
  write(ob->short()+" "+qual+"\n");
  call_other(this_player(), "add_spell_point", -20);
  return 1;
        }

    write(ob->short()+" is not a blade.\n");
    return 1;
        }
