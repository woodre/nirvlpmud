#include "/players/wocket/closed/ansi.h"
#include "../Def.h"
inherit "obj/monster.c";
int have_book;
object hero;

reset(arg){
 ::reset(arg);
 if(arg) return;
 set_name("yestler");
 set_short(HIY+"Yestler"+OFF+", the old hermit");
 set_alias("hermit");
 set_al(100);
 set_race("seusian");
 set_long("yes");
 set_level(20);
 set_hp(1000);
 set_wc(30+random(10));
 set_ac(17+random(5));
 set_dead_ob(this_object());
}

init(){
  ::init();
  add_action("ask","ask");
  add_action("saying","say");
#ifndef __LDMUD__
  add_action("ask"); add_xverb("'");
#else
  add_action("ask", "'");
#endif
}

saying(str){
string one,two,three;
if(sscanf(str,"%seuka%slanguage%s",one,two,three) == 3){
  hero = this_player();
  call_out("ask",2,"yestler");
}
else
if(random(10)){
  write("Yestler looks at you strangely.\n");
}
return 0;
}

ask(str){
  if(!str || (str != "yestler" && str != "hermit")){
    notify_fail("Who would you like to ask?\n");
    return 0;
  }
  if(!hero) hero = this_player();
  tell_object(hero,"Yestler says, \"Well I don't really know much.  I've been living out in\n"+
                   "               This forest for so long.  Many strange creatures out here.\n"+
                   "               When I first got here they were always speaking jibberish\n"+
                   "               til I found out it was a language.  Heh, in the begining I\n"+
                   "               even wrote down some of the basics in a book.\"\n");
  call_out("speakdelay",2);
return 1;
}

speakdelay(ob){

if(!have_book){  
  tell_object(hero,"Yestler says, \"Hey, I suppose you could have this.  I dont really need it\n"+
                   "               anymore.\"\n");
  tell_object(hero,"Yestler gives you a book.\n");
  move_object(EPATH+"OBJ/questbook.c",hero);
  have_book = 1;
  }
  else{
  tell_object(hero,"Yestler says, \"To bad I already gave it away to somebody or I'd let you have it.\n");
  }
  hero = 0;
return 1;
}

monster_died(){
}
