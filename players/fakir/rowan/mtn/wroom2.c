
#include "/players/molasar/rowan/room/exit.h"

#define TRGEN "/players/molasar/rowan/obj/tr_gen"

reset(arg) {
   if(!arg)
    set_light(0);
  extra_reset();
}

extra_reset() {
   object chest, mace, sword;
   object heal, money;
   int i;

   chest = present("chest");
   if(chest && !first_inventory(chest))
     destruct(chest);
   if(!present("chest")) {
     chest = clone_object("players/molasar/rowan/obj/chest");
     chest->set_name("chest");
     chest->set_short("A large wooden chest");
     chest->set_long("A heavy wooden chest reinforced with metal straps.\n");
     chest->set_key_id("mol_chest_key");
     chest->set_locked(1);
     TRGEN->get_magic2(chest);
     TRGEN->get_magic3(chest);
     TRGEN->get_magic3(chest);  
     TRGEN->get_magic5(chest);
     TRGEN->get_scroll1(chest);
     TRGEN->get_scroll1(chest);  
     TRGEN->get_money(5000, chest);
     sword = clone_object("players/sandman/paladin/obj/weapon");
     sword->set_name("sword");
     sword->set_alias("longsword");
     sword->set_short("A steel longsword");
     sword->set_long("A longsword of superb craftsmanship.\n");
     sword->set_weight(1);
     sword->set_class(16);
     sword->set_weapon_type("sword");
     sword->set_value(800);
     move_object(sword, chest);
     mace = clone_object("players/sandman/paladin/obj/weapon");
     mace->set_name("mace");
     mace->set_short("An iron mace");
     mace->set_long("A small but heavy iron mace.\n");
     mace->set_class(17);
     mace->set_weapon_type("mace");
     mace->set_value(800);
     move_object(mace, chest);
     i = 0;
     while(i < 3) {
       heal = clone_object("obj/heal");
       move_object(heal, chest);
       i += 1;
     }
     money = clone_object("obj/money");
     money->set_money(5000+random(1000));
     move_object(money, chest);
     move_object(chest, this_object());
   }
}

short() { return "A storage room"; }

long() {
  write("You are in a storage room.\n");
  write("     There is one obvious exit:  west\n");
}

init() {
   add_exit("west","/players/molasar/rowan/mtn/wroom1");
}

move() {
  string verb;
  verb = query_verb();
  if(verb == "west") {
    this_player()->move_player("west#players/molasar/rowan/mtn/wroom1");
    return 1;
  }
}


