#define eo environment(this_object())
id(str) { return str == "life"; }


short() { return "Undead Object- Obsolete"; }

drop() {
   if(environment(this_object())) 
   tell_object(environment(this_object()),
    "The Obsolete Undead Object disappears.\n");
  destruct(this_object());
return 1; }

reset(arg) {
  if(arg) return;
}

state() {
  if(environment(this_object())) {
   tell_object(environment(this_object()),
     "The Undead guild has been closed.\n"+
    "Your guild stats have been cleared.\n"+
    "                      - The Managment <8-25-1997>\n");
  eo->set_home("/room/church.c");
  eo->set_guild_name(0);
  eo->set_guild_rank(0);
  eo->add_exp(eo->query_guild_exp()/10);
  tell_object(eo,"You have recieved "+(eo->query_guild_exp()/10)+" in compensation.\n");
  eo->set_guild_exp(0);
  eo->set_guild_file(0);
  eo->add_guild_exp(-(eo->query_guild_exp()));
  eo->add_guild_rank(-(eo->query_guild_rank()));
  command("save",eo);
}
return 1; }

init() {
  destruct(this_object());
}
