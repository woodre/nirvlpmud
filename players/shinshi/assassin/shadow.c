
object player;
string name, cap_name, long_desc, short_desc;

format(str, i){ return str; }
id(str){
   if(this_player()->query_level() < 20) return str == lower_case(name);
   else
       return str == player->query_real_name() || str == lower_case(name);

}
short(){
   string v;
   int can_see;
   if(previous_object()->query_level() > 20) can_see = 1;
   if(can_see){
     return capitalize(name)+" <disguised player: "+player->query_name()+
          ">";
   }
   switch(query_verb()){
   case "look":
   case "l":
      return capitalize(name);
      break;
   case "who":
   case "people":
   case "p":
      return player->short();
      break;
   }
   if(member_array(previous_object(), users())) return capitalize(name);
   if(previous_object() == player) return player->short();
   else return capitalize(name);
}


shadow_player(frog){
   player = frog;
  shadow(player, 1);
  return 1;
}

stop_shadow(){
   shadow(this_object(), 0);
   destruct(this_object());
   return 1;
}
set_name(str){ name = str; cap_name = capitalize(name); }
set_cap_name(str){ cap_name = str; }
set_short(str){ short_desc = str; }
set_long(str){ long_desc = str; }
query_name(){ return capitalize(name); }
query_cap_name(){ return capitalize(name); }
query_invis(){ return player->query_invis(); }
query_level(){ return player->query_level(); }
query_age(){ return player->query_age(); }


long() {
	int hp, mhp;
	hp = player->query_hp();
	mhp = player->query_max_hp();
    write(short()+".\n");
	if (hp < mhp/10) {
    write(cap_name + " is in very bad shape.\n");
	return;
	}
	if (hp < mhp/5) {
    write(cap_name + " is in bad shape.\n");
	return;
	}
	if (hp < mhp/2) {
    write(cap_name + " is somewhat hurt.\n");
	return;
	}
	if (hp < mhp - 20) {
    write(cap_name + " is slightly hurt.\n");
	return;
	}
    write(cap_name + " is in good shape.\n");
}

move_player(str){
    int i;
   string dir,dest;
   player->set_invs_sp();
   if(sscanf(str, "%s#%s", dir, dest) != 2){
      tell_object(player, "Move to bad dir/dest.\n");
	  return;
   }
   say(cap_name + " leaves "+ dir + ".\n");
   player->move_player(str);
   /* This one is rewarded the Sleaze of the Year award.
    * Of course, decent mudlib support would make this unnecessary...
   */
   for(i=0; i <=12; i++) player->invs_counter();
   say(cap_name + " arrives.\n");
   return 1;
}

communicate(str){
	if (!str) {
    write("Say what?\n");
	return 1;
	}
	str = format(str,60);
	if (player->query_ghost()) {
    say(short() + " says: " + str + ".\n");
	if (player->query_brief())
        write("Ok.\n");
	else
        write("You say: " + str + "\n");
	return 1;
	}
    say(query_cap_name()+" says: "+str+"\n");
	if (player->query_brief())
    write("Ok.\n");
	else
    write("You say: " + str + "\n");
	return 1;
}
