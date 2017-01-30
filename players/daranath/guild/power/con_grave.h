/* Guild Level 3 - basic spell
   Spell allows a necromancer to declare that a certain area
   is a gravesite. Moves gsite_ob to area.
   TotalCost - 54sp (50 sp, 2 blood)    */
con_grave() {
object ob;

ob = present("necro_ob",tp);

if(tp->query_sp() < 100) {
write("You do not have the spell points available for the Bad Moon.\n");
return 1; }
if(ob->query_blood() < 2) {
write("You do not have the components available for this spell.\n");
return 1; }

if(present("gsite_ob",environment(tp))){
  write("This area is already a consegrated gravesite.\n"+
        "You feel right at home here.\n");
return 1; } else {
  move_object(clone_object("/players/daranath/guild/obj/misc/gsite_ob.c"),environment(tp));
  write("You take blood from your component pouch and draw a symbol upon\n"+
        "the ground, consecrating this area with the Realm of Death.\n"+
        "A pillar of stone rises from the earth, marking the graveyard.\n");
  say(tp->query_name()+" speaks a few words in an arcane language.\n"+
      "A pillar of dark stone slowly rises from the ground.\n");

tp->add_spell_points(-100);
ob->add_blood(-2);
ob->save_me();
return 1; }
}

