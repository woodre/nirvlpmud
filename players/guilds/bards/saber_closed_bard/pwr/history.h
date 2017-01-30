/*
 *  A spell to get info on a player for the Bardic Guild of Ryllian.
 *  v3.0 by Saber / Geoffrey Z.
 *
 */

int level, ex_lv;
string pretitle, name, title, gender, guild_name, al_title;
string description, lastime, cap_name;

history(str)  {
string nme;

  if(!str)  {
    write("History syntax: < History > < player_name >\n");
    return 1;
        }
  
 nme = explode(str,"");
 
 if(!restore_object("pfiles/"+nme[0]+"/"+lower_case(str)))  {
    write("That player has not visited the realms of magic.\n");
    return 1;
        }
  
  write("\n");
  write("    This is the history and lore of "+cap_name+".\n\n");
  
  if(guild_name == "none" || guild_name == 0)  {
    write(cap_name+" is a "+gender+" player who does not belong to a guild.\n\n");
        }  else  {
    write(cap_name+" is a "+gender+" player who belongs to the "+guild_name+" guild.\n\n");
        }
    write("The official title of "+cap_name+" is:\n");
    write("  "+pretitle+" "+cap_name+" "+title+"\n\n");
  if(description == 0)  {
    write(cap_name+" has no distinctive features...\n\n");
        }  else  {
    write(cap_name+" could roughly be described as:\n");
    write(cap_name+" "+description+" \n");
        }
    write(cap_name+" has earned "+level+" levels within the realms of magic.\n\n");
    write("Having studied "+cap_name+"'s history, you believe they are of "+
          al_title+" "+NORM+"alignment.\n\n");
    return 1;
        }
