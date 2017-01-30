/*
 *  The Gothic Kin chat line.  (v2.0)
 *
 */

gothic_talk(str)  {
  object member, person, *list;
  int i,c;
  string temp;

  member = present("gothic_obj", TP);
  if(member->query_gothic_flag() < 1)  {
    write("You are not currently in good standing with the gothic community.\n"+
        "How depressing.        <gothic_toggle>\n");
      return 1;  }
  if(!str)  { write("You whisper so that only you can hear.\n");
    return 0;        }
  temp = "(Gothic) "+tp+" recites:";
  temp = temp+" "+str;
  c = 0;  list = users();
  for(i = 0; i < sizeof(list); ++i)  {
    person = list[i];
    member = present("gothic_obj", person);
    if(member && (int)member->query_gothic_flag())  {
      tell_object(person, format(temp));
      ++c;
        }
        }
  if(c == 1)  {
    write("You are the only Goth within the realms of magic.\n");
        }
    return 1;
        }
