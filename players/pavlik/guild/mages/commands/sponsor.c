#include "/players/pavlik/guild/mages/defs.h"
inherit "players/pavlik/guild/mages/inherit/command";

#define pos obj->query_possessive()

reset(arg) {
  if(arg) return;
  set_verb("sponsor");
  set_name("Sponsor");
  set_color_name(HIC+"Sponsor"+NORM);
  set_rank(40);
#if 0
  set_descrip(
	"Sponsorship is required for entrance into the Mages Guild. " +
	"A second sonsporship is also required to advance into the " +
	"senior ranks of the guild.\n" +
	"\n" +
	"Mages of Rank 40 or higher may act as sponsors.  The number " +
	"if people you can sponsor is limited, but will increase as " +
	"your guild rank increases.  The maximum number of people a " +
	"Mage can sponsor for the guild is (5).\n"
  );
#endif
  set_descrip(
	"Sponsorship is no longer required for entrance into the Mages Guild. \n" );
}


cmd(str)
{
  object ob, obj;
  string name;

  /* look at my sponsor info */
  if(!str || str == "who")
  {
	sponsor_report();
	return 1;
  }

  if(tp->query_guild_rank() < query_rank())
  {
	notify_fail("You are not high enough in the guild to sponsor.\n");
	return 0;
  }

  /* debug */
  if(str == "pav" && tp->query_level() > WIZLEVEL)
  {
	write("Sponsor string: "+guild->query_sponsor()+"\n");
	return 1;
  }

  /* debug  */
  if(str[0..3] == "pav ")
  {
	name = str[4..(strlen(str)-1)];
	write("Sponsor string set to: " + name + "\n");
	guild->set_sponsor(name);
	return 1;
  }

  /* debug */
  if(str == "reset" && tp->query_level() > WIZLEVEL)
  {
	write("Reseting sponsor string.\n");
	guild->set_sponsor("0#0+");
	return 1;
  }

  if(file_size("/players/pavlik/guild/mages/players/banned/"+str) > 0)
  {
	notify_fail(capitalize(str)+" has been banned from the Mages Guild.\n" +
		    "This person cannot be sponsored.\n");
	return 0;
  }

  obj = find_player(str);

  if(!obj || !present(obj, env))
  {
	notify_fail(capitalize(str)+" is not here.\n");
	return 0;
  }

  /*
   * if player is already in the guild then this is a secondary sponsorship
   */
  if(obj->query_guild_name() == "mage")
  {
	sponsor_2(obj);
	return 1;
  }

  if(obj->query_guild_name() != 0)
  {
	notify_fail("You cannot sponsor the member of another guild.\n");
	return 0;
  }

  if(!valid_sponsor(str)) 
	return 1;

  name = obj->query_real_name();

  write(
   "You have deemed "+capitalize(name)+" to be worthy.  The power of magic\n"+
   "flows through "+pos+" veins and burns in "+pos+" soul.  You have permitted\n"+
   "this person entry into the Circle of Mages upon your own word.\n"+
   "So be it.\n");
  tell_object(obj,
   ME+" has deemed you worthy.  "+capitalize(PN)+" has seen the potential that lies\n"+
   "yet untapped within you.  Upon "+ME+"'s word you will be able to\n"+
   "enter the Circle of Mages.\n"+
   "So be it.\n");

  ob = clone_object(OBJ_DIR + "sponsor.c");
  ob->set_sponsor(tp->query_real_name());
  move_object(ob, obj);
  add_name(str);
  return 1;

}


