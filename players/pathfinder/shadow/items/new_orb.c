#include "/players/pathfinder/closed/shadow/esc.h"
#define TP this_player()
#define CAP capitalize
#define QRN query_real_name()
#define EXP TP->query_exp()
#define GL TP->query_guild_level()
#define GX TP->query_guild_exp()
#define LOG "/players/pathfinder/closed/shadow/ADVANCE"
#define UNJOIN_LOG "/players/pathfinder/closed/shadow/UNJOIN"
#define BOLD ESC+"[1m"
#define NOSTYLE ESC+"[0m"
 
int xpfor, exp_str;
 
id(str) { return str = "black_orb" || str == "orb" || str == "black orb"; }
 
short() {
  string short;
  short = BOLD+"A Black Orb"+NOSTYLE;
  return short;
}
 
long() {
   write("This is the black orb.  It contains no light.\n"+
         "Type 'info advance' for more help.\n");
   return 1;
}
 
reset(arg) {
 
   if(arg) return;
 
   xpfor = allocate(9);
 
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
  add_action("swap_exp_gxp", "swap");
  add_action("advance_glevel", "advance");
}
 
swap_exp_gxp(str) {
  int amt, level, grank, gxp, xp;
  object mark;
  mark = present("shadow-mark", TP);
  grank = TP->query_guild_rank();
  gxp = TP->query_guild_exp();
  level = TP->query_level();
  xp = TP->query_exp();
  
  if(TP->query_guild_name() != "shadow") {
    write("Cheater!  You cannot use the shadow guild to advance another\n");
    write("Guild!\n");
    say(CAP(TP->QRN)+" is a cheater!!\n");
    move_object(TP,"/room/church");
    return 1;
  }
  
  if(!sscanf(str,"%d",amt) == 1) {
    write("Usage: swap <amt>\n");
    return 1;
  }
 
/* player is dumb enough to try to change too many gxps */
 
  if(grank >= 8 || ((amt + gxp) > xpfor[8])) {
    write("It would be worthless to you to change so much experience to\n");
    write("guild experience\n");
    say(CAP(TP->QRN)+" attempts to place their hands upon the black orb but cannot\n");
    return 1;
  }
    
  if((xp - amt) < exp_str[level]) {
/* they do not have enough xps available */  
    write("You do not have enough experience available to do that!\n");
    write("The maximum experience available for swapping is "+(xp - exp_str[level])+"\n");
    say(CAP(TP->QRN)+" places their hands upon the black orb.\n");
    return 1;
    }
/* else they have enough experience available to change exp to gxp */
  write("You swap "+amt+" experience for guild experience.\n");
  say(CAP(TP->QRN)+" places their hands upon the black orb.\n");
  TP->add_guild_exp(amt); /* add the guild experience */
  TP->add_exp(-amt); /* removes the experience from their player file */
  mark->save_me();
  command("save",TP);
  return 1;
}
 
advance_glevel() {
  int gxp, grank;
  object mark;
  mark = present("shadow-mark",TP);
  
  gxp = TP->query_guild_exp();
  grank = TP->query_guild_rank();
  
  if(TP->query_guild_name() != "shadow") {
    write("Cheater!  You cannot use the shadow guild to advance another\n");
    write("Guild!!\n");
    say(CAP(TP->QRN)+" is a cheater!\n");
    move_object(TP,"/room/church");
    return 1;
  }
 
/* if they are already the highest guild rank */  
 
  if(grank >= 8) {
    write("You already have the highest shadow level!\n");
    return 1;
  }
 
/* if they do not have enough guild experience */  
 
  if(gxp < xpfor[(grank + 1)]) {
    write("You do not have enough experience to attain another shadow level!\n");
    say(CAP(TP->QRN)+" places their hands upon the black orb.\n");
    return 1;
  }
  
  write("You have gained a Shadow Level!\n");
  write("Congratulations!\n");
  say(CAP(TP->QRN)+" just advanced to rank "+(grank + 1)+"\n");
  mark->guild_echo("[-]"+BOLD+CAP(TP->QRN)+NOSTYLE+"[-] has just advanced to rank "+(grank + 1)+"\n");
  TP->add_guild_rank(1);
  mark->save_me();
  command("save",TP);
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
 

