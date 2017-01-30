#include "defs.h"

inherit MONSTER;

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("p'lila");
  set_alt_name("waittress");
  set_short("P'lila the Waittress");
  set_long("P'lila is a strong and healthy young p'kalian woman.  Her skin is a\n"+
           "vibrant avocado green, and her eyes are a cute shade of pink.  She\n"+
           "wears a faded blue apron over the traditional white cotton blouse and\n"+
           "skirt of p'kalian women.  She seems to have a sashay as she walks\n"+
           "about.\n");
  set_gender("female");
  set_race("p'kalian");
  set_level(12);
  set_wc(16);
  set_ac(9);
  set_hp(180);
  set_al(350);
  add_money(500+random(100));
  set_chat_chance(5);
  load_chat("P'lila hurries among the tables serving drinks.\n");
  load_chat("P'lila stops a moment to gossip with a group of young p'kalians.\n");
  load_chat("You hear a constant low murmur among the p'kalians.\n");
  add_talk("p'chilik", "P'lila sighs.  \"Isn't he dreamy?\"\n");
  add_talk("key", "P'lila says: You are a stranger to our village.  I'm not sure I\n"+
                  "\tshould "+BOLD+"trust"+NORM+" you with it.\n");
  add_talk("trust","P'lila says: If you do something "+BOLD+"brave"+NORM+" for me, then I will know for\n"+
                   "\tsure that I can trust you.\n");
  add_talk("brave", "P'lila says: My brother was kidnapped by some of the Sultan's\n"+
                    "\tsoldiers.  I will give you the key to the well if you prove\n"+
                    "\tthat you are a friend to my people by rescuing my brother.\n");
  add_talk("p'salin", "P'lila says: He is such an old lecher.\n");
  add_talk("p'kolitor", "P'lila says: He is almost as bad as P'salin!\n");
  add_talk("tully", "P'lila says: He has many stories of places beyond the mountains.\n");
  add_talk("qadlfik", "P'lila says: It is very good for a growing P'kalian.\n");
}

init() {
  ::init();
  call_out("quest_check",3,this_player());
}

quest_check(play) {
  object ob;
  ob=present("quest token",play);
  if(ob) {
    tell_object(play,
"You give P'lila the tiny statue and tell her her brother's message.\n"+
"She hugs you around the neck and says,\n"+
"\"Thank you, thank you!  Here is the key, friend to all P'kalians!\"\n");
    move_object(clone_object(OBJ_PATH+"key4.c"),play);
    destruct(ob);
  }
}
