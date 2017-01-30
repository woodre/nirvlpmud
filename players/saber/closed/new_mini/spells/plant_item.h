/*
 *  The kender ability to plant an item on a person.  (v2.0)
  *
  */

plant_item(str)  {

  object item, person;
  string ITEM, PERSON;
  int stealth, weight;

  if(spell(-3000,1,10) ==-1)  return 0;

  if(!str || !sscanf(str, "%s on %s", ITEM, PERSON))  {
    write("Hay bud, you need to type: plant <item> on <person>\n");
    return 1;
        }

  person = present(PERSON, environment(this_player()));
  if(!person)  {
    write(person->query_name()+" is not here.\n");
    return 1;
      }

  item = present(ITEM, environment(this_player()));
  if(!item)  item = present(ITEM, this_player());
    if(!item)  {
    write("You can't smuggle something you don't have...\n");
    return 1;
        }

/* added check years later to make legal.. verte */
  if(living(item) || !item->get() || !item->drop()){
    write("You cannot plant "+(string)item->short()+"!\n");
    return 1;
  }
  if(!living(person))  {
    write("You can't plant an item on a "+capitalize(PERSON)+".\n");
    return 1;
        }

  if(environment(item) == this_player())  {
    if(call_other(item, "drop", 0))  {
    write("You can't smuggle your "+ITEM+".\n");
    return 1;
       }
       }

  write("\nYou secertly smuggle a "+ITEM+" onto "+capitalize(PERSON)+".\n");
  stealth = call_other(this_player(), "query_attrib", "ste");
  if(random(stealth) + random(this_player()->query_level()) < random(8))  {
    say("You notice "+tp+" plant a "+ITEM+" on "+capitalize(PERSON)+".\n",person);
        }
  if(random(stealth) + random(this_player()->query_level()) < random(person->query_attrib("int")))  {
    write(CAP+" notices you planting the "+ITEM+" on them...oh oh...\n");
  tell_object(person, "You just caught "+tp+" trying to plant an "+ITEM+" on you.\n");
  return 1;
        }

  if(person->query_level() > 20)  {
    tell_object(person, tp+" has just planted a "+ITEM+" on you.\n");
        }

  weight = call_other(person, "query_weight", 0);
  call_other(person, "add_weight", weight);
  move_object(item, person);
  call_other(this_player(), "add_weight", -weight);
  call_other(this_player(), "add_spell_point", -10);
  return 1;
       }
