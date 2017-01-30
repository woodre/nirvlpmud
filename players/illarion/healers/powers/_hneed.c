#include "../def.h"
inherit POWERBASE;

void reset() {
  special_target_string = "all|room";
  default_target = "room";
  spell_name = "need";
  target_range = "mud";
  requirements = ([ ]);
  costs = ([ ]);
}

string out_of_10(mixed x);

status main(string str, object target, object usr, object gob)
{  

  string hpstat,spstat;
  string infusion_info, intox_info, stuffed_info, soaked_info;
  string guild_name;
  string level_info;
  int healer_level;
  int extra_level, prestige_level;
  int status_flag;
  
  healer_level=(int)gob->query_healer_level();

  if(!target)
  {
    object *ppl;
    int h,s;
    if(str == "all" || !str) {
    write("NEED ANALYSIS for ALL Players:\n\n");
      ppl = users();
      write(" Name        <guild>  lvl       HP SP  Location      Status\n");
    } else {
      write("NEED ANALYSIS for ALL Players in ROOM:\n\n");
        ppl = all_inventory(ENV(usr));
      if(healer_level > 10) {
        write(" Name        <guild>  lvl       HP SP  T  I  F  S   Status\n");
      } else {
        write(" Name        <guild>  lvl       HP  SP  T   Status\n");      
      }
    }
    s = sizeof(ppl);
    for(h=0; h<s; h++) {
      if(ppl[h]->is_player()) {
        string msg;
        if((int)ppl[h]->query_level() > 19 || (int)ppl[h]->query_invis() > (int)usr->query_level()) continue;
        guild_name = (string)ppl[h]->query_guild_name();
        if(!guild_name || guild_name == "") guild_name = "none";
        write(pad((string)ppl[h]->query_name(),12)); 
        write(" <"); write(pad(guild_name[0..4],5)); write("> ");
        level_info = pad(""+ppl[h]->query_level(),-2);
        extra_level = (int)ppl[h]->query_extra_level();
        prestige_level = (int)ppl[h]->query_prestige_level();
        if(extra_level) { level_info += "+"+pad(""+extra_level,-3); }
        if(prestige_level) { level_info += "{" + pad(""+prestige_level,-2)+"}"; }
        write(pad(level_info,10));
        if(ppl[h]->query_mhp()) 
          hpstat = ""+(((int)ppl[h]->query_hp()) * 10/((int)ppl[h]->query_mhp()));
          else 
            hpstat = "0";
        if((string)environment(ppl[h])->realm() == "NM" || environment(ppl[h])->query_NM()) 
          spstat = " NM ";
        else if(ppl[h]->query_msp()) 
          spstat = ""+(((int)ppl[h]->query_sp()) * 10/((int)ppl[h]->query_msp()));
        else 
          spstat = "0";            
        write(pad(hpstat,-3));
        write(pad(spstat,-3));
        if(str == "all" || !str) {
          write(" ");
          write(ANSIPAD((string)environment(ppl[h])->short(),20));  write(NORM);
        } else {
        infusion_info = ""+(((int)ppl[h]->query_infuse()) * 10/((int)ppl[h]->query_infuse_limit()));
        write(pad(infusion_info,-3));
        
          if(healer_level > 10) {
            intox_info = ""+((int)ppl[h]->query_intoxination())*10/(((int)ppl[h]->query_max_intox()));
            stuffed_info = ""+((int)ppl[h]->query_stuffed())*10/(((int)ppl[h]->query_max_stuff()));
            soaked_info = ""+((int)ppl[h]->query_soaked())*10/(((int)ppl[h]->query_max_soak()));
            write(pad(intox_info,-3));
            write(pad(stuffed_info,-3));
            write(pad(soaked_info,-3));
          }
        }
        write(" ");
        if(!interactive(ppl[h])) write("DISC");
        else {
        if(query_idle(ppl[h]) > 120) write("IDLE ");
          if(ppl[h]->query_attack()) write("COMBAT ");
          if(ppl[h]->query_ghost()) write("GHOST");
        }
        
        
        write("\n");
      }
    }
    return 1;
  }
  
  if(!DAEM->check_living_target(usr, target, TO))
    return 0;
    
  if(target->query_mhp()) 
    hpstat = ""+(((int)target->query_hp()) * 10/((int)target->query_mhp()));
    else 
      hpstat = "0";
  if((string)environment(target)->realm() == "NM" || environment(target)->query_NM()) 
    spstat = " NM ";
  else if(target->query_msp()) 
    spstat = ""+(((int)target->query_sp()) * 10/((int)target->query_msp()));
  else 
    spstat = "0";    
     
  infusion_info = ""+(((int)target->query_infuse()) * 10/((int)target->query_infuse_limit()));
  intox_info = ""+((int)target->query_intoxination())*10/(((int)target->query_max_intox()));
  stuffed_info = ""+((int)target->query_stuffed())*10/(((int)target->query_max_stuff()));
  soaked_info = ""+((int)target->query_soaked())*10/(((int)target->query_max_soak()));
  guild_name = (string)target->query_guild_name();
  if(!guild_name || guild_name == "") guild_name = "none";
   
  extra_level = (int)target->query_extra_level();
  prestige_level = (int)target->query_prestige_level();
  
  write("NEED ANALYSIS for "+target->query_name()+"  <lvl: "+target->query_level() + (extra_level?"+"+extra_level:"") + 
        (prestige_level?"{"+prestige_level+"}":"") +">"+
        "  [ "+guild_name+ " ]"+
        "\n\n");

  write("     HP: "+out_of_10(hpstat)+"     SP: "+out_of_10(spstat)+"     TR: "+out_of_10(infusion_info));
  if(healer_level > 10) 
    write("\n     I:  "+out_of_10(intox_info)+"     F:  "+out_of_10(stuffed_info)+"     S:  "+out_of_10(soaked_info));
  write("\n");
  
  if(environment(target)) {
    write("     Loc: "+environment(target)->short());
    if(((string)environment(target)->realm()) == "NT") write("  [non-teleport]");
    write("\n");
  }

  status_flag = 0;
  write("\n     STATUS:");
  if(!interactive(target)) { write(" DC"); status_flag = 1; }
  else {
    if(query_idle(target) > 120) { write(" IDLE"); status_flag = 1; }
          if(target->query_attack()) { write(" COMBAT   ATT: "+(target->query_attack())->short()); status_flag = 1; }
          if(target->query_ghost()){ write(" GHOST"); status_flag = 1; }
  }
  if(healer_level > 7) {  if(present("disease",target) || present("virus",target) || present("VD",target) ||
                    present("illness",target) || present("cold",target)) { write(" SICK"); status_flag = 1; }
        if(present("poison",target) || present("venom",target)) { write(" POISON"); status_flag = 1; }
        }
  if(!status_flag) write(" NORMAL");
  
  if(healer_level > 8) {
    write("\n     DEFENSE: ");
    write(SCALE->show_scale(target->query_ac(), 25, 10));
  }
  if(healer_level > 15) {
    write("\n     STATS: \n"+
"Charisma:       "+SCALE->show_scale(target->query_attrib("cha"), 30, 10)+
"      Dexterity:      "+SCALE->show_scale(target->query_attrib("dex"), 30, 10)+"\n"+
"Intelligence:   "+SCALE->show_scale(target->query_attrib("int"), 30, 10)+
"      Luck:           "+SCALE->show_scale(target->query_attrib("luc"), 30, 10)+"\n"+
"Magic Aptitude: "+SCALE->show_scale(target->query_attrib("mag"), 30, 10)+
"      Piety:          "+SCALE->show_scale(target->query_attrib("pie"), 30, 10)+"\n"+
"Stamina:        "+SCALE->show_scale(target->query_attrib("sta"), 30, 10)+
"      Stealth:        "+SCALE->show_scale(target->query_attrib("ste"), 30, 10)+"\n"+
"Strength:       "+SCALE->show_scale(target->query_attrib("str"), 30, 10)+
"      Will Power:     "+SCALE->show_scale(target->query_attrib("wil"), 30, 10)+"\n");
    
  }
  
  write("\n");
  
  return 1;
}

string out_of_10(mixed x) {
  return pad(""+x, -2)+"/10";
}

