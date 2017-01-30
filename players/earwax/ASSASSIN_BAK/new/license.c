
/* Thanks to Molasar for this nice guild object.  I even added some
fine bugs to it.

The idea is to keep all-guild functions in this file, and to put 
guild-unique functions in a file included at the end.  Guild-unique global
variables and defines should go in a defs.h file to be included at beginning.
That's my idea.
Deathmonger
*/


#include "defs.h"

int muffled, battle;
int wimpy_at, wimpystate, wimdir;
string me, guild_quests, wimpydir;
string guildobs, guildnames;


/* finger variables */
string channel_names, gender, cap_name, name, mailaddr, title, pretitle;
string called_from_ip, description, lastime, guild_name;
int level, ghost, age, frog, player_killing;

/* Weapon proficiency variables */
int sword_pro, dagger_pro, bow_pro, thrown_pro, gun_pro;

/* Formats columns nicely */
justify(str, len){ return extract(str+"                           ",0,len-1); }

reset(arg) {
   if(this_player() && this_player()->query_guild_exp() == 0) {
      this_player()->add_guild_exp(1);
	  return 1;
   }
   battle = 0;
   if(arg)
      return;
   guildobs = allocate(20);
   guildnames = allocate(20);
   /* Make sure the numbers of these two arrays line up...ie fangs is the same n
   umber element of
   guildobs as Vampire is in guildnames.
   */
   guildobs = ({ "medal", "mrobe", "fangs", "license", "seal",
                 "shadow-mark","symbol","black robes" });
   guildnames = ({ "Paladin", "Monk", "Vampire", "Assassin", "Mason",
    "Shadow", "Cleric", "Nethermancer" });
   
}

earplugs(){
   if(muffled){
	  muffled = 0;
      write("You are now listening to the assassin channel.\n");
	  return 1;
   }
   else {
	  muffled = 1;
      write("You are now deaf to the assassin channel.\n");
	  return 1;
   }
   write("This should not happen.  Report it to Deathmonger.\n");
}


set_guildhome(str){
    if(str == "church"){
    this_player()->set_home("room/church");
    write("You will now start out in the church.\n");
    return 1;
    }
    this_player()->set_home(APATH+"/cenguild");
    write("You will now start out in the guild hall at logon.\n");
    return 1;
}
query_muffled() { return muffled; }

set_wimdir(wr) { wimdir = wr; }
query_wimdir() { return wimdir; }

set_wimpy_at(wa) { wimpy_at = wa; }
query_wimpy_at() { return wimpy_at; }

set_wimpydir(wp) { wimpydir = wp; }
query_wimpydir() { return wimpydir; }

set_battle(bt) { battle = bt; }
query_battle() { return battle; }

set_wimpystate(wst) { wimpystate = wst; }
query_wimpystate() { return wimpystate; }

set_guild_quest(gq) {
   if(!gq) return;
   if(gq == "none") {
      guild_quests = 0;
      return 1;
   }
   if(query_guild_quests(gq) == 1) return 0;
   if(guild_quests == 0)
      guild_quests = gq;
   else
      guild_quests = guild_quests+"#"+gq;
   return 1;
}

query_guild_quests(str) {
   string tmp, rest, rest_tmp;
   
   if(str == 0)
      return guild_quests;
   rest = guild_quests;
   while(rest) {
      if(str == rest)
         return 1;
      if(sscanf(rest, "%s#%s", tmp, rest_tmp) != 2) return 0;
      if(str == tmp)
         return 1;
      rest = rest_tmp;
   }
   return 0;
}


id(str) { return str == "license" || str == "license to kill" ||
   str == "guild_license" || str == "pro_object"; }

query_auto_load() {
   return "players/deathmonger/ASSASSIN/license:"+muffled+"#"+guild_quests+"#"+
   sword_pro+"#"+dagger_pro+"#"+bow_pro+"#"+thrown_pro+"#"+
   gun_pro;
}

init_arg(arg) {
   sscanf(arg, "%d#%s#%d#%d#%d#%d#%d#%d#%d#%d", muffled,
	  guild_quests, sword_pro, dagger_pro, bow_pro, thrown_pro, gun_pro);
   return;
}

get() { return 1; }

drop() { return 1; }

short(){ return "License to Kill"; }

long() {
   write("The license reads: You can go ahead and kill "+
         "that person if you like.\n");
}

