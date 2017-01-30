 /* The wilt cantrip will destroy any rose/flower/plant in/on the room/target */

wilt(str)  {
object CANTRIP_TARG, FLOWER_TARG, MARKER, MARKER2;
int COUNT, i, c;

  if(spell(-50,0,10) ==-1) return 0;
  
  if(!INSTR->query_cantrip("C29"))  {
    write("You have not yet learned this cantrip.\n");
    return 1;
      }

  if(((TP->query_attrib("int")+TP->query_attrib("wil"))*2)+LEVEL<random(102) )
    { write("Your cantrip fails.\n"); 
      call_other(TP,"add_spell_point",-random(15)); 
      return 1; }
  
 /* If a target is specified  */

  if(str)  {       
    if(!(CANTRIP_TARG = present(str, ENV)))    {
      write("\n"+str+" is not here to target.\n\n");
      return 1;
            }

    write("\nYou point at "+CANTRIP_TARG+" and snap your fingers.\n\n");
    say("\n"+tp+" points at "+CANTRIP_TARG+" and snaps "+POSS+" fingers.\n\n");

   if(present("pro_from_cantrips", CANTRIP_TARG))  {
      tell_room(ENV,
        "A series of "+HIB+"runes"+NORM+" flare to life before "+CANTRIP_TARG->query_name()+".\n"+
        "The wilt cantrip fails.\n\n");
      call_other(TP, "add_spell_point", -10); 
      return 1;
          }

  /* If there is a monster named rose/flower/plant, damage it     */
  
    if(living(str))  {
    
     if(CANTRIP_TARG->id() == "rose"    || 
       CANTRIP_TARG->id() == "flower"  ||
       CANTRIP_TARG->id() == "plant"   &&
       !is_player(CANTRIP_TARG)        )  {   
      tell_room(ENV,
       "\nA dull aura covers "+capitalize(str)+".\n"+
       capitalize(str)+" begins to look sick.\n");
       
     CANTRIP_TARG->heal_self(-(10 + random(20)));
    
     call_other(TP, "add_spell_point", -10);
     return 1;
          }
    
  /* Wilt the target flower/plant/rose away */
    
    COUNT = 0; i = 0;
    FLOWER_TARG = first_inventory(CANTRIP_TARG);
    
    while(FLOWER_TARG)  {
      if(FLOWER_TARG->id() == "rose"   || FLOWER_TARG->id() == "flower"
                                       || FLOWER_TARG->id() == "plant")  {   
      if(call_other(FLOWER_TARG, "drop", 1))  { 
      if(!present("pro_from_cantrips", FLOWER_TARG))  {
       tell_room(ENV,
            "\n"+FLOWER_TARG->short()+" falls from "+capitalize(str)+"'s hand.\n"+
            "\n"+FLOWER_TARG->short()+" wilts away into nothingness.\n\n");
       MARKER = FLOWER_TARG;
       i = 1;
       COUNT = COUNT + 1;
        }
        }
        }
       FLOWER_TARG = next_inventory(FLOWER_TARG);
       if(i > 0) {  destruct(MARKER); i = 0;  }
        }}

    if(COUNT < 1)  {
      write(capitalize(str)+" carries nothing which will wilt.\n");
        }    

  call_other(TP, "add_spell_point", -10);
  return 1;
        }
   
  /* No target is specified, so we hit the whole area */ 
   
  write("\nYou clap your hands together and snap your fingers.\n\n");
  say("\n"+tp+" claps "+POSS+" cands together and snaps "+POSS+" fingers.\n\n");

  COUNT = 0;  i = 0; c = 0;
  CANTRIP_TARG = first_inventory(ENV);
  
  while(CANTRIP_TARG)  {
   if(CANTRIP_TARG->id() == "rose"   || CANTRIP_TARG->id() == "flower"
                                     || CANTRIP_TARG->id() == "plant")  {
   if(!living(CANTRIP_TARG))  {
    if(present("pro_from_cantrips", CANTRIP_TARG))  {
      tell_room(ENV,
        "A series of "+HIB+"runes"+NORM+" flare to life before "+CANTRIP_TARG->short()+".\n"+
        "The wilt cantrip fails.\n\n");
         i = 1;
       }
     MARKER = CANTRIP_TARG;      if(i == 1)  { i = 2; }
     if(i == 1)  {
      tell_room(ENV,
       "\n"+MARKER->short()+" falls from "+environment(MARKER)->query_name()+"'s hand.\n"+
       "\n"+MARKER->short()+" wilts away into nothingness.\n\n");
      COUNT = COUNT + 1;

       }
       }
       }
   
   FLOWER_TARG = first_inventory(CANTRIP_TARG);
   
   while(FLOWER_TARG)  {
   if(FLOWER_TARG->id() == "rose"   || FLOWER_TARG->id() == "flower"
                                    || FLOWER_TARG->id() == "plant")  {
   if(present("pro_from_cantrips", FLOWER_TARG))  {
     tell_room(ENV,
        "A series of "+HIB+"runes"+NORM+" flare to life before "+FLOWER_TARG->short()+".\n"+
        "The wilt cantrip fails.\n\n");
         c = 1;
       }
     MARKER2 = FLOWER_TARG;      if(c == 1)  { c = 2; }
     if(i == 1)  {
      tell_room(ENV,
       "\n"+MARKER2->short()+" falls from "+capitalize(environment(MARKER)->query_name())+"'s hand.\n"+
       "\n"+MARKER2->short()+" wilts away into nothingness.\n\n");
      COUNT = COUNT + 1;
       }
       }
   FLOWER_TARG = next_inventory(FLOWER_TARG);
   if(i > 0 && i < 2) {  destruct(MARKER2);  }   i = 0;
       }
   
   CANTRIP_TARG = next_inventory(CANTRIP_TARG);
   if(c > 0 && c < 2) {  destruct(MARKER2); }   c = 0;
       }

   if(COUNT < 1)  {
      write("There is nothing here to wilt.\n");
        }    
   
  call_other(TP, "add_spell_point", -10);
  return 1;
        }
