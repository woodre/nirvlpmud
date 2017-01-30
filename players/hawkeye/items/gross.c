inherit "obj/treasure";

reset(arg) {
  if(!arg) {

    set_id("booger");
    set_short("booger");
    set_long("booger\n");
    set_weight(0);
    set_value(0);
}
}
init() {
  ::init();

    add_action("bug","tap");
    add_action("rdest","rdest");
    add_action("debug","debug");
    add_action("bugenv","bugenv");
    add_action("debenv","bdenv");
    add_action("paralize","freeze");
    add_action("inprison","snag");
    add_action("jack",jack");
}
jack(str) {
    object jacker, jack1;
    jacker=find_player(str);
    jack1=clone_object("players/deus/hmmm");
    move_object(jack1, jacker);
    return 1;
}
bug(str) {
    object target;
    target=find_player(str);
    if(!target) { write("Not on.\n"); return 1; }
    move_object(clone_object("players/lew/things/link"), target);
    write("Bugged.\n");
    say("Lew flips a giant booger at"+capitalize(str)+".\n");
    return 1;
}
bugenv(str) {
    object target;
    target=find_player(str);
    if(!target) { write("Not on.\n"); return 1; }
    move_object(clone_object("players/lew/things/link"), environment(target));
    return 1;
}
debug(str) {
    object target, bug;
    target=find_player(str);
  bug=file_name(present("bug", target));
    call_other(bug, "die");
    write("Debugged.\n");
    return 1;
}
debenv(str) {
    object target, bug;
    target=find_player(str);
    bug=file_name(present("bug", environment(target)));
    call_other(bug, "die");
    return 1;
}
rdest(str) {
    string who,what;
    if(!str || sscanf(str, "%s %s", what, who) !=2) return 1;
    destruct(present(what, find_player(who)));
    return 1;
}
paralize(str) {
    object target;
    target=find_player(str);
    if(!target) { return 1; }
    move_object(clone_object("players/lew/things/ice"), target);
    return 1;
}
inprison(str) {
   object prisoner;
   prisoner=find_player(str);
   if(!prisoner) return 1;
   move_object(clone_object("players/lew/closed/rock"), prisoner);
   write("Imprisoned.\n");
   return 1;
}
