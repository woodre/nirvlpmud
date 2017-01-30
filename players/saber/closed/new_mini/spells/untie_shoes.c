/*
 *  The blade ability to untie tied shoelaces.  (v2.0)
 *
 */

untie_shoes(str)  {
  object ob, ob2;
  int stealth;

  if(!str)  {
    write("Untie whose shoe laces?\n");
    return 1;
       }

  ob = present(str, environment(this_player()));
  if(!ob)  {
    write(CAP+" is not here.\n");
    return 1;
        }

  if(!(living(ob)))  {
    write(CAP+"'s don't wear shoes...\n");
    return 1;
        }

  if(!present("shoelace",ob))  {
    write(CAP+"'s shoelaces are not tied together.\n");
    return 1;
        }

  ob2 = present("shoelace",ob);

  write("\nYou covertly untie "+CAP+"'s shoelaces.\n");
  stealth = call_other(this_player(), "query_attrib", "ste");
  if(random(stealth) + random(this_player()->query_level()) < random(8))  {
    say("You notice "+tp+" covertly untieing "+CAP+"'s shoelaces.\n",ob);
        }
  if(random(stealth) + random(this_player()->query_level()) < random(ob->query_attrib("int")))  {
    write(CAP+" notices you untieing their shoe laces.\n");
    tell_object(ob, "You just noticed "+tp+" untieing your shoe laces.\n"+
    "Wonder who tied them together?\n");
        }

  if(ob->query_level() > 20)  {
    tell_object(ob, tp+" just untied your shoe laces.\n");
        }

  destruct(ob2);
  return 1;
        }
