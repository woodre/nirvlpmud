/*
 * The Bar for the Servants of Shardak and their allies
 * It is a modified /room/pub2.c (it has coffee, beer, special, fb)
 * You can also buy some portable heals here (I grok wrongness)
 * November 2000 - Rewritten by Verte [../doc/forau_heals for guide]
 * 030715 - Added color, tweaked desc, and added exits that can only be
 *          read by shardaks [linus]
 * 030719 - Fixed long.  set_items work once again. [linus]
 */

#include "/players/balowski/lib.h"
#include "../include/def.h"
#include "../include/ansi.h"
inherit ROOM;

void
create()
{
    ::create();
    set_short(RED+"Forau's"+NORM);
    set_long(HIK+"\
This cave has been fitted out as a bar at the whim of Shardak.\n\
Only the servants and allies of Shardak may come here to quench\n\
their thirst. A charred sign hangs on the wall behind the bar.\n"+NORM);
    set_items(([
        "sign" : "Flames must have licked this piece of wood many times.\n"+
                        "There is something written on it.\n",
               "bar" : 0,
        "passage" : "A dark passage leads east to the rest of the guild.\n",
    ]));
    set_exits((["east" : (PATH + "cave")]));
    set_light(1);
    set_property("fight area", 1);
    set_property("no teleport", 1);
    move_object(clone_object(OBJDIR + "dispensr"), this_object());
}

void
reset(int arg)
{
    object      mon;

    ::reset(arg);
    if (!(mon = present("forau", this_object()))) {
        mon = clone_object(MONSTER);
        mon->set_name("Forau");
        mon->set_gender("male");
        mon->set_race("demon");
        mon->set_short("Forau - Bartender");
        mon->set_long(HIK+"\
Forau is dressed all up in black. His silk shirt glows softly in the dim\n\
light. He is the bartender of this joint and one of Satan's disciples.\n"+NORM);
        mon->set_level(16);
        mon->set_al(-300); /* infamous, but he doesn't do anything */
        mon->set_chat_chance(3);
        mon->load_chats(({
           "Forau wipes up some glasses.\n",
           "With experienced hands Forau concocts a foul smelling drink.\n",
           "Forau casually remarks, \"Rumour is that Pitsniffer waxed Boltar incognito.\"\n",
           "Forau grins and says to you, \"Vertebraker used to be one of us...\"\n",
           "Forau ponders, \"I wonder whatever became of Balowski...\"\n",
             }));
        mon->setCallBack();
        move_object(mon, this_object());
    }
}

void
init()
{
    ::init();
    add_action("cmdBuy", "purchase");
    add_action("cmdList", "list");
    add_action("cmdBuy", "buy");
    add_action("do_read","read");
}

