#include "/players/fred/mages/defs.h"

inherit "obj/monster";
#include "tune.h"


reset(arg){
 ::reset();
    if(arg) return;
    set_name("shade");
    set_short(BOLD+BLK+"Shade of Darkness, the Grand Adept ("+RED+"lord of evil"+BLK+")"+NORM);
    set_level(40);
    set_wc(150);
    set_ac(50);
    set_hp(1000000);
    set_al(-1000);
    set_chat_chance(1);
    load_chat(BOLD+BLK+"Shade says:  Learn the way of the Black Circle Mage.\n"+NORM);
    load_chat(BOLD+BLK+"Shade says:  You must be intelligent to use magic.\n"+NORM);
    load_chat(BOLD+BLK+"Shade says:  Don't be afraid to call on my power.\n"+NORM);
}

long() {
   write("  The Shade teaches the Spells most Black Circle Mages wish to learn.\n\n");
   write("  You can:  learn auramancery      Level 1 Adept Spells\n");
   write("            learn shadowmancery    Level 2 Adept Spells\n");
   write("            learn necromancery     Level 3 Adept Spells\n");
   write("            learn geomancery       Level 4 Adept Spells\n");
   write("            learn chronomancery    Level 5 Adept Spells\n");
   write("            cost                   Level costs\n");
   write("            raise magic            Raise extended magic\n");
   write("            leavecircle            Leave the guild.\n");
}

init(){
 ::init();
  add_action("cost","cost");
  add_action("learn","learn");
  add_action("raise", "raise");
  add_action("leave_guild","leavecircle");
  add_action("leave_guild","Leavecircle");
}

raise(str) {
 object ob;
 int mag, max, enough, xlvl, lvl;
 mag = TP->query_attrib("mag");
 lvl = TP->query_level();
 xlvl = TP->query_extra_level();
 ob = present("dark_circle", TP);
 if(!ob) return;
  if(str == "mag" || str == "magic"){
     if(mag < 30){
       write("You can't raise your extra magic yet.\n"); return 1; }
     if(mag == 40){
       write("You can't raise your magic any higher.\n"); return 1; }
     if(xlvl < 1)  
       enough = TP->query_exp() - call_other("room/adv_guild","get_next_exp",lvl-1);
     if(xlvl > 0)
       enough = TP->query_exp() - call_other("room/exlv_guild","get_next_exp",xlvl-1);
     if(enough < 50000){
       write("You don't have enough exp to raise your magic.\n"); return 1;}   
     max = mag + 1;
     TP->set_attrib("mag", max);
     TP->add_exp(-50000);
     write("You raise your magic to "+max+".\n");
     command("register", TP);
     write_file("/players/fred/mages/log/magic",
     capitalize(TPRN)+" raised their magic to "+max+" on "+ctime()[4..15] + "\n");
     TP->save();
     return 1; }
}

