
#include "/players/khrell/define.h"
#include "/players/khrell/ansi.h"
inherit "obj/monster";
int X;
int Y;
int Z;
int G;
string SIZE;
string WHAT;
string NAME;
string RACE;
object gold;
object ob;
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  Y = (random(5));
  Z = (random(10));
  X = (Y+16);

  if(X == 16) SIZE = " small";
  if(X == 17) SIZE = " medium";
  if(X == 18) SIZE = " large";
  if(X == 19) SIZE = " very large";
  if(X == 20) SIZE = " huge";

  if(Z == 0) WHAT = "ungor";
  if(Z == 1) WHAT = "gor";
  if(Z == 2) WHAT = "beastigor";
  if(Z == 3) WHAT = "fury";
  if(Z == 4) WHAT = "centigor";
  if(Z == 5) WHAT = "ogre";
  if(Z == 6) WHAT = "troll";
  if(Z == 7) WHAT = "harpy";
  if(Z == 8) WHAT = "tuskgor";
  if(Z == 9) WHAT = "chaoshound";

  if(Z == 0) RACE = "beastman";
  if(Z == 1) RACE = "beastman";
  if(Z == 2) RACE = "beastman";
  if(Z == 3) RACE = "daemon";
  if(Z == 4) RACE = "beastman";
  if(Z == 5) RACE = "ogre";
  if(Z == 6) RACE = "troll";
  if(Z == 7) RACE = "beastman";
  if(Z == 8) RACE = "beastman";
  if(Z == 9) RACE = "hound";

  if(Z == 0){ ungor(); }
  if(Z == 1){ gor(); }
  if(Z == 2){ beastigor(); }
  if(Z == 3){ fury(); }
  if(Z == 4){ centigor(); }
  if(Z == 5){ ogre(); }
  if(Z == 6){ troll(); }
  if(Z == 7){ harpy(); }
  if(Z == 8){ tuskgor(); }
  if(Z == 9){ chaoshound(); }

  if(Y == 0) G = (random(600)+490);
  if(Y == 1) G = (random(600)+550);
  if(Y == 2) G = (random(600)+600);
  if(Y == 3) G = (random(1500)+1000);
  if(Y == 4) G = (random(2000)+3000);

  set_name(WHAT);
  set_short(HIK+"A"+SIZE+" "+WHAT+""+NORM);
  set_alias("RACE");
  set_race("RACE");
  set_hp(400+(Y*25));
  set_level(X);
  set_al(-1200);
  set_wc(X-3);
  set_ac(22+(Y*2));
  set_aggressive(0);


  gold=clone_object("obj/money");
  gold->set_money(G);
  move_object(gold,this_object());

}

  id(str) {
  return (str == WHAT || str == RACE || str == "smon"); 
}

