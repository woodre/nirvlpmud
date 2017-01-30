#include "/players/mythos/closed/guild/def.h"
inherit "players/mythos/amon/forest/monster1";
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("ashura");
  set_race("avatar");
  set_short("Ashura");
  set_long(HIG+"The avatar of Destruction and War.\n\n"+NORM+
            "The Hunter locked him here to prevent holocaust.\n"+
            "Ashura does not look as he is often depicted- a young\n"+
            "man with three faces set around the head- rather he looks\n"+
            "to be a young boy of around the age of 10.  His black hair\n"+
            "is bundled up.  In the dim light that you have brought, \n"+
            "his skin shines golden and a ruby earring in his upswept ears\n"+
            "gleams.  He rests on the throne with his eyes half closed.\n"+
            BOLD+"\t   BE WARY!\n"+NORM);
  set_hp(1300);
  set_level(22);
  set_al(-1000);
move_object(clone_object("/players/mythos/awep/forest/shurato.c"),this_object());
  init_command("wield shurato");
  set_wc(40);
  set_ac(17);
  set_heal(3,20);
  set_dead_ob(this_object());
  set_aggressive(0);
  set_chat_chance(1);
  set_a_chat_chance(15);
  load_chat("Ashura slowly gives you a cold smile.\n");
  load_chat("Eyes of gold stare at you for a second and then are closed.\n");
  load_a_chat("Ashura grins evilly. \n");
  load_a_chat("Golden eyes gleam and you suddenly feel great pain!\n"); 
  set_pet_command();
  set_pet_cmd1("Ashura laughs and gestures!\n");
  set_pet_cmd2("With an evil smile, Ashura commands his servants!\n");
  set_mass_chance(10);
  set_mass_dam(10);
  set_mass_spell("Ashura gestures and a ball of flame appears in his"+
            " hands!\n\n"+
                  YEL+"\t       ^^^^^^^^^^^^^^^^^^^^^^\n"+
                      "\t  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n"+
    "\t^^^^^^^^^^^ "+RED+"I N F E R N O"+NORM+YEL+" ^^^^^^^^^^^\n"+NORM+YEL+
                      "\t  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n"+
                      "\t       ^^^^^^^^^^^^^^^^^^^^^^\n"+NORM+"\n"+
                      "You are in AGONY!\n"); 
  set_chance(10);
  set_spell_dam(15);
  set_spell_mess1("You see Ashura point a finger at his foe!\n");
  set_spell_mess2("Ashura points a finger at you!\nYou feel great PAIN!\n"); 
  call_out("cmd",10);
}


  
cmd() {
	object fool;
	int a;
	a=0;
  if(!environment(this_object())) return 1;
	fool=first_inventory(environment(this_object()));
	while(fool) {
		if(living(fool) && fool->query_ghost() !=1) {
			a=a+1;
		}
		fool=next_inventory(fool);
		}
	if(a>2) {
		fool=first_inventory(environment(this_object()));
	while(fool) {
		if(living(fool) && fool->query_ghost() !=1) {
			fool->attack_object(next_inventory(fool));
		}
		fool=next_inventory(fool);
		}
		say("Ashura calls the rage and violence from within you!\n"+
			HIG+"\t   Chaos Erupts!\n"+NORM);
		call_out("cmd",50);
	return 1;}
	call_out("cmd",10);
	return 1;}

monster_died() {
  if(present(fear,this_object()->query_attack())) {
    present(fear,this_object()->query_attack())->set_image(1);
    present(fear,this_object()->query_attack())->save_dark();
    command("uu",this_object()->query_attack());
    tell_object(this_object()->query_attack(),
      "You feel power flood you and you see CHAOS before you!\n"+
      "You reach out and grasp it!\n"+
      "Chaos is yours to command!\n"+
      "To cast type <chaotic>\n");
/*
  write_file("/players/mythos/closed/guild/task_spell",
    ctime(time())+" "+(this_object()->query_attack())->query_real_name()+
    "  chaos\n");
*/
  }
}
