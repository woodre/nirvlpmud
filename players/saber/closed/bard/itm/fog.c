/*
 * Thick fog created by the storm fog spell.
 * Note: Bards can see in this fog.
 * Bard v3.0
 */

inherit "obj/treasure";

int GO_AWAY;

reset(arg)  {
  if(arg) return;
    set_id("fog");
    set_short("A dense cloud of fog");
    set_long("You can't see through the fog.\n");
    set_value(0);
    set_light(1);
    call_out("dark",2);
        }

get()    { return 1;   }
drop()   { return 1;   }
can_put_and_get()  { return 0; }

dark() {
  remove_call_out("dark");
  call_out("go_away", this_object()->query_go_away());
  return 1;
        }


init()  {
  ::init();
  if(!present("instrument", this_player()))  {
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
  add_action("look_s","kill");
  add_action("look_s","mi");
  add_action("look_s","sh");
  add_action("look_s","fi");
  add_action("look_s","so");
  add_action("look_s","missile");
  add_action("look_s","shock");
  add_action("look_s","fireball");
  add_action("look_s","sonic");

  tell_object(this_player(), "There is a lot of fog in here.\n");
         }
         
look_s() {
  write("You can't see through the fog.\n");
  return 1;
         }

query_go_away()               { return GO_AWAY;   }

set_go_away(str)  {  GO_AWAY = str;  }  
