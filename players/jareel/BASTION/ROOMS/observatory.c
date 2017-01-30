
#include "std.h"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
     object witch, broom, pendant;
     if(!present("kokiri")) {
          witch=clone_object("obj/monster");
          witch->set_name("kokiri");
          witch->set_alias("witch");
          witch->set_short("Kokiri the witch");
          witch->set_long("You see a young woman dressed in a jet black gown, "+
               "hair\nflowing over her shoulders the same shade. She wears a\n"+
               "small silver pendant as her only adornment.\n");
          witch->set_level(19);
          witch->set_hp(475);
          witch->add_money(500);
          witch->set_al(500);
          witch->set_chance(20);
          witch->set_spell_dam(random(30));
          witch->set_spell_mess2("You are hit by a lightning bolt.");
          witch->set_spell_mess1("Kokiri casts a lightning bolt.");
          witch->set_chat_chance(10);
          witch->load_chat("Kokiri says: Excuse me. I have to adjust an "+
               "observation.\n");
          witch->load_chat("Kokiri walks over to a terminal and types "+
               "something in.\n");
          broom=clone_object("obj/weapon");
          broom->set_name("broom");
          broom->set_alt_name("witch's broom");
          broom->set_short("A witch's broom");
          broom->set_long("This is Kokiri's broom.\n");
          broom->set_class(16);
          broom->set_weight(1);
          broom->set_value(3500);
          pendant=clone_object("obj/armor");
          pendant->set_type("amulet");
          pendant->set_id("pendant");
          pendant->set_alias("silver pendant");
          pendant->set_ac(2);
          pendant->set_value(3000);
   pendant->set_weight(1);
          pendant->set_short("A silver pendant");
          pendant->set_info("Pendant of protection +2");
          move_object(witch, this_object());
          transfer(broom, witch); 
          transfer(pendant, witch);
          command("wield broom", witch); 
          command("wear pendant", witch); 
          witch->set_wc(28);
          witch->set_ac(16); }
}

ONE_EXIT("players/bastion/isle/wiz/solarium", "down",
     "Observatory",
     "You enter a sterile looking room, the walls banked by strange devices\n"+
     "and machines. The dome of the ceiling is transparent from this side,\n"+
     "revealing the skies above. A large cylindrical device, with a small\n"+
     "chamber in its base capable of seating one, stands in the center of\n"+
     "the room. The telescope currently protrudes through a slit running\n"+
     "from the top of the dome. A young woman bustles around adjusting\n"+
     "various pieces of equipment. A staircase leads downward.\n",
     1)
