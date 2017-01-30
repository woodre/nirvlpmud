#include "../../defs.h"


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
  set_type("dagger");
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
string bodypart;
int bpart_amount;
object ob,bpart;
int c_level, gain;
string bpartarray;
int bpartgain;

gain = 0;
bpartarray = ({"blood","skin","eye","heart","spine","soul"});
bpartgain = ({1,4,10,15,15,20});

if(!GOB) {
write("You must be a necromancer to do that.\n");
return 1; }
if(!wielded) { write("You must have harvesting tool wielded!\n"); return 1; }
  if(!str) { write("harvest <what> <amount>\n<amount> default is 1.\n"); return 1; }
  if(str == "corpse") { write("You can't do that.\n"); return 1;}
  ob = present("corpse",environment(tp));
  if(!ob) { write("There is no corpse here.\n"); return 1; }

  if(sscanf(str,"%s %d",bodypart,bpart_amount) != 2) {
	  bodypart = str;
	  bpart_amount = 1;
  }

  if(member_array(bodypart,bpartarray) == -1) {
	write("You can not harvest that.\n"); return 1;
  }

  if(sscanf(ob->short(),"corpse of %s",name)) {
    while(bpart_amount > 0) {
   if(!ob) { bpart_amount = -1; }
  else {
		 c_level = ob->query_corpse_level();
		 gain = bpartgain[member_array(bodypart,bpartarray)];
         if(c_level < gain) {
			write("You may not harvest "+bodypart+" from that corpse.\n");
			bpart_amount = -1;
	     } else {
		   c_level = c_level - gain;
		   if(c_level < 1) {
	         write("You have harvested all you can from the corpse.\n");
             destruct(ob);
	       } else ob->set_corpse_level(c_level);
	       write("You bend over and harvest "+bodypart+".\n");
               write("Quickly you slip the "+bodypart+" into your pouch.\n");
           call_other(GOB,"add_"+bodypart,1);
           bpart_amount = bpart_amount - 1;
	     }
    }
   }
  say(tpn+" bends over and takes a few body parts from the corpse.\n");
  } else {
  write("The corpse is too decayed to harvest any parts from.\n");
  }
return 1; }

