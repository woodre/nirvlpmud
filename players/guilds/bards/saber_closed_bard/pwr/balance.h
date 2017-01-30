/*
 *  A spell to check if a creature is good or evil for the Bards of Ryllian.
 *  v3.0 by Saber / Geoffrey Z.
 *
 */

balance(str)  {
object ob;

  if(!str)  {
    write("Syntax: balance < creatue >\n");
    return 1;
        }
        
  ob = present(str, ENV);
    if(!ob)  { write("There is no "+str+" here to be balanced.\n");
                   return 1;   }

  say(tp+" fingers "+POSS+" "+INST+" as "+PRO+" glances at "+ob->query_name()+".\n");
  write("You finger your "+INST+" as you glance at "+ob->query_name()+".\n");
  
       if(ob->query_alignment() < -50)
       write(BOLD+ob->query_name()+NORM+"'s soul is balanced towards "+HIB+BOLD+"darkness"+NORM+".\n");
  else if(ob->query_alignment() > 50)
       write(BOLD+ob->query_name()+NORM+"'s soul is balanced towards the "+HIY+BOLD+"light"+NORM+".\n");
  else
       write(BOLD+ob->query_name()+NORM+"'s soul is in "+BOLD+"balance"+NORM+".\n");

  return 1;
       }
