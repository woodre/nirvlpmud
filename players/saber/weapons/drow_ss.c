/*
 *    A drow short sword which will melt away from darkness.
 */

#define tp this_player()->query_name()
#define CAP capitalize(attacker->query_name())

int w;
object player;
inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("short sword");
    set_alias("sword");
    set_type("sword");         /* set type added by Pavlik */
    set_short("An adamantite short sword");
    set_long("A wickedly sharp short sword forged from adamantite.\n"+
             "It carries a heavy enchantment, and is of Drow workmanship.\n");
    set_class(17);
    set_weight(2);
    set_value(1000);
    call_out("light_check",30);
    set_hit_func(this_object());
}

weapon_hit(attacker){
   w=random(15);
        
   if(w<5)  {
     write("Your sword's razor edge slices through "+CAP+".\n");
     say(tp+"'s short sword cuts into "+CAP+" with swift percision.\n");
      return 8;
        }        
      return;
        }

light_check()  {
  player = environment(this_object());
  
  if(call_other(environment(this_object()), "arate", 0) != "YES"   &&
     call_other(environment(this_object()), "DARK",  0) != "YES"   &&
     call_other(environment(player), "arate", 0) != "YES"          &&
     call_other(environment(player), "DARK",  0) != "YES")  {
       tell_room(environment(player),
         player->query_name()+"'s short sword begins to melt away.\n");
       command("drop short sword", player);
       tell_room(environment(player),
         "The short sword breaks apart into many small shards of adamantite.\n");
  destruct(this_object());
  return 1;
          }
  call_out("light_check", 60);
  return 1;
          }
