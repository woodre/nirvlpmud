/* This cantrip will vandalize a room, item or monster */

vandalize(str)  {
string X1, X2, VAND;
object CANTRIP_TARG;
 
 if(attack_spell(-50,0,5,CANTRIP_TARG) == -1) return 0;

  if(!INSTR->query_cantrip("C27"))  {
    write("You have not yet learned this cantrip.\n");
    return 1;
      }

  if(((TP->query_attrib("int")+TP->query_attrib("wil"))*2)+LEVEL<random(102) )
    { write("Your cantrip fails.\n"); 
      call_other(TP,"add_spell_point",-random(15)); 
      return 1; }
  
 sscanf(str, "%s %s", X1, X2);      
 
 if(!str)  {
   write("What do you wish to vandalize?\n");
   return 1;
        }
 
  if(!(CANTRIP_TARG = present(X1, TP)))  {
   if(!(CANTRIP_TARG = present(X1, environment(TP))))  {
    write("There is no "+capitalize(X1)+" here.\n");
    return 1;
          }
          }
          
   if(!X2)             { VAND = tp+" was here";                 }
   else if(X2 == "1")  { VAND = "Bards Rule!";                  }
   else if(X2 == "2")  { VAND = "We are the blessed of Crysea"; }
   else if(X2 == "3")  { VAND = "No Fear!";                     }
   else { write("<Cantrip help vandalize> for a list of options.\n"); return 1; }
   
   CANTRIP_TARG = ENV;
   
   CANTRIP_TARG->set_long(CANTRIP_TARG->long()+"\n"+
     "Runes of smoke spelling \""+BOLD+""+VAND+"\" hang in the air.\n");
   
   if(COLOR)  {
   write("\nYou whisper "+BOLD+"\"Fyre de Sol iche nas"+NORM+".\"\n"+
         "You fingers begin to glow "+HIR+"Crimson"+NORM+".\n"+
         "With quick strokes, you spell the runes "+BOLD
         +""+VAND+""+NORM+" in the air.\n");
   say("\n"+tp+" whispers "+BOLD+"\"Fyre de Sol iche nas"+NORM+".\"\n"+
         tp+"'s fingers begin to glow "+HIR+"Crimson"+NORM+".\n"+
         "With quick strokes, "+PRO+" spells out the runes "+BOLD
         +""+VAND+""+NORM+" in the air.\n");  
      }  else  {
   write("\nYou whisper "+BOLD+"\"Fyre de Sol iche nas"+NORM+".\"\n"+
         "You fingers begin to glow Crimson.\n"+
         "With quick strokes, you spell the runes "+BOLD
         +""+VAND+""+NORM+" in the air.\n");
   say("\n"+tp+" whispers "+BOLD+"\"Fyre de Sol iche nas"+NORM+".\"\n"+
         tp+"'s fingers begin to glow Crimson.\n"+
         "With quick strokes, "+PRO+" spells out the runes "+BOLD
         +""+VAND+""+NORM+" in the air.\n");  
  
  call_other(TP, "add_spell_point", -5); 
  return 1;
        } 
      

 if(!living(X1))  {
      
  write("\nYou trace the runes for your name in the air\n"+
        "Holding up "+lower_case(CANTRIP_TARG->short())+", you softly blow the glowings runes towards it.\n"+
        "The runes \""+BOLD+""+tp+""+NORM+"\"\ inscribe themselves on "+lower_case(CANTRIP_TARG->short())+"\n"); 
  say("\n"+tp+" traces the runes for "+POSS+" name in the air.\n"+
      tp+" holds up "+lower_case(CANTRIP_TARG->short())+" and blows the glowing runes towards it.\n"+
      "The runes \""+BOLD+""+tp+""+NORM+"\"\ inscribe themselves on "+lower_case(CANTRIP_TARG->short())+"\n");      
    
  CANTRIP_TARG->set_long(CANTRIP_TARG->long()+"\n"+
     "Runes spelling \""+BOLD+""+tp+""+NORM+"\"\ gleam in the light.\n");

  
  if(present("pro_from_cant", CANTRIP_TARG))  { 
    tell_room(ENV, HIB+"Runes of blue"+NORM+" flash suddenly around "+
              lower_case(CANTRIP_TARG->short())+".\n"+
              "The glowing letters fade away.\n");
    call_other(TP, "add_spell_point", -5); 
    return 1;
          }         
          }
        
  write("You can not vandalize a "+capitalize(str)+".\n");
  return 1;
        }
