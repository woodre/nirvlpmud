inherit "players/pavlik/guild/mages/inherit/command";
#include "/players/pavlik/guild/mages/defs.h"
#include "/players/pavlik/guild/mages/include/string.h"

reset(arg) {
  if(arg) return;
  set_verb("gw");
  set_name("Guild Who");
  set_color_name(HIC+"Guild Who"+NORM);
  set_rank(1);
  set_descrip(
	"Display a list of Magi currently on Nirvana\n" +
	"See Also: mw\n"
  );
}


cmd()
{
  object ob, obj;
  string str, name;
  int mages, i, count;

  mages = 0;
  DONATOR->get_names();
  DONATOR->sort_names();
  write("\n"+
   "------------------------------------------------------------------------\
------\n"+
   "  Name:      Lvl:  G:   Rank:                Location:\n"+
   "------------------------------------------------------------------------\
------\n");
  ob = users();
  for(i=0; i<sizeof(ob); i++)
  {
	obj = present("mageobj", ob[i]);
	if(obj && ob[i]->query_invis() < tp->query_level())
	{
		if(ob[i]->query_pl_k()==1) write(HIR+"*"+NORM);
		else write(" ");
		if(obj->query_muffled()==1) write(HIC+"%"+NORM);
		else write(" ");
		name = ob[i]->query_real_name();
		if(name == DONATOR->query_first())
		{
			name = totalcap(name);
			write(align_str(name, 12));
		}
		else
			write(align_str(capitalize(name), 12));
		if(ob[i]->query_level() > 99) write(HIC+ob[i]->query_level()+NORM+"  ");
		else if(ob[i]->query_level() < 10) write(ob[i]->query_level()+"    ");
		else write(ob[i]->query_level()+"   ");
		if(ob[i]->query_gender() =="male") write(" M   ");
		else if(ob[i]->query_gender() =="female") write(" F   ");
		else write(" C  ");
		print_title(ob[i]->query_guild_rank());
		write(environment(ob[i])->short()+"\n");
		mages++;
	}
  }
  write(
   "-------------------------------------------------------------------------\
------\n");
  write(" ["+mages+"] Mages logged on    * = player killer    % = muffled\n");
  write(
   "-------------------------------------------------------------------------\
------\n");

  return 1;

}
        
print_title(rank)
{
  int x;
  string msg;
  if(rank > 60){ x = 70; msg = "Time"; }
  else if(rank > 50){ x = 60; msg = "Stars"; }
  else if(rank > 40){ x = 50; msg = "Storms"; }
  else if(rank > 30){ x = 40; msg = "Dragons"; }
  else if(rank > 20){ x = 30; msg = "Fire"; }
  else if(rank > 10){ x = 20; msg = "Air"; }
  else { x = 10; msg = "Earth"; }
  x = x - rank;
  if(rank > 99) msg = HIM+"Wizard";
  else if(rank < 1) msg = "Apprentice";
  else if(rank > MAXGUILDRANK) msg = HIC+"Council Member";
  else if(rank > 69) msg = msg+HIC+" (master)";
  else if(x == 0) msg = msg+HIC+" (master)";
  else if(x == 1) msg = msg+" (1st circle)";
  else if(x == 2) msg = msg+" (2nd circle)";
  else if(x == 3) msg = msg+" (3rd circle)";
  else if(x > 3) msg = msg+" ("+x+"th circle)";
  if((rank > 69) || (x == 0)) write(align_str(msg, 29));
  else write(align_str(msg, 22));
  write(NORM);
  return 1;
}

totalcap(str)
{
  string name, msg, letter;
  int i, count;

  msg = "";
  count = strlen(str);
  for(i=0; i<count; i++){
	letter = extract(str, i, i);
	letter = capitalize(letter);
	msg = msg + letter;
  }
  return msg;
}

