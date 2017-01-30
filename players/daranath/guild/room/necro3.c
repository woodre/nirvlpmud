#include "/players/daranath/guild/defs.h"
#define TP this_player()

inherit "room/room";

reset(arg) {
if(arg) return;

  set_light(1);
  short_desc= "Necromancer Training Academy";
  long_desc= 
    "The necromancer training school, where necros can advance guild\n"+
    "level and study more about their spells. The only exit is\n"+
    "back to the west.\n"+
    "Commands here are advance, cost and study.\n";

  dest_dir=({
   "/players/daranath/guild/room/necro2.c","west",
  });
}

init() {
  ::init();
  if(present("necro_ob",tp)) {
   add_action("advance","advance");
	add_action("cost","cost");
   add_action("study","study");
   add_action("study_list","study_list");
  }
}

cost() {
int min_xp, c_xp, g_level;
int extra_xp, need_xp;
int c_val, need_val, amount;
  if(tp->query_level() > 20) {
  write("You have no need for this ability.\n");
  return 1; }
  if(tp->query_extra_level()) 
    min_xp = call_other("/room/exlv_guild","get_next_exp",tp->query_extra_level()-1);
  else
    min_xp = call_other("/room/adv_guild","get_next_exp",tp->query_level()-1);
  c_xp = tp->query_exp();
  extra_xp = c_xp - min_xp;
  c_val = present("necro_ob",tp)->query_val();
  g_level = tp->query_guild_rank();
  
  switch(g_level) {
    case 1: need_xp = 20000; need_val = 100; break;
	case 2: need_xp = 25000; need_val = 200; break;
	case 3: need_xp = 25000; need_val = 400; break;
	case 4: need_xp = 50000; need_val = 550; break;
	case 5: need_xp = 75000; need_val = 750; break;
	case 6: need_xp = 100000; need_val = 850;  break;
	case 7: need_xp = 150000; need_val = 1000;  break;
	case 8: need_xp = 150000; need_val = 1250;  break;
    case 9: need_xp = 300000; need_val = 1250;  break;
	case 10: need_xp = 1500000; need_val = 5000; break;
   }
   amount = need_xp - extra_xp;
if(amount > 0) write("<"+HIW+"RoD"+NORM+"> You need "+amount+" more exp to advance.\n");
  else write("<"+HIW+"RoD"+NORM+"> You have enough exp to advance your Necromantic Level.\n");
if(c_val < need_val) write("<"+HIW+"RoD"+NORM+"> The Realm of Death still hungers from you.\n");
  else write("<"+HIW+"RoD"+NORM+"> The Realm of Death is pleased with your actions.\n");
return 1; 
}

advance() {
int min_xp, c_xp, g_level;
int extra_xp, need_xp;
int c_val, need_val;
  if(tp->query_extra_level()) 
    min_xp = call_other("/room/exlv_guild","get_next_exp",tp->query_extra_level()-1);
  else
    min_xp = call_other("/room/adv_guild","get_next_exp",tp->query_level()-1);
  c_xp = tp->query_exp();
  extra_xp = c_xp - min_xp;
  c_val = present("necro_ob",tp)->query_val();
  g_level = tp->query_guild_rank();
  
  switch(g_level) {
    case 1: need_xp = 20000; need_val = 100; break;
	case 2: need_xp = 25000; need_val = 200; break;
	case 3: need_xp = 25000; need_val = 400; break;
	case 4: need_xp = 50000; need_val = 550; break;
	case 5: need_xp = 75000; need_val = 750; break;
	case 6: need_xp = 100000; need_val = 850;  break;
	case 7: need_xp = 150000; need_val = 1000;  break;
	case 8: need_xp = 150000; need_val = 1250;  break;
    case 9: need_xp = 300000; need_val = 1250;  break;
	case 10: need_xp = 1500000; need_val = 5000; break;
   }
   
   if(extra_xp < need_xp) {
write("<"+HIW+"RoD"+NORM+"> You need "+(need_xp - extra_xp)+" to advance your Necromantic Level.\n");
   return 1; }
   if(c_val < need_val) {
      write("The Realm of Death still hungers from you.\n");
   return 1; }
   tp->add_guild_exp(need_xp);
   tp->add_exp(-need_xp);
   present("necro_ob",tp)->set_val(0);
   tp->add_guild_rank(1);
   present("necro_ob",tp)->save_me();
   tp->reset(1);
write("<"+HIW+"RoD"+NORM+"> You have advanced your Necromantic Level.\n");
   write_file("/players/daranath/guild/log/ADVANCE",ctime(time())+" "+tp->query_real_name()+"  level:"+
     (tp->query_level()+tp->query_extra_level())+"  To guildlevel:"+tp->query_guild_rank()+"\n");
   command("save",tp);
return 1; }

