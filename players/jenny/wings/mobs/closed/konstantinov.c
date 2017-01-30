/*specials - wc bonus 52 the heal_self bonus comes to 20, the bonus that happens when opponents hp get low comes to 12, i figure that should go off 25 percent of the time or more
the bonus that goes off more when the monsters hp get low comes to 20.  Together that's 52
*/
inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "vladimir konstantinov" ||  str == "vladimir" || str == "konstantinov" || str == "Vladimir Konstantinov" || str == "vladi" || str == "alumni"; } 
object ob;
reset(arg)
{
   ::reset(arg);
   if (arg) return;
   set_name("Vladimir Konstantinov");
   set_race("human");
   set_gender("male");
   set_al(1000);
   set_level(26);
   set_hp(1220+random(65));

   MOCO("/players/jenny/wings/items/vladistick.c"),TO);
   init_command("wield stick");

   set_wc(48);
   set_wc_bonus(52);
   set_ac(25);
   set_heal(5,2);
    set_dead_ob(this_object());

   MOCO("/players/jenny/wings/items/painkillers.c"),TO);
   MOCO("/players/jenny/wings/items/painkillers.c"),TO);
   if(!random(250)) {
   MOCO("/players/jenny/wings/items/1997ring.c"),TO);
   init_command("wear ring");}
   MOCO("/players/jenny/wings/items/puck.c"),TO);
   MOCO("/players/jenny/wings/items/puck.c"),TO);

message_hit = ({
        BOLD+"punches"+NORM," in the mouth, knocking out a few teeth",
        BOLD+"jabs"+NORM," in the eye with his fingers",
        BOLD+"head buts"+NORM," opening up a nasty cut",           
        BOLD+"knees"+NORM," in the groin",
        BOLD+"kicks"+NORM," in the stomach",
        BOLD+"punches"+NORM," in the ribs",
        BOLD+"punches"+NORM," in the arm"
        });

   set_short(BOLD+RED+"Vladimir Konstantinov"+NORM);
   set_long(
      "Vladimir Konstantinov is a Detroit Red Wings alumni.  He is an average\n"+
      "size man with short brown hair.  His brief NHL career only lasted 6 years,\n"+
      "from 1991 to 1997.  It was tragically cut short when the limo he was riding\n"+
      "in crashed into a tree, causing him to suffer severe brain damage.  Vladimir\n"+
      "was just starting to establish himself as one of the top defensemen in the\n"+
      "the NHL.  He was a fearsome body-checker who had good offensive skills.\n"+
      "Vladimir played a big part in the Wings ending their 42 year Stanley Cup\n"+
      "drought in 1997.\n");

}
init() {
  ::init();
add_action("nomove","north");
add_action("nomove","east");
add_action("nomove","leave");
}
nomove() {
     if(MEAT) {
write("Vladimir Konstantinov says: Where do you think you're going"+MEATN+"?\n");
         if(attacker_ob) { already_fight = 0; attack();}

   return 1; }}
heart_beat() {
   ::heart_beat();
  if(MEAT){
         if(  (MEAT->query_mhp() - MEAT->query_hp()) > random(465))     if(attacker_ob) { already_fight = 0; attack(); }

    if(!random(6)) ouch();

    if(TO->query_hp() < random(1500))      if(attacker_ob) { already_fight = 0; attack(); }

  }
}

ouch() {
   if(!environment(this_object())) return 1;
   if(MEAT)
      if(environment() == environment(MEAT)) {
      say("\n"+
        RED+"Vladimir Konstantinov rams "+MEATN+" up against the wall.\n"+
      "\n"+
      CAP(MEATN)+" appears to be a little dizzy."+NORM+"\n"+
      "\n");
      MEAT->heal_self(-50-random(20));
      return 1; }
   return 1;
}
monster_died() { 
  write_file("/players/jenny/logs/alumni", MEATN+" killed "+TO->query_name()+" on "+ctime()+"\n"); 
return 0;}