init() {
   me = this_player()->query_real_name();
   this_player()->set_guild_name("assassin");
   add_action("register","adjust_myself");
   add_action("earplugs","earplugs");
   add_action("battlescore","battlescore");
   add_action("battlescore","o");
   add_action("wimpydir","wimpydir");
   add_action("set_guildhome", "guildhome");
   add_action("wimpyhp","wimpyhp");
   add_action("finger","finger");
   add_action("rank","rank");
   add_action("news","news");
   add_action("guild_tell","ac");
   add_action("guild_who","awho");
   add_action("who2","wh");
   add_action("help_license","license");
   add_action("help_license2", "license2");
   add_action("weapon_proficiency","weapon");
   add_action("identify_object","id");
   add_action("reserve_monster", "reserve");
   add_action("unreserve", "unreserve");

   /* assassins guild specific powers */
   add_action("pkers", "pkers");
   add_action("fear", "fear");
   add_action("backstab", "backstab");
   add_action("harm", "harm");
   add_action("cannibalize", "cannibalize");
   add_action("cannibalize", "cann");
   add_action("spy", "spy");
   add_action("bug", "bug");
   add_action("unbug", "unbug");
   add_action("roombug", "roombug");
   add_action("unroombug", "unroombug");
   add_action("code", "code");
   add_action("hitlist", "hitlist");
   add_action("heroes", "heroes");
   add_action("escape", "escape");
   add_action("consider", "consider");
   add_action("contract", "contract");
   add_action("disguise", "disguise");
   add_action("stalk", "stalk");
   add_action("preview", "preview");
   add_action("sneak", "sneak");
   add_action("disguise", "disguise");
   add_action("undisguise", "undisguise");
   add_action("emote"); add_xverb(":");
   add_action("quit", "quit");
   add_action("no_spell", "fi");
   add_action("no_spell", "fireball");
   add_action("no_spell", "sh");
   add_action("no_spell", "shock");
   add_action("no_spell", "mi");
   add_action("no_spell", "missle");
   add_action("no_spell", "so");
   add_action("no_spell", "sonic");
   if(disguised) {
     add_action("communicate");  add_xverb("'");
     add_action("communicate", "say");
    }

}

help_license(str) {
   if(!str) {
      cat(APATH +"HELP1");
      return 1;
   }
}

help_license2(str){
   if(!str){
      cat(APATH + "HELP2");
	  return 1;
   }
}

help_license3(str){
   if(!str){
       cat(APATH + "HELP3");
       return 1;
   }
}

no_spell(){
   notify_fail("You cannot use that spell.");
}

register() {
   object ob, new_license;
   new_license = clone_object(APATH+"license");
   new_license->set_wimdir(wimdir);
   new_license->set_wimpy_at(wimpy_at);
   new_license->set_wimpydir(wimpydir);
   if(muffled) new_license->earplugs();
   new_license->set_wimpystate(wimpystate);
   new_license->set_bug(bug);
   new_license->set_roombug(roombug);
   new_license->set_guild_quests(guild_quests);
   new_license->set_weapon_pro("sword", sword_pro);
   new_license->set_weapon_pro("dagger", dagger_pro);
   new_license->set_weapon_pro("bow", bow_pro);
   new_license->set_weapon_pro("thrown", thrown_pro);
   new_license->set_weapon_pro("gun", gun_pro);
   new_license->set_disguise(shadow);
   new_license->set_disguised(disguised);
   new_license->set_reserved(monshadow);
   new_license->set_stalkee(stalkee, stalkee_name, stalk);
   new_license->set_ok_backstab(ok_backstab);
   transfer(new_license, this_player());
   write("Your medallion brightens for a moment then returns to normal.\n");
   destruct(this_object());
   return 1;
}


nice_time(i) {
   string nicetime;
   nicetime = "";
   if(i/43200) {
      nicetime += i/43200 + " days ";
      i = i - (i/43200)*43200;
   }
   if(i/1800) {
      nicetime += i/1800 + " hours ";
      i = i - (i/1800) * 1800;
   }
   if(i/30) {
      nicetime +=i/30 + " minutes ";
      i = i - (i/30)*30;
   }
   nicetime += i*2 + " seconds.";
   return nicetime;
}

finger(str){
   object who;
   channel_names=0;gender=0;cap_name=0;mailaddr=0;title=0;pretitle=0;
   called_from_ip=0;description=0;lastime=0;guild_name=0;name=0;
   level=0;ghost=0;age=0;frog=0;player_killing=0;
   if(!str){ notify_fail("Usage: finger <who>"); }
   restore_object("players/"+str);
   if(!name){ notify_fail("No one by the name of "+capitalize(str)+
        " has ever visited Nirvana."); }
   who = find_player(str);
   if(pretitle) write(pretitle+" ");
   write(capitalize(name)+" "+title+"\n");
    write("Level: "+level+"  Gender: "+gender+
"\nAge: "+nice_time(age)+"\n");
   if(description) write(capitalize(name)+" "+description+"\n");
   write("Last logged in from: "+called_from_ip+"\n");
/*
   if(ok_email) write("Email: "+mailaddr+"\n");
*/
   if(ghost) write("Is a ghost.\n");
   if(frog) write("Is a frog.\n");
   if(player_killing) write("Can fight other players.\n");
   if(guild_name) write("Member of "+guild_name+" guild.\n");
   if(who && who->query_interactive() && !who->query_invis()){
      write("Logged in!\n");
      write("Location: "+environment(who)->short()+"\n");
   }
   else {
      write("Last login: "+lastime+"\n");
   }
   return 1;
}


