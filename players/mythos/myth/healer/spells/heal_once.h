heal_once(str) {
  if(!str) { write("qheal <name>\nNote: only once per person per boot\n");
             return 1; }
  if(member_array(HOB->query_oncelist(),str) == -1) {
             write("Only once per person per boot.\n");
  return 1; }
  if(!find_player(str)) {
    write("That person is not online.\n"); return 1; }
  if(find_player(str)->query_invis()) {
    write("That person is not online.\n"); return 1; }
  if(environment(find_player(str)) != etp) {
    write("That person is not present.\n"); return 1; }
  if(find_player(str)->query_level() > 19) {
     write("You cant heal wizes.\n"); return 1; }
  if(find_player(str)->query_ghost()) {
    write("You cant heal a ghost!\n"); return 1; } 
  find_player(str)->heal_self();
  tp->add_spell_point(-);
  HOB->add_oncelist(str);
  write("You have used the quick heal on "+str+"\n");
  say("\n");
return 1; }