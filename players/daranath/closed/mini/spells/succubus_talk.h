/*
 *  The succubus chat line.  (v2.0)
 *
 */

succubus_talk(str)  {
  object member, person, *list;
  int i,c;
  string temp;

  member = present("succubus_obj", TP);
  if(member->query_succubus_flag() < 1)  {
    write("You must regain contact with your succubus kin.  <succubus_toggle>\n");
      return 1;  }
  if(!str)  { write("You whisper sweet nothings to yourself.\n");
    return 0;        }
  temp = "(Succubus) "+tp+" whispers:";
  temp = temp+" "+str;
  c = 0;  list = users();
  for(i = 0; i < sizeof(list); ++i)  {
    person = list[i];
    member = present("succubus_obj", person);
    if(member && (int)member->query_succubus_flag())  {
      tell_object(person, format(temp));
      ++c;
        }
        }
  if(c == 1)  {
    write("You are the only Succubus within the realms of magic.\n");
        }
    return 1;
        }
