/*  A pet that players can find - approx cost of 3500  */


inherit "obj/treasure";

reset(arg) {   
   if (arg) return;
   
   set_id("drake egg");
   set_alias("egg");
   set_short("A large egg");
   set_long("The egg of a Sun Drake.  It is warm to the touch, and\n"+
            "appears to be ready to hatch.  If you want to try to\n"+
            "force the egg to hatch, type < hatch > < egg >\n");
   set_weight(1);
   set_value(3500);
        }
   
        
init() {  add_action("hatch_egg", "hatch");   }


hatch_egg(str) {  
object DRAKE;

  if ((!str) || !id(str)) return 0;
  
  DRAKE = clone_object("/players/saber/monsters/tr/drake_pet.c");
  DRAKE->set_master(this_player()->query_real_name());
  
  write("You place the egg on the ground and tap it.\n");
  say(this_player()->query_name()+" puts a large egg on the ground and taps it.\n");
  command(this_player(), "drop egg");
  
  tell_room(environment(this_object()),
  "\nThe egg shakes and cracks.\n\n"+
  "A young sun drakes crawls from the egg and shakes it's tiny wings dry.\n");
  
  move_object(DRAKE, environment(this_player()));

  destruct(this_object());
  return 1;   
   
   }
