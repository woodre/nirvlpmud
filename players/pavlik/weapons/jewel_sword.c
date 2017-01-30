#include <ansi.h>
#define ME capitalize(this_player()->query_name())
#define IT capitalize(attacker->query_name())
inherit "obj/weapon";
int i, wow;
reset(arg) {
::reset(arg);
if(arg) return;
 set_alias("sword");
 set_type("sword");
 set_name("rusty longsword");
 set_short("The Jewel Sword");
 set_long("The Jewel Sword.\n");
 set_class(12);
 set_weight(4);
 set_value(100000);
 set_hit_func(this_object());
 set_save_flag(0);
 wow = 0;
}

short(){
  if(wow == 0){
    if(wielded) return "A rusty longsword (wielded)";
    else return "A rusty longsword";
  } else {
    if(wielded) return "The "+HIC+"Jewel Sword"+NORM+" (wielded)";
    else return "The "+HIC+"Jewel Sword"+NORM;
  }
}

long(){
  if(wow == 0)
    write("An old rusty longsword.\n");
  else
    write("The marvelous Jewel Sword.\n"+
    "Huge shiny jewels adorn the hilt of this sword.  Each gem shines with\n"+
   "magical power.  There seems to be something written on the hilt.\n"+
    "type 'help jewel sword' for more information.\n");
  return;
}

weapon_hit(attacker) {
  if(wow == 0){
    i = random(5);
    if(i == 0) write("The blade flakes off abit when you swing it.\n");
    if(i == 1) write("The pommel rattles loosely as you swing the sword.\n");
    if(i == 2) write("The balance of this sword is all wrong!  You almost drop the weapon.\n");
    if(i == 3) write("Something rattles around inside the pommel when you swing the sword.\n");
    if(i == 4) write("There is something very strange about the pommel of this sword...\n");
  return;
  }

  i = random(100);
if(i > 70){
  write("The Jewel Sword spews "+HIR+" a stream of fire!"+NORM+"\n");
  write(HIR+IT+" is engulfed in flames!!!"+NORM+"\n");
  say(ME+"'s sword spews forth a "+HIR+" column of flame!"+NORM+"\n");
  say(HIR+IT+" is engulfed in fire!!!"+NORM+"\n");
  return 10;
} else if(i > 35){
  i = random(4);
  if(i == 0){
    write("You hack mercilessly at "+IT+".\n");
    say(ME+" hacks away mercilessly with the Jewel Sword.\n");
  } else if(i == 1){
    write("The Jewel Sword glows "+HIC+"hot"+NORM+" with magic!\n");
    say(ME+"'s sword glows "+HIC+BLINK+"hot"+NORM+" with magic!\n");
  } else if(i == 2){
    write("You slash "+IT+" across the stomach.\n");
    write("      "+HIR+"Blood gushes out of the wound!"+NORM+"\n");
    say(ME+" slashes his enemy across the stomach.\n");
    say("        "+HIR+"Blood gushes out of the wound!"+NORM+"\n");
  } else if(i == 3){
    write("You smash "+IT+" in the face with the hilt of your sword.\n");
    say(ME+" smashes "+IT+" in the face with the hilt of his sword.\n");
  } else if(i == 4){
    write("The magical sword sinks "+HIR+"deep"+NORM+" into the flesh of your enemy!\n");
    say(ME+"'s magical sword sinks "+HIR+"deep"+NORM+" into the flesh of his enemy!\n");
  }
  return 4;
  } else {
  return;
  }
}

init() {
  ::init();
 add_action("see_pommel","look");
 add_action("remove_pommel","twist");
 add_action("whirl_wind", "wwind");
 add_action("death", "death");
 add_action("help", "help");
}

