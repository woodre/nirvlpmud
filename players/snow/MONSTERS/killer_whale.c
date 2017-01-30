/*
A vicious Killer Whale.
*/
 
#define MEATN capitalize(this_object()->query_attack()->query_name())
inherit "/obj/monster";
 
reset(arg) {
   ::reset(arg);
   if (!arg) {

  object ob;
  int R;
  string shortdesc;

R = random(3);
  if(R == 0) shortdesc = "A furious Killer Whale";
  if(R == 1) shortdesc = "A fearsome Killer Whale";
  if(R == 2) shortdesc = "A powerful Killer Whale";

  ob = clone_object("/players/snow/heals/kw_meat");
  ob->set_meat_value(random(50)+25);
  move_object(ob,this_object());

 
     set_name("killer whale");
     set_short(shortdesc);
     set_race("whale");
     set_alias("orca");
     set_long(
"A huge creature with razor-sharp teeth. Beware the hungry Orca in the surf!\n");
     set_level(18);
     set_ac(6);
     set_wc(random(15)+20);
     set_hp(random(80)+250);
     set_heal(1,1);
     set_al(0);
     set_aggressive(1);
     set_chat_chance(7);
     set_a_chat_chance(10);
     load_chat("The Killer Whale swims rapidly around you!\n");
     load_a_chat("The water churns with slashing teeth!\n");
set_chance(15);
set_spell_mess1("The Killer Whale smashes its foe with its tail!\n");
set_spell_mess2("The Killer Whale smashes you with its tail!\n");
set_spell_dam(30);
   }
}
