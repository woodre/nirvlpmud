
string who, me;
int amt;

#define CWHO capitalize(who)
#define CME capitalize(this_player()->query_real_name())
#define GUILD present("guild_license", TARGET)
#define TARGET find_player(who)

id(str) { return str == "stone" || str == "guildstone"; }

short() { return "A guildstone"; }

long() {
   write("This is a guildstone.\n");
   write("Available Commands:\n"+
         "-------------------\n"+
         "cmod <player> <mod> <amt> Sets <players>'s combat mod <mod\n"+
         "                             to <amt>\n"+
         "expell <member>           Expells member from guild\n"+
         "gcheck <member>           List <member>'s weapon pro\n"+
         "quests <member>           List guild quests of <member>\n"+
         "recruit <player>          Recruits player into guild\n"+
         "setquest <member> <quest> Sets <quest> to <member>\n");
   write("wp <player> <pro> <amt>   Sets <player>'s weapon proficiency\n"+
         "                               <pro> to <amt>\n");
}

get() {
   if(this_player()->query_level() < 10)
      return 0;
   return 1;
}

drop() { return 0; }

init() {
   if(this_player()->query_level() < 10)
     return 0;
   add_action("set_cmod","cmod");
   add_action("expell","expell");
   add_action("gcheck","gcheck");
   add_action("recruit","recruit");
   add_action("quests","quests");
   add_action("setquest","setquest");
   add_action("set_weap_pro","wp");
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
  tell_object(TARGET, CME+" set your guild "+pro+" proficiency to "+amt+"\n");
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
  tell_object(TARGET, CME+" set your combat modifier '"+mod+"' to "+amt+"\n");
  return 1;
}

gcheck(str) {
   int sword, axe, mace, hammer, lance, flail;
   int shield_mod, mounted_mod, dual_mod, combat_method;
   string sh_str;
   object second_weapon;

   if(!str || sscanf(str, "%s", who) != 1) {
     write("Useage:  gcheck <member>\n");
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
   sh_str = TARGET->short();
   sword = GUILD->query_weapon_pro("sword");
   axe = GUILD->query_weapon_pro("axe");
   mace = GUILD->query_weapon_pro("mace");
   hammer = GUILD->query_weapon_pro("hammer");
   lance = GUILD->query_weapon_pro("lance");
   flail = GUILD->query_weapon_pro("flail");
   mounted_mod = GUILD->query_combat_mod("mounted");
   shield_mod = GUILD->query_combat_mod("shield");
   dual_mod = GUILD->query_combat_mod("dual");
   combat_method = GUILD->query_combat_method();
   write("\n"+sh_str+"\n");
   write("\n"+CWHO+"'s weapon proficiences:\n");
   write("--------------------------------------------\n");
   write("Sword:\t"+sword+"\tAxe:\t"+axe+"\n");
   write("Mace:\t"+mace+"\tHammer:\t"+hammer+"\n");
   write("Lance:\t"+lance+"\tFlail:\t"+flail+"\n\n");
   write(CWHO+"'s combat modifiers:\n");
   write("--------------------------------------------\n");
   write("Mounted:\t"+mounted_mod+"\tShield & Sword:\t"+shield_mod+
         "\tDual Weapons:\t"+dual_mod+"\n");
   write("Current Combat Method: ");
   if(combat_method == 0) 
     write("Standard\n");
   if(combat_method == 1)
     write("Mounted\n");
   if(combat_method == 2)
     write("Shield & Sword\n");
   if(combat_method == 3)
     write("Dual Weapons\n");
   write("\n");
   write("\n");
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
   if(this_player()->query_guild_exp()) {
     write(CWHO+" is a member of another guild.\n");
     return 1;
   }
   medal = clone_object("players/sandman/paladin/medal");
   transfer(medal, TARGET);
   write("You have recruited "+CWHO+" into the Paladins.\n");
   tell_object(TARGET, CME+" has recruited you into the Paladins Guild.\n");
   return 1;
}

quests(str) {
   string quests;

   if(!str || sscanf(str, "%s", who) != 1) {
     write("Useage:  quests <player>\n");
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
   quests = GUILD->query_guild_quests();
   if(quests == 0) quests = "none";
   write("Guild quests solved by "+CWHO+": "+quests+"\n");
   return 1;
}

setquest(str) {
   string quest;

   if(!str || sscanf(str, "%s %s", who, quest) != 2) {
     write("Useage:  setquest <player> <quest>\n");
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
   if(GUILD->query_guild_quests(quest)) {
     write(CWHO+" has already solved that quest.\n");
     return 1;
   }
   GUILD->set_guild_quest(quest);
   if(quest == "none") {
     write("You have cleared "+CWHO+" of all guild quests.\n");
     return 1;
   }
   write("You gave "+CWHO+" the "+quest+" guild quest.\n");
  write("Guild quests solved by "+CWHO+": "+GUILD->query_guild_quests()+"\n");
   return 1;
}

