inherit "/players/pavlik/guild/mages/inherit/advance";
inherit "/players/pavlik/guild/mages/inherit/room";
inherit "room/room";
#include "/players/pavlik/guild/mages/defs.h"

int min_exp;

reset(arg) {
  if(arg);
  set_light(1);
  short_desc=HIC+"Calador's"+NORM+" Chambers";
  long_desc=
	"You have entered the chambers of "+HIC+"Calador the Archmage"+NORM+".  The walls\n"+
	"are covered with bookshelves, each of which is filled with volume\n"+
	"upon volume of books.  Each book is filled with untold power of\n"+
	"the "+CYN+"arcane arts"+NORM+".  Calador oversees the "+MAG+"training"+NORM+" of every Mage\n"+
	"within the guild, and he takes his work very seriously.  The center\n"+
	"of the room is occupied by Calador's work table.  Several beakers\n"+
	"filled with boiling liquids bubble quietly on the table top.\n"+
	"There is a "+MAG+"scroll"+NORM+" unfurled on the desktop as well.\n";

  items=({
    "scroll",
	"A scroll lies unfurled on the work table.\n"+
	"On it are the words '"+HIC+"aziar eim oyish"+NORM+"'",
    "walls",
	"Every wall is completely occupied by Calador's bookshelves",
    "bookshelves",
	"Bookshelves of finely crated wood occupy every wall in this\n"+
	"chamber.  Endless rows of books fill each shelf, there are far\n"+
	"too many books to count.  Each tome holds unknown powers of the\n"+
    "books",
	"There must be millions of books stacked neatly on the bookshelves\n"+
	"of this chamber.  Each book is carefully protected by magic so\n"+
	"that not even the dust would disturb them.  You scan the titles\n"+
	"of the books but you are unable to recognize the writing",
    "table",
	"Calador's work table occupies the center of the room.  The table\n"+
	"appears to be made from some sort of marble.  Deep colorations\n"+
	"swirl within the depths of the stone.  There are several potions\n"+
	"and an unfurled "+MAG+"scroll"+NORM+" on the table top",
    "potions",
	"Several potions bubble and smoke on the work table of Calador.\n"+
	"As tempting as it might be, you know better than to touch them",
    "curtain",
	"A red curtain stands between you and Calador's private chambers",
  });

  dest_dir=({
	ROOM_DIR+"ante_room",		"south",
  });

}

query_mguild(){ return "Calador's"; }

init() {
  ::init();
  if(!mage_check()) return;
  add_action("guild_move","gm");
  add_action("speak_it","aziar");
#ifndef __LDMUD__
  add_action("summon_master"); add_xverb("'");
#else
  add_action("summon_master","'", 3);
#endif
  add_action("summon_master","say");
  add_action("advance","advance");
  add_action("how_much","cost");
  add_action("advance_help","??");
}


