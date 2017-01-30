inherit "obj/armor";

int charges;

reset(arg){
  ::reset(arg);
  if(arg) return;
  set_short("Tourmaline Ring");
  set_long("a ring. neat.\n");
  set_ac(1);
  set_weight(1);
  set_value(3000);
  set_alias("ring");
  set_name("Tourmaline Ring");
  set_type("ring");
  charges = 3;
}

long(){
  write("A golden pinky ring with a blue gem set in it.\n"+
  "This ring is known to have magical powers of healing.\n"+
  "You can activate its magic by twisting the gem.\n"+
  "There are "+charges+" charges remaining.\n");
  return;
}

init(){
 ::init();
 add_action("twist_gem","twist");
}

twist_gem(str){
 write("twist_gem called\n");
 write("str: " + str+"\n");
 if(!str) return (notify_fail("Twist what?\n"), 0);
  if(str != "gem") return (notify_fail("You may only twist the gem.\n"), 0);
 if(str == "gem") {
	if(!worn) {
		write("You must wear the ring first.\n");
		return 1;
	}
	write("You twist the small gem and the ring grows warm against your skin.\n");
	write("The ring restores your health.\n");
	this_player()->heal_self(30+random(20));
	charges--;
	if(charges == 0) {
		write("The magic of the gem is used up and the ring disappears.\n");
                remove("Tourmaline Ring");
		destruct(this_object());
		return 1;
	}
	return 1;
  }
}

string locker_arg() { return ""+charges; }
void locker_init(string arg)
{
  if(sscanf(arg,"%d",charges)!=1) {
    write("Object failed to initialize properly.  Destructing.\n");
    destruct(this_object());
  }
}

int restore_thing(string str) { restore_object(str); return 1; }
int save_thing(string str) { save_object(str); return 1; }