guild_tell(str) {
   object list, guild;
   int i, emote;
   string me, junk;
   me = capitalize(this_player()->query_name());
   if(!str) {
      write("Tell assassins what?\n");
      return 1;
   }
   if(sscanf(str, ":%s", junk)) emote = 1;
   list = users();
   for(i=0; i < sizeof(list); i++) {
      guild = present("license to kill", list[i]);
      if(guild && guild->query_muffled() == 0) {
         if(!emote)
            tell_object(list[i], me+" -}===- "+str+"\n");
          else tell_object(list[i], "-}===- "+me+" "+str+"\n");
       }
   }
   return 1;
}

guild_who() {
   object list, guild;
   int i;
   list = users();
   write("\n");
   write("[======================================================]\n");
   write("Level:\tName:\n");
   write("------\t-----\n");
   for(i=0; i< sizeof(list); i++) {
      guild = present("guild_license", list[i]);
      if(guild) {
         string name;
         int lvl;
         name = list[i]->query_name();
         lvl = list[i]->query_level();
         if(lvl > 20) lvl = "WIZ";
         if(guild->query_muffled()) {
            name = "*"+name;
         }
         if(list[i]->query_invis() > 0) { write(""); } else
            write(lvl+"\t"+name+"\n");
       }
   }
   write("[======================================================]\n");
   return 1;
}

check_guild(who){   /* check who for guild obj, return guild name */
   object guild;
   string gname;
   int i;
   gname = 0;
   if(!who){ notify_fail("Error: Non-player passed to check_guild()\n"); }
   for(i=0;i<sizeof(guildobs);i++){
      guild = present(guildobs[i], who);
      if(guild){    /* yes! */
         if(gname && who->query_level() < 20){
            gname = "Cheater";  /* weasel is in another guild already */
            break;
         }
         gname = guildnames[i];          /* vector the guild name */
       }
   }
   if(!gname) gname = "No guild";
   return gname;
}

who2() {
   object list;
   int i, j;
   list = users();
   write("\n");
   write("[==========================================]\n");
   write(justify("Level:",9)+justify("Name:",14)+
         justify("Guild:",12)+"Location:");
   write("\n");
   write("------\t "+"-----"+"         ------"+"      ---------\n");
   for(i=0; i< sizeof(list); i++) {                 /* for each player */
      string name, gname;
      int lvl;
      gname = check_guild(list[i]);
      name = list[i]->query_name();
      lvl = list[i]->query_level();
      if(lvl > 20) lvl = "WIZ";
      if(list[i]->query_invis() > 0) { write(""); } else
         write(justify(lvl,9)+justify(name,14)+justify(gname,12)+
              justify(environment(list[i])->short(),40)+
              "\n");
   }
   write("[==========================================]\n");
   return 1;
}

muffles(str) {
   if(!str) {
      write("Usage: muffles <on/off>\n");
      return 1;
   }
   if(str == "on") {
      if(muffled == 1) {
         write("You already have your muffles on!\n");
         return 1;
      } else
         muffled = 1;
      write("You are now muffled.\n");
      return 1;
   }
   if(str == "off") {
      if(muffled == 0) {
         write("Your muffles are not on!\n");
         return 1;
      } else
         muffled = 0;
      write("Your muffles are now off.\n");
      return 1;
   }
}

news() {
   cat("/players/deathmonger/ASSASSIN/NEWS");
   return 1;
}

reserve_monster(str){
   object what;
   if(!str){ write("Reserve what?\n"); return 1; }
   if(monshadow){
      notify_fail("You can only reserve one monster at a time."); }
   what = present(str, environment(this_player()));
   if(!what){ notify_fail("That is not here."); }
   if(what->query_reserved_monster()){
      notify_fail("That monster has already been reserved. "+
                  "Please choose another."); }
   if(!what->query_npc()){
     notify_fail("You cannot reserve one of those."); }
   monshadow = clone_object(APATH+"/monstop");
   monshadow->block_attacks(what, this_player()->query_real_name());
   write("You stake flags into the ground around "+capitalize(str)+".\n");
   say(this_player()->query_name()+
       " stakes flags into the ground around "+capitalize(str)+".\n");
   return 1;
}

unreserve(){
   if(!monshadow){
     notify_fail("You have no reserved monster."); }
   write("You remove the monster reservation.\n");
   monshadow->remove_blocks();
   monshadow = 0;
   return 1;
}

