#include "/players/fred/ansi.h"
inherit "/obj/armor";
#define tpn this_player()->query_name()
#define tpp this_player()->query_pronoun()
#define USER environment(this_object())

reset(arg) {
  if(arg) return;
  set_name("shoes");
  set_alias("boots");          
  set_short("Punter's "+BOLD+YEL+"Shoes"+NORM);
  set_long(
  "  These are specially designed shoes for those crazy\n"+
  "people that like to punt some serious ASS!!\n");
  set_type("boots");
  set_ac(2);
  set_weight(1);
  set_value(500);
}

init(){
  ::init();
   add_action("puntem","punt");
  }

puntem(str){
  int p;
  object person;
  if(!str){ write("Punt who?\n"); return 1; }
   person = find_living(str);
   p = (random(99900)+100);
   if(!present(person, environment(this_player()))){
    write("That person is not here!\n");
    return 1; }
  if(!worn){ write("You have to be wearing the shoes.\n"); return 1; }
  if(p > 80000){
    say(
      tpn+" punts "+capitalize(str)+" "+p+" yards.\n"+
      "Holy Shit!! That's a new record!\n"+
      "All Hail the KING!\n");
    write(
      "You punt "+capitalize(str)+" "+p+" yards.\n"+
      "Holy Shit!! That's a new record!\n"+
      "Everyone should worship you.\n");
     return 1; }
  if(p > 60000){
    say(
      tpn+" punts "+capitalize(str)+" "+p+" yards.\n"+
      "Aww... "+capitalize(str)+"'s gonna be feeling that one for awhile!\n"+
      "You yell: Whose YOUR DADDY!!\n");
    write(
      "You punt "+capitalize(str)+" "+p+" yards.\n"+
      "Aww... "+capitalize(str)+"'s gonna be feeling that one for awhile!\n"+
      tpn+" yells: Whose YOUR DADDY!!\n");
    return 1; }
  if(p > 40000){
    say(
      tpn+" punts "+capitalize(str)+" "+p+" yards.\n"+
      "WOW!! that's like 4 city blocks!\n");
    write(
      "You punt "+capitalize(str)+" "+p+" yards.\n"+
      "WOW!! that's like 4 city blocks!\n");
    return 1; }
  if(p > 20000){
    say(
      tpn+" punts "+capitalize(str)+" "+p+" yards.\n"+
      "DAMN!! "+tpn+" kicked "+capitalize(str)+"'s ASS!\n"); 
    write(
      "You punt "+capitalize(str)+" "+p+" yards.\n"+
      "DAMN!! You kicked "+capitalize(str)+"'s ASS!\n");
    return 1; }
  if(p > 10000){
    say(
      tpn+" punts "+capitalize(str)+" "+p+" yards.\n"+
      "You all point and laff at "+tpn+"\n");
    write(
      "You punt "+capitalize(str)+" "+p+" yards.\n"+
      "Everyone points at you and laffs!\n"+
      "God you suck. You better practice more.\n");
    return 1; }
  if(p > 100){
    say(
      tpn+" tries to punt "+capitalize(str)+" but misses!\n"+
      tpn+" flies through the air and lands on "+tpp+"'s head. OUCH!\n");
    write(
      "You try to kick "+capitalize(str)+" but miss!\n"+
      "You sail through the air and land on your head. OUCH!\n");
      this_player()->add_hit_point(-(random(20)+10));
      return 1; } 
  }    