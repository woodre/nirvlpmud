inherit "/obj/monster";
#include "/players/jareel/define.h"

     object cloak;
     int gear;
	 int healdam1;
	 int healdam2;
     int lives;
     int M;
     int sword;
     int a;
     int L;
	 int heal, x;
	 int heal2, y;
	 object *stuff;
	 int My_Mhp;
	 
	 
  reset(arg) {

  ::reset(arg);
    if (arg) return;
  set_level(25);
  set_name("chandra");
  set_race("human");
  set_gender("female");
  set_al(0);
  set_aggressive(0);
  set_multi_cast(1);
  set_hp(2000); 
  set_hp_bonus(8750); /* Battle Healer Heals a lot does Damage when she heals 6000 in health
                         and 2750 in one shot damage seemed more logical to put it here than
    					 anywhere else because the diminishing returns on xp and it would not
						 be a reoccurring source of damage as a spell would be*/ 
  heal = (2);
  heal2 = (20);
  set_ac(44);
  set_heal(10,1);
  set_res(40);
  set_ac_bonus(20); /* Illarion Said ac bonus for Physical Res should be 1 py per percent of Res */
  set_wc(32+random(99)); 
  set_dead_ob(this_object());

  set_short(HIY+"Chandra, "+HIK+"["+BLU+"Battle Healer"+NORM+HIK+"]"+NORM+" of "+HIY+"C"+BLU+"alana "+HIY+"A"+BLU+"rroy"+NORM+". (Holy Neutral)");
  set_long(
"Flowing blond hair flows from under the rag tag pieced together battle armor this\n"+ 
"warrior has pieced together.  Utilising some of the most powerful items in the land\n"+
"this battle mage stand ready for the powers of chaos that deep within the Chaos Wood.\n"+
"The powerful aura of a healer radiates of pure power off every pore of her being.\n"+
"\n"+
"Chandra is Wearing:\n"+
HIR+"A Flowing Red Scarf"+NORM+" (worn).\n"+
MAG+"Flowing purple robes"+NORM+" (worn)."+NORM+"\n"+
HIB+"Shield of Tears"+NORM+" (worn).\n"+
"Bracers of Speed (worn).\n"+
"Ice Skates (worn).\n"+
"Shamanic "+BLU+"boxer shorts"+NORM+" (worn).\n"+
YEL+"Gold Dragon Leggings"+NORM+" (worn).\n"+
HIK+"A "+HIR+"ju"+NORM+RED+"ju"+NORM+HIK+" trinket"+NORM+" (worn).\n"+
GRN+"Warpstone"+HIK+" Amulet"+NORM+" (worn).\n"+
"the face of "+HIK+"CyberJesus"+NORM+" (worn).\n"+
HIW+"Chestguard of "+GRN+"Health"+NORM+" (worn).\n"+
GRN+"Warpstone "+HIK+"Armor"+NORM+" (worn).\n"+
HIW+"Nature's "+NORM+HIG+"Blessing"+NORM+" (floating nearby).\n"+
"A black belt "+RED+"<Demon Cursed>"+NORM+" (worn).\n"+
HIW+"Silver ring"+NORM+" (worn).\n"+
"A "+YEL+"golden"+NORM+" earring (worn).\n"+
HIK+"Demon Tentacles "+NORM+"["+HIY+"Sun Forged"+NORM+"]"+NORM+"(worn).\n"+    "\n");	
	
MOCO("/players/jareel/weapons/CALANAARROY/HealerStaff.c"),this_object());
          init_command("wield staff");
