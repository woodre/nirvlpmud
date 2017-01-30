/*
 *  Lets a Bard sponsor another into the Bardic Guild of Ryllian.
 *  v3.0 by Saber / Geoffrey Z.
 *
 */

sponsor(str)  {
string who, sponsor;
int level, level2, ali, sponsor_left;
object ob, OB, GRACE;


if(spell(-100,8,0) == -1) return 0;


if(!str || sscanf(str, "%s", who) !=1)  {
  write("Syntax: sponsor < bard to be >\n");
  return 1;
        }


if(!present(who, environment(TP)))  {
  write(CAP+" is not close enough to sponsor.\n");
  return 1;
        }

if(
INSTR->query_sponsor_number() > 1)  {
  write("You have sponsored as many bards as your level permits.\n");
  return 1;
        }


  sponsor_left = INSTR->query_sponsor_number();

 
  ob = present(who, ENV);
  sponsor = ob->query_real_name();


if(ob->query_level() < 4)  {
  write("Players must be at least level four to join the Bardic Guild.\n");
  return 1;
        }


if(ob->query_guild_name() == "none" ||
   ob->query_guild_name() == 0 ||
   ob->query_guild_exp() == "0")  {


  if(!(GRACE = (present("bard_grace",ob)) || (GRACE->query_gifting() == tp)))  {
    write(CAP+" must have the good graces of a Bard other then yourself "+
              "before "+ob->query_pronoun()+" may be sponsored.\n");
    return 1;
       } 


  level = ob->query_level();
  INSTR->set_sponsor_number(sponsor_left + 1);
  INSTR->set_sponsored(INSTR->query_sponsored()+"-"+ob->query_real_name());


  OB = clone_object("/players/saber/closed/bard/instrument.c");
  move_object(OB,ob);


  while(ob->query_alignment() < 0)  {
       ali = ob->query_alignment();
       call_other(ob, "add_alignment", 50);
       }
  
  
  OB->set_bard_level(1);         OB->set_sponsor(tp);
  ob->set_guild_name("bard");    ob->set_title("the Apprentice");

  write("You have sponsored "+CAP+" into the Bardic Guild!.\n");
  tell_object(ob, "You have been sponsored into the Bardic Guild by "+tp+"\n"+
  "You are now a Bard!\n\n"+
  "Type 'lore' for information, and 'sco' to see your new stats.\n\n"+
  "You are given a Bardic Instrument.\n\n");


  command("bt A NEW BARD HAS ENTERED THE REALMS OF MAGIC",ob);
  command("pppp",ob);


  write_file("/players/saber/closed/bard/log/sponsor",tp+"("+
  tp+") sponsored "+ ob->query_name()+"("+ob->query_level()+")->"+ctime(time())+"\n");
  return 1;
        }


  write("The players is a member of another guild.  If there is a problem\n"+
    "ask a wizard for help.\n");
    return 1;
        }
