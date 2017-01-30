#include "../defs.h"
/* Guild Level 4 - Misc Spell
   Cloak of Confusion lowers the targets WC while slightly
   raising the AC of the target. 
   TotalCost - 250 sp (150sp, 2 hearts, 1 soul)    */
cmd(str) {
int dam, val;
object ob, ob2, att;
string caster_msg,room_msg,target_msg;
  ob = GOB;
  if(!ob) return;
  if(!GOB->checklev(9,15)) return 1;
  if(!str){
    if(tp->query_attack()) att = tp->query_attack();
    else{
      notify_fail("Who would you like to wither?\n");
      return 0; 
    } 
  }
  else{
    att = present(str, environment(tp)); 
  }
  if(tp->query_spell_dam()){
    notify_fail("");
    return 0;
  }
  if(!att){
    notify_fail("There is no "+str+" here to wither.\n"); 
    return 0; 
  }
  if(!att->is_npc()){
    notify_fail("That is not something you can attack.\n");
    return 0;
  }
  if(tp->query_sp() < 150) {
    write("You do not have the spell points available for this spell.\n");
    return 1;
  }
  if((ob->query_soul() < 1) || (ob->query_heart() < 2)) {
    write("You do not have the spell components available for the spell.\n");
    return 1;
  }
  val = 1;
  caster_msg = "You take out two hearts from your pouch.  Some how you manage to slip one\n"+
               "inside the other as you insert a small soul crystal.  The word \"Visth\"\n"+
               "is uttered as you begin to twist the hearts.  Blood begins to pour out \n"+
               "the rips that are begining to form.  You then crush a soul crystal, releasing\n"+
               "it's capture.\n";
  
  room_msg = tpn+" removes two hearts from "+tp->query_possessive()+" pouch.  "+capitalize(tp->query_pronoun())+" then manages to\n"+
             "slips one inside the other and insert a small crystal.  As "+tpn+" twists the\n"+
             "hearts you hear a small crunch.\n";

  target_msg = "";
  if(BLOODMOON) {
    caster_msg+=ROD+"The Bloodmoon increases the power of your spell.\n";
    val += 1; 
  }
  if(GRAVESITE) {
    caster_msg+=ROD+"The Graveyard increases the power of your spell.\n";
    val += 1; 
  }  
  tp->add_spell_point(-150);
  ob->add_val(val);
  ob->add_heart(-2);
  ob->add_soul(-1);
  ob->save_me();
  call_out("wither2",2,({tp,ob,att}));
  write(caster_msg);
  say(room_msg);
  tp->set_spell_dam(1);
return 1; 
}

wither2(arg){
int oldhp,newhp;
  oldhp = arg[2]->query_hp();
  newhp = oldhp/2;
  if(newhp > 300) newhp = 300;
  arg[2]->heal_self(-newhp);
    tell_room(environment(arg[0]),arg[2]->query_name()+BOLD+" buckles in pain.\n"+OFF+
                       "A "+BOLD+"white mist"+OFF+" begins to emminate from "+arg[2]->query_possessive()+" pores as "+arg[2]->query_possessive()+" skin begins to shrivel.\n"+
                       "You can see "+arg[2]->query_possessive()+" body withering with each passing second.\n->>"+OFF);
    arg[2]->attack_object(arg[0]);
}