static object
MakeDrink(string which)
{
    object ob;

    switch (lower_case(which)) {
      case "bottle of paranoia":
             ob = clone_object(STDDIR+"heal"); /* props to felde */
             ob->set_name("bottle");
      ob->add_alias("paranoia");
      ob->add_alias("bottle of paranoia");
             ob->set_short("A bottle of Paranoia");
             ob->set_long("\
A long necked bottle of clear transparent glass. The fluid within\n\
the bottle is almost colourless, but when you look carefully, you\n\
see glimpses of odd distortions in the fluid--as if the fluid or\n\
something _in_ the fluid is moving about.\n");
             ob->set_type("gulps of Paranoia");
             ob->set_msg("You drink a gulp of Paranoia.\n");
      ob->set_msg2(" drinks a gulp of Paranoia.\n");
             ob->add_cmd("drink");
      ob->add_cmd("gulp");
             ob->set_charges(4);
             ob->set_soak(10);
             ob->set_heal((40 + random(10) + random(2)),(40 + random(10) + random(2)));
      ob->set_value(682 + random(2)); /* per charge */
             break;

      case "tub of gluttony":
             ob = clone_object(STDDIR+"heal");
             ob->set_name("tub");
      ob->add_alias("gluttony");
      ob->add_alias("tub of gluttony");
             ob->set_short("A tub of Gluttony");
             ob->set_long("\
A dark grey mixture of slop and grease rests in this plastic\n\
tub.  A brown ooze has settled at the bottom, and an odour of\n\
blood and gore exudes from this strange mixture.\n");
             ob->set_type("chunks of Gluttony");
             ob->set_msg("You reach your hand into the tub and gulp down a chunk of Gluttony.\n");
      ob->set_msg2(" gulps down a chunk of Gluttony.\n");
             ob->add_cmd("gulp");
      ob->add_cmd("eat");
      ob->add_cmd("devour");
             ob->set_charges(4);
             ob->set_stuff(10);
             ob->set_heal((40 + random(10) + random(2)),(40 + random(10) + random(2)));
      ob->set_value(682 + random(2)); /* per charge */
             break;

      case "bottle of rage":
             ob = clone_object(STDDIR+"heal");
             ob->set_name("bottle");
      ob->add_alias("rage");
      ob->add_alias("bottle of rage");
             ob->set_short("A bottle of Rage");
             ob->set_long("\
A stout bottle made from dark brown, almost opaque, glass. The label\n\
says \"Rage -- 42 percent proof\". You can almost feel it bubbling\n\
inside the bottle.\n");
             ob->set_type("gulps of Rage");
             ob->set_msg("You drink a gulp of Rage.\n");
      ob->set_msg2(" drinks a gulp of Rage.\n");
             ob->add_cmd("drink");
      ob->add_cmd("gulp");
             ob->set_charges(5);
             ob->set_intox(15);
             ob->set_heal(32 + random(12), 32 + random(12));
      ob->set_value(280 + random(48)); /* per charge ~ 304 */
             break;

      case "bottle of insomnia":
             ob = clone_object(STDDIR+"heal");
             ob->set_name("bottle");
      ob->add_alias("insomnia");
      ob->add_alias("bottle of insomnia");
             ob->set_short("A bottle of Insomnia");
             ob->set_long("\
A small ceramic vial with glazed white surface. It is tightly sealed\n\
with a cork. The inscription in black gothic letters says: \"Insomnia --\n\
cures drunkenness and hangovers\".\n");
             ob->set_type("gulps of Insomnia");
             ob->set_msg("You drink a gulp of Insomnia.\n");
      ob->set_msg2(" drinks a gulp of Insomnia.\n");
             ob->add_cmd("drink");
      ob->add_cmd("gulp");
             ob->set_charges(2);
             ob->set_intox(-14);
      ob->set_value(240 + random(80)); /* per charge ~ 280 */
             break;

      case "jar of malice":
             ob = clone_object(STDDIR+"heal");
             ob->set_name("jar");
             ob->add_alias("malice");
      ob->add_alias("jar of malice");
             ob->set_short("A jar of malice");
             ob->set_long("\
The dim glass jar is engraved with some strange symbols unknown\n\
to you. It contains a tenuous mist of seasoned malice, which you\n\
can inhale for greater strength.\n");
             ob->set_type("whiffs of Malice");
             ob->set_msg("You inhale the vapours from the jar and feel damn near invincible.\n");
      ob->set_msg2(" inhales the vapours from a small jar.\n");
             ob->add_cmd("whiff");
      ob->add_cmd("inhale");
             ob->set_charges(1);
             ob->set_intox(-50);
             ob->set_heal(1000,1000);
      ob->set_value(10000 + random(1920)); /* ~ 10960 */
             break;
    }
    return ob;
}

