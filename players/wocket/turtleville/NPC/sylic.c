/*  10/09/06 - Rumplemintz
      Moved inherit to top of file
*/

inherit "/obj/monster.c";
#include "/players/wocket/closed/ansi.h"
#define BANNED ({"healer","polymorph"})
#include "/players/beck/MortalKombat/MKQuestNPC.h"

reset(arg){
    ::reset(arg);
    if(arg) return;
    move_object(clone_object("/players/wocket/turtleville/OBJ/shellmail.c"),this_object());
    move_object(clone_object("/players/wocket/turtleville/OBJ/bloodlust.c"),this_object());
    move_object(clone_object("/players/dragnar/MKScar/scar.c"),this_object());

    set_name("sylic");
    set_alias("swordsman");
    set_alt_name("master");
    set_race("seussian");
    set_gender("male");
    set_short("A master swordsman");
    set_long("Sylic has survived many battles in his time.  Scars line\n"+
      "his arms and face as marks of his triumphs.  He has long\n"+
      "since retired from his days as a warrior but trains others\n"+
      "to follow in his footsteps.  He can help you 'advance' your\n"+
      "level or even 'raise' a stat or two.\n");
    set_level(20);
    set_hp(600);
    set_wc(40+random(3));
    set_ac(20); 
    set_al(750);
    set_chat_chance(3);
    load_chat("Sylic says: Hiya.\n");
    load_chat("Sylic grins evilly.\n");
    set_a_chat_chance(24);
    load_a_chat("Sylic screams the "+HIB+"WARRIOR"+NORM+" cry ! ! ! ! !\n\n"+
      "as Sylic  "+HIR+"M A U L S"+NORM+"  his opponent in to  "+HIR+"B I T S"+NORM+" ! ! ! ! !\n");
    load_a_chat("Sylic  "+HIR+"S M A S H E S"+NORM+"  his target with a  "+HIR+"B L O O D  C U R D L I N G"+NORM+"  punch.\n");
    set_chance(30);
    set_spell_dam(20);
    set_spell_mess1("Sylic  "+HIR+"C R U S H E S"+NORM+"  his advisary with a  "+HIR+"M A S S I V E"+NORM+"  blow.\n");
    set_spell_mess2("Sylic  "+HIR+"C R U S H E S"+NORM+"  his advisary with a  "+HIR+"M A S S I V E"+NORM+"  blow.\n");
}

init(){
    ::init();
    add_action("alt_advance","advance");
    add_action("alt_raise","raise");
}

int alt_advance(){
    if(member_array(this_player()->query_guild_name(),BANNED)!= -1){
	notify_fail("Sylic says: I'm sorry, but I can not train your unusual talents.\n");
	return 0;
    }
    if(this_player()->query_level() > 16){
	notify_fail("Sylic says: You are much too advanced to be trained by me.\n");
	return 0;
    }
    call_other("/room/adv_guild","advance");
    return 1;
}

int alt_raise(string str){
    if(member_array(this_player()->query_guild_name(),BANNED)!= -1){
	notify_fail("Sylic says: I'm sorry, but I can not train your unusual talents.\n");
	return 0;
    }
    call_other("/room/adv_guild","raise",str);
    return 1;
}

