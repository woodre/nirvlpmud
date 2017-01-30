
#include "/players/jaraxle/define.h"
#define TP this_player()
#define NAME "jaraxle"
inherit "room/room";
int shield, COLOR, COLOR1, COLOR2, COLOR3, SHAPE, SHAPE2, SHAPE3;

reset(arg) {
        if(!present("bulletinboard", this_object())){
move_object(clone_object("players/boltar/templar/board"),this_object());
        }
  if(arg) return;


long_desc =
  "A sparse working area with nothing but a desk and chair. You may\n"+
  "turn your privacy shield (on/off). There are also hidden exits to\n"+
  "the 'church' and the 'post' office.\n";
set_light(1);

items = ({
  "chair","A creaky old wooden chair",
  "desk","A scarred old desk with the intial 'B' carved in it",
});

dest_dir = ({
  "room/adv_inner.c","north",
});

}

short(){ 

 
switch(random(14)){
    case 0: COLOR = HIR; break; 
    case 1: COLOR = RED; break; 
    case 2: COLOR = HIB; break;
    case 3: COLOR = BLU; break;
    case 4: COLOR = HIG; break; 
    case 5: COLOR = GRN; break;
    case 6: COLOR = HIC; break; 
    case 7: COLOR = CYN; break; 
    case 8: COLOR = HIM; break;
    case 9: COLOR = MAG; break;
    case 10: COLOR = HIY; break; 
    case 11: COLOR = YEL; break;
    case 12: COLOR = BOLD; break;
    case 13: COLOR = BLK; break;
 }
 
switch(random(14)){
    case 0: COLOR2 = HIR; break; 
    case 1: COLOR2 = RED; break; 
    case 2: COLOR2 = HIB; break;
    case 3: COLOR2 = BLU; break;
    case 4: COLOR2 = HIG; break; 
    case 5: COLOR2 = GRN; break;
    case 6: COLOR2 = HIC; break; 
    case 7: COLOR2 = CYN; break; 
    case 8: COLOR2 = HIM; break;
    case 9: COLOR2 = MAG; break;
    case 10: COLOR2 = HIY; break; 
    case 11: COLOR2 = YEL; break;
    case 12: COLOR2 = BOLD; break;
    case 13: COLOR2 = BLK; break;
 }
switch(random(14)){
    case 0: COLOR1 = HIR; break; 
    case 1: COLOR1 = RED; break; 
    case 2: COLOR1 = HIB; break;
    case 3: COLOR1 = BLU; break;
    case 4: COLOR1 = HIG; break; 
    case 5: COLOR1 = GRN; break;
    case 6: COLOR1 = HIC; break; 
    case 7: COLOR1 = CYN; break; 
    case 8: COLOR1 = HIM; break;
    case 9: COLOR1 = MAG; break;
    case 10: COLOR1 = HIY; break; 
    case 11: COLOR1 = YEL; break;
    case 12: COLOR1 = BOLD; break;
    case 13: COLOR1 = BLK; break;
 }


switch(random(6)){
    case 0: COLOR3 = HIR; break; 
    case 1: COLOR3 = HIB; break; 
    case 2: COLOR3 = HIG; break;
    case 3: COLOR3 = HIC; break;
    case 4: COLOR3 = HIM; break; 
    case 5: COLOR3 = HIY; break;
}

switch(random(11)){
    case 0: SHAPE = "7"; break;
    case 1..2: SHAPE = "@"; break;
    case 3..4: SHAPE = "X"; break;
    case 5..6: SHAPE = "!"; break;
    case 7..8: SHAPE = "~"; break;
    case 9..10: SHAPE = "*"; break;
}
switch(random(6)){
    case 0: SHAPE2 = "7"; break;
    case 1: SHAPE2 = "@"; break;
    case 2: SHAPE2 = "X"; break;
    case 3: SHAPE2 = "!"; break;
    case 4: SHAPE2 = "~"; break;
    case 5: SHAPE2 = "*"; break;
}
switch(random(6)){
    case 0: SHAPE3 = "7"; break;
    case 1: SHAPE3 = "@"; break;
    case 2: SHAPE3 = "X"; break;
    case 3: SHAPE3 = "!"; break;
    case 4: SHAPE3 = "~"; break;
    case 5: SHAPE3 = "*"; break;
}

 if(SHAPE == "7" && SHAPE2 == "7" && SHAPE3 == "7")
{
return " "+HIY+"*!* !JACKPOT! *!*"+NORM+"  "+COLOR3+"["+COLOR+SHAPE+NORM+COLOR3+"] "+NORM+COLOR3+"["+NORM+COLOR1+SHAPE2+NORM+COLOR3+"] ["+NORM+COLOR2+SHAPE3+NORM+COLOR3+"]"+NORM+"  "+HIY+"*!* !JACKPOT! *!*"+NORM+"";
}
return ""+BLK+BOLD+"["+HIY+"slots"+NORM+BLK+BOLD+"]"+NORM+"  "+COLOR3+"["+COLOR+SHAPE+NORM+COLOR3+"] "+NORM+COLOR3+"["+NORM+COLOR1+SHAPE2+NORM+COLOR3+"] ["+NORM+COLOR2+SHAPE3+NORM+COLOR3+"]"+NORM+"  "+BLK+BOLD+"["+HIY+"slots"+NORM+BLK+BOLD+"]"+NORM+"";
}
init() {
  ::init();
  add_action("church","church");
  add_action("post", "post");
  add_action("off", "off");
  add_action("church", "church");
if(this_player()->query_real_name() != NAME && shield == 1) {
  write("You feel an electric shock and see a FLASH of white light\n"+
        "as you rebound off some surrounding shield.\n");
  this_player()->move_player("off the shields#room/church");
  return 1; }
 }

church() {
  TP->move_player("church#room/church.c");
  command("look",this_player());
  return 1; }

static on() {
  write("You "+BOLD+"activate"+NORM+" the shield.\n");
  shield = 1;
  return 1; }

static off() {
if(TP->query_real_name() != NAME) {
  write("You are not allowed to do that!!!!!!!\n");
  return 1; }
  write("You "+BOLD+"deactivate"+NORM+" the shield.\n");
  shield = 0;
  return 1; }

post(){
  TP->move_player("post office#room/post.c");
  return 1; }

