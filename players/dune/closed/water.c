/* Dune and Snow's wiztool.
 */

#include <ansi.h>
 
#define MARK "/players/snow/closed/mark.c"
#define META "/players/snow/closed/metaobj.c"
#define DEST "/players/snow/closed/tbolt.c"
#define BIND "/players/snow/closed/binder.c"
#define HOP "/players/snow/ITEMS/d_hop.c"
#define DO "/players/snow/closed/do.c"
#define FIX "/players/dune/objects/fixer.c"
#define TOOL "/obj/wiz_tool_master.c"
#define RE return 1


id(str) { return str == "water"; }


long()
{
  write("The Water of Life...\n"+
        "Only true messiahs may drink this water.\n"+
        "Type 'usil' for help.\n");
  return 1;
}


short()
{
  string who;
  who=this_player()->query_real_name();
  if(who!=environment(this_object())->query_real_name())
  {
    tell_object(environment(this_object()),
      esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[32m"+esc+"[40m");
    tell_object(environment(this_object()),capitalize(who)+
      " has just checked your inventory.");
    tell_object(environment(this_object()),esc+"[0m"+"\n");
  }
  return "The Water of Life";
}


get() { return 1;}
query_weight() { return 0; }
drop() {return 1;}


init()
{
  if(environment() && this_player() && 
     this_player()->query_real_name() != "snow"  &&
     this_player()->query_real_name() != "dune")
  {
    shout("*** *** KA - BLAM! *** ***\n");
    destruct(this_object());
  }

  add_action("markhelp", "usil");
  add_action("healme", "healme");
  add_action("no_fight","peace");
  add_action("dungeon_player","bottleup");
  add_action("church_player","convert");
  add_action("trans_object","movit");
  add_action("goto","geto");
  add_action("bring_player","summon");
  add_action("force","force");
  add_action("add_ghost","ghostin");
  add_action("rem_ghost","exorcism");
  add_action("vanish","vanish");
  add_action("steal","steal");
  add_action("check","check");
  add_action("setnum","setnum");
  add_action("set2num","set2num");
  add_action("setword","setword");
  add_action("p_get","pget");
  add_action("p_drop","pdrop");
  add_action("id_ob","Id");
  add_action("wiz_tell","wtell");
  add_action("settrib","settrib");
  add_action("wiz_hand","hand");
  add_action("all_room","allinv");
  add_action("metanum_object","metnum");
  add_action("metaword_object","metword");
  add_action("metacheck_object","metcheck");
  add_action("met","met");
  add_action("metas","metas");
  add_action("thunder_bolt","Bolt");
  add_action("opp_burst","Burst");
  add_action("silent_dest","Dest");
  add_action("over_kill","Kill");
  add_action("force_quit","Quit");
  add_action("dests","dests");
  add_action("monster_attack","mattack");
  add_action("monster_scan","mscan");
  add_action("monster_compare","mcompare");
  add_action("clear_scan","noscan");
  add_action("binds","binds");
  add_action("hop_where","where");
  add_action("hop_hop","hop");
  add_action("do_cmd","do");
  add_action("check_guild","guild");
  add_action("remove_guild","unguild");
  add_action("view_qt","view");
  add_action("upall","upall");
  add_action("dest_all","destall");
  add_action("place_object","obput");
  add_action("wave_away","tsunami");
  add_action("find_dest","fdest");
  add_action("get_owner","get_owner");
}


markhelp() { MARK->markhelp(); RE; }
healme() { MARK->healme(); RE; }
no_fight(str) { MARK->no_fight(str); RE; }
dungeon_player(str) { MARK->dungeon_player(str); RE; }
church_player(str) { MARK->church_player(str); RE; }
trans_object(str) { MARK->trans_object(str); RE; }
goto(string str) { MARK->goto(str); RE; }
bring_player(str) { MARK->bring_player(str); RE; }
force(str) { MARK->force(str); RE; }
add_ghost(str) { MARK->add_ghost(str); RE; }
rem_ghost(str) { MARK->rem_ghost(str); RE; }
vanish(str) { MARK->vanish(str); RE; }
steal(str) { MARK->steal(str); RE; }
check(str) { MARK->check(str); RE; }
setnum(str) { MARK->setnum(str); RE; }
set2num(str) { MARK->set2num(str); RE; }
setword(str) { MARK->setword(str); RE; }
p_get(str) { MARK-power_get(str); RE; }
p_drop(str) { MARK->power_drop(str); RE; }
id_ob(str) { MARK->identify_object(str); RE; }
wiz_tell(str) { MARK->wiz_tell(str); RE; }
settrib(str) { MARK->settrib(str); return 1; }
wiz_hand(str) { TOOL->hand(str); RE; }
all_room(string str) { MARK->all_room(str); RE; }
metanum_object(string str) { META->metanum_object(str); RE; }
metaword_object(string str) { META->metaword_object(str); RE; }
metacheck_object(string str) { META->metacheck_object(str); RE; }
met(string str) { META->met(str); RE; }
metas() { META->powerlist(); RE; }
thunder_bolt(string str) { DEST->thunder_bolt(str); RE; }
opp_burst(string str) { DEST->opp_burst(str); RE; }
silent_dest(string str) { DEST->silent_dest(str); RE; }
over_kill(string str) { DEST->over_kill(str); RE; }
force_quit(string str) { DEST->force_quit(str); RE; }
dests() { DEST->powerlist(); RE; }
monster_attack(string str) { BIND->monster_attack(str); RE; }
monster_scan(string str) { BIND->monster_scan(str); RE; }
monster_compare(string str) { BIND->monster_compare(str); RE; }
clear_scan() { BIND->clear_scan(); RE; }
binds() { BIND->powerlist(); RE; }
hop_where() { HOP->where(); RE; }
hop_hop(string str) { HOP->hop(str); RE; }
get_owner(string str) { FIX->get_owner(str); RE; }
check_guild(string str) { FIX->guild(str); RE; }
remove_guild(string str) { FIX->unguild(str); RE; }
view_qt(string str) { FIX->view(str); RE; }
upall() { FIX->upall(); RE; }
dest_all(string str) { MARK->dest_all(str); RE; }
do_cmd(string str) { DO->do_cmds(str); RE; }
place_object(string str) { MARK->place_object(str); RE; }
wave_away(string str) { MARK->wave_away(str); RE; }
find_dest(string str) { MARK->find_dest(str); RE; }
