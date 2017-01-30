/* combatob.c: combat object that other person carrys */
status loaded;
object targeted_by;
set_targeted_by(ob) { targeted_by = ob; }
init() {
  if(loaded)
    destruct(this_object());
  loaded = 1;
  add_action("end_game", "quit");
}
end_game() {
  if(targeted_by) {
    tell_object(targeted_by, this_player()->query_name()+" has left the game.\n");
    tell_object(targeted_by, "No conclusion recorded.\n");
    write("You no longer feel watched.\n");
  }
  destruct(this_object());
}
short() {
  if(this_player()->query_level() > 20)
    return "A combat recording object (INVIS) (DO NOT TOUCH)";
  return 0;
}
id(str) {
  return str == "liquid_combat_ob";
}
get() { return 1; }
/* another of my 'stroke of genius' ideas */
/* drop(1) is called by transfer_all_to(corpse) in living.c   */
/* hence, the following function is called when the player    */
/* dies. through sheer luck, it is called b4 attacker_ob is   */
/* cleared, which means i luck out bigtime. Unless, of course */
/* the system processes the other commands concurrently...    */
drop(arg) {
  object ob;
  if(environment(this_object())->query_ghost()) {
    ob = environment(this_object())->query_attack();
    if(!ob) return 1;
    if(present("metallic skin", ob)) {
      present("metallic skin", ob)->other_player_died(environment(this_object()));
      call_out("auto_dest", 5); /* this prevents a fuckup with move_object */
    }
  }
  return 1;
}
auto_dest() {
  destruct(this_object());
}