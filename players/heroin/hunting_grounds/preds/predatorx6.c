inherit "obj/monster.talk";
object mane,gold,foe,foe_name, attacker,crap,preyroom;
reset(arg) {
::reset(arg);
if(!arg) {
set_name("predator");
set_level(13);
set_alias("predator");
 set_race("predator"); 
set_hp(195);
set_al(-1000);
set_short("Predator champion"); 
set_long(
"You are staring into the eyes of the universe's most supreme and\n"+
" and perfect hunter.  You have proved yourself worthy of the hunt and\n"+
"here's your reward: a fight to the death.  The predator stands at\n"+
"approximately 7'2 and weighs about 300 lbs.  You would never guess\n"+
"by his speed and agility.  The predator wears a bio-mech armor which\n"+
"adjusts automatically to meet the predator's needs.  On his right\n"+
"shoulder sits a laser with target-locking, heat-seekers.  On his\n"+
"left arm, is the control panel for both the weapon and armor systems\n"+
"The predator himself has hard-leathery skin, which has an almost \n"+
"reptilian scale texture.  The predator has double-jaws: outside\n"+
"incisors for ripping, and inside fangs for grinding.  \n"+
"Around the predator's neck lies his trophys, a necklace of skulls.\n"+
"The last thing, you notice about the predator is four-12 inch \n"+
"serated blades protruding from his right hand- this must be the \n"+
"weapon that the Predator uses in close quarters.  Remember- the\n"+
"Predator is the only creature in the hunt to ever come close to \n"+
"defeating Angst...Good Luck!\n");
set_wc(17); 
set_ac(10);
/* Changed to aggressive until changes are made. -Snow */
set_aggressive(1); 
set_chance(10);    
set_spell_dam(7);  
set_spell_mess1("Predator shoves his claws into your torso and holds you \n off the ground.");
set_spell_mess2("Predator puts his claws through you!");   
enable_commands();
set_chat_chance(10);
load_chat("The Predator stretches his claws.\n");
load_chat("Predator bears his teeth.\n");
load_chat("Predator plays with his necklace.\n");
set_a_chat_chance(20);
load_a_chat("Predator throws out his arms and screams to the sky.\n");
load_a_chat("Predator lunges at you with his claws.\n");
load_a_chat("Predator knocks you across the room.\n");
set_alt_name("hunter");
gold = clone_object("/obj/money");
gold->set_money(random(400)+300);
move_object(gold,this_object());
move_object(clone_object("/players/heroin/hunting_grounds/preds/bishield.c"), this_player());
 
}
}
