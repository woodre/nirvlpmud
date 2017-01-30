#include "/players/softly/closed/ansi.h"
#define DEST "/players/softly/point/rooms/lh"
inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (arg) return;
   move_object(clone_object("/players/softly/point/obj/fsabre.c"),this_object());
   set_name("blackbeard");
   set_short(BOLD + "Ghost" + NORM + " of Edward Teach");
   set_alias("ghost");
   set_long("\
  Blackbeard has an evil smile, merciless as he gazes\n\
at you.  His huge black beard that nearly covers his face\n\
is braided and tied with small ribbons. He looks strong and\n\
his hair seems to be on fire.\n");
   set_race("ghost");
   set_level(20);
   set_ac(17);
   set_wc(30);
   set_hp(700);
   set_al(-1000);
   set_aggressive(1);
   set_chance(20);
   set_spell_dam(50);
   set_spell_mess1("Blackbeard slashes out with his sabre.\n");
   set_spell_mess2("\n\tBlackbeard penetrates your flesh with\n"+
                   "\this sabre.  Your "+HIR+"blood "+NORM+"flows freely.\n");
   set_dead_ob(this_object());
   add_money(3000+random(300));
   call_out("john_candy", 120);
}

john_candy()
{
    if(!environment()) return;
    move_object(this_object(), DEST + "" + (13 + random(8)));
    call_out("john_candy", 120);
}

monster_died(){
  write_file("/players/softly/logs/point",
  ctime(time())+": "+this_object()->query_attack()->query_name()+" [L "+this_object()->query_attack()->query_level()+
  "+"+this_object()->query_attack()->query_extra_level()+"] killed Blackbeard.\n");
}
