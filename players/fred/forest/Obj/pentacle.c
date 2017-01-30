/*edited 05-15-07 by Tallos to add mage guild bonus*/
#include "/obj/ansi.h"
#define GUILDID "mageobj"
#define BONUS_TYPE "will power"
#define BONUS_AMOUNT 1
inherit "/obj/armor";
int X;

reset(arg) {
  if(arg) return;
  ::reset(arg);
  set_name("pentacle");
  set_alias("necklace");
  set_short(BOLD+RED+"Pentacle "+NORM+BOLD+"of "+BLK+"Defense"+NORM);
  set_long(
  "  A beautiful necklace with a pentacle attached to it.\n"+
  "There is a large"+RED+" red"+NORM+" cyrstal locked in the center of it.\n"+
  "As you gaze at it's beauty you realize that it holds\n"+
  "great power.\n");
  set_type("necklace");
  set_ac(1);
  set_params("magical",1,0,0);
  set_weight(1);
  set_value(1500);
/*  WHY - Bp
  set_save_flag();
*/
}
query_guild_bonus(){ return BONUS_AMOUNT; }

add_guild_bonus()
{
  if(present(GUILDID, this_player()))
	present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE, BONUS_AMOUNT);
			
}

remove_guild_bonus()
{
  if(present(GUILDID, this_player()))
	present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE, -BONUS_AMOUNT);
	
}
do_special(owner){
   int n;
   n = random(100);
   if(n < 14){
    int r;
    r = random(4); 
    tell_object(owner,
    "The"+RED+" pentacle"+NORM+BOLD+" glows"+NORM+" protectively around you.\n"); 
    X += r;
   return 1; 
 }
   if(X > 10){
    tell_object(owner,
    "The"+RED+" pentacle"+NORM+BOLD+" releases"+NORM+" its power into you!\n");
     owner->add_hit_point(random(4));
    X -= 11;
   return 1; 
  }
}
