/*
 *  The master chat line of the mini guilds.  (v2.0)
 *
 */

int master_line(string str, int i_emote)  {
  object member, person, *list;
  int i,c;
  string temp;

  member = present("base_obj", TP);
  if(!member->query_master_flag())  {
    notify_fail("You must be on the master linfe before you can speak.\n"+
      "Type <m_toggle> to turn it on.\n");  return 0;  }
  if(!str)  { notify_fail("You realize that you have nothing to say.\n");
    return 0;        }
  temp = "(MASTER) "+tp;
  if(!i_emote) temp = temp+" speaks:";
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
