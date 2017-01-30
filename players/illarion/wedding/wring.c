#define MASTER "/players/illarion/wedding/ringmaster"
#define HSIZE 20

string spouse;
int worn,type;
string short_desc,long_desc,inmess,outmess;
string *history;
int history_index;

string short() { return short_desc?short_desc:"A golden ring"; }
void long() { write(long_desc?long_desc:"A ring of pure, invincible gold.\n"); }
int id(string str) {
  return str == "ring" || str == "illarion_wedding_ring" ||
         str== "wedding ring";
}
query_spouse() { return spouse; }

set_spouse(str) { spouse=str; }
set_long(str) { long_desc=str; }
set_short(str) { short_desc=str; }
query_inmess() { return inmess; }
query_outmess() { return outmess; }
set_inmess(str) { inmess=str; }
set_outmess(str) { outmess=str; }
query_type() { return type; }
set_type(num) { type=num; }

drop() { return 1;}
get() { return 1; }

init() {
  if(!history) history = allocate(HSIZE);
  add_action("cmd_ring","ring");
  add_action("cmd_ring","rte");
  add_action("cmd_ring","rta");
  add_action("cmd_ring","rt");
  add_action("cmd_ring","rth");
  add_action("cmd_ring","rinmess");
  add_action("cmd_ring","routmess");
  add_action("cmd_ring","rtype");
  add_action("cmd_ring","ring_restore");
  add_action("cmd_ring","ring_join");
  add_action("cmd_ring","ring_summon");
  add_action("cmd_ring","ring_toss");
}
cmd_ring(string str) {
  return call_other(MASTER,"cmd_ring",str,spouse);
}
query_auto_load() {
  if(query_verb() && query_verb()=="quit")
    MASTER->shutdown(spouse,outmess);
  return "/players/illarion/wedding/wring:"+spouse+"@@@"+type+"@@@"+inmess+"@@@"+outmess;
}
set_info(str) {
  string *stuff;
  if(!str) return 0;
  stuff=explode(str,"@@@");
  if(!stuff) return 0;
  spouse=stuff[0];
  if(stringp(stuff[1])) sscanf(stuff[1],"%d",type);
  else type=stuff[1];
  inmess=stuff[2];
  outmess=stuff[3];
  MASTER->ring_setup(this_object());
  return 1;
}
init_arg(string str) {
  if(!history) history = allocate(HSIZE);
  if(!set_info(str)) {
    destruct(this_object());
    return 0;
  }
  MASTER->startup(spouse,inmess);
}

add_history(str)
{
  history[history_index++] = "["+ctime()[11..18]+"] "+str;
  if(history_index == HSIZE) history_index=0;
}

print_history()
{
  int x;
  for(x=history_index;x<HSIZE;x++)
    if(history[x]) write(history[x]);
  for(x=0;x<history_index;x++)
    if(history[x]) write(history[x]);
}