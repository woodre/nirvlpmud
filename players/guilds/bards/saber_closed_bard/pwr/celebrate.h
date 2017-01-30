/*
 *  Lets a Bard celebrate with their mentor.
 *  This gives the Bard the ability to sponsor another.
 *  v3.0 by Saber / Geoffrey Z.
 *
 */

celebrate(str)  {
string who;
int sponsor_left;
object ob, MENTOR;


if(spell(-100,8,0) == -1) return 0;


if(!str || sscanf(str, "%s", who) !=1)  {
  write("Syntax: celebrate < mentor >\n");
  return 1;
        }

if(!(MENTOR = present(who, environment(TP))))  {
  write(CAP+" is not close enough to celebrate with.\n");
  return 1;
        }

if(INSTR->query_celebrate() > 0)  {
  write("You have celebrated with your sponsor!\n");
  return 1;
        }

if(INSTR->query_sponsor() != ob->query_name())  {
  write(ob->query_name()+" was not your sponsor!\n");
  return 1;
        }

if(!(ob = present("instrument", MENTOR))) {
  write(ob->query_name()+" is not a Bard!\n");
  return 1;
        }

  sponsor_left = ob->query_sponsor_number();

  ob->set_sponsor_number(sponsor_left - 1);

  INSTR->set_celebrate("partied");

  tell_room(ENV, "\n"+
  tp+" walks up to "+ob->query_name()+" and says \"I have studied long.\"\n\n");

  tell_room(ENV,   
  ob->query_name()+" says \"You are no longer a student.\"\n\n");

  tell_room(ENV, "\n"+
  tp+" says \"Thank you for being my sponsor.\"\n\n");

  tell_room(ENV,   
  ob->query_name()+" says \"I am glad to see I choose well.\"\n\n");

  command("bte and "+ob->query_name()+" celebrate "+tp+"'s advancement from"+
          " the rank of Journeyman to Bard!" ,TP);

  write_file("/players/saber/closed/bard/log/celebrate",tp+"("+
  tp+") celebrated with "+ ob->query_name()+"("+ob->query_level()+")->"+ctime(time())+"\n");
  return 1;
        }
