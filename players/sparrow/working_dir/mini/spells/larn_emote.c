/*
 *  The Servants of Larn emote line.  (v2.0)
 *
 */

larn_emote(str)  {
  object member, person, *list;
  int i,c;
  string temp;

  member = present("larn_obj", TP);
  if(!member->query_larn_flag())  {
    write("You must open your mind to the universe. <larn_toggle>\n");
    return 1;        }
  if(!str)  { write("You pray silently.\n");
    return 0;        }
  temp = "(Larn) "+tp;
  temp = temp+" "+str;
  c = 0;  list = users();
  for(i = 0; i < sizeof(list); ++i)  {
    person = list[i];
    member = present("larn_obj", person);
    if(member && (int)member->query_larn_flag())  {
      tell_object(person, format(temp));
      ++c;
        }
        }
  if(c == 1)  {
    write("There are no other Servants of Larn within the realms of magic.\n");
        }
    return 1;
        }
