/*
 *  The Kender emote line.  (v2.0)
 *
 */

kender_emote(str)  {
  object member, person, *list;
  int i,c;
  string temp;

  member = present("kender_obj", TP);
  if(!member->query_kender_flag())  {
    write("You have your ears plugged with wax.  <kender_toggle>\n");
    return 1;        }
  if(!str)  { write("You regale great stories to yourself.\n");
    return 0;        }
  temp = "(Kender) "+tp;
  temp = temp+" "+str;
  c = 0;  list = users();
  for(i = 0; i < sizeof(list); ++i)  {
    person = list[i];
    member = present("kender_obj", person);
    if(member && (int)member->query_kender_flag())  {
      tell_object(person, format(temp));
      ++c;
        }
        }
  if(c == 1)  {
    write("There are no other Gypsies within the realms of magic.\n");
        }
    return 1;
        }
