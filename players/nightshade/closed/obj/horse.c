#define WHO this_player()->query_real_name()
#define ac this_player()->query_ac()
#define wc this_player()->query_wc()
#define att owner->query_attack()
inherit "/obj/monster";
int mount, damage, old_hp, new_hp;
string nme;
object owner;
reset(arg) {
   ::reset();
   if(arg) return;
   set_name("Horse");
   set_short("Black Stallion");
   set_ep(0);
   set_alias("horse");
   set_ep(0);
   set_ac(3);
   set_wc(30);
   set_hp(350);
	set_heart_beat(1);
   nme = "A Black Stallion";
   enable_commands();
	if(!arg) mount=0;
	owner=0;
}

id(str) {
  return str == "horse" || str == "stallion";
}

heart_beat() {
   ::heart_beat();

	if(owner==0) {
	say(nme+"'s owner is missing.  He runs off in freedom.\n");
	destruct(this_object());
	}
   if(environment(find_living(owner->query_real_name())) != environment(this_object())) {
	say(nme+" gallops after "+capitalize(owner->query_real_name())+".\n");
      move_object(this_object(),environment(find_living(owner->query_real_name())));
	say(nme+" gallops in after "+capitalize(owner->query_real_name())+".\n");
   }
if(att && mount == 1) {
new_hp = owner->query_hp();
damage = old_hp - new_hp;
if(damage > 0) {
owner->heal_self(damage/2);
this_object()->hit_player(damage/2);
tell_object(owner,"Your horse takes "+damage+" pts of damage for you.\n");
	}
old_hp = new_hp;
}
	if(att && damage==0) {
	att->hit_player(random(5));
	say(capitalize(owner->query_real_name())+"'s horse stomps "+capitalize(att->query_real_name())+" into the ground!\n");
	}
}


set_owner(ob) { owner = ob; }


short() {
   return nme;
}

long() {
   object ob;
   object ob2;
   ob = this_player();
   ob2 = find_living(owner->query_real_name());
	if(!((owner->query_real_name())==this_player()->query_real_name())) {
	write("This is a beautiful black horse dressed for battle.  It's saddle\n" +
"and armor look very protective.  It seems someone on a horse like\n" +
"this one would have a great advantage over you.\n");
   write("This is the horse of "+capitalize(owner->query_real_name())+".\n");
	}
      if((owner->query_real_name())==this_player()->query_real_name()) {
	write("This is your horse that you can mount and dismount.  If you are\n"+
"attack something and are mounted on your horse, your horse will\n" +
"take a certain amount of the hit each round.  While mounted you also \n" +
"have a great advantage because your horse enhances your weapon\n" +
"and armor class.  Your horse will be loyal to you and follow you\n" +
"wherever you go until it's death.  You can give your horse\n"+
"back it's freedom whenever you wish by the command 'letgo'.\n"+
	"[HPS] "+this_object()->query_hp()+"/"+this_object()->query_mhp()+"\n");
      }
   }
   
   init() {
      ::init();
	add_action("mount","mount");
	add_action("dismount","dismount");
	add_action("letgo","letgo");
	add_action("at","attack");
}
   
   
   letgo() {
	if(this_player()==owner) {
	if(mount==1) {
	write("You can not let your horse go while you are mounted.\n");
	return 1;
	}
	write("Your horse look at you for a moment then runs off.\n");
      say(capitalize(owner->query_real_name())+"'s horse looks at him a moment then runs off.\n");
      destruct(this_object());
      return 1;
	}
}
   
   
   
   
mount(arg) {
	if(this_player()==owner) {
	if(mount==1) {
	write("You are already on your horse!\n");
	return 1;
	}
	write("You climb on the back of your horse and prepare for battle.\n");
	say(capitalize(owner->query_real_name())+" mounts the horse.\n");
	mount=1;
  old_hp = this_player()->query_hp();
	this_player()->set_ac((ac)+1);
	this_player()->set_wc((wc)+1);
	return 1;
	}
}
dismount() {
	if(this_player()==owner) {
	if(mount==0) {
	write("You are not on the horse!\n");
	return 1;
	}
	write("You climb down from your stallion.\n");
	say(capitalize(owner->query_real_name())+" dismounts the horse.\n");
	mount=0;
	owner->set_ac((ac)-1);
	owner->set_wc((wc)-1);
	return 1;
	}
}


	query_pet() { return 1; }
query_owner() { return owner; }
