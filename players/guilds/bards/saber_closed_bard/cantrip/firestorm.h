/* This cantrip will dest any item which can be dropped */

firestorm(str)  {
object CANTRIP_TARG;

  if(spell(-50,0,5) ==-1) return 0;
  
  if(!INSTR->query_cantrip("C8"))  {
    write("You have not yet learned this cantrip.\n");
    return 1;
      }

  if(((TP->query_attrib("int")+TP->query_attrib("wil"))*2)+LEVEL<random(102) )
    { write("Your cantrip fails.\n"); 
      call_other(TP,"add_spell_point",-random(15)); 
      return 1; }
  
  if(!str)  {
    write("What object do you wish to fry?\n");
    return 1;
            }

  if(!(CANTRIP_TARG = present(str, TP)))    {
    write("\nYou are not holding a "+str+".\n\n");
    return 1;
            }

 if(call_other(CANTRIP_TARG, "drop", 0))  {
    write("\nYour cantrip is not powerful enough to fry the "+str+".\n\n");
    return 1;
       }

  if(COLOR)  {
    write("\nYou hum a dark melody.\n");
    say("\n"+tp+" hums a dark melody.\n");
    tell_room(ENV,
      "\nThe clouds above you roar with fury.\n"+
      "A "+HIR+"column of fire"+NORM+" descends from the heavens.\n\n");

  if(present("pro_from_cantrips", CANTRIP_TARG))  {
    tell_room(ENV,
      "\nA series of "+HIB+"runes"+NORM+" flare to life before "+
         CANTRIP_TARG->short()+".\n"+
      "The "+HIR+"column of fire"+NORM+" strikes "+CANTRIP_TARG->short()+".\n\n"+
      CANTRIP_TARG->short()+" is unharmed.\n");
     return 1;
          }

    tell_room(ENV,
      RED+""+CANTRIP_TARG->short()+" bursts into "+NORM+""+HIR+"flames."+NORM+"\n");

    write("You drop "+CANTRIP_TARG->short()+".\n");
    command("drop "+str, TP);

    tell_room(ENV,
      CANTRIP_TARG->short()+" is consumed in an inferno of "+HIR+"liquid fire"+NORM+".\n");

      }  else  {

    write("\nYou hum a dark melody.\n");
    say("\n"+tp+" hums a dark melody.\n");
    tell_room(ENV,
      "\nThe clouds above you roar with fury.\n"+
      "\nA column of fire descends from the heavens.\n\n");

  if(present("pro_from_cantrips", CANTRIP_TARG))  {
    tell_room(ENV,
      "\nA series of runes flare to life before "+CANTRIP_TARG->short()+".\n"+
      "The column of fire strikes "+CANTRIP_TARG->short()+".\n\n"+
      CANTRIP_TARG->short()+" is unharmed.\n");
     return 1;
          }

    tell_room(ENV,
    CANTRIP_TARG->short()+" bursts into flames.\n");

    write("You drop "+CANTRIP_TARG->short()+".\n");
    command("drop "+str, TP);
    destruct(CANTRIP_TARG);

    tell_room(ENV,
      "\n"+CANTRIP_TARG->short()+" is consumed in an inferno of liquid fire.\n");
          }
    
  call_other(TP, "add_spell_point", -10);
  return 1;
        }
