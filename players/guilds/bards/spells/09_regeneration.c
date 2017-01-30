#include "/players/guilds/bards/def.h"

status main(string str) {
  object ob;
  object regen_ob;
  if (spell(-194, 9, 100) == -1)
    return 0;

  if(!str){       
    ob=TP;
  } else {
    ob=present(str,environment(TP));
  }
  if(!ob || !ob->is_player())
    FAIL("You may only grant regeneration to players.\n");
  
  regen_ob=present("bardic_regeneration_object",ob);
  if(!regen_ob) {
    regen_ob=clone_object(OBJ+"regen.c");
    move_object(regen_ob,ob);
  }
  if((int)regen_ob->query_strength() > 50) {
    if(ob==TP) {
      FAIL("Your regeneration is too strong to be renewed.\n");
    } else {
      FAIL(NAME(ob)+"'s regeneration is too strong to be renewed.\n");
    }
  }

  tell_room(environment(TP),"\n\n");
  write("You play the Rhapsody of Regeneration upon your " + INST + ".\n" +
      "You speak one of the Words of Power.\n");
  say(tp + " plays a Rhapsody upon " + POSS(TP) + " " + INST + ".\n" + tp +
    " speaks one of the Words of Power.\n\nYou shiver.\n");

  tell_object(ob,"Your body begins to regenerate.\n");
  regen_ob->add_strength(200);
  regen_ob->start_regen();
        
  call_other(TP, "add_spell_point", -100);
  return 1;
}
