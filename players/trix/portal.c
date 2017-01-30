inherit "obj/treasure";
init(){
   add_action("enter","enter");
}
reset(arg){
   if(arg) return;
   set_short("A glowing portal");
   set_id("portal");
   set_long("A portal has sprung up! You may enter it.\n");
   set_weight(1);
   set_value(10);
}
drop(){return 1;}
get(){return 0;}

enter(arg){
   object room;
   room = environment(this_object());
   if (!arg){
      write("Enter what?\n");
      return 1;
   }
   if (arg == "portal"){
      write("You step through the portal and emerge...\n");
tell_room("/players/ladyfinger/room/tower6/towera",capitalize(this_player()->query_name()) + " arrives through the portal.\n");
      move_object(this_player(),"/players/ladyfinger/room/tower6/towera");
      command("look",this_player());
tell_room(room,capitalize(this_player()->query_name()) + " enters the portal.\n");
      return 1;
   }
   return 1;
}
