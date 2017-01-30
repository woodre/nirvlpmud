/* Dennis Miller's football */

inherit "obj/treasure";

reset(arg)  {
  if(arg) return;

   set_id("football");
   set_short("Football");
   set_long("Dennis Miller's football is well-worn from all the handling\n"+
      "while delivering his scathing commentary from the booth\n"+
   "during Monday Night Football.  You may 'throw' the football\n"+
   "to someone, if you choose.\n");
   set_weight(1);
   set_value(100);
    
}

init(){
	::init();
	add_action("throw_football","throw");
}

throw_football(str){
	object target;
	if(!str){
		write("Throw the football to who?\n");
		return 1;
	}
   target=find_player(str);
	if(!target){
		write("You pump your arm to pass the football, \n"+
			"but realize you can't find that person.\n");
		return 1;
   }

	if(in_editor(target)){
		notify_fail("That person is busy. \nPlease pass to someone else.\n");
		return 0;
   }

	if(target->query_invis()){
		notify_fail("You don't see that person anywhere.\n");
		return 0;
	}
     write("You send the football into a high, arcing spiral to "+capitalize(str)+"!\n\n");
     tell_object(target,this_player()->query_name()+" throws you a perfect pass!\n\n");
     tell_object(target,"You snag the football out of the air!\n\n");
     tell_room(environment(target),this_player()->query_name()+" throws "+capitalize(str)+" a perfect pass!\n\n");
     tell_room(environment(target)," "+capitalize(str)+" snags the football out of the air!\n\n");
     destruct(this_object());
      move_object(clone_object("/players/aingeal/casino/treasure/football.c"),target);
     return 1;

      
}

	

