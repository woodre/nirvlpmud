/* Robin Williams */

#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */

inherit "/obj/monster.c";

reset(arg)
{
  ::reset(arg);
  if (!arg)
  {
    object gold,shell,spear;
    gold = clone_object("obj/money");
    gold->set_money(random(200) + 500 );
    move_object(gold,this_object());
    shell = clone_object("/players/aingeal/casino/armor/shell_helmet.c");
    move_object(shell,this_object());
    spear = clone_object("/players/aingeal/casino/weapons/spear.c");
    move_object(spear,this_object());
  }
  set_name("robin");
  set_alias("williams");
  set_alt_name("entertainer");
  set_short("Robin Williams");
  set_race("human");
  set_long("Robin Williams poses melodramatically as he surveys the audience,\n\
his broad grin comical in itself.  He is dressed in loose black\n\
dockers and a collared silk shirt decorated with a loud tropical\n\
pattern in shades of blue.  For some unfathomable reason, he has\n\
donned the tortoise shell helmet from his hit movie 'Jumanji', \n\
and is toting a homemade-looking bamboo spear, both of which\n\
he obviously intends to use in his next skit.\n");
  set_level(17);
  set_ac(12 + random(2));
  set_wc(23 + random(3));
  set_hp(330 + random(20));
  set_al(-100);
  set_aggressive(0);
  set_chat_chance(10);
  set_a_chat_chance(25);
  set_chance(10);
  set_spell_mess1("\n\tRobin's face contorts with rage as he SHOUTS\n\
\n\tan incoherent phrase!\n");
  set_spell_mess2("\n\tRobin bounds over to you, his face contorted into\n\
\n\ta mask of rage as he SHOUTS an incoherent phrase at you!\n\
\n\tYou feel suddenly weaker!\n");
  set_spell_dam(25);
  load_chat("Robin bounds across the stage with an excess of energy!\n");
  load_chat("Robin quips, 'Cocaine is God's way of saying you're making\n\
too much money!'\n");
  load_chat("Robin grins as he says: When the media ask George W. Bush a\n\
question, he answers 'Can I use a lifeline?'\n");
  load_chat("Robin leaps into the air as he exclaims, 'Spring is nature's\n\
way of saying LET'S PARTY!'\n");
  load_chat("Robin quips, 'If it's the Psychic Network, why do they need\n\
a phone number??'\n");
  load_a_chat("Robin scowls at you as he dodges out of your way!\n");
  load_a_chat("\n\tRobin lunges menacingly with his spear as he shouts,\n\
\n\t"+RED+"J"+YEL+"U"+MAG+"M"+BLU+"A"+GRN+"N"+WHT+"J"+CYN+"I"+NORM+"!\n");
  load_a_chat("Robin launches his spear into the fray!\n");
  load_a_chat("Robin swings his spear at your head like a quarterstaff!\n");
}

