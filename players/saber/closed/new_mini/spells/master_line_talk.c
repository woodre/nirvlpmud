/*
 *  The master chat line of the mini guilds.  (v2.0)
 *
 */

master_line_talk(str)  {
  object member, person, *list;
  int i,c;
  string temp;

  member = present("base_obj", TP);
  if(member->query_master_flag() < 1)  {
    write("You must be on the master linfe before you can speak.\n"+
      "Type <m_toggle> to turn it on.\n");  return 0;  }
  if(!str)  { write("You realize that you have nothing to say.\n");
    return 0;        }
  temp = "(MASTER) "+tp+" speaks:";
  temp = temp+" "+str;
  c = 0;  list = users();
  for(i = 0; i < sizeof(list); ++i)  {
    person = list[i];
    member = present("base_obj", person);
    if(member && (int)member->query_master_flag())  {
      tell_object(person, format(temp));
      ++c;
        }
        }
  if(c == 1)  write("There is no one else on the Master line within the realms of magic.\n");
    return 1;
        }
