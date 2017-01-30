#include "../defs.h"

status main(string str, object gob, object player)
{
	string *alphaall, *abilities;
	string what, cmd, doc; 
	int x, i, l, s;
	
	alphaall = ({ "absorb", "assign", "darts", "fatal", "flee", "hypermode", "KO", "lance", "list", "mp", 
		            "raise", "save", "score", "set", "shape" , "shed", "strike", "tentacles", "wep" });
	
  if((int)player->query_ghost()) return 0;
    
  if(!str)
  {
  	tell_object(player,
  	  SGC+"\n<<"+PGC+"==-==-==-==-==-==-=="+HIW+"   Neo Symbiote Guild   "+PGC+"==-==-==-==-==-==-=="+SGC+">>\n"+NORM);
    tell_object(player,"\n"+
      "  The Neo Symbiote guild of Nirvana LPMud is loosely based on\n"+
      "  the characters Venom(tm) and Carnage(tm) of Marvel Comics'\n"+ 
      "  Spiderman(tm) series.  The original idea and guild was the\n"+ 
      "  brainchild of Maledicta@Nirvana.  This second version is an\n"+ 
      "  adaptation of its precurosor, with both enchancements and\n"+
      "  changes designed to foster enjoyment and thematic role-play\n"+ 
      "  for guild members.\n"+
      "\n"+
      "  The help system is reached by typing 'help <topic>'.  For\n"+
      "  starters you may want to check out the following topics:\n"+
      "\n"+
      "     Getting Started       Theme               Advancement\n"+
      "     Skills                Matter Points       Tentacles\n"+
      "\n"+
      "  You may also access a list of all help files available to you\n"+
      "  by typing 'link help'.  Please keep in mind that this listing\n"+
      "  may change as you progress through the guild, so keep a close\n"+
      "  eye on it.\n");
    tell_object(player,
      SGC+"\n<<"+PGC+"==-==-==-==-==-==-==-==-==-==-====-==-==-==-==-==-==-==-==-==-=="+SGC+">>\n"+NORM);
    return 1;
    
  }
  if(str == "help")
  {
  	abilities = ({ "tentacles", "save", "mp", "list", "raise", "set", "assign" });
  	
  	tell_object(player,
  	  SGC+"\n<<"+PGC+"==-==-==-==-==-==-== "+HIW+"Neo Symbiote Abilities "+PGC+"==-==-==-==-==-==-=="+SGC+">>\n"+NORM);
  	
    if((int)gob->query_skill("combat") >= 1) abilities += ({ "wep", });
    if((int)gob->query_skill("combat") >= 2) abilities += ({ "strike", });
    if((int)gob->query_skill("combat") >= 3) abilities += ({ "KO", });
    if((int)gob->query_skill("combat") >= 4) abilities += ({ "fatal", });
    if((int)gob->query_skill("combat") >= 5) abilities += ({ "darts", });
    if((int)gob->query_skill("combat") >= 7) abilities += ({ "lance", });
    if((int)gob->query_skill("combat") >= 8) abilities += ({ "hypermode", });
    x = 0;
    for(i = 0; i < sizeof(alphaall); i++)
    {
      if(member_array(alphaall[i], abilities) > -1)
      {
      	if(x < 1)
      	{
      		tell_object(player, "       "+pad(CAP(alphaall[i]), 12)+"");
          x++;
      	}
      	else if(x < 3)
      	{
          tell_object(player, "  "+pad(CAP(alphaall[i]), 12)+"");
          x++;
        }
        else
        {
          tell_object(player, "  "+pad(CAP(alphaall[i]), 12)+"\n");
          x = 0;
        }
      }
    }
    tell_object(player,
      SGC+"\n<<"+PGC+"==-==-==-==-==-==-==-==-==-==-====-==-==-==-==-==-==-==-==-==-=="+SGC+">>\n"+NORM);
    return 1;
  }
  
  what = implode(explode(str, " "), "_");  
  what = lower_case(what);
  l = strlen(what);
  s = 0;
  while(s < l) 
  {
    if ((what[s] < 'a' || what[s] > 'z') &&	(what[s] < '0' || what[s] > '9') && what[s] != '_')
    {
      tell_object(player, "Subject not found.\n");
      return 1;
    }
    s += 1;
  }
  cmd = CMDDIR+what+".c";
  if(file_size(cmd) > 0)
  {
    cmd->help(gob, player);
    return 1;
  }
  doc = HELP+what+".c";
  if(file_size(doc) > 0)
  {
    doc->help(gob, player);
      return 1;
  }
  tell_object(player, "Subject not found.\n");
    return 1;  
  return 1;
}
