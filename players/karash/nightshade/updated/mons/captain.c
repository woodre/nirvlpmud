inherit "obj/monster";
#include <ansi.h>

#define TO this_object() 
#define ENV environment

/******************************************************************************
 * Program: captain.c
 * Path: /players/nightshade/mons/
 * Type: Mob
 * Updated: September 2014 by Karash
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

object weap, arm, clk, shld;


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

/** Moved this to add_spell function - Karash - Sept 2014
 *  set_chance(30);
 *  set_spell_dam(10);
 *  set_spell_mess1("The captain of the watch executes a blinding double attack!");
 *  set_spell_mess2("You are hit from all sides as the captain executes a blurring double attack!");
 */
 
add_spell("double_attack",
    "You are hit from all sides as the captain executes a blurring double attack!\n",
    "The captain of the watch executes a blinding double attack!\n",
    30,10,"physical",0);

/** Removing these armor clones and putting description in long description since 
 ** this Cassanna clone will destruct                                              
 * weap=clone_object("players/nightshade/weap/drow_cleaver");
 * move_object(weap, this_object());
 * arm=clone_object("players/nightshade/armor/capt_armor");
 * move_object(arm, this_object());
 * clk=clone_object("players/nightshade/armor/capt_cloak");
 * move_object(clk, this_object());
 * shld=clone_object("players/nightshade/armor/capt_shield");
 * move_object(shld, this_object());
*****************************************************************************************/

/** Treasure does not matter - this object will be destroyed when attacked and replaced by another **/
add_money(2000);

}


void init()
{
  ::init();
    
	add_action("cast_mimage", "kill");
	
}


cast_mimage(str)
{

    if(str == "captain" || str == "cassana" ) 
	{
      if(present("cassana",environment()))
	  {
	  calm_room();
	  
	  tell_room(environment(), "Cassana holds a small platinum mirror in the air.  The tiny mirror reflects\n\
a "+HIW+"brilliant "+NORM+HIY+"beam"+NORM+HIW+" of light"+NORM+" in your eyes.\n\n");
	  tell_room(environment(), "Cassana casts a "+HIC+"spell"+NORM+" over the reflected light and two identical elven\n\
captains "+HIM+"step out"+NORM+" of the enchanted mirror in the same space as the caster.\n\n");
	  tell_room(environment(), "The "+HIC+"three"+NORM+" captains separate to stand beside each other while they each draw\n\
their cleaver pointing them at you and saying in unison,\n\n");
	  tell_room(environment(), "\n\          "+HIM+"'Choose your target!'"+NORM+"\n\n");
	  

  	  mirror_images();
  	  destroy_inventory(); 
  	  destruct(this_object()); 
	  /** return 1 to avoid kill command to continue after mirror images are cast - player will have to choose new target **/
	  return 1;
	  
	  }
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


mirror_images()
{
  int x, mi;
  object cl;
  mi = random(3);
 
  while(x < 3)
  {

    /* PATH UPDATED */
    cl = clone_object("players/nightshade/mons/captain2_new");
	/* for testing */
	/* tell_room(environment(), "mi = "+mi+".\n"); */
    if( mi == 2 )
    {
      cl->set_realorimage("real");
	  cl->SetMultipleIds( ({ "cassana", "onecaptainone" }) );
      move_object(cl, environment());
      /* tell_room(environment(), "MI = REAL\n"); */
	}
    else
    {
      cl->set_realorimage("image");
	  if(mi == 0 || mi == 3) {cl->SetMultipleIds( ({ "cassana", "twocaptaintwo" }) );}
	  if(mi == 1 || mi == 4) {cl->SetMultipleIds( ({ "cassana", "threecaptainthree" }) );}
      move_object(cl, environment());
      /* tell_room(environment(), "MI = IMAGE\n"); */
	}
    mi++;
    x++;
  
  }
}


/** Calm Room if combat is started without using kill command **/
heart_beat() 
{
  ::heart_beat();
  calm_room();
}

/************************************************************
 * This is to destroy Cassana inventory when destruction is called
 ************************************************************/
void destroy_inventory() {
  int ci, csize;
  object *cinv;
  cinv = all_inventory( this_object() );
  for( ci=0, csize = sizeof(cinv); ci < csize; ci++ )
  {
  destruct(cinv[ci]);
  }
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

  