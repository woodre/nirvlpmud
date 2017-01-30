inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

  object ob, ob2, gold;

ob = clone_object("/players/saber/armor/chaosarmor.c");
move_object(ob,this_object());
ob2 = clone_object("/players/saber/weapons/hspear.c");
move_object(ob2,this_object());
init_command("wield spear");
init_command("wear armor");

     set_name( "Yuki-Onna" );
     set_short("Lady Yuki-Onna the Anti Paladin");
     set_alias("yuki");
     set_race( "spirit");
     set_alt_name("paladin");
     set_gender("female");
     set_heal(5,25);
     set_long("Lady Yuki-Onna is a woman with skin the color of a smooth, white silk.\n"+
"Her long black hair flows freely down her back, and her blazing eyes of\n"+
"ebony black fill you with a sense of icy terror.\n");
     set_level(21);
     set_ac(17);
     /* an anti-paladin should be strong against evil but vulnerable to good
        note that her armor partially makes up for this vulnerability */
     set_armor_params("other|good",-15,0,0);
     set_armor_params("other|evil",15,0,0);
     set_wc(38);
     set_hp(755);
     set_al(-950);
     set_aggressive(0);
     set_dead_ob(this_object());
     set_chat_chance(7);
     set_a_chat_chance(10);
     load_chat("Yuki-Onna glares at you with eyes full of hate.\n");
     load_chat("Yuki-Onna smiles faintly.\nYou feel a chill pass through your soul.\n");
     load_chat("Yuki-Onna whispers to her spear.\n");
     load_chat("Yuki-Onna watches you with her eyes of cold fury.\n");
     load_chat("Yuki-Onna waits for you to attack her so she may kill you.\n");
     load_a_chat("Yuki-Onna punches you with a spiked gauntlet.\n");
     load_a_chat("Yuki-Onna glares at you.\n");
     load_a_chat("Yuki-Onna parries your attack.\n");
     load_a_chat("Yuki-Onna casts a spell.\n");
     load_a_chat("Yuki-Onna stabs you.\n");
     load_a_chat("Yuki-Onna kicks you in the groin.\n");
     add_spell("unholy_word",
"You reel in pain from the force of #MN#'s voice.\n\n",
"\n#MN# whispers an UNHOLY WORD.\n\n",
15,"1d50+50","other|evil",1);
/* Replaced with add_spell above
     set_spell_mess1("\nYuki-Onna whispers an UNHOLY WORD.\nYou reel in pain.\n\n");
     set_spell_mess2("\nYuki-Onna whispers an UNHOLY WORD.\nYou reel in pain.\n\n");
     set_chance(15);
    set_spell_dam(50 + random(50));
*/
     set_ac_bonus(12); /* Bonus for freeze attack. Feldegast 7-24-01 */
     call_out("freeze_player",10);
   }
  }

monster_died()  {
object ob;
  tell_room(environment(this_object()),
  "\nYuki-Onna gasps, and chokes blood as she slumps to the ground.\n\n"+
  "Two dark figures with large wings materialize and grab her ghost,\n"+
  "dragging Yuki-Onna kicking and screaming down into the depths of hell.\n\n");
  tell_room(environment(this_object()),
  "\nYuki-Onna screams \"\I'll get you one day!!!  And you shall pay for this...\"\n\n");
  ob = clone_object("/players/saber/monsters/hero/statue.c");
  ob->set_id("yuki");
  ob->set_short("A statue of Yuki-Onna");
  ob->set_long("A statue of the dark paladin Yuki-Onna.\n");
  move_object(ob,environment(this_object()));
  return 0;
        }

freeze_player()  {
object target, HERE;
int a;
if(!environment(this_object())) return 1;

HERE = first_inventory(environment(this_object()));

while(HERE)  {
  if(this_object()->query_attack())  {
  if(HERE->query_name() != "Yuki-Onna")  {
  if(living(HERE))  {
  if(call_other(HERE, "query_attrib", "wil") < random(45))  {
  target = clone_object("/players/saber/closed/evil/para.c");
  move_object(target,HERE);
  call_other(target, "freeze");
  tell_room(environment(this_object()),
  "\nYuki-Onna glares at "+HERE->query_name()+".\n"+
  HERE->query_name()+" is frozen with fright.\n\n");
  if(HERE->query_guild_name() == "paladin") HERE->heal_self(-4);
        }
        }
        }
        }
HERE = next_inventory(HERE);
        }
call_out("freeze_player",15);
  return 1;
        }
