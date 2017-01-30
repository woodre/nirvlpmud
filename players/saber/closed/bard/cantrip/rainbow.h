/* This cantrip will either make a rainbow in the room, or hit a target with
   a harmless color emote */

rainbow(str)  {
object CANTRIP_TARG;
int CANTRIP_INT;

  if(spell(-50,0,3,this_object()) == -1)  return 0;

  if(!INSTR->query_cantrip("C22"))  {
    write("You have not yet learned this cantrip.\n");
    return 1;
      }

  if(((TP->query_attrib("int")+TP->query_attrib("wil"))*2)+LEVEL<random(102) )
    { write("Your cantrip fails.\n"); 
      call_other(TP,"add_spell_point",-random(3)); 
      return 1; }
  
  if(!str)  {
  
    write("\nClapping your hands twice, you gaze up at the sky.\n");
    say("\n"+tp+" claps "+POSS+" hands together twice and looks up at the sky.\n");
    
    tell_room(ENV,
      "\nIn the distance, you see a "+
      HIR+"R"+RED+"A"+HIY+"I"+HIG+"N"+HIB+"B"+MAG+"O"+HIM+"W"+NORM+".\n\n");
    
  call_other(TP, "add_spell_point", -15); 
  return 1;
          }
  
  if(!(CANTRIP_TARG = present(str, ENV)))  {
    write("There is no "+capitalize(str)+" here to hit with a rainbow.\n");
    return 1;
          }
  
  write("\nYour clap your hands, sending a burst of "+
    HIR+"R"+RED+"A"+HIY+"I"+HIG+"N"+HIB+"B"+MAG+"O"+HIM+"W"+NORM 
    +" light at "+CANTRIP_TARG->query_name()+"."+NORM+"\n");
  say("\n"+tp+" claps "+POSS+" hands together, sending a burst of "+
    HIR+"R"+RED+"A"+HIY+"I"+HIG+"N"+HIB+"B"+MAG+"O"+HIM+"W"+NORM 
    +" light at "+CANTRIP_TARG->query_name()+"."+NORM+"\n", CANTRIP_TARG);
  tell_object(CANTRIP_TARG,
    "\n"+tp+" claps "+POSS+" hands together, sending a burst of "+
    HIR+"R"+RED+"A"+HIY+"I"+HIG+"N"+HIB+"B"+MAG+"O"+HIM+"W"+NORM 
    +" light at you!"+NORM+"\n");

  if(present("pro_from_cantrips", CANTRIP_TARG))  {
    tell_room(ENV,
      "\n"+HIB+"Runes of blue"+NORM+" appear before "+CANTRIP_TARG->query_name()+".\n"+
      "The "+HIR+"R"+RED+"A"+HIY+"I"+HIG+"N"+HIB+"B"+MAG+"O"+HIM+"W"+NORM
      +" fades away.\n");
      
    call_other(TP, "add_spell_point", -3); 
    return 1;
          } 

  CANTRIP_INT = random(6);

  if(CANTRIP_INT == 0)  {
    tell_room(ENV,
      "\n"+HIR+"R"+RED+"A"+HIY+"I"+HIG+"N"+HIB+"B"+MAG+"O"+HIM+"W"+NORM
      +" colors fly in all directions!\n");
          }
  if(CANTRIP_INT == 1)  {
    tell_room(ENV,
      "\nBlinding bursts of "+
      HIR+"R"+RED+"A"+HIY+"I"+HIG+"N"+HIB+"B"+MAG+"O"+HIM+"W"+NORM
      +" light gleam then are gone.\n");
          }
  if(CANTRIP_INT == 2)  {
    tell_room(ENV,
      "\n"+HIR+"R"+RED+"A"+HIY+"I"+HIG+"N"+HIB+"B"+MAG+"O"+HIM+"W"+NORM
      +" colors drip slowly off of "+CANTRIP_TARG+".\n");
          }
  if(CANTRIP_INT == 3)  {
    tell_room(ENV,
      "\n"+HIR+"R"+RED+"A"+HIY+"I"+HIG+"N"+HIB+"B"+MAG+"O"+HIM+"W"+NORM
      +" light sprays off of "+CANTRIP_TARG+".\n");
          }
  if(CANTRIP_INT == 4)  {
    tell_room(ENV,
      NORM+"\n");
          }
  if(CANTRIP_INT == 5)  {
    tell_room(ENV,
      "Rays of "+HIR+"R"+RED+"A"+HIY+"I"+HIG+"N"+HIB+"B"+MAG+"O"+HIM+"W"+NORM
      +" color shimmer momentarily and then fade away.\n");
          }

  call_other(TP, "add_spell_point", -3); 
  return 1;
          }
