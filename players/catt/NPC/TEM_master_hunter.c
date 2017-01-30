inherit "obj/monster";
#include "/players/catt/AREAS/base_defines.c"

reset(arg) {
  object money;
  ::reset(arg);
  if(arg) return;
  set_name("master hunter");
  set_alias("hunter");
  multipleIds = ({"master","hunter","master hunter"});
  set_short("Master Hunter");
   set_long(format("This is the master hunter of zombies and only "+
            "he can tell you if you are fit to be a hunter. "+
         "He is a goblin of massive stature. Just looking "+
         "at him makes you nervous. He just looks at you calmly. "+
            "Do not fight the master. He is a very bad enemy "+
            "to make.\n"));
  set_level(23);
  set_race("goblin");
  set_ac(20);
  set_wc(40);
  set_hp(1200);
  set_hp_bonus(200);
  set_heal(5,15);
  set_chat_chance(10);
  load_chat("Master Hunter says: Are you a zombie hunter?\n");
  load_chat("Master Hunter intones: Don't try me. I have had recent training, "+
 "making me a meaner and tougher opponent.\n");
   add_spell("orcbite",
      "#MN# jumps on you and bites you as hard as he can on the head.\n",
      "#MN# jumps on #TN# and biting #TP# viciously in the head.\n",
      15,30,0);

   add_spell("hammerfist",
      "#MN# raises his fist high in the air and slams you with it.\n",
      "#MN# raises his fist high in the air and slams #TN# with it.\n",
      25,20,0);

   set_multi_cast(0);
  money = clone_object("obj/money");
  money->set_money(5000);
  move_object(money,this_object());
}

init() {
   ::init();
   add_action("tunnel","tunnel");
}

tunnel() {
  object who, who_level;
  who = this_player();
  who_level = who->query_level();
  if(who_level > 5) {
    write("Master Hunter says: You are too experienced to be a hunter.\n");
    move_object(who, environment(this_object()));
    return 1; /* Rumplemintz */
  }
}
