#include "/players/dune/closed/guild/guild_docs.c"

#define TP this_player()
#define FP find_player
#define TE tell_object

id(str) { return str == "daemon"; }
short () {return "CyberNinja daemon";}
long() {write("This is the CyberNinja guild daemon.\n");}

object IP(object ob) {
   object guild_object;
   guild_object = present("implants", ob);
   return guild_object;
}

update_implants() {
   object implants, this_ob;
   implants=clone_object("/players/dune/closed/guild/implants.c");
   move_object(implants, this_player());
   tell_object(this_player(), 
     "Rewiring Cyberlink...\n");
   this_ob = present("implants", this_player());
   destruct(this_ob);
   return 1;
}

enhance(string str) {
  int new_lev, current_lev, low_new_xp;
  string who;
  object targ;
  if(!str) { 
    write("Usage: enhance <member> <newlevel>.\n");
    return;}
  if(!sscanf(str, "%s %d", who, new_lev)) {
    write("Usage: enhance <member> <newlevel>.\n");
    return;}
  if(!find_player(who)) {
    write("User "+capitalize(who)+" not found.\n");
    return;}
  targ = find_player(who);
  current_lev = IP(targ)->guild_lev();
  if (new_lev == current_lev) {
    write(capitalize(who)+" is already of quality "
       +new_lev+"\n");
    return;}
  if ((new_lev > 10) && (new_lev < current_lev)) {
    write("You have been demoted to a quality of "+
      new_lev+"\n");
    write("However, you are still guildmaster.\n");
    IP(targ)->set_rank(new_lev);
    IP(targ)->save_me();
    return;}
   if ((new_lev > 10) && (new_lev > current_lev) &&
     (current_lev <=10)) {
    write("You have been promoted to guildmaster!\n");
    write("Be sure to read the help file on guildmasters.\n");
    IP(targ)->set_rank(new_lev);
    IP(targ)->save_me();
    return;}
  if ((new_lev > 10) && (new_lev > current_lev) &&
     (current_lev > 10)) {
    write("You are promoted to quality "+new_lev+".\n");
    IP(targ)->set_rank(new_lev);
    IP(targ)->save_me();
    return;}
  if (new_lev > current_lev) {
    write("You have been enhanced to quality "+new_lev+".\n");
    IP(targ)->set_rank(new_lev);
    low_new_xp = low_exp(new_lev);
    IP(targ)->set_xp(low_new_xp);
    IP(targ)->save_me();
    return;}
  if(new_lev < current_lev) {
    write("You have been demoted to a quality of "+new_lev+"\n");
    IP(targ)->set_rank(new_lev);
    low_new_xp = low_exp(new_lev);
    IP(targ)->set_xp(low_new_xp);
    IP(targ)->save_me();
    return;}
}

addxp(string str) {
  int amount;
  string who;
  object whoob;
  if(!str) {
    write("Usage: addxp <member> <amount>.\n");
    return;}
  if(!sscanf(str, "%s %d", who, amount)) {
    write("Usage: addxp <member> <amount>.\n");
    return;}
  if(!find_player(who)) {
    write("User "+capitalize(who)+" not found.\n");
    return;}
  whoob = find_player(who);
  IP(whoob)->add_xp(amount);
  IP(whoob)->save_me();
  if(amount >= 0) 
    write("You alter "+capitalize(who)+"'s guild xp by +"
      +amount+".\n");
  else write("You alter "+capitalize(who)+"'s guild xp by "
      +amount+".\n");

}

advance_member() {
  int current_xp, current_lev, new_lev, new_lev_xp, temp;
  object targob;
  if(!IP(TP)) {
    TE(TP,"You are not a CyberNinja.\n");
    return;}
  targob = this_player();
  current_lev = IP(targob)->guild_lev();
  current_xp = IP(targob)->guild_exp();
  new_lev = xp_list(current_xp);
  if (new_lev > current_lev) {
    if(current_lev == 10) {
      TE(TP,"You cannot enhance your quality any further.\n");
      TE(TP,"You have reached your maximum level.\n");
      return;}
    current_lev++;
    IP(targob)->set_rank(current_lev);
    TE(TP,"You enhance your implants to quality "
      +current_lev+".\n");
    IP(targob)->save_me();
    net_channel(TP->query_real_name()+
      " has become of higher quality!\n");
    return;}
  if (new_lev == current_lev) {
    if(current_lev == 10) {
      TE(TP,"You cannot enhance your quality any further.\n");
      TE(TP,"You have reached your maximum level.\n");
      return;}
    new_lev++;
    current_lev++;
    new_lev_xp = low_exp(new_lev);
    temp = new_lev_xp - current_xp;
    TE(TP,"You need "+temp+
      " more experience points to advance to quality level "+
      current_lev+".\n");
    return;}
  if (new_lev < current_lev) {
    TE(TP,"Experience point error, fixing your database.\n");
    IP(targob)->set_rank(new_lev);
    return;}
}

