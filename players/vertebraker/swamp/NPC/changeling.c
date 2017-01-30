#include "../define.h"
#define MLOG "/players/vertebraker/log/Monster"
inherit "/obj/monster";
reset(arg) {
   ::reset(arg);
   set_dead_ob(TO);
   set_name("a slimy blob");
   set_alias("blob");
   set_short("a slimy blob");
   set_long(
      "  A strange puddle of goo that seems to have\n"+
      "gained the ability to speak and slide around.\n");
   set_race("changeling");
   set_level(21);
   set_wc(44);
   set_ac(16);
   set_chat_chance(15);
   set_a_chat_chance(15);
   set_gender("creature");
   set_hp(1000);
   set_ac_bonus(5);
}

init() {
   ::init();
   remove_call_out("do_change");
   call_out("do_change",5);
}
do_change() {
   string color;
   switch(random(5)) {
      case 0: color = HIM; break;
      case 1: color = HIR; break;
      case 2: color = HIB; break;
      case 3: color = HIG; break;
      case 4: color = HIY; break; }
   dump_chats();
   tell_room(USER,color+" Suddenly, "+alias+" changes its form!\n"+NORM);
   peace();
   switch(random(8)) {
      case 0:
      set_name("An innocent chicken");
      set_alias("chicken");
      set_short("An innocent little chicken");
      set_long(
         "An innocent little chicken.  It loves\n"+
         " to cluck.\n");
      load_chat("The chicken pecks around the cave.\n");
      load_chat("The chicken clucks.\n");
      load_a_chat("The chicken pecks you in the face!\n");
      load_a_chat("The chicken gets angry...\n");
      break;
      case 1:
      set_name("A grizzly bear");
      set_alias("bear");
      set_short("A roaring grizzly bear");
      set_long(
         "A lumbering grizzly bear that walks around,\n"+
         " looking for food.\n");
      load_chat("The bear growls angrily!\n");
      load_chat("The bear paws at something.\n");
      load_a_chat("The bear slashes at you with its claws!\n");
      load_a_chat("The bear roars!\n");
      break;
      case 2:
      set_name("A woolly mammoth");
      set_alias("mammoth");
      set_short("A woolly mammoth");
      set_long(
         "A HUMONGOUS woolly mammoth that lumbers around\n"+
         " looking for plants to eat.  You thought these\n"+
         " things were extinct!\n");
      load_chat("The mammoth roars...\n");
      load_chat("The mammoth blows its massive trunk!\n");
      load_a_chat("The mammoth SLASHES its tusks into your skin!\n");
      load_a_chat("The mammoth tramples over you!\n");
      break;
      case 3:
      set_name("A circus midget");
      set_alias("midget");
      set_short("A circus midget");
      set_long(
         "A short little man with a top hat and a small\n"+
         " wool suit on.  A tag on his suit says,\n"+
         "\"Tom Thumb\".\n");
      load_chat("Tom Thumb says: \"I am Tom Thumb, who the hell are you?\"\n");
      load_chat("A midget poses.\n");
      load_a_chat("The midget does a two-step on your forehead!\n");
      load_a_chat("The midget gets angry, and punches you in your stomach!\n");
      break;
      case 4:
      set_name("A "+color+"balloon"+NORM);
      set_alias("balloon");
      set_short(name);
      set_long(
         "A long, stringy balloon.\n");
      load_chat("A balloon floats...\n");
      load_a_chat("A balloon bops into you!\n");
      load_a_chat("A balloon moves out of your reach...\n");
      break;
      case 5:
      set_name("A komodo dragon");
      set_alias("dragon");
      set_short("A komodo dragon");
      set_long(
         "This short lizard is the only true dinosaur\n"+
         " left in existence.  He doesn't like intruders.\n");
      load_chat("The dragon scratches at a wall.\n");
      load_a_chat("The dragon scratches you with its claws!\n");
      load_a_chat("The dragon coughs up a puff of smoke.\n");
      break;
      case 6:
      set_name("A gas station attendant");
      set_alias("attendant");
      set_short("A gas station attendant");
      set_long(
         "A man wearing blue overalls and holding on to\n"+
         " a nozzle where gas would normally pump out of,\n"+
         " except there is no hose.  *boggle*\n");
      load_chat("Attendant says: \"Try to steal gas, eh?\"\n");
      load_a_chat("Attendant kicks you in the ribs!\n");
      load_a_chat("Attendant socks you over your head with the nozzle!\n");
      break;
      case 7:
      set_name("A cursed demon");
      set_alias("demon");
      set_short("A cursed demon");
      set_long(
         "A reddish demon with an evil glint in its eye.\n"+
         " It has four foot long claws and gets very\n"+
         " angry, very quick.\n");
      load_chat("The cursed demon roars with anger!\n");
      load_a_chat("The cursed demon scratches at you with its claws!\n");
      load_a_chat("The cursed demon gets very angry!\n");
      break; }
   call_out("do_change",10+random(5)); return 1; }
dump_chats() { chat_str = 0; a_chat_str = 0; }


peace() {
   object enemy, ob;  int x;
   ob = all_inventory(USER);
   x = 0;
   while(x < sizeof(ob)) {
      if(ob[x]->query_attack()) {
         enemy = ob[x]->query_attack();
         ob[x]->stop_fight();
         enemy->stop_fight();
         }
      x += 1;
   }
   return 1; }

monster_died() {
/*
    if(attacker_ob) write_file(MLOG, HIB + "[" + NORM + ctime()[4..15] + HIB + "] " + NORM + (string)capitalize(attacker_ob->query_real_name()) + " [" + (int)attacker_ob->query_level() + "+" + (int)attacker_ob->query_extra_level() + "] - Changeling.\n");
*/

   tell_room(USER,
      "\nThe changeling dissolves into a puddle of goo on the\n"+
      " cave floor, revealing a tiny golden ring.\n\n");
   destruct(present("corpse",USER));
   MO(CO(OBJ_DIR+"gold_ring"),USER);
   MO(CO(OBJ_DIR+"slime"),USER);
   return 1; }


status
id(string str)
{
    if(::id(str)) return 1;
    if(str == "blob") return 1;
}
