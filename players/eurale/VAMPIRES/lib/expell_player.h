/*
  expell_traitor.h
*/

#include "/players/eurale/defs.h"

/* ------ throw a cheater out ------ */
expell_player(str) {
  object stuff, target_obj;
  int i, minus, exp, is_vamp;
  string player_name, player_reason;

if(TPRN != "fred" && TPRN != "khrell" && TPRN != "rumplemintz") {
  write("You do not have authority to do that!\n");
  return 1; }

if(!str) {
  write("Use: expell <who> "+
        "[E=expell, CE=council expell, P=prohibited, R=rejected]\n");
  return 1; }

sscanf(str, "%s %s", player_name, player_reason);
if(!player_name || !player_reason) {
  write("Use: expell <who> "+
        "[E=expell, CE=council expell, P=prohibited, Q=quit)]\n");
  return 1; }

player_reason = capitalize(player_reason);
if(player_reason!="E" &&
    player_reason!="CE" &&
    player_reason!="P" &&
    player_reason != "R" &&
    player_reason!="Q") {
  write("Invalid reason code.  "+
        "[E=expell, CE=council expell, P=prohibited, R=rejected]\n");
  return 1; }

target_obj=find_living(player_name);
call_other(MEMBER, "???");
if(target_obj)
  is_vamp = call_other(MEMBER, "query_member", player_name);
else
  is_vamp = 0;
if(!is_vamp) target_obj = 0;
if(!target_obj) {
    /* take them off the member list */
  call_other(MEMBER, "???");
  call_other(MEMBER, "delete_player", player_name);
    /* add them to the traitor list & indicate they were Expelled */
  call_other(TRAITOR, "???");
  call_other(TRAITOR, "add_player", player_name, player_reason);
  write(capitalize(player_name)+" is now on the guild prohibited list "+
        "for ("+player_reason+").\n");
  return 1; }

  /* get rid of any guild stuff around */
target_obj->dismiss_bat("bat");
  /* destruct their coffin & everything in it */
call_other(COFFIN_ROOM, "???", 0);
stuff = first_inventory(COFFIN_ROOM);
while (stuff) {
  if(stuff->query_coffin_owner_name() == player_name) {
    destruct(stuff);
    break;
  }
  stuff = next_inventory(stuff);
}

  /* dismiss wolf, if there is one */
if(PFANGS->query_wolf_obj()) destruct(PFANGS->query_wolf_obj());
  /* now drop any vampire equipment they have */
if(present("vampire dagger", target_obj))
  command("drop dagger", target_obj);
if(present("vampire tuxedo", target_obj))
  command("drop tuxedo", target_obj);
  /* take them off the member list */
call_other(MEMBER, "???");
call_other(MEMBER, "delete_player", player_name);
  /* add them to the traitor list */
call_other(TRAITOR, "???");
call_other(TRAITOR, "add_player", player_name, player_reason);
  /* fix their title */
target_obj->set_title("-->Expelled from the Vampire guild");
i = target_obj->query_guild_exp();
target_obj->add_guild_exp(-i);
target_obj->set_guild_name(0);
target_obj->set_guild_file(0);
stuff = present("vampire fangs", target_obj);
exp = target_obj->query_exp();
minus = exp / 4;
target_obj->add_exp(-minus);

/* reduce stats of expelled player */
target_obj->raise_strength(-5);
if(target_obj->query_attrib("str") < 0) target_obj->set_attrib("str") == 0;
target_obj->raise_magic_aptitude(-5);
if(target_obj->query_attrib("mag") < 0) target_obj->set_attrib("mag") == 0;
target_obj->raise_stamina(-5);
if(target_obj->query_attrib("sta") < 0) target_obj->set_attrib("sta") == 0;
target_obj->raise_will_power(-5);
if(target_obj->query_attrib("wil") < 0) target_obj->set_attrib("wil") == 0;
target_obj->raise_stealth(-4);
if(target_obj->query_attrib("ste") < 0) target_obj->set_attrib("ste") == 0;
target_obj->raise_luck(-3);
if(target_obj->query_attrib("luc") < 0) target_obj->set_attrib("luc") == 0;
target_obj->raise_intelligence(-3);
if(target_obj->query_attrib("int") < 0) target_obj->set_attrib("int") == 0;
target_obj->raise_piety(-2);
if(target_obj->query_attrib("pie") < 0) target_obj->set_attrib("pie") == 0;
target_obj->save_me();
destruct(stuff);
write(BOLD+
  capitalize(player_name)+" has been expelled from the Vampires!\n"+NORM);
rm("/"+VMEMBER+target_obj->query_real_name()+".o");
return 1;
}
