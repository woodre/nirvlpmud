inherit "obj/corpse";
object peach;
reset(arg){
set_name("Robert Frost");


       peach=clone_object("players/airwoman/food/peach");
	move_object(peach, this_object());
}

get() {
   return 0;
}
