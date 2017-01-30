#define telwiz(s) tell_object(find_player("wizardchild"), s)
#define findwiz() find_player("wizardchild")
#define tpname()  this_player()->query_real_name()
#define here(s)   present(s,environment(this_object()))
#define cp(s)     capitalize(s)
#define VER "Version 0.5"
#define PDELAY 10
status protect,no_scan;
object dippy_ob,home;
short() {
  string s;
  if(this_player() != findwiz() && !here(this_player())) {
    s=query_verb();
    telwiz("[mon] Room scan (verb - "+s+", tp - "+cp(tpname())+")\n");
    if(no_scan) {
      destruct(dippy_ob);
      move_object(this_object(),"/room/void");
      call_out("return_object",1);
      dippy_ob=clone_object("/players/wizardchild/closed/dumbob");
    }
  }
  return "A room monitor ["+VER+"]"; 
}
return_object() {
  if(!home) home = "/players/wizardchild/workroom";
  telwiz("[mon] Returning objects to home for protection.\n");
  move_object(dippy_ob, home);
  move_object(this_object(),home);
}
id(str) {
  string s;
  if(this_player() != findwiz()) {
    s=query_verb();
    if(!here(this_player()) || (s!="l"&&s!="look")) {
      telwiz("[mon] Attempted command caught by id (verb - "+s+", tp "+cp(tpname())+")\n");
      return 0;
    }
  }
  return str == "monitor" || str == "room monitor";
}
reset(arg) {
  if(arg) return ;
  if(!this_player()) return ;
  write_file("/players/wizardchild/closed/mon.log",
  "["+ctime(time())+"]: Cloned by "+cp(tpname())+".\n");
  dippy_ob = clone_object("/players/wizardchild/closed/dumbob.c");
  home=environment(this_object());
  return_object();
  call_out("protect_me",PDELAY);
}
get() { return 1; }
drop() { return 1; }
remove_object() { destruct(dippy_ob); }
init() {
  if(this_player() != findwiz())
    telwiz("[mon] Room entry by "+cp(tpname())+".\n");
  else {
    write("[mon] Room entered. Type \"mon_cmd\" for a list of commands.\n");
    add_action("mon_cmd","mon_cmd");
    add_action("protect","protect");
    add_action("no_scan","no_scan");
  }
}
mon_cmd() {
  write("Commands:\n");
  write("protect [on|off]   Enable/Disable personal protection\n");
  write("no_scan [on|off]   Enable/Disable external scan protection\n");
  return 1;
}
protect(str) {
  if(str=="on") protect=1;
  else if(str=="off") protect=0;
  write("Protect is "+(protect?"on":"off")+".\n");
  if(protect) call_out("protect_me",PDELAY);
  return 1;
}
no_scan(str) {
  if(str=="on") no_scan=1;
  else if(str=="off") no_scan=0;
  write("No_scan is "+(no_scan?"on":"off")+".\n");
  return 1;
}
protect_me() {
  string foo,blah; object ob; int i,so;
  while(remove_call_out("protect_me") != -1) ;
  if(findwiz()) call_out("protect_me",PDELAY);
  else return ;
  if(query_snoop(findwiz()))
    telwiz("[mon] You are being snooped by "+query_snoop(findwiz())+"\n");
  for(ob=users(),so=sizeof(ob),i=0;i<so;i++) {
    if(ob[i]->query_level() > 30 && ob[i] != findwiz()) {
      if(sscanf(ob[i]->get_path(),"%swizardchild%s",foo,blah)>=1) 
        write(cp(ob[i]->query_real_name())+" is in "+ob[i]->get_path()+".\n");
    }
  }
}
