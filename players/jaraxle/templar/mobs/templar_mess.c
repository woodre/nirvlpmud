#include "/players/jaraxle/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("louis");
set_alt_name("templar_mess");
set_alias("messenger");
set_race("human");
set_gender("male");
set_short("Louis, the Templar Messenger");
set_long(
"  Louis' job is to send out invitations to those who wish entrance\n"+
"into the castle without harm. To send an invitation: "+GRN+"invite"+NORM+" <"+GRN+"who"+NORM+">.\n"+
"Be careful, whomever you invite can enter without being stopped by\n"+
"the guards. And remind the person you invite that the invitation\n"+
"needs to be destroyed after use, for others can use it as well.\n");
set_level(3);
set_hp(55);
set_al(500);
set_wc(6);
set_ac(2);
set_aggressive(0);


gold = clone_object("obj/money");
gold->set_money(20);
move_object(gold,this_object());
}

init(){
::init();
if(present("KnightTemplar", this_player())){
call_out("bow_motion", 3, this_player());
  }
add_action("invite_them", "invite");
}

invite_them(str){
object invited;
	if(!present("KnightTemplar", this_player())){
		write("Louis ignores you.\n");
		return 1;
	}
	if(!str){
		write("Invite who?\n");
		return 1;
	}
invited = find_living(str);

if(!invited){
write("Louis cannot find that person.\n");
return 1;
}

if(present("KnightInvite", invited)){
	write("Louis says: that person already has an invitation.\n");
	return 1;
}

move_object(clone_object("players/jaraxle/templar/items/invite.c"), invited);
tell_object(invited,
			"A messenger from the Templar castle arrives and delivers to you\n"+
			"an invitation. You may enter freely when you desire.\n");
tell_object(this_player(),
			"Louis leaves to invite "+capitalize(str)+", and quickly returns.\n"+
			"Louis says: They are invited.\n");
write_file("/players/jaraxle/log/INVITES",
this_player()->query_real_name()+" invited "+str+" on "+ctime(time())+".\n");
return 1;
}




bow_motion(object who){
if(!present(who, environment())){
return 1;
}
tell_object(who,
"Louis nods and bows low to you.\n");
return 1;
}
