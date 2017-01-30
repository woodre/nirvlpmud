#include "scar.h"
#define user environment()
#define att ((object) call_other(environment(), "query_attack"))
#define NAME(x) ((string) call_other(x, "query_real_name"))
#define RN NAME(user)

int    pdeaths, muffled, pkills, checklev, ansi;
static string checker,_reply;
static object checker_ob;

query_checker() { return checker; }
query_muffled() { return muffled; }
query_pkills()  { return pkills; }
query_pdeaths() { return pdeaths; }

set_reply_list( reply_str ) {  _reply = reply_str; }
set_pdeaths(ob) { pdeaths = ob; }
set_pkills(ks)  { pkills = ks; }
set_muffled(mf) { muffled = mf; }
toggle_ansi(f)   { return (ansi ^= f); }

id(str) { return str == "scar" || str == "bloodscar"; }
short() { return "Blood scar of Mortal Kombat"; }
query_auto_load() { return "/players/dragnar/closed/scar:" + ansi; }
get() { return 0; }
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


init() {
   if (this_player() != environment())
       return;
   if (present("bloodscar 2", environment())) {
      tell_object(user, "Disintegrating duplicate scar...\n");
      destruct(this_object());
      return;
   }

   CHANNELD->register(this_object(), CHANNAME);
   restore_me();

   if (this_player()->query_level() > 20)
   {
      add_action("faucet","check_log");
      add_action("faucet","boot_blood");
      add_action("faucet","set_kills");
      add_action("faucet","check");
      add_action("faucet","query_player");
   }
   add_action("reply","reply");
   add_action("faucet","mtell");
   add_action("faucet","heal_scar");
   add_action("faucet","give_scar");
   add_action("faucet","new_scar");
   add_action("faucet","infoscar");
   add_action("faucet","infokills");
   add_action("faucet","scaransi");
   add_action("faucet","deathmatch");
   add_action("restore_me","restore_me");
/* Removed -- Dragnar 12/27/99 ***************************
   add_action("save_me","save_me");
**********************************************************/
   add_action("faucet","stats");
   add_action("faucet","ppl");
   add_action("faucet","bdt");
   add_action("faucet","bts");
   add_action("faucet","bbe");
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

/******************************************************************
save_me() {
   if (save_object(SAVE_PATH + RN), 1)
       tell_object(user, "Saving kill stats.\n");
   else
      tell_object(user, "Error in saving kill stats!\n");
   return 1;
}
*****************************************************************/

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
        MASTER->mtell( temp_str );
        return 1;
    }
}
faucet(string arg) {
   if(query_verb() == "deathmatch") {
      write(
        "Deathmatch has been temporarily removed.\n"+
        "All cotrolled death arenas mudwide have been closed due to\n"+
        "player abusing certain bugs.\n"+
        "\n\nHopefully it will reopen soon.  --the management.\n");
      return 1;
   }
   return (status) call_other(MASTER, query_verb(), arg);
}
