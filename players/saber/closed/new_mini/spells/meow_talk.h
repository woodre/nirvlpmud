/*
 *  The Feline chat line.  (v2.0)
 *
 */

meow_talk(str)  {
  object member, person, *list;
  int i,c;
  string temp;

  member = present("meow_obj", TP);
  if(member->query_meow_flag() < 1)  {
    write("You are not listening to the caterwauling of your kin.  <meow_toggle>\n");
      return 1;  }
  if(!str)  { write("You mew silently.\n");
    return 0;        }
  temp = "(Feline) "+tp+" meows:";
  temp = temp+" "+str;
  c = 0;  list = users();
  for(i = 0; i < sizeof(list); ++i)  {
    person = list[i];
    member = present("meow_obj", person);
    if(member && (int)member->query_meow_flag())  {
      tell_object(person, format(temp));
      ++c;
        }
        }
  if(c == 1)  {
    write("You are the only Feline within the realms of magic.\n");
        }
    return 1;
        }
