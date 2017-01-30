/*
 *    A drow dagger which will melt away from darkness.
 */

#define tp this_player()->query_name()

int w;
object player;
inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("adamantite dagger");
    set_alias("dagger");
    set_type("dagger");         /* set type added by Pavlik */
    set_short("An adamantite dagger");
    set_long("A wickedly sharp dagger forged of adamantite.\n"+
             "It carries a heavy enchantment, and is of Drow workmanship.\n");
    set_class(14);
    set_weight(1);
    set_value(500);
    call_out("light_check",30);
}

light_check()  {
  player = environment(this_object());
  
  if(call_other(environment(this_object()), "arate", 0) != "YES"   &&
     call_other(environment(this_object()), "DARK",  0) != "YES"   &&
     call_other(environment(player), "arate", 0) != "YES"          &&
     call_other(environment(player), "DARK",  0) != "YES")  {
       tell_room(environment(player),
         player->query_name()+"'s adamantite dagger begins to melt away.\n");
       command("drop adamantite dagger", player);
       tell_room(environment(player),
         "The dagger breaks apart into many small shards of adamantite.\n");
  destruct(this_object());
  return 1;
          }
  call_out("light_check", 60);
  return 1;
          }
