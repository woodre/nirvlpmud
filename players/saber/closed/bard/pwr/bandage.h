/*
 *  A minor healing ability for the Storm Bards of Ryllian.
 *  This spell heals random(pie)/2 + 10hp for 15 sp (ave 15 w/ 20 pie)
 *  v3.0 by Saber / Geoffrey Z.
 *
 */

bandage(str)  {

object PLAYER;
int HEALING, TEMP, HEALTH;

  if(!str)  str = TPQ;
  
  PLAYER = present(str, ENV);
    if(!PLAYER)  { write("There is no "+str+" here to bandage.\n");
                   return 1;   }
  
  if(spell(-100,2,15) == -1) return 0;
  
  if(PLAYER->query_hp() == PLAYER->query_mhp())  {
    write(PLAYER->query_name()+" has no wounds to bandage.\n");
    return 1;
        }

  HEALING = TP->query_attrib("pie");
  HEALING = random(HEALING / 2) + 10;
  
  if(PLAYER->is_player())  { 
    PLAYER->add_hit_point(HEALING);
        }  else  {
    PLAYER->heal_self(HEALING);
        }

  HEALTH = PLAYER->query_hp() * 100 / PLAYER->query_mhp();  
  write(BOLD+"[ "+HEALING+" : "+HEALTH+"% ]\n"+NORM);
    
  if(str == TPQ)  {
    write("\nYou bandage your wounds.\n"+
          "You have been healed "+HEALING+" hit points.  "+
           BOLD+"[ "+HEALING+" : "+HEALTH+"% ]"+NORM+"\n\n");
    say("\n"+tp+" bandages "+POSS+" wounds.\n\n");
        }  else  {
    write("\nYou bandage "+CAP+"'s wounds.\n"+
          "You have healed "+CAP+" "+HEALING+" hit points.  "+
           BOLD+"[ "+HEALING+" : "+HEALTH+"% ]"+NORM+"\n\n");
    say("\n"+tp+" bandages "+CAP+"'s wounds.\n\n", PLAYER);
    tell_object(PLAYER,
        "\n"+tp+" bandages your wounds.\n"+
        "You have been healed "+HEALING+" hit points.\n\n");
        }
  
   call_other(TP, "add_spell_point", -15);     
   return 1;
        }
