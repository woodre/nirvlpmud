inherit "/obj/monster";
#include "/players/jareel/define.h"

     int stuff;
     int lives;
     int M;
     int sword;
     int a;
     int L;
	 int heal, x;
	 object *gear;
     int scimitar;
	 int My_Mhp;
	 
	 
  reset(arg) {
    object scar;
    gear = random(8);
    a = 3300;
    ::reset(arg);
      if (arg) return;
    set_name("mondar");
    set_race("human");
    set_gender("male");
    set_al(0);
    set_aggressive(0);
    set_hp(1800); 
	set_hp_bonus(3600); /* 3 x 1200 = 3600 */
	heal = 3;
    set_level(28);
    set_ac(26);
    set_wc(52+random(40)); /* Average 71 */
	set_wc_bonus(116); /* +71 WC +45 Spells extra attack in HB */
    set_gender("male");
    set_dead_ob(TO);
    scar=clone_object("players/dragnar/MKScar/scar.c");
    move_object(scar, this_object());
	
  if(gear == 0) { /* Dual Swords - Main Armor */ 
    MOCO("/players/jareel/general_stuff/mondar_bag.c"),this_object());
    MOCO("/players/jareel/armor/mondar_armor2.c"),this_object());
      init_command("wear armor");
    MOCO("/players/jareel/weapons/humakti_iron_offwield_sword.c"),this_object());
      sword = present("iron bastard sword",this_object());
      sword->set_short("Iron Bastard Sword (offwielded)");
    MOCO("/players/jareel/weapons/humakti_iron_offwield_sword.c"),this_object());
      init_command("wield sword"); 
  }

  if(gear == 1){ /*Death Sword - Shield */
    MOCO("/players/jareel/general_stuff/mondar_bag.c"),this_object());
    MOCO("/players/jareel/armor/mondar_shield.c"),this_object());
      init_command("wear shield");
    MOCO("/players/jareel/weapons/mondar_death_sword.c"),this_object());
      init_command("wield sword");
  }

  if(gear == 2){ /* Dual Swords - Helmet */
    MOCO("/players/jareel/general_stuff/mondar_bag.c"),this_object());
    MOCO("/players/jareel/armor/mondar_helmet.c"),this_object());
      init_command("wear helmet");
    MOCO("/players/jareel/weapons/humakti_iron_offwield_sword.c"),this_object());
      sword = present("iron bastard sword",this_object());
      sword->set_short("Iron Bastard Sword (offwielded)");
    MOCO("/players/jareel/weapons/humakti_iron_offwield_sword.c"),this_object());
      init_command("wield sword");    
  } 

  if(gear == 3){ /* Dual Swords - Boots */
    MOCO("/players/jareel/general_stuff/mondar_bag.c"),this_object());
    MOCO("/players/jareel/armor/mondar_boots.c"),this_object());
      init_command("wear boots");
    MOCO("/players/jareel/weapons/humakti_iron_offwield_sword.c"),this_object());
      sword = present("iron bastard sword",this_object());
      sword->set_short("Iron Bastard Sword (offwielded)");
    MOCO("/players/jareel/weapons/humakti_iron_offwield_sword.c"),this_object());
      init_command("wield sword");
  }

  if(gear == 4){ /* Dual Swords - amulet */
    MOCO("/players/jareel/general_stuff/mondar_bag.c"),this_object());
    MOCO("/players/jareel/armor/mondar_amulet.c"),this_object());
      init_command("wear amulet");
    MOCO("/players/jareel/weapons/humakti_iron_offwield_sword.c"),this_object());
      sword = present("iron bastard sword",this_object());
      sword->set_short("Iron Bastard Sword (offwielded)");
    MOCO("/players/jareel/weapons/humakti_iron_offwield_sword.c"),this_object());
      init_command("wield sword");
  }

  if(gear == 5){ /* Dual Swords - Ring */
    MOCO("/players/jareel/general_stuff/mondar_bag.c"),this_object());
    MOCO("/players/jareel/armor/mondar_gauntlets.c"),this_object());
      init_command("wear ring");
    MOCO("/players/jareel/weapons/humakti_iron_offwield_sword.c"),this_object());
      sword = present("iron bastard sword",this_object());
      sword->set_short("Iron Bastard Sword (offwielded)");
    MOCO("/players/jareel/weapons/humakti_iron_offwield_sword.c"),this_object());
      init_command("wield sword");
  }

  if(gear == 6){ /* Dual Swords - Misc */
    MOCO("/players/jareel/general_stuff/mondar_bag.c"),this_object());
    MOCO("/players/jareel/armor/mondar_misc.c"),this_object());
      init_command("wear misc");
    MOCO("/players/jareel/weapons/humakti_iron_offwield_sword.c"),this_object());
      sword = present("iron bastard sword",this_object());
      sword->set_short("Iron Bastard Sword (offwielded)");
    MOCO("/players/jareel/weapons/humakti_iron_offwield_sword.c"),this_object());
      init_command("wield sword");
  }

  if(gear == 7){ /* Humakti DeathSword - Main Armor */
    MOCO("/players/jareel/general_stuff/mondar_bag.c"),this_object());
    MOCO("/players/jareel/armor/mondar_armor.c"),this_object());
      init_command("wear armor");
    MOCO("/players/jareel/weapons/mondar_death_sword.c"),this_object());
      init_command("wield sword");    
  }

  set_short("Mondar - "+BOLD+BLK+"Rune Sword"+NORM+" of Humakt. (neutral)");
  set_long(
    "Mondar is an old wrinkled man.  Having seen many\n"+
    "years of battles, his silver-white hair and scar \n"+
    "ridden body prove he is not someone to mess with.\n"+
    "A small lump rises in the back of your throat as\n"+
    "he catches you looking at him.\n");	
 