cloak=clone_object("/players/jareel/SoulboundObjects/ARMOR/DemonCloakBinding.c");
        move_object(cloak, this_object());
  
            set_armor_params("magical",0,20,"pro_magical"); 
            set_armor_params("other|evil",0,20,"pro_evil");
            set_armor_params("other|good",0,20,"pro_good");
            set_armor_params("other|fire",0,20,"pro_fire");
            set_armor_params("other|ice",0,20,"pro_ice");
            set_armor_params("other|sonic",0,20,"pro_sonic"); 
            set_armor_params("other|mental",0,20,"pro_mental");
            set_armor_params("other|electric",0,20,"pro_electric");
            set_armor_params("other|wind",0,20,"pro_wind");
            set_armor_params("other|earth",0,20,"pro_earth");
            set_armor_params("other|dark",0,20,"pro_dark"); 
            set_armor_params("other|light",0,20,"pro_light");
            set_armor_params("other|water",0,20,"pro_water");
            set_armor_params("other|poison",0,20,"pro_fire");
            set_armor_params("other|laser",0,20,"pro_laser");
 
  add_spell( /* Allied Spirit Damage There is a necklace in the Caves that has a res vs other|spirit damage */
    "allied spirit",
"Chandra summons a spirit from her staff.\n\
"+NORM+BOLD+"\n\
"+NORM+"             An enraged Spirit slashes at #TN#.\n\
"+NORM+"\n",	
"Chandra summons a spirit from her staff.\n\
"+NORM+BOLD+"\n\
                     An enraged Spirit slashes at #TN#.\n\
         "+NORM+"\n",
    20,"40-54+50","other|spirit", 1);
	
  add_spell(
    "chandra armorShield1",
"Chandra strikes #TN# with a shield spike.\n",
"Chandra strikes #TN# with a shield spike.\n",
    40,"6-12+2","other\Jareel", 1); /* Changed From Physical as not to be mitigated */
	
  add_spell(
    "chandra armorBoots1",
"#TN# is sliced open by the blade of Chandra's skate.\n\
\n\
                 "+HIR+"BLOOD"+NORM+" splatters everywhere.\n",
"#TN# is sliced open by the blade of Chandra's skate.\n\
\n\
                 "+HIR+"BLOOD"+NORM+" splatters everywhere.\n",
   40,"6-12+2","other\Jareel", 1); /* Changed From Physical as not to be mitigated */

  add_spell(
   "chandra armorgloves1",
"\nA cross-shaped rocket fires from the face of "+HIK+"CyberJesus"+NORM+" (worn)!\n"+RED+"        ---|-------\n"+NORM+"",
"\nA cross-shaped rocket fires from the face of "+HIK+"CyberJesus"+NORM+" (worn)!\n"+RED+"        ---|-------\n"+NORM+"",
    40,"6-12+2","other\Jareel", 1); /* Changed From Physical as not to be mitigated */

  add_spell(
   "chandra armorHelm1",
"Chandra smashes #TN# with a backhand, blood drips off his gauntlet.\n",
"Chandra smashes #TN# with a backhand, blood drips off his gauntlet.\n",
    40,"6-12+2","other\Jareel", 1); /* Changed From Physical as not to be mitigated */
	
  add_spell(
  "chandra armorMisc1",
"#TN# is "+YEL+"smashed"+NORM+" with a "+HIK+"giant boulder"+NORM+" from "+HIW+"Nature's "+GRN+"Blessing"+NORM+"!"+NORM+"\n",
"#TN# is "+YEL+"smashed"+NORM+" with a "+HIK+"giant boulder"+NORM+" from "+HIW+"Nature's "+GRN+"Blessing"+NORM+"!"+NORM+"\n",
    20,"6-12+2","other|dark", 1); 
	
  add_spell(
"chandra armorBoots1",
"#TN# is sliced open by the blade of Chandra's skate.\n\
 \n\
                "+HIR+"BLOOD"+NORM+" splatters everywhere.\n",
"#TN# is sliced open by the blade of Chandra's skate.\n\
\n\
               "+HIR+"BLOOD"+NORM+" splatters everywhere.\n",
    40,"6-12+2","other\Jareel", 1); /* Changed From Physical as not to be mitigated */

	
  add_spell(
    "chandra armorshield2",
"#TN# is "+HIY+"zapped"+NORM+" with a "+HIY+"jolt of"+NORM+HIW+" lightning from "+HIW+"Nature's "+GRN+"Blessing"+NORM+"!.\n",
"Chandra strikes #TN# with a shield spike.\n",
    20,"6-12+2","other\Jareel", 1); /* Changed From Physical as not to be mitigated */

  add_spell(
    "chandra armorMisc2",
HIK+"#TN# is squeezed by Chandra's flowing Demonic Tentacles..\n"+NORM,
HIK+"#TN# is squeezed by Chandra's flowing Demonic Tentacles..\n"+NORM,
    40,"6-12+2","other|dark", 1);
	
	
  add_spell(
"chandra armorBoots1",
"#TN# is sliced open by the blade of Chandra's skate.\n\
 \n\
                "+HIR+"BLOOD"+NORM+" splatters everywhere.\n",
"#TN# is sliced open by the blade of Chandra's skate.\n\
\n\
               "+HIR+"BLOOD"+NORM+" splatters everywhere.\n",
    40,"6-12+2","other\Jareel", 1); /* Changed From Physical as not to be mitigated */
	
  add_spell(
    "chandra armorBracers2",
HIB+"Chandras's form"+HIW+" || |  | blurs |  | ||"+HIB+" as his bracers "+HIY+"glow"+NORM+"...\n",
HIB+"Chandras's form"+HIW+" || |  | blurs |  | ||"+HIB+" as his bracers "+HIY+"glow"+NORM+"...\n",
    40,"6-12+2","other|dark", 1);
	
