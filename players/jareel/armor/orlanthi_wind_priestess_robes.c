inherit "obj/armor";
#include "/players/jareel/define.h"
#include "/players/jareel/ansi.h"
#define ATT USER->query_attack()
#define USER environment(this_object())

#define GUILDID         "mageobj"
#define BONUS_TYPE      "power"
#define BONUS_AMOUNT    3

/* Most Mage armors give +4 to stats this gives +3 as it is a spell point regenerating armor and is 'Lightning' as with Amulet of lightning it adds to power. */

reset(arg) {
 ::reset(arg);
  if(arg) return; /* verte */
 call_out("elec",60);

set_name("robes");
set_id("armor");
set_alias("robes");

set_short(BOLD+BLU+"Lightning Robes"+NORM);
set_long(
  "This armor is charged with a current of arcing electricity.  A surge\n"+
  "of power pulsates through the garment.  The runes of Air and motion\n"+
  "are finely embroidered throughout its surface.  \n");

set_ac(3);
set_params("other|electric",0,10,0);
set_params("other|earth",0,-10,0);
/*
set_save_flag(1);
Make save -Bp
*/
set_value(1100);
set_type("armor");
set_weight(1);
 
}

elec() {
object hh;
if(!environment(this_object())) return 1;
hh = environment(environment(this_object()));
if(!hh) return 0;
tell_room(hh,
"Arcing "+BOLD+"electrical energy"+NORM+" leaps from "+USER->query_name()+"'s robes."+NORM+"\n");
call_out("elec2",60);
   return 1;
}

elec2() {
object hh;
if(!environment(this_object())) return 1;
hh = environment(environment(this_object()));
if(!hh) return 0;
tell_room(hh,
""+BOLD+BLU+USER->query_name()+"'s robes"+NORM+" hum with raw power."+NORM+"\n");
   call_out("elec3",20);
   return 1;
}

elec3() {
object hh;
if(!environment(this_object())) return 1;
hh = environment(environment(this_object()));
if(!hh) return 0;
tell_room(hh,
""+BOLD+"Electricity arcs "+NORM+"over "+USER->query_name()+"'s body."+NORM+"\n");
call_out("elec",60);
   return 1;
}

query_guild_bonus(){ return BONUS_AMOUNT; }

add_guild_bonus()
{
  if(present(GUILDID, this_player()))
        present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE, BONUS_AMOUNT);
}

remove_guild_bonus()
{
  if(present(GUILDID, this_player()))
        present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE, -BONUS_AMOUNT);
}




do_special(owner)
{
   if(!random(6)){
     tell_room(environment(USER),
BOLD+BLU+USER->query_name()+" robes course with energy"+NORM+".\n");
owner->add_spell_point(3+random(5));
return 0;}
return 0;}
