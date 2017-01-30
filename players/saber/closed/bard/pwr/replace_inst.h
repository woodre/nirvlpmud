/*
 *  Replace a instrument on a bard.
 *  v3.0 by Saber / Geoffrey Z.
 *
 */


replace_inst(str)  {

string target;
int level, amount;
object instr, instr2;


  if(!str || sscanf(str, "%s", target) !=1)  {
    write("\nTo replace an instrument, type: < replace > < bard name >\n\n");
    return 1;
        }

  if(!(instr = find_player(target)))  {
    write("You can not find "+capitalize(str)+" within the realms of magic.\n");
    return 1;
        }
        
  if((instr->query_guild_name()) != "bards")  {
    write(capitalize(str)+" is not a BARD!\n");
    return 1;
        }
        
  instr2 = clone_object("/players/saber/closed/bard/instrument.c");
  move_object(instr2,instr);
  write("You have given "+capitalize(str)+" a new instrument.\n");
  tell_object(instr, "You have a new instrument.\n");
  return 1;
  
        }
