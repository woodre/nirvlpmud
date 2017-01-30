#include "/players/daranath/closed/ansi.h"
#define tp this_player()
#define tpn tp->query_name()

inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("harvesting tool");
  set_alias("necro_tool");
  set_alt_name("tool");
  set_short("Harvesting Tool");
  set_long("The Harvesting Tool used primarily by a Necromancer.\n"+
           "The tool itself has a curved steel blade edged in diamond,\n"+
           "perfect for cutting and slashing through a body. A\n"+
           "black stone handle gives it great balance.\n");
  set_class(12);
  set_weight(1);
  set_value(0);
  set_hit_func(this_object());
}

query_save_flag() { return 0; }

weapon_hit(attacker){
  if(tp->query_attrib("int") > random(50)) {
  write("You slip your dagger between the defenses of your foe.\n");
  return 9; }
   return;
}

init() {
  ::init();
  add_action("harvest","harvest");
}

harvest(str) {
string name;
object ob,bpart;
int c_level, gain;
if(!present("necro_ob",tp)) {
write("You must be a necromancer to do that.\n");
return 1; }
if(!wielded) { write("You must have harvesting tool wielded!\n"); return 1; }
  if(!str) { write("Harvest what?\n"); return 1; }
  if(str == "corpse") { write("You can't do that.\n"); return 1;}
  ob = present("corpse",environment(tp));
  if(!ob) { write("There is no corpse here.\n"); return 1; }
  if(sscanf(ob->short(),"corpse of %s",name)) {
    if(str == "blood") {
    bpart = clone_object("/players/daranath/guild/obj/misc/blood.c"); 
	gain = 1;}
    else if(str == "skin") {
    bpart = clone_object("/players/daranath/guild/obj/misc/skin.c"); 
	gain = 4;}
    else if(str == "eye") {
    bpart = clone_object("/players/daranath/guild/obj/misc/eye.c"); 
	gain = 10;}
	else if(str == "heart") {
    bpart = clone_object("/players/daranath/guild/obj/misc/heart.c"); 
	gain = 15;}
    else if(str == "spine") {
    bpart = clone_object("/players/daranath/guild/obj/misc/spine.c"); 
	gain = 15;}
    else if(str == "soul") {
    bpart = clone_object("/players/daranath/guild/obj/misc/soul.c"); 
	gain = 20;}
    else { write("You can not harvest that.\n"); return 1; }
	bpart->set_name(name);
  c_level = ob->query_corpse_level();
	c_level = c_level - gain;
    if(c_level == 0) {
    write("You have harvested all you can from the corpse.\n");
    destruct(ob); }
	if(c_level < 0) {
    if(str != "blood") {
	 write("You may not harvest "+str+" from that corpse.\n");
	 destruct(bpart);
	 return 1;
     }
  destruct(ob);
	}
    if(c_level > 0) ob->set_corpse_level(c_level);
	move_object(bpart,tp);
  write("You bend over and harvest the body parts needed for your magic.\n");
  say(tpn+" bends over and takes a few body parts from the corpse.\n");
  } else {
  write("The corpse is too decayed to harvest any parts from.\n");
  }
return 1; }
  
