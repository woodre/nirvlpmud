inherit "obj/monster";
#include "definitions.h"


int one;
int talk;


id(str) { return str == "ebudee" || str == "wytch"; }


reset(arg)
{
  object gold;

  one = 0;
  talk = 0;

  ::reset(arg);
  if(arg) return;
  set_name("Ebudee");
  set_race("wytch");
  set_alias("wytch");
  set_short("Ebudee, the Nature Wytch");
  set_long(
"     Ebudee is a small elderly woman. Wrinkles cover every part of\n"+
"her wise face. She is dressed in a tattered green shawl. Sticks of\n"+
"wood poke out of her hair.\n");
  set_level(16);
  set_hp(300);
  set_al(0);
  set_wc(17);
  set_ac(5);
  enable_commands();
  set_chance(40);
  set_spell_dam(random(30)+5);
  set_spell_mess1("&&**Ebudee casts a spell of Magik'Threat against you.");
  set_spell_mess2("&&**Ebudee causes you to suffer in mystical pain.");
  set_chat_chance(15);
  load_chat("Ebudee gathers some swamp herbs.\n");
  load_chat("Ebudee says: Oh how the days work on my poor back...\n");
  load_chat("Ebudee plays with some frogs.\n");
  gold=clone_object("obj/money");
  gold->set_money(random(1000)+500);
  move_object(gold,this_object());
}


catch_tell(string str)
{
  string msg;

  str = lower_case(str);

  if(sscanf(str,"%scities%s",msg) ||
     sscanf(str,"%scity%s",  msg))
  {
    if (talk == 0)
    {
      tell_object(this_player(), 
"Ebudee tells you:\n"+
"     So... the Sithi Cities you say?!\n"+
"Mugwort! Mugwoooort! What is it then? Yes dear, sleep more.\n"+
"There are seven such cities, yes, yes. Each one to a phase\n"+
"of the moon it corresponds. Exactly. But, one city corresponds\n"+
"to all but one phase... Enki-o Shao'saye, once the greatest of\n"+
"Sithi Cities. Now barely rubble. Mugwoooort! Time for a story.\n"+
"     You see, the Lord of Shao'saye is not in Shao'saye!\n"+
"Desnon schemes with Smaeonte in Jao-e Tinukai'i. So, it is only\n"+
"six Sithi Cities that you must find if you wish to find all the\n"+
"Sithi Lords. But no! I can read your mind... you must also seek\n"+
"the Sithi Diagram! So, Shao'saye you must eventually go.\n"+
"     Remember, Shao'saye appears on all but the darkest moon!\n"+
"And unlike its sisters, Shao'saye always appears in the same place.\n"+
"That's a good girl. Oh deary, I didn't mean you Mugwort!\n"+
"     Now I am tired and I must go.\n"+
"     I must sleep for another day.\n"+
"     .... Before death do I pay.\n");
      remove_chat("Ebudee gathers some swamp herbs.\n");
      remove_chat("Ebudee says: Oh how the days work on my poor back...\n");
      remove_chat("Ebudee plays with some frogs.\n");
      talk = 1;
    }
    else
    {
      tell_object(this_player(),
"Ebudee is fast asleep. She cannot talk to you now.\n");
    }
    return 1;
  }
  return 1;
}
