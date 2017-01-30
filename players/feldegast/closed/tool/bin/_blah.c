do_cmd(str) {
  object *list;
  int i, level, invis;
  string snooper;
  string name, ed, tab;
  list=users();
  write(pad("name",20)+pad("Level",7)+pad("Invis",8)+pad("Edit",8)+"\n");
  write("------------------------------------------------\n");
  for(i=0; i<sizeof(list); i++) {
    name=capitalize((string)list[i]->query_real_name());
    level=list[i]->query_level();
    invis=list[i]->query_invis();
    if(invis>999) { invis=999;}
    ed="  ";
    if(in_editor(list[i])) {
      ed="Ed";
    }
    if(list[i]->query_brief()) {
     write(name+"\n");
    }
  }
  return 1;
}