learn(str){
 object ob;
 int lvl, xlvl, cando, exp, rank;
 rank = this_player()->query_guild_rank();
 lvl = this_player()->query_level();
 xlvl = this_player()->query_extra_level();
 exp = this_player()->query_exp();
 ob = present("dark_circle", TP);
 if(!ob) return;
 if(!str){ write("What would you like to learn?\n"); return 1; }
 if(str == "auramancery"){
    if(rank > 0){
      write("Shade tells you: You already know Auramancery.\n"); return 1; }
     if(xlvl < 1)  
       cando = exp - call_other("room/adv_guild","get_next_exp",lvl-1);
     if(xlvl > 0)
       cando = exp - call_other("room/exlv_guild","get_next_exp",xlvl-1);
     if(cando < 50000){
      write("Shade tells you: It costs more experience than you have to learn this.\n"); return 1; }
     write("Shade teaches you the spells of Auramancery.\n");
     TP->add_exp(-50000);
     TP->add_guild_rank(1);
     ob->set_glevel(1);
     ob->add_guild_xp(50000);
     TP->add_guild_exp(50000);
     write_file("/players/fred/mages/log/Aura",
     capitalize(TPRN)+" learned Auramancery on "+ctime()[4..15] + "\n");
     ob->msave();
     command("save", TP);
     return 1;
    }
  if(str == "shadowmancery"){
    if(rank > 1){
      write("Shade tells you: You already know Shadowmancery.\n");
      return 1;}
    if(rank < 1){
      write("Shade tells you: You need to learn Auramancery first.\n");
      return 1;}
    if(xlvl < 1)  
       cando = exp - call_other("room/adv_guild","get_next_exp",lvl-1);
    if(xlvl > 0)
       cando = exp - call_other("room/exlv_guild","get_next_exp",xlvl-1);
    if(cando < 150000){
       write("Shade tells you: It costs more experience than you have to learn this.\n");
       return 1;}
     write("Shade teaches you the spells of Shadowmancery.\n");
     TP->add_exp(-150000);
     TP->add_guild_rank(1);
     TP->add_guild_exp(150000);
     ob->set_glevel(2);
     ob->add_guild_xp(150000);    
     write_file("/players/fred/mages/log/Shadow",
     capitalize(TPRN)+" learned Shadowmancery on "+ctime()[4..15] + "\n");
     ob->msave();
     command("save", TP);
     return 1;
    }
  if(str == "necromancery"){
    if(rank > 2){
      write("Shade tells you: You already know Necromancery.\n");
      return 1; }
    if(rank < 2){
      write("Shade tells you: You need to learn Shadowmancery first.\n");
      return 1;}
    if(xlvl < 1)  
       cando = exp - call_other("room/adv_guild","get_next_exp",lvl-1);
    if(xlvl > 0)
       cando = exp - call_other("room/exlv_guild","get_next_exp",xlvl-1);
    if(cando < 750000){
      write("Shade tells you: It costs more experience than you have to learn this.\n");
      return 1;}
    write("Shade teaches you the spells of Necromancery.\n");
    TP->add_exp(-750000);
    TP->add_guild_rank(1);
    TP->add_guild_exp(750000);
    ob->set_glevel(3);
    ob->add_guild_xp(750000);
    write_file("/players/fred/mages/log/Necro",
    capitalize(TPRN)+" learned Necromancery on "+ctime()[4..15] + "\n");
    ob->msave();
    command("save", TP);
    return 1;
   }
  if(str == "geomancery"){
    if(rank > 3){
      write("Shade tells you: You already know Geomancery.\n");
      return 1; }
    if(rank < 3){
      write("Shade tells you: You need to learn Necromancery first.\n");
      return 1; }  
    if(xlvl < 1)  
       cando = exp - call_other("room/adv_guild","get_next_exp",lvl-1);
    if(xlvl > 0)
       cando = exp - call_other("room/exlv_guild","get_next_exp",xlvl-1);
    if(cando < 1500000){
      write("Shade tells you: It costs more experience than you have to learn this.\n");
      return 1; }
    write("Shade teaches you the spells of Geomancery.\n");
    TP->add_exp(-1500000);
    TP->add_guild_rank(1);
    TP->add_guild_exp(1500000);
    ob->set_glevel(4);
    ob->add_guild_xp(1500000);
    write_file("/players/fred/mages/log/Geo",
    capitalize(TPRN)+" learned Geomancery on "+ctime()[4..15] + "\n");
    ob->msave();
    command("save", TP);
    return 1;
    } 
  if(str == "chronomancery"){
    if(rank > 4){
      write("Shade tells you: You already know Chronomancery.\n");
      return 1; }
    if(rank < 4){
      write("Shade tells you: You need to learn Geomancery first.\n");
      return 1; }
    if(xlvl < 1)  
       cando = exp - call_other("room/adv_guild","get_next_exp",lvl-1);
    if(xlvl > 0)
       cando = exp - call_other("room/exlv_guild","get_next_exp",xlvl-1);
    if(cando < 2500000) {
      write("Shade tells you: It costs more experience than you have to learn this.\n");
      return 1; }
    write("Shade teaches you the spells of Chronomancery.\n");
    TP->add_exp(-2500000);
    TP->add_guild_rank(1);
    TP->add_guild_exp(2500000);
    ob->set_glevel(5);
    ob->add_guild_xp(2500000);
    write_file("/players/fred/mages/log/Chrono",
    capitalize(TPRN)+" learned Chronomancery on "+ctime()[4..15] + "\n");
    ob->msave();
    command("save", TP);
    return 1;
    }
 write("Shade tells you: I don't know how to teach you "+str+".\n");
 return 1;
}

cost(){
  write("The Shade says it costs this much to learn the following:\n\n");
  write("Auramancery       - 50,000 exp\n");
  write("Shadowmancery     - 150,000 exp\n");
  write("Necromancery      - 750,000 exp\n");
  write("Geomancery        - 1,500,000 exp\n");
  write("Chronomancery     - 2,500,000 exp\n");
  return 1;
}

leave_guild(){
  object ob;
  ob = present("dark_circle", TP);
  if(!ob){ write("You are not a member of this guild!\n"); 
  return 1; }
  write_file("/players/fred/mages/log/Left",
      capitalize(TPRN)+" left the Dark Circle guild on " + ctime()[4..15] + "\n");
   TP->set_guild_file(0);
   TP->set_home(0);
   TP->set_guild_rank(0);
   TP->set_guild_name(0);
   TP->add_guild_exp(-TP->query_guild_exp());
   TP->add_guild_rank(-TP->query_guild_rank());
   if(TP->query_attrib("mag") > 30) TP->set_attrib("mag", 30); command("register", TP);
   write(BOLD+BLK+"Shade's eyes burn a deep crimson "+RED+"red"+NORM+BOLD+BLK+"...\n"+
        ""+TPN+" is disintegrated by Shade for leaving the guild."+NORM+"\n");
   TP->death("Shade");
   rm("/players/fred/mages/member/"+TPRN+".o");
   destruct(ob);
   return 1;
}
