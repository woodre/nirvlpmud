#define tp this_player()
#define tpname this_player()->query_name()
#define where_name(obj) environment(obj)->query_name()
#define maker "sado"

#define START_ENERGY 20

inherit "obj/treasure";

object target;
int energy,ran;

init()
{
		::init();
		add_action("attack","pester");
}

reset(arg)
{
		if(!arg) {
			       set_id("chihuahua");
                set_short("A ferocious little chihuahua");
                set_long("You know chihuahuas.  They're small, they yip, they snap at your\n" +
					 			 "ankles, they pee on your feet, and they're generally just obnoxious\n" +
								 "little fiends.  This one has a cute pink bow wrapped around it's neck.\n");
                set_alias("dog");
                set_weight(4);
                set_value(0);
					 energy=START_ENERGY;
                set_heart_beat(0);
		}
}

get() { return 0;}  /*Can't pick up the doggie*/

query_energy()
{
	write("This doggie has "+energy+" rounds of pestering left.\n");
	return 1;
}

attack(str)
{
	if(!str) write("You need to tell the doggie who to pester.\n");
	else if(!(target=find_player(str))) write("Couldn't find that player on the MUD!\n");
        else if(target->query_level() > 1000000) {
          write("You can't sick the dog on a wizard.\n");
          return 1;
        }
	else {
		say("The little Chihuahua tears off after a sworn enemy.\n");
		write("The little Chihuahua tears off after "+target->query_name()+".\n");
		move_object(this_object(),environment(target));
		tell_room(environment(target),"A little Chihuahua comes waddling into the room, at an unbelievable pace.\n");
		tell_object(target,"It looks up at you as it enters, and decides to pick on you.  Uh-oh.\n");
		set_heart_beat(1);
	}
	return 1;
}

pee()
{
	tell_object(target,"The little Chihuahua relieves itself on your foot.  It's amazing\n" +
					 "how much urine such a small body can hold.\n");
	say("The Chihuahua pisses on "+target->query_name()+"'s foot.\n",target);
	return 1;
}

yip()
{
	say("The little Chihuahua runs around "+target->query_name()+"'s feet, yipping like crazy.\n",target);
	tell_object(target,"The little Chihuahua runs around your feet, yipping like crazy.\n");
	return 1;
}

bite()
{
	tell_object(target,"The little Chihuahua bites you on the ankle!  It draws blood.\n");
	say("The little Chihuahua bites "+target->query_name()+" on the ankle.  It draws blood.\n",target);
	tell_object(target,"OUCH!!\n");
	return 1;
}


heart_beat()
{
		int i;

		if(environment(target)!=environment(this_object())) {
				tell_object(target,"Running away won't save you from the fury of the Chihuahua!\n");
				say("The ferocious little Chihuahua chases "+target->query_name()+" out of the room.\n");
				move_object(this_object(),environment(target));
				say("A vicious little Chihuahua enters the room.  It has a mean look in its eyes!\n");
		}

		i=random(3);

		if(i==0)  pee();
		if(i==1)  yip();
		if(i==2)  bite();

		if(--energy==0) {
				say("The poor little doggie has worn itself out.  It has a cardiac arrest, and dies.\n" +
				    "An old lady, carrying a leash which has been chewed through enters the room.\n" +
					 "She picks up the poor little doggie's body, looks around the room, and sees\n" +
					 target->query_name()+".  She starts crying, and runs from the room.\n");
				tell_object(target,"You finally managed to get rid of that pestering doggie.\n");
				destruct(this_object());
		}
}
