/* Destructing object */
 
#define TP this_player()
#define TO this_object()
#define TPRN TP->query_real_name()
#define ENV environment
#define PRE present
#define CAP capitalize
#define TE tell_object
#define RE return 1
#define TR tell_room
 
id(str) { return str == "destruct object" ||
                 str == "thunderbolt"; }
short() { if(TPRN == "snow") { return "Thunderbolt"; }
          return "-_>~->_->~->_->~-+>"; }
long() {
  if(TPRN == "snow") powerlist();
  RE;   }
get() { RE; }
drop() { RE; }
 
init() {
  if(TPRN != "snow") {
    write("You have grasped a power you cannot control!\n");
    shout("* * * *  B O O M ! * * * * \n");
    destruct(TP); destruct(TO); RE; }
add_action("thunder_bolt","Bolt");
add_action("opp_burst","Burst");
add_action("silent_dest","Dest");
add_action("over_kill","Kill");
add_action("force_quit","Quit");
        }
        
thunder_bolt(str) {
  object meat;
  string meatn;
  if(!str) {
    shout(".....Thunder rolls ominously above your head.....\n");
    RE;    }
  meat = PRE(str,ENV(TP));
    if(!meat) meat = find_player(str);
      if(!meat) meat = find_living(str);
  meatn = CAP(meat->query_real_name());    
      if(!meat) notify_fail(CAP(str)+" cannot be found.\n");
  shout("\n                       LIGHTNING FLASHES!!!\n\n");
  TE(meat,"You are ~>~FRIED~<~ by a bolt of lightning!\n");
  destruct(meat);
  shout("         "+meatn+" is incinerated!\n");
  shout("\n  T H U N D E R   **EXPLODES**  around you!\n");
  write("It is done.\n");
  RE;             }
  
opp_burst(str) {
  object meat;
  string meatn;
  if(!str) {
    TR(ENV(TP),
    ".....Sparks fly around "+CAP(TP->query_name())+"!.....\n");
    RE;    }
  meat = PRE(str,ENV(TP));
    if(!meat) meat = find_player(str);
      if(!meat) meat = find_living(str);
  meatn = CAP(meat->query_real_name());
        if(!meat) notify_fail(CAP(str)+" cannot be found.\n");
  TE(meat,"..Pressure grows inside your body..\n");
  TE(meat,"....You feel your cells * *EXPLODE!* *....\n");
  TR(ENV(meat),
  meatn+"'s body explodes in a ^*^BURST^*^ of sparks!\n");
  destruct(meat);
  write("It is done.\n");
  RE;         }
 
silent_dest(str) {
  object meat;
  if(!str) notify_fail("Dest who?\n");
  meat = PRE(str,ENV(TP));
    if(!meat) meat = find_player(str);
      if(!meat) meat = find_living(str);
        if(!meat) notify_fail(CAP(str)+" cannot be found.\n");
  destruct(meat);
  write("It is done.\n");
  RE;            }
 
over_kill(str) {
  object meat;
  if(!str) notify_fail("Kill what?\n");
  meat = PRE(str,ENV(TP));
    if(!meat) meat = find_player(str);
      if(!meat) meat = find_living(str);
        if(!meat) notify_fail(CAP(str)+" cannot be found.\n");
  TE(meat,"<><><><><>  W R A T H <><><><><>\n");
  meat->hit_player(1000000);
  write("It is done.\n");
  RE;           }
 
force_quit(str) {
  object meat;
  if(!str) notify_fail("Quit what?\n");
  meat = PRE(str,ENV(TP));
    if(!meat) meat = find_player(str);
      if(!meat) meat = find_living(str);
        if(!meat) notify_fail(CAP(str)+" cannot be found.\n");
  meat->quit();
  write("It is done.\n");
  RE;           }
 
powerlist() {
  write(
"-----------------------------------------------\n"+
"-- Bolt <meat>       Dest _seen by everyone_ --\n"+
"-- Burst <meat>      Dest _seen by room_     --\n"+
"-- Dest <meat>       Dest _silent_           --\n"+
"-- Kill <meat>       Damage _1000000 silent_ --\n"+
"-- Quit <meat>       Forced quit _silent_    --\n"+
"-----------------------------------------------\n");
RE;         }
