/*
 *  The Bless spell for the Bardic Guild or Ryllian
 *  v3.0 by Saber / Geoffrey Z.
 *
 */


bless(str)  {

object BLESSING, BLESSED;
string SELF, SELF1;

  if(!str)   str = TPQ;
  
  if(!(BLESSED = present(str, ENV)))  {
    write("\n"+CAP+" is not here to bless.\n");
    write("Syntax: < bless > < player >\n");
    return 1;
        }

  if(!(BLESSED->is_player()))  {
    write("You may only bless players.\n");
    return 1;
        }

  if(spell(-50,3,20) == -1) return 0;

  if(present("blessing_obj", BLESSED))  {
    write("\nYou sense that "+CAP+" still carries the aura of the blessed!\n\n");
    return 1;
        }

  if(BLESSED = TP)  { 
    SELF = "your shoulder";  SELF1 = POSS+" shoulder";
        }  else  {           SELF = str;   SELF1 = str;
        }

  write("\nPlacing your hand upon "+SELF+", you sing\n");
  say("\n"+tp+" places "+POSS+" hand upon "+SELF1+" and sings\n");
  tell_room(ENV, "    \"Seri wyrd Crysea di blyss protecti ahi gaudr\"\n");
  tell_object(BLESSED, "You feel a warm glow spread through your body.\n");
    if(COLOR)  {
      tell_room(ENV, CAP+" begins to "+HIR+"glow"+NORM+" with an "+HIR+
                         "aura of protection"+NORM+".\n");
        }  else  {
      tell_room(ENV, CAP+" begins to glow with an aura of protection.\n\n");
        }
  
  BLESSING = clone_object("/players/saber/closed/bard/itm/blessing.c");
  move_object(BLESSING, BLESSED);
  call_other(TP, "add_spell_point", -20);
  return 1;
        }
