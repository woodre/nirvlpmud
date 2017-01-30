#include "/players/guilds/bards/bard_lib/lib.h"
#include <ansi.h>
inherit ROOM;

void create() {
	::create();
  set_short(HIM+"The Bard Lounge"+NORM);
  set_long(HIM+
    "The Bard Lounge\n"+NORM+
    "This is a private lounge just for the Bards.  There are\n"+
    "large leather booths lining the walls, with a table between\n"+
    "them.  In the center of the room is a circular booth and a\n"+
    "table it is arrayed around.  On this table is a stone on\n"+
    "which are a list of names of the members of the Bardic Guild\n"+
    "of Ryllian.  To the north is the entrance to the guild.\n"+
	  HIM+"[9.27.16]"+NORM+" To join the guild, type <"+HIM+"join_bards"+NORM+">.\n"  /* verte */
    );
  set_items(([
    "booths" :
    "Very comfortable leather booths arrayed around tables.\n",
    "table" :
    "Oak tables around which are arrayed booths for seating.\n",
    ]));
  set_smells(([
    "default" :
    "The smell of leather furniture permeates this room.\n",
    ]));
  set_sounds(([
    "default" :
    "Soft harp music plays in the background.\n",
    ]));
  set_exits(([
    "north" : "/players/guilds/bards/bardrooms/enterance",
    ]));
  set_light(1);
  replace_program(ROOM);
}

void init()
{
	::init();
	add_action("join_bards","join_bards");
}

/* this function hacked out of ~guilds/bards/spells/gc_sponsor.c */
status join_bards()
{
	object ob;
	string tp;
	int level;
	object OB;
	ob = this_player();
  
	if(!ob || !ob->is_player())
	{
		write("You are not a player!\n");
		return 1;
	}
  if (ob->query_level() < 5) {
    write
    ("Players must be at least level Five to join the Bardic Guild.\n");
    return 1;
  }
  level = (int)ob->query_level();
  if(ob->query_guild_name()){ write("You are in a guild.\n"); return 1; }
  if(ob->query_guild_rank()){ write("You are in a guild.\n"); return 1; }
  if(ob->query_guild_exp()){ write("You are in a guild.\n"); return 1; }
  if(ob->query_pl_k()){ write("You are PK!\n"); return 1; }

	tp = (string)ob->query_real_name();
  level = (int)ob->query_level();
  OB = clone_object("/players/guilds/bards/instrument.c");
  move_object(OB, ob);
  OB->set_bard_level("1");
  OB->set_sponsor(ob);
  ob->set_guild_name("bard");
  ob->set_title("the Apprentice");
  write("You have sponsored yourself into the Bardic Guild!.\n");
  tell_object(ob,
    "You have been sponsored into the Bardic Guild by yourself.\n" + "You are now a Bard!\n\n" +
    "Type 'lore' for information, and 'sco' to see your new stats.\n\n"
  + "You are given a Bardic Instrument.\n\n");
  command("bt A NEW BARD HAS ENTERED THE REALMS OF MAGIC", ob);
  command("pppp", ob);
  write_file("/players/guilds/bards/logs/sponsor", tp + "(" +
    tp + ") sponsored "+objective(ob)+"self (" +
  ob->query_level() + ")->" + ctime(time()) + "\n");
	return 1;
}