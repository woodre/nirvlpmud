inherit "obj/treasure";

reset(arg) {
   if(!arg) {
      
      set_id("terminal");
      set_short("A WYSE-185 vt100 terminal");
      set_long("This is a WYSE-185 vt100 terminal.  If you are logged on\n"+
         "you may want to log yourself off.  To do so, type 'lo'.\n");
      set_alias("terminal");
      set_weight(100);
      set_value(1);
      return 1;
   }
}
init() {
   ::init() ;
   
   add_action("lo","lo");
}

lo() {
   write("You have just logged Roomstalker off.\n");
   write("You have a very strange feeling.\n"+
         "You feal as if you have entered space.\n"+
         "You have just entered virtual reality.\n");
    move_object(this_player(), "players/lew/elof/vir_wrld1");
    write(call_other(this_player(), "look")+"\n");
   say(capitalize(this_player()->query_real_name())+" loggs off Roomstalker.\n");
   return 1;
}

take() { write("It is attached to the table with a cable.\n"+
               "Just log him out.\n"); return 1;
}
