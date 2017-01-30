#define TP this_player()
#define TPN TP->query_real_name()

object projection;

id(str){ return str=="astral_ob"; }
short(){ return 0; }

reset(arg) {
     if(arg) return;
}
init() {
  if(TP->query_level()<20) destruct(this_object());
  add_action("aquit","aquit");
  add_action("agoto","agoto");
  add_action("ainvis","ainvis");
  add_action("asnoop","asnoop");
  add_action("afollow","afollow");
  add_action("afile","afile");
  add_action("amuffle","amuffle");
  add_action("asay","asay");
  add_action("aemote","aemote");
  add_action("acom","acom");
  add_action("alook","alook");
  add_action("abrief","abrief");
  if(!projection) {
    projection=clone_object("/players/languilen/tools/projection.c");
    projection->set_owner(TPN);
    move_object(projection,environment(TP));
  }
}
alook(){
     projection->ast_look();
     return 1;
}
abrief(){
     projection->set_brief();
     return 1;
}

agoto(str) {
  object target;
  target=find_living(str);
  if(target) {
    move_object(projection,environment(target));
    write("You send your astral body to watch "+capitalize(str)+"'s room.\n");
    return 1;
  }
  write("Usage: agoto <living>\n");
  return 1;
}
ainvis() {
  if(!projection) {
    write("Something has happened to your astral body.\n");
    return 1;
  }
  projection->go_invis();
  write("You cast a spell of invisibility on your astral body.\n");
  return 1;
}
aquit() {
  write("You dismiss your astral self.\n");
  if(projection) destruct(projection);
  destruct(this_object());
  return 1;
}
asay(str) {
  object room;
  room=environment(projection);
  if(!room) {
    write("No environment for projection.\n");
    return 1;
  }
  if(projection->query_invis()){
     tell_room(room,"An astral body says: "+str+"\n");
     return 1;
  }
  tell_room(room,TPN+"'s astral body says: "+str+"\n");
  return 1;
}
aemote(str) {
  object room;
  room=environment(projection);
  if(!room) {
    write("projection has no environment!\n");
    return 1;
  }
  if(projection->query_invis()){
     tell_room(room,"An astral body "+str+"\n");
     return 1;
  }
  tell_room(room,TPN+"'s astral body "+str+"\n");
  return 1;
}
asnoop() {
  projection->set_snooping();
  write("You toggle the projection's snooping ability(Nosy!).\n");
  return 1;
}
afollow(str) {
  object target;
  if(!str){
     target=0;
     projection->set_follow(target);
     write("Your astral self stops following.\n");
     return 1;
  }
  target=find_living(str);
  if(!target) {
    write("That living does not exist.\n");
    return 1;
  }
  projection->set_follow(target);
  write("You send your astral body to follow "+target->query_name()+".\n");
  return 1;
}
afile(str) {
  projection->set_file(str);
  write("You set the projection's log file to "+str+".\n");
  return 1;
}
amuffle() {
  projection->set_muffle();
  return 1;
}
acom(str) {
  write("You command your astral body to '"+str+"'.\n");
  command(str,projection);
  return 1;
}
