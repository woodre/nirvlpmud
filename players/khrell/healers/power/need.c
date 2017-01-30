#include "../def.h"

status main(string str, object PO, object User)
{
  object trg;
  object *who;
  string hpstat, spstat, msg;
  int INF;
  string def, any;
  string gname;
  int h, TTL, ST;
  int ac, hps, sps;
  int a,b;
  int ix, fo, sa;
  
  if(str) 
  {
    if(str != "room") 
    {
      TTL = User->LVL + User->EXLVL;
      ST = 0;

      trg = find_player(str);
 
      if(str == "guest") 
      { 
        write("You may not need guest.\n"); 
        return 1; 
      }
      if(!trg) 
      { 
        write("That person is not here.\n"); 
        return 1; 
      }
      if(trg->query_invis()) 
      { 
        write("That person is not here.\n"); 
        return 1; 
      }
      if(trg->LVL > 19)
      { 
        write("You can not do a need analysis on a wiz.\n");
        return 1; 
      }
      
      if(trg->MHP)
      {
        a = (((int)trg->HP * 10) / ((int)trg->MHP));   
        hpstat = ""+a;
      }
      else 
        hpstat = "0";
      
      if((string)environment(trg)->realm() == "NM" || environment(trg)->query_NM()) 
        spstat = " NM ";
 
      else if(trg->MSP)
      {
        b = (((int)trg->SP * 10) / ((int)trg->MSP)); 
        spstat = ""+b;
      }
      else 
        spstat = "0";
        
      INF = ""+( ((int)trg->query_infuse() * 10) / ((int)trg->query_infuse_limit()));
      ix = (int)trg->query_intoxination()*10/((int)trg->query_max_intox());
      fo = (int)trg->query_stuffed()*10/((int)trg->query_max_stuff());
      sa = (int)trg->query_soaked()*10/((int)trg->query_max_soak());

      gname = (string)trg->query_guild_name();

      if(!gname || gname == 0 || gname == "") 
        gname = "none";
   
      write("NEED ANALYSIS for "+capitalize(str)+"  <lvl: "+((int)trg->EXLVL + (int)trg->LVL) + ">"+
            "  [ "+gname+ " ]"+
            "\n\n"+
            "     HP: "+hpstat+"     SP: "+spstat+"     TR: "+INF);
      if(TTL > 10) 
        write("\n     I: "+ix+"       F: "+fo+"      S: "+sa);
      write("\n");
     
      if(environment(trg)) 
        write("     Loc: "+environment(trg)->short());

      if((string)environment(trg)->realm() == "NT") 
        write("  [non-teleport]");

      write("\n     STATUS: ");

      if(!interactive(trg)) 
      { 
        write("DC"); 
        ST = 1; 
      }
      
      if(interactive(trg))
      {
        if(query_idle(trg) > 120) 
        { 
          write("IDLE"); 
          ST = 1; 
        }
        if(trg->query_attack()) 
        { 
          write("  COMBAT   ATT: "+(trg->query_attack())->short()); 
          ST = 1; 
        }
        if(trg->GHOST)
        { 
          write("  GHOST"); 
          ST = 1; 
        }
      }

      if(TTL > 7) 
      {  
        if(present("disease", trg) || present("virus", trg) || 
           present("VD", trg) || present("illness", trg) || 
           present("cold", trg)) 
        { 
          write("  SICK"); 
          ST = 1; 
        }
      
        if(present("poison", trg) || present("venom", trg)) 
        { 
          write("  POISON"); 
          ST = 1; 
        }
      }

      if(!ST) 
      write("  NORMAL");

      write("\n");

      if(TTL > 8) 
      { 
        ac = (int)trg->query_ac();

        write("     "); 
        write("Defense:  ");
         
        if(ac < 8)
         def = "WEAK";
        else if(ac < 12)
         def = "OKAY";
        else if(ac < 18)
         def = "BUFF";
        else
         def = "STRONG"; 
           
        write("+def+");
        write("\n"); 
      }
      
      if(TTL > 15) 
      { 
        ST = 0; 
        write("     STATS UNDER 30:");

        if(trg->query_attrib("str") < 30) 
        { 
          write(" STR"); 
          ST = 1; 
        }
        if(trg->query_attrib("mag") < 30) 
        { 
          write(" MAG"); 
          ST = 1; 
        }
        if(trg->query_attrib("sta") < 30) 
        { 
          write(" STA"); 
          ST = 1; 
        }
        if(trg->query_attrib("pie") < 30) 
        {
          write(" PIE"); 
          ST = 1; 
        }
        if(trg->query_attrib("int") < 30) 
        { 
          write(" INT"); 
          ST = 1; 
        }
        if(trg->query_attrib("luc") < 30) 
        { 
          write(" LUC"); 
          ST = 1; 
        }
        if(trg->query_attrib("ste") < 30) 
        { 
          write(" STE"); 
          ST = 1; 
        }
        if(trg->query_attrib("wil") < 30) 
        { 
          write(" WIL"); 
          ST = 1; 
        }
        if(trg->query_attrib("dex") < 30)
        {
          write(" DEX");
          ST = 1;
        } 
        if(trg->query_attrib("cha") < 30)
        {
          write(" CHA");
          ST = 1;
        }
    
        if(!ST) 
          write("  NONE");
      
        write("\n");
      }
      write("\n");
    } 
    else 
    {
      TTL = User->LVL + User->EXLVL;
 
      who = all_inventory(environment(User));
     
      write("NEED ANALYSIS for ALL Players in ROOM:\n\n");
      for(h=0; h<sizeof(who); h++) 
      {
        if(who[h]->LVL)
          if(environment(who[h]))
            if(who[h]->is_player())
              if(find_player(who[h]->RN))
                if((string)who[h]->RN != "guest")
                  if(who[h]->LVL < 20 && !who[h]->query_invis()) 
                  {
                    gname = (string)who[h]->query_guild_name();
                   
                    if(!gname || gname == 0 || gname == "") 
                      gname = "none";
                   
                    msg = (string)who[h]->QN;
                    msg += " <"+gname+">";
                       
                    while(strlen(msg) < 16) 
                      msg += " ";
                            
                    msg += " lvl: ";
                      
                    if(who[h]->EXLVL+who[h]->LVL < 10) 
                      msg += " "+who[h]->LVL;
                    else 
                      msg += who[h]->EXLVL+who[h]->LVL;
                         
                    if(who[h]->MHP) 
                    {
                      hps = (((int)who[h]->HP * 10) / ((int)who[h]->MHP));

                      switch(hps)
                      {
                        case 0: any = HIR+"ZERO*"+NORM; break;
                        case 1: any = HIR+"ZERO*"+NORM; break;
                        case 2: any = RED+"SOME "+NORM; break;
                        case 3: any = RED+"SOME "+NORM; break;
                        case 4: any = BLU+"HALF "+NORM; break;
                        case 5: any = BLU+"HALF "+NORM; break;
                        case 6: any = BLU+"HALF "+NORM; break;
                        case 7: any = GRN+"ALOT "+NORM; break;
                        case 8: any = GRN+"ALOT "+NORM; break;
                        case 9: any = "FULL "; break;
                        case 10: any = "FULL "; break;                     
                      }
                      msg += "  hp: "+any+"";
                    }
                      
                    if((string)environment(who[h])->realm() =="NM" || environment(who[h])->query_NM()) 
                      msg += "  sp:  NM  ";
                    else if(who[h]->MSP)
                    {
                      sps = (((int)who[h]->SP * 10) / ((int)who[h]->MSP));
 
                      switch(sps)
                      {
                        case 0: any = HIR+"ZERO*"+NORM; break;
                        case 1: any = HIR+"ZERO*"+NORM; break;
                        case 2: any = RED+"SOME "+NORM; break;
                        case 3: any = RED+"SOME "+NORM; break;
                        case 4: any = BLU+"HALF "+NORM; break;
                        case 5: any = BLU+"HALF "+NORM; break;
                        case 6: any = BLU+"HALF "+NORM; break;
                        case 7: any = GRN+"ALOT "+NORM; break;
                        case 8: any = GRN+"ALOT "+NORM; break;
                        case 9: any = "FULL "; break;
                        case 10: any = "FULL "; break;                     
                      }
                      msg += "  sp: "+any+"";
                    }

                    msg += "  ";
                           
                    ix = (int)who[h]->query_intoxination()*10/((int)who[h]->query_max_intox());
                    fo = (int)who[h]->query_stuffed()*10/((int)who[h]->query_max_stuff());
                    sa = (int)who[h]->query_soaked()*10/((int)who[h]->query_max_soak());
                              
                    if(TTL > 10) 
                    { 
                      msg += "I: "+ix+" F: "+fo+" S: "+sa;
                      msg += "   "; 
                    }
                    
                    if(!interactive(who[h])) 
                      msg += "DC   ";
                           
                    if(interactive(who[h]))
                    {
                      if(query_idle(who[h]) > 120) 
                        msg += "IDLE   ";
                                
                      if(who[h]->query_attack()) 
                        msg += "COMBAT   ";
                      
                      if(who[h]->GHOST)  
                        msg += "GHOST";
                    }
                    msg += NORM+"\n";
                    write(msg);
                  }
      }
      write("\n");
    }
    return 1; 
  }
   
  who = users();
  
  write("NEED ANALYSIS for ALL Players:\n\n");
  for(h=0; h<sizeof(who); h++) 
  {
    if(who[h]->LVL)
      if(environment(who[h]))
        if((string)who[h]->RN != "guest")
          if(who[h]->LVL < 20 && !who[h]->query_invis()) 
          {
            msg = (string)who[h]->QN;
                   
            while(strlen(msg) < 16) 
              msg += " ";
                  
            msg += "lvl: ";
               
            if(who[h]->EXLVL+who[h]->LVL < 10) 
              msg += " "+who[h]->LVL;
            else 
              msg += who[h]->EXLVL+who[h]->LVL;
                    
            if(who[h]->MHP) 
            {
              hps = (((int)who[h]->HP * 10) / ((int)who[h]->MHP));
                   
              switch(hps)
              {
                case 0: any = HIR+"ZERO*"+NORM; break;
                case 1: any = HIR+"ZERO*"+NORM; break;
                case 2: any = RED+"SOME "+NORM; break;
                case 3: any = RED+"SOME "+NORM; break;
                case 4: any = BLU+"HALF "+NORM; break;
                case 5: any = BLU+"HALF "+NORM; break;
                case 6: any = BLU+"HALF "+NORM; break;
                case 7: any = GRN+"ALOT "+NORM; break;
                case 8: any = GRN+"ALOT "+NORM; break;
                case 9: any = "FULL "; break;
                case 10: any = "FULL "; break;                     
              }
              msg += "  hp: "+any+"";
            }
                         
            if((string)environment(who[h])->realm() =="NM" || environment(who[h])->query_NM()) 
              msg += "  sp:  NM  ";
      
            else if(who[h]->MSP) 
            {
              sps = (((int)who[h]->SP * 10) / ((int)who[h]->MSP));
                      
              switch(sps)
              {
                case 0: any = HIR+"ZERO*"+NORM; break;
                case 1: any = HIR+"ZERO*"+NORM; break;
                case 2: any = RED+"SOME "+NORM; break;
                case 3: any = RED+"SOME "+NORM; break;
                case 4: any = BLU+"HALF "+NORM; break;
                case 5: any = BLU+"HALF "+NORM; break;
                case 6: any = BLU+"HALF "+NORM; break;
                case 7: any = GRN+"ALOT "+NORM; break;
                case 8: any = GRN+"ALOT "+NORM; break;
                case 9: any = "FULL "; break;
                case 10: any = "FULL "; break;                     
              }
              msg += "  sp: "+any+"";
            }
                                  
            msg += "   ";
            
            if(environment(who[h])) 
            {
              msg += "Loc: ";
              msg += (string)environment(who[h])->short();
              msg += NORM+"  ";
            }
                    
            if(!interactive(who[h])) 
              msg += "DC   ";
                    
            if(interactive(who[h]))
            {
              if(query_idle(who[h]) > 120) 
                msg += "IDLE   ";
                      
              if(who[h]->query_attack()) 
                msg += "COMBAT   ";
                        
              if(who[h]->GHOST)  
                msg += "GHOST";
            }
            msg += NORM+"\n";
            write(msg);
          }
  }
  write("\n");
  return 1; 
}
