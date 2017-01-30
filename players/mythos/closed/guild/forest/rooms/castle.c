#include "/sys/ansi.h"
#include "/players/mythos/closed/guild/def.h"
int n, s;
object test, obb;
inherit "room/room";
reset(arg) {
  if(!present("xb")) { 
  move_object(clone_object("/players/mythos/closed/guild/forest/misc/xb.c"),this_object());
  }
  if(!arg) {
  n = 1;
  s = 0;
  set_light(0);
    short_desc = "Before the "+HIK+"Castle of the Forbidden"+NORM;
    long_desc =
    "You stand before a majestic castle.  Towers of dark marble,\n"+
    "walls of ebony, and windows masked in shadows.  A dark and \n"+
    "malicious aura eminates from this castle.  Beware... "+HIM+HBBLU+"FEAR\n"+NORM+
    "rules here.\n";
  items = ({
    "back",HIK+"Darkness"+NORM+"....",
    "east",HIK+"Darkness"+NORM+"....",
  });

  dest_dir = ({
    "/players/mythos/closed/guild/forest/rooms/castle2.c", "east",
    "/players/mythos/closed/guild/forest/rooms/huntera.c", "back",
  });
} }
realm() { return "NT";}

init() {
  ::init();
  if(!present("night_mare_check",tp)) {
  obb = clone_object("/players/mythos/closed/guild/forest/misc/nit.c");
  move_object(obb,tp); 
  obb->set_ss(tp->query_sp());}
  if(tp->id("white") || tp->id("thorns") || tp->id("blood")) { destruct(tp); }
  add_action("redo","east");
  add_action("redo","back");
  if(this_player()) /* by verte */
  if(pp && tgl == 1 && tl > 5) {
  test = tp;
  tell_object(tp,"Something calls you from deep within the earth....\n");
  add_action("dig","dig");
  add_action("stare","stare");
  add_action("slook","look");
  call_out("caller",10); }
}

redo() {
if(s == 1) { write("The stone disappears!\n"); }
n = 1;
s = 0;
}

caller() {
if(!n) { return 1;}
  if(!test) return 1;
tell_object(test,"Something calls you from deep within the earth....\n");
call_out("caller",10);
return 1;}

slook(str) {
  if(str == "at stone" && s) {
    write("You see a dark crystal- a purple flame seems to glow within it.\n");
    return 1;}
}

dig() {
  write("You slowly dig....\n\n");
  call_out("dig1",15);
return 1;}

dig1() {
n = 0;
s = 1;
  tell_object(test,"About 2 feet down you find a small black stone....\n"+
                   "The voices stop.....\n\n"+
                   "Something in the darkness overhead tells you to \n"+
                   "'stare into stone' and do not leave till what is done is done.\n");
return 1;}

stare(str) {
  if(!str || !s) return 0;
  if(str == "into stone" && s) {
  write("You look deep within the stone.....\n"+
        "Slowly an image forms.....\n\n");
        s = 0;
  call_out("stone1",15);
return 1;}
}

stone1() {
  tell_object(test,
        "  *   *    You see a small room, it is dimly lit with black candles.\n"+
        "  *   *    Papers and arcane items are scattered across the room.\n"+
        "  *   *    The smell of sweat and fear surrounds, and the air is still.\n\n");
 call_out("stone2",15);
return 1;}

stone2() {
  tell_object(test,
        "  *   *    A man steps from out of the shadows into the light....\n"+
        "  *   *    He is tall and regal looking- shoulder length brown hair,\n"+
        "  *   *    handsome features, lean body.  He looks about the room and\n"+
        "  *   *    picks up a jeweled knife.  Suddenly, he looks up and gazes\n"+
        "  *   *    straight at you!\n\n");
 call_out("stone3",10);
return 1;}

stone3() {
  tell_object(test,
        "  *   *    Eyes of pale grey, flecked with silver, look you over.....\n"+
        "  *   *    He smiles- a grim smile.  Involuntarily, you shiver- from fear.\n"+
        "  *   *    In a low voice he speaks:\n"+
        "  *   *      'I see, another one who has awakened to the power.'\n"+
        "  *   *    He chuckles- an evil sound.\n\n");
 call_out("stone4",6);
return 1;}

stone4() {
  tell_object(test,
        "  *   *    He stares at you for a few seconds and laughs- COLD.\n"+
        "  *   *      'It seems that though you may have the power,\n"+
        "  *   *      'you do not see the NIGHT.  Nor do you understand\n"+
        "  *   *      'the true price.'\n"+
        "  *   *    He pauses...\n"+
        "  *   *      'First lesson, honour your elders.'\n"+
        "  *   *    He gestures...\n\n");
  tell_room(environment(test),capitalize(test->query_real_name())+
            " grovels before man.\n");
call_out("stone5",4);
return 1;}

stone5() {
  tell_object(test,
        "  *   *    He nods.\n"+
        "  *   *      'Much better.  Now, for your second lesson....'\n"+
        "  *   *    Suddenly, he steps forward, and touches you with a finger\n"+
        "  *   *    his hand passing through the stone!\n\n");
  call_out("stone6",4);
return 1;}

stone6() {
  tell_object(test, 
        "  *   *    Suddenly, the darkness of the night explodes into a dance\n"+
        "  *   *    of colors.  The Dark Fae- dark purple, delicate strands \n"+
        "  *   *    of power- swirl around you.  Each strand a slightly different\n"+
        "  *   *    hue, each dancing to a rythmn so ancient- so ingrained within\n"+
        "  *   *    the Universe and the Soul.\n\n");
    call_out("stone7",4);
return 1;}

stone7() {
  tell_object(test, 
        "  *   *    Music fills the air- a music so intimate, notes of powerful\n"+
        "  *   *    beauty.  It fills your soul, it enters your body through\n"+
        "  *   *    every pore, hair, essence.  You are awash with passions and\n"+
        "  *   *    wants- needs and HUNGERS.\n\n");
    call_out("stone8",6);
return 1;}

stone8() {
  tell_object(test, 
        "  *   *    The man gives you a faint smile as you stare in wonder at\n"+
        "  *   *    the world.  In your mind he speaks:\n"+
        "  *   *      >> This is the NIGHT.  This is the world that others\n"+
        "  *   *      >> fear.  Forever yours to know and hold.  This is the\n"+
        "  *   *      >> world of FEAR and HUNGER.  The path to true magic and\n"+
        "  *   *      >> power.  Though the sun may kill, the darkness soothes.\n"+
        "  *   *      >>\n"+
        "  *   *      >> But... there is a price.\n\n");
   call_out("stone9",4);
return 1;}

stone9() {
  tell_object(test, 
        "  *   *      >>  For every instance of power, something must be given\n"+
        "  *   *      >>  up for it- a sacrifice.  The greater the sacrifice\n"+
        "  *   *      >>  the greater the power.\n"+
        "  *   *    He smiles again- a cold smile.\n"+
        "  *   *      >>  And for every gift, there must be a gift in return.\n"+
        "  *   *      >>  For my gift of SIGHT, I take what I will.\n"+
        "  *   *    He gestures and you feel a great wretching in your soul!\n\n");
  present(fear,test)->set_dark_level(2);
  present(fear,test)->add_sacrifice(1000);
  present(fear,test)->dsave();
  present(fear,test)->update_me();
  test->lower_attrib();
  test->lower_attrib();
  test->lower_attrib();
  test->lower_attrib();
  test->save_me();
  n = 1;
  tell_object(test, 
       "  *   *    He laughs.... and the image vanishes....\n");
return 1;}
