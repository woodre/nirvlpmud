/*
 * Fakir's Wiztell
 * (c) Vert & Fakir 2000
 */

#include "/players/vertebraker/define.h"
#define PATH "/players/fakir/closed/ftell.c"
string replyer;
string *history;
inherit TREASURE

id(str) {
  return str == "teller" || str == "link" || str == "smile" || str == "ftell"; }

long() {
  string name;
  name = USER->RN;
  if(name == "fakir") return write("Actions:\n\n1] Say\n2] Reply\n3] Tell\n4] History\n5] Fwho\n");
  if(name != "fakir") return write("A small, telepathic link to Fakir.\nYou can '"+HIR+"ft"+NORM+"' him if you wish.\n");
 }

init() {
  ::init();
  if(TP->RN != "fakir") write(HIR+"\nThe Sands whirl around you....."+NORM+"\nYou have received a telepathic link from "+HIR+"Fakir"+NORM+".\nUse "+HIR+"<"+NORM+"ft"+HIR+"> '"+NORM+"msg"+HIR+"'"+NORM+" to communicate with him.\n");
  if(TP->RN == "fakir") {
    add_action("cmd_fgive","fgive");
    add_action("cmd_reply","reply");
    add_action("cmd_tell","tell");
    add_action("cmd_say","say");
    add_action("cmd_say"); add_xverb("'"); 
    add_action("cmd_history","history");
    add_action("cmd_fwho","fwho"); }
    add_action("cmd_ft","ft"); }
  
extra_look() {
  string name;
  name = USER->RN;
  if(name != "fakir") return CAP(name)+" has a telepathic link to "+HIR+"Fakir"+NORM;
  if(name == "fakir") return CAP(name)+"'s glowing smile warms your heart"; }

drop() { return 1; }

cmd_tell(str) {
  object ob;
  string who,what;
  if(!str || (sscanf(str,"%s %s",who,what) != 2)) {
    FAIL("Tell who what?\n");
    return 0; }
  ob = find_player(who);
  if(!ob) {
    FAIL("Not logged on!\n");
    return 0; }
  write(HIR+"You tell "+CAP(who)+NORM+": "+what+"\n");
  tell_object(ob,
HIR+"Fakir tells you: "+NORM+what+"\n");
  ob->add_tellhistory(HIR+"Fakir told you: "+NORM+what);
  return 1; }

cmd_say(str) {
  if(!str) {
    FAIL("Say what?\n");
    return 0; }
  write(HIR+"You say: "+NORM+str+"\n");
  say(HIR+TPN+" says: "+NORM+str+"\n");
  return 1; }

add_history(string str, string str2) {
  if(!history) history = ({ });
  if(sizeof(history) > 18) history -= ({ history[0],history[1], });
  history += ({ str, str2, }); }

cmd_history() {
  int x,y;
  write(HIR+" -(-=             "+HIW+"FTELL HISTORY             "+HIR+"=-)-"+NORM+"\n");
  for(x = 0; x < sizeof(history); x+=2) {
    y += 1;
    write(HIW+y+NORM+"]"+HIR+" ~"+NORM+history[x]+HIR+"~"+NORM+": "+history[x+1]+"\n"); }
  write(HIR+" -(-=            "+HIW+"< > < > < > < >            "+HIR+"=-)-"+NORM+"\n");
  return 1; }

cmd_fwho() {
  int x;
  object *us;
  us = users();
  write(HIR+" -(-=           "+HIW+"FRIENDS OF FAKIR            "+HIR+"=-)-"+NORM+"\n");
  for(x = 0; x < sizeof(us); x++) 
    if(present("ftell",us[x])) write(us[x]->query_level()+"+"+us[x]->query_extra_level()+": "+us[x]->query_name()+"\n");
  write(HIR+" -(-=            "+HIW+"< > < > < > < >            "+HIR+"=-)-"+NORM+"\n");
  return 1; }

cmd_ft(str) {
  string msg;
  object fak;
  fak = find_player("fakir");
  if(!fak) {
    FAIL(HIR+"Fakir isn't logged on!\n"+NORM);
    return 0; }
  if(in_editor(fak)) {
    FAIL(HIR+"Fakir is editing ("+NORM+"LEAVE HIM ALONE!"+HIR+")\n"+NORM);
    return 0; }
  write(HIR+"~"+HIW+"^"+HIR+"~ You tell Fakir: "+NORM+str+"\n");
  msg = HIR+"~"+HIW+"^"+HIR+"~ "+TPN+" tells you: "+NORM+str;
  tell_object(fak,msg+"\n");
  present("ftell",fak)->add_history(CAP(TPRN),str);
  present("ftell",fak)->set_replyer(TPRN);
  return 1; }

cmd_reply(string blah) {
  object rep;
  if(!replyer) {
    FAIL(HIR+"No one to reply to!\n"+NORM);
    return 0; }
  rep = find_player(replyer);
  if(!rep) {
    FAIL(HIR+"No such player!\n"+NORM);
    return 0; }
  write(HIR+"You told "+CAP(replyer)+": "+NORM+blah+"\n");
  tell_object(rep,HIR+"Fakir tells you: "+NORM+blah+"\n");
  rep->add_tellhistory(HIR+"Fakir told you: "+NORM+blah+"\n");
  return 1; }

set_replyer(re) {
  replyer = re; }

cmd_fgive(str) {
  object ob;
  if(!str) {
    FAIL("Give a teller to who?\n");
    return 0; }
  ob = find_player(str);
  if(!ob) {
    FAIL("Not logged on!\n");
    return 0; }
  MOCO(PATH),ob);
  write(HIR+"You give a link to "+NORM+CAP(str)+HIR+".\n");
  return 1; }
