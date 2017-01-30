/*
 *  Unholy water from the Temple of Arate!
 */

#define tp this_player()->query_name()
 inherit "obj/treasure.c";

int count;

 reset(arg) {
    if (arg) return;
    set_id("unholy water");
    set_alias("bottle");
    set_short("A bottle of unholy water");
   set_long("A bottle of unholy water, blessed by the priests of Arate.\n"+
        "You could <douse> an opponent with it.\n");
    set_value(25);
}

init() {
  ::init();
add_action("douse", "douse");
}

douse()  {
object ob;
ob = this_player()->query_attack();
if(!ob)  {
    write("You must be fighting something before you can douse it.\n");
  return 1;        }

if(ob->is_player())  {
  write("Unholy water may not be used against players.\n");
    return 1;
        }

if(ob->query_alignment() < 0)  {
  write("You douse "+ob->query_name()+" with unholy water.\n"+
    ob->query_name()+" does not seem affected.\n");
  say(tp+" douses "+ob->query_name()+" with some water.\n");
  destruct(this_object());
  return 1;
        }

  ob->heal_self(-(random(20) + 10));
  write("You douse "+ob->query_name()+" with unholy water!\n"+
    ob->query_name()+" screams in pain as the water eats away at "+ob->query_objective()+"...\n");
  say(tp+" douses "+ob->query_name()+" with unholy water!\n"+
    ob->query_name()+" screams in pain as the water eats away at "+ob->query_objective()+"...\n");
  destruct(this_object());
  return 1;
}

query_save_flag()  { return 0; }
can_put_and_get()  { return 0; }
drop()  { return 1; }
get()   { return 1; }
