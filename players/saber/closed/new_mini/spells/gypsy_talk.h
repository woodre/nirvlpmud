/*
 *  The Gypsy Kin chat line.  (v2.0)
 *
 */

gypsy_talk(str)  {
  object member, person, *list;
  int i,c;
  string temp;

  member = present("gypsy_obj", TP);
  if(member->query_gypsy_flag() < 1)  {
    write("Your medallion faces the wrong direction. <gypsy_toggle>\n");
      return 1;  }
  if(!str)  { write("You whisper a silent story to yourself.\n");
    return 0;        }
  temp = "(Gypsy) "+tp+" whispers:";
  temp = temp+" "+str;
  c = 0;  list = users();
  for(i = 0; i < sizeof(list); ++i)  {
    person = list[i];
    member = present("gypsy_obj", person);
    if(member && (int)member->query_gypsy_flag())  {
      tell_object(person, format(temp));
      ++c;
        }
        }
  if(c == 1)  {
    write("You are the only Gypsy Kin within the realms of magic.\n");
        }
    return 1;
        }
