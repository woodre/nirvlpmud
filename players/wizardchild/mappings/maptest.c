inherit "/players/wizardchild/mappings/mapping.c";
#define SAVE "players/wizardchild/mapping"
mapping map;
string save_map;
reset(arg) {
  if(arg) return ;
  map = (["test1":1,"test2":2,"test3":3]);
}
short() { return "A mapping tester"; } 
id(str) { return str == "test" || str == "mapping tester"; }
long() { 
  write("Type \"save_map\" or \"restore_map\" to test.\n"); 
  write("Type \"element <word>\" to test mapping.\n");
}
init() { 
  add_action("save_map","save_map"); 
  add_action("restore_map","restore_map");
  add_action("element","element");
}
save_map() {
  save_map = store_mapping(map);
  save_object(SAVE);
  save_map = 0;
  write("Ok.\n");
  return 1;
}
restore_map() {
  map = ([]); /* zero out */
  restore_object(SAVE);
  map = extract_mapping(save_map);
  save_map = 0;
  write("Ok.\n");
  return 1;
}
element(str) {
    write(map[str]+"\n");
  return 1;
}
