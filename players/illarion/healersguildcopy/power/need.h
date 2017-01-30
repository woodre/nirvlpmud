need(str) {
object trg;
string hpstat, spstat, msg;
string INF;
string gname;
int h, TTL, ST;
int ix, fo, sa;
   if(str) {
      if(str != "room") {
      TTL=tl+tx;
	  ST = 0;
	  trg = find_player(str);
      if(str == "guest") { write("You may not need guest.\n"); return 1; }
      if(!trg) { write("That person is not here.\n"); return 1; }
      if(trg->query_invis()) { write("That person is not here.\n"); return 1; }
      if(trg->query_level() > 19) { write("You can not do a need analysis on a wiz.\n");
                                     return 1; }
      if(trg->query_mhp()) hpstat = ""+(trg->query_hp() * 10/trg->query_mhp());
	    else hpstat = "0";
      if(environment(trg)->realm() == "NM" || environment(trg)->query_NM()) spstat = " NM ";
      else if(trg->query_msp()) spstat = ""+(trg->query_sp() * 10/trg->query_msp());
	       else spstat = "0";
	  INF = ""+(trg->query_infuse() * 10/trg->query_infuse_limit());
          ix = trg->query_intoxination()*10/(trg->query_max_intox());
          fo = trg->query_stuffed()*10/(trg->query_max_stuff());
          sa = trg->query_soaked()*10/(trg->query_max_soak());
	  gname = trg->query_guild_name();
	  if(!gname) gname = "none";
	  if(gname == 0) gname = "none";
	  if(gname == "") gname = "none";
      write("NEED ANALYSIS for "+capitalize(str)+"  <lvl: "+(trg->query_extra_level() + trg->query_level()) + ">"+
            "  [ "+gname+ " ]"+
            "\n\n"+
            "     HP: "+hpstat+"     SP: "+spstat+"     TR: "+INF);
			if(TTL > 10) write("\n     I: "+ix+"       F: "+fo+"      S: "+sa);
			write("\n");
            if(environment(trg)) write("     Loc: "+environment(trg)->short());
			if(environment(trg)->realm() == "NT") write("  [non-teleport]");
			write("\n     STATUS: ");
			if(!interactive(trg)) { write("DC"); ST = 1; }
			if(interactive(trg)){
			  if(query_idle(trg) > 120) { write("IDLE"); ST = 1; }
              if(trg->query_attack()) { write("  COMBAT   ATT: "+(trg->query_attack())->short()); ST = 1; }
              if(trg->query_ghost()){ write("  GHOST"); ST = 1; }
			}
			if(TTL > 7) {  if(present("disease",trg) || present("virus",trg) || present("VD",trg) ||
			                  present("illness",trg) || present("cold",trg)) { write("  SICK"); ST = 1; }
						if(present("poison",trg) || present("venom",trg)) { write("  POISON"); ST = 1; }
						}
			if(!ST) write("  NORMAL");
			write("\n");
            if(TTL > 8) { write("     "); write("Defense:  "+needDef(trg->query_ac())+"\n"); }
            if(TTL > 15) { ST = 0; write("     STATS UNDER 20:");
			               if(trg->query_attrib("str") < 20) { write(" STR"); ST = 1; }
	                       if(trg->query_attrib("mag") < 20) { write(" MAG"); ST = 1; }
						   if(trg->query_attrib("sta") < 20) { write(" STA"); ST = 1; }
						   if(trg->query_attrib("pie") < 20) { write(" PIE"); ST = 1; }
						   if(trg->query_attrib("int") < 20) { write(" INT"); ST = 1; }
						   if(trg->query_attrib("luc") < 20) { write(" LUC"); ST = 1; }
						   if(trg->query_attrib("ste") < 20) { write(" STE"); ST = 1; }
						   if(trg->query_attrib("wil") < 20) { write(" WIL"); ST = 1; }
						   if(!ST) write("  NONE");
						  write("\n");
						  }
	     write("\n");
     } else {
	 TTL=tl+tx;
	   trg = all_inventory(environment(tp));
	        write("NEED ANALYSIS for ALL Players in ROOM:\n\n");
	        for(h=0;h<sizeof(trg);h++) {
	           if(trg[h]->query_level())
	             if(environment(trg[h]))
				   if(trg[h]->is_player())
				     if(find_player(trg[h]->query_real_name()))
	                if(trg[h]->query_real_name() != "guest")
	               if(trg[h]->query_level() < 20 && !trg[h]->query_invis()) {
					    gname = trg[h]->query_guild_name();
					   	 if(!gname) gname = "none";
					   	 if(gname == 0) gname = "none";
	                     if(gname == "") gname = "none";
	                     msg = trg[h]->query_name();
	                     msg += " <"+gname+">";
	                     while(strlen(msg) < 16) msg += " ";
	                     msg += " lvl: ";
	                     if(trg[h]->query_extra_level()+trg[h]->query_level() < 10) msg += " "+trg[h]->query_level();
	                     else msg += trg[h]->query_extra_level()+trg[h]->query_level();
	                     if(trg[h]->query_mhp()) msg = "   "+msg+"  hp: "+needany(trg[h]->query_hp() * 10/trg[h]->query_mhp());
	                     else msg = "   "+msg+"  hp: "+needany(0);
	   				  if(environment(trg[h])->realm() =="NM" || environment(trg[h])->query_NM()) msg += "  sp:  NM  ";
	                     else if(trg[h]->query_msp()) msg += "  sp: "+needany(trg[h]->query_sp() * 10/trg[h]->query_msp());
	                           else msg += "  sp: "+needany(0);
	   				  msg += "  ";
					  ix = trg[h]->query_intoxination()*10/(trg[h]->query_max_intox());
					  fo = trg[h]->query_stuffed()*10/(trg[h]->query_max_stuff());
                                          sa = trg[h]->query_soaked()*10/(trg[h]->query_max_soak());
					  if(TTL > 10) { msg += "I: "+ix+" F: "+fo+" S: "+sa;
					   msg += "   "; }
				  if(!interactive(trg[h])) msg += "DC   ";
			      if(interactive(trg[h])){
				    if(query_idle(trg[h]) > 120) msg += "IDLE   ";
                    if(trg[h]->query_attack()) msg += "COMBAT   ";
                    if(trg[h]->query_ghost())  msg += "GHOST";
                  }
	                     msg += NORM+"\n";
	                     write(msg);
	              }
	        }
     write("\n");
	 }
   return 1; }
   trg = users();
     write("NEED ANALYSIS for ALL Players:\n\n");
     for(h=0;h<sizeof(trg);h++) {
        if(trg[h]->query_level())
          if(environment(trg[h]))
             if(trg[h]->query_real_name() != "guest")
            if(trg[h]->query_level() < 20 && !trg[h]->query_invis()) {
                  msg = trg[h]->query_name();
                  while(strlen(msg) < 16) msg += " ";
                  msg += "lvl: ";
                  if(trg[h]->query_extra_level()+trg[h]->query_level() < 10) msg += " "+trg[h]->query_level();
                  else msg += trg[h]->query_extra_level()+trg[h]->query_level();
                  if(trg[h]->query_mhp()) msg = "   "+msg+"  hp: "+needany(trg[h]->query_hp() * 10/trg[h]->query_mhp());
                  else msg = "   "+msg+"  hp: "+needany(0);
				  if(environment(trg[h])->realm() =="NM" || environment(trg[h])->query_NM()) msg += "  sp:  NM  ";
                  else if(trg[h]->query_msp()) msg += "  sp: "+needany(trg[h]->query_sp() * 10/trg[h]->query_msp());
                        else msg += "  sp: "+needany(0);
				  msg += "   ";
                  if(environment(trg[h])) {
                    msg += "Loc: ";
                    msg += pad(environment(trg[h])->short(),13);
                    msg += NORM+"  ";
                  }
				  if(!interactive(trg[h])) msg += "DC   ";
			      if(interactive(trg[h])){
				    if(query_idle(trg[h]) > 120) msg += "IDLE   ";
                    if(trg[h]->query_attack()) msg += "COMBAT   ";
                    if(trg[h]->query_ghost())  msg += "GHOST";
                  }
				  msg += NORM+"\n";
                  write(msg);
           }
     }
     write("\n");
  return 1; }


needany(int a) {
string what;
  switch(a) {
    case 0: what = HIR+"ZERO*"+NORM; break;
    case 1: what = HIR+"ZERO*"+NORM; break;
    case 2: what = RED+"SOME "+NORM; break;
    case 3: what = RED+"SOME "+NORM; break;
    case 4: what = BLU+"HALF "+NORM; break;
    case 5: what = BLU+"HALF "+NORM; break;
    case 6: what = BLU+"HALF "+NORM; break;
    case 7: what = GRN+"ALOT "+NORM; break;
    case 8: what = GRN+"ALOT "+NORM; break;
    case 9: what = "FULL "; break;
    case 10: what = "FULL "; break;
    default : what = " NM "; break;
  }
return what; }

needDef(int a) {
string what;
  switch(a) {
    case -5:
	case -4:
	case -3:
	case -2:
	case -1:
    case 0:
    case 1: what = "WEAK"; break;
    case 2:
    case 3:
    case 4: what = "OKAY"; break;
    case 5:
    case 6:
    case 7: what = "BUFF"; break;
    default: what = "STRONG"; break;
  }
return what; }

