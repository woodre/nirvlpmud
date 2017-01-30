#include <ansi.h>   /* Changed to standard ansi.h - Rumplemitnz */
/* #include "/players/fred/ansi.h"; */
inherit "/obj/monster.c";
#define tpn this_player()->query_name()

object leggings;
reset(arg) {
  ::reset(arg);
  if(arg) return;


  set_name("gold dragon");
  set_race("dragon");
  set_short(BOLD+HIM+"An Ancient "+NORM+""+YEL+"Gold"+HIM+" Dragon"+NORM);
  set_long(
    "  This mighty creature is the most powerful of all dragon races. He\n"+
    "glares at you with watchful eyes. His presence makes you nervous.\n");
  
  add_money(10000);
  leggings = clone_object("/players/tallos/7tigers/objects/dragon_legs.c");
  move_object(leggings, this_object());
  command("wear leggings", this_object());  
  set_level(21);
  set_hp(2000+random(1500));
  set_al(800);
  set_heal(30,5);
  set_ac(30+random(8));
  set_wc(42+random(8));
  set_aggressive(0);
  set_weapon_params("other|fire",20,0);
  set_armor_params("other|fire",0,50,0);
  set_armor_params("other|ice",0,-20,0);
  set_armor_params("other|magic",0,20,0);
  set_multi_cast(0);
  add_spell("Cone of Fire",
  "#MN# opens his mouth and...\n"+
  "                         "+HIR+"FFFFFFFFFFFFFFFFFFF\n"+
  "  "+NORM+""+YEL+"*    *"+HIR+"            FFFFFFFFFFFFFFFFFFFFFFFF\n"+
  "   "+NORM+""+YEL+"****"+HIR+"       FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF\n"+
  ""+NORM+""+YEL+"DRAGON***"+HIR+" FFFFFFFFFFFFFFFFFFF "+NORM+"YOU "+HIR+"FFFFFFFFFF\n"+
  "  "+NORM+""+YEL+" ****"+HIR+"       FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF\n"+
  "  "+NORM+""+YEL+"*    *"+HIR+"            FFFFFFFFFFFFFFFFFFFFFFFF\n"+
  "                         FFFFFFFFFFFFFFFFFFF"+NORM+"\n",
  "#MN# opens his mouth and releases his breath weapon of:\n"+
  " \n"+
  "                 "+HIR+"FIRE!!!! "+NORM+"\n"+
  " \n",
    15,100+random(120),"other|fire");
  add_spell("Tail Slap",
  "#MN# pulls his tail back and...\n"+
  " \n"+
  "              "+RED+"S M A C K !!!!!!!"+NORM+"\n"+
  " \n"+
  "             You are hit with his mighty tail.\n",
  "#MN# pulls his tail back and...\n"+
  " \n"+
  "              "+RED+"S M A C K !!!!!!!"+NORM+"\n"+
  " \n"+
  "   The dragon swings with his mighty tail.\n",
    33,25 + random(75),"other|physical");  

}
