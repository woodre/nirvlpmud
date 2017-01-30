inherit "/obj/monster.c";
#include "/obj/ansi.h"
#define tpn this_player()->query_name()

object bra;
reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("attendant");
  set_race("human");
  set_short(BOLD+GRN+"A Victoria's Secret Attendant"+NORM);
  set_long(
    "  This is a victoria secret sales attendant. she wears\n"+
    "a sexy pair of bra and panties.  She greets you with a\n"+
    "sultry smile and buxom breasts.  She goes a little hop\n"+
    "as you enter with plenty of perkiness.\n");
  
  bra = clone_object("/players/tallos/victoria/objects/secretbrayellow.c");
  move_object(bra, this_object());
  command("wear bra", this_object());
  add_money(100);
  set_level(17);
  set_hp(450);
  set_al(0);
  set_ac(15);
  set_wc(25);
  set_aggressive(0);
  set_chat_chance(10);
  load_chat("\"Hi! It's SO GOOD to see you!\" says the sexy attendant. \"If you need help just ask or you can 'browse' for what you like. Ok?!?\"\n");
  load_chat("The attendant models off her sexy underwear for a few customers.\n");
  load_chat("The attendant bubbles with excitement. BOING!!!!\n");  
}
