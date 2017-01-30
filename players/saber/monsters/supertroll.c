inherit "/obj/monster";

#include "/players/jaraxle/define.h"
object gold, sphere;

reset(arg) {
   ::reset(arg);
   if (!arg) {
      gold = clone_object("obj/money");
      gold->set_money(6000);
      move_object(gold,this_object());
      sphere = clone_object("/players/saber/closed/quest/items/sphere.c");
      move_object(sphere,this_object());
      set_name( "troll" );
      set_short("A Troll");
      set_alt_name("supertroll");
      set_race( "troll");
      set_long("A huge, wicked looking troll with large claws.\n"+
         "It appears to have a large 'S' rune carved into its chest.\n");
      set_frog(1);
      set_level(22);
      set_heal(5,30);
      set_ac(15);
      set_wc(25);
      set_hp(8000);
      set_al(-1000);
      set_aggressive(0);
      set_dead_ob(this_object());
      set_chat_chance(10);
      set_a_chat_chance(10);
      load_chat("The Troll looks at you.\n");
      load_chat("The Troll growls.\n");
      load_chat("The Troll flicks you off.\n");
      load_chat("The Troll tromps towards you.\n");
      load_chat("The Troll fingers its nose.\n");
      load_a_chat("The Troll laughs at you.\n");
      load_a_chat("The Troll shrugs off your attacks.\n");
      load_a_chat("The Troll stomps on your foot.\n");
      load_a_chat("The Troll yawns.\n");
      load_a_chat("The Troll slams its fist into you.\n");
      
      set_spell_mess1("SuperTroll "+HIR+"slams"+NORM+" his foe against the cavern wall!");
      set_spell_mess2("SuperTroll "+HIR+"slams"+NORM+" you against the cavern wall!");
      set_chance(10);
      set_spell_dam(35+random(16));
   }
}

monster_died()  {
   object ob;
   ob = clone_object("/players/saber/closed/quest/items/head.c");
   move_object(ob, this_object());
   return 0;
}

/* Additions by Jaraxle [6/10/03] */

hurt_me(){
   
   string ATT_NAME,msg;
   if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
   
   say("\nSuperTroll slams two fists into "+ATT_NAME+"'s chest.\n"+
      ATT_NAME+" crumples in pain!\n\n"+NORM);
   
   attacker_ob->hit_player(10+random(31));
}

hurt_me_more(){
   
   string ATT_NAME,msg;
   if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
   
   say("\nSuperTroll grabs "+ATT_NAME+" by the neck and lifts them off the ground.\n"+
      ATT_NAME+" gurgles and gasps for air.\n\n"+NORM);
   
   attacker_ob->hit_player(20+random(21));
}

heart_beat(){
   int i;
   ::heart_beat();
   
   if(attacker_ob){
      i = random(11);
      switch(i){
         
         case 0..2: hurt_me();
         break;
         
         case 3..4: hurt_me_more();
         break;
         
         case 5..10: return 0;
         break;
      }
   }
}

/* End additions - Jaraxle */

