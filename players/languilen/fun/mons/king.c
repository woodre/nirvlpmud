#include "/players/languilen/closed/ansi.h"
#include "../paths.h"
#define TP this_player()
inherit "obj/monster.c";

reset(arg)  {
   int i;
   ::reset(arg);
   if(arg) return;

   set_name("the champ");
   set_alias("kid");
   set_alt_name("champ");
   set_race("human");
   set_short("The Champ -King of the Hill-");
   set_long(
"The reigning King of the Hill.  He's here to defend his title.\n");

   i=TP->query_level()+6;
   if(i>11) i = 11;
   set_level( i );
   set_hp( i * 15 );
   set_al( -50 );
   set_aggressive(0);
   set_dead_ob(this_object());

   set_chat_chance(5);
      load_chat("The champ says 'You'll never be King!' \n");
   set_a_chat_chance(5);
      load_a_chat("The champ says 'Get off my hill!' \n");

   set_chance(5);
   set_spell_dam(10);

   set_spell_mess1(
      "The king kicks his attacker! \n");
   set_spell_mess2(
      "The king kicks you in the chest! \n");

   add_money(200);

   if(!present("pugil",this_object())) {
      move_object(clone_object(OBJ+"pugil.c"),
      this_object()); 
   }
   init_command("wield pugil");
   if(!present("pads",this_object())) {
      move_object(clone_object(OBJ+"sppads.c"),
      this_object()); 
   }
   init_command("wear pads");
   if(!present("helmet",this_object())) {
      move_object(clone_object(OBJ+"sphelm.c"),
      this_object());
   }
   init_command("wear helmet");
   set_wc( 16 );
   set_ac( 12 );
}

monster_died() {
   TP->set_title("The "+HIW+"King of the Hill"+NORM+"");
   TP->save_me();
   tell_room(environment(this_object()),
      TP->query_name()+" is the new "+HIW+"King of the Hill"+NORM+"!!! \n");
   return 0;
}

