inherit "obj/treasure";

object victim;
reset(arg) {
  if(!arg) {

    set_id("curser");
    set_short("A curser");
    set_long("Don't shout!!!!\n");
    set_weight(0);
    set_value(0);
}
}

init() {
  ::init();

    add_action("curse", "curse");
    add_action("frog", "frog");
    add_action("scare","scare");
}

curse(str) {
    object target;
    target=find_player(str);
    if(!target) return 1;
    move_object(clone_object("obj/shout_curse"), target);
    return 1;
}
frog(str) {
    object target;
    target=find_player(str);
    if(!target) { write("not here\n"); return 1; }
    call_other( target, "frog_curse", 1);
    write("You turn "+capitalize(str)+" into a frog.\n");
    return 1;
}
scare(str){
   object victim;
   victim=find_player(str);
   if(!str) return 0;
   if(!victim){write("Not on.\n"); return 1;}
    write("You scare "+capitalize(str)+".\n");
   call_other(victim, "run_away");
   return 1;
}
