/*
   A spell to raise the dead players
   cost 100sp 10blood(20sp) 5skin(35sp) 2eyes(40sp) 1heart(30sp) 1spine(30sp)
   total cost 255 sp
   full heal to player.

*/

#include "../defs.h"

cmd(str) {
object ob;
object deadguy;

ob = GOB;
  if(!GOB->checklev(9,15)) return 1;
  if(tp->query_sp() < 100) {
    notify_fail("You do not have the spell points to raise the dead.\n");
    return 0; 
  }
  if((ob->query_blood() < 10) || (ob->query_skin() < 5) || (ob->query_eye() < 2) || 
     (ob->query_heart() < 1) || (ob->query_spine() < 1)) {
     notify_fail("You do not have the components available for this spell.\n");
     return 0; 
  }
  if(!str){
    notify_fail("Who would you like to resurrect?\n");
    return 0;
  }
  deadguy = present(str,environment(tp));
  if(!deadguy){
    notify_fail(capitalize(str)+" is not here to be resurrected.\n");
    return 0; 
  }
  if(!deadguy->is_player()) {
    write("That is not something you can raise from the dead.\n");
    return 1; 
  }
  if(!deadguy->query_ghost()) {
    write("You cannot cast this spell on someone who is still alive.\n");
    return 1; 
  }
  write("  You draw a "+BOLD+"circle"+OFF+" on the ground in "+BOLD+"salt"+OFF+" and begin to lay out the\n"+
        "fresh body parts within the circle.  As you whisper some enchantments,\n"+
        "your eyes begin to glow red. You then pour blood over your patchwork\ncorpse.\n");
  say("  "+tpn+" draws a "+BOLD+"circle"+OFF+" on the ground in "+BOLD+"salt"+OFF+" and begins to lay out the\n"+
        "fresh body parts within the circle.  As "+tp->query_pronoun()+" whispers some enchantments, \n"+
        tp->query_possessive()+" eyes begin to glow red.  "+capitalize(tp->query_pronoun())+" then pours blood over the patchwork\ncorpse.\n");
  call_out("raiseme",3,deadguy);
  tp->add_spell_point(-100);
  ob->add_val(3);
  ob->add_blood(-10);
  ob->add_heart(-1);
  ob->add_skin(-5);
  ob->add_spine(-1);
  ob->add_eye(-2);
  ob->save_me();
  return 1; 
}

raiseme(deadguy){
  if(deadguy){
    tell_room(environment(deadguy),"\n  An eerie, "+GRN+"green mist"+OFF+" rises from the circle as flesh begins to rebuild\n"+
                                 "itself around "+deadguy->query_name()+"'s soul.  Piece by piece a new body is assembled.\n\n"+OFF);
    call_out("raiseme2",3,deadguy);
  }
}

raiseme2(deadguy){
  if(deadguy){
    tell_room(environment(deadguy),"  Just as the last strand of flesh attaches itself, there is a brilliant\n"+
            BOLD+"flash"+OFF+" of light"+OFF+".\n\n"+OFF);
    move_object(clone_object(OBJ+"/misc/resurrectob.c"),deadguy);
    command("necroresurrectme",deadguy);
    deadguy->heal_self(500);
  }
}