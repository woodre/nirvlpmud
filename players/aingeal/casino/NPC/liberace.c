/* Liberace */

#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */

inherit "/obj/monster.c";

reset(arg)
{
  ::reset(arg);
  if (arg)
  {
    object g2;
    /* The ring is armor worth about 1500 */
    move_object(clone_object("/players/aingeal/casino/armor/lring.c"),
                this_object());
  }
  set_name("liberace");
  set_alias("Liberace");
  set_alt_name("entertainer");
  set_short("Liberace");
  set_race("human");
  set_long("Liberace wears a brilliant smile only a shade less bright\n\
than the thousands of tiny points of light reflected by the\n\
diamond-encrusted designs on his pastel blue dinner jacket.\n\
Elaborate candelabras grace the white baby grand piano\n\
at his fingertips.  He simpers ingratiatingly at the audience\n\
as he announces his next number.\n");
  set_level(22);
  set_ac(16 + random(2));
  set_wc(32 + random(5));
  set_hp(550 + random(100));
  set_al(-500);
  set_aggressive(0);
  add_money(random(501) + 5000);
  set_chat_chance(10);
  set_a_chat_chance(25);
  set_chance(20);
  set_spell_mess1("Liberace reaches over to his piano and plays a STRIDENT CHORD!\n");
  set_spell_mess2("Blood pours from your ears as Liberace's STRIDENT CHORD cuts into you with the sharpness of a blade!\n");
  set_spell_dam(50);
  /* Regular chats */
  load_chat("Liberace simpers, 'Have you met my brother, George?'\n");
  load_chat("Liberace pounds out a strident chord, then \n\
pauses dramatically to smile at you.\n");
  load_chat("Liberace struts around the stage, showing off his\n\
newest jewel-encrusted ensemble.\n");
  load_chat("Liberace leans over the stage and holds out his hands\n\
to proudly display his myriad of gaudy, obscenely \n\
expensive diamond rings.\n");
  load_chat("Liberace launches into a spirited rendition of Korsakov's\n\
'Flight of the Bumblebee' on his baby grand.\n");
  load_chat("Liberace pauses to wink playfully at the audience.\n");
  load_chat("Liberace pauses dramatically over the keyboard of his\n\
baby grand, then caresses the ears of the audience with\n\
the soothing strains of 'Moonlight Sonata'.\n");
  load_chat("Liberace smiles out into the audience as he says,'\n\
'I'm so happy that my mother can be here tonight.\n\
Mother, will you please stand up?  This is my mother.'\n");
  /* Combat chats */
  load_a_chat("Liberace shrieks, 'Take that, you brute!'\n");
  load_a_chat("Liberace punches you, huge diamond rings glittering\n\
as they descend toward your face.\n");
  load_a_chat("Liberace screams like a woman as he rushes at you\n\
to tackle you with his considerable weight.\n");
  load_a_chat("Liberace backhands you across the face, leaving\n\
a line of bloody scratches from his diamond rings.\n");
  load_a_chat("Liberace wails, 'I'll get you, you big meanie!'\n");
  set_dead_ob(this_object());
}

/*  Liberace will summon George when he dies. George is aggressive, but a lower level than Liberace.*/

monster_died(ob)
{
  write("\n\tLiberace screams in his death throes,\n\
\t\t'AVENGE me, George!'\n\n");
  tell_room(environment(),
            "\n\tWith a primal ROAR, Liberace's brother George\n\
\t\tleaps from the orchestra pit onto the stage!\n");
  move_object(clone_object("/players/aingeal/casino/NPC/george.c"));
}


