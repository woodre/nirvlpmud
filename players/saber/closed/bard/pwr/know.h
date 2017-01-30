/*
 *  True Speak: Know
 *
 *    Gives info on weapons/objects/monsters
 *
 *  v3.0 by Saber / Geoffrey Z.
 *
 */

know(str)  {
object KNOW;
string TEMP, WEAPON, ARMOR, WIMP, ALIGNME;
int WEAP, ARM, HEALTH_LEVEL, TEMPO, ALIGNM;
  
  if(!str)  {
    write("Syntax: ko < item > or < creature > \n");
    return 1;
        }

  if(spell(-50,8,20) == -1)  return 0;        

  if(!INSTR->query_know_spell("know_know"))  {
    write("You have not yet learned the words of knowledge.\n");
    return 1;
      }
  
  if(!(KNOW = present(str, ENV)))  {
   if(!(KNOW = present(str, TP)))  {
    write("There is no "+str+" here to know.\n");
    return 1;
      }
      }
  
    write("\nYou lift your right hand and sing\n\n"); 
    say("\n"+tp+" lifts "+POSS+" right hand and sings\n\n"); 
    tell_room(ENV, 
    "       \""+BOLD+"Gu ski nojuko reri paskoda for jatcuru ski seya"+NORM+"\".\n\n");

if(COLOR)  { 
  if(KNOW->is_player())  {
    tell_room(ENV, 
        BOLD+KNOW->query_name()+NORM+" begins to "+HIY+"glow"+NORM+".\n");
     }  else  {
    tell_room(ENV, 
        BOLD+KNOW->short()+NORM+" begins to "+HIY+"glow"+NORM+".\n");
     }

   }  else  {
  if(KNOW->is_player())  {
    tell_room(ENV, 
        BOLD+KNOW->query_name()+NORM+" begins to glow.\n");
     }  else  {
    tell_room(ENV, 
        BOLD+KNOW->short()+NORM+" begins to glow.\n");
   }
   }


  if(10 + (TP->query_attrib("wil") * 4) + ((1 + BLVL) / 6) < random(100) )  {
    write("\nYour words of knowledge fail.\n");
    tell_room(ENV, "The glow surrounding "+lower_case(KNOW->short())+" fades away.\n\n");
    call_other(TP,"add_spell_point",-20); 
    return 1; 
      }
         
  call_other(TP, "add_spell_points", -20);

  if(living(KNOW))  {
  
   write("\n\n");
   write("  "+BOLD+KNOW->short()+NORM+"\n\n");
   write("  <NAME>   ");
   write(pad(KNOW->query_name(), 15));
   if(KNOW->query_race())  {
     write("<RACE>   "+KNOW->query_race());
      }
   write("\n");
   write("  <LEVEL>  ");
   write(pad(KNOW->query_level(), 15));
   
   HEALTH_LEVEL = KNOW->query_hp() * 100 / KNOW->query_mhp();
   
   write("<HEALTH> "+HEALTH_LEVEL+" % of total\n");
   write("\n");
  
    if(KNOW->is_player())  {
    
      write("  <ALIGNMENT> ");
      write(pad(KNOW->query_al_title(), 13));
      write("<GENDER>   "+KNOW->query_gender()+"\n");
      
      if(KNOW->query_wimpy()) { WIMP = "yes"; } else { WIMP = "no"; }
      write("  <WIMPY>     ");
      write(pad(WIMP, 13));
     
     if(KNOW->query_wc() > 3)  { 
      write("<WIELDING> "+KNOW->query_weapon()->query_name()+".\n\n");
        }  else  {
      write("<WIELDING> Nothing\n\n");
       
        }

      if(KNOW->query_hunted())  
        write("   Hunted by a "+KNOW->query_hunted()+".\n");
      if(KNOW->query_ghost())
        write("   "+KNOW->query_name()+" is a ghost.");
      if(KNOW->query_pregnancy())
        write("   "+KNOW->query_name()+" is pregnant.");
      if(KNOW->query_frog())
        write("   "+KNOW->query_name()+" is a frog.");
      if(KNOW->query_pl_k())
        write("   "+KNOW->query_name()+" is PK.");
      if(KNOW->query_crime())
        write("   "+KNOW->query_name()+" is a criminal.");
      
      write("\n");
    
      }  else  {
  
      write("\n   <ALIGNMENT> ");

      ALIGNM = KNOW->query_alignment();
      ALIGNME = check_ali(ALIGNM);

      write(pad(ALIGNME, 13));
      if(KNOW->query_hunted())  
        write("   Hunted by "+KNOW->query_hunted()+".\n");
      
      if(KNOW->query_aggressive())
        write("   "+KNOW->query_name()+" is aggressive.");
      if(KNOW->query_frog())
        write("   "+KNOW->query_name()+" is cursed.");
      if(KNOW->query_wimpy())
        write("   "+KNOW->query_name()+" is a wimp.");
      
      write("\n");

      if(KNOW->is_pet())
      write("   "+KNOW->query_name()+" is a pet or a kid.\n");
  
      }
      
     WEAP = KNOW->query_wc(); ARM = KNOW->query_ac();
     
     WEAPON = check_mwc(WEAP);  ARMOR  = check_mac(ARM); 
     
     write("   "+KNOW->query_name()+" has "+BOLD+WEAPON+NORM+
           " weapons and "+BOLD+ARMOR+NORM+" armor.\n\n");
  
  return 1;
        }
  
  
  /*  know an item */

  TEMPO = KNOW->query_save_flag();
  if(TEMPO == 0)  { TEMP = "yes"; }  else  { TEMP = "no "; }

  WEAP = KNOW->weapon_class(); ARM = KNOW->armor_class();
  
  if(WEAP > 0) WEAPON = check_wc(WEAP);
  
  if(ARM  > 0)   {
       if(KNOW->query_type() == "armor")  ARMOR  = check_aac(ARM); 
                                      else ARMOR  = check_ac(ARM);
                 }
             
  write("\n\n "+BOLD+KNOW->short()+NORM+"\n\n");

if(KNOW->query_value() > 1)  {
  write(" <VALUE>                   "+KNOW->query_value()+" golden coins.\n");
   }  else  {
  write(" <VALUE>                   This item has no value.\n");
   }

if(WEAP > 0)  {
  write(" <WEAPON>                  This is a "+BOLD+WEAPON+NORM+" weapon.\n");
   }  else  {
  write(" <WEAPON>                  This item has no value as a weapon.\n");
   }
   
if(ARM  > 0)  {
  write(" <ARMOR>                   This is "+BOLD+ARMOR+NORM+" armor.\n");
   }  else  {
  write(" <ARMOR>                   This item has no value as armor.\n\n");
   }
   
  write(" <WEIGHT> "+BOLD+KNOW->query_weight()+NORM+"   <SAVE>  "+BOLD+TEMP+NORM+
  "  <NAME> "+BOLD+capitalize(str)+NORM+"\n");

  write("\n");
  
  return 1; 
        }


