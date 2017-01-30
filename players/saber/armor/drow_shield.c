inherit "obj/armor";
object player;

reset(arg){
   ::reset(arg);
   set_name("buckler");
   set_short("An adamantite buckler");
   set_long("A buckler constructed from adamantite.\n"+
            "It is of drow workmanship.\n");
   set_type("shield");
   set_ac(2);
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
         player->query_name()+"'s adamantite buckler begins to melt away.\n");
       command("drop buckler", player);
       tell_room(environment(player),
         "The buckler breaks apart into many small shards of adamantite.\n");
  destruct(this_object());
  return 1;
          }
  call_out("light_check", 60);
  return 1;
          }
