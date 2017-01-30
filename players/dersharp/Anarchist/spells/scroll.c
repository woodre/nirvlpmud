inherit "obj/treasure";
id(str) { return str == "scroll";}
#define Tpn		capitalize(this_player()->query_real_name())
reset(arg){
   if(arg) return;
   set_short("A scroll");
   set_long("A scroll of blindness\n");
   set_weight(1);
   set_value(0);
}
init() {
   add_action("Blindthem","blind");
}
Blindthem(arg){
   object ob;
   object blinder;
   if(!arg) {
      write("Usage: blind opponent.\n");
      return 1;
   }
   ob = find_player(arg);
   if(!ob){
      write("Not around the mudd right now!\n");
      return 1;
   }
   if(!present(ob, environment(this_player()))) {
      write("You must be in the same room as "+capitalize(ob->query_real_name())+".\n");
      return 1;
   }
   this_player()->add_apell_points(-20);
   blinder = clone_object("/players/dersharp/Anarchist/spells/blinder.c");
   tell_object(ob, "You have been struck blind by "+Tpn+"\n");
   move_object(blinder,ob);
   return 1;
}
