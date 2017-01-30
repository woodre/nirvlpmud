/* Basic Example of using monster spells */

inherit "/obj/monster.c";

void reset(status arg) {
  ::reset(arg);
  if(arg) return;
set_name("Gandalf the Grey");
set_alt_name("gandalf");
  set_race("human");
  set_gender("male");
 set_short("Gandalf, the Grey");
 set_long("Gandalf's eyes twinkle as his long grey beard flows in the wind,\n"+
"he stands with an aire of might and quiet strength.\n");
  set_hp(1500);
  set_ac(15);
  set_wc(30);

/* With set_multi_cast at 1, the monster can potentially cast every */
/* spell in his arsenal each round.  The chance on each spell is */
/* checked in turn.*/  
  set_multi_cast(1);

/* Standard damage-doing spell but with wind damage */
add_spell("air blast",
 "#MN# points his staff at you and air \"$HC$SWIRLS$N$\" around, sand and sticks fly everywhere.\n"+
"Rocks and debris blow against your face and body.\n",
"#MN#  conjures a great \"$HC$WIND$N$\" swinging his staff in an arcane pattern.\n"+
 "Wind blasts #TN# with rocks and debris.\n",
  25,30,"other|wind");
  
/* Physical damage to all opponents */
  add_spell("whirlwind spin",
  "#MN#'s whirling feet smack you in the face!\n",
  "#MN# yells, \"Whirlwind Spin\"!\n"+
  "#MN# leaps into the air, #MP# feet flying in a thousand different directions.\n",
  25,30,"physical",1);

/* Physical damage to one opponent, plus a bonus... */
  add_spell("tiger palm",
  "#MN# yells, \"Tiger Palm\"!\n"+
  "#MN# strikes you in the chest with #MP# open right palm!\n",
  "#MN# yells, \"Tiger Palm\"!\n"+
  "#MN# strikes #TN# in the chest with his open right palm!\n",
  25,50,"physical",0,"tiger_palm_extra");
 
}

/* If the tiger palm did more than 1/2 damage, move the target */
/* to another room.  normally you'd use an adjacent room, not */
/* the church */
void tiger_palm_extra(object target,object room,int damage) {
  if(target && room && damage > 25) {
    tell_object(target,
    "The force of the Tiger Palm blasts you out of the room!\n");
    tell_room(room,
    "The force of the Tiger Palm blasts "+target->query_name()+" out of the room!\n",
    ({target,this_object()}));
    transfer(target,"/room/church");
    tell_room("/room_church",
    target->query_name()+" flies into the room!\n",({target}));
    command("look",target);
  }
}
