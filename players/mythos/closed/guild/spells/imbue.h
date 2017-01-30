#include "/players/mythos/closed/guild/def.h"

imbue(str) {
string p, looks, nm, deep;
object ob, ob2, ob3, ob4;
string name, type, sbef;
int before, weigh;
if(!str) { write("Usage: imbue <name of object> <type of power>\n");
  write("Power Types:  strength <adds wc/ac>  grenade  place_teleport\n"+
        "\nNote: The above four are the known ones, there are hints of\n"+
        "        others- search well.\n");
            return 1;}
if(qtf < 10) { write("Your control over fae is not enough!\n"); return 1;}
if(tsp < 75) { write("You do not have enough energy!\n"); return 1;}
if(scrp < 120) { write("The darkness calls for a sacrifice.\n"); return 1;}
if(sscanf(str,"%s %s",name,type) != 2) { write("Please try again.\n"); return 1;}
ob = present(name,tp);
if(!ob || ob->query_auto_load()) { write("You do not have that!\n"); return 1;}
if(ob->weapon_class() && tp->query_weapon() == ob) {
command("unwield "+name,this_player()); }
if(ob->armor_class()) {
command("remove "+name,tp); }
if(present("adder",ob)) { 
write("You have placed too much of a strain on this item!\n");
write("It explodes!\n");
tp->heal_self(-random(10));
destruct(ob);
return 1;}
if(type != "strength" && type != "grenade" && type != "place_teleport" &&
  type != "spy") { 
  write("That is not possible.\n"); return 1;}
if(type == "strength") {
if(ob->weapon_class()) {
before = ob->weapon_class();
ob->set_class(before + 1); }
if(ob->armor_class()) {
before = ob->armor_class();
ob->set_class(before + 1); }
if(!(ob->weapon_class()) && !(ob->armor_class())) {
looks = ob->short();
weigh = ob->query_weight();
destruct(ob);
ob2 = clone_object("/obj/weapon.c");
ob2->set_name(name);
ob2->set_short(looks+BLU+"  <aura>"+NORM);
ob2->set_class(10+ random(7));
ob2->set_weight(weigh);
ob = ob2;
move_object(ob,tp);
}
write("The item is now stronger!\n");}
if(type == "grenade") {
if(ob->weapon_class()) {
before = ob->weapon_class();
ob->set_class(before - 1 - random(2));}
if(ob->armor_class()) {
before = ob->armor_class();
ob->set_class(before - random(3));}
move_object(clone_object("/players/mythos/closed/guild/spells/grenade.c"),ob); 
tp->add_spell_point(-5);
ob->set_short(looks+BLU+"  <aura>"+NORM);
write("\nTo have the device explode, simply drop the item.\n\n");}
if(type == "place_teleport") {
looks = ob->short();
weigh = ob->query_weight();
destruct(ob);
ob2 = clone_object("/players/mythos/closed/guild/spells/teleport.c");
ob2->set_id(name);
ob2->set_short(looks+BLU+"  <aura>"+NORM);
ob2->set_long("\nTo use the device: <dset> to set place of teleportation\n"+
                     "                   <activate> to go to set place.\n");
ob2->set_weight(weigh);
ob = ob2;
move_object(ob,tp);
write("Look at the item to see how to use it.\n");}
if(type == "spy") {
looks = ob->short();
weigh = ob->query_weight();
destruct(ob);
ob2 = clone_object("/players/mythos/closed/guild/spells/spy.c");
ob2->set_id(name);
ob2->set_short(looks);
ob2->set_weight(weigh);
ob2->set_owner(tpn);
move_object(ob2,tp);
write("This item will simply tell you what is done by the person holding it.\n"+
      "Or in the room it is dropped in.\n");
move_object(clone_object("/players/mythos/closed/guild/spells/adder.c"),ob2); 
write("The "+ob2->short()+" glows with a blue light......\n");
tp->add_spell_point(-15);
pp->add_sacrifice(-40);      
return 1;}
tell_room(environment(tp),"The "+name+" glows with a blue light......\n");
move_object(clone_object("/players/mythos/closed/guild/spells/adder.c"),ob); 
tp->add_spell_point(-75);
pp->add_sacrifice(-120);
return 1;}