add_spell(
  "allied spirit","\n\
	Mondar summons a spirit from his sword.\n\
    "+NORM+BOLD+"\n\
    "+NORM+"             An enraged Spirit slashes at #TN#.\n\n\
         "+NORM+"\n\n",	
	     "Mondar summons a spirit from his sword.\n\
         "+NORM+BOLD+"\n\
                 An enraged Spirit slashes at #TN#.\n\
         "+NORM+"\n\n",
    30,"40-54+50","other|spirit", 1);	/* +32 WC Bonus */
	
add_spell(
  "mondar bladesharp","\n\
	Mondar casts a bladesharp spell over his blade.\n\
    "+NORM+"\n\
    "+BLINK+CYN+" E N E R G Y "+NORM+" flows over the blade.\n\n",
	"Mondar casts a bladesharp spell over his blade.\n\
    "+NORM+"\n\
    "+BLINK+CYN+" E N E R G Y "+NORM+" flows over the blade.\n\n",
    30,"5d6+5","magical", 1); /* +5 WC Bonus	*/
	
add_spell(
  "fist smash","\n\
	Mondar smashes #TN# with a backhand, blood drips off his gauntlet.\n",
	"Mondar smashes #TN# with a backhand, blood drips off his gauntlet.\n",
    30,"24","physical", 1);		/* +8 WC Bonus */


add_spell(
  "Heal spell","\n\
Mondar takes a heal out of a bag.\n\
Mondar eats some "+BOLD+BGRN+"berries"+NORM+".\n",
"Mondar takes a heal out of a bag.\n\
Mondar eats some "+BOLD+BGRN+"berries"+NORM+".\n",
30,"5-10",0,3,"heal_me");


}

     heart_beat() {
  object       ob;
  ::heart_beat();
  corpse_loop();

  if(!attacker_ob) {
    return;
  }
  
  already_fight=0;
  attack();
  
		 if(!environment()) return ;
        
        if(heal && (this_object()->query_hp() < 400))
        {
                this_object()->heal_self(1200);
                stuff = all_inventory(environment(this_object()));
                tell_object(stuff[x], "DEBUG: HE HEALED!\n");
                if(stuff[x]->is_player())
                {
                      /*  stuff[x]->hit_player(125,"energy"); */
                        tell_object(stuff[x]," "+BOLD+BLK+"\n\nMondar asks for divine assistance.\n\n"+NORM+"!\n\n");
                }
                heal--;
        }
}
	 
         

 
void corpse_loop()    {
  object ob;
  if((ob = present("corpse", environment())) && (int)ob->is_corpse()) {
    tell_room(environment(),
      "Mondar takes: "+(string)ob->short()+".\n");
    move_object(ob, this_object());
    this_object()->corpse_loop();
  }
}

monster_died() {
  if(objectp(sword)) sword->reset();
  return 0;
}

heal_me( object target, object room, int damage ) {
string ATT_NAME,msg;
  if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
heal_self(25+random(26));
	set_heal(5,1);
}
 