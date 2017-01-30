/*
 *  The Succubus emote line.  (v2.0)
 *
 */

succubus_emote(str)  {
  object member, person, *list;
  int i,c;
  string temp;

  member = present("succubus_obj", TP);
  if(!member->query_succubus_flag())  {
    write("You must regain contact with your succubus kin.  <succubus_toggle>\n");
    return 1;        }
  if(!str)  { write("You whisper sweet nothings to yoursef.\n");
    return 0;        }
  temp = "(Succubus) "+tp;
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
    write("There are no other Succubus within the realms of magic.\n");
        }
    return 1;
        }
