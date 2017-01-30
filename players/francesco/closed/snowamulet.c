/* This amulet is gained by winning the Elemental Test. If it seems powerful, please try
 * the Test and/or contact me.  - Snow
 * [5.25.01] Vertebraker changed hit_player dmg for earth
    special to other|earth
 */

inherit "/obj/armor.c";
#include "/players/snow/closed/color.h"

reset(arg) {
  ::reset(arg);
  set_name("elemental amulet");
  set_alias("amulet");
  set_short(RED+"~ "+OFF+BLUE+"Ele"+OFF+GREEN+"ment"+OFF+BOLD+"al Am"+OFF+GREEN+"ul"+OFF+
            BLUE+"et"+OFF+RED+" ~"+OFF);
  set_long("\n\tThe Elemental Amulet.\n"+
    "This amulet glows with a shimmering light.\n");
  set_type("misc");
  set_ac(2);
  set_weight(1);
  set_value(10000);
  remove_call_out("elements");
  call_out("elements", 10);
  }

query_save_flag() { return 0; }

elements() {
  object me, att;
  if(!environment(this_object())) return;
  if(!worn) { call_out("elements", 10); return 1; }
  me = environment(this_object());
  if(!me->is_player()) { call_out("elements", 10); return 1; }
  att = me->query_attack();
  if(!att) { if(!random(10)) me->heal_self(5);
    call_out("elements", 10); return 1; }
  combat_effects(att);
  call_out("elements", 10);
  return 1; }

combat_effects(object ob) {
  int r;
  object att;
  att = ob;
  r = random(4);
  if(!environment()) return;
  if(!r) {
    tell_room(environment(ob),
    BROWN+"\t%*% %*% Stones fly from the earth to strike "+att->query_name()+"! %*% %*%\n"+OFF);
    att->hit_player(random(10) + 6, "other|earth");
}
  if(r == 1) {
    tell_object(environment(this_object()),
    BLUE+"\t_,' _,' Water cleanses and purifies your body! ',_ ',_\n"+OFF);
    environment(this_object())->heal_self(random(5)+2); }
  if(r == 2) {
    if(environment(this_object()) && environment(this_object())->is_player()) {
      environment(this_object())->add_stuffed(-3);
      environment(this_object())->add_soaked(-3);
      tell_object(environment(this_object()),
        RED+"\t * * * Flame cleanses your system * * *\n"+OFF); }
    }
  if(r == 3) {
    tell_room(environment(att),
   BOLD+"\t<-> Blades parry some of "+att->query_name()+"'s attacks! <->\n"+OFF);
    if(!att->is_player()) att->set_wc(att->query_wc()-1);
    else att->heal_self(-3); }
  return 1; }
