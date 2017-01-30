inherit "obj/monster";
#include <ansi.h>

#define TO this_object() 
#define ENV environment

/******************************************************************************
 * Program: captain2_new.c
 * Path: /players/nightshade/mons/
 * Type: Mob
 * Created: September 2014 by Karash
 *
 * Purpose: An upgrade to the original Nightshade mob named Cassana (captain)
 *		    When the object called captain.c is attacked, it will destruct and 
 *          create 3 clones of this object (captain2_new.c) where one of them will randomly
 *          be set as the real captain and the other 2 will be set as mirror images.
 *          All 3 captains will attack the attacker, but only the real captain will
 *          reward experience for the kill.  Therefore, all bonuses from the 2
 *          images are set in this object for the real captain.
 *
 *          As a level 25 mob, this mob will  have a spell attack and the 2 special
 *          advantages will be 1) since all 3 images attack, it is very similar to
 *          multicast with 3 spells and 2) there is a 2:3 chance the attacker will kill
 *          an image and will have to fight again to get exp from the real captain.
 *          Note: The second (and possibly third) fight is not included in the exp
 *		    rewards - it is dependent on the luck of selecting the correct captain.
 * 
 * History:
 *          
 ******************************************************************************/


object gold, ear, weap, arm, clk, shld;
object capt1, capt2, capt3;
object captimg1, captimg2, captimg3;

object mir;
object room, corpse;

string realorimage;


reset(arg)
{
::reset(arg);
if(arg) return;
set_alias("cassana");
set_name("captain");
set_short("Cassana Praxis, Captain of the Watch");
set_long(
"This is Cassana Praxis, an elven female and captain of the town watch.\n"+
"She has lived many centuries but still looks rather young. Of course\n"+
"only through magic could she stay so young. Another curious feature\n"+
"you notice about her, is that she is almost seven feet tall! Once again\n"+
"only through magic could she have attained such a height. Strapped on\n"+
"her back is Drow Cleaver, a magically enchanted axe. It is her most\n"+
"prized possession and she is quite capable of keeping it that way. She\n"+
"is very hard to kill. You have been warned.\n"+
"Cassana is carrying:\n\
Black Shield (worn).\n\
Chainmail cloak (worn).\n\
Plate mail +1 (worn).\n\
Drow Cleaver (wielded).\n\
"+YEL+"Elven ear cuffs"+NORM+" (worn).\n\
A Platinum Mirror.\n");

set_level(25);
set_hp(1200);
set_wc(44);
set_ac(23);
set_heal(5,1);

/** Since all 3 captains will fight when either is attacked, setting wc_bonus for the
 ** other 2 captains at 2x 44wc = 88wc bonus plus each has a drow cleaver at 19wc x2 = 38wc
 ** for a total bonus of 126wc.  Also, the other 2 images will also have the same spell,
 ** which averages 50damage cast at 30% chance, which adds bonus of 50dmg * .30chance * 2 images =
 ** 30wc bonus, making total wc bonus = 156wc. Since only the real captain will give
 ** exp at death, the bonuses will be on each clone to account for the 2 images since
 ** the images are randomly selected when cloned
 **/
set_wc_bonus(156);


/** Moved this to add_spell function - Karash - Sept 2014
 ************************************************************************
 *  set_chance(30);
 *  set_spell_dam(10);
 *  set_spell_mess1("The captain of the watch executes a blinding double attack!");
 *  set_spell_mess2("You are hit from all sides as the captain executes a blurring double attack!");
 */
 
add_spell("double_attack",
  "You are hit from all sides as the captain executes a $M$blurring double attack$N$!\n",
  "The captain of the watch executes a $M$blinding double attack$N$!\n",
  30,"40-60","physical",0);

/** Moved this to clone on corpse after death to avoid having to destruct inventory
 ** when the images are killed - Karash - Sept 2014  
 ************************************************************************************* 
 ** ear=clone_object("players/karash/nightshade/updated/earcuffs_new");
 ** move_object(ear, this_object());
 ** weap=clone_object("players/nightshade/weap/drow_cleaver");
 ** move_object(weap, this_object());
 ** arm=clone_object("players/nightshade/armor/capt_armor");
 ** move_object(arm, this_object());
 ** clk=clone_object("players/nightshade/armor/capt_cloak");
 ** move_object(clk, this_object());
 ** shld=clone_object("players/nightshade/armor/capt_shield");
 ** move_object(shld, this_object());
 ** increase treasure when level increases 
 ** add_money(2000); 
 **/
 
set_dead_ob(this_object());

}


