inherit "/obj/monster";
#include "/players/beck/MortalKombat/MKQuestNPC.h" 

reset(arg) {
   ::reset(arg);
   if (!arg) {
object ob, ob2, gold;
gold = clone_object("/players/saber/gems/sapphire.c");
move_object(gold,this_object());
ob2 = clone_object("/players/saber/gems/ruby.c");
  move_object(ob2, this_object());
  ob = clone_object("/players/saber/weapons/2scimitars.c");
move_object(ob,this_object());
init_command("wield scimitar");
     set_name("The Dark One");
     set_alt_name("one");
     set_short("The Dark One");
     set_race( "demon");
     set_alias("dark");
     set_gender("creature");
     set_long("The Dark One is but a shadow.\n"+
        "It appears to have no form, but radiates an evil presence.\n"+
        "You get a bad feeling about this...\n");
     set_level(21);
     set_ac(18);
     set_wc(32);
     set_hp(525);
     set_al(-1000);
     set_aggressive(0);
     set_chat_chance(9);
     set_a_chat_chance(8);
     load_chat("The Dark One look at you and laughs.\n");
     load_chat("The Dark One glares at you.\n");
     load_chat("The Dark One says: Attack me and die.\n");
     load_chat("The Dark One whispers to himself.\n");
     load_a_chat("The Dark One howls.\n");
     load_a_chat("The Dark One yells: YOU WILL DIE!\n");
     load_a_chat("The Dark One summons flame.\n");
     add_spell("FIRE",
"The summoned fire burns you!\n\n",
"\n#MN# summons $HR$FIRE$N$!\n\n",
12,30,"other|fire",1);
/* 5% chance of a demon each hb is the same odds as one being summoned
   through the call_out method */
     add_spell("summon demon",
"","",5,0,0,0,"SUMMON");

/* converted to add_spell format - illarion dec 2004
     set_spell_mess2("The Dark One summons FIRE.\n");
     set_spell_mess1("The Dark One summons FIRE.\n");
     set_chance(12);
     set_spell_dam(30);

  call_out("check",15);
*/
  move_object(clone_object("/players/dragnar/MKScar/scar.c"),this_object()); 
   }
}

SUMMON()  {
  object demon;
  say("The Dark One gestures, and a minor demon steps forth from the circle.\n");
  demon = clone_object("/players/saber/monsters/mdemon.c");
  move_object(demon, environment(this_object()));
}

check()  {
  if((this_object()->query_attack()) && (random(20) < 5))  {
  SUMMON();
  call_out("check",15);
  return 1;
       }
  call_out("check", 15);
        }
