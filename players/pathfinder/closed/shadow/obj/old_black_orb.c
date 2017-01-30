#include "/players/pathfinder/closed/shadow/esc.h"
#include "/players/pathfinder/closed/shadow/color.h"
#define TP this_player()
#define CN capitalize(TP->query_real_name())
#define PSHAD present("shadow-mark",TP)
#define LEVEL TP->query_level()
#define SHLEVEL PSHAD->query_shlev()
#define EXP TP->query_exp()
#define GL TP->query_guild_level()
#define GX TP->query_guild_exp()
#define SHXP PSHAD->query_shxp()
#define LOG "players/pathfinder/closed/shadow/ADVANCE"
#define UNJOIN_LOG "players/pathfinder/closed/shadow/UNJOIN"
 
int xpfor, exp_str;
id(str) { return str == "orb"||str =="black_orb"; }
 short() {
    string short;
    short = BOLD + "A Black Orb"+NOSTYLE;
    return short;
 }
long() {
   write("This is the black orb.  It contains no light.\n"+
         "Type 'info advance' for more help.\n");
   return 1;
}
 get() { return 0; }
 drop() { return 0; }
 query_value() { return 0; }
 
reset(arg) {
 
   if(arg) return;
 
   xpfor = allocate(13);
 
   xpfor[0] = 0;
   xpfor[1] = 0;
   xpfor[2] = 20000;
   xpfor[3] = 40000;
   xpfor[4] = 100000;
   xpfor[5] = 250000;
   xpfor[6] = 500000;
   xpfor[7] = 1200000;
   xpfor[8] = 1900000;
 
   exp_str = allocate(21);
 
   exp_str[20]     =  2500000;
   exp_str[19]     =  2000000;
   exp_str[18]     =  1367106;
   exp_str[17]     =  1040028;
   exp_str[16]     =   820028;
   exp_str[15]     =   620026;
   exp_str[14]     =   492294;
   exp_str[13]     =   295592;
   exp_str[12]     =   195591;
   exp_str[11]     =   134998;
   exp_str[10]     =    90000;
   exp_str[9]      =    59995;
   exp_str[8]      =    39993;
   exp_str[7]      =    26662;
   exp_str[6]      =    12812;
   exp_str[5]      =     5885;
   exp_str[4]      =     2332;
   exp_str[3]      =     1771;
   exp_str[2]      =     1014;
   exp_str[1]      =        0;
   exp_str[0]      =        0;
}
 
init() {
 
   add_action("advance_shadow", "advance");
   add_action("show_table","table");
   add_action("unjoin_start","unjoin");
}
 
 
advance_shadow() {
   int old_xp, old_shxp, free, guild_rank, shlevel, guild_exp, cost;
   object mark;
   mark = PSHAD;
   old_xp = EXP;
  shlevel = mark->query_shlev();
  old_shxp = mark->query_sh_xp();
   free = get_free();
   guild_rank = GL;
   guild_exp = GX;
   if(guild_exp != old_shxp)
      TP->add_guild_exp(old_shxp - GX);
   if(guild_rank != shlevel)
      TP->add_guild_rank(shlevel - guild_rank);
   write("You place your hands on the orb.\n");
   say(CN+" places "+mark->query_possesive()+" hands on the orb.\n");
   if(shlevel > 7) {
      write("You cannot advance past 8th level.\n");
      say(CN +" is denied.\n");
      return 1;
   }
   free = get_free();
   cost = cost_for_level(shlevel + 1);
   if((free - cost) < 0 ) {
      write("You do not have enough free experience points.\n");
      say(CN +" is denied.\n");
      return 1;
   }
   TP->add_exp(-cost);
   write_file(LOG, CN+" advanced from "+SHLEVEL);
  mark->set_shlevel(shlevel + 1);
    write_file(LOG," to "+SHLEVEL+" on "+ctime(time())+".\n");
   mark->guild_echo("<<-->>"+BOLD+CN+NOSTYLE+" is now level "+
        SHLEVEL+"!\n");
   return 1;
}
 
get_free() {
   int free;
   if(LEVEL > 19) {
      write("As a wiz, you must mail/ask quicksilver to set your level.\n");
      return 1;
   }
   free = EXP - exp_str[LEVEL];
   return free;
}
 
cost_for_level(level) {
    return xpfor[level] - SHXP;
}
 
show_table() {
   int n;
    n = 2;
   write("--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--\n");
    write("\n   Level\tMinimum experience needed\n");
    write("     1\t\t\tFree\n");
  while(n < 9) {
      write("    "+n+"\t\t\t"+xpfor[n]+"\n");
      n+=1;
   }
   write("\n");
   write("--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--\n");
   return 1;
}
 
unjoin_start() {
   write("If you leave the guild, you will loose 1/6 your experience, and "+
    "loose all\nguild xps.  Is this ok?(y/n)");
   input_to("unjoin");
   return 1;
}
 
unjoin(str) {
   int exp;
   string yes_er_no;
   yes_er_no = explode(str, "");
   write("String is "+yes_er_no[0]+".\n");
   if(yes_er_no[0] == "y" || yes_er_no[0] == "Y") {
      exp = TP->query_exp();
      exp = exp/6;
      TP->add_exp(-exp);
      destruct(present("shadow-mark", TP));
      TP->set_al(0);
      TP->add_guild_rank(-GL);
      TP->add_guild_exp(-GX);
      TP->set_guild_name("0");
   write_file(UNJOIN_LOG, CN+" left the guild on "+ctime(time())+".\n");
      write("Guild information stripped.\nLoosing 1/6 experience.\n");
      TP->move_player("in disgrace#room/church");
      return 1;
   }
   write("Very well then.\n");
   return 1;
}
 
cost_at_level(level) {
  if(level > 8) return 6900000;
  else if(level == 8) return 1900000;
  else if(level == 7) return 1200000;
  else if(level == 6) return 500000;
  else if(level == 5) return 250000;
  else if(level == 4) return 100000;
  else if(level == 3) return 40000;
  else if(level == 2) return 20000;
  else if(level == 1) return 0;
}
 


