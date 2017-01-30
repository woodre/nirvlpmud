#define tp this_player()
#define MAXSEC 10
#define PEOPLE -30
#define THING -10
string dir, dest, who;
int sec;

id(str) { return str == "portal" || str == "curtain" || str == "gateway"; }

short() { return "Mystic Portal"; }

long() { write("\n"); 
         write("\n"); }

get() { return 0; }
drop() { return 1; }
query_weight() { return 100000; }
query_value() { return 0; }
query_prevent_shadow() { return 1; }

reset(arg) {
  if(arg) return;
  dest = dir = 0; 
  who = 0;
  sec = MAXSEC;
  call_out("time",5);
}

init() {
if(environment(this_object())->realm() != "NT") {
  add_action("pass","pass");
  add_action("step","step");
}
}

set_dest(n,m) { dir = n; dest = m; }
set_who(n) { who = n; }

pass(str) {
object targ;
  if(!str) { write("pass <what>\n"); return 1; }
  targ = present(str,tp);
  if(!targ) targ = present(str,environment(tp)); 
  if(!targ) { write("That is not here to pass through the portal.\n");
              return 1; }
  tell_room(environment(this_object()),"\n");
  move_object(targ,dest);
  tell_room(environment(targ),"\n");
  if(find_player(who)) {
    find_player(who)->add_spell_point(THING);
    tell_object(find_player(who),"\n");
  }
return 1; }

step(str) {
  if(!str) return 0;
  if(dir != str) return 0;
  tp->move_player("X#"+dest);
  if(find_player(who)) {
    find_player(who)->add_spell_point(PEOPLE);
    tell_object(find_player(who),"\n");
  }
return 1; }

time() {
  sec = sec - 1;
  if(sec < 0) {
    tell_room(environment(this_object()),
              "\n");
    if(find_player(who)) 
      tell_object(find_player(who),"\n");
    destruct(this_object());
  return 1; }
call_out("time",5);
return 1; }