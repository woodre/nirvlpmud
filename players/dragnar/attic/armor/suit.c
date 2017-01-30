/*  Changelog:
*
*  Dragnar/John 11/19/98
*  Suit no longer has to be 'don'ed to wear it.  Use scope resolution
*  to call wear in /obj/armor.  Had to put in actions for remove
*  and unwear because it wasn't working when called to the base 
*  class.  When armor is turned invisible it no longer clones a
*  new object, it just sets the short to 0.
*
a
/* 2005.04.27 -Forbin Fixed color problem when suit vis resets short */
#include <ansi.h>
inherit "obj/armor";

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
   set_short(BOLD+BLK+"Black Ninja Suit"+NORM);
    set_long_des();
   set_ac(4);
   set_weight(2);
   set_value(5000);
   set_alias("ninja suit");
   set_name("suit");
   set_type("armor");
}
set_long_des() {
    if( vis_flag == 0 ) vis_flag = "visible";
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
armor( str ) {
    if( !str ) {
        write("armor <vis> or armor <invis>?\n");
        return 1;
    }
    if( str == "invis" && vis_flag == "visible" ) {
        vis_flag = "invisible";
        write("The ninja suit grows a bright red and then fades from view.\n");
        set_short( 0 );
        set_long_des();
        return 1;
    }
    if( str == "vis" && vis_flag == "invisible" ) {
        vis_flag = "visible";
        write("There is a red flash of light, and your suit is visible again.\n");
        set_short(BOLD+BLK+"Black Ninja Suit"+NORM);
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
