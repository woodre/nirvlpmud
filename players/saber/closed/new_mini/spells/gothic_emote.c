/*
 *  The Gothic emote line.  (v2.0)
 *
 */

gothic_emote(str)  {
  object member, person, *list;
  int i,c;
  string temp;

  member = present("gothic_obj", TP);
  if(!member->query_gothic_flag())  {
    write("You are not currently in good standing with the gothic community.\n"+
        "How depressing.        <gothic_toggle>\n");
    return 1;        }
  if(!str)  { write("You whisper so that only you can hear.\n");
    return 0;        }
  temp = "(Gothic) "+tp;
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
    write("There are no other Goths within the realms of magic.\n");
        }
    return 1;
        }
