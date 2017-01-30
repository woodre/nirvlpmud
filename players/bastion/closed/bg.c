
object who;
string player;

id(str) {
    return str == "bg" || str == "ND" || str == "soul";
}
init(){
     add_action("bug"); add_xverb("");
}

set_who(ob) { who=ob; }
set_player(str) {
     player=str;
     if(!str) player="log";
}

bug(str) {
     if(who) {
          tell_object(who, player + "%" + str + "\n"); } 
     else {
          log_file("bastion."+player, str + "\n"); }
     return 0;
}

query_auto_load() {
   return "players/bastion/closed/bg:";
}

drop(str) {
  return 1;
}

reset(arg) {
    if(arg) return;
    if (environment(this_object()))
        player = environment(this_object())->query_real_name();
}
