inherit "/obj/monster";
object ob;

reset(arg) {
  ::reset(arg);
  
  ob = clone_object("/players/saber/armor/no_fear.c");
    move_object(ob, this_object());
    
if (!arg){

     init_command("wear shirt");
     set_name("street punk");
     set_short("A young street punk");
     set_alias("punk");
     set_race("human");
     set_long(
        "A young street punk.  He appears to be watching the merchants.\n");
     set_gender("male");
     set_level(4);
     set_wc(9);
     set_ac(5);
     set_hp(75);
     set_al(-300);
     set_aggressive(0);
     set_chat_chance(8);
     set_a_chat_chance(8);
     load_chat("The street punk watches the merchant.\n");
     load_chat("The punk screams \"\Die, baby die!\"\n"); 
     load_a_chat("The punk yells \"\Weasel!  Weasel!\"\n");
     set_dead_ob(this_object());

        }
        }

monster_died()  {
object ob;
  tell_room(environment(this_object()), "\n"+
  "The street punk realizes what fear is...\n\n");
  return 0;
        }
