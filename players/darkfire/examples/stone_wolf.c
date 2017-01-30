inherit "obj/monster";

#include <ansi.h>


reset(arg){
  ::reset(arg);
  if(arg) return;
  
  set_name("wolf");
  set_race("canine");
  set_alias("stone wolf");
	set_short("Stone Wolf");
	set_long("This is a wolf made of pure stone. His eyes are made from\n\
"+HIG+"emeralds"+NORM+" and his teeth are made from "+HIBLK+"obsidian"+NORM+" granite.\n");
  set_level(15);
  set_hp(20);
  set_al(0);
  set_wc(50);
  set_ac(30);
  
	set_aggressive(1);
  call_out( "self_destruction", 5+random(10) );
}

self_destruction() {
  object room;
  room = environment();
  
  if( room )
    tell_room( room, "The Stone Wolf crumbles to dust.\n" );
  destruct( this_object() );
}
