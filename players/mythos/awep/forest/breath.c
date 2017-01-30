/***********************************
*   OK.. this is a wc 20 weapon with 
*   a nice return.. however, it is
*   extremely heavy (15) and the player
*  will have trouble wielding anything
*  but this.  also, there is a randomm
*  chance that a uncontrolled mass attack 
*  will occur (wont effect players)  taken
*   off the ryu.c  
*
*    approved by saber
******************************************/


#include "/players/mythos/closed/ansi.h"
#define tp this_player()->query_name()
int w;
string mesin, mesout, tmin, tmout, pt,ti, ali;
 inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
   set_name("dragon aura");
    set_alt_name("dragon");
    set_alias("aura");
     set_short("Dragon's Aura");
  set_long(RED+"An aura taken from a dragon.\n"+NORM+
      "Wield it and be imbued with the powers of a dragon!\n"+
      "But be careful, mortals may have trouble controlling it.\n");
    set_class(20);
    set_weight(15);
    set_value(10000);
    set_hit_func(this_object());
}
weapon_hit(attacker){
int l,w,n,m,ch;
object ob, ob1;
ob=environment(this_player());
  l=call_other(this_player(),"query_attrib","luc");
  w=call_other(this_player(),"query_attrib","wil");
ch=random(20);
  if(ch==0) {
  n=random(100);
    if((w*3)<n) {
      write("You lose control over the dragon's aura!\n");
      write("\n\n");
   say("You see "+capitalize(this_player()->query_name())+" lose control!\n");
      write(BOLD+"\n\tLightning floods the area!\n\n"+NORM+
                 BLU+ "\t^   ^   ^   ^   ^   ^   ^   ^   ^\n"+
                      "\t ^   ^ ^ ^   ^  ^  ^   ^   ^ ^  ^\n"+
                      "\t  ^   ^   ^   ^ ^ ^   ^   ^   ^\n"+NORM+BLU+
                      "\t ^ ^   ^   ^   ^^^   ^   ^   ^ ^\n"+
                      "\t    ^   ^   ^   ^   ^   ^   ^\n"+
                      "\t   ^   ^    ^ FLASH ^   ^   ^\n"+NORM+BLU+
                      "\t  ^     ^    ^  ^  ^     ^   ^\n"+
                      "\t   ^        ^   ^    ^   ^\n"+
                      "\t   ^            ^     ^ \n"+NORM+BLU+
                      "\t    ^            ^    ^\n"+
                      "\t                 ^\n"+NORM+"\n");
      say(BOLD+"\n\tLightning floods the area!\n\n"+NORM+
                 BLU+ "\t^   ^   ^   ^   ^   ^   ^   ^   ^\n"+
                      "\t ^   ^ ^ ^   ^  ^  ^   ^   ^ ^  ^\n"+
                      "\t  ^   ^   ^   ^ ^ ^   ^   ^   ^\n"+NORM+BLU+
                      "\t ^ ^   ^   ^   ^^^   ^   ^   ^ ^\n"+
                      "\t    ^   ^   ^   ^   ^   ^   ^\n");
                  say("\t   ^   ^    ^ FLASH ^   ^   ^\n"+NORM+BLU+
                      "\t  ^     ^    ^  ^  ^     ^   ^\n"+
                      "\t   ^        ^   ^    ^   ^\n"+
                      "\t   ^            ^     ^ \n"+NORM+BLU+
                      "\t    ^            ^    ^\n"+
                      "\t                 ^\n"+NORM+"\n");
      ob1=first_inventory(ob);
      while(ob1) {
        if(living(ob1) && ob1->query_npc() && !call_other(ob1,"id","messenger")) {
        call_other(ob1,"hit_player",random(20));
        ob1->attack_object(environment(this_object()));
        }
      ob1=next_inventory(ob1);
      }
    return;}
    else{
    write("You command nature to strike your foe!\n");
    write(BOLD+"\n\tLightning floods the area!\n\n"+NORM+
                 BLU+ "\t^   ^   ^   ^   ^   ^   ^   ^   ^\n"+
                      "\t ^   ^ ^ ^   ^  ^  ^   ^   ^ ^  ^\n"+
                      "\t  ^   ^   ^   ^ ^ ^   ^   ^   ^\n"+NORM+BLU+
                      "\t ^ ^   ^   ^   ^^^   ^   ^   ^ ^\n"+
                      "\t    ^   ^   ^   ^   ^   ^   ^\n"+
                      "\t   ^   ^    ^ FLASH ^   ^   ^\n"+NORM+BLU+
                      "\t  ^     ^    ^  ^  ^     ^   ^\n"+
                      "\t   ^        ^   ^    ^   ^\n"+
                      "\t   ^            ^     ^ \n"+NORM+BLU+
                      "\t    ^            ^    ^\n"+
                      "\t                 ^\n"+NORM+"\n");
    say(capitalize(this_player()->query_name())+ " commands nature!\n");
      say(BOLD+"\n\tLightning floods the area!\n\n"+NORM+
                 BLU+ "\t^   ^   ^   ^   ^   ^   ^   ^   ^\n"+
                      "\t ^   ^ ^ ^   ^  ^  ^   ^   ^ ^  ^\n"+
                      "\t  ^   ^   ^   ^ ^ ^   ^   ^   ^\n"+NORM+BLU+
                      "\t ^ ^   ^   ^   ^^^   ^   ^   ^ ^\n"+
                      "\t    ^   ^   ^   ^   ^   ^   ^\n");
                  say("\t   ^   ^    ^ FLASH ^   ^   ^\n"+NORM+BLU+
                      "\t  ^     ^    ^  ^  ^     ^   ^\n"+
                      "\t   ^        ^   ^    ^   ^\n"+
                      "\t   ^            ^     ^ \n"+NORM+BLU+
                      "\t    ^            ^    ^\n"+
                      "\t                 ^\n"+NORM+"\n");
         call_other(attacker,"hit_player",random(20));
  return 7;}
  }
  if(ch>0 && ch<4 ) {
  write("You bite down on your enemy!  Feels real good!\n");
  say(BOLD+"The Dragon bites down on its foe!\n"+NORM);
  m=random(60);
    if(l>m) {
      attacker->hit_player(13);
tell_object(attacker,"You feel the teeth of the Dragon sink deep into you!\n");
write(RED+"You taste the blood of your foe- what pleasure!\n"+NORM);
    }
return 4;}
  if(ch>3 && ch < 7) {
  m=random(60);
  write(GRN+"You rake your claw across your foe's body!\n"+NORM);
  say(GRN+"The RYU rakes its claw across its foe's body!\n"+NORM);
  if(l>m) {
    attacker->hit_player(3);
write(HIR+"Blood splatters everywhere as you rip both your claws through "+
"your foe!\n"+NORM);
tell_object(attacker,HIR+"Two claws of great sharpness rake across "+
"your body!\n"+NORM);
   }
return 1;}
    return;
}

