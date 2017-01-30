/*
 *  The Canine emote line.  (v2.0)
 *
 */

canine_emote(str)  {
  object member, person, *list;
  int i,c;
  string temp;

  member = present("canine_obj", TP);
  if(!member->query_canine_flag())  {
write("Your collar is too tight. <canine_toggle>\n");
    return 1;        }
if(!str)  { write("You perk your ears up and bark for no reason.\n");
    return 0;        }
  temp = "(Canine) "+tp;
  temp = temp+" "+str;
  c = 0;  list = users();
  for(i = 0; i < sizeof(list); ++i)  {
    person = list[i];
    member = present("canine_obj", person);
    if(member && (int)member->query_canine_flag())  {
      tell_object(person, format(temp));
      ++c;
        }
        }
  if(c == 1)  {
write("You are the only canine within the realms of magic.\n");
        }
    return 1;
        }
