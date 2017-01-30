/* George Carlin */

#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */

inherit "/obj/monster";

reset(arg)
{
  ::reset(arg);
  if (!arg)
  {
    object gold;
    gold = clone_object("obj/money");
    gold->set_money(random(1000) + 3000);
    move_object(gold,this_object());
    set_name("george");
    set_alt_name("carlin");
    set_alias("entertainer");
    set_short("George Carlin");
    set_race("human");
    set_long("George Carlin studies his audience with wild-eyed intensity,\n\
his cragged face decorated with a slightly scruffy greying\n\
beard and mustache.  He is almost spectrally thin, his whip-\n\
cord appearance emphasized by the severity of the tight \n\
ponytail holding his long, greying hair back from his face.\n");
    set_level(19);
    set_ac(13 + random(3));
    set_wc(23 + random(5));
    set_hp(400 + random(50));
    set_al(-1000);
    set_aggressive(0);
    set_chat_chance(15);
    set_a_chat_chance(25);
    set_chance(10);
    set_spell_mess1("\n\tGeorge " + RED + "SEARS" + NORM +
      " his opponent to the bone\n\\n\twith his " + RED + 
      "BURNING" + NORM + " cynicism!\n");
    set_spell_mess2("\n\tGeorge " + RED + "SEARS" + NORM +
      " you to the bone\n\\n\twith his " + RED + "BURNING" + NORM +
      " cynicism!\n");
    set_spell_dam(40);
    load_chat("George quips, 'Call me!  I'll give ya somethin' \n" +
      "to put in your mouth!'\n");
    load_chat("George muses, 'There oughta be at least one round state.'\n");
    load_chat("George complains, 'When is this $@%& gonna be outlawed?!'\n");
    load_chat("George stalks across the stage as he launches \n"+
      "into another lengthy diatribe.\n");
    load_chat("George explains, 'There are seven words you can't say on television...'\n");
    load_a_chat("George shouts, '@%#%  &@%$^ #@$&!!'\n");
    load_a_chat("George cuts you deeply with his sharp sarcasm!\n");
    load_a_chat("George sucker punches you in the jaw!\n");
    load_a_chat("George hits you hard below the belt!\n");
  }
}