sponsor_2(obj)
{
  string name, str;
  string m1, m2, y;

  name = obj->query_real_name();

  if(obj->query_guild_rank() < 20)
  {
	write(capitalize(name)+" is not ready to be sponsored again.\n");
	return 1;
  }

  if(obj->query_guild_rank() > 20)
  {
	write(capitalize(name)+" does not need to be sponsored again.\n");
	return 1;
  }

  sscanf(present("mageobj", obj)->query_sponsor(), "%s#%s+%s", m1, m2, y);

  if(m1 == tp->query_real_name())
  {
	write("You have already sponsored "+capitalize(name)+".\n" +
	      "Someone else must be the 2nd sponsor of this person.\n");
	return 1;
  }

  if(!valid_sponsor(name))
	return 1;

  write(
   "You acknowledge that magic has become "+capitalize(name)+"'s life and that\n"+
   PN+" is worthy of the power it may yield.  Upon your name "+capitalize(name)+"\n"+
   "may continue to study and advance with the Mages Guild.\n");
  tell_object(obj,
   ME+" acknowledges that magic has become your life.  You may continue\n"+
   "your studies and know what it is to become a senior member of the Mages Guild\n");

  add_name(name);
  present("mageobj", obj)->set_sponsor(m1+"#"+tp->query_real_name()+"+");
  return 1;

}


valid_sponsor(str)
{
  string sponsored;
  string z;
  int max;
  int i;

  /* wizards and GCs can always sponsor */
  if(tp->query_guild_rank() > MAXGUILDRANK)
	return 1;

  /*
   * define the max ppl we could sponsor
   */
  if(tp->query_guild_rank() > 69) max = 5;
  else if(tp->query_guild_rank() > 59) max = 4;
  else if(tp->query_guild_rank() > 49) max = 3;
  else if(tp->query_guild_rank() > 39) max = 2;

  if(sscanf(guild->query_sponsor(), "%s+%s", z, sponsored) != 2)
  {
	write(HIR+"Corrupt sponsorship info\n"+NORM +
	      "Please contact the guild administrator.\n");
	return 0;
  }

  if(sponsored == "" || sponsored == 0)
	return 1;

  while(sscanf(sponsored, "%s#%s", z, sponsored) == 2)
  {
	if(z != "" && z != 0)
		i++;
  }
  if(sponsored != "" && sponsored != 0)
	i++;

  if(i >= max) {
	write("You cannot sponsor anyone else at this time.\n");
	return 0;
  }

  return 1;
}


add_name(str)
{
  string m, s;
  int x;

  sscanf(guild->query_sponsor(), "%s+%s", m, s);

  if(s == "" || s == 0)
	guild->add_sponsor(str);
  else
	guild->add_sponsor("#"+str);

  return 1;
}


sponsor_report()
{
  string sponsors;
  string sponsored;
  string m1, m2;
  string s1, s2;
  int x;

  if(!guild->query_sponsor())
  {
	write(HIR+"Corrupt sponsorship info\n"+NORM +
	      "Please contact the guild administrator.\n");
	return 1;
  }

  if(sscanf(guild->query_sponsor(), "%s+%s", sponsors, sponsored) != 2)
  {
	write(HIR+"Corrupt sponsorship info\n"+NORM +
	      "Please contact the guild administrator.\n");
	return 1;
  }

  write(HIC+"            Mages Sponsorship Info:\n"+NORM);
  write(HIC+"---------------------------------------------------\n"+NORM);

  write("You were sponsored by: \n");
  sscanf(sponsors, "%s#%s", m1, m2);
  if(m1 != "" && m1 != 0)
	write ("  1): " + capitalize(m1) + "\n");
  else
	write ("  1): unknown\n");
  if(m2 != "" && m2 != 0)
	write ("  2): " + capitalize(m2) + "\n");
  else
	write ("  2): unknown\n");


  if(tp->query_guild_rank() >= query_rank())
  {
	x = 1;
	write("\n");
	write("You have sponsored:\n");
	while(sscanf(sponsored, "%s#%s", s1, sponsored) == 2)
	{
		if(s1 != "" && s1 != 0)
		{
			write("  " + x + "): " + capitalize(s1) + "\n");
			x++;
		}
	}
	if(sponsored != "" && sponsored != 0)
		write("  " + x +"): " + capitalize(sponsored) + "\n");
  }

  write(HIC+"---------------------------------------------------\n"+NORM);
  write("\n");
  return 1;

}

