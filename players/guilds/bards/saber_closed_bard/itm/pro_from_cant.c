/*
 * A spell to protect bards from cantrips.
 * Bard v3.0
 */

inherit "obj/treasure";

reset(arg)  {
  if(arg) return;
    set_id("pro_from_cant");
    call_out("go_away",300+random(350));
        }

drop()   { return 1;   }
can_put_and_get()  { return 0; }

go_away() {
  tell_object(environment(this_object()),
    "\nYour protection from cantrips spell expires.\n\n");
  remove_call_out("go_away");
  destruct(this_object());
  return 1;
        }


init()  {
  ::init();
  add_action("cantrip_cast","cantrip");
  add_action("cantrip_cast","C");
         }
         
cantrip_cast() {
  write("You can not cast a cantrip while you are protected from them.\n");
  return 1;
         }
