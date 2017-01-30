/* Guild Level 7 - Misc Spell
   Grafting is a healing spell which effects hp only
   random(25) + 20 healing. Healing also causes massive scarring
   upon the extra_look of the char (hey, its a necro heal!)
   TotalCost - 46sp (30sp, 1 skin, 4 blood)      */
grafting(str) {

int MAX_HP, CURR_HP;
int grch, heal;
string g_part;
object ob, ob2;
object target;
int already;

ob = present("necro_ob",tp);
heal = 20 + random(25);

if(!str) {
write("Who do you want to help through grafting?\n");
return 1; }
if(!(target = present(str,environment(tp)))) {
write("That is not present.\n"); return 1; }
if(!living(target)) {
write("That is not something you can help through grafting.\n");
return 1; }
if(!find_player(str) && str != "undead") {
write("You cannot help those within the realm of death.\n");
return 1; }
if(str != "undead" && find_player(str) != target) {
write("Target is not a player.\n");  return 1; }

if(tp->query_sp() < 30) {
write("You do not have the spell available for the grafting.\n");
return 1; }
if((ob->query_blood() < 4) || (ob->query_skin() < 1)) {
write("You do not have the available spell components for the grafting.\n");
return 1; }
if(present("gsite_ob",environment(tp))) {
heal = heal + 5;  }

MAX_HP = target->query_mhp();
CURR_HP = target->query_hp();

if(MAX_HP > CURR_HP) {

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
if(target == this_player()) {
write("You pull out a small amount of skin and some blood from your pouch.\n");
write("You painfully afix the components to your wounds, healing yourself.\n");
say(tp->query_name()+" digs around through "+tp->query_possessive()+" component pouch.\n");
say(tp->query_name()+" takes a couple of components and applies them to "+tp->query_possessive()+" wounds.\n");
} else {
write("You pull out a small amount of skin and some blood from your pouch.\n");
write("You tend to the wounds of "+target->query_name()+", leaving a couple of scars.\n");
say(tp->query_name()+" tends to the wounds of "+target->query_name()+".\n");
tell_object(target, tp->query_name()+" takes a couple of object from thier component pouch.\n");
tell_object(target, tp->query_name()+" grafts those components onto your wounds.\n");
tell_object(target, "Although the wound is healed, that's gonna leave a scar.\n");
}
  tp->add_spell_point(-30);
  ob->add_blood(-4);
  ob->add_skin(-1);
  ob->save_me();

} else write("You cannot Graft someone who is fully healed.\n");
return 1;
}
