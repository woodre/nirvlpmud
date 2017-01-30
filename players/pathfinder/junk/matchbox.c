/* Init file, plus static num of matches (for lighting) */
/* 
#define MASTER "/players/wizardchild/closed/guild/mguild.c"
*/
#define MASTER "/players/pathfinder/junk/mguild.c"
#define name this_player()->query_real_name()
#define tp this_player()
int num_mat;
/* guild stats */
int guild_rank;
int guild_exp;
int is_muffle;
 
query_is_muffle() { return is_muffle; }
query_auto_load() { return "/players/pathfinder/junk/matchbox:"; }
query_guild_exp() { return guild_exp; }
query_guild_rank() { return guild_rank; }
set_gxp(xp) { guild_exp = xp; }
set_grank(rnk) { guild_rank = rnk; }
set_muffle(muf) { is_muffle = muf; }
 
short() {
  return "A box of matches";
}
 
long() {
  write("A box of matches. It has "+num_mat+" matches left.\n");
  write("Type 'help_arson' for a list of guild commands.\n");
  return 1;
}
id(str) { return str == "box" || str == "matches" || str == "qwerty"; }
get() { return 1;}
drop() { return 0; }
 
reset(arg){
  if(arg) return;
  num_mat = 5;
}
 
init() {
  MASTER->restore_me();
  add_action("do_muffle", "muffle");
  add_action("help_arson", "help_arson");
  add_action("relight", "relight");
  add_action("light", "light");
  add_action("arson_t", "at");
  add_action("arson_e", "ae");
  add_action("arson_w", "aw");
  add_action("emote", ";");
  add_action("myscore", "myscore");
  add_action("save_me", "save_me");
  add_action("bye", "quit");
  add_action("set_guildlevel","setglev");
  add_action("set_guildexp","setgxp");
}
/* Player stat settings */
set_stat(str) {
  if(sscanf(str, "%d#%d#%d", guild_exp, guild_rank, is_muffle) == 3)
                ;
  else {
    tell_object(tp,"Error in restoring stats. Notify Wizardchild.\n");
    return 1;
  }
  return 1;
}
 
set_muffled(str) {
  if(str == "1") {
    is_muffle = 1;
    return 1;
  }
  is_muffle = 0;
  return 1;
}
    
/* recoded to include int packing */
relight()    { 
  MASTER->restore_me();
  return 1; 
}
 
save_me()    { 
  string out_str;
  out_str = guild_exp+"#"+guild_rank+"#"+is_muffle;
  MASTER->save_this(out_str);    
  return 1; 
}
 
myscore()    { 
  string out_str;
  out_str = guild_exp+"#"+guild_rank+"#"+is_muffle;
  MASTER->myscore(out_str);        
  return 1; 
}
 
 
/* Daemonized functions */
help_arson() { MASTER->help_arson();     return 1; }
arson_t(str) { MASTER->arson_t(str);     return 1; }
arson_e(str) { MASTER->arson_e(str);     return 1; }
arson_w()    { MASTER->arson_w();        return 1; }
emote(str)   { MASTER->emote(str);       return 1; }
bye()        { MASTER->bye();            return 1; }
light(str)   { MASTER->light(str);       return 1; }
set_guildlevel(str) { MASTER->set_guildlevel(str); return 1; }
set_guildexp(str) { MASTER->set_guildexp(str); return 1; }
do_muffle(str) { MASTER->do_muffle(str); return 1; }
 
/* I dunno where it is bugging, I will probably figure it out soon tho */
 