int low_exp(int level) {
  int xp;
  switch(level) {
    case 0:	xp = 0; 		break;
    case 1:	xp = 100; 		break;
    case 2:	xp = 1000; 	break;
    case 3:	xp = 10000; 	break;
    case 4:	xp = 100000; 	break;
    case 5:	xp = 200000; 	break;
    case 6:	xp = 300000; 	break;
    case 7:	xp = 400000; 	break;
    case 8:	xp = 500000; 	break;
    case 9:	xp = 600000; 	break;
    case 10:	xp = 700000; 	break;
    }
  return xp;
}

int xp_list(int xp) {
  int lev;
  if(xp <= 99) { 		lev = 0; return lev;}
  if(xp <= 999) { 		lev = 1; return lev;}
  if(xp <= 9999) { 		lev = 2; return lev;}
  if(xp <= 99999) { 	lev = 3; return lev;}
  if(xp <= 199999) { 	lev = 4; return lev;}
  if(xp <= 299999) { 	lev = 5; return lev;}
  if(xp <= 399999) { 	lev = 6; return lev;}
  if(xp <= 499999) { 	lev = 7; return lev;}
  if(xp <= 599999) { 	lev = 8; return lev;}
  if(xp <= 699999) { 	lev = 9; return lev;}
  if(xp >= 700000) { 	lev = 10; return lev;}
  return lev;
}

string guild_title(int level) {
  string title;
  switch(level) {
    case 10:title = "the big bad warrior";		break;
    case 9: title = "the warrior";				break;
    case 8: title = "the great adventurer";		break;
    case 7: title = "the experienced adventurer";	break;
    case 6: title = "the small adventurer";		break;
    case 5: title = "the experienced fighter";	break;
    case 4: title = "the small fighter";			break;
    case 3: title = "the master ranger";			break;
    case 2: title = "the lowrank ranger";		break;
    case 1: title = "the simple wanderer";		break;
    case 0: title = "the utter novice";			break;
    }
  return title;
}

set_guild_title() {
  string new_title;
  if(IP(TP)) {
    new_title = guild_title(IP(TP)->guild_lev());
    IP(TP)->change_title(new_title);
    IP(TP)->save_me();
    return;}
}

help_levels() {
  write("List of levels and experience for CyberNinja guild.\n");
  write("LEVEL		XP				TITLE\n");
  write("_______________________________________________________\n");
  write("Level 1		"+low_exp(1)+"		"+guild_title(1)+"\n");
  write("Level 2		"+low_exp(2)+"		"+guild_title(2)+"\n");
  write("Level 3		"+low_exp(3)+"		"+guild_title(3)+"\n");
  write("Level 4		"+low_exp(4)+"		"+guild_title(4)+"\n");
  write("Level 5		"+low_exp(5)+"		"+guild_title(5)+"\n");
  write("Level 6		"+low_exp(6)+"		"+guild_title(6)+"\n");
  write("Level 7		"+low_exp(7)+"		"+guild_title(7)+"\n");
  write("Level 8		"+low_exp(8)+"		"+guild_title(8)+"\n");
  write("Level 9		"+low_exp(9)+"		"+guild_title(9)+"\n");
  write("Level 10	"+low_exp(10)+"	"+guild_title(10)+"\n");
}

rank_info() {
  write(TP->query_real_name()+"'s CyberNinja guild info......\n");
  write("Quality Level: "+IP(TP)->guild_lev()+"\n");
  write("Guild Xp: "+IP(TP)->guild_exp()+"\n");
}


net_channel_emote(str) {
   int i;
   object people, memb;
   if(!str) {
      write("Usage nem <emote>.\n");
      return 1;}
   people = users();
   for(i = 0; i<sizeof(people); i++) {
      memb=IP(people[i]);
      if(memb && memb->muffled() < 1) {
         tell_object(people[i], "\n(CYBER) "+
           capitalize(this_player()->query_real_name())+
           " "+str+"\n");
       }
   }
   return 1;
}

net_muffle_channel(str) {
  int muff;
  muff = IP(TP)->muffled();
   if(!str) {
      write("Useage: line <on/off>\n");
      return;
   }
  if(str == "off") {
      if(muff == 1) {
         write("You already are muffled.\n");
         return;} 
      else
         muff = 1;
      write("You are now muffled.\n");
      IP(TP)->set_muffle(muff);
      return;
   }
   if(str == "on") {
      if(muff == 0) {
         write(" You were not muffled.\n");
         return;
         } 
      else muff = 0;
      write("You are now on the CyberNet.\n");
      IP(TP)->set_muffle(muff);
      return;
      }
}


