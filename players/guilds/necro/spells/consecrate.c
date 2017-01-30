#include "../defs.h"
/* Guild Level 3 - basic spell
   Spell allows a necromancer to declare that a certain area
   is a gravesite. Moves gsite_ob to area.
   TotalCost - 104sp (100 sp, 2 blood)    */
cmd(str) {
object ob;

ob = GOB;

  if(!GOB) return 0;
  if(!GOB->checklev(3,7)) return 1;
  if(str != "gravesite"){
    notify_fail("What would you like to consecrate?\n");
    return 0;
  }
  if(tp->query_sp() < 100) {
    notify_fail("You don't have the spell points available for this spell.\n");
    return 0;
  }
  if(ob->query_blood() < 2) {
    notify_fail("You don't have the components available for this spell.\n");
    return 0;
  }
  if(!creator(environment(tp))){ 
    notify_fail("You cannot declare a gravesite within the village.\n");
    return 0;
  }
  if(GRAVESITE){
    notify_fail("This area is already a declared gravesite.\n");
    return 0; 
  }
  write("You take some blood and salt from your component pouch and draw a symbol upon\n"+
        "the ground.  As you speak a few arcane words you consecrating this area with \n"+
        "the Realm of Death.\n");
  say(tpn+" draws a demonic symbol on the ground and speaks a few words in from\n"+
          "arcane language.\n");
  call_out("raise_pillar",3,environment(tp));
  tp->add_spell_point(-100);
  ob->add_val(3);
  ob->add_blood(-2);
  ob->save_me();
  return 1; 
}

raise_pillar(room){
  tell_room(room,"The ground begins to shake and crack as a pillar of stone rises from\n"+
                 "within.  "+BOLD+"A gravesite has been declared.\n"+OFF);
  move_object(clone_object(OBJ+"/misc/gsite_ob.c"),room);
}