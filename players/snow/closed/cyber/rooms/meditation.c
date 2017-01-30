#include "/players/dune/closed/guild/lib/DEFS.h"

inherit "room/room";

init() {
 add_action("advance_member","advance");
 add_action("exchange_exp","exchange");
 ::init();
}

reset(arg){
 if(!arg){
 set_light(1);
 short_desc="CyberNinja Meditation Room";
 long_desc=
"     You are in a place of silence and solitude.  The lighting\n"+
"is dark here.  Several pillows and soft silk sheets cover the\n"+
"floor.  This is a place for meditation.  A place to improve one's\n"+
"mental and physical being by tapping into the riches of cyberspace.\n"+
"You can either 'advance' or 'exchange <#xp>' here.\n";

items=({
 "pillows", "The pillows are soft and comfortable",
 "sheets","Several sheets lie upon the floor for kneeling on",
 });

  dest_dir=({
 "/players/snow/closed/cyber/rooms/hallway1.c","west",
      });
  }   }

object IP(object ob) {
/* This function is similar to a #define, it just
 * returns the guild object on the player specified.
 */
   object guild_object;
   guild_object = present("implants", ob);
   return guild_object;
}

advance_member() {
/* So guild members can advance level in the guild */
  int current_xp, current_lev, new_lev, new_lev_xp, temp, cost, credits;
  int next_lev, honor;
  if(!IP(TP)) {
    TE(TP,"You are not a CyberNinja.\n");
    return 1;}
  credits = IP(TP)->balance();
  current_lev = IP(TP)->guild_lev();
  current_xp = IP(TP)->guild_exp();
  honor = IP(TP)->query_honor();
  new_lev = call_other("/players/snow/closed/cyber/newdaem.c",
                       "xp_list", current_xp);
  if (new_lev > current_lev) { /* possible to advance */
    next_lev = current_lev + 1;
    if(next_lev == 11) {
      TE(TP,"You cannot enhance your quality any further.\n");
      TE(TP,"You have reached your maximum level.\n");
      return 1;}

    if((next_lev == 6) && (honor < MODERATE)) { 
      /* cannot be qlv 6 with newbie honor */
      write("You are not honorable enough to be enhanced further.\n");
      return 1; }

    if((next_lev == 10) && (honor < HIGH)) { 
      /* cannot be qlv 10 with moderate honor */
      write("You are not honorable enough to be enhanced further.\n");
      return 1; }

    cost = cost_to_advance(next_lev);
    if(credits < cost) {
      temp = cost - credits;
      TE(TP, "You do not have enough credits to advance.\n");
      TE(TP, "You are short "+temp+" @'s\n");
      return 1; }
    IP(TP)->set_rank(next_lev);
    TP->add_guild_rank(1);
    IP(TP)->addToBalance(-cost);
    TE(TP,"You enhance your implants to quality "
      +next_lev+".\n");
    write_file(slog+"ADVANCE", RN+" advanced to level "+
               next_lev+" ("+ctime()+")\n");
    command("set_title", TP);
    IP(TP)->save_me();
    TP->save_me();
    IP(TP)->update_implants();
    IP(TP)->overchannel(TP->query_real_name()+
      " has enhanced to quality level "+next_lev+"!\n");
    return 1;}
  if (new_lev == current_lev) { /* not enough xp yet */
    next_lev = current_lev + 1;
    if(current_lev == 10) {
      TE(TP,"You cannot enhance your quality any further.\n");
      TE(TP,"You have reached your maximum level.\n");
      return 1;}
    new_lev_xp = call_other("/players/snow/closed/cyber/newdaem.c",
                            "low_exp", next_lev);
    temp = new_lev_xp - current_xp;
    TE(TP,"You need "+temp+
      " more experience points to advance to quality level "+
      next_lev+".\n");
    return 1;}
  if (new_lev < current_lev) {
    TE(TP, "You are low on guild experience.\n");
    TE(TP, "With the amount of guild xp you have, you should\n"+
           "not be as high of quality as you are.\n");
    return 1; }
}

int cost_to_advance(int level) {
  switch(level) {
    case 1:        return 1000;
    case 2:        return 5000;
    case 3:        return 10000;
    case 4:        return 20000;
    case 5:        return 30000;
    case 6:        return 40000;
    case 7:        return 50000;
    case 8:        return 60000;
    case 9:        return 70000;
    case 10:       return 100000;
    }
  return 0;
}

exchange_exp(string str) {
/* Way to exhchange normal xp to guild xp */
  int amount, current_real_xp, new_guild_xp, min_xp, extra_xp;
  if(!str) {
    TE(TP,"How much experience do you want to exchange?\n");
    return 1;}
  if(!sscanf(str, "%d", amount)) {
    TE(TP,"Usage: exchange <amount>.\n");
    return 1;}
  if(amount == 0) {
    TE(TP,"Why waste your time exchanging zero experience.");
    return 1;}
  if(amount < 0) {
    TE(TP,"Nice Try   >:)   \n");
    return 1;}
  current_real_xp = ((int)TP->query_exp());
  if(TP->query_level() > 19)
     min_xp = call_other("/room/adv_guild.c",
                         "get_next_exp", 0);
  else
     min_xp = call_other("/room/adv_guild.c",
                         "get_next_exp",TP->query_level() - 1);
  if(amount > current_real_xp) {
    TE(TP,"You do not have that much experience to exchange.\n");
    return 1;}
  extra_xp = current_real_xp - min_xp;
  if(extra_xp <= 0) {
    TE(TP,"You do not have extra experience to exchange experience.\n");
    return 1;}
  else {
    if(amount > extra_xp) {
      TE(TP, "Exchanging "+extra_xp+" experience.\n");
      IP(TP)->add_xp(extra_xp);
      amount = extra_xp;
      }
    else {
      TE(TP,"Exchanging "+amount+" experience into guild experience.\n");
      IP(TP)->add_xp(amount);
     write_file(slog+"XPCHANGE",
      "("+ctime()+") "+RN+" exchanged "+amount+" exps.\n");
      }
    call_other(TP, "add_exp", -amount);
    IP(TP)->save_me();
    TP->save_me();
    return 1;}
}

feel() { return "no"; }