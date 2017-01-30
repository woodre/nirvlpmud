/*
 *  The Servants of Larn chat line.  (v2.0)
 *
 */

larn_talk(str)  {
  object member, person, *list;
  int i,c;
  string temp;

  member = present("larn_obj", TP);
  if(member->query_larn_flag() < 1)  {
    write("You must open your mind to the universe.  <larn_toggle>\n");
      return 1;  }
  if(!str)  { write("You pray silently.\n");
    return 0;        }
  temp = "(Larn) "+tp+" chats:";
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
    write("You are the only Servant of Larn within the realms of magic.\n");
        }
    return 1;
        }
