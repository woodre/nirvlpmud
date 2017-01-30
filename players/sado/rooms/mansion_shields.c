array sneakies;
int num_sneakies;
int shields;

reset(arg)
{
  if(arg) return;
  shields = 0;
  num_sneakies = 0;
  add_sneaky("sado");
  add_sneaky("esoterica");
}

query_shields()
{
  return shields;
}

set_shields()
{
  shields = 1;
  return 1;
}

reset_shields()
{
  shields = 0;
  return 1;
}

toggle_shields()
{
  shields = !shields;
  return 1;
}

query_slip_thru(str)
{
  if(str == "sado") return 1;
  if(query_shields() && sneakies && member_array(str, sneakies) == -1) return 0; else return 1;
}

add_sneaky(str)
{
  int i;
  int old_num;
  array new_sneakies;

  if(sneakies && member_array(str,sneakies) != -1) return 0;

  old_num = num_sneakies;
  new_sneakies = allocate(++num_sneakies);

  for(i=0; i<old_num; i++) new_sneakies[i] = sneakies[i];
  new_sneakies[i] = str;
  sneakies = new_sneakies;
  return 1;
}

remove_sneaky(str)
{
  int i,j;
  array new_sneakies;

  if(sneakies && member_array(str,sneakies) == -1) return 0;

  j=0;
  new_sneakies = allocate(--num_sneakies);
  for(i=0; i<num_sneakies; i++)
    {
      if(sneakies[i+j] != str) new_sneakies[i] = sneakies[i+j];
      else j++;
    }
  sneakies = new_sneakies;
  return 1;
}

toss_em(who)
{
  object me;
  tell_object(who,"Sorry.  The fumes in there are too dangerous just at the moment.\n" +
	      "Sado had a bit of an accident with a bottle of some nasty green\n" +
	      "chemotoxin.  Best try again later.\n");
  move_object(who,"/room/church.c");
  if(me=find_player("sado"))
    tell_object(me,capitalize(who->query_real_name())+" tried to get in.\n");
}
