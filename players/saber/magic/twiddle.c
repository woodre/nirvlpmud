/*
 *
 *  A twiddle card - all rights still to WoTC.
 *
 */

inherit "/players/saber/closed/bards/shapeobj.c";
reset(arg)  {
   if (arg) return;
   set_name("magic card");
   set_alt_name("twiddle");
   set_alias("card");
   set_short("A Revised Magic Card");
   set_long("A Magic Card from Wizards of the Coast.\n"+
            "You might want to read it.\n");
   set_weight(0);
   set_value(0);
        }

read(str)  {
  if(str == "card")  {
  write(
  "\n"+
  "You read the Magic Card.\n\n"+
  "This is a blue magic card called Twiddle.\n"+
  "By typing Twiddle <player name>, you can either tap\n"+
  "or untap them.  (Yes, you can do it at range.  Its\n"+
  "a magic spell)  The casting of this spell will cost\n"+
  "you one mana, and will remove the card from your hand.\n"+
  "\nTo use type <twiddle: player name>\n\n");
  write(
     "You never know who twiddled you...\n"+
       "                                   - A SABER product.\n");
  return 1;
        }
        }

init()  {
  ::init();
   add_action("send","twiddle");
   add_action("read","read");
        }

send(str)  {
object ob, ob2;
  if(!str)  {
    write("To use type: twiddle <player name>\n");
    return 1;
        }
  ob = this_object();
  ob2 = find_living(str);
  if(!ob2)  {
    write("You cannot find "+capitalize(str)+" anywhere.\n");
    return 1;
        }
  if(in_editor(ob2)  ||
     str == "boltar" )  {
    write(capitalize(str)+" spell blasts your twiddle!\n");
  return 1;
        }
/* Changing so wizzes can't be twiddled. 5/20/97 -snow */
  if(ob2->query_level() > 20) {
    write("Wizzes are immune to the twiddle!\n"); return 1; }
  write("You twiddle "+capitalize(str)+".\n"+
    "You have a mental image of "+capitalize(str)+" being picked up by\n"+
    "a mystic blue force and turned sideways.\n");
  tell_room(environment(ob2), "A magical force enters the room and surrounds "+capitalize(str)+".\n"+
    capitalize(str)+" is violently grabbed by the force and turned sideways.\n");
  tell_object(ob2, "You now have a Magic Card.\n");
  move_object(ob,ob2);
  return 1;
        }
