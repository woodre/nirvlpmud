inherit "/obj/monster";
object venom, gem;
int which;

reset(arg) {
  ::reset(arg);
  
  gem = clone_object("/players/saber/gems/pearl.c");
    move_object(gem,this_object());
  venom = clone_object("/players/saber/weapons/venom.c");
    move_object(venom,this_object());
    
if (!arg){

     set_name("giant spider");
     set_short("A giant spider");
     set_alias("spider");
     set_race("spider");
     set_long(
        "A huge spider with dark eyes and evil looking fangs.\n"+
        "It seems to be quite intelligent.\n");
     set_gender("creature");
     set_level(15);
     set_ac(11 + random(3));
     set_wc(19 + random(3));
     set_hp(200 + random (50));
     set_al(-800);
     set_aggressive(0);
     set_chance(10);
     set_spell_dam(30);
     set_spell_mess1("The giant spider sinks its poisoned fangs into its foe.\n");
     set_spell_mess2("The giant spider sinks its poisoned fangs into you!\n");
        }
        }