study(str) {
  if(!str) {write("What would you like to study?\n"+
     "study_list for a list of items.\n"); return 1; }
if(str == "parts") {cat("/players/daranath/guild/docs/parts_list.txt"); return 1; }
if(str == "level1") {cat("/players/daranath/guild/docs/level1.txt"); return 1; }
if(str == "level2") {cat("/players/daranath/guild/docs/level2.txt"); return 1; }
if(str == "level3") {cat("/players/daranath/guild/docs/level3.txt"); return 1; }
if(str == "level4") {cat("/players/daranath/guild/docs/level4.txt"); return 1; }
if(str == "level5") {cat("/players/daranath/guild/docs/level5.txt"); return 1; }
if(str == "level6") {cat("/players/daranath/guild/docs/level6.txt"); return 1; }
if(str == "level7") {cat("/players/daranath/guild/docs/level7.txt"); return 1; }
if(str == "level8") {cat("/players/daranath/guild/docs/level8.txt"); return 1; }
if(str == "level9") {cat("/players/daranath/guild/docs/level9.txt"); return 1; }
if(str == "level10") {cat("/players/daranath/guild/docs/level10.txt"); return 1; }
if(str == "avatar") {cat("/players/daranath/guild/docs/avatar.txt"); return 1; }
if(str == "gravepact") {cat("/players/daranath/guild/docs/gravepact.txt"); return 1; }
if(str == "chill") {cat("/players/daranath/guild/docs/chill_touch.txt"); return 1; }
if(str == "autopsy") {cat("/players/daranath/guild/docs/autopsy.txt"); return 1; }
if(str == "preserve") {cat("/players/daranath/guild/docs/preserve.txt"); return 1; }
if(str == "wform") {cat("/players/daranath/guild/docs/wraithform.txt"); return 1; }
if(str == "harvest") {cat("/players/daranath/guild/docs/harvest.txt"); return 1; }
if(str == "toolme") {cat("/players/daranath/guild/docs/summon_tool.txt"); return 1; }
if(str == "lifedrain") {cat("/players/daranath/guild/docs/life_drain.txt"); return 1; }
if(str == "ddoor") {cat("/players/daranath/guild/docs/death_door.txt"); return 1; }
if(str == "embrace_death") {cat("/players/daranath/guild/docs/embrace_death.txt"); return 1; }
if(str == "clight") {cat("/players/daranath/guild/docs/corpse_light.txt"); return 1; }
if(str == "consume") {cat("/players/daranath/guild/docs/consume_corpse.txt"); return 1; }
if(str == "backstab") {cat("/players/daranath/guild/docs/backstab.txt"); return 1; }
if(str == "congrave") {cat("/players/daranath/guild/docs/con_grave.txt"); return 1; }
if(str == "disturb") {cat("/players/daranath/guild/docs/disturb.txt"); return 1; }
if(str == "badmoon") {cat("/players/daranath/guild/docs/badmoon.txt"); return 1; }
if(str == "bury_me") {cat("/players/daranath/guild/docs/buried_alive.txt"); return 1; }
if(str == "syphon") {cat("/players/daranath/guild/docs/syphon.txt"); return 1; }
if(str == "abandon") {cat("/players/daranath/guild/docs/abandon.txt"); return 1; }
if(str == "cloak") {cat("/players/daranath/guild/docs/cloak.txt"); return 1; }
if(str == "gstench") {cat("/players/daranath/guild/docs/ghast_stench.txt"); return 1; }
if(str == "graft") {cat("/players/daranath/guild/docs/grafting.txt"); return 1; }
if(str == "raise") {cat("/players/daranath/guild/docs/raise_dead.txt"); return 1; }
if(str == "grasp") {cat("/players/daranath/guild/docs/spect_grasp.txt"); return 1; }
if(str == "sphere") {cat("/players/daranath/guild/docs/sphere.txt"); return 1; }
if(str == "banshee") {cat("/players/daranath/guild/docs/banshee.txt"); return 1; }
if(str == "boneportal") {cat("/players/daranath/guild/docs/raise_portal.txt"); return 1; }
if(str == "hist1") {cat("/players/daranath/guild/docs/hist1.txt"); return 1; }
if(str == "hist2") {cat("/players/daranath/guild/docs/hist2.txt"); return 1; }
if(str == "hist3") {cat("/players/daranath/guild/docs/hist3.txt"); return 1; }
if(str == "hist4") {cat("/players/daranath/guild/docs/hist4.txt"); return 1; }
if(str == "rules") {cat("/players/daranath/guild/docs/rules.txt"); return 1; }
if(str == "leave_guild") {cat("/players/daranath/guild/docs/leave_guild.txt"); return 1; }
if(str == "rod") {cat("/players/daranath/guild/docs/rod.txt"); return 1; }
if(str == "basic") {cat("/players/daranath/guild/docs/basic.txt"); return 1; }
if(str == "shadow") {cat("/players/daranath/guild/docs/shadow.txt"); return 1;}
if(str == "glee") {cat("/players/daranath/guild/docs/sad_glee.txt"); return 1;}
if(str == "agony") {cat("/players/daranath/guild/docs/agony.txt"); return 1;}
if(str == "deathfog") {cat("/players/daranath/guild/docs/deathfog.txt"); return 1;}
if(str == "value") {cat("/players/daranath/guild/docs/value.txt"); return 1; }
else { write("What would you like to study?\n"+
       "study_list for a list of items.\n");
return 1; }
}

study_list() {
write("\nA listing of things you can study:\n\n");
write("The basics of the Guild:\n");
write("basic, level1, level2, level3, level4, level5, level6\n");
write("level7, level8, level9, level10, avatar, parts\n\n");
write("The spells of the guild:\n");
write("autopsy, harvest, preserve, chill, clight, wform, toolme\n");
write("embrace_death, backstab, consume, ddoor, disturb, badmoon\n");
write("grasp, congrave, bury_me, lifedrain, abandon, cloak\n");
write("gstench, sphere, syphon, graft, shadow\n");
write("agony, deathfog, glee, raise, banshee\n");
write("boneportal\n\n");
write("And a few things about the guild:\n");
write("hist1, hist2, hist3, hist4, rules, value, leave_guild, rod\n");
write("\nUsage: study <item>\n");
return 1; 
}

realm() {return "NT";}