advance()
{
  int exp, next_exp, rank, x;
  string tmp, msg;

  if(!present("calador", this_object()))
  {
	write("There is noone here to help you.\n");
	return 1;
  }

  if(present("calador", this_object())->query_BUSY())
  {
	write(CYN+"Calador"+NORM+" says: In a moment, Magi.  I am instructing another pupil.\n");
	return 1;
  }

  rank = tp->query_guild_rank();
  exp = tp->query_guild_exp();

  if(rank >= MAXGUILDRANK)
  {
	write(
	  CYN+"Calador"+NORM+" says: I have taught you all that I can.\n" +
	  CYN+"Calador"+NORM+" says: You must seek a higher power if you wish to advance further.\n");
	return 1;
  }

  next_exp = rank_costs(rank + 1);

  if(exp - next_exp < 0)
  {
	write(
	  CYN+"Calador"+NORM+" says: You are not ready to advance yet, Mage.\n" +
	  CYN+"Calador"+NORM+" says: You must aquire more experience before I will instruct you further.\n");
	return 1;
  }

  /* Calador cannot train us as Master of an Order
   * This must be done by another high-ranking player.
   * if(rank == 9 || rank == 19 || rank == 29 || rank == 39 || 
   */
#if 0
  if(rank+1 == 10 || rank+1 == 20 || rank+1 == 30 || rank+1 == 40 ||
  rank+1 == 50 || rank+1 == 60 || rank+1 == 71)
  {
	if(rank+1 == 10) tmp = HIG+"Earth"+NORM;
	else if(rank+1 == 20) tmp = HIB+"Air"+NORM;
	else if(rank+1== 30) tmp = HIR+"Fire"+NORM;
	else if(rank+1 == 40) tmp = HIM+"Dragons"+NORM;
	else if(rank+1 == 50) tmp = HIB+"Storms"+NORM;
	else if(rank+1 == 60) tmp = HIY+"Stars"+NORM;
	else if(rank+1 == 71) tmp = HIM+"Time"+NORM;

	write(
	  CYN+"Calador"+NORM+" says: You are ready to become a "+HIC+"Master"+NORM+" of "+tmp+".'\n" +
	  CYN+"Calador"+NORM+" says: I cannot teach you this.  You must be trained by another Mage.\n");

	/* ignore this check if we are council member */
	/*
	if(DAEMON->is_gc(tp))
		write("Council Member ... ok.\n");
	else if(tp->query_real_name() == "pavtest" || tp->query_real_name() == "crip")
		write("... Beta-test character ... skipping teach requirement.\n");
	else
	*/
		return 1;
  }
#endif

  /* Mages must have a 2nd sponsor before advancing past rank 20 */
  /* TEMPORARILY COMMENTED OUT....6/1/97
  if(rank+1 == 21)
  {
	if(!sponsor_check()) return 1;
  }
  */

  if((rank+1 > 60) && (tp->query_level() < 18)){
	write("You must be level 18 before you can advance in the Order of Time.\n");
	return 1;
  }
  else if((rank+1 > 50) && (tp->query_level() < 16)){
	write("You must be level 16 before you can advance in the Order of Stars.\n");
	return 1;
  }
  else if((rank+1 > 40) && (tp->query_level() < 14)){
	write("You must be level 14 before you can advance in the Order of Storms.\n");
	return 1;
  }
  else if((rank+1 > 30) && (tp->query_level() < 12)){
	write("You must be level 12 before you can advance in the Order of Dragons.\n");
	return 1;
  }
  else if((rank+1 > 20) && (tp->query_level() < 10)){
	write("You must be level 10 before you can be admittted to the Order of Fire.\n");
	return 1;
  }
  else if((rank+1 > 10) && (tp->query_level() < 7)){
	write("You must be level 7 before you can advance in the Order of Air.\n");
	return 1;
  }

  tp->add_guild_rank(1);
  command("gtitle", tp);

  /* give neat message to the player */
  display_message();

  /* do we get any new spells? */
  x = spell_chances(tp);
  if(x)
  {
	write("You recieve "+HIC+x+NORM+" new spell ");
	if(x == 1) write ("chance.\n");
	else write ("chances.\n");
	guild->add_new_spell_chances(x);
  }

  /* do we get any more training sessions? */
  x = training_sessions(tp);
  if(x)
  {
	write("You recieve "+HIC+x+NORM+" training ");
	if(x == 1) write("session.\n"); else write("sessions.\n");
	guild->add_training_sessions(x);
  }

  /* tell the other members of the guild */
  /*
  if(!DAEMON->is_gc(tp))
	tell_members();
  */

  return 1;

}


how_much()
{
  int cost, much;

  if(!present("calador", this_object()))
  {
	write("Noone is here to help you.\n");
	return 1;
  }

  cost = rank_costs(tp->query_guild_rank() + 1);
  much = cost - tp->query_guild_exp();

  write(
  CYN+"Calador tells you:"+NORM+" You must have "+HIW+cost+NORM+" guild exp to advance to your next rank.\n");

  if(much < 1)
	write(CYN+"Calador tells you:"+NORM+" You are ready to advance "+HIY+"now"+NORM+".\n");
  else
	write(CYN+"Calador tells you:"+NORM+" You need "+HIY+much+NORM+" more guild exp to advance.\n");
  return 1;
}


