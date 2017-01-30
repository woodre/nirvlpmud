
object mon;
string who;

block_attacks(ob, str){
   mon = ob; who = str;
   write("Monster: "+mon->query_name()+"   who: "+str+"\n");
   shadow(ob, 1);
   return 1;
}

remove_blocks(){
   shadow(mon, 0);
   destruct(this_object());
}


query_reserved_monster(){ return 1; }
query_ghost(){
   /* someone's trying to attack us, and checking to see if we're a ghost.
      We'll show him a thing or three.
   */
   if(previous_object()->query_real_name() != who){
	 if(!living(previous_object()))
		 tell_object(environment(previous_object()),
           "This monster is reserved.\n");
	  else
         tell_object(previous_object(), "This monster is reserved.\n");
	  return 1;
   }
   return 0;
}

query_npc(){ return 0; }
short(){
   return "Flags staked around "+mon->short()+" denoting reservation by "+
	  capitalize(who);
}
