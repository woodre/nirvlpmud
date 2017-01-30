/* This cantrip will take an item from a player, and move it to a random other
   other player on the mud  */

pixie(str)  {

object CANTRIP_TARG, *LIST, PIXIE_TARG, CANTRIP_OBJ;
int i, c, COUNT, CANTRIP_INT;
string PNAME;

  if(spell(-50,0,10) == -1)  return 0;
  
  if(!INSTR->query_cantrip("C19"))  {
    write("You have not yet learned this cantrip.\n");
    return 1;
      }

  if(((TP->query_attrib("int")+TP->query_attrib("wil"))*2)+LEVEL<random(102) )
    { write("Your cantrip fails.\n"); 
      call_other(TP,"add_spell_point",-random(15)); 
      return 1; }
  
  if(!str)  {
    write("Syntax: cantrip pixie < item >\n");
    return 1;
          }
  
  if(!(CANTRIP_TARG = present(str, TP)))  {
    write("\nA pixie flutters into the room and stares at you with a confused expression.\n"+
      "Pixie sings \"But you don't have a "+str+"...\"\n"+
      "The pixie flies away.\n\n");
    say("\nA pixie flutters into the room and stares at "+tp+".\n"+
      "The pixie looks confused, and then flies away.\n\n");
    return 1;
          }

 if(call_other(CANTRIP_TARG, "drop", 0))  {
   write("\nA pixie flutters into the room and grabs your "+capitalize(str)+".\n"+
     "The pixie looses her balance and falls to the ground.\n"+
     "Pixie wimpers \"\I can't carry that!\"\n"+
     "The pixie flutters away.\n\n");
   say("\nA pixie flutters into the room and hovers before "+tp+".\n"+
     "The pixie grabs "+tp+"'s "+capitalize(str)+", looses her balance, and falls to the ground.\n"+
     "The pixie looks abashed, wimpers, and flies away.\n\n");
    return 1;
       } 

  LIST = users(); 

  /* for(COUNT=0;COUNT<sizeof(LIST); ++COUNT);  */
  
  COUNT = random(sizeof(LIST));

  /* for(c=0;c<45;++c)  { */
   
  for(i=0;i<sizeof(LIST); ++i)  {
    if(i > COUNT)  {  

      PIXIE_TARG = LIST[i];
        if(PIXIE_TARG->query_level() < 1000)  { i = 50; }  
        
          }
          }
 
  
  write("\nA pixie flutters gracefully into the room and lands on your shoulder.\n"+
    "You whisper the word \""+str+"\" to the pixie.\n\n");
  say("\nA pixie flutters gracefully into the room and lands on "+tp+"'s shoulder.\n"+
    tp+" whispers the word \""+str+"\" to the pixie.\n\n");
  
  command("drop "+str, TP);
  
  str = lower_case(CANTRIP_TARG->short());
  PNAME = PIXIE_TARG->query_name();
  
  write("The pixie grabs "+str+" from you.\n");
  say("The pixie grabs "+str+" from "+tp+".\n\n");
    
  move_object(CANTRIP_TARG, environment(PIXIE_TARG));

  CANTRIP_INT = random(6);
  
  if(CANTRIP_INT == 0)  {
    tell_room(ENV,
      "With a gleam of tiny white teeth and a peal of laughter, the pixie flies away.\n\n");
    tell_room(environment(PIXIE_TARG),
      "An excited pixie glides into the room and drops a "+str+".\n"+
      "The pixie waves to "+PNAME+".\n"+
      "With a gleam of tiny white teeth and a peal of laughter, the pixie flies away.\n\n");
            }
  if(CANTRIP_INT == 1)  {
    tell_room(ENV,
      "Staggering from the weight, the pixie flutters slowly away.\n\n");
    tell_room(environment(PIXIE_TARG),
      "\nA pixie flutters slowly into the room, burdened by "+str+".\n"+
      "The pixie drops "+str+" in front of "+PNAME+".\n"+
      "With a smile, the pixie flits gracefully from the room.\n\n");
            } 
  if(CANTRIP_INT == 2)  {
    tell_room(ENV,
      "The pixie does an aerial loop and zooms off into the sky.\n\n");
    tell_room(environment(PIXIE_TARG),
      "\nA pixie whizzes into the room, dropping "+str+" in front of "+PNAME+".\n"+
      "The pixie does an aerial loop and zooms off into the sky.\n\n");
            }
  if(CANTRIP_INT == 3)  {
    tell_room(ENV,
      "The pixie screams \"\Weeeeeeeeeeee\"\ and whizzes off into the sky.\n\n");
    tell_room(environment(PIXIE_TARG),
      "\nA pixie zooms into the room and drops "+str+" in front of "+PNAME+".\n"+
      "The pixie screams \"\Weeeeeeeeeeeeee\"\ and whizzes off into the sky.\n\n");
            }
  if(CANTRIP_INT == 4)  {
    tell_room(ENV,
      "The pixie flits up to your face and places a tiny kiss on your nose.\n"+
      "The pixie winks at you as she flutters away.\n\n");
    tell_room(environment(PIXIE_TARG),
      "\nA pixie flits into the room and drops "+str+".\n"+
      "The pixie flits up to your face and places a tiny kiss on your nose.\n"+
      "The pixie winks at "+PNAME+" as she flutters away.\n\n");
            }
   if(CANTRIP_INT == 5)  {
     tell_room(ENV,
       "The pixie grins wildly as she whirls off into the sky.\n\n");
     tell_room(environment(PIXIE_TARG),
       "\nA wildly grinning pixie whirls into the room and drops "+str+".\n"+
       "The pixie looks up at "+PNAME+", grins, and zooms off into the sky.\n\n");
            }
   
  call_other(TP, "add_spell_point", -10); 
  return 1;
          }
