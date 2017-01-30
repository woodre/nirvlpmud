/*  Changelog:
*
*  Dragnar/John 11/19/98
*  Suit no longer has to be 'don'ed to wear it.  Use scope resolution
*  to call wear in /obj/armor.  Had to put in actions for remove
*  and unwear because it wasn't working when called to the base 
*  class.  When armor is turned invisible it no longer clones a
*  new object, it just sets the short to 0.
*
/* 2005.04.27 -Forbin Fixed color problem when suit vis resets short */
/* 09/18/2013 - Approved weight of 1 - difficult to get this suit
   -- Rumplemintz
 */
#include <ansi.h>
inherit "obj/armor";

#define GUILDID "mageobj"
#define BONUS_TYPE "illusion"
#define BONUS_AMOUNT 4

string vis_flag;
init() {
    ::init();
    add_action("wear_suit","wear");
    add_action("armor","armor");
    add_action("remove_suit","remove");
    add_action("remove_suit","unwear");
    add_action("drop_suit","drop");
}
reset(arg){
   ::reset(arg);
   
   if(arg) return;
   
   set_short(BOLD+BLK+"Black Ninja Suit"+NORM);
   set_long_des();
   set_ac(4);
   set_weight(1);
   set_value(5000);
   set_alias("ninja suit");
   set_name("suit");
   set_type("armor");
}
set_long_des() {
    if( vis_flag == 0 ) 
      vis_flag = "visible";
      
    set_short(BOLD+BLK+"Black Ninja Suit"+NORM);
    set_long("This is a black ninja suit made by the ancients' for the strongest\n"+
    "warriors.  If you think you have mastered the ninja power of stealth, maybe you\n"+
    "should try to wear the suit.  The suit also has hidden 'armor' powers.\n"+
    "The suit is currently "+vis_flag+ ".\n");
}
wear_suit( str ) {
   int stealth;
   if(str == "suit"){
      stealth = this_player()->query_attrib("ste");
      if(stealth > 18){
            ::wear( "suit" );
            return 1;
      }
      else{
         write("You are not capable of wearing a ninja suit.\n");
            return 1;
      }
   }
}

short() {
  if( vis_flag == "visible" )
    return ::short();
  
  if( this_player() && this_player() == environment( this_object() ) ) {
    return ::short();
  }
    
  return 0;
}
armor( str ) {
    if( !str ) {
        write("armor <vis> or armor <invis>?\n");
        return 1;
    }
    if( str == "invis" && vis_flag == "visible" ) {
        vis_flag = "invisible";
        write(HIR+"The ninja suit grows brightly and then fades from view."+NORM+"\n");
        set_long_des();
        set_short( short_desc + " (invis)" );
        return 1;
    }
    if( str == "vis" && vis_flag == "invisible" ) {
        vis_flag = "visible";
        write(HIR+"There is a bright flash of light, and your suit is visible again."+NORM+"\n");
        set_long_des();
        return 1;
    }
    else {
        write("You can't make your suit "+str+" while it is "+vis_flag+".\n");
        return 1;
    }
}
remove_suit( str ) {
    if( str == "suit" ) {
        if( !worn ) {
            write("What?\n");
            return 1;
        }
        ::remove( "suit" );
        if( vis_flag == "invisible" ) armor( "vis" );
        return 1;
    }
}

drop_suit( str ) {
   if( ( ::id(str) || str == "all" ) && vis_flag == "invisible" ) {
        armor( "vis" );
        ::drop( str );
    }
}

do_special( owner ) {
  int tot_ste, ret;
   
  if( owner && vis_flag == "invisible" ) {
    tot_ste =  owner->query_attrib( "ste" );
     
    if( random(100) < tot_ste ) {
      tell_object(owner,  HIBLK+"\tThe Ninja Suit flickers as it transfers energy into your body.\n"+NORM);
      tell_room(environment(owner), 
        HIBLK+"The air flickers around "+owner->query_name()+"'s body.\n"+NORM
       , ({ owner }) );
      owner->add_spell_point(1+random(tot_ste/3));
      return 1;
    }
  }
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