net_who() {
   object list, guild;
   int i,level;
   list = users();
   write("\n");
   write("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
   write("NAME:\t\tQUALITY:\tMUFFLED:  LOCATION\n");
   write("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
   for(i=0; i < sizeof(list); i++) {
      guild = IP(list[i]);
      if(guild) {
         write(capitalize(list[i]->query_real_name()));
         if(strlen(list[i]->query_real_name())>7) write("\t"); 
         else write("\t\t");
         write(guild->guild_lev()+"\t");
         if(guild->muffled() > 0) write("Yes\t");
         else write("No\t");
         if(!environment(list[i])) write("Logging in");
         else write(environment(list[i])->short());
         write("\n");
       }
   }
   write("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
   return 1;
}

net_channel(str) {
   object everyone, member;
   int i;
   if(!str) {
      Write("Usage: net <message>.\n");
      return;}
   everyone = users();
   for(i = 0; i < sizeof(everyone); i++) {
      member = IP(everyone[i]);
      if(member && member->muffled() < 1) {
        tell_object(everyone[i], 
          "CYBERNET~~~" + TP->query_name() +">>> "+str+"\n");
        }
      }
   return 1;
}
  
check_time() {
  call_other("/room/church.c","long","clock");
  return;
}

leave_ninjas() {
  int guild_xp, guild_rank, real_exp;
  guild_xp = IP(TP)->guild_exp();
  guild_rank = IP(TP)->guild_lev();
  real_exp = call_other(TP, "query_exp", 0);
  IP(TP)->set_xp(-guild_xp);
  IP(TP)->set_rank(-guild_rank);
  IP(TP)->set_guild_name(0);
  call_other(TP, "add_exp", -real_exp/6);
  TE(TP, "You lose 1/6th of your experience for leaving a guild.\n");
  TE(TP, "Your cyberlinks are disconnected.\n");
  TE(TP, "Your implants are removed, painfully.\n");
  TE(TP, "You perform the Ninja ritual of leaving.\n");
  TE(TP, "You have left the CyberNinja Guild.\n");
  IP(TP)->save_me();
  net_channel(TP->query_real_name()+" has quit the Ninjas.\n");
  destruct(IP(TP));
}

exchange_exp(string str) {
  int amount, current_real_xp, new_guild_xp, min_xp;
  if(!str) {
    TE(TP,"How much experience do you want to exchange?\n");
    return;}
  if(!sscanf(str, "%d", amount)) {
    TE(TP,"Usage: exchange <amount>.\n");
    return;}
  if(amount == 0) {
    TE(TP,"Why waste your time exchanging zero experiee Try   >:)   \n");
    return;}
  current_real_xp = call_other(TP, "query_exp", 0);
  if(TP->query_level() > 19) 
   min_xp = call_other("/room/adv_guild.c","get_next_exp", 0);
  else
   min_xp = call_other("/room/adv_guild.c","get_next_exp",TP->query_level());
  if(amount > current_real_xp) {
    TE(TP,"You do not have that much experience to exchange.\n");
    return;}
  if(current_real_xp - min_xp <= 0) {
    TE(TP,"You do not have extra experience to exchange experience.\n");
    return;}
  else {
    TE(TP,"Exchanging "+amount+" experience into guild experience.\n");
    IP(TP)->add_xp(amount);
    call_other(TP, "add_exp", -amount);
    IP(TP)->save_me();
    return;}
}

recruit_member(string str) {
  object ob;
  if(!str) {
    write("Usage: recruit <who>\n");
    return;}
  if(!find_player(str)) {
    write("User "+capitalize(str)+" not found.\n");
    return;}
  ob = find_player(str);
  if(already_in_a_guild(ob)) {
     TE(TP,ob->query_real_name()+
       " is a member of another guild.\n");
     return;}
  else join_guild(ob);
}

join_member() {
  object ob;
  ob = this_player();
  if(already_in_a_guild(ob)) {
    TE(TP,"You may only be a member of one guild.\n");
    return;}
  else join_guild(ob);
}

int already_in_a_guild(object ob) {
  if((ob->query_guild_name() != 0) || 
     (ob->query_guild_xp() != 0)   ||
     (ob->query_guild_rank() != 0)) {
       return 1;}
  return 0;
}   

join_guild(object p_ob) {
   object g_ob;
   g_ob=clone_object("/players/dune/closed/guild/implants.c");
   move_object(g_ob, this_player());
   TE(p_ob,"Implants are surgically placed inside your body.\n");
   TE(p_ob,"Your electronics are connected to the CyberNet.\n");
   TE(p_ob,".....You are now a CyberNinja!\n");
   TE(p_ob,"Type 'cyber' to see the general guild help list.\n");
   net_channel(p_ob->query_real_name()+" has joined the Ninjas!\n");
   return;
}
