#include "scar.h"
#define user environment()
#define att ((object) call_other(environment(), "query_attack"))
#define NAME(x) ((string) call_other(x, "query_real_name"))
#define RN NAME(user)

int    pdeaths, pkills, checklev;
static string checker, muffled;
static object checker_ob;
static int ansi;

query_checker() { return checker; }
query_muffled() { return muffled; }
query_pkills()  { return pkills; }
query_pdeaths() { return pdeaths; }

set_pdeaths(ob) { pdeaths = ob; }
set_pkills(ks)  { pkills = ks; }
set_muffled(mf) { muffled = mf; }
toggle_ansi(f)   { return (ansi ^= f); }

id(str) { return str == "scar" || str == "bloodscar"; }
extra_look() { return environment(this_object())->query_name()+" has "+
"a Blood Scar of Mortal Kombat"; }
short(){ return 0; }
query_auto_load() { return "/players/beck/closed/scar:" + ansi; }
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
   if (!objectp(victim) || !interactive(victim)) return;
   if (environment(victim) && environment(victim)->query_spar_area()) return;
   if (environment(user) && environment(user)->query_spar_area()) return;
   pkills += (checklev = (int) victim->query_level());
   command("save_me", user);

   checker = NAME(victim);
   tell_object(user, "You have killed " + checker + " and gain " +
                     checklev + " kills!\n");
   MASTER->tell_scar(RN, checker);
}

ev_death(object killer) {
   if (!objectp(killer) || !interactive(killer)) return;
   if (environment(killer) && environment(killer)->query_spar_area()) return;
   if (environment(user) && environment(user)->query_spar_area()) return;
   pdeaths++;
   command("save_me", user);
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
      write_file(CHAMPLOG, ctime() + " >> " + this_player()->query_real_name() + ".\n");

   CHANNELD->register(this_object(), CHANNAME);
   restore_me();

   if (this_player()->query_level() < 20)
      call_out("hb", 5);
   else {
      add_action("faucet","check_log");
      add_action("faucet","boot_blood");
      add_action("faucet","set_kills");
      add_action("faucet","check");
      add_action("faucet","query_player");
   }
   add_action("faucet","heal_scar");
   add_action("faucet","give_scar");
   add_action("faucet","ddeeaatthhmmee");
   add_action("faucet","tell_scar");
   add_action("faucet","punt");
   add_action("faucet","new_scar");
   add_action("faucet","infoscar");
   add_action("faucet","infokills");
   add_action("faucet","scaransi");
   add_action("faucet","deathmatch");
   add_action("restore_me","restore_me");
   add_action("save_me","save_me");
   add_action("faucet","stats");
   add_action("faucet","ppl");
   add_action("faucet","bdt");
   add_action("faucet","bts");
   add_action("faucet","bbe");
}

/*
 * this is a little complicated..
 * first time into this function checker_ob is 0, and it stays 0
 * until user begins fighting another *player*. And first then:
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
      if (ob = present("bloodscar", checker_ob))
         ob->ev_death(user);

      /* check if fighting somebody new */
      if ((ob = att) && (ob != checker_ob) && interactive(ob))
         checker_ob = ob;
      else
         checker_ob = 0;
   }
   else {
      checker_ob = 0;
      if ((ob = att) && interactive(ob))
         checker_ob = ob;
   }
   call_out("hb", (checker_ob) ? 2 : 5);
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
   if (save_object(SAVE_PATH + RN), 1)
       tell_object(user, "Saving kill stats.\n");
   else
      tell_object(user, "Error in saving kill stats!\n");
   return 1;
}

faucet(string arg) {
   if (query_verb() == "deathmatch") {
      write(
        "Deathmatch has been temporarily removed.\n"+
        "All cotrolled death arenas mudwide have been closed due to\n"+
        "player abusing certain bugs.\n"+
        "\n\nHopefully it will reopen soon.  --the management.\n");
      return 1;
   }
   return (status) call_other(MASTER, query_verb(), arg);
}
