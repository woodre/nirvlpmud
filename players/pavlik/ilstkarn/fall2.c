#include <ansi.h>
inherit "room/room";

object obj;

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="Down the Chasm";
  long_desc=
	"\nYou are Falling!!!\n\n";
  dest_dir=({
	"/players/pavlik/ilstkarn/null", "up",
	"/players/pavlik/ilstkarn/null", "down",
  });
}

long() {
  write("\n\n        You are Falling!!!          \n\n");
  return 1;
}

query_ilstkarn(){ return "fall2"; }
realm(){ return "NT"; }
query_nofollow(){ return 1; }
query_no_teleport(){ return 1; }

init() {
  ::init();
  if(this_player()->is_player()) {
	call_out("fall1", 5, this_player());
  }
  else {
	move_object(this_player(), "players/pavlik/waste_room");
	destruct(this_player());
  }
}

fall1(ob) {
  if(ob && present(ob, this_object())) {
	tell_object(ob,
	"\n"+
	"     You "+HIB+"tumble"+NORM+" down the Chasm!\n"+
	"     Your body speeds downward at "+HIR+"break-neck"+NORM+" speed!\n"+
	"\n");
	call_out("fall2", 5, ob);
	return 1;
  }
}

fall2(ob) {
  if(ob && present(ob, this_object())) {
	tell_object(ob,
	"\n"+
	"    You spin "+HIW+"uncontrolably"+NORM+" as you continue to "+HIR+"plummet"+NORM+" deeper\n"+
	"    into the seemingly "+HIW+"bottomless"+NORM+" chasm!\n"+
	"\n");
	call_out("fall3", 5, ob);
	return 1;
  }
}

fall3(ob) {
  if(ob && present(ob, this_object())) {
	tell_object(ob,
	"\n"+
	"    Finally, the "+YEL+"end"+NORM+" is within sight ...\n"+
	"    The chasm floor appears below ...\n"+
	"\n");
	call_out("fall4", 2, ob);
	return 1;
  }
}

fall4(ob) {
  if(ob && present(ob, this_object())) {
	tell_object(ob,
	"\n"+
	"    You will "+HIR+"smash"+NORM+" into it at several hundred miles per hour!\n"+
	"\n");
	call_out("fall5", 2, ob);
	return 1;
  }
}

fall5(ob) {
  if(ob && present(ob, this_object())) {
	tell_object(ob,
	"\n"+
	"    You "+HIW+"squeeze"+NORM+" your eyes shut in preparation of the imminent!\n"+
	"\n");
	call_out("fall6", 2, ob);
	return 1;
  }
}

fall6(ob) {
  if(ob && present(ob, this_object())) {
	tell_object(ob,
	"\n\n"+HIB+
	"                    ~~~~~~~~       \n"+
	"                ~~~~~~~~~~~~~~~~   \n"+
	"                ~~  SPLASH!!  ~~   \n"+
	"                ~~~~~~~~~~~~~~~~   \n"+
	"                    ~~~~~~~~       \n"+NORM+
	"\n");
	call_out("fall7", 2, ob);
	return 1;
  }
}

fall7(ob) {
  int i;
  i = 1 + random(5);
  if(ob && present(ob, this_object())) {
	tell_object(ob,
	"\n"+
	"     "+HIB+"SPLASH!?"+NORM+"  Didn't You mean "+HIR+"<<SPLAT!>>"+NORM+" ?\n"+
	"     No, indeed it was a Splash!  You have fallen into an\n"+
	"     "+HIB+"underground lake"+NORM+", deep below the surface of the world.\n"+
	"\n");
	move_object(ob, "players/pavlik/ilstkarn/lake"+i);
	return 1;
  }
}

