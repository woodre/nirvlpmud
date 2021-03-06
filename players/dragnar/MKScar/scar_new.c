#include "scar.h"
#include <ansi.h>
#define att ((object) call_other(environment(), "query_attack"))
#define NAME(x) ((string) call_other(x, "query_name"))
#define TIME 300

int    MKForfeits, MKWins, CDelay, muffled, pkills, ansi;
mixed *MKVictims;
static mapping cmds;
static string checker, _reply;
static object MKOpponent;
static int checklev, LoginTime;
static status MKChallenge, MKIssued;

#include "/players/beck/MortalKombat/MKScar/Killed.c"
#include "/players/beck/MortalKombat/MKScar/Fatality.c"

query_checker() { return checker; }
query_muffled() { return muffled; }
query_pkills()  { return pkills; }
query_ansi() { return ansi; }
QMKForfeits() { return MKForfeits; }
QMKChallenge() { return MKChallenge; }
QMKOpponent() { return MKOpponent; }
QMKIssued() { return MKIssued; }
QLoginTime() { return time() - LoginTime; }
QCDelay() { return CDelay; }
QMKVictim(string str) {
  if(member_array(str, MKVictims) > -1) return 1;
  else return 0;
}

set_reply_list( reply_str ) {  _reply = reply_str; }
set_pkills(ks)  { pkills = ks; }
set_muffled(mf) { muffled = mf; }
set_ansi(x) { ansi = x; }
SCDelay() { CDelay = 900; }
QMKRank() {
  if(user->is_player() && user->query_level() > 20) {
    return "---";
  }
  else return Rank;
}
AMKForfeits() { MKForfeits++; }
CMKForfeits() { MKForfeits = 0; }

AMKWins(string name, int amt) {
  int index;
  if(!MKVictims)
     MKVictims = ({});
  index = member_array(name, MKVictims);
  if( index > -1 ) {
    MKVictims[index+1] = MKVictims[index+1] + 1;
  }
  else {
    MKVictims += ({ name, 1 });
  }
}

id(str) { return str == "scar" || str == "bloodscar" || str == "kill_check_object"; }
short() { return 0; }
query_auto_load() { return "/players/dragnar/MKScar/scar:"; }
get() { return 1; }
drop() { return 1; }
query_value() { return 0; }
init_arg(s) {
  if(environment(this_object())) {
    if((user->is_player() && user->query_level() < 21) || user->is_npc()) {
      if(this_player()->query_name() != "some mist") RANK->NewInsert(this_player()->query_name());
    }
    LoginTime = time();
  }
}

long() {
   write(
"This is the scar you recieved when you became a champion of Mortal\n"+
"Kombat.  The scar means you are worthy of the powers it possesses.\n"+
"Type \"scar info\" to see what the scar enables you to do.\n");
}

remove_object() {
   CHANNELD->deregister(this_object(), CHANNAME);
   destruct(this_object());
   return 1;
}

receive_message(int p, string bwmsg, string cmsg) {
   if (!muffled || p)
      tell_object(user, ansi ? cmsg : bwmsg);
}

extra_look() {
  if (this_player() == environment())
    return "You have a symbol of a dragon branded on your forearms";
  else {
    if(user->is_player() || present("bloodscar",this_player()) ||
      present("mkquest",this_player())) {
    return environment()->query_name() +
      " has a symbol of a dragon branded on " +
      environment()->query_possessive() + " forearms";
    }
  }
}
ev_pkill(object victim) {
   int level_diff;
   string msg;

   if (!objectp(victim) || !interactive(victim)) return;
   if (environment(victim) && environment(victim)->query_spar_area()) return;
   if (environment(user) && environment(user)->query_spar_area()) return;
   checklev = (int) victim->query_level() + victim->query_extra_level();
   level_diff = (int) user->query_level() - victim->query_level();
   if( level_diff > 8 ) {
      checklev = 0;
   }
   pkills += checklev;
   command("save_me", user);

   checker = victim->query_real_name();
   tell_object(user, "You have killed " + checker + " and gain " +
                     checklev + " kills.\n");
   if(user->is_player() && !user->id("masakado"))
   TOPLIST->Insert(capname, pkills);
   msg = HIR+capitalize(RN)+" has killed "+capitalize(checker)+"."+NORM+"\n";
   CHANNELD->broadcast(msg, 0, "Blood");
}


