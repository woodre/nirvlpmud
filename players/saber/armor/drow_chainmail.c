inherit "obj/armor";
object player;

reset(arg){
   ::reset(arg);
   set_name("elven chainmail");
   set_short("Adamantite chainmail");
   set_alias("chainmail");
   set_long("An exquisite suit of adamantite chainmail.  It is of Drow\n"+
            "craftsmanship, and heavily enchanted to offer stalwart protection.\n");
   set_ac(4);
   set_weight(1);
   set_value(1000);
   call_out("light_check", 30);
}

light_check()  {
  player = environment(this_object());
  
  if(call_other(environment(this_object()), "arate", 0) != "YES"   &&
     call_other(environment(this_object()), "DARK",  0) != "YES"   &&
     call_other(environment(player), "arate", 0) != "YES"          &&
     call_other(environment(player), "DARK",  0) != "YES")  {
       tell_room(environment(player),
         player->query_name()+"'s adamantite chainmail begins to melt away.\n");
       command("drop elven chainmail", player);
       tell_room(environment(player),
         "The chainmail breaks apart into many small strands of adamantite.\n");
  destruct(this_object());
  return 1;
          }
  call_out("light_check", 60);
  return 1;
          }
