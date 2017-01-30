#include "std.h"
#define OB "/players/bastion/isle/wiz/vault2"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
     object ob, ob2;
     if(!present("door")) {
          ob=clone_object("/players/bastion/obj/newdoor");
          ob->set_name("vault door");
          ob->set_alias("door");
          ob->set_key_name("strange key");
          ob->set_long("A heavy, metallic door inscribed with runes.\n");
          ob->set_dest_key(1);
          ob->set_dest_dir("west");
          ob->set_dest_room("players/bastion/isle/wiz/vault2");
          ob->set_can_lock(1);
          ob->set_shield(1);
          ob2=clone_object("players/bastion/obj/newdoor");
          ob2->set_name("vault door");
          ob2->set_alias("door");
          ob2->set_key_name("strange key");
          ob2->set_long("A heavy, metallic door inscribed with runes.\n");
          ob2->set_dest_dir("east");
          ob2->set_dest_room("players/bastion/isle/wiz/vault1");
          ob2->set_can_lock(1);
          ob2->set_shield(1);
          ob->set_partner_ob(ob2);
          ob2->set_partner_ob(ob);
          ob->set_is_locked(1);
          ob2->set_is_locked(1);
          move_object(ob, this_object());
          move_object(ob2, OB);
     }
     security();
}


ONE_EXIT("players/bastion/isle/wiz/prison_hall", "east",
     "Vault Entrance",
     "You enter a small, bare room, dimly lit by a single fixture on\n"+
     "the ceiling. A large, vaulted door leads west, while the hallway\n"+
     "is east.\n",
     1)



realm() { return "NT"; }

security() {
  object ob;
  ob=first_inventory(this_object());
  while(ob) {
     if(ob->is_player()) {
         tell_object(ob, "The vault's security system resets itself.\n");
         if(call_other(ob, "query_level") < 40) {
            move_object(ob, "players/bastion/isle/wiz/prison_hall");
            tell_room(this_object(), ob->query_name() + " disappears.\n");
            tell_object(ob, "You suddenly find yourself elsewhere.\n"); }
      }
     ob=next_inventory(ob); }
     ob=find_object("players/bastion/isle/wiz/prison_hall");
     ob->reset();
     ob=present("door");
     ob->reset();
     return 1;
}
