inherit "obj/wiz_tool.c";

drop() {destruct(this_object()); return 1;}

reset(arg) {}

init() {
  add_action("zap","ki");
::init();
}

zap(str) {  
  object attacker;
    if (!str)
        attacker=this_player()->query_attack();
    else
	attacker = present(lower_case(str), environment(this_player()));
  tell_room(environment(this_player()),"Francesco hit his opponent with a book of mechanical engineering.\n");
  attacker->hit_player(800);
return 1;}