query_save_flag()  { return 1; }

init() {
  ::init();
  add_action("dwield","wield");
  add_action("awield","unwield");
  add_action("adrop","drop");
  if(environment(this_object())->is_player() && environment(this_object()) == this_player()) {
    command("wield dragon aura",environment(this_object()));
return 1;}
}

dwield(str) {
  if(str != "dragon aura") {
    write(HIR+"The Dragon's Aura will not let go....\n"+NORM);
  return 1;}
  write("You feel the powers of a dragon infuse you...\n\n"+RED+
  "You feel your shape change!  You are now a DRAGON!\n\n"+NORM);
  say(capitalize(tp)+" wields the dragon aura...\n"+
  "There is a rumbling like thunder and suddenly...\n\n"+RED+
  "\t"+capitalize(tp)+" is transformed into a DRAGON!\n\n"+NORM);
  emit_channel("junk","\t<<<<  A Dragon is born!  >>>>\n");
  pt=this_player()->query_pretitle();
  ti=this_player()->query_title();

  this_player()->set_title(BLU+"the Dragon"+NORM);
  this_player()->set_pretitle("");
  this_player()->set_al_title(RED+"DRAGON"+NORM);
 
}

adrop(str) {
int ra;
ra=random(100);
  if(str=="aura" || str=="dragon" || str=="dragon aura") {
  if(environment(this_object())->query_name() == this_player()->query_name()) {
  if(call_other(this_player(),"query_attrib","wil")<ra) {
    write(HIR+"The Dragon's Spirit does not want to let go....\n"+NORM);
  return 1;}
  write(RED+"You release the Aura of the Dragon...\n"+NORM);
  say(RED+capitalize(tp)+" releases the Dragon's Spirit...\n"+NORM);
  this_player()->set_title(ti);
  this_player()->set_pretitle(pt);
 
  if(this_player()->query_alignment() > 640)
{this_player()->set_al_title("white lord"); }
  if(this_player()->query_alignment()>320 )
{this_player()->set_al_title("paladin"); }
  if(this_player()->query_alinment()>160)
{this_player()->set_al_title("crusader"); }
  if(this_player()->query_alignment()>80) 
  {this_player()->set_al_title("good");}
  if(this_player()->query_alignment()>40)
{this_player()->set_al_title("honorable"); }
  if(this_player()->query_alignment()>-40)
{this_player()->set_al_title("neutral"); }
  if(this_player()->query_alignment()>-80)
{this_player()->set_al_title("malicious"); }
  if(this_player()->query_alignment()>-160)
{this_player()->set_al_title("evil"); }
  if(this_player()->query_alignment()>-320)
{this_player()->set_al_title("infamous"); }
  if(this_player()->query_alignment()>-640) {
  this_player()->set_al_title("black knight"); }
  if(this_player()->query_alignment()<-639) {
  this_player()->set_al_title("lord of evil"); }
}
}
}
awield(str) {
  if(str=="aura" || str=="dragon" || str=="dragon aura") {
    write(HIR+"The Dragon's Spirit does not want to let go....\n"+NORM);
  return 1;}
  }
