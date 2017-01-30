
inherit "room/room";

int unflag,opflag;
string clo,loc;

reset(arg) {
   if(arg) return;
   unflag=0;
   opflag=0;
   clo="closed";
   loc="locked";
    short_desc = "A corridor";
   dest_dir =
   ({
    "/players/hurtbrain/quest/hotel3_6","west",
    "/players/hurtbrain/quest/hotel3_5","northeast",
    "/players/hurtbrain/quest/hotel3_4","north",
    "/players/hurtbrain/quest/hotel_room","south",
    } ) ;
    set_light(1);
}
realm(){return "NT";}

long()  {write("This is one of the many corridors of this big hotel.\n"+
    "You see a strange door north from you. the door is "+clo+" and "+loc+".\n"+
    "You need the key to open it.\n");
    }


void init() {
	::init();
	add_action("note","south");
	add_action("unlock","unlock");
	add_action("lock","lock");
	add_action("open","open");
	add_action("close","close");
}

unlock(str)   {
	if(str!="door")  {	
		write("What do you want to unlock?\n");
		return 1;
		}
	if(unflag==1)  {
		write("The door is already unlocked.\n");
		return 1;
		}
	if(!present("singolar",this_player()))
		{
		write("You need the key to unlock the door!\n");
		return 1;
		}
	write("Click! You unlock the door.\n");
	unflag=1;
	loc="unlocked";
	return 1;
	}


lock(str)   {
	if(str!="door")  {	
		write("What do you want to lock?\n");
		return 1;
		}
	if(unflag==0)  {
		write("The door is already locked.\n");
		return 1;
		}
	if(opflag==1)  {
		write("You have to closed it first.\n");
		return 1;
		}
	if(!present("singolar",this_player()))
		{
		write("You need the key to lock the door!\n");
		return 1;
		}
	write("Click! You lock the door.\n");
	unflag=0;
	loc="locked";
	return 1;
	}

open(str)   {
	if(str!="door")  {	
		write("What do you want to open?\n");
		return 1;
		}
	if(opflag==1)  {
		write("The door is already opened.\n");
		return 1;
		}
	if(unflag==0)
		{
		write("The door is locked.\n");
		return 1;
		}
	write("You open the door.\n");
	opflag=1;
	clo="opened";
	return 1;
	}

close(str)   {
	if(str!="door")  {	
		write("What do you want to lock?\n");
		return 1;
		}
	if(opflag==0)  {
		write("The door is already closed.\n");
		return 1;
		}
	if(unflag==0)  {
		write("The door is locked.\n");
		}
	write("You closed the door.\n");
	opflag=0;
	clo="closed";
	return 1;
	}

note()  {
	if(unflag==0 || opflag==0)  {
		write("You can't pass thru a closed door.\n");
		return 1;
		}
}