status
cmdBuy(string arg)
{
    string mess, str, a_str;
    int heal, value, strength;
    object ob;

    if (!present("forau", this_object()))
      return (notify_fail("There is nobody to serve you.\n"), 0);
    if (!arg) return (notify_fail("Forau peers quizzically at you.\n"), 0);

    switch (atoi(arg)) {
    case 1:
             str = "Dark brew";
             mess = "You drink the brew. That feels good.\n";
             heal = 1; value = 10; strength = 3;
             break;
    case 2:
             str = "Gasoline";
             mess = "You down the shot and try not to breathe at the candles.\n";
             heal = 10; value = 150; strength = 7;
             break;
    case 3:
             str = "Blood of children";
             mess = "You let the thick red concoction crawl down your throat.\n";
             heal = 25; value = 230; strength = 14;
             break;
    case 4:
             str = "Incinerator";
             mess = "You feel somewhat invigorated.\n";
             heal = 0; value = 20; strength = -2;
             break;
    case 5:
             str = "bottle of Paranoia";
             value = 2730;
             break;
    case 6:
             str = "bottle of Rage";
             value = 1520;
             break;
    case 7:
             str = "bottle of Insomnia";
             value = 560;
             break;
    case 9:
             str = "jar of Malice";
             value = 10960;
             break;
    case 8:
      str = "tub of Gluttony";
      value = 2730;
      break;
    default:
             write("Forau says, \"What is it that you want, moron?\"\n");
             return 1;
    }

    if ((int) this_player()->query_money() < value) {
        write("Forau barks, \"Bugger off, you poor bum.\"\n");
             return 1;
    }
    this_player()->add_money(-value);
    a_str = indefinite(str);

    if (ob = MakeDrink(str)) {
             if (transfer(ob, this_player())) {
                 write("You cannot carry more.\n");
                 destruct(ob);
                 return 1;
             }
    else write("Forau nods and thanks you.\n"+
               "He hands you a "+str+" in exchange for "+value+" gold pieces.\n");
    return 1;
    }
    else {
             if (strength - 2 > (int) this_player()->query_level()) {
                 if (strength - 5 > (int) this_player()->query_level()) {
                         /* This drink is *much* too strong for the player */
                         say(this_player()->query_name() + " orders " +
                             a_str + ", and immediately throws it up.\n");
                         write("You order " + a_str + ", try to drink it, and throw up.\n");
                 } else {
                         say(this_player()->query_name() + " orders " +
                             a_str + ", and spews it all over you!\n");
                         write("You order " + a_str + ", try to drink it, and sputter it all over the room!\n");
                 }
                 this_player()->add_money(-value);
                 return 1;
             }

             if (!this_player()->drink_alcohol(strength)) {
                 write("Forau says, \"I think you've had enough.\"\n");
                 say(this_player()->query_name() + " asks for " +
                         a_str + " but Forau refuses.\n");
                 return 1;
             }
    }
    write("You pay Forau " + value + " gold pieces for the " + str + ".\n");
    say(this_player()->query_name() + " orders " + a_str + ".\n");
    this_player()->add_money(-value);
    this_player()->add_alignment(-(random(33) + random(69)));
    this_player()->heal_self(heal);
    if (mess) write(mess);
    return 1;
}

int
do_read(string str)  /* baffling sign fix by verte */
{
    if (!str)
    {
      notify_fail("Read what?\n");
      return 0;
    }

    if (str == "sign" || str == "the sign")
    {
      tell_object(this_player(),
      " ~ Drinks served in the bar ~\n\n"+
      "  1. Dark brew                       10.\n"+
      "  2. Gasoline                       150.\n"+
      "  3. Blood of children        230.\n"+
      "  4. Incinerator        20.\n\n");
      tell_object(this_player(),
      "       ~ Bottled drinks ~\n\n"+
      "  5. Paranoia                2730.\n"+
      "  6. Rage            1520.\n"+
      "  7. Insomnia                560.\n\n");
      tell_object(this_player(),
      "       ~ Special orders ~\n"+
      "  8. Gluttony         2730. \n"+
      "  9. Malice           10960.\n\n");
      return 1;
    }
}

int
cmdList(string str)
{
    if(str) return 0;
    command("read sign", this_player());
    return 1;
}

/* Room long description, shows exits only to Shards */

void
long(string arg){
 if(!arg) {
  if ((int)this_player()->query_brief() != 2)
   write(RED+"Forau's\n"+NORM);
    ::long(arg);
  if (present("shardak_mark",this_player()))
   write("\t"+NORM+RED+"\The only exit is: east.\n"+NORM);
    return;
 }
  else ::long(arg);
}




