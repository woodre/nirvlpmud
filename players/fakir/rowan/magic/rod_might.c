

/*
 * ROD OF MIGHT (1/24/94)
 * You can change the rod into different types of paladin weapons
 * each type has a different wp.
 * You can also drain random(6)+5 hp from attacker up to 5 times
 */

/* Changed to paladin_old to get it to load -Snow 10/99 */
inherit "players/sandman/paladin_old/obj/weapon";

int charges;

reset(arg) {
   if(arg) {
      charges += 1 + random(2);
      return;
   }
   set_name("rod");
   set_alias("rod");
   set_short("A rod of might");
   set_long("You can change the rod into three different types of\n"+
            "weapons:  axe, mace, and sword.  Usage: change <weapon>\n"+
            "In addition you can drain life from a monster to a limit.\n"+
            "Usage: drain <monster>\n");
   set_weapon_type("lance");
   set_class(12);
   set_value(2500);
   set_hit_func(this_object());
   charges = 5;
}

init() {
   add_action("change","change");
   add_action("drain","drain");
   ::init();
}

change(str) {
   if(!str) {
     set_short("A rod of might");
     set_alias("rod");
     set_class(12);
     set_weapon_type("lance");
     set_long("You can change the rod into three different types of\n"+
            "weapons:  axe, mace, and sword.  Usage: change <weapon>\n"+
            "In addition you can drain life from a monster to a limit.\n"+
            "Usage: drain <monster>\n");
     write("Ok.\n");
     return 1;
   }
   if(str != "sword" && str != "mace" && str != "axe") {
     write("You may only change the rod to a sword, mace, or axe.\n");
     return 1;
   }
   if(wielded || offwielded) {
     write("You must unwield your weapon first.\n");
     return 1;
   }
   if(str == "sword") {
     set_weapon_type("sword");
     set_alias("sword");
     set_short("A glowing sword");
     set_class(14);
     set_long("You can change the rod into three different types of\n"+
            "weapons:  axe, mace, and sword.  Usage: change <weapon>\n"+
            "In addition you can drain life from a monster to a limit.\n"+
            "Usage: drain <monster>\n");
     write("Ok.\n");
     return 1;
   }
   if(str == "mace") {
     set_weapon_type("mace");
     set_alias("mace");
     set_short("A glowing mace");
     set_class(15);
     set_long("You can change the rod into three different types of\n"+
            "weapons:  axe, mace, and sword.  Usage: change <weapon>\n"+
            "In addition you can drain life from a monster to a limit.\n"+
            "Usage: drain <monster>\n");
     write("Ok.\n");
     return 1;
   }
   if(str == "axe") {
     set_weapon_type("axe");
     set_alias("axe");
     set_short("A glowing battle-axe");
     set_class(16);
     set_long("You can change the rod into three different types of\n"+
            "weapons:  axe, mace, and sword.  Usage: change <weapon>\n"+
            "In addition you can drain life from a monster to a limit.\n"+
            "Usage: drain <monster>\n");
     write("Ok.\n");
     return 1;
   }
}

drain(str) {
   object target, dest;

   if(!str)
     return 0;
   if(!wielded) {
     write("You must wield the rod first.\n");
     return 1;
   }
   target = find_living(str);
   dest = environment(this_player());
   if(!target || !present(target, dest)) {
     write(capitalize(str)+" is not here.\n");
     return 1;
   }
   if(!target->query_npc())
     return 0;
   if(charges <= 0) {
     write("The rod of might is out of charges.\n");
     return 1;
   }
   write("A burst of energy strikes your foe.\n");
   tell_room(environment(this_player()), capitalize(str)+
       " is hit by a bolt of energy.\n");
   target->hit_player(random(6)+5);
   charges -= 1;
   return 1;
}

weapon_hit(attacker) {
   if(this_object()->query_weapon_type() != "sword")
     return 0;
   if(this_player()->query_alignment() > 0 
                          && attacker->query_alignment() < 0) 
     if(30 < random(100)) {
        write("The sword flares brightly as it strikes your foe!\n");
        return 4;
     }
   return 0;
}