check_aac(str)  {

  if(!str)  {  str == 0;  }

       if(str <  1) return "pitiful.  You call this armor?";
  else if(str == 1) return "poor";
  else if(str == 2)  return "average";
  else if(str == 3)  return "good";
  else if(str == 4)  return "excellent";
  else if(str == 5)  return "superb";
  else if(str >  5)  return "exquisit";
  else return "ERROR!";

  return 0;
  
        }


check_ac(str)  {

  if(!str)  {  str == 0;  }

       if(str <  1)  return "pitiful.  You call this armor?";
  else if(str == 1)  return "average";
  else if(str == 2)  return "superb";
  else if(str >  2)  return "exquisit";
  else return "ERROR!";

  return 0;
  
        }


check_ali(str)  {

  if(!str)  {  str == 0;  }

       if(str < -949)                 return "Diabolical";
  else if(str > -950 && str < -799)   return "Obscene";
  else if(str > -801 && str < -599)   return "Wicked";
  else if(str > -600 && str < -399)   return "Corrupt";
  else if(str > -400 && str < -199)   return "Vile";
  else if(str > -200 && str <  -50)   return "Malevolent";
  else if(str > -51  && str <   51)   return "Balanced";
  else if(str >   50 && str <  200)   return "Benevolent";
  else if(str >  199 && str <  400)   return "Virtuous";
  else if(str >  399 && str <  600)   return "Pure";
  else if(str >  599 && str <  800)   return "Magnanimous";
  else if(str >  799 && str <  950)   return "Righteous";
  else if(str >  949)                 return "Saintly";
  else return "ERROR!";
  
  return 0;
  
        }


