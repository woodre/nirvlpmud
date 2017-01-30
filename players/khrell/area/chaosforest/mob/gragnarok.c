#include "/players/khrell/ansi.h"
#include "/players/khrell/define.h"
inherit "obj/monster";
reset(arg)  {
  object gold;
  ::reset(arg);
  if(arg) return;
  set_name("skargroth");
  set_short(HIK+"Skargroth the ancient shaggoth"+NORM+" ("+HIW+"lord of evil"+NORM+")");
  set_alias("shaggoth");
  set_race("shaggoth");
  set_long("The Shaggoth are an old race, rumored to be older then the great scaled\n"+
           "beasts known as dragons.  Posessing a centaur like body.  The lower half\n"+
           "scaled and with a long well muscled tail, the upper body resembles a great\n"+
           "ogre, thus giving the nickname of 'dragon-ogres'.  Skargroth here is no \n"+
           "exception.  It is old and large as their race continues to grow during their\n"+
           "near immortal and ageless lives.\n");
  set_hp(1000);
  set_level(25);
  set_al(-1200);
move_object(clone_object("/players/khrell/weapons/slayerofkings.c"));
init_command("wield sword");  
  set_wc(44);
  set_ac(25);
  set_heal(10,3);
  set_aggressive(1);

  set_chat_chance(3);
  set_a_chat_chance(15);
  load_chat("Skargroth grinds his fangs.\n");
  load_chat("Skargroth's eyes flare with hatred.\n");
  load_a_chat("You feel afraid of the creature before you.\n");

  set_chance(20);
  set_spell_dam(50);
  set_spell_mess1("Skargroth lashes out with his "+GRN+"great tail"+NORM+" at his attacker!\n");
  set_spell_mess2("The "+GRN+"great tail"+NORM+" \n"+
                  GRN+"|>>>>>                       <<<<<|"+NORM+"\n"+
                  "          <<<<"+HIR+"S L A M S"+NORM+">>>>        \n"+
                  GRN+"|>>>>>                       <<<<<|"+NORM+"\n"+
                  "           into                           \n"+
                  "                       you                \n"+
                  " and you can feel your"+HIW+" bones"+NORM+" crack and snap.\n");
  
   set_chance(10);
   set_spell_dam(150);
   set_spell_mess1("Skargroth summons forth a "+HIW+"Lightning "+HIB+"bolt"+NORM+"!\n"); 
   set_spell_mess2("            Skargroth ssmashes you with a......\n"+
                   "            great                  \n"+
                   "                                   \n"+
                   BLINK+HIW+"         L I G H T N I N G        "+NORM+"\n"+
                   HIB+"             B O L T"+NORM+" ! ! !\n");

  gold=clone_object("obj/money");
  gold->set_money(random(4000)+6000);
  move_object(gold,this_object());
}
