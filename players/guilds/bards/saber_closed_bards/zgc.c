sponsor(str)  {
string who, sponsor;
int level, level2;
object ob, OB;

if(spell(-300,11,0) == -1) return 0;

if(!str || sscanf(str, "%s", who) !=1)  {
  write("To sponsor a new bard type: sponsor <bard to be>\n");
  return 1;
        }

if(!present(find_player(who), environment(TP)))  {
  write(CAP+" is not close enough to sponsor.\n");
  return 1;
        }

  ob = find_player(who);
  sponsor = find_player(who)->query_real_name();

if(ob->query_level() < 3)  {
  write("Players must be at least level three to join the Bardic Guild.\n");
  return 1;
        }

if(ob->query_guild_name() == "none" ||
  ob->query_guild_name() == 0 ||
  ob->query_guild_exp() == "0")  {

level = ob->query_level();

OB = clone_object("/players/saber/closed/bards/instrument.c");
move_object(OB,ob);
  OB->set_bard_level("1");
  OB->set_sponsor(tp);
  ob->set_guild_name("bard");
  ob->set_title("the Apprentice");
write("You have sponsored "+CAP+" into the Bardic Guild!.\n");
tell_object(ob, "You have been sponsored into the Bardic Guild by "+tp+"\n"+
  "You are now a Bard!\n\n"+
  "Type 'lore' for information, and 'sco' to see your new stats.\n\n"+
  "You are given a Bardic Instrument.\n\n");
  command("bt A NEW BARD HAS ENTERED THE REALMS OF MAGIC",ob);
  command("pppp",ob);
write_file("/players/saber/closed/bards/logs/sponsor",tp+"("+
  tp+") sponsored "+ ob->query_name()+"("+ob->query_level()+")->"+ctime(time())+"\n");
  return 1;
        }
  write("The players is a member of another guild.  If there is a problem\n"+
    "ask a wizard for help.\n");
  return 1;
        }

bard_set(str)  {
string target;
int level, amount;
object instr, instr2;
  if(spell(-1000,11,9) == -1);
  if(!str || sscanf(str, "%s", target) !=1)  {
  write("\nBard Master, you must type: Bset <bard name>\n\n");
    return 1;
        }
  if(!(instr = find_player(target)))  {
    write("I can not find "+TARG+" within the realms of magic.\n");
    return 1;
        }
  if((instr->query_guild_name()) != "bard")  {
    write(TARG+" is not a BARD!\n");
    return 1;
        }
  instr2 = clone_object("/players/saber/closed/bards/instrument.c");
  move_object(instr2,instr);
  write("You have given "+TARG+" a new instrument.\n");
  tell_object(instr, "You have a new instrument.\n");
  return 1;
        }

check_max(str)  {
object ob;
  if(!str)  {
    write("Check who?\n");
  return 1;
        }
  ob = find_player(str);
  if(!find_player(str))  {
    write("You can't find "+str+" within the realms of magic.\n");
    return 1;
        }

  if(ob->query_hostname() == "198.68.17.1")  {
    write("Check with Saber before sponsoring in this person.\n");
    return 1;
        }

  write("Its not Max...\n");
    return 1;
        }
