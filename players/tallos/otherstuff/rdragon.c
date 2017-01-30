inherit "/obj/monster";
#include "/players/saber/closed/ansi.h"

reset(arg) {
   ::reset(arg);
   if (!arg) {

  object ob, ob2, gold;

ob = clone_object("/players/saber/armor/dragonarmor.c");
ob2 = clone_object("/players/saber/closed/bards/palsword.c");
gold = clone_object("obj/money");
/* Changed from 1000 to 10,000. -Feldegast 5-31-01 */
gold->set_money(8000+random(4000));
move_object(gold,this_object());
move_object(ob,this_object());
move_object(ob2,this_object());
/* Why would a dragon be wearing armor? - Felde 5-31-01
init_command("wear scale");
*/

     set_name( "Ranzarak" );
     set_short("Ranzarak, Lord of the Red Dragons");
     set_alias("ranzarak");
     set_race( "dragon");
     set_alt_name("red dragon");
     set_gender("creature");
     set_heal(5,25);
     set_long("Ranzarak is a Red Dragon of gargantuan size.  His scales are as tough as\n"+
       "ore from the Mountain of Iron, and his claws as sharp as Death's own scythe.\n");
     set_level(21);
     set_ac(27);
     /* Red Dragons are strong against fire but weak against ice
       - Illarion Dec 2004
     */
     set_armor_params("other|fire",0,100,0); /* No fire damage */
     set_armor_params("other|ice",0,-100,0);   /* Double ice damage */
     set_wc(60);
     set_hp(2000);
     set_al(-950);
     set_aggressive(0);
     set_dead_ob(this_object());
     set_chat_chance(7);
     set_a_chat_chance(13);
     load_chat("The Red Dragon watches you with hungry eyes.\n");
     load_chat("The Red Dragon licks its lips.\n");
     load_chat("The Red Dragon whispers \"\Mortal, are you to be my snack?\"\n");
     load_chat("The Red Dragon extends its claws.\n");
     load_a_chat("The Red Dragon ROARS!!!\n");
     load_a_chat("The Red Dragon lashes you with its tail.\n");
     load_a_chat("The Red Dragon stamps at you with a HUGE foot.\n");
     load_a_chat("The Red Dragon bites you.\n");
     load_a_chat("The Red Dragon uses its wings to bash its foe.\n");
     load_a_chat("The Red Dragon exhales a cloud of smoke.\n");
     /* Updated fire attack to use add_spell
       - illarion Dec 2004 */
     add_spell("fire breath",
"The $HR$flame$N$ burns you!\n",
"#MN# BREATHES$HR$\n"+
"   *******************************************************************\n"+
"  *****************************  F L A M E  ***************************\n"+
"   *******************************************************************$N$\n",
15,"1d100+120","other|fire",1);

   }
}

monster_died()  {
object ob;
  if(environment(this_object()))
{
  tell_room(environment(this_object()),
   "\nRanzarak, Lord of the Red Dragons staggers, and falls to the ground.\n\n"+
   "The ghost of the Red Dragon soars off into the sky.\n\n");
  tell_room(environment(this_object()),
   "\nRanzarak thunders \"\You have not seen the last of me.  I shall return!\"\n\n");
  ob = clone_object("/players/saber/monsters/hero/statue.c");
  ob->set_id("dragon");
  ob->set_short("A statue of Ranzarak, Lord of the Red Dragons");
  ob->set_long("A statue of the great Dragon Lord know as Ranzarak.\n");
  move_object(ob,environment(this_object()));
}
  return 0;
        }

/* Removed HB version of spell - Illarion Dec 2004 */