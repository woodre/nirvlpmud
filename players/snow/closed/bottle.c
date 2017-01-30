/*  The bottle of Nu Nuth by Saber (12/12/94)
 *  A portable prision for those who really need it...
 *
 */

id(str)  { return str == "bottle";  }

short()  { return "A bottle of tinted blue glass";  }

long()  {
  if(environment(this_player()) == this_object())  {
  write(
  "\nYou are trapped inside of the mystic blue bottle of Nu Nath.\n");
        }
  if(environment(this_player()) != this_object())  {
  write(
    "\nThis is the mystic blue bottle of Nu Nath.\n");
        }
  write(
    "\nInscribed into the glass are many runes of glowing silver.\n"+
    "\nThe runes read:\n\n"+
    "  I met a traveler from an antique land,\n"+
    "  Who said: Two vast and trunkless legs of stone\n"+
    "  Stand in the desert.  Near them, on the sand,\n"+
    "  Half sunk, a shattered visage lies, whose frown,\n"+
    "  And wrinkled lip, and sneer of cold command,\n"+
    "  Tell that its sculptor well those passions read,\n"+
    "  Which yet survive, stamped on these lifeless thing,\n"+
    "  The hand that mocked them, and the heart that fed:\n\n"+
    "  And on the pedestal these words appear:\n"+
    "  \"My name is Ozymandias, King of Kings:\n"+
    "  Look on my works, ye Mighy, and despair!\"\n"+
    "  Nothing beside remains.  Round the decay\n"+
    "  Of that colossal wreck, boundless and bare\n"+
    "  The lone and level sands stretch far away.\n\n");
  if(environment(this_player()) == this_object())  {
  write("\nYou may only <say> <emote> and <look> in here.\n\n");
        }
        }

init()  {
  if((this_player()->query_level()) < 99 &&
        environment(this_player()) == this_object())  {
#ifndef __LDMUD__
     add_action("action_check"); add_xverb("");
#else
     add_action("action_check", "", 3);
#endif
        }
  if(this_player()->query_level() > 30) {
   add_action("put_in","Put");
   add_action("break_bottle","Break");
        }
        }

action_check(str)  {
string one, two;
  if(sscanf(str, "%s %s", one, two) < 2)  {
     sscanf(str, "%s", one);  }
  if(one == "look" || one == "l" || one == "exa" ||
     one == "say"  || one == "'" || one == ";" ||
     one== "emote" || one == ":" ||
     one == "pray")  {
  OK_ACTION(str);
        }
  else  {
  write("The mystic powers of the bottle prevent your action.\n");
  say(this_player()->query_name()+" is briefly bound in mystic silver chains.\n");
  return 1;
        }
        }

OK_ACTION(str)  {
  if(str == "pray")  {
  this_player()->move_player("into oblivion#room/void");
        }
        }

put_in(str)  {
object PLAYER;
  if(!str || !(PLAYER = find_player(str)))  {
  write("Who would you like to trap within the bottle of Nu Nuth?\n");
  return 1;
        }
  write("You utter the name "+capitalize(str)+"\n"+
    capitalize(str)+" is sucked into the bottle of Nu Nuth.\n");
  tell_room(environment(PLAYER),
    "\n"+PLAYER->query_name()+" is surrounded by glowing silver chains.\n"+
    "\n"+PLAYER->query_name()+" shrinks down to the size of your finger and vanishes.\n");
  move_object(PLAYER, this_object());
  tell_object(PLAYER,
    "You are now trapped within the bottle of Nu Nuth.\n");
  tell_room(environment(this_player()),
    "The bottle in "+this_player()->query_name()+"'s hand quivers slightly.\n");
  tell_object(environment(PLAYER),
    "\n"+PLAYER->query_name()+" appears in the bottle.\n");
  return 1;
        }

transfer_all_to(dest)  {
object ob, next_ob;
if(!dest) return 0;
  ob = first_inventory(this_object());
  while(ob)  {
    next_ob = next_inventory(ob);
    if(!call_other(ob, "drop", 1))  move_object(ob, dest);
    FALL(ob->query_real_name());
    ob = next_ob;
        }
        }

break_bottle()  {
object ME;
  ME = this_player();
  write("You smash the bottle of Nu Nuth against the ground!\n");
  say(this_player()->query_name()+" smashes the bottle of Nu Nuth against the ground.\n");
  transfer_all_to(environment(ME));
  destruct(this_object());
  return 1;
        }

FALL(str)  {
object OB;
  OB = find_living(str);
  tell_object(OB,
  "\nThere is a brilliant flash of light as the bottle explodes into a million\n"+
   "shards of glass.\n\n"+
  "You feel yourself\n\n\n");
  tell_object(OB,
  "\n\n\n           FALLING\n\n\n");
  tell_object(OB,
   "\n\n\nYou are somewhere new.\n\n");
  return 1;
        }

can_put_and_get()  { return 1; }
get() { return 1; }
realm() { return 1; }
