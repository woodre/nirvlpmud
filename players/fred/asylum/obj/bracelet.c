inherit "/obj/armor";
#include <ansi.h>
#define tpn this_player()->query_name()

reset(arg) {
  if(arg) return;
  ::reset(arg);
  set_name("bracelet");
  set_alias("ring");
  set_long(
  "  A small silver bracelet that is old and worn. There is\n"+
  "writing on the front and the back of the bracelet.\n");
  set_type("ring");
  set_ac(2);
  set_weight(1);
  set_value(2300);
}
  
query_save_flag(){
  return 1; }

short(){
  if(worn) {
    return "A "+BOLD+BLK+"Silver"+NORM+" Bracelet (worn)";
    }
  else{
    return "A "+BOLD+BLK+"Silver"+NORM+" Bracelet";
    }
  }
 
init(){
  ::init();
    add_action("readem","read");
  }

wear(str){
   string A;
   int a;
   if(!id(str)) return 0;
   if(worn) return 0;
 ::wear(str);
   a = random(6);

switch(a){
  case 0: A = "  People being "+RED+"burned"+NORM+" alive while trapped in a room..."; break;
  case 1: A = "  A woman "+BOLD+"kicking"+NORM+" and "+BOLD+"screaming"+NORM+" while being dragged away by doctors..."; break;
  case 2: A = "  A table full of surgical equipment covered in "+BOLD+RED+"blood"+NORM+"..."; break;
  case 3: A = "  A man shaking "+BOLD+"violently"+NORM+" while under going "+HIY+"electroshock"+NORM+" therapy..."; break;
  case 4: A = "  Horrendous "+GRN+"screams"+NORM+" coming from behind a locked "+BOLD+BLK+"door"+NORM+"..."; break;
  case 5: A = "  "+RED+"Blood"+NORM+" stained walls and floors..."; break; }

   write(
      "As you slip the "+BOLD+BLK+"silver"+NORM+" bracelet onto your wrist your "+BOLD+"eyes"+NORM+" snap shut...\n"+
      "   your mind is flooded with "+BLU+"visions"+NORM+" of...\n"+
      "    "+A+"\n"+
      "         You open your eyes in a "+HIY+"cold"+NORM+" sweat.\n");
      return 1; }

readem(str){
  if(!str){ write("What would you like to read?\n"); return 1; }
  if(str == "bracelet"){ write("You can only read the <"+GRN+"front"+NORM+"> and <"+GRN+"back"+NORM+">\n");
    return 1; }
  if(str == "front"){
    say(tpn+" reads the front of the bracelet.\n");
    write(MAG+"                  F.I.A.\n"+NORM);
    write(MAG+"           Fred's Insane Asylum\n"+NORM);
    return 1; }
  if(str == "back"){
    say(tpn+" reads the back of the bracelet.\n");
    write(
     MAG+"          Name: Gregory H. Parsens\n"+
         "         D.O.B: 11-08-17\n"+     
         "     Patient #: 0512A3KL9\n"+NORM);
    return 1; }
  }
