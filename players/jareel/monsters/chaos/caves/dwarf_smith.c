inherit "/obj/monster.c";
#include "/players/jareel/define.h"

  int hammer;

  
reset(arg)  {

  string str;
  object gold;
    ::reset(arg);
  if(arg) return;

  set_name("groum");
  set_alias("smith");
  set_alt_name("blacksmith");
  set_race("dwarf");
  set_short("Groum Stonebeard - Master Dwarven Blacksmith.");
  set_long(
    "Short, stout, and muscular, Groum is the pure image of a\n"+
    "dwarven blacksmith.  A dark soot covers his leathery skin.\n"+
    "His arms mucles bulge as he swings his hammer, dragging his\n"+
    "gey beard over the floor as he moves about his workshop.  It\n"+
    "is of little wonder why Mondar only uses this blacksmith.\n"+
    "\n");  
  set_level(20);
  set_hp(800);
  set_al(0);
  MOCO("/players/jareel/weapons/chaos/cave/groum_hammer.c"),this_object());
    init_command("wield hammer");
  set_wc(50);
  set_ac(52);
  set_heal(25,1);
  set_aggressive(0);
  set_heart_beat(1);
  set_chat_chance(5);
    load_chat("Groum says: You needs a Matrix?  You have come to the right place.\n");
    load_chat("Groum wipes his brow.\n");
    load_chat("Groum says: Ill fix that weapon.\n");
  gold = clone_object("obj/money");
  gold->set_money(random(2000) + 1000);
  move_object(gold,this_object());
}

init(){
  ::init();
    add_action("ask_me", "ask");
    add_action("fix", "fix");
    add_action("matrix", "matrix");
}

matrix(string str) {

  int cost;
  object ob, wep;

    ob=present(str,this_player());
      if(!ob) ob = present(str,this_object());
      if(!ob) {
        write("Groum says: Thats not hear come back when you wont waste my time.\n");
      return 1;
      }

   if(!ob->weapon_class()){ write("Groum says: Thats not a wep dumbass\n"); return 1; }
   
   if(ob->query_wielded()){ 
     write("Groum says: Um you gonna hit me, unwield that shit.\n");
   return 1;
   }

   if(ob->query_shadowed()){ write("Groum says: Nice try punk.\n"); return 1; }
     cost = 5000;
   if(this_player()->query_money() < cost) {
     write("Groum says: You need more cash punk, I ain't cheep.\n");
   return 1;
   }
   this_player()->add_money(-cost);

   wep = clone_object("/players/jareel/general_stuff/wepshad.c");
   wep->add_shadow(ob);
   write(
     "Groum grabs the "+str+" in one hand...\n"+
     "Groum says: This will help you a lot.\n"+
     "Groum engraves some runes over your sword.\n"+
     "Groum gives the weapon back.\n");
   return 1;
   }


fix(str) {

  int cost;

  object ob;

  if (!str) return 0;
      
  ob=present(str,this_player());
 
  if(!ob) ob = present(str,this_object());
  if(!ob) {
    write("Groum says: I don't see that shit.\n");
  return 1;
  }

  if(ob->query_wielded()){ 
    write("Groum says: Unwield that shit.\n");
  return 1;
  }
 
  if(!ob->fix_weapon()) {
write("Groum say: That shit ain't broken, you're a fucken moron.\n");
  return 1;
  }

  cost = 500;
    if (this_player()->query_money() < cost) {
      ob->re_break();
        write("Groum says: I don't do this shit for free Bitch.\n");
    return 1;
    }
    this_player()->add_money(-500);
    write(
      "Groum takes "+str+" in one hand grabs his hammer and...\n\n\n"+
 BOLD+"<-><-><-><-><-><-><-><-> C L A N G <-><-><-><-><-><-><-><->"+NORM+"\n\n\n"+
      "Groum returns it to your waiting grasp.\n"+
      "Groum say: Treat your weapon better next time.\n");
    return 1;
    }

  query_limited_shadow(){ return 1; }

ask_me(str){
  if(!str){ 
    write("Ask who?\n");
  return 1;
  }

  if(str == "groum" || str == "smith" || str == "dwarf"){
    write(
      "Groum says,\n"+
  HIK+"   'I have seen many people, and you are one of the scrubbiest ever.\n\n"+
      "    I can fix any weapon that is broken, unless your a fool,\n"+
      "    and mangle it. That costs you 500 coins.'\n\n"+
      "    I can add a dark 'matrix' to your weapon.  That cost is 5000 coins.\n"+
      "    You may not be such a scrub with my help, but I could be wrong'"+NORM+"\n"); 
    return 1;
    }
    write("What are you asking?\n");
    return 1;
}

