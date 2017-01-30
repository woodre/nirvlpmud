/* Crusader Knight found in /players/daranath/qualtor/gateway.c
   will be a major factor in my qualt'tor king quest.  -Dar */

/* Made simple changes to Crusader Knight to keep him in line with updated
   monster guide. Lowered level from 24 to 22, while kept wc and ac same. 
   Hp range now 750-830, guide suggests 700. Different items are same as
   before, just with changed names and some ansi...  01-30-02  -Dar */
/* Added spell attack of random(75)+25 pts.  Sick of seeing level 10 players
   kill the knight   02-23-02  -Dar */

#define ROOT "/players/daranath/qualtor/newstuff/"
inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

move_object(clone_object("/players/daranath/qualtor/newstuff/heals/red_wine.c"),this_object());
move_object(clone_object(ROOT+"obj/crusader_pl.c"),this_object());
move_object(clone_object(ROOT+"obj/crusader_sh.c"),this_object());
move_object(clone_object(ROOT+"obj/surcoat1.c"),this_object());
move_object(clone_object(ROOT+"weps/crusader.c"),this_object());
/* Total value after selling of 4050 gold, 2950 below guide */

     set_name("Crusader Knight");
     set_short("A knight leans heavily upon his shield");
     set_alias("knight");
     set_alt_name("crusader");
     set_race("human");
     set_gender("male");
     set_long("The human leans heavily upon his white shield bearing the red\n"+
              "cross of a holy crusade. The knight seems upset as he looks\n"+
              "over at the blackened remains of the keep within the city.\n"+
              "A beautiful sword hangs at his belt, alongside a bottle\n"+
              "of dark red wine, which helps him get over the depression\n"+
              "of his failed mission.\n");
     set_level(22);

     init_command("wield sword");
     init_command("wear platemail");
     init_command("wear coat");
     init_command("wear shield");

     set_ac(23);
     set_wc(40 + random(4));
     set_hp(750 + random(80));
     set_al(1000);
     set_aggressive(0);
     set_dead_ob(this_object());
     set_chat_chance(7);
     set_a_chat_chance(10);
     load_chat("Crusader Knight weeps for his failure to the king.\n");
     load_chat("The knight leans heavily upon his shield for support.\n");
     load_chat("Crusader Knight whispers: I shall avenge thee, my king...\n");
     load_a_chat("Crusader Knight takes his frustration out on you.\n");

set_chance(20);
set_spell_dam(random(75)+25);
set_spell_mess2("Crusader Knight salutes you, then cuts into you deeply with the Blade.\n");
set_spell_mess1("Crusader Knight salutes those who are about to die.\n");
   }
}

monster_died() {
write("\nCrusader Knight falls to one knee, bleeding from multiple wounds.\n"+
      "He slowly speaks: Forgive me, my King...\n\n"+
      "                       For I have failed thee...\n\n");
write_file("/players/daranath/closed/log/crusader_death",ctime(time())+"\t"+
  (this_object()->query_attack())->query_real_name()+"\t\t"+
  (this_object()->query_attack())->query_level()+"\n");
return 0;
}
