#include "/players/pavlik/guild/mages/defs.h"
inherit "players/pavlik/guild/mages/inherit/command";

reset(arg) {
  if(arg) return;
  set_verb("commands");
  set_name("Commands");
  set_color_name(HIC+"Commands"+NORM);
  set_rank(1);
  set_descrip(
	"Display a list the guild commands that are available to you.\n" +
	"Use commands [x] to display commands only available at " +
	"guild rank [x] or use commands [x] [y] to dispaly available " +
	"commands from rank [x] to rank [y].\n" +
	"See Also: spells\n"
  );
}


cmd(str)
{
  string *cmd_list;
  string *f;
  string verb;
  string s;
  int i;
  int x;
  int min, max;

  if(tp->query_guild_rank() <= 0)
  {
	write("You are a mere "+CYN+"apprentice"+NORM+" and have no guild commands yet.\n");
	write("Advance to guild rank 1 and then review the available commands.\n");
	return 1;
  }

  cmd_list = ({});

  print_header();

  if(str)
	if(sscanf(str, "%d %d", min, max) != 2)
		sscanf(str, "%d", min);

  if(min && min < 1) min = 1;
  if(max && max > 100) max = 100;

  /*
   * build a string array of all usable commands
   */
  for(i=0; i<sizeof(f = files(CMD_DIR + "*.c")); i++)
  {
	if(f[i][0..1] == "__")
		continue;

	if(f[i][0..0] == "_")
		continue;

	if(file_size(CMD_DIR + f[i]) > 0)
	{
		s = CMD_DIR + f[i];
		if(s->query_rank() <= tp->query_guild_rank())
		{
			cmd_list += ({ s->query_rank() });
			cmd_list += ({ s->query_name() });
			cmd_list += ({ s->query_verb() });
		}
	}
  }

  /*
   * now print list sorted by rank
   */
  for(i=1; i<(tp->query_guild_rank()+1); i++)
  {
	for(x=0; x<sizeof(cmd_list)-2; x+=3)
	{
		if(cmd_list[x] == i)
		{
		  /*
		   * print only cmds in specified range (if specified)
		   */
		  if( (!min) ||
		      ( (min && max) && (cmd_list[x] >= min) && (cmd_list[x] <= max) ) ||
		      ( (min > 0) && (cmd_list[x] == min) ) )
		  {
			print_command(cmd_list[x],
			      cmd_list[x+1],
			      cmd_list[x+2]);
		  }
		}
	}
  }

  print_footer();
  return 1;

}

print_header()
{
  write(CYN+
   "Rank:\tCommand Name:\t\tCommand:\n" +
   "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+NORM);
}

print_footer()
{
  write(CYN+
   "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+NORM);
}

print_command(rank, name, verb)
{
  write(" "+rank+"\t");
  write(bufstr(name, 18)+"\t");
  write("["+bufstr(verb+"]", 10)+"\n");
}

bufstr(str, field)
{
  int i, x;
  string buff;

  buff = str;
  x = 20 - strlen(buff);
  for(i=0; i<x; i++){ buff = buff + " "; }
  return buff;
}

