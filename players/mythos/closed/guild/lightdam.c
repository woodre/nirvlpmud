#define io  this_object()->short()
#define ao  this_object()->query_alias()
#define tp  this_player()->query_name()
#define eo  environment(this_object())
string owner;
int is_light, k;
int lightcheck;
string cname;

id(str) { return str == "lightdam" || str == cname; }

set_owner(str) { owner = str;}
query_owner() { return owner;}
query_light() { return lightcheck; }		
set_cname(str) { cname = str; }
query_save_flag() { return 1;}
get() {return 0; }

reset(arg) {
  if(arg) return;
  is_light = k = 0;
  lightcheck = 0;
  call_out("checker",3);
}

checker() {
if(!present("dester",this_object())) {
move_object(clone_object("/players/mythos/closed/guild/dest.c"),this_object());
  }
  if(!present(owner,eo)) {
  k = k + 1;
  if(!find_player(owner) || k > 1) {
  destruct(this_object());
  return 1;}
  move_object(this_object(),environment(find_player(owner)));
  k = 0;
  }
  is_light = set_light(0);
  if(present("weather",environment(this_object()))) { is_light =  0; }
  if(present("dark_cloak",find_player(owner))) { is_light = -1; }
  if(present("myst",environment(this_object()))) { is_light = is_light - 1; }
  if(present("darkness",environment(this_object()))) { is_light = is_light - 2; }
  if(present("mailread",tp)) { is_light = 0; }
  lightcheck = is_light;
  if(find_player(owner)->query_interactive() &&
    !find_player(owner)->query_ghost()) {
  find_player(owner)->heal_self(-(is_light)); 
  if(is_light > 1) { tell_object(find_player(owner),
                   "You feel great pain as light burns into you!\n");}
  if(is_light < -2 && find_player(owner)->query_hp() < find_player(owner)->query_mhp() ) {
  tell_object(find_player(owner),
                   "You feel a cool touch as the darkness heals you.\n"); }
  }
  is_light=0;
  call_out("checker",3); 
  return 1;}
  
query_shatter_proof() { return 1;}
