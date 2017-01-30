/*
 * An object which prevents all talking in a room.
 * Bard v3.0 by Saber / Geoffrey Z.
 *
 */

inherit "obj/treasure";

reset(arg)  {
  if(arg) return;
    set_id("aura_of_silence");
    set_alias("aura");
    set_short("An aura of silence");
    set_long("\n\n\n\tA featureless void of silence.\n\n\n\tIt engulfs you.\n\n\n");
    set_value(0);
    call_out("go_away", 200+random(400));
        }

get()    { return 1;   }
drop()   { return 1;   }
can_put_and_get()  { return 0; }

is_illusion()   { return "illusion"; }

go_away() {
  tell_room(environment(this_object()),
    "\nThe silence which engulfs the room dissipates.\n\n");
  remove_call_out("go_away");
  destruct(this_object());
  return 1;
        }

/* blocks bards, vampires, mini guilds, pain line, */
/* need knight, ranger, mage, shardak, cyberninja, polymorph */ 

init()  {
  ::init();
  if(this_player()->query_level() < 21)  {
  add_action("look_s","say");
  add_action("look_s","'");
  add_action("look_s",";");
  add_action("look_s","whisper");
  add_action("look_s","shout");
  add_action("look_s","gossip");
  add_action("look_s","equip");
  add_action("look_s","risque");
  add_action("look_s","junk");
  add_action("look_s","tell");
  add_action("look_s",":");
  add_action("look_s","emote");
  add_action("look_s","be");
  add_action("look_s","bt");
  add_action("look_s","bte");
  add_action("look_s","farsong");
  add_action("look_s","farsonge");
  add_action("look_s","tempt");
  add_action("look_s","tempte");
  add_action("look_s","brag");
  add_action("look_s","brage");
  add_action("look_s","tale");
  add_action("look_s","talee");
  add_action("look_s","meow");
  add_action("look_s","meowe");
  add_action("look_s","recite");
  add_action("look_s","recitee");
  add_action("look_s","story");
  add_action("look_s","storye");
  add_action("look_s","chat");
  add_action("look_s","chate");
  add_action("look_s","te");
  add_action("look_s","tf");
  add_action("look_s","tel");
  add_action("look_s","pt");
  add_action("look_s","pe");

         }
         }
         
look_s() {
  write("\nThe aura of silence prevents your action.\n\n");
  return 1;
         }
