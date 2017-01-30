/*
Robes from /pl/s/MONSTERS/glarvinthal
ac4, non-storeable, with limited sp addition
*/
/* edited 05-15-07 by Tallos to add mage guild
guild bonus*/
 
#define TP this_player()
#define TPN TP->query_name()
#define GUILDID "mageobj"
#define BONUS_TYPE "evocation"
#define BONUS_TYPE2 "conjuration"
#define BONUS_TYPE3 "necromancy"
#define BONUS_TYPE4 "enchantment"
#define BONUS_TYPE5 "illusion"
#define BONUS_AMOUNT 1 
inherit "obj/armor";
 
int charges;

/* 
query_save_flag() { return 1; }
 If we save the charges value, this cloak can be savable. -Bp */
locker_arg() {
  string blah;
  blah="--"+charges+"--";
  return blah;
}
locker_init(arg) { 
  int blah;
  sscanf(arg,"--%d--",blah);
  charges = blah;
}
query_guild_bonus(){ return BONUS_AMOUNT; }

add_guild_bonus()
{
  if(present(GUILDID, this_player()))
  {
	present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE, BONUS_AMOUNT);
	present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE2, BONUS_AMOUNT);
	present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE3, BONUS_AMOUNT);
	present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE4, BONUS_AMOUNT);
	present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE5, BONUS_AMOUNT);				
   }
}

remove_guild_bonus()
{
  if(present(GUILDID, this_player()))
  {
	present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE, -BONUS_AMOUNT);
	present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE2,-BONUS_AMOUNT);
	present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE3,-BONUS_AMOUNT);
	present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE4,-BONUS_AMOUNT);
	present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE5,-BONUS_AMOUNT);	
  }
}

init() {
  ::init();
add_action("focus_robes","focus");
}
 
reset(arg){
   ::reset(arg);
   set_name("robes of the archwizard");
   set_short("Robes of the Archwizard");
   set_alias("robes");
   set_long(
"Shining white robes formerly worn by the Archwizard Glarvinthal.\n"+
"You should be able to 'focus' the robes' power into your own.\n");
   set_type("armor");
   set_ac(4);
   set_weight(1);
   set_params("other|magical", 2, 10, "do_spec");
   set_value(10000);
charges = 5;
}
 
 
focus_robes() {
  if(TP->query_level() < 10) {
    write("You are not powerful enough to focus the robes' powers!\n");
return 1;
  }
  if(charges == 0) {
    write("The Archwizard's robes have no more power to give!\n");
return 1;
  }
else
  write("You focus the power of the Archwizard's robes into your own!\n");
  say(TPN+
" closes "+TP->query_possessive()+" eyes and is surrounded by a powerful aura!\n");
call_other(TP,"add_spell_point",50);
charges = charges -1;
  if(charges == 0) {
    write(
"You have absorbed all the power from the Archwizard's robes.\n");
  }
return 1;
}


do_spec(object owner){
     if(!random(3)){
       tell_object(owner,
       "The robes glow faintly under the magical attack!\n");
       return 1002;
       }
return 0;
}