add_spell(
    "chandra armor2",
"#TN# is "+HIC+"suffocated"+NORM+" with a "+CYN+"gust of wind"+NORM+" from "+HIW+"Nature's "+GRN+"Blessing"+NORM+"!\n",
"#TN# is "+HIC+"suffocated"+NORM+" with a "+CYN+"gust of wind"+NORM+" from "+HIW+"Nature's "+GRN+"Blessing"+NORM+"!\n",
    20,"6-12+2","other\Jareel", 1); /* Changed From Physical as not to be mitigated */
		
	
  add_spell(
    "Heal spell",
"Chandra takes an Elixir of "+HIR+"E"+HIB+"verlast"+NORM+" out of her "+HIK+"Demon Cloak of Holding"+NORM+".\n\
Chandra Drinks from the Elixir.\n\
Chandra Drinks from the Elixir.\n\
Chandra Drinks from the Elixir.\n",
"Chandra takes an Elixir of "+HIR+"E"+HIB+"verlast"+NORM+" out of her bag.\n\
Chandra Drinks from the Elixir.\n\
Chandra Drinks from the Elixir.\n\
Chandra Drinks from the Elixir.\n",
    30,"5-10",0,3,"heal_me");

	add_spell(
    "chandra armorMisc21",
HIK+"#TN# is squeezed by Chandra's flowing Demonic Tentacles..\n"+NORM,
HIK+"#TN# is squeezed by Chandra's flowing Demonic Tentacles..\n"+NORM,
    20,"6-12+2","other|dark", 1);

}

     heart_beat() {
       object       ob;
       ::heart_beat();
       corpse_loop();

    if(!attacker_ob) {
      return;
    }
   
		 if(!environment()) return ;
        
        if(heal && (this_object()->query_hp() < 400))
        {
                this_object()->heal_self(1000); /* Will Heal 2000 */
                healdam1 = all_inventory(environment(this_object()));
                tell_object(healdam1[x], "\n");
                if(healdam1[x]->is_player())
                {
                        healdam1[x]->do_damage(125,"energy");  /* Will hit for 250 */ 
                        tell_object(healdam1[x]," "+BOLD+BLK+"\n\nChandra for divine assistance.\n\n"+NORM+"!\n\n");
                }
                heal--;
        }
		
	    if(heal2 && (this_object()->query_hp() < 1000))
        {
                this_object()->heal_self(200); /* Will Heal 4000 Hit Points */
                healdam2 = all_inventory(environment(this_object()));
                tell_object(healdam2[y], BLINK+GRN+"Chandra uses your life force to heal her life force!\n"+NORM);
                if(healdam2[y]->is_player())
                {
                        healdam2[y]->do_damage(125,"energy"); /* Will deal 2500 Damage in the fight */
                        tell_object(healdam2[y]," "+BLINK+BOLD+GRN+"\n\Life flows from Chandra's Surroundings pulling from you and every living thing!.\n\n"+NORM+"!\n\n");
                }
                heal2--;
        }
}
 
  void corpse_loop()    {
    object ob;
    if((ob = present("corpse", environment())) && (int)ob->is_corpse()) {
      tell_room(environment(),
        "Chandra takes: "+(string)ob->short()+".\nChandra say's 'That poor lost soul I will see that he is sent to the proper gods.'");
      heal2 += 20; /* heal2 = (40);Big Fuck you if you die to this Mob Sets the Heal2 counter to 40 giving her a lot of fucking hit points */
      set_hp_bonus( hp_bonus + (200 * 20) );
      move_object(ob, this_object());
      this_object()->corpse_loop();
    }
}

 monster_died() {
  if( attacker_ob && cloak ) {
    cloak->set_binder( attacker_ob->query_real_name() );
    tell_room( environment(), ""+HIW+"A flash of light flashes from the cloak as it is soulbound to "+
      attacker_ob->query_name()+".\n"+NORM );
  }}

  heal_me( object target, object room, int damage ) { /* More Healing No one said this would be a short fight Heing isn't super high here but
                                                         multi-cast is on and this will set 10,1 heal on so there is a lot of xp this mob does 
														 lot of xp this mob does not give. */
  string ATT_NAME,msg;
    if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
  heal_self(20+random(16));
}
string query_long() {
  string str;
  str = long_desc;
  if( this_player() && this_player()->query_level() > 60 )
    str += "heal : " +heal+ "\nheal2: "+heal2+"\n";
  return str;
}
query_limited_shadow() { return 1; }
 
