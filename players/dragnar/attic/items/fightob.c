short() { return 0; }
int x;
object owner;
reset(arg) {
   if(arg) return;
   set_heart_beat(1);
   enable_commands();
   if(!arg) owner=0;
   x=0;
}
id(str) { return str=="fightob"; }
set_owner(ob) { owner=ob; }
init() {
   add_action("accept","accept");
   add_action("decline","decline");
}
heart_beat() {
   x=x+1;
   if( x > 5) {
      tell_object(environment(this_object()), "Time has run out to accept the fight.\n");
	destruct(this_object());
	return 1;
   }
   if(owner==0){
      destruct(this_object());
   }
}
accept(str) {
   if(str=="fight") {
      tell_object(owner, capitalize(this_player()->query_real_name())+" has accepted your fight!\n");
      write("You have accepted the fight!\n");
      move_object(this_player(), "players/dragnar/ARENA.c");
      move_object(owner, "players/dragnar/ARENA.c");
      destruct(this_object());
      return 1;
   }
}
decline(str) {
   if(str=="fight") {
      tell_object(owner, capitalize(this_player()->query_real_name())+" has declined your fight.\n");
      write("You have declined the fight.\n");
      destruct(this_object());
      return 1;
   }
}
get() { return 1; }
query_owner() { return owner; }
