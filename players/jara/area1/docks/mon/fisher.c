/* A fisherman, Created <5/12/00> by Jara */

#include "/players/jara/misc/ansi.h"
inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object ob;

  ob = clone_object("/players/jara/area1/docks/obj/pole.c");
move_object(ob,this_object());

  add_money(300);
  set_name("fisherman");
  set_alt_name("nuri");
  set_short("An old fisherman");
  set_race("human");
  set_long("The fisherman wears a wide-brimmed hat, with light grey hair\n"+
    "visible at the base of his neck. He is rough shaven and he\n"+
    "wears loose fitting overalls and rubber boots.\n");
  set_level(12);
  set_ac(9);
  set_wc(16);
  set_hp(180);
  set_al(0);
  set_aggressive(0);
  set_chat_chance(15);
  set_a_chat_chance(10);
  load_chat("The fisherman reels his line in slowly.\n");
  load_chat("The fisherman gently bobs the end of the pole.\n");
  load_chat("The fisherman gazes intently at the waters.\n");
  load_a_chat("The fisherman swings at you with his fist.\n");
  load_a_chat("The fisherman curses at you.\n");
   }
}

init() {
  add_action("ask","ask");
}

ask(str) {
string what;
  if(!str) { notify_fail("Ask whom about what?\n"); return 0; }
  if(sscanf(str,"nuri about %s",what)!=1) { notify_fail("Ask whom about what?\n"); return 0; }
  switch(what) {
      case "nuri": case "fisherman":
      write(
    "The fisherman looks up at you, a smile crossing his lips.\n"+
    "'Yes, I'm Nuri the fisherman,' he says, leaning over to his box.\n"+ 
    "'I can tell you about our"+HIW+" land"+NORM+" if you're interested, stranger.'\n"+
    "He digs around in the tackle and produces a juicy, fat worm.\n"+
    "He continues, 'Or if you'd rather, I can tell you a little story\n"+
    "about the"+HIW+" barmaid"+NORM+"...'\n"+
    "His eyes sparkle with mischief.\n");
  return 1;
      case "fishing":
      write(
    "The fisherman smiles and gently bobs the end of his line...\n"+
    "He looks up at you and says, 'The fish have been good to me today!\n");
  return 1;
      case "pirates":
      write(
    "The fisherman grins, his yellowed teeth showing...\n"+
    "'Those pirates were a nasty bunch, they were! We fought them\n"+
    "away from our homes with everything we had. I remember one time\n"+
    "when...' the fisherman drifts off, mumbling to himself.\n");
  return 1;
      case "land": 
      write(
     "The fisherman nods his head up and down, and begins, 'Our land\n"+
    "was once a joyful and bountiful place. The"+HIW+" King"+NORM+" and his"+HIW+" Queen"+NORM+"\n"+
    "were fair rules and all the people were happy.'\n"+
    "A look of sadness crosses the fisherman's face for a moment...\n"+
    "He continues, 'An evil "+HIW+"wizard"+NORM+", named "+HIW+"Manahnan"+NORM+" came upon our\n"+ 
    "land and became infatuated with our young"+HIW+" princess"+NORM+"'.\n"+
    "The fisherman sighs to himself.\n");
  return 1;
     case "barmaid":
      write(
    "The fisherman grins, his yellowed teeth visible.\n"+
    "'You want to know more about Amelia, eh? Well, she's the\n"+
    "sweetest girl you'll ever meet. Just ask her about that\n"+
    "stablehand in the city sometime,' he says with a huge grin.\n"+
    "The fisherman laughs to himself and nods his head.\n");
  return 1;
      case "king":
      write(
    "The fisherman slowly reels in his line...\n"+
    "'The King is a good and honest man, hardworking and he cared\n"+
    "about the people in this land. He's a different man now that\n"+
    "his only daughter was kidnapped by that evil"+HIW+" wizard"+NORM+". He and\n"+
    "his"+HIW+" Queen"+NORM+" live in the castle on the hill just beyond the city\n"+
    "to the north. They haven't seen anyone since the"+HIW+" princess"+NORM+" was\n"+
    "taken from them four years ago...\n"+
    "The fisherman shakes his head slowly.\n");
  return 1;
      case "queen":
      write(
    "A smile crosses Nuri's lips for a moment before he continues.\n"+
    "'Ah, the Queen Valencia is a beautiful woman, with a kind heart\n"+
    "and caring soul,' the fisherman says with a smile.\n"+
    "She and her daughter were riding through the forests north of\n"+
    "the city when"+HIW+" Manahnan"+NORM+" trapped them with his evil magic and\n"+ 
    "kidnapped the"+HIW+" princess"+NORM+". Took her right through a magic portal,\n"+
    "he did.'\n");
  return 1;
      case "wizard": case "manahnan":
      write(
    "The fisherman narrows his eyes and his chin begins to quiver...\n"+
    "'The wizard Manahnan is a wretched man,' the fisherman says,\n"+
    "sighing...\n"+
    "'He took the princess right from her mother's arms and vanished\n"+
    "without a trace, although it is rumored he makes his home deep\n"+
    "within the"+HIW+" forests"+NORM+".\n");
  return 1;
      case "princess":
      write(
    "'The Princess Jasmine was such a lovely young woman, with golden\n"+
    "curls and a beautiful smile...' the fisherman says, looking up\n"+
    "at you for a moment.\n"+
    "It would be a miracle in this land if someone could find her and\n"+
    "return her safely home.'\n"+
    "The fisherman gazes sadly at the waters.\n");
  return 1;
      case "forests":
      write(
    "The fisherman looks up at you sharply.\n"+
    "'Don't think of going into those forests, the evil"+HIW+" wizard"+NORM+" has\n"+
    "placed a strange enchantment on them...\n"+
    "The fisherman gives you a hard poke in your ribs.\n");
  return 1;
  default:
      write(
    "The fisherman smiles and says, 'I don't know much about that...'\n");
  return 1;
  }
}
