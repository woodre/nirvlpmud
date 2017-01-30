/*
 * Magical darkness created by the bard light: dark spell.
 * Note: Dark Mages will *still* be able to see.
 * Bard v3.0
 */

inherit "obj/treasure";

reset(arg)  {
  if(arg) return;
    set_id("darkness");
    set_short("A cloud of darkness");
    set_long("It is too dark.\n");
    set_value(0);
    set_light(-1);
    call_out("dark",100 + random(300));
        }

get()    { return 1;   }
drop()   { return 1;   }
can_put_and_get()  { return 0; }

is_illusion()   { return "illusion"; }

dark() {
  tell_room(environment(this_object()),
    "The darkness which fills the room dissipates.\n");
  remove_call_out("dark");
  destruct(this_object());
  return 1;
        }


init()  {
  ::init();
  if(!present("coldfire", this_player()))  {
  if(this_player()->query_level() < 21)  {
  add_action("look_s","look");
  add_action("look_s","l");
  add_action("look_s","exa");
  add_action("look_s","examine");
  add_action("look_s","i");
  add_action("look_s","inventory");
  add_action("look_s","get");
         }
         }
         }
         
look_s() {
  write("It is too dark.\n");
  return 1;
         }
