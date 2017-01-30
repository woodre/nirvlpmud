/*
 *  The Blade chat line.  (v2.0)
 *
 */

blade_talk(str)  {
  object member, person, *list;
  int i,c;
  string temp;

  member = present("blade_obj", TP);
  if(member->query_blade_flag() < 1)  {
  write("You decided not to listen to those braggarts, remember? <blade_toggle>\n");
      return 1;  }
  if(!str)  { write("You're so good, you don't even need to brag.\n");
    return 0;        }
  temp = "(Blade) "+tp+" brags:";
  temp = temp+" "+str;
  c = 0;  list = users();
  for(i = 0; i < sizeof(list); ++i)  {
    person = list[i];
    member = present("blade_obj", person);
    if(member && (int)member->query_blade_flag())  {
      tell_object(person, format(temp));
      ++c;
        }
        }
  if(c == 1)  {
    write("You are the only Blade within the realms of magic.\n");
        }
    return 1;
        }
