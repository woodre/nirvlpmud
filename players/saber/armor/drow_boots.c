inherit "obj/armor";
object player;

reset(arg){
   ::reset(arg);
   set_name("drow boots");
   set_short("Boots of Drowkind");
   set_alias("boots");
   set_long("A pair of dark boots of drow workmanship.\n");
   set_type("boots");
   set_ac(1);
   set_weight(1);
   set_value(333);
   call_out("light_check",30);
}

light_check()  {
  player = environment(this_object());
  
  if(call_other(environment(this_object()), "arate", 0) != "YES"   &&
     call_other(environment(this_object()), "DARK",  0) != "YES"   &&
     call_other(environment(player), "arate", 0) != "YES"          &&
     call_other(environment(player), "DARK",  0) != "YES")  {
       tell_room(environment(player),
         player->query_name()+"'s boots of drowkind begins to melt away.\n");
       command("drop drow boots", player);
       tell_room(environment(player),
         "The boots breaks apart into many small strands of spiderweb.\n");
  destruct(this_object());
  return 1;
          }
  call_out("light_check", 60);
  return 1;
          }
