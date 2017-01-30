#include "/players/dragnar/MKScar/scar.h"
#include "/players/dragnar/closed/color.h"
#define att ((object) call_other(environment(), "query_attack"))
#define NAME(x) ((string) call_other(x, "query_real_name"))
int    pdeaths, MKWins, muffled, pkills, ansi;
mixed *MKVictims;
static mapping cmds;
static string checker,_reply;
static object checker_ob;
static int checklev;
#include "/players/beck/MortalKombat/MKScar/Killed.c"
#include "/players/beck/MortalKombat/MKScar/Fatality.c"
query_checker() { return checker; }
query_muffled() { return muffled; }
query_pkills()  { return pkills; }
query_pdeaths() { return pdeaths; }

set_reply_list( reply_str ) {  _reply = reply_str; }
set_pdeaths(ob) { pdeaths = ob; }
set_pkills(ks)  { pkills = ks; }
set_muffled(mf) { muffled = mf; }
toggle_ansi(f)   { return (ansi ^= f); }
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

id(str) { return str == "scar" || str == "bloodscar"; }
short() { return 0; }
query_auto_load() { return "/players/dragnar/MKScar/scar:" + ansi; }
get() { return 1; }
drop() { return 1; }
query_value() { return 0; }
init_arg(s) { ansi = atoi(s);}

long() {
   write(
"This is the scar you recieved when you became a champion of Mortal\n"+
"Kombat.  The scar means you are worthy of the powers it possesses.\n"+
"Type infoscar to see what the scar enables you to do.\n");
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

ev_pkill(object victim) {
   int level_diff;

   if (!objectp(victim) || !interactive(victim)) return;
   if (environment(victim) && environment(victim)->query_spar_area()) return;
   if (environment(user) && environment(user2)->query_spar_area()) return;
   checklev = (int) victim->query_level() + victim->query_extra_level();
   level_diff = (int) user2->query_level() - victim->query_level();
   if( level_diff > 5 ) {
      checklev = 0;
   }
   pkills += checklev;
   command("save_me", user);

   checker = NAME(victim);
   tell_object(user, "You have killed " + checker + " and gain " +
                     checklev + " kills.\n");

    CHANNELD->broadcast(
        "<<"+RED+"Angel of Death"+RESET+">>: " + capitalize(RN) + " has killed " +
        capitalize(victim) + ".\n",
        1, CHANNAME);

}

ev_death(object killer) {
   if (!objectp(killer) || !interactive(killer)) return;
   if (environment(killer) && environment(killer)->query_spar_area()) return;
   if (environment(user) && environment(user)->query_spar_area()) return;
   pdeaths++;
   command("save_me", user2);
}

init() {
   if (this_player() != environment())
       return;
   if (present("bloodscar 2", environment())) {
      tell_object(user, "Disintegrating duplicate scar...\n");
      destruct(this_object());
      return;
   }
   if (previous_object() && previous_object()->id("shang"))
   {
      write_file(CHAMPLOG, ctime() + " >> " + this_player()->query_real_name() + ".\n");
      save_me();
   }
   CHANNELD->register(this_object(), CHANNAME);
   restore_me();

   if (this_player()->query_level() < 20)
      call_out("hb",5);
   else {
      add_action("faucet","check_log");
      add_action("faucet","boot_blood");
      add_action("faucet","set_kills");
      add_action("faucet","check");
      add_action("faucet","query_player");
   }
   add_action("save_me","save_me");
   add_action("restore_me","restore_me");

   if (cmds = ACTIONS->query_cmds()) {
               string *ks; int i;
               i = sizeof(ks = keys(cmds));
               while (i--) add_action("ScarAction", ks[i]);
      }
}

ScarAction(string str) {
    string cmd;
    if (cmd = cmds[query_verb()])
        return (status) cmd->main(str);
}
/*
 * this is a little complicated..
 * first time into this function checker_ob is 0, and it stays 0
 * until user2 begins fighting another *player*. And first then:
 * At the following hb, I check for the kill. If no kill, store
 * current opponent, and call_out again..
 *
 * Say opponent dies, query_attack() might not return the opponent
 * anymore, but because I check the stored opponent _before_
 * obtaining current opponent, the kill won't be lost.
 * Plus, no "old" kills. checker_ob lifetime is only one round
 */

hb() {
   object ob;

   if (checker_ob && checker_ob->query_ghost()) {
      ev_pkill(checker_ob);
      /* Now taken care of by the person that got killed
	  if (ob = present("bloodscar", checker_ob))
         ob->ev_death(user2);
      */
      /* check if fighting somebody new */
      if ((ob = att) && (ob != checker_ob) && interactive(ob))
         checker_ob = ob;
      else
         checker_ob = 0;
   }
   else if(checker_ob && environment(this_object())->query_ghost()) {
      ev_death( checker_ob );
	  checker_ob = 0;
   }
   else {
      checker_ob = 0;
      if ((ob = att) && interactive(ob))
         checker_ob = ob;
   }
   call_out("hb", (checker_ob) ? 1 : 2);
}

restore_me() {
   if (!user)
      return 0;
   if (restore_object(SAVE_PATH + NAME(user)))
       tell_object(user, "Restoring kill stats...\n");
   else
       tell_object(user, "No kills stats to restore...\n");
   return 1;
}

save_me() {
   if (save_object(SAVE_PATH + user->query_real_name()), 1)
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

