/* stun object.  blocks auto attacks and commands until time
   expires */
   
 id(str) { 
  if(str=="belle morte stun") return 1; 
  if(str=="block_attack_object") {
    if(environment())
      tell_object(environment(), "You are paralyzed by fear and desire!\n");
    return 1;
  }  
 }
 
 init()
 {
#ifndef __LDMUD__
	add_action("cmd_hook"); add_xverb("");
#else
	add_action("cmd_hook", "", 3);
#endif
 }

 cmd_hook()
 {
	write("You are paralyzed by fear and desire!\n");
	return 1;
}

inflict_stun(victim, duration) {
	object existing_stun;
	if(!victim || duration < 0)
		return;
	existing_stun = present("belle morte stun", victim);
	if(existing_stun)
	{
		existing_stun->change_duration(duration);
		return;
	}
	move_object(this_object(), victim);
	call_out("remove_stun", duration);
}

change_duration(duration) {
	remove_call_out("remove_stun");
	call_out("remove_stun", duration);
}

remove_stun()
{
  if(environment()) tell_object(environment(), "\n\nYou are no longer paralyzed.\n\n\n");
    destruct(this_object());
}
