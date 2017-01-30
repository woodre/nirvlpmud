#include "../defs.h"

cmd(str){
int cost;
int g_level,numb;
object shield, ob;
ob = GOB;
  if(!GOB) return 0;
  if(!GOB->checklev(1,5)) return 1;
  if(!str){
    notify_fail("What would you like to evoke?\n");
    return 0;
  }
  if(str != "ghouls"){
    notify_fail("You do not know how to evoke that.\n");
    return 0;
  }
  if(present(GHOULSHIELD,tp)){
    notify_fail("You have alread evoked ghouls to protect you.\n");
    return 0;
  }
  g_level = tp->query_guild_rank();
  if(g_level > 10) g_level = 10;
  switch(g_level){
    case 0..2:  cost = 25;           break;
    case 3..5:  cost = 30;           break;
    case 6..8:  cost = 40;           break;
    case 9..10: cost = 50;           break;
  }
  if(tp->query_sp() < cost) {
    notify_fail("You do not have the spell points available for this spell.\n");
    return 0;
  }
  if( (ob->query_blood() < 3) || (ob->query_skin() < 2) ) {
    notify_fail("You do not have the spell components available for the spell.\n");
    return 0;
  }
  if(tp->query_attack()) {
    notify_fail("You can not cast this during combat!\n"); 
    return 0; 
  }
  shield=clone_object(OBJ+"/spells/spirit_armor.c");
  numb = g_level/2;
  if(numb < 3) numb = 3;
  shield->set_numof(numb);
  shield->set_time(100+random(g_level*20));
  write("You lay out a piece of skin on the ground before you.  As you chant the dark\n"+
        "word \""+BOLD+"Ghenatia"+OFF+"\", you drip the oozing blood across the skin.\n");
  say(tp->query_name()+" lays out a piece of skin on the ground and begins to pour blood\n"+
      "upon it while chanting.\n");
  call_out("summonghouls",4,({ tp,shield }) );
  tp->add_spell_point(-cost);
  ob->add_blood(-3);
  ob->add_skin(-2);
  ob->add_val(1);
  ob->save_me();
  /* had to move the object early so you can't spam the cmd and get multiples - 1/07/2004 - Wocket */
  move_object(shield,this_player());
return 1; 
}

summonghouls(things){
  tell_room(environment(things[0]),"Suddenly the skin is pushed upwards from beneath.\n");
  things[1]->activate();
}