wimpyhp(str) {
   if(!verify_use())
      return 1;
   if(!str) {
      if(wimpystate == 0) {
         write("Guildwimpy is not on!\n");
         return 1;
      }
      write("Guildwimpy has been turned off.\n");
      wimpystate = 0;
      wimdir = 0;
      wimpydir = 0;
      return 1;
   }
   if(sscanf(str, "%d", wimpy_at) != 1) {
      write("Usage:  wimpyhp <hit points>\n");
      return 1;
   }
   wimpystate = 1;
   write("Guildwimpy has been turned on and set at "+wimpy_at+".\n");
   set_heart_beat(1);
   return 1;
}

wimpydir(str) {
   if(!str || sscanf(str, "%s", wimpydir) != 1) {
      write("Usage:  wimpydir <direction>\n");
      return 1;
   }
   if(!verify_use())
      return 1;
   write("Wimpydir set to:  "+wimpydir+"\n");
   wimdir = 1;
   return 1;
}

battlescore() {
   if(battle == 0) {
      write("Battlescore has been turned on.\n");
      battle = 1;
      set_heart_beat(1);
      return 1;
   } else
      battle = 0;
   write("Battlescore has been turned off.\n");
   return 1;
}

rank() {
   write("\n");
   write(capitalize(this_player()->query_real_name())+" (Level: "+
      this_player()->query_level()+") (Extra Level: "+
      this_player()->query_extra_level()+")\n");
   write("Hit points:\t"+this_player()->query_hp()+"["+
      this_player()->query_mhp()+"]"+"\tSpell points:\t"+
      this_player()->query_sp()+
      "["+this_player()->query_msp()+"]\n");
   write("Experience:\t"+this_player()->query_exp()+"\t\tGold coins:\t"+
      this_player()->query_money()+"\n");
   if(wimpystate == 1) {
      write("Guildwimpy is on. Wimpyhp: "+wimpy_at+"  Wimpydir: "+wimpydir+"\n")
      ;
   } else write("Guildwimpy is off.\n");
   if(muffled == 1) {
      write("Earplugs are in.\n");
   } else write("Earplugs are out.\n");
   write("\n");
   weapon_proficiency();
   write("\n");
   return 1;
}

heart_beat() {
   if(!me) return;
   if(wimpystate == 1 && find_player(me)->query_hp() < wimpy_at) {
      if(find_player(me)->query_attack()) {
         if(wimdir == 1) {
            command(wimpydir, find_player(me));
         } else
            find_player(me)->run_away();
      }
   }
   if(battle == 1) {
      int hp, sp, mhp, msp;
      hp = find_player(me)->query_hp();
      sp = find_player(me)->query_sp();
      mhp = find_player(me)->query_mhp();
      msp = find_player(me)->query_msp();
      tell_object(find_player(me),
         "Hit points: ["+hp+"/"+mhp+"]    Spell points: ["+sp+"/"+msp+"]\n");
   }
   my_heart_beat();
}


/********************************/
/*      WEAPON PROFICIENCY      */
/********************************/

set_weapon_pro(str, arg) {
   if(str == "dagger") dagger_pro = arg;
   if(str == "sword") sword_pro = arg;
   if(str == "bow") bow_pro = arg;
   if(str == "thrown") thrown_pro = arg;
   if(str == "gun") gun_pro = arg;
}

query_weapon_pro(str) {
   if(str == "sword") return sword_pro;
   if(str == "dagger") return dagger_pro;
   if(str == "bow") return bow_pro;
   if(str == "thrown") return thrown_pro;
   if(str == "gun") return gun_pro;
}

weapon_proficiency() {
   write("Weapon Proficiency:\n");
   write("==================================================\n");
   write("Sword:\t"+sword_pro+"\tDagger:\t"+dagger_pro+"\tBow:\t"+
      bow_pro+"\n");
   write("Thrown:\t"+thrown_pro+"\tGun:\t"+gun_pro+"\n");
   write("==================================================\n");
   return 1;
}

identify_object(str) {
   object itemob;
   
   if(!str) {
      write("What would you like to identify?\n");
      return 1;
   }
   itemob = present(str, this_player());
   if(!verify_use())
      return 1;
   if(!itemob) {
      write("You do not have a(n) "+str+".\n");
      return 1;
   }
   if(itemob->query_pro_weapon()) {
      write("You identify the "+str+" as weapon type: ");
      identify_weapon(itemob);
      return 1;
   }
   itemob->set_obj_id(1);
   if(!itemob->query_obj_id()) {
      write(str+" is unidentifiable.\n");
      return 1;
   }
   write("You identify the "+str+" as:\n");
   write(itemob->short()+"\n");
   return 1;
}

identify_weapon(itemob) {
   string wtype;
   wtype = itemob->query_weapon_type();
   write(wtype+"\n");
}

#include "powers.c"

