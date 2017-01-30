/* These boots is gained by winning the Elemental Test. If it seems powerful, please try
 * the Test and/or contact me.  - Snow
 * [5.25.01] Vertebraker changed hit_player dmg for earth
    special to other|earth
 */

inherit "/obj/armor.c";
#include "/players/snow/closed/color.h"
#define AMULET RED+"~ "+OFF+BLUE+"Ele"+OFF+GREEN+"ment"+OFF+BOLD+"al Ear"+OFF+GREEN+"ri"+OFF+BLUE+"ng"+OFF+RED+" ~"+OFF

reset(arg) {
  ::reset(arg);
  set_name("elemental earring");
  set_alias("earring");
  set_short(AMULET);
  set_long("");
  set_type("earring");
  set_ac(1);
  set_weight(1);
  set_value(10000);
  remove_call_out("elements");
  call_out("elements", 10);
  }

id(str){ return (::id(str) || str == "snow_elem_armor"); } /*added by Fred [10-26-03]*/

query_save_flag() { return 0; }

elements() {
  object me, att;
  if(!environment(this_object())) return;
  if(!worn) { remove_call_out("elements"); call_out("elements", 10); return 1; }
  me = environment(this_object());
  if(!me->is_player()) { remove_call_out("elements"); call_out("elements", 10); return 1; }
  att = me->query_attack();
  if(!att) { if(!random(10)) me->heal_self(5);
    remove_call_out("elements");
    call_out("elements", 10); return 1; }
  combat_effects(att);
  remove_call_out("elements");
  call_out("elements", 10);
  return 1; }

combat_effects(object ob) {
  int r;
  object att;
  att = ob;
  r = random(4);
  if(!environment() || !att) return;
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
    if(!att->is_player())
      att->heal_self(-3);
    else
      environment(this_object())->heal_self(random(5)+2);
/* makes negative wcs. removed. -Bp
    if(!att->is_player()) att->set_wc(att->query_wc()-1);
    else att->heal_self(-3); }
*/
}
  return 1; }

/* Wear func added by Fred [10-26-03] to check for Elemental Aura and
   for the new elemental armors to make sure a player can only wear
   one piece at a time.
*/

wear(str)
{
  object *inv, ob;
  int x,z;
  inv = all_inventory(this_player());
  z = sizeof(inv);
  if(this_object()->id(str)) {
  if(!present("elemental aura", this_player())) {
    write("The "+AMULET+" burns you with its power!\n");
    return 1; }
  for(x=0;x<z;x++){
   if((string)inv[x]->is_elem_armor() && inv[x]->query_worn() && inv[x] != this_object()) {
         write("You are already wearing a piece of elemental armor.\n");
         return 1;
       }
     }
  if(str == "earring" || str == "elemental earring"){  
   ::wear(str);
   return 1; }
 }
}

is_elem_armor(){ return 1; }

string short() {
  return AMULET + (this_object()->query_worn() ? " "+GREEN+"("+OFF+"worn"+GREEN+")"+OFF : ""); 
}

void long() {
  object a, b;

  write(
    "  You see before you a legendary earring, molded from the very\n"+ 
    "elements themselves, forged by the gods of Nirvana for those mighty\n"+ 
    "and worthy.  Crafted from soft metal, they have been reinforced\n"+
    "with plates of blue-green Elementite. Flickering white specks float\n"+
    "about them. ");
  if((a = this_player()) && (b = environment()) && (b == a)) {
    write("\n  You can sense a "+BLUE+"mys"+GREEN+"tic"+OFF+BOLD+"al "+OFF+GREEN+"ene"+BLUE+"rgy"+OFF+" coursing through the earring.");
    if(present("elemental aura",environment(this_object())))
      write("  Worn by\n"+
            "those with both valor and might, this earring will protect anyone so brave\n"+
            "to have faced the Five Elements and defeated them in battle.");
  }
  write("\n");
  ::long();
}

