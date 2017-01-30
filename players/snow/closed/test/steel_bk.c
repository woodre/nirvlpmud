/*
* Steel, the final test
*/

/* changed steels special to do more damage, and use dmg type :)
 -Jaraxle [7/18/03]  */
#include "/players/dune/closed/guild/DEFS.h"

inherit "/obj/monster";

object testvic;

reset(arg) {
   ::reset(arg);
   if (!arg) {
 
     set_name("steel");
    set_short(BOLD+"Steel"+OFF);
     set_race("fifth");
     set_alias("blades");
     set_long(
"\tYou look upon your fifth test, Steel.\n"+
"Whirling blades of steel blur before your eyes.\n");
     set_level(20);
     set_ac(35);
     set_wc(55);
     set_hp(1000);
/* Added R15 - Jaraxle [9/6/03] */
    set_heal(3,15+random(15));
     set_al(0);
     set_aggressive(1);
     set_dead_ob(this_object());
   }
}

monster_died() 
{
    object imp, rew, mark, nog, chog;
    nog = first_inventory(environment());
    while(nog)
    {
      if((status)nog->is_player())
      {
        chog = nog;
        nog = 0;
    }
      else if(nog) nog = next_inventory(nog);
    }

    if(!chog) return 0;

    imp = present("implants", chog);

    rew = clone_object("/players/snow/closed/test/wish_orb.c");
    mark = clone_object("/players/snow/closed/test/aura.c");

    tell_room(environment(),
      "\n\tThe whirling blades of Steel shatter into slivers and\n"+
      "\tdisappear. You have completed the last stage of your test!\n\n"+
      "\tGreat honor is yours!\n");
    write_file("/players/snow/closed/test/complete",
      "\t"+pad(capitalize(chog->query_real_name()), 13) + ctime() + "\n");

    if(imp && !present("elemental aura", chog) ) 
    {
      imp->add_honor(15);
      call_other(CHANNELD, "overchannel",
      chog->query_name()+" has completed the Elemental Test!\n");
    }

    move_object(rew, this_object());

    if(!present("elemental aura", chog) ) move_object(mark, chog);
  
    emit_channel("announce", chog->query_name() + " \
has completed the Elemental Test!\n");
    tell_room(environment(), "\t\
*** You sense something new in your environment! ***\n");
    extra_xp(chog);
    logMyDeath();
    return 0;
}

armor_break(){
   object inv;
   int x;
   if(!attacker_ob) return;
   inv = all_inventory(attacker_ob);
say("Whirling blades of steel cut through your equipment!\n");
   
   for(x = 0; x < sizeof(inv); x++){
  if(random(100) < 20 && inv[x]->query_worn() && inv[x]->query_type() == "shield"){
inv[x]->armor_breaks();
       }       
if(random(100) < 20 && inv[x]->query_worn() && inv[x]->query_type() == "armor"){
inv[x]->armor_breaks();
       }       
if(random(100) < 20 && inv[x]->query_worn() && inv[x]->query_type() == "helmet"){
inv[x]->armor_breaks();
       }       
if(random(100) < 20 && inv[x]->query_worn() && inv[x]->query_type() == "amulet"){
inv[x]->armor_breaks();
       }       
if(random(100) < 20 && inv[x]->query_worn() && inv[x]->query_type() == "boots"){
inv[x]->armor_breaks();
       }       
if(random(100) < 20 && inv[x]->query_worn() && inv[x]->query_type() == "misc"){
inv[x]->armor_breaks();
       }       
if(random(100) < 20 && inv[x]->query_worn() && inv[x]->query_type() == "ring"){
inv[x]->armor_breaks();
       }       
   }
say("As sparks fly you hear the sounds of shattering steel.\n");
}

heart_beat() {
  ::heart_beat();
if(!random(7)){ armor_break(); }

if(random(100) < 40){
    if(attacker_ob && !attacker_ob->query_ghost()){
      already_fight=0;
      tell_object(attacker_ob,
"Steel disappears in a blur of light.\n");
      tell_room(environment(),
"Steel disappears in a blur of light.\n",
      ({attacker_ob}));
      attack();
      }
   }
  find_victim();
  check_self();
  if(attacker_ob && present(attacker_ob, environment(this_object()))) {
    blade_slice(attacker_ob); }
  if(!attacker_ob) heal_self(500);
}


blade_slice(object ob) {
  object meat;
  int slices;
  meat = ob; if(!meat) return;
  for(slices=0; slices<random(3)+1; slices++) {
    tell_object(meat, "Steel slices into you!\n");
   if(!meat->query_ghost()) meat->hit_player(random(16)+25, "other|steel");
  }
  return 1; }

#include "defenses.h"
#include "logme.h"
