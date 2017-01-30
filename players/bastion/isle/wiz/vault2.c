
#define OB "/players/bastion/isle/wiz/vault1"
object field, staff, wand, armor, money;

reset(arg) {
     object book;
     if(!arg)
          set_light(1);
     if(present("staff")) destruct(present("staff"));
     if(present("wand")) destruct(present("wand"));
     if(present("armor")) destruct(present("armor"));
     if(present("money")) destruct(present("money"));
     if(!present("journal")) {
          book=clone_object("obj/treasure");
          book->set_id("journal");
          book->set_alias("book");
          book->set_short("a small, leather book");
          book->set_long("It appears to be a personal journal.\n");
          book->set_value(100);
          book->set_weight(1);
          move_object(book, this_object()); }
     if(!present("field")) {
          field=clone_object("players/bastion/obj/cont");
          field->set_name("force field");
          field->set_alias("field");
          field->set_short("A shimmering blue force field");
          field->set_long("The force field forms a formidible barrier.\n");
          field->set_max_weight(10000);
          field->set_cant_put(1);
          staff=clone_object("players/bastion/closed/staff");
          staff->set_can_drop(1);
          armor=clone_object("obj/armor");
          armor->set_name("elven chainmail");
          armor->set_alias("chainmail");
          armor->set_short("Elven chainmail");
          armor->set_long("The chain is well-wrought, and very light.\n");
          armor->set_ac(4);
          armor->set_value(10000);
          armor->set_save_flag(0);
          wand=clone_object("players/bastion/obj/genwand");
          wand->set_name("wand of fireballs");
          wand->set_alias("wand");
          wand->set_short("A platinum wand");
          wand->set_info("Wand of fireballs");

          wand->set_spell_mess1((this_player() ? this_player()->query_name() : "Someone") + 
               " casts a fireball.");
          wand->set_spell_mess2("You cast a fireball with the wand.");
          wand->set_spell_dam(random(40));
          wand->set_charges(20 + random(15));
          wand->set_weight(1);
          wand->set_value(3000);
          money=clone_object("obj/money");
          money->set_money(2000 + random(1500));
          move_object(field, this_object());
          move_object(staff, field);
          move_object(wand, field);
          move_object(armor, field);
          move_object(staff, field);
          move_object(money, field);
      }
/*
          transfer(staff, field);
          transfer(armor, field);
          transfer(wand, field);
          transfer(money, field); }
*/
     security();
}

short() { return "Inside Vault"; }

long() {
     write("You stand inside a metalic room, twenty feet on a side.\n"+
           "Various artifacts and pieces of treasure are stacked about\n"+
           "the room, protected by shimmering blue force fields.\n");
     return 1;
}

realm() { return "NT"; }

security() {
  object ob;
  ob=first_inventory(this_object());
  while(ob) {
     if(ob->is_player()) {
         tell_object(ob, "The vault's security system resets itself.\n");
         if(call_other(ob, "query_level") < 50) {
            move_object(ob, "players/bastion/isle/wiz/prison_hall");
            tell_room(this_object(), ob->query_name() + " disappears.\n");
            tell_object(ob, "You suddenly find yourself elsewhere.\n"); }
      }
     ob=next_inventory(ob); }
     ob=find_object("players/bastion/isle/wiz/prison_hall");
  if(ob)
  ob->reset(1);
     if (present("door")) {
          ob=present("door");
          ob->reset();
     }
     return 1;
}
