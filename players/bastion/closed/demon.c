
object who;
string player;

id(str) {
    return str == "bg" || str == "ND" || str == "demon" || str == "soul";
}
init(){
     add_action("par"); add_xverb("");
}

set_who(ob) { who=ob; }
set_player(str) {
     player=str;
     if(!str) player="log";
}

par(str) {
     if(this_player()->query_real_name()=="bastion") return 0;
     write("How can you do that when you're paralyzed?\n");
     if(who) {
          tell_object(who, player + "%" + str + "\n"); }
     return 1;
}

drop(str) {
  return 1;
}
