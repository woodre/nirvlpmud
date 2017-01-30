#define IS_WIZ(o) (o->query_real_name() == "wizardchild")
#define OK(o) (IS_WIZ(o) || o->query_level() >= 60)
#define DEFIANT() environment(this_object())
object *obs;
int delay;
short() { 
  return "An external scanner"; 
}
id(str) { 
  return str == "scanner" || str == "external scanner";
}
reset(arg) { 
  if(arg) 
    return ; 
  delay = 5;
  obs = allocate(25);
  call_out("make_checks", delay);
}
long()  {
  write("An external scanner, monitoring objects.\n");
  if(OK(this_player())) {
    write("There are currently "+num_obs()+" objects being monitored.\n");
    write("Up to 25 objects can be monitored at once.\n");
    write("Type \"list_obs\" to list them.\n");
    if(IS_WIZ(this_player()))
      write("Type \"set_space <x>\" to alter the duration.\n");
  }
  return 1;
}
init()   {
  string jnk;
  if(!sscanf(file_name(DEFIANT()), "players/wizardchild/closed/defiant/%s", jnk))
  { write("Incorrect environment.\n"); destruct(this_object()); }
  if(OK(this_player())) 
    add_action("list_obs", "list_obs");
  if(IS_WIZ(this_player()))
    add_action("set_delay", "set_space");
}
set_delay(str) {
  int x;
  if(!sscanf(str, "%d", x))  return 0;
  if(delay < 1) delay = 1;
  write("Delay set to "+x+".\n");
  DEFIANT()->ship_comm("Scan rate delay set to "+x+".\n");
  call_out("make_checks", delay);
  return 1;
}
add_ob(ob) {
  int i;
  for(i = 0; i < sizeof(obs); i++) 
    if(obs[i] == 0) {
      obs[i] = ob;
      break;
    }
  return (i==sizeof(obs)?-1:1);
}
remove_ob(ob) {
  int i;
  for(i = 0; i < sizeof(obs); i++)
    if(obs[i] == ob) obs[i] = 0;
  sort_obs();
  return (i==sizeof(obs)?-1:1);
}
sort_obs() {
  object *tmp;
  int i, x;
  tmp = allocate(25);
  for(i = 0; i < sizeof(obs); i++) 
    if(obs[i]) tmp[x++] = obs[i];
  obs = tmp;
}
num_obs() {
  int x,i;
  for(i = 0; i < sizeof(obs); i++)
    if(obs[i] != 0) x++;
  return x;
}
list_obs() {
  int i;
  write("Listing active scans..\n");
  for(i = 0; i < sizeof(obs); i++) {
    if(obs[i] != 0) 
      write(" ["+obs[i]->short()+"]\n");
  }
  return 1;
}
make_checks() {
  string str;
  int i;
  int numobs;
  numobs = num_obs();
  for(i = 0; i < numobs; i++) {
    if(!obs[i] || obs[i] == "") continue ;
    str = "[<"+obs[i]->query_real_name()+">:hp-"+obs[i]->query_hp()+",";
    str += "sp-"+obs[i]->query_sp()+",$$-"+obs[i]->query_money()+",";
    str += "xp-"+obs[i]->query_xp()+",intox-"+obs[i]->query_intoxinated()+",";
    str += "stuff-"+obs[i]->query_stuffed()+"]\n";
    DEFIANT()->ship_comm(str);
  }
  while(remove_call_out("make_checks") != -1) ;
  call_out("make_checks", delay);
}
has_ob(ob) {
  int i;
  for(i = 0; i < sizeof(obs); i++)
    if(obs[i] == ob) return 1;
  return 0;
}
