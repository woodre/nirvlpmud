/*
Mob History: [Added 7/26/2002]  Londros is a Rune lord in the Lunar Empire
for the subcult of the crimson bat.  The crimson Bat is a huge monster that requires
a vast about of food, Londros is on a hunting expidition to feed the Bat, if a player dies to Londros, londros will take the corpse and save it to feed to the Bat.  This is a very evil character who will feed himself to the bat if his god so desirerd.
17% chance of 35 damage
17% chance of 20 damage
17% chance of 75 damage
regains 17 hpts/hb on average
*/
inherit "/obj/monster";
#include "/players/jareel/define.h"

     int a;
     int L;
     int scimitar;
       reset(arg) {
     a = 3300;
       ::reset(arg);
         if (arg) return;
     set_name("londros");
     set_race("human");
     set_al(-1000);
     set_level(25);
     set_aggressive(0);
     set_hp(1000);
     MOCO("/players/jareel/general_stuff/londros_bag.c"),this_object());
     MOCO("/players/jareel/armor/chaos/crimson_cape.c"),this_object());
       init_command("wear misc");
     MOCO("/players/jareel/weapons/chaos/scarlet_scimitar.c"),this_object());
       scimitar = present("scimitar",this_object());
       scimitar->set_short(BOLD+MAG+"Scarlet Scimitar "+HIK+"[ "+BOLD+MAG+"Glowing "+HIK+"] "+NORM+RED+"[ "+CYN+" Energized"+RED+" ]"+NORM);
         init_command("wield scimitar");
     set_ac(25);
     set_wc(45);
     set_ac_bonus(17);
     set_wc_bonus(69);
     set_gender("male");
     set_dead_ob(this_object());
     set_short(
       "Londros - Feeder of the "+RED+"Crimson Bat"+NORM+" [ "+RED+"Seven Mothers "+NORM+"] (lord of evil)");
     set_long(
       "Londros has a chaotic twinkle in his eyes.  Having years of\n"+
       "battles under his belt, his flowing red hair is starting to\n"+
       "gray.  He stands in a crimson aura from which he seems to draw\n"+
       "energy. His cold stare chills you to the bone as he catches\n"+
       "you looking at him.\n");
     set_chance(40);
     set_spell_mess1(
       "Londros focuses his mental energy.\n");
     set_spell_mess2(
       "Londros slams you with a mental blast of Energy.\n");
     set_heal(3,2);
     set_spell_dam(50);
     set_chat_chance(10);
       load_chat(
         "Londros says: 'The skeleton king is around here somewhere.'\n");
       load_chat(
         "Londros says: 'This realm is vast but secrets lie all around.'\n");
       load_chat( 
         "Londros says: 'The Sembrak will make a good meal for the Crimson Bat.'\n");
       load_chat(
         "Londros says: 'You will make a good meal for the Crimson Bat.'\n");
       load_chat(
         "Londros says: 'I found the "+BOLD+"pass"+NORM+" into the chaos woods.....Hmmm.'\n");
       load_chat(
         "Londros says: 'If you want to buy a heal its 3300 coins.'\n");
}

     heart_beat(){
       object       ob;
         ::heart_beat();
         corpse_loop();
         if(attacker_ob) {
           L = random(6);
             if(attacker_ob){
             if(L == 0) L_allied();      /* 175 - 1/3 .34 x 175 = 60*/
             if(L == 1) L_lune();        /*  35 - 1/6 .17 x 35 = 6*/
             if(L == 2) L_heal();        /*  50 - 1/3 .34 x 50 = 17*/
             if(L == 3) L_heal();        /*  50 */
             if(L == 4) L_allied();      /* 175 */
             if(L == 5) L_bladesharp();  /*  20 - 1/6 .17 x 20 = 3 */
}
}
}

     L_lune()  {
       if(environment(attacker_ob) != environment()) return; /* Fred [11/5/04] */
       tell_room(environment(TO),
         "Londros releases...\n"+
         "          a wave of power from\n"+
         "                 his "+BOLD+MAG+"Scarlet Scimitar\n"+NORM);
           call_other(attacker_ob,"hit_player",random(10)+30);
       return;
}

     L_heal() {
       tell_room(environment(TO),
         "Londros takes something from his bag.\n"+
         "Londros is engulfed buy a "+RED+"Crimson aura"+NORM+".\n");
           heal_self(50);
       return;
}

     L_bladesharp() {
       if(environment(attacker_ob) != environment()) return; /* Fred [11/5/04] */
       tell_room(environment(TO),
         "Londros casts a bladesharp spell over his blade.\n"+
         "\n"+
         "    "+BLINK+CYN+" E N E R G Y "+NORM+" flows over the blade.\n"+
         "\n");
           call_other(attacker_ob,"hit_player",random(30)+5);
       return;
}

     L_allied()  {
       if(environment(attacker_ob) != environment()) return; /* Fred [11/5/04] */
       tell_room(environment(TO),
         "Londros summons a spirit from his "+BOLD+MAG+"Scarlet Scimitar.\n"+
         ""+NORM+BOLD+"\n"+
         "        An enraged Spirit slashes at "+attacker_ob->query_name()+".\n"+
         ""+NORM+"\n");
         attacker_ob->hit_player(random(50)+150, "other|jareel");
       return;
}
/* by verte */
     corpse_loop()    {
       object ob;
         if((ob = present("corpse", environment())) && (int)ob->is_corpse()) {
           tell_room(environment(),
             "Londros takes: "+(string)ob->short()+".\n");
             move_object(ob, this_object());
     corpse_loop();
  }
}

     monster_died() {
       scimitar->reset();
         return 0;}

     init() { 
       ::init(); 
         add_action("heals","buy");
}

     heals(arg) {
       if(!arg) { return 0; }
       if(arg == "heal" || arg == "heals") {
       if(!this_player()->add_weight(1)) {
         write("Londros says: Lighten your load.\n");
           return 1; }
       if(this_player()->query_money() < a) {
         write("Londros says: You lack the money for the heal\n");
           return 1; }
       TP->add_money(-a);
         write("Londros takes your coins mutters a few words, the coins turn into a heal.\n");
         say(TPN+" buys a heal from Londros.\n");
         MOCO("/players/jareel/heals/aura.c"),TP);
           return 1; }
}
