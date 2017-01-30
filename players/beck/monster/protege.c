inherit "/obj/monster.c";
#include "/players/beck/rangers/Defs.h"
#include "/players/beck/MortalKombat/MKQuestNPC.h"

reset(arg)
{
   ::reset(arg);
   if(arg) return;
   if(!present("avenger", this_object())){
      move_object(clone_object("/players/beck/weapon/holy_avenger.c"), this_object());}
   move_object(clone_object("/players/dragnar/MKScar/scar.c"),this_object());
   set_name("protege");
   set_race("human");
   set_alias("protege");
   set_gender("male");
   set_short("Protege, the Guardian of the Paladins");
   set_long("Protege is the sentry for the paladin guild of Nirvana\n"+
      "Protege died on January 26, 1995 when he was shot 4 times.\n"+
      "He was had stepped in to help 2 women who were being robbed,\n"+
      "and most likely raped by 8 gang members.\n"+
      "He so happened to be the western-Tennessee kickboxing champion and\n"+
      "in the fight, he killed 2 members, while 4 others died later from injuries.\n"+
      "Now his spirit serves as guidance for all Paladin's, as he made the\n"+
      "ultimate sacrifice for what was right.\n"+
      "");
   set_level(18);
   set_al(2000);
   set_hp(5000);
   set_wc(30);
   set_ac(30);
   set_chance(25);
   set_spell_dam(20);
   set_spell_mess1("");
   set_spell_mess2("");
   /* I've added this to more accurately reflect the difficulty of the monster.
      There is little risk of this killing a player, so it should not be worth as much
   as it is currently. -Feldegast 7/12/00 */
   set_hp_bonus(-2000);
   set_aggressive(0);
   set_chat_chance(10);
   set_a_chat_chance(7);
   load_chat("Protege says: To be a Paladin you must be willing to\n"+
      "sacrifice everything in order to help others.\n");
   load_chat("Protege says: Paladins are the protectors of truth and justice\n");
   load_chat("Protege says: Legends are not created by words, but by actions.\n");
   load_chat("Protege recites: Take a look at the world we've come to know,\n"+
      "Does it seem much more than a crazy circus show?\n"+
      "But maybe from the madness,\n"+
      "Something beautiful will grow.\n");
   set_armor_params("magical",10,0,0);
}

init(){
   ::init();
   if(COMM){
      COMM->TrainRangerSkill("armor",4,"beck","Protege",75);
   }
   /*  Added to make cheating a little less easy - 7/24 Eurale  */
   /*
   add_action("No_way","insanity");
   add_action("No_way","symbol");
   */
}

No_way() {
   write("Protege laughs in your face!\n");
   return 1; }


set_wc(x){
   if(this_player()) /* added 6.13.01 by verte */
      if(this_player() != this_object()){
      this_player()->hit_player(30,"magical");
      return;
   }
   ::set_wc(x);
}

calculate_worth() {
   int worth;
   worth = ::calculate_worth();
   if(worth < 0) worth = 0;
   return worth;
}
