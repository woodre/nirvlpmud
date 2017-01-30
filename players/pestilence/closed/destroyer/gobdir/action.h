#define CMD_DIR "/players/pestilence/closed/destroyer/cmds/"
#define ATT USER->query_attack()
/* repeat, ld dont like -Bp
static string *cmds;
*/
int here;

save_me(object ob) {
  string file;
  int tellme;
  if(ob) tellme++;
  if(!ob) ob = ENV();
  file = "players/pestilence/closed/destroyer/members/" + ob->query_real_name();
  if(!save_object(file)) {
    if(tellme) tell_object(ob,"Save error...\n");
    return 0;
    }
  if(tellme) tell_object(ob,"Saving Destroyer...\n");
  write(""+YEL+"Saving "+HIW+">"+HIR+"A"+HIW+"."+HIR+"o"+HIW+"."+HIR+"P"+HIW+"<"+NORM+"...\n");
  return 1;

}

add_cmds() 
  {
   int x; string cmd;
   cmds = get_dir(CMD_DIR);
   for(x=0;x<sizeof(cmds);x++)
#ifdef __LDMUD__ /* Rumplemintz */
  {
    if (sscanf(cmds[x], "%s.c", cmd))
      add_action("cmd_hook", cmd, 3);
  }
  add_action("cmd_emote", ":", 3);
#else
   if(sscanf(cmds[x],"%s.c",cmd)) 
     {
     if(cmd == "\"") 
       { 
       add_action("cmd_hook"); add_xverb(cmd); 
       }
     else if(cmd == "'") 
       { 
       add_action("cmd_hook"); add_xverb(cmd); 
       }
     else add_action("cmd_hook",cmd); 
     }
   add_action("cmd_emote"); add_xverb(":");
#endif
  }

cmd_hook(str) 
  {
  string verb;
  verb = query_verb();
  /* sloppy communication bug fix */
  if(verb == "'") 
   { 
    call_other(CMD_DIR+"say.c","main",str); 
      return 1; 
    }
  if(call_other(CMD_DIR+verb+".c","main",str)) 
    return 1; 
  }

cmd_emote(str)
  {
  if(!str) return;
  write("You "+str+"\n");
  TP->remote_say(capitalize(TPRN)+" "+str+"\n");
    return 1;
  }

