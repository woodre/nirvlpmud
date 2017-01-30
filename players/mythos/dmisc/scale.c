inherit "obj/treasure";
reset(arg) {
  if(arg) return;
    set_id("scale");
    set_short("A SandLizard's Scale");
    set_long("The mythical scale of a SandLizard.\n"+
             "With it a SandLizard may be summoned to help.\n"+
             "During battle 'pass hand over scale'\n");
    set_weight(1);
    set_value(1000);
}

init() { ::init(); add_action("pass","pass"); }

pass(str) {
object ob;
  if(str == "hand over scale") {
  if(!this_player()->query_attack()) { write("You are not in combat!\n"); return 1; }
    if((this_player()->query_attack())->is_player()) {
      write("You may not call forth a SandLizard against players!\n");
    return 1; }
    ob = clone_object("/players/mythos/dmon/sandlizard.c");
    ob->set_aggressive(0);
    move_object(ob,environment(this_player()));
    tell_room(environment(this_player()),
    "There is a whirl of sand and a SandLizard races out from the ground!\n");
    ob->attack_object(this_player()->query_attack());
    write("The scale disappears.\n");
    move_object(this_object(),ob);
    call_out("checker",1);
  return 1; }
}

checker() { 
if(!environment(this_object())) { destruct(this_object()); return 1; }
if(!living(environment(this_object()))) { destruct(this_object()); return 1; }
  if(!environment(this_object())->query_attack()) {
    environment(this_object())->zap_object(environment(this_object()));
    destruct(this_object());
    return 1; }
call_out("checker",5);
return 1; }
