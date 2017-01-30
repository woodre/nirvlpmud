#include "/players/pavlik/guild/mages/defs.h"
inherit "players/pavlik/guild/mages/inherit/command";

reset(arg) {
  if(arg) return;
  set_verb("study");
  set_name("Study Monster");
  set_color_name(HIC+"Study Monster"+NORM);
  set_rank(4);
  set_descrip(
	"Utilize your vast knowledge to evaluate the characteristics " +
	"of a potential advesary.  The study skill can help you determine " +
	"how you will match up against an opponent.\n"
  );
}


cmd(str)
{
  object obj;
  string name;
  int lvl, wc, ac;
  int xhp, lhp;

  if(tp->query_guild_rank() < query_rank())
	return 0;

  if(!str)
	obj = tp->query_attack();
  else
	obj = present(str, env);

  if(!obj)
  {
	notify_fail("There is no "+str+" here.\n");
	return 0;
  }

  if(!living(obj))
  {
	notify_fail("You can only "+CYN+"study"+NORM+" living things.\n");
	return 0;
  }

  name = capitalize(obj->query_name());
  lvl = obj->query_level();
  wc = obj->query_wc();
  ac = obj->query_ac();
  xhp = obj->query_mhp();
  if(xhp >= 800) lhp = xhp - 200;
  else if(xhp >= 500) lhp = xhp - 100;
  else if(xhp >= 200) lhp = xhp - 50;
  else lhp = xhp - 25;

  write(
   "You search through your pouches until you find a large book.\n"+
   "Aha!  Here it is...you pull your trusted "+HIM+"'Heward's Comprised\n"+
   "Compendium of Ugly Nasties'"+NORM+" and look up '"+HIC+name+NORM+"'....\n");
  say(
  ME+" reaches into his pouch and pulls out a large book.  He quickly\n"+
   "flips through the pages, searching intently.  Finally, "+ME+" finds\n"+
   "whatever it was he was looking up.\n");
  say(
   ME+" studies the book intently for a moment and then puts it away.\n" +
   ME+" smiles knowingly.\n");

  write(HIM+"  "+obj->short()+" (pg "+random(100)+"): \n"+NORM);
  if(lvl > 30) write(name+" is a being of Godlike proportions.");
  else if(lvl > 20) write(name+" is a supernatural being.");
  else if(lvl > 16) write(name+" is a high level monster.");
  else if(lvl > 12) write(name+" is a medium level monster.");
  else if(lvl > 8) write(name+" is an inexperienced monster.");
  else write(name+" is a pathetic newbie monster.");
  if(lvl > tp->query_level()) write(" [>]\n");
  else if(lvl < tp->query_level()) write(" [<]\n");
  else write(" [=]\n");

  if(wc >= 30) write(name+" can squash you like a bug.");
  else if(wc >= 20) write(name+" can rip you to pieces.");
  else if(wc >= 18) write(name+" can hurt you bad.");
  else if(wc >= 15) write(name+" can cut you up pretty good.");
  else if(wc >= 10) write(name+" can hurt you.");
  else write(name+" will just annoy you.");
  if(wc > tp->query_wc()) write(" [>]\n");
  else if(wc < tp->query_wc()) write(" [<]\n");
  else write(" [=]\n");

  if(ac > 20) write(name+" is an impregnable fortress.");
  else if(ac > 15) write("You would be lucky to hit "+name+".");
  else if(ac >= 12) write(name+" will be difficult to hit.");
  else if(ac >= 9) write(name+" will be moderately hard to hit.");
  else if(ac >= 6) write(name+" will be considerably easy to hit.");
  else if(ac >= 3) write(name+" will be a cinch to hit.");
  else write(name+" will practicly fall onto your weapon.");
  if(ac > tp->query_ac()) write(" [>]\n");
  else if(ac < tp->query_ac()) write(" [<]\n");
  else write(" [=]\n");

  if(lvl > tp->query_level() + 9)
	write(name+" will be a very difficult kill.\n");
  else if(lvl > tp->query_level() + 5)
	write(name+" will be a hard earned kill.\n");
  else if(lvl > tp->query_level())
	write("You and "+name+" are evenly matched.\n");
  else if(lvl < tp->query_level() - 10)
	write(name+" will be a patheticly easy kill.\n");
  else if(lvl < tp->query_level() - 5)
	write(name+" should be an easy kill.\n");
  else
	write(name+" will put up a good fight.\n");

  write("You close up Heward's Compendium and return it to your pouch.\n");
  return 1;

}
