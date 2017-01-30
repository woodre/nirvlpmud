inherit "obj/clean"

#define SAVE_P "players/dune/talk/"
#define FILE "/players/dune/objects/talkobj.c"
#define MASTER_AU "/players/dune/objects/talkdaem.c"
#define TP this_player()
#define RN TP->query_real_name()

string presy, postsy;
int talkmsr, totalt;

id(str) { return str == "talker"; }
short () { return "A fancy talker :O "; }
long() { MASTER_AU->uselist(); }

drop() { return 1; }
get() { return 1; }
query_weight() { return 0; }
query_value() { return 0; }
query_auto_load() { return "/players/dune/objects/talkobj.c:"; }

init() {
   restore_talk();
   if(query_totaltalk()) {
     add_action("ft","tell");
     add_action("sy","say"); }
   add_action("save_talk","savetalk");
   add_action("restore_talk","loadtalk");
   add_action("totaltalk","totaltalk");
   add_action("sy","sy");
   add_action("presay","presay");
   add_action("postsay","postsay");
   add_action("talkmagic","talkmagic");
   add_action("viewtalk","viewtalk");
   add_action("notalk","notalk");
   add_action("newtalk","newtalk");
   add_action("givetalk","givetalk");
   add_action("bug_report","talknote");
   add_action("whotalk","whotalk");
   if( (RN == "dune") || (talkmsr) ||
       (TP->query_level() >= 20) ) {
       add_action("versions","versions");
       add_action("talkup","talkup");
       add_action("talkupall","talkupall");
       add_action("talkrm","talkrm"); }
   if (RN == "dune") add_action("master","master");
}

restore_talk() {
  object player;
  if(TP->query_guild_name() == "vampire") {
    write("Your little talker device disintegerates\n"+
          "because you are a vampire :(, sorry.\n");
    destruct(this_object());
    return; }
  player = find_player(RN);
  if(!TP) { return 0; }
  tell_object(player, "Loadin' talker scripts :) \n");
  restore_object(SAVE_P + RN); return 1; }

save_talk() {
  string file;  file = SAVE_P + RN;
  if(!save_object(file)) {
tell_object(TP, "Error in savin' talker scripts :o \n"); return 1;}
  else {
tell_object(TP, "Savin' talker scripts :) \n"); return 1;} }

string query_presay() { return presy; }
string query_postsay() { return postsy; }
string query_version() { return "400x"; }
int query_totaltalk() { return totalt; }
int    query_talkmaster() { return talkmsr; }
change_totaltalk(int new) { totalt = new; }
change_master(int new) { talkmsr = new; }
change_presay(string newprsy) { presy = newprsy; }
change_postsay(string newposy) { postsy = newposy; }

sy(str)        { MASTER_AU->sy(str); return 1; }
postsay(str)   { MASTER_AU->postsay(str); return 1; }
presay(str)    { MASTER_AU->presay(str); return 1; }
talkmagic()    { MASTER_AU->talkmagic(); return 1; }
viewtalk()     { MASTER_AU->viewtalk(); return 1; }
givetalk(str)  { MASTER_AU->givetalk(str); return 1; }
talkup(str)    { MASTER_AU->talkup(str); return 1; }
whotalk()      { MASTER_AU->whotalk(); return 1; }
notalk()       { MASTER_AU->notalk(); return 1; }
talkupall()    { MASTER_AU->talkupall(); return 1; }
talkrm(str)    { MASTER_AU->talkrm(str); return 1; }
bug_report(str){ MASTER_AU->bug_report(str); return 1; }
versions()     { MASTER_AU->versions(); return 1; }
totaltalk(str) { MASTER_AU->totaltalk(str); return 1; }
master(str)   { MASTER_AU->master(str); return 1; }

newtalk() {
   write("Your talker is getting a little old and grimy, so\n");
   write("you flip it over and use the other side for a while.\n");
   move_object(clone_object("/players/dune/objects/talkobj.c"),
       this_player());
   destruct(this_object());
   return 1;}