void init()
{
  ::init();
  
  set_heart_beat(1);
  
  /* COMMENT OUT this line in PROD - used for testing */  
  /* tell_room(environment(), "\n\Real or Image = "+realorimage+"\n"); */
  
  /** Set images to give no experience to players **/
  if(realorimage != "real")
  { set_no_exp_value(); }
	
}


heart_beat()
{
  ::heart_beat();
  
  /* for testing */
  /* tell_room(environment(), "CHECK 1a\n"); */
	
  if(this_object()->query_attack()) 
  { return 0; }                     
  capt1 = present("cassana", environment());
  /* for testing */
  /* tell_room(environment(), "capt1 set\n"); */
  capt2 = present("cassana 2", environment());
  /* for testing */
  /* tell_room(environment(), "capt2 set\n"); */
  capt3 = present("cassana 3", environment());
  /* for testing */
  /* tell_room(environment(), "capt3 set\n"); */
  
  /* for testing */
  /* tell_room(environment(), "CHECK 1b\n"); */
  
 
  
  if(capt1 && capt1->query_attack())
  {
    attack_object(capt1->query_attack());
    /* for testing */	
	/* tell_room(environment(), "Attacking capt1 attacker\n"); */
  }
  else if(capt2 && capt2->query_attack())
  {
    attack_object(capt2->query_attack());
	/* for testing */
	/* tell_room(environment(), "Attacking capt2 attacker\n"); */
  }
  else if(capt3 && capt3->query_attack())
  {
    attack_object(capt3->query_attack());
	/* for testing */
	/* tell_room(environment(), "Attacking capt3 attacker\n"); */
  }
  
    /* for testing */
    /* tell_room(environment(), "CHECK 2\n"); */
  
}

set_realorimage(string roi)
{
  realorimage = roi;
  
}


monster_died()
{

  corpse = present( "corpse of captain", environment() );
  room = environment(corpse);


  if (realorimage == "real")
  {
	/** "twocaptaintwo" and "threecaptainthree" are images - destroy them if present when real captain is killed **/
    captimg2 = present("twocaptaintwo", room); 
	if(captimg2) {destruct(present("twocaptaintwo", room)); /* tell_room(room, "captimg2 destroyed\n"); */ }
    captimg3 = present("threecaptainthree", room); 
	if(captimg3) {destruct(present("threecaptainthree", room)); /* tell_room(room, "captimg3 destroyed\n"); */ }	
	
	tell_room(room, "\n\As Cassana gasps her last breath, all remaining "+HIC+"images"+NORM+" disappear.\n\n");
	
	/* increase treasure when level increases */
    gold=clone_object("obj/money");
    gold->set_money(2000);
    move_object(gold, corpse); 
	
	/* PATHS UPDATED */
    mir = clone_object("players/nightshade/misc/mirror_new"); 
 	move_object(mir, corpse);
    ear=clone_object("players/nightshade/armor/earcuffs_new"); 
    move_object(ear, corpse);
    weap=clone_object("players/nightshade/weap/drow_cleaver");          
    move_object(weap, corpse);
    arm=clone_object("players/nightshade/armor/capt_armor");
    move_object(arm, corpse);
    clk=clone_object("players/nightshade/armor/capt_cloak");
    move_object(clk, corpse);
    shld=clone_object("players/nightshade/armor/capt_shield");
    move_object(shld, corpse);
	
		
  }

  else if(realorimage != "real")
  {
    calm_room();

	tell_room(room, "\n\Cassana laughs wholeheartedly at you as the "+HIC+"image"+NORM+" disappears and says,\n");
	tell_room(room, "\n\          "+HIM+"'You chose... poorly.'"+NORM+"\n\n");

    destruct(corpse);
  }  
}


calm_room() 
{

 object att, *ob;
 int    h, s;
 s = sizeof(ob = all_inventory(environment(this_object())));
 
 while(h < s)
 {
  if(att = (object)ob[h]->query_attack())
  {
   ob[h]->stop_fight();
   att->stop_fight();
  }
  h++;
 }
 return 1;
}


move_player(){
  tell_room(ENV(TO),
  TO->query_name()+" tries to move but is compelled to stay...\n");}

move_object(){
  tell_room(ENV(TO),
  TO->query_name()+" tries to move but is compelled to stay...\n");}

run_away(){
  tell_room(ENV(TO),
  TO->query_name()+" tries to run but is compelled to stay...\n");}

movement(){
  tell_room(ENV(TO),
  TO->query_name()+" tries to move but is compelled to stay...\n");}

  