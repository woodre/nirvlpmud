#include <ansi.h>
inherit "obj/monster.c";
reset(arg) {
   ::reset(arg);
   if(!arg) {
      set_name("Shere Khan");
      set_alias("shere khan");
      set_alt_name("shere");
      set_short("Shere Khan, a huge tiger");
      set_long("Shere Khan is a huge African tiger. His stripes are bright\n"+
         "and prominent. He is stalking through the tall grass, just\n"+
         "waiting to pounce on his prey. His claws are drawn and\n"+
         "his teeth bared. He is searching the forest for Mowgli,\n"+
         "the man-cub.\n");
      set_aggressive(1);
      set_ac(21);
      set_wc(40);
      set_level(23);
      set_race("animal");
      set_hp(820);
      set_al(-1000);
      set_wc_bonus(24);
      set_chat_chance(10);
      load_chat("Shere Khan says: I'll find that man-cub yet.\n");
      set_chance(30);
      set_a_chat_chance(50);
      load_a_chat("Shere Khan sinks his teeth deep into your arm, ripping a piece of flesh out!\n");
      load_a_chat("Shere Khan claws at your face, shredding it to pulp!\n");
      set_spell_dam(90);
      set_spell_mess1("Shere Khan slashes into his enemy with his massive claws!\n");
      set_spell_mess2("Shere Khan slashes into you with his massive claws!\n");
   }
}

void
heart_beat()
{
    ::heart_beat();
     if(!random(3) && attacker_ob)
     {
       tell_object(attacker_ob, "\nShere Khan pounces on you!\n\tBlood pours from your scalp!\n\n");
       tell_room(environment(), "\nShere Khan pounces on " + attacker_ob->query_name() + "!\n\tBlood pours from " + possessive(this_player()) + " scalp!\n\n", ({ attacker_ob }));
       attacker_ob->hit_player(72);
     }
}

id(str) { return (::id(str) || str == "tiger"); }

monster_died()
{
    object gold;
    tell_room(environment(), "\n\tShere Khan falls to the ground with a last "+BOLD+"roar"+NORM+"...\n");
    tell_room(environment(), "\n\tYou spy a pile of gold coins upon the ground, near his corpse.\n\n");
    gold=clone_object("/obj/money");
    gold->set_money(4000+random(3000));
    move_object(gold, environment());
    move_object(clone_object("/players/bagera/weapons/verte_claw"), environment());
}
