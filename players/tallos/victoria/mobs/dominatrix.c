inherit "/obj/monster.c";
#include "/obj/ansi.h"
#define tpn this_player()->query_name()

object bra;
reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("Dominatrix");
  set_race("demon");
  set_alias("woman");
  set_short(BOLD+RED+"Melinda the Dominatrix"+NORM);
  set_long(
    "    This sultry creature is the manager of all the runway\n"+
    "models.    She has a wicked heart and an even more wicked \n"+
    "tight black leather corset showing off her ample breasts.\n"+
    "She looks at you with cold eyes and licks her lips sizing\n"+
    "you up.\n"+
    " \n"+
    " Measurements: 34D-30-36\n");
    
  bra = clone_object("/players/tallos/victoria/objects/corset1.c");
  move_object(bra, this_object());
  command("wear corset", this_object());
  
  add_money(2250+random(1250));
  set_level(20);
  set_hp(1500);
  set_al(-1000);
  set_ac(27);
  set_wc(40);
  set_aggressive(0);
  set_chat_chance(9);
  load_chat("   Melinda drops a pen on the ground intentionally. She bends over low to\n"+
            "pick it up, her breasts nearly spilling out of the tight corset.\n");
  load_chat("Melinda watches your eyes bulge in your head. She jiggles a bit to titillate your\n"+
            "dirty mind...\n");
  load_chat("Melinda, smiles a wicket smile knowing she has complete control over you.\n");
  load_chat("Melinda licks her lips suggestively.\n");
  load_chat("Melinda runs her hands down her smooth dark leather pants.\n");
  add_spell("Frenzy",
  ""+HIM+"Melinda takes out a whip and CRACK!!!"+NORM+"\n",
  ""+HIM+"Melinda takes out a whip and CRACK!!!"+NORM+"\n",
  33,100,"other|physical");
}