check_mac(str)  {

  if(!str)  {  str == 0;  }
    
       if(str <  3)   return "pitiful.  Close your eyes and swing.\n   You'll still hit";
  else if(str >  2 && str < 5)  return "pitiful";
  else if(str >  4 && str < 7)  return "poor";
  else if(str >  6 && str < 9)  return "average";
  else if(str >  8 && str < 11) return "good";
  else if(str > 10 && str < 13) return "strong";
  else if(str > 12 && str < 15) return "excellent";
  else if(str > 14 && str < 17) return "exceptional";
  else if(str > 16 && str < 19) return "superb";
  else if(str > 18 && str < 21) return "amazing";
  else if(str > 20 && str < 23) return "exquisit";
  else if(str > 22 && str < 27) return "godlike";
  else if(str > 26)             return "godlike.  \n   Face it.  You're not going to hit.";
  else return "ERROR!";
  
  return 0;
  
        }


check_mwc(str)  {

  if(!str)  {  str == 0;  }

       if(str <  3)             return "pitiful.\n   Party naked!  It still won't hit.";
  else if(str >  2 && str < 5)  return "pitiful";
  else if(str >  4 && str < 7)  return "feeble";
  else if(str >  6 && str < 9)  return "weak";
  else if(str >  8 && str < 11) return "poor";
  else if(str > 10 && str < 13) return "below average";
  else if(str > 12 && str < 15) return "average";
  else if(str > 14 && str < 17) return "good";
  else if(str > 16 && str < 19) return "strong";
  else if(str > 18 && str < 21) return "excellent";
  else if(str > 20 && str < 23) return "deadly";
  else if(str > 22 && str < 25) return "exceptional";
  else if(str > 24 && str < 27) return "superb";
  else if(str > 26 && str < 29) return "amazing";
  else if(str > 28 && str < 31) return "exquisit";
  else if(str > 30 && str < 33) return "lethal";
  else if(str > 32 && str < 37) return "godlike";
  else if(str > 36)             return "godlike.\n   Run while you still can!";
  else return "ERROR!";
  
  return 0;
  
        }


check_wc(str)  {

  if(!str)  {  str == 0;  }

       if(str <  3)             return "wait...you call _that_ a weapon?";
  else if(str >  2 && str < 5)  return "pitiful";
  else if(str >  4 && str < 7)  return "feeble";
  else if(str >  6 && str < 9)  return "weak";
  else if(str >  8 && str < 11) return "poor";
  else if(str > 10 && str < 13) return "average";
  else if(str > 12 && str < 15) return "good";
  else if(str > 14 && str < 17) return "excellent";
  else if(str > 16 && str < 19) return "deadly";
  else if(str > 18 && str < 21) return "superb";
  else if(str > 20 && str < 23) return "exquisit";
  else if(str > 22 && str < 25) return "godlike";
  else if(str > 24)             return "godlike.  Wield this weapon!";
  else return "ERROR!";

  return 0;
  
        }
