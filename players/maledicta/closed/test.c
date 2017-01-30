/*
* Fakir's Wiztool
* by Vert@Nirvana
* revised 8.2000 [facelift and slew of new cmds]
   *                [added wiztell cmds]
*/

#include "/players/vertebraker/define.h"
#define JUNK "/players/fakir/jdkjglkjg"
inherit "/obj/wiz_tool.c";
object replyer;

id(str) { return str == "whirlwind" || str == "tool" || str == "wiztool" || str == "ftell"; }
short() { return "A portable "+YEL+"WhirlWind"+NORM; }
init() {
   ::init();
   add_action("cmd_fgive","fgive");
   add_action("cmd_tellh","tellh");
   add_action("cmd_force","force");
   add_action("cmd_view","view");
   add_action("cmd_exec","exec");
   add_action("cmd_upload","upload");
   add_action("cmd_fin","fin");
   add_action("cmd_atell","atell");
   add_action("cmd_say","say");
#ifndef __LDMUD__
   add_action("cmd_say"); add_xverb("'");
   add_action("cmd_say"); add_xverb("\"");
#else
   add_action("cmd_say", "'", 3);
   add_action("cmd_say", "\"", 3);
#endif
   add_action("cmd_reply","reply");
   add_action("cmd_tell","tell");
}

long() {
   ::long();
   write(HIR+"\nvert cmds --\n"+NORM+
      "force <name> <what>         forces name to do what\n"+
      "tellh <name>                reads name's tellhistory\n"+
      "view  <name> [a/h]          views name's aliases or cmd history\n"+
      "exec  <line>                runs a line of code\n"+
      "upload <file>               loads/updates a file\n"+
      "fin   <name>                mythos's finger tool cmd\n"+
      "atell <what>                arrina's special tell cmd\n"+
      HIR+"Wiztell cmds:"+NORM+" say, tell, fgive, reply.\n"+
      "written by: [who's ya daddy] -> verte.\n");
}

cmd_force(str) {
   string who,what;
   object ob;
   if(!str || (sscanf(str,"%s %s",who,what) != 2)) {
      FAIL("Force who to do what?\n");
      return 0; }
   ob = find_player(who);
   if(!ob) {
      FAIL("Player not logged on!\n");
      return 0; }
   write("You force "+CAP(who)+" to: "+what+"\n");
   tell_object(ob,HIR+"The Sands command you to:\n\t'"+NORM+what+HIR+"'\n"+NORM);
   command(what,ob);
   return 1; }

cmd_tellh(str) {
   object ob;
   if(!str) {
      FAIL("Read who's tellhistory?!\n");
      return 0; }
   ob = find_player(str);
   if(!ob) {
      FAIL(CAP(str)+" isn't logged on!\n");
      return 0; }
   write(HIR+"        "+CAP(str)+"'s TellHistory\n"+NORM);
   write(HIR+" - - --- -- -------- - -- - - ------ -------- -  -\n"+NORM);
   ob->write_tellhistory();
   return 1; }

cmd_view(str) {
   string who, arg; object ob;
   if(!str || !sscanf(str,"%s %s",who,arg)) {
      FAIL("Syntax: 'view <who> [a/h]'\n");
      return 0; }
   ob = find_player(who);
   if(!ob) {
      FAIL(CAP(str)+" isn't logged on!\n");
      return 0; }
   if(!present("qt",ob)) {
      FAIL("Player doesn't have a quicktyper!\n");
      return 0; }
   ob = present("qt",ob);
   if(arg == "a") {
      ob->alias(); }
   else if(arg == "h") {
      ob->history(); }
   else write("Syntax: 'view <who> [a/h]'\n");
   return 1; }

cmd_fgive(str) {
   object ob;
   if(!str) {
      FAIL("Give a teller to who?\n");
      return 0; }
   ob = find_player(str);
   if(!ob) {
      FAIL("Not logged on!\n");
      return 0; }
   MO(CO("/players/fakir/closed/ftell"),ob);
   write(HIR+"You give a link to "+NORM+CAP(str)+HIR+".\n");
   return 1; }

cmd_upload(str) {
   command("load "+str,TP);
   command("update "+str,TP);
   return 1; }

cmd_fin(str) {
   object fin;
   fin = CO("/players/mythos/closed/play/finger.c");
   MO(fin,TP);
   command("fin "+str,TP);
   destruct(fin);
   return 1; }

cmd_atell(str) {
   object atell;
   atell = CO("/players/arrina/closed/atell.c");
   MO(atell,TP);
   command("atell "+str,TP);
   destruct(atell);
   return 1; }

cmd_reply(str) {
   if(!replyer) {
      FAIL(HIR+"You have no one to reply to!\n"+NORM);
      return 0; }
   if(!ENV(replyer)) {
      FAIL(HIR+"They have logged off!\n"+NORM);
      return 0; }
   command("tell "+replyer->RN+" "+str,TP);
   return 1; }

cmd_say(str) {
   if(!str) {
      write("Say what?\n");
      return 1; }
   write(HIR+"You say: "+NORM+str+"\n");
   say(HIR+TPN+" says: "+NORM+str+"\n");
   return 1; }

cmd_exec(str) {
   if(!str) {
      FAIL("You must supply some code.\n");
      return 0; }
   write_file(JUNK,"#include \"/players/vertebraker/define.h\"\n"+
      "execute_file() {\n"+
      str+"\n"+
      " return 1; }\n");
   JUNK->execute_file();
   destruct(JUNK);
   rm(JUNK);
   return 1; }

cmd_tell(str) {
   string what;
   object ob;
   if(!str || sscanf(str,"%s %s",str,what) < 2) {
      FAIL("Tell who what?\n");
      return 0; }
   ob = find_player(str);
   if(!ob) {
      FAIL("Player not logged on!\n");
      return 0; }
   write(HIR+"You tell "+CAP(str)+": "+NORM+what+"\n");
   tell_object(ob,HIR+CAP(TPRN)+" tells you: "+NORM+what+"\n");
   ob->add_tellhistory(HIR+CAP(TPRN)+" told you: "+NORM+what);
   return 1; }

set_replyer(object ob) { replyer = ob; }
