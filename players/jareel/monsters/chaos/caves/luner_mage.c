/*
Mob History: [Added 3/18/2008]  Olimite is a Rune Mage in the Lunar Empire
for the subcult of the crimson bat.
*/
inherit "/obj/monster";
#include "/players/jareel/define.h"

     int a;
     int L;
     int staff;
       reset(arg) {
     a = 3300;
       ::reset(arg);
         if (arg) return;
     set_name("olimite");
     set_race("human");
     set_al(-1000);
     set_level(25);
     set_aggressive(1);
     set_hp(1000);
     MOCO("/players/jareel/general_stuff/londros_bag.c"),this_object());
     MOCO("/players/jareel/armor/chaos/crimson_cape.c"),this_object());
       init_command("wear misc");
     MOCO("/players/jareel/weapons/chaos/scarlet_scimitar.c"),this_object());
       staff = present("scimitar",this_object());
       staff->set_short(BOLD+MAG+"Scarlet Scimitar "+HIK+"[ "+BOLD+MAG+"Glowing "+HIK+"] "+NORM+RED+"[ "+CYN+" Energized"+RED+" ]"+NORM);
         init_command("wield scimitar");
     set_ac(90);
     set_wc(15);
     set_gender("male");
     set_dead_ob(this_object());
     set_short(
       "Acolite Olimite - Order of the Crater Makers [ "+RED+"Seven Mothers "+NORM+"] (lord of evil)");
     set_long(
       "Olimite has a chaotic twinkle in his eyes.  His skin worn and\n"+
       "leathery from the cosmic powr he has unleashed.  His arcane\n"+
       "robe adorns the mark of chaos and the luner empire.  His staff\n"+
       "radiates power and a soft glow.  He is not a man to be taken\n"+
       "lightly.\n");
 
    set_chance(90);
     set_spell_mess1(
       "Olimite focuses darkness, unleashing a blast of energy.\n");
     set_spell_mess2(
       "Olimte blasts you with a beam of focused darkness.\n");
     set_heal(3,2);
     set_spell_dam(75);
     set_chat_chance(10);
       load_chat(
         "Olimite says: 'The skeleton king is around here somewhere.'\n");
       load_chat(
         "Olimite says: 'This cavern is vast but secrets lie all around.'\n");
       load_chat( 
         "Olimite says: 'The Trolls will make a good meal for the Crimson Bat.'\n");
       load_chat(
         "Olimite says: 'You will make a good meal for the Crimson Bat.'\n");
       load_chat(
         "Olimite says: 'If you want to buy a heal its 3300 coins.'\n");
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
       if(environment(attacker_ob) != environment()) return; 
       tell_room(environment(TO),
         "Olimite cracks his staff into the ground...\n\n"+
         "          "+BOLD+"~C~R~A~C~K~\n\n"+
         "                 Chaos is Unleashed!\n"+NORM);
           call_other(attacker_ob,"hit_player",random(40)+30);
       return;
}

     L_heal() {
       tell_room(environment(TO),
         "Olimite takes something from his bag.\n"+
         "Olimite is engulfed buy a "+RED+"Crimson aura"+NORM+".\n");
           heal_self(100);
       return;
}

     L_bladesharp() {
       if(environment(attacker_ob) != environment()) return; 
       tell_room(environment(TO),
         "Olimite charges his staff.\n"+
         "\n"+
         "    "+BLINK+CYN+" E N E R G Y "+NORM+" flows over the staff.\n"+
         "\n");
           call_other(attacker_ob,"hit_player",random(30)+5);
       return;
}

     L_allied()  {
       if(environment(attacker_ob) != environment()) return; /* Fred [11/5/04] */
       tell_room(environment(TO),
         "Olimite summons a spirit from his "+BOLD+RED+"Crimson Staff.\n"+
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
       staff->reset();
         return 0;}

     init() { 
       ::init(); 
         add_action("heals","buy");
}

     heals(arg) {
       if(!arg) { return 0; }
       if(arg == "heal" || arg == "heals") {
       if(!this_player()->add_weight(1)) {
         write("Olimite says: Lighten your load.\n");
           return 1; }
       if(this_player()->query_money() < a) {
         write("Olimite says: You lack the money for the heal\n");
           return 1; }
       TP->add_money(-a);
         write("Olimite takes your coins mutters a few words, the coins turn into a heal.\n");
         say(TPN+" buys a heal from Olimite.\n");
         MOCO("/players/jareel/heals/aura.c"),TP);
           return 1; }
}