whirl_wind(str) {
   object ob, obj1;
   int exp;
  if(wow == 0) return 0;
  if(this_player()->query_sp() < 30){
    write("You do not have enough magical energy for this.\n");
    return 1;
  }
  if(!str) {
    write("Who do you want to Chop up?\n");
    return 1;
  }
  ob = present(lower_case(str), environment(this_player()));
  if(!ob->query_npc()) {
   write("You cannot use this spell on players!\n");
   return 1;
}
  if(!ob) {
  write("That object is not here!\n");
  return 1;
  }
  ob->hit_player(random(20)+12);
  this_player()->add_spell_point(-30);
  ob->attacked_by(this_player());
  write("You call upon the magical enegry of the sword to send it\n"+
  "whirling into motion faster then the eye can see.\n"+
  HIC+"You chop down your enemy with a flury of deadly attacks!"+NORM+"\n");
  say(ME+" whirls the Jewel Blade in fast deadly strokes.\n"+
  HIC+ME+" chops "+capitalize(str)+" into tiny little pieces!"+NORM+"\n");
  return 1;
}

death(str){
  object ob;
  int dmg;
  string guy;
  if(wow == 0) return 0;
 if(this_player()->query_sp() < 100) {
   write("You do not have enough magical energy to do this.\n");
  return 1;
}
 if(!str) {
   write("Destroy who?\n");
  return 1;
  }
  ob = present(lower_case(str), environment(this_player()));
  if(!ob->query_npc()){
  write("Nice try!\n You can't use this spell on Players!\n");
   return 1;
 }
   if(!ob) {
   write("That object is not here!\n");
   return 1;
   }
   if(!(this_player()->query_attack())) {
   write("You must be attacking first!\n");
           return 1;
     }
   if(ob->query_level() > 20) {
  write("This monster is too powerful for the death function of\n"+
  "this sword.  You think better of using the swords power\n"+
  "and save the weapon for another foe.\n");
        return 1;
   }
  guy = capitalize(ob->query_name());
  this_player()->add_spell_point(-100);
  dmg = ob->query_hp();
  ob->heal_self(-dmg);
  write(
  "You gather all your magical power about you.  Focusing all\n"+
  "your energy on your target you hurl the blade at its heart!\n"+
  HIR+"The Jewel Sword strikes "+guy+" in the chest and sinks all the way to the hilt!\n"+
  HIC+"The sword shivers and then blows up into thousands of pieces!!!"+NORM+"\n");
  say(
  ME+" concentrates and focuses all his energy.\n"+
  ME+" hurls his magical sword at "+guy+"!\n"+
  HIR+"The sword strikes "+guy+" in the chest and sinks all the way to the hilt!\n"+
  HIC+"The sword quivers and then explodes into thousands of pieces!!!\n");
  say(NORM);
  ob->hit_player(40);
  destruct(this_object());
return 1;
}

see_pommel(str){
  if(str == "pommel" || str == "at pommel"){
    write("The rusty swords pommel is old and beaten.\n"+
   "It looks like one good twist would rip it off the hilt.\n");
  return 1;
  }
}

remove_pommel(str){
  if(str == "pommel"){
    write("You grab the pommel and give it a good twist.\n"+
    "The pommel twists off and falls to the floor!\n"+
    CYN+"The room is filled with magical light as the old rusy sword\n"+
    "transforms into a powerful weapon of magic!"+NORM+"\n");
    say(ME+"'s old rusty longsword transforms into a powerful weapon of magic!\n");
    this_object()->set_name("The Jewel Sword");
    this_object()->set_class(20);
    wow = 1;
  return 1;
  }
}

help(str){
  if(wow == 0) return 0;
  if(str == "jewel sword"){
    write(
    "The Jewel Sword is an ancient powerful artifact from lost times.\n"+
    "Jewel Swords are empowered with 2 magical functions:  The whirlwind\n"+
    "attack and the devasting death magic.\n"+
    "   wwind <target> : costs 30sp and does major damage.\n"+
    "   death <target> : costs 100sp and will outright kill the target,\n"+
    "                    the sword is destroyed when this function is used.\n"+
    "\n");
    return 1;
  }
}
