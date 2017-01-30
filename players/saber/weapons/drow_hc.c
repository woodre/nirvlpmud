/*
 *    A drow hand crossbow which will melt away from darkness.
 */

#define tp this_player()->query_name()
#define CAP capitalize(attacker->query_name())

int w, bolts_left, loaded;
object player;
inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    
    bolts_left = 4;
    
    if (arg) return;

    set_name("hand crossbow");
    set_alias("crossbow");
    set_type("crossbow");         /* set type added by Pavlik */
    set_short("A hand crossbow");
    set_long("A small hand crossbow constructed from dark wood.\n"+
           "With it is a small quiver which can hold up to poisoned four bolts.\n"+
           "Type <check_crossbow> to see the number of poisoned bolts left.\n"+
           "Type <load_bolt> to load a poisoned bolt into the crossbow.\n"+
           "Type <snipe> to shoot an opponent in combat.\n");
    set_class(15);
    set_weight(1);
    set_value(1000);
    call_out("light_check",30);
    set_hit_func(this_object());
}

weapon_hit(attacker){
   w=random(15);
        
   if(w<5)  {
     write("Your quickly reload the hand crossbow and fire again at "+CAP+".\n");
     say(tp+" quickly reloads the hand crossbow and fires again at "+CAP+".\n");
      return 5;
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
         player->query_name()+"'s hand crossbow begins to melt away.\n");
       command("drop hand crossbow", player);
       tell_room(environment(player),
         "The hand crossbow breaks apart into many small shards of wood.\n");
  destruct(this_object());
  return 1;
          }
  call_out("light_check", 60);
  return 1;
          }


init()  {
  ::init();
  add_action("check_crossbow","check_crossbow");
  add_action("load_bolt","load_bolt");
  add_action("shoot_monster","snipe");
         }


check_crossbow()  {
string is_loaded;
  if(loaded == 1) 
    { is_loaded = "is"; } else { is_loaded = "is not"; }
  write("You have "+bolts_left+" poisoned bolts left.\n");
  write("The hand crossbow "+is_loaded+" loaded.\n");
  return 1;
         }
         
load_bolt()  {
  if(bolts_left < 1)  {
    write("You have no poisoned bolts left.\n");
    return 1;
          }
  loaded = 1;
  bolts_left = bolts_left - 1;
  write("You load a poisoned bolt into the hand crossbow.\n");
  say(tp+" loads a bolt into the hand crossbow.\n");
  return 1;
          }


shoot_monster()  {
object target, poison;
  target = this_player()->query_attack();
  if(!target)  {
    write("You must be in combat to shoot something.\n");
    return 1;
       }
  if(loaded < 1)  {
    write("You must load the hand crossbow before you can shoot it.\n");
    return 1;
       }
  if(target->is_player())  {
    write("Only drow may fire poisoned bolts at players.\n");
    return 1;
       }
  poison = clone_object("/players/saber/closed/poison.c");
  move_object(poison, target);
  write("You fire a poisoned bolt into "+target->query_name()+".\n");
  say(tp+" fires a poisoned bolt into "+target->query_name()+".\n");
  loaded = 0;
  return 1;
       }