ungor(){
    set_long("     The ungor are the lowest in beastmen society.  They are\n"+
             "slime creatures with lower haf of a cloven hoofed animal but\n"+
             "the upper body is vaguely humanoid, with a horned head.\n");
  set_chat_chance(2);
  set_a_chat_chance(15);
  load_chat("The ungor glares at you with hatred.\n");
  load_chat("A high pitched braying sound comes from the ungor.\n");
  load_a_chat("The ungor rakes you with dirty claws.\n");
}
gor(){
    set_long("     The gor are the standard creature of beastman society.\n"+
             "Usually powerfully built with a great horned head and with \n"+
             "legs of a goat or some other animal. They do pride themselves\n"+
             "on the size and shape of their great horns.\n");
  set_chat_chance(2);
  set_a_chat_chance(15);
  load_chat("The gor scratches the ground and snorts.\n");
  load_chat("A loud braying sound echoes from all around.\n");
  load_a_chat("The beastman beatbutts you with his horned head.\n");
}
beastigor(){
    set_long("     The beastigor are often the favored gors of the tribal chief\n"+
             "and as such generally are the envy of the lesser ranks of their \n"+
             "own kind.  Though no ungor could ever gain this status, the gor are\n"+
             "the sole race chosen for this honor.\n");
  set_chat_chance(2);
  set_a_chat_chance(15);
  load_chat("The beastigor struts proudly about.\n");
  load_chat("The beastigor polishes his impressive horns.\n");
  load_a_chat("The beastigor punches you in the gut.\n");
}
fury(){
    set_long("     The Furies are lesser daemons of chaos undivided.  They hold\n"+
             "no loyalities to any power but serve their own interests.  Great\n"+
             "fanged maws, and massive leathery wings give this creature an aura\n"+
             "of menace as it's form seems to waver and fade before returning.\n");
  set_chat_chance(2);
  set_a_chat_chance(15);
  load_chat("The fury cackles at your insignificance.\n");
  load_chat("The fury licks its fangs.\n");
  load_a_chat("The fury rakes you with ichor stained talons.\n");
}
centigor(){
    set_long("     The centigor are another example of the warping nature of chaos.\n"+
             "It had the upper body of a gor, but the lower body is of some great\n"+
             "four legged beast.  Also well known for it's love of strong drink and\n"+
             "an equally bad temper this creature is dangerous.\n");
  set_chat_chance(2);
  set_a_chat_chance(15);
  load_chat("A deep growl echoes through the still air.\n");
  load_chat("The centigor burps then drinks from a wineskin.\n");
  load_a_chat("The centigor attacks in a drunken fury.\n");
}
ogre(){
    set_long("     The Ogres in the service of chaos started out at one time\n"+
             "as mercenaries but now are warped and twisted parodies of their\n"+
             "former selves.\n");
  set_chat_chance(2);
  set_a_chat_chance(15);
  load_chat("Something unidentifiable drop from the mouth of the ogre.\n");
  load_chat("The ogre growls dangerously.\n");
  load_a_chat("A terrible unwashed stench assails your senses.\n");
}
troll(){
    set_long("     Trolls in the armies of chaos are generally ones that have fallen\n"+
             "under chaos' dire influence.  The seem to be more intellgent yet they\n"+
             "retain their beastial intellgence.\n");
  set_chat_chance(2);
  set_a_chat_chance(15);
  load_chat("The stomach of the troll gurgles.\n");
  load_chat("The troll open one of it's many mouths.\n");
  load_a_chat("A mutated limb painfully hits you.\n");
}
harpy(){
    set_long("     It is unknown where the harpies originate, but it is known they\n"+
             "are cruel and vicious creatures of spite.  They have the upper body\n"+
             "of a human female yet the arms are claws and they sport taloned legs\n"+
             "and feathered wings.\n");
  set_chat_chance(2);
  set_a_chat_chance(15);
  load_chat("A piercing wail echoes from the harpy.\n");
  load_chat("The harpy swoops about the air.\n");
  load_a_chat("The harpy slashes at you with cruel talons.\n");
}
tuskgor(){
    set_long("     The tuskgor are a odd war beast of the beastman armies.  It \n"+
             "seems to be a gigantic boar that sports the all too familiar horns\n"+
             "all too commong with the beastmen race.\n");
  set_chat_chance(2);
  set_a_chat_chance(15);
  load_chat("The tuskgor grunts.\n");
  load_chat("The snorts and paws at the ground.\n");
  load_a_chat("Pain shoots through you as the tuskgor rams into you.\n");
}
chaoshound(){
    set_long("     This shaggy beast can barely be called a hound by some sort of\n"+
             "great understatement. Its form is warped and twisted by its exposure\n"+
             "to chaos thus no two are ever alike.  Massive mutations visited upon \n"+
             "this creature have driven it beyond the brink of sanity.\n");
  set_chat_chance(2);
  set_a_chat_chance(15);
  load_chat("The hound growls low in its throat.\n");
  load_chat("Madness flickers within the eyes of the hound.\n");
  load_a_chat("The hound snaps his slavering fangs at your throat.\n");
}

heart_beat() {
  ::heart_beat();
  if (query_attack() &&  random(2) == 1) {
    if(Z == 0){ a_ghoul(); }
    if(Z == 1){ a_wraith(); }
    if(Z == 2){ a_skeleton(); }
    if(Z == 3){ a_daemon(); }
    if(Z == 4){ a_revenant(); }
    if(Z == 5){ a_zombie(); }
    if(Z == 6){ a_shade(); }
    if(Z == 7){ a_ghost(); }
    if(Z == 8){ a_phantom(); }
    if(Z == 9){ a_hellhound(); }
  }
}

a_ungor() {
tell_room(environment(this_object()),
HIG+"test"+NORM+"\n");
return 1;
}

a_gor() {
tell_room(environment(this_object()),
HIG+"test"+NORM+"\n");
return 1;

}

a_beastigor() {
tell_room(environment(this_object()),
HIG+"test"+NORM+"\n");
return 1;

}

a_fury() {
tell_room(environment(this_object()),
HIG+"test"+NORM+"\n");
return 1;

}

a_centigor() {
tell_room(environment(this_object()),
HIG+"test"+NORM+"\n");
return 1;

}

a_ogre() {
tell_room(environment(this_object()),
HIG+"test"+NORM+"\n");
return 1;

}

a_troll() {
tell_room(environment(this_object()),
HIG+"test"+NORM+"\n");
return 1;

}

a_harpy() {
tell_room(environment(this_object()),
HIG+"test"+NORM+"\n");
return 1;

}

a_tuskgor() {
tell_room(environment(this_object()),
HIG+"test"+NORM+"\n");
return 1;

}

a_chaoshound() {
tell_room(environment(this_object()),
HIG+"test"+NORM+"\n");
return 1;

}
