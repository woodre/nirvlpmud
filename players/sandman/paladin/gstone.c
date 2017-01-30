
/*
 * GUILD STONE (3/5/94)
 * For changing guildmembers stats
 */

string who, me;
int amt;

#define CWHO capitalize(who)
#define CME capitalize(this_player()->query_real_name())
#define GUILD present("guild_medal", TARGET)
#define TARGET find_player(who)

justify(str,len) { return extract(str+"                    ",0,len-1); }
id(str) { return str == "stone" || str == "guildstone"; }

short() { return "A guildstone"; }

long() {
   write("This is a guildstone.\n");
   write("Available Commands:\n"+
         "-------------------\n"+
         "cmod <player> <mod> <amt> Sets <players>'s combat mod <mod>\n"+
         "                             to <amt>\n"+
         "      <mod> = shield   dual   mounted\n"+
         "expell <member>           Expells member from guild\n"+
         "gstats                    List member's guild info\n"+
         "gstats <member>           Individual statistics\n"+
         "powerup <member> <amt>    Sets guild stats to <amt>\n"+
         "recruit <player>          Recruits player into guild\n");
   write("wp <player> <pro> <amt>   Sets <player>'s weapon proficiency\n"+
         "                               <pro> to <amt>\n"+
         "      <pro> = sword  axe  mace  flail  lance\n");
}

get() {
   if(this_player()->query_level() < 21) {
      destruct(this_object());
      return 0;
   }
   return 1;
}

drop() { 
  destruct(this_object());
  return 1; 
}

init() {
   add_action("set_cmod","cmod");
   add_action("expell","expell");
   add_action("gstats","gstats");
   add_action("recruit","recruit");
   add_action("set_weap_pro","wp");
   add_action("powerup","powerup");
}

expell(str) {
   int gexp;

   if(!str || sscanf(str, "%s", who) != 1) {
     write("Useage:  expell <player>\n");
     return 1;
   }
   if(!TARGET) {
     write("Could not find "+CWHO+".\n");
     return 1;
   }
   if(!GUILD) {
     write(CWHO+" is not a member of the guild.\n");
     return 1;
   }
   destruct(GUILD);
   write(CWHO+" has been expelled from the guild.\n");
   tell_object(TARGET, "You have been expelled from the guild by "+CME+".\n");
   gexp = TARGET->query_guild_exp();
   TARGET->add_guild_exp(-gexp);
   TARGET->set_guild_name(0);
   return 1;
}

set_weap_pro(str) {
   string who, pro;
   int amt;

   sscanf(str, "%s %s %d", who, pro, amt);
   if(!TARGET) {
     write(CWHO+" is not on.\n");
     return 1;
   }
   if(!GUILD) {
     write(CWHO+" is not a guild member.\n");
     return 1;
   }
   GUILD->set_weapon_pro(pro, amt);
   write(CWHO+"'s guild "+pro+" profiency is set to "+amt+"\n");
   tell_object(TARGET, CME+" set your "+pro+" proficiency to "+amt+"\n");
   return 1;
}

set_cmod(str) {
  string who, mod;
  int amt;

  sscanf(str, "%s %s %d", who, mod, amt);
  if(!TARGET) {
    write(CWHO+" is not on.\n");
    return 1;
  }
  if(!GUILD) {
    write(CWHO+" is not a guild member.\n");
    return 1;
  }
  GUILD->set_combat_mod(mod, amt);
  write(CWHO+"'s combat modifier '"+mod+"'is now set to "+amt+"\n");
  tell_object(TARGET, CME+" set your "+mod+" combat modifier to "+amt+"\n");
  return 1;
}

gstats(who) {
   int i, sword, mace, axe, lance, flail, shield, dual, mount;
   string name;
   object list, guild;
   
   if(who) {

     if(!TARGET) {
       write("Could not find "+CWHO+".\n");
       return 1;
     }
     if(!GUILD) {
       write(CWHO+" is not a Paladin.\n");
       return 1;
     }
     write(CWHO+":\n");
     GUILD->abilities();
     return 1;
   }
   write("Paladin Stats:\n");
write("(=============================================================="+
      "============)\n");
   write(justify("Name:",14)+justify("Sword:",8)+justify("Mace:",8)+
         justify("Axe:",8)+justify("Lance:",8)+justify("Flail:",8)+
         justify("S&S:",8)+justify("Dual:",8)+justify("Mount:",8)+"\n");
   write(justify("-----",14)+justify("------",8)+justify("-----",8)+
         justify("----",8)+justify("------",8)+justify("------",8)+
         justify("----",8)+justify("-----",8)+justify("------",8)+"\n");
   list = users();
   for(i=0; i < sizeof(list); i++) {
      guild = present("guild_medal", list[i]);
      if(guild) {
        name = list[i]->query_real_name();
        name = capitalize(name);
        sword = guild->query_weapon_pro("sword");
        mace = guild->query_weapon_pro("mace");
        axe = guild->query_weapon_pro("axe");
        lance = guild->query_weapon_pro("lance");
        flail = guild->query_weapon_pro("flail");
        shield = guild->query_combat_mod("shield");
        dual = guild->query_combat_mod("dual");
        mount = guild->query_combat_mod("mounted");
        write(justify(name,14)+justify(sword,8)+justify(mace,8)+
              justify(axe,8)+justify(lance,8)+justify(flail,8)+
              justify(shield,8)+justify(dual,8)+justify(mount,8)+"\n");
      }
   }
write("(=============================================================="+
      "============)\n");
   return 1;
}

recruit(str) {
   object medal;

   if(!str || sscanf(str, "%s", who) != 1) {
     write("Useage:  recruit <player>\n");
     return 1;
   }
   if(!TARGET) {
     write("Could not find "+CWHO+".\n");
     return 1;
   }
   if(GUILD) {
     write(CWHO+" is already a member of the guild.\n");
     return 1;
   }
   if(this_player()->query_guild_exp() &&
           this_player()->query_level() < 21) {
     write(CWHO+" is a member of another guild.\n");
     return 1;
   }
   medal = clone_object("players/sandman/paladin/medal");
   move_object(medal, TARGET);
   TARGET->set_guild_name("Paladins");
   TARGET->add_guild_exp(1);
   write("You have recruited "+CWHO+" into the Paladins.\n");
   tell_object(TARGET, CME+" has recruited you into the Paladins Guild.\n");
   tell_object(TARGET, "Type 'medal' for information on your abiltities.\n");
   return 1;
}

powerup(str) {
   
   if(!str || sscanf(str, "%s %d", who, amt) != 2) {
     write("Usage:  powerup <member> <amt>\n");
     return 1;
   }
   if(!TARGET) {
     write("Could not find "+CWHO+".\n");
     return 1;
   }
   if(!GUILD) {
     write(CWHO+" is not a member of the paladin guild.\n");
     return 1;
   }
   GUILD->set_weapon_pro("sword", amt);
   GUILD->set_weapon_pro("axe", amt);
   GUILD->set_weapon_pro("flail", amt);
   GUILD->set_weapon_pro("mace", amt);
   GUILD->set_weapon_pro("lance", amt);
   GUILD->set_combat_mod("mounted", amt);
   GUILD->set_combat_mod("shield", amt);
   GUILD->set_combat_mod("dual", amt);
   tell_object(TARGET, "Guild stats have been set to "+amt+" by "+CME+".\n");
   write("You have set "+CWHO+"'s guild stats to "+amt+".\n");
   return 1;
}