advance_help()
{
  if(!present("calador", this_object()))
  {
	write("Noone is here to help you.\n");
	return 1;
  }

  write(CYN+"Calador says:\n"+NORM+
  "  'I am here to help train the "+CYN+"Magi"+NORM+".  Come to me when you are ready'\n"+
  "  'to "+HIM+"advance"+NORM+" in the guild.  If you seek to become a "+CYN+"Master"+NORM+" of your'\n"+
  "  'your Order then you must be trained by another "+CYN+"Mage"+NORM+".'\n"+
  "\n" +
  "  commands are:\n"+
  "        advance  - advance a guild rank.\n"+
  "        cost     - query cost to advance to next guild rank.\n"+
  "\n");
  return 1;
}

tell_members()
{
  object ob, mob, monk;
  int i;

  ob = users();
  for(i = 0; i < sizeof(ob); i++)
  {
	mob = present("mageobj", ob[i]);
	if(mob && mob->query_muffled() == 0)
		tell_object(ob[i], "\n" +
		  CYN+"["+HIM+"*"+HIC+"Calador"+HIM+"*"+NORM+CYN+"]:"+NORM+" "+ME+" just advanced in the Guild!\n");
  }
  return 1;
}


speak_it()
{
  write("You have the feeling you should try to speak these words aloud\n");
  return 1;
}


summon_master(str)
{
  object obj;

  if(str == "aziar eim oyish" || str == "eim oyish")
  {
	write("You say: aziar eim oyish\n");
	say(ME+" says: aziar eim oyish\n");

	if(present("calador", this_object()))
	{
		tell_room(this_object(),
		"Calador coughs politely and taps his fingers on the work table.\n");
		return 1;
	}

	tell_room(this_object(),
	"The ground begins to shake slightly under your feet.  The slight\n"+
	"tremble becomes a giant quaking.  Towers of stacked books topple\n"+
	"to the floor.  You grab onto a nearby bookshelf to keep from\n");
	tell_room(this_object(),
	"falling over.  A myraid of brilliant colors explodes over the room.\n");

	tell_room(this_object(),
	"    "+CYN+"Calador says:"+NORM+" Greetings Magi?  How can I help you?\n");

	obj = clone_object(NPC_DIR+"calador");
	move_object(obj, this_object());
	return 1;
  }
}


sponsor_check()
{
  string spon, trash;
  string who1, who2;
  sscanf(guild->query_sponsor(), "%s+%s", spon, trash);
  sscanf(spon, "%s#%s", who1, who2);

  if(!who2 || who2 == "0") {
    write(
    "Calador says:  You will need to seek the sponsorship of a\n"+
    "               Senior Mage before you can advance.  Take care\n"+
    "               of this obligation and return to me.\n");
    return 0;
  }

  if(who1 == who2) {
    write(
    "Calador says: "+capitalize(who1)+" cannot be the one to sponsor your\n"+
    "              again.  Find another Senior Mage to sponsor you.\n");
    return 0;
  }
  
  return 1;
}

 
display_message()
{
  int x;
  x = random(4);

  if(x == 0)
    write(
	CYN+"Calador"+NORM+" says: If you wish to wield the powers of magic you must pay attention\n" +
	"to details.  If you allow the slightest inconsitency your magic will fail.\n");
  else if(x == 1)
    write(
	CYN+"Calador"+NORM+" says: Magic is a tool and tools are only as effective as the person\n" +
	"who uses the tool.  You are an artisan and magic is your medium.\n");
  else if(x == 2)
    write(
	CYN+"Calador"+NORM+" says: You must be able to exert your will over the magic.  These powers\n" +
	"know no master.  If you let your emotions weaken and your resolve waiver then the magic\n" +
	"may escape your control - Do not let this happen to you.\n");
  else if(x == 3)
    write(
	CYN+"Calador"+NORM+" says: Patience is key.  You are an evolution of power.\n" +
	CYN+"Calador"+NORM+" says: Feel the change within you and take hold!\n");

  write(HIC+"Congratulations Mage - You have advanced in the guild.\n"+NORM);
}


