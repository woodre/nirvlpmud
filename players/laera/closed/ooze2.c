#include "/players/fred/ansi.h"
#include "/players/fred/defines.h"
inherit "/obj/weapon.c";

reset (arg) {
  ::reset(arg);
  if(arg) return;

  set_name("ooze");
  set_alias("blob");
  set_short("A mysterios blob of green ooze");
  set_long(
 "  A silvery ball of ooze that you could mold into almost any\n"+
 "weapon. To see it's many uses 'helpooze'.\n" );
  set_class(16);
  set_weight(2);
  set_value(5000);
  set_hit_func(TO);
  }

init(){
 ::init();
   add_action("helpyhelp", "helpooze");
   add_action("booya", "name_ooze");
   add_action("popo", "lname_ooze");
   add_action("snausage", "type_ooze");
   add_action("foam_cow", "boost_ooze");
   add_action("cubicle_good", "README");
   }

helpyhelp(){
  write(YEL+"*****************************************************************"+NORM+BOLD+"\n\n"+
        "name_ooze"+NORM+" ............<set the Short description>"+BOLD+"\n"+
        "lname_ooze"+NORM+" ...........<set the Long description>"+BOLD+"\n"+
        "type_ooze"+NORM+" ............<set weapon type ie. sword, club, bow>"+BOLD+"\n"+
        "boost_ooze"+NORM+" ...........<raise it's wc. It will cost you exp to do>"+BOLD+"\n"+
        "README"+NORM+" ...............<legal disclaimer>"+YEL+"\n\n"+
        "*****************************************************************"+NORM+"\n");
  return 1; }

booya(str){
  set_short(str);
  write("Ok.\n");
  return 1; }

popo(){
 write("Enter your description of the weapon and end with '**'\n");
 long_desc = "";
 input_to("my_name_is_FRED");
 return 1; }

my_name_is_FRED(str){
  if(str == "**"){
    write("Ok.\n");
    return 1; }
  long_desc += str+"\n";
  input_to("my_name_is_FRED");
  return 1;
 }

snausage(str){
  if(str == "sword" || str == "knife" ||
     str == "axe" || str == "bow" ||
     str == "club" || str == "polearm"){
  	set_type(str);
  	write ("The ooze is now a" + str + "\n");
  	return 1; }
  else
  	notify_fail("You must use sword, knife, axe, bow, club, or polearm.\n");
	return 0;}


foam_cow(){
  int yarbles, garbles, EEK, GOO, FOO, MOOCOW, MADCOW;
  string drool;
  yarbles = TP->query_level();
  garbles = TP->query_exp();
  GOO = TP->query_extra_level();
  drool = TO->query_type();
  MOOCOW = 0;
  MADCOW = TO->weapon_class();

   if(MOOCOW = 0){ FOO = 5000; }
   if(MOOCOW = 1){ FOO = 15000; }
   if(MOOCOW = 2){ FOO = 30000; }
   if(GOO < 1 && yarbles < 21)
     EEK = garbles - call_other("room/adv_guild","get_next_exp",
    (this_player()->query_level()) - 1);

    if(GOO > 0 && yarbles < 21)
      EEK = garbles - call_other("room/exlv_guild","get_next_exp",
    (this_player()->query_extra_level()) - 1);

      if(FOO > EEK){
        write("You don't have enough exp to boost your "+drool+" yet.\n");
        return 1; }
      if(EEK > FOO){
        if(MADCOW > 18){
         write("The weapon is currently at it's highest level.\n");
         return 1; }
        if(MADCOW < 20){
        write("You boost the energy of your "+drool+"\n");
        set_class(MADCOW+1);
        TP->add_exp(-FOO);
        MOOCOW ++;
        return 1; }
       }
     }

cubicle_good(){
  write("\nSince you have the freedom to set the name on this weapon\n"+
        "I do expect players to keep it civil. Anything that people\n"+
        "would find offensive ie. using other player names in a way\n"+
        "that would be innappropriate, swearing, etc. Will result in\n"+
        "an initial warning. No second warnings will be given and you\n"+
        "will be punished. Thank you.\n\n"+
        "Fred.\n");
  return 1; }

weapon_hit(hoser){
   int p, o, t, s, weed, flipflop;
   string whoop;
   p = TP->query_attrib("wil");
   o = TP->query_attrib("int");
   t = TP->query_hp();
   s = TP->query_sp();
   flipflop = TO->weapon_class();
   whoop = TO->query_type();
   weed = random(50);

   if(weed < 10){
     if((s-t) < ((p*o)*2)){
       write("\nYour "+GRN+capitalize(whoop)+NORM+" channels through the air\n"+
             ""+RED+"         D E S T R O Y I N G "+NORM+hoser->query_name()+"\n\n");
       say("\n"+TP->query_name()+RED+" destroys "+NORM+hoser->query_name()+"\n"+
           "  with "+TP->query_possessive()+" powerful "+whoop+"\n\n");
       if(flipflop = 16){
         hoser->heal_self(-(1+random(2))); }
       else if(flipflop = 17){
         hoser->heal_self(-(2+random(4))); }
       else if(flipflop = 18){
         hoser->heal_self(-(3+random(6))); }
       else{
         hoser->heal_self(-(4+random(8))); }
      return 1; }
    return 4; }

   if(weed > 45){
      write("\nYour "+YEL+capitalize(whoop)+NORM+" shines with an "+MAG+"eerie"+NORM+"\n"+
            "  Glow.  "+HIY+"Light"+NORM+BOLD+" energy"+NORM+" fires from your "+whoop+"\n"+
            "    into "+hoser->query_name()+"\n");
      say("\n"+TP->query_name()+"'s "+whoop+" fires "+HIY+"Light"+NORM+BOLD+" energy"+NORM+" into "+hoser->query_name()+"\n");
      if(flipflop = 16){
        TP->heal_self(1+random(1)); }
      else if(flipflop = 17){
        TP->heal_self(2+random(2)); }
      else if(flipflop = 18){
        TP->heal_self(3+random(3)); }
      else{
        TP->heal_self(4+random(4)); }
      return (3+random(3)); }
   }
