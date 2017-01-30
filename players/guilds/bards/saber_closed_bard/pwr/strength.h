/*
 *  A spell that tells % of the opponents health and rough wc and ac.
 *  For the Storm Bards of Ryllian
 *  v3.0 by Saber / Geoffrey Z.
 *
 */

strength(str)  {

object MARK;
int HEALTH, NUMBER, WEAPON, ARMOR;
string ARMORS, WEAPONS;

  if(!str)  {
    write("You must play the melody to a creature.\n");
    write("Syntax: strength (or stre) < creature >\n");
    return 1;
        }

  MARK = present(str, ENV);
  
  if(!MARK)  { write("You don't see "+CAP+" here.\n"); return 1; }
  if(!(living(MARK)))  { write(CAP+" is not alive!\n");  return 1; }

  say(tp+" plays a simple melody upon "+POSS+" "+INST+".\n");
  write("You play the Melody of Strength upon your "+INST+".\n\n");
 
      ARMOR  = MARK->query_ac();
      WEAPON = MARK->query_wc();
      HEALTH = MARK->query_hp() * 100 / MARK->query_mhp();

            if(ARMOR < 3)                ARMORS = "pitiful";
       else if(ARMOR > 2  && ARMOR < 5)  ARMORS = "poor";
       else if(ARMOR > 4  && ARMOR < 8)  ARMORS = "average";
       else if(ARMOR > 7  && ARMOR < 12) ARMORS = "good";
       else if(ARMOR > 11 && ARMOR < 16) ARMORS = "excellent";
       else if(ARMOR > 15)               ARMORS = "amazing";
 
            if(WEAPON < 5)                 WEAPONS = "pitiful";
       else if(WEAPON > 4  && WEAPON < 11) WEAPONS = "poor";
       else if(WEAPON > 10 && WEAPON < 15) WEAPONS = "average";
       else if(WEAPON > 14 && WEAPON < 19) WEAPONS = "good";
       else if(WEAPON > 18 && WEAPON < 25) WEAPONS = "excellent";
       else if(WEAPON > 26)                WEAPONS = "amazing";

      if(MARK = TP)  {
      write(BOLD+"You"+NORM+" have "+ARMORS+" armor, "+WEAPONS+
            " weaponry and is at "+HEALTH+" % health.\n");       
        } else {
      write(BOLD+MARK->query_name()+NORM+" has "+ARMORS+" armor, "+WEAPONS+
            " weaponry and is at "+HEALTH+" % health.\n");
        }       

   write("\n");
   return 1;
      }
