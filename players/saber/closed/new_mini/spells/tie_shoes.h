/*
 *  The blade ability to tie a persons shoe laces togather (v2.0)
 *
 */

tie_shoes(str)  {
  object ob;
  int stealth;

  if(spell(-3000,1,30)  ==-1)  return 0;

  if(!str)  {
    write("Tie whose shoe laces together?\n");
    return 1;
        }

  ob = present(str, environment(this_player()));
  if(!ob)  {
    write(CAP+" is not here.\n");
    return 1;
        }

  if(!living(ob))  {
    write(CAP+"'s don't wear shoes...\n");
    return 1;
        }

  if(present("shoelaces",ob))  {
    write(CAP+"'s shoelaces have already been tied together.\n"+
    "If you want to untie them, try <untie> <"+tp+".\n");
    return 1;
        }

  write("\nYou covertly tie "+CAP+"'s shoelaces together.\nHehehe\n");
  stealth = call_other(this_player(), "query_attrib", "ste");
  if(random(stealth) + random(this_player()->query_level()) < random(8))  {
    say("You notice "+tp+" covertly tieing "+CAP+"'s shoelaces together.\n",ob);
        }
  if(random(stealth) + random(this_player()->query_level()) < random(ob->query_attrib("int")))  {
  write(CAP+" notices you tieing their shoe laces together...oh oh...\n");
  tell_object(ob, "You just caught "+tp+" trying to tie your shoe laces together.\n");
  return 1;
       }

  if(ob->query_level() > 20)  {
    tell_object(ob, tp+" has just tied your shoe laces together.\n"+
    "If you wish to untie them, just type <untie>.\n");
        }

  move_object(clone_object("/players/saber/closed/new_mini/shoelace.c"),ob);
  call_other(this_player(), "add_spell_point", -30);
  return 1;
        }
