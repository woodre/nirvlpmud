#define tp this_player()->query_name()
inherit "players/mythos/amon/forest/monster1";
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("orochi");
  set_alias("yamato");
  set_race("serpent");
  set_short("Yamato-no Orochi");
  set_long("A great white serpent- 100 meters long.\n"+
            "Its eight heads glare at you with blood red\n"+
            "eyes.  Legend has told of a sword hidden within\n"+
            "the snake....\n");
  set_hp(900);
  set_level(21);
  set_al(-750);
  set_wc(35);
  set_ac(20);
  set_heal(8,15);
  set_aggressive(1);
  
  set_dead_ob(this_object());

  set_chat_chance(2);
  set_a_chat_chance(35);
  load_chat("The Orochi glares at you!\n");
  load_chat("Ssssssssssss\n");
  load_a_chat("A head of the Great Serpent rears back and speeds in for"+
  " an attack!\n");   
  load_a_chat("The Orochi's tail twitches.\n");

  set_chance(35);
  set_spell_dam(85);
  set_spell_mess1("The tail of the Orochi slams into is foe!\n");
  set_spell_mess2("The tail of the Orochi slams into you!\n");

  set_mult(8);
  set_mult_chance(45);
  set_mult_dam1(15);
  set_mult_dam2(10);

}

monster_died() {
object ob;
ob=clone_object("/players/mythos/amisc/forest/tail.c");
  move_object(ob,this_object());
return 0;
}

#include "/players/mythos/amon/hb_ag.h"
