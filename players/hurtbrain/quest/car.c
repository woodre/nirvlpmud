
inherit "room/room";
object obj;
int k,fl1,fl2,fl3;
reset(arg) {
   if(arg) return;
    short_desc = "Bond's car" ;
    long_desc = "You are in your car, running away from your pursuers.\n"+
    "You continue to press the accelerator but they don't seem to want to\n"+
    "let you escape. There are three buttons on the instrument panel.\n"+
    "Perhaps they can be useful.\n";
    k=0;
    fl1=0;
    fl2=0;
    fl3=0;
    set_light(1) ;
}
realm(){return "NT";}

void init() {
	::init();
	add_action("press","press");
	}


int press(string number)  {
	int num;
	string nummac;
    if (!number || sscanf(number,"%d",num) != 1 || num < 1 || num > 3) {
        notify_fail("What do you want to press?\n");
	return 0;
    }
    if(k==0)
	nummac="one of the three";
    else if(k==1)
	nummac="the first of the two";
    else
	{
	nummac="the last";
	obj=this_player();
	}
    ++k;
    if (num == 1)   {
      if(fl1==1)  {
		write("No more oil\n");
		--k;
		}
      else  
	write("Your car starts to spread oil from the back and "+nummac+"\n"+
	"pursuer's car go off road, crashing against a tree.\n");
	fl1=1;
	if(k>2)
		call_out("last",2);
	return 1;
	}
    if (num == 2)   {
      if(fl2==1)  {
		write("No more gas\n");
		--k;
		}
      else  
	write("Your car leave to go a cloud of black gas and "+nummac+"\n"+
	"pursuer's car have to stop.\n");
	fl2=1;
	if(k>2)
		call_out("last",2);
	return 1;
	}
    if (num == 3)   {
      if(fl3==1)  {
		write("No more nails\n");
		--k;
		}
      else
          write("Your car drop some nails on the road and a pneumatic of\n"+
	nummac+" pursuer's car pierce. The car can't continue the pursue!\n");
	fl3=1;
	if(k>2)
		call_out("last",2);
	return 1;
	}
}

last()   {
	tell_object(obj,"You leave your pursuers and you can now go to your secret base.");
	move_object(obj,"/players/hurtbrain/quest/base.c");
	command("look",obj);
	k=0;
	fl1=0;
	fl2=0;
	fl3=0;
    return 1;
}
