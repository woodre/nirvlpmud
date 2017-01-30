inherit "obj/armor";
object player;

reset(arg){
   ::reset(arg);
   set_name("drow cloak");
   set_short("An inky black cloak");
   set_alias("cloak");
   set_long("An inky black cloak of drow workmanship.\n"+
            "Wearing it, you almost feel invisible.\n");
   set_type("misc");
   set_ac(1);
   set_weight(1);
   set_value(334);
   call_out("light_check",30);
}

light_check()  {
  player = environment(this_object());
  
  if(call_other(environment(this_object()), "arate", 0) != "YES"   &&
     call_other(environment(this_object()), "DARK",  0) != "YES"   &&
     call_other(environment(player), "arate", 0) != "YES"          &&
     call_other(environment(player), "DARK",  0) != "YES")  {
       tell_room(environment(player),
         player->query_name()+"'s inky black cloak begins to melt away.\n");
       command("drop drow cloak", player);
       tell_room(environment(player),
         "The cloak breaks apart into many small strands of spiderweb.\n");
  destruct(this_object());
  return 1;
          }
  call_out("light_check", 60);
  return 1;
          }