init() {
  if(this_player() != environment()) {
    return;
  }
   if (present("bloodscar 2", environment())) {
      tell_object(user, "Disintegrating duplicate scar...\n");
      destruct(this_object());
      return;
   }

   MKChampion = 1;
   CHANNELD->register(this_object(), CHANNAME);
   restore_me();
   LoginTime = time();
   if((user->is_player() && user->query_level() < 21) || user->is_npc()) {
     RANK->NewInsert(this_player()->query_name());
   }

    if(this_player()->query_level() > 20) {
      add_action("faucet","check_log");
      add_action("faucet","boot_blood");
      add_action("faucet","set_kills");
      add_action("faucet","query_player");
   }
   add_action("save_me","save_me");
   add_action("restore_me","restore_me");
/*
   add_action("reply","reply");
*/

   if (cmds = ACTIONS->query_cmds()) {
               string *ks; int i;
               i = sizeof(ks = keys(cmds));
               while (i--) add_action("ScarAction", ks[i]);
      }
  if( sizeof(ks) < 2) {
    write_file(ERROR,ctime(time())+" cmds is "+sizeof(ks)+" big!\n");
  }
}

ScarAction(string str) {
    string cmd;
    if (cmd = cmds[query_verb()])
        return (status) cmd->main(str);
}

restore_me() {
   if (!user)
      return 0;
   if (restore_object(SAVE_PATH + RN)) {
       tell_object(user, "Restoring kill stats...\n");
       return 1;
   }
   else
       tell_object(user, "No kills stats to restore...\n");
       save_me();
   return 1;
}

save_me() {
  if(!MKVictims) MKVictims = ({});
   if (save_object(SAVE_PATH + RN), 1)
       tell_object(user, "Saving kill stats.\n");
   else
      tell_object(user, "Error in saving kill stats!\n");
   return 1;
}

reply( string str ) {
    string temp_str;

    if( _reply == 0 ) {
        write("No one to reply to.\n");
        return 1;
    }
    if( !str ) {
         write("You will reply to "+_reply+".\n");
        return 1;
    }
    else {
        temp_str = _reply + " " + str;
        command("mtell "+temp_str+"", this_player());
        return 1;
    }
}

void
Challenged(int chal, object who) {
  MKIssued = chal;
  MKChallenge = 1;
  MKOpponent = who;
  if(chal) {
    /* we are the one being challenged, so start call_out */
    call_out("MKTimeOut", TIME);
  }
}

MKTimeOut() {
  object scarobj;

  if(!MKChallenge || !MKOpponent) {
    ChallengeReset();
    return;
  }
  tell_object(MKOpponent, capname+" forfeited your Mortal Kombat challenge.\n");
  tell_object(user, "You forfeit the Mortal Kombat challenge to "+MKOpponent->query_name()+".\n");
  scarobj = present("bloodscar", MKOpponent);
  ChallengeReset();
  scarobj->ChallengeReset();
  remove_call_out("MKTimeOut");
}

MKBegin() {
  if(!MKChallenge || !MKOpponent) {
    ChallengeReset();
    return;
  }
  tell_object(user, "You accept the Mortal Kombat Challenge!\n");
  tell_object(MKOpponent, capname+" accepts your Mortal Kombat Challenge!\n");
  remove_call_out("MKTimeOut");
  CHALLENGE->AddQue(user, MKOpponent);
}


MKNPC() {
  call_out("NPCStart", random(120));
}

NPCStart() {
  if(!MKChallenge || !MKOpponent) {
    ChallengeReset();
    return;
  }
  tell_object(MKOpponent, capname+" tells you: I'm looking forward to killing you.\n");
  command("accept challenge", user);
}
ChallengeReset() {
  MKChallenge = 0;
  MKOpponent = 0;
  MKIssued = 0;
}

void
kill_check(object ob)
{
  if((status)ob->is_player() && !ob->id("masakado"))
    ev_pkill(ob);
  if(environment(user) && environment(user)->QueryMKTemple() ) {
    write("Resetting Temple.\n");
    environment(user)->ResetTemple();
  }
}
