inherit "obj/monster.c";
#include "/players/persephone/rooms.h"
reset (arg){
 object boot;
 object club;
 ::reset(arg);
  if(!arg){
   object gold;
   gold = clone_object("obj/money");
   gold->set_money(3500+random(1500));
   move_object(gold, TOB);
   boot = clone_object("players/persephone/armour/entsho");
   move_object(boot, TOB);
   init_command("wear boots");
   club = clone_object("players/persephone/weapon/entclub");
   move_object(club, TOB);
   init_command("wield club");
   set_name("fanghorn");
   set_alias("ent");
   set_alias("treebeard");
   set_short("Fanghorn the Ent Commander");
   set_long("Fanghorn is the leader and strongest of the Ents. His skin looks like\n" +
            "the bark of a tree and you can tell that he is both tough and strong.\n" +
            "Indeed you feel looking at him that if you irritate him he could\n" +
            "crush you in his bare hands.\n");
   set_level(20);
   set_wc(30);
   set_ac(17);
   set_hp(500);
   set_al(450);
   set_aggressive(0);
   set_gender(0);
   set_chance(20);
   set_spell_dam(40);
   set_spell_mess1("Fanghorn opens his arms and says: Die foul creatures");
   set_spell_mess2("Fanghorn embraces you in a bear hug");
  }
}
second_life(){
 ::second_life();
  write("Fanghorn falls dead on top of you. It feels like he has\n" +
        "crushed your body\n");
 say("Fanghorn falls down on "+attacker_ob->query_name() + " crushing him as he dies\n");
  attacker_ob->hit_player(20+random(30));

}
