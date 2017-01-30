#include "../defs.h"
/* Guild Level 5 - Misc Spell
   Grafting is a healing spell which effects hp only
   random(25) + 20 healing. Healing also causes massive scarring
   upon the extra_look of the char (hey, its a necro heal!)
   TotalCost - 46sp (30sp, 1 skin, 4 blood)      */

cmd(str) {

int MAX_HP, CURR_HP;
int grch, heal;
string msg,g_part;
object ob, ob2;
object target;
int already;

ob = present(GUILD_ID,tp);
heal = 20 + random(25);
  
  if(!GOB->checklev(5,10)) return 1;
  if(!str) {
    notify_fail("Who do you want to help through grafting?\n");
     return 0;
  }
  if(!(target = present(str,environment(tp)))) {
    notify_fail(capitalize(str)+" is not here to graft.\n");
    return 0;
  }
  if(!living(target)) {
    write("You can not graft flesh to non living things.\n");
    return 1; 
  }
  if(tp->query_sp() < 30) {
    write("You do not have the spell points available for this spell.\n");
    return 1;
  }
  if((ob->query_blood() < 4) || (ob->query_skin() < 1)) {
    write("You do not have the spell components available for the spell..\n");
    return 1; 
  }
  if(GRAVESITE) {
    msg = ROD+"The Graveyard increases the power of your spell.\n";
    heal = heal + 5; 
  }
  MAX_HP = target->query_mhp();
  CURR_HP = target->query_hp();

  if(MAX_HP > CURR_HP) {
    if(target == this_player()) {
      write("You pull out a small amount of skin and some blood from your pouch and\n"+
            "skillfully apply them to your wounds.  As you begin to concentrate the\n"+
            "fibers of the dead skin begin to interlace with the living flesh closing\n"+
            "your wounds.\n");
      say(tp->query_name()+" searches through "+tp->query_possessive()+" pouch and pulls out some components.\n"+
          "Then "+tp->query_name()+" begins to mend "+tp->query_possessive()+" wounds by applying\n"+
          "dead flesh to them.\n");
    }
    else{
      write("You pull out a small amount of skin and some blood from your pouch and\n"+
            "skillfully apply them to "+target->query_name()+"'s wounds.  As you begin to concentrate the\n"+
            "fibers of the dead skin begin to interlace with the living flesh closing the wounds.\n");
      say(tp->query_name()+" heals the wounds of "+target->query_name()+" by sealing them with dead skin.\n",target);
      tell_object(target, tp->query_name()+" takes a couple of object from thier component pouch.\n");
      tell_object(target, tp->query_name()+" grafts those components onto your wounds.\n");
    }
    if(msg) write(msg);
    tp->add_spell_point(-30);
    ob->add_val(1);
    ob->add_blood(-4);
    ob->add_skin(-1);
    ob->save_me();
    target->add_hit_point(heal);
    return 1;
  } 
  else{ 
  write("You cannot graft someone who is fully healed.\n");
  return 1;
  }
}

/* removed temporarily
add_scar(){
if(!(ob2 = present("graft_obj",target))) 
ob2 = move_object(clone_object("/players/daranath/guild/obj/misc/graft_obj.c"),target);
  target->add_hit_point(heal);
  switch(random(19)) {
    case 0: g_part = "face"; break;
	case 1: case 2: g_part = "head"; break;
	case 3: g_part = "neck"; break;
	case 4: case 5: case 6: 
	case 7: g_part = "chest"; break;
	case 8: case 9: case 10: g_part = "back"; break;
	case 11: case 12: g_part = "rightarm"; break;
	case 13: case 14: g_part = "leftarm"; break;
	case 15: case 16: g_part = "rightleg"; break;
	case 17: case 18: g_part = "leftleg"; break; 
  }
    grch = call_other(ob2,"query_"+g_part);
	if(grch < 3) call_other(ob2,"set_"+g_part,grch+1);
}
*/