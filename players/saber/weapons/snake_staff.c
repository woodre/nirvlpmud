/*
 *    The snake staff carried by the Priestess of Arate.
 *    It can animate, cloneing /players/saber/monsters/staff_snake.c
 */

#define tp this_player()->query_name()
#define CAP capitalize(attacker->query_name())

int w, CHARGES;
inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    
    if (arg) return;

    set_name("snake staff");
    set_alias("staff");
    set_short("A Snake Staff");
    set_type("staff");         /* set type added by Pavlik */
    set_long("A long, ironwood staff carved to resemble a snake.\n"+
             "It is covered with runes of alteration and summoning.\n");
    set_read("To animate the staff, type <snake> <monster name>.\n");
    set_class(16);
    set_weight(2);
    set_value(1500);
    set_hit_func(this_object());
    CHARGES = random(3);
}


weapon_hit(attacker){
   w=random(100);
   
   if(w< 1)  {
   call_out("drop_staff",1);
        }
     
   if(w>70)    {
     write("The head of the snake staff animates and bites at "+CAP+".\n");
     say("The head of "+tp+"'s snake staff animates and bites at "+CAP+".\n");
   if(w > 90)  {
     write("The snake sinks its fangs into "+CAP+".\n");
     say("The snake sinks its fangs into "+CAP+".\n");
               }

   if(w > 90) { return 8; } else { return 5; }
        }
          
      return;
        }


drop_staff()  {
object player;
  player = environment(this_object());
  tell_room(environment(player),
    "\nThe snake staff in "+player->query_name()+"'s hand wiggles to life.\n\n");
  tell_object(player, "The snake tries to bite you!\n"+
                      "You quickly drop the staff!\n\n");
  command("drop snake staff", player);
  tell_room(environment(player),
    "The snake staff slithers away.\n");
  destruct(this_object());
  return 1;
          }


init()  {
  ::init();
  add_action("animate_snake","snake");
           }


animate_snake(str)  {
object target, snake;

  if(!str)  {
    write("Who do you wish for the snake to attack?\n");
    return 1;
            }
  
  if(CHARGES < 1)  {
    write("The snake staff is out of charges.\n");
    return 1;
            }
  
  target = present(str, environment(this_player()));
  if(!target)  {
    write("The snake hisses \""+capitalize(str)+" isss not here...\"\n");
    return 1;
            }
  
  if(target->is_player())  {
    write("The snake can not attack players.\n");
    return 1;
            }
  
  CHARGES = CHARGES - 1;
  snake = clone_object("/players/saber/monsters/staff_snake.c");
  move_object(snake, environment(this_player()));
  call_other(snake, "set_master", this_player()->query_real_name());
  call_other(snake, "set_charges", CHARGES);
  
  write("You throw your staff to the ground and shout \"\ANIMATE\"\n");
  say(tp+" throws "+this_player()->query_possessive()+" staff to the ground"+
         " and shouts \"\ANIMATE\"\n");
  command("drop snake staff", this_player());
  call_other(snake, "sic", target);
  destruct(this_object());
  return 1;
          }

query_charges()  { return CHARGES; }
set_charges(str) { CHARGES = str;  }
