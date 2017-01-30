

#include "/players/anshar/closed/ansi.h"
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
  if(Z == 5) WHAT = "spawn";
  if(Z == 6) WHAT = "tuskgor";
  if(Z == 7) WHAT = "harpy";
  if(Z == 8) WHAT = "mutant";
  if(Z == 9) WHAT = "chaoshound";

  if(Z == 0) RACE = "beastman";
  if(Z == 1) RACE = "beastman";
  if(Z == 2) RACE = "beastman";
  if(Z == 3) RACE = "daemon";
  if(Z == 4) RACE = "beastman";
  if(Z == 5) RACE = "beastman";
  if(Z == 6) RACE = "beastman";
  if(Z == 7) RACE = "beastman";
  if(Z == 8) RACE = "beastman";
  if(Z == 9) RACE = "hound";

  if(Z == 0){ ungor(); }
  if(Z == 1){ gor(); }
  if(Z == 2){ beastigor(); }
  if(Z == 3){ fury(); }
  if(Z == 4){ centigor(); }
  if(Z == 5){ spawn(); }
  if(Z == 6){ tuskgor(); }
  if(Z == 7){ harpy(); }
  if(Z == 8){ mutant(); }
  if(Z == 9){ chaoshound(); }

  if(Y == 0) G = (random(600)+490);
  if(Y == 1) G = (random(600)+550);
  if(Y == 2) G = (random(600)+600);
  if(Y == 3) G = (random(1500)+1000);
  if(Y == 4) G = (random(2000)+3000);

  set_name(WHAT);
  set_short("A"+SIZE+" "+WHAT+"");
  set_alias("RACE");
  set_race("RACE");
  set_hp(400+(Y*25));
  set_level(X);
  set_al(-200);
  set_wc(X-3);
  set_ac(22+(Y*2));
  set_aggressive(0);

  set_dead_ob(TO);

  gold=clone_object("obj/money");
  gold->set_money(G);
  move_object(gold,this_object());

}


  id(str) {
  return (str == WHAT || str == RACE || str == "smon"); 
}

ungor(){
    set_long("     This is the lowest of the lows in the beastman society.\n"+
             "Some have small horns other just have bumpy ridges, they are \n"+
             "generally slight of build but can vary due to the warping .\n"+
             "influence of chaos, thus each ungor is unique looking each \n"+
             "having various mutations, minor and major, all beastial.\n");
  set_chat_chance(2);
  set_a_chat_chance(15);
  load_chat("The ungor sneers at youwith hate filled beady eyes.\n");
  load_chat("The ungor scratches at the dirt with it's cloven hoof.\n");
  load_a_chat("The ungor rams you with it's horns.\n");
}
gor(){
    set_long("     The gor is the common foor soldier of the beastmen, They\n"+
             "hate civilization and all society, as they are creatures born \n"+
             "chaos. They mainly use scavenged gear they get from their numberous\n"+
             "raids upon others. Large and powerfully built they pride themselves\n"+
             "on the size and shape of their horns, though they do not often look\n"+
             "like any sort of beast that would normally have horns.\n");
  set_chat_chance(2);
  set_a_chat_chance(15);
  load_chat("The gor brays loudly, forcing you to cover your ears.\n");
  load_chat("The beast snorts at you wiht total loathing.\n");
  load_a_chat("Abellow is heard off in the distance.\n");
}
beastigor(){
    set_long("     Beastigor are the elite of the beastmen forces. Not better\n"+
             "trained, just better equipped. Hand picked by the beastlord to\n"+
             "be his personal guard in battle. When not in battle they guard\n"+
             "the hordes horde and herd stone from harm.\n");
  set_chat_chance(2);
  set_a_chat_chance(15);
  load_chat("The beastman grunts noisly.\n");
  load_chat("The beastigor looks at you with contempt.\n");
  load_a_chat("A snarl of hatred escapes from it's tusked mouth.\n");
}
fury(){
    set_long("     With a slick hide of dark colors, it is almost black, this form\n"+
             "is an imposing sight. Sharp white fangs drip acidic ichor while a\n"+
             "large pair of wings hang lazily over it's shoulders. This undivided\n"+
             "daemon of chaos revels in the carnage and arnachy it creates.\n");
  set_chat_chance(2);
  set_a_chat_chance(15);
  load_chat("The daemon laughs at your insignificance.\n");
  load_chat("The daemon dares you to attack.\n");
  load_a_chat("The daemon slams you with its fists.\n");
}
centigor(){
    set_long("     This creature has the upper body of a gor and the lower part of\n"+
             "some great beastial quadraped. Well known for their love of strong drink\n"+
             "and a taste for carnage, they prowl the forests in search of caravans to \n"+
             "raid and plunder.\n");
  set_chat_chance(2);
  set_a_chat_chance(15);
  load_chat("A deep growl echoes through the still air.\n");
  load_chat("The centigor emite a horrid sounding belch.\n");
  load_a_chat("The centigor attacks in a drunken fury.\n");
}
spawn(){
    set_long("     The shambling mound of unidentifible mass was once some\n"+
             "servant of chaos, but it now in a near mindless creature forever\n"+
             "twisting and changing it's shape into something more foul.\n");
  set_chat_chance(2);
  set_a_chat_chance(15);
  load_chat("A burbeling hiss escape from one of it's mouths.\n");
  load_chat("The spawn squirms and gibbers.\n");
  load_a_chat("Tentacles, claws and other appendages assail you.\n");
}
tuskgor(){
    set_long("     A beast commonly used to pull massive charriots of the beastmen\n"+
             "it is part beastman gor and part boar, though it no longer resembles\n"+
             "neither. It inherits both the illtempers of it's 'parental' races.\n");
  set_chat_chance(2);
  set_a_chat_chance(15);
  load_chat("The tuskgor grunts loudly at you.\n");
  load_chat("A deep grunt emits from the horned snout of the creature.\n");
  load_a_chat("With a earpiercing squeal, the creature gores you.\n");
}
harpy(){
    set_long("     This winged and claws thing bears little sanity to anything sane.\n"+
             "It posessed the naked upperbody of a female, it lacks any beauty and\n"+
             "only posessess nothing in the way of intellgence. It is a warped predator\n"+
             "of the chaos wastes, but has been known to migrate south.\n");
  set_chat_chance(2);
  set_a_chat_chance(15);
  load_chat("A wail echoes from the harpy.\n");
  load_chat("The harpy shrieks and flaps it's wings.\n");
  load_a_chat("It's claws lash out at you in a frenzy.\n");
}
mutant(){
    set_long("     This is a lesser mutated form of the spawn. it still has a vague\n"+
             "humanoid form. Though it seems to lack any sort of uniform appearence.\n"+
             "Many appendages erupt seemingly in randomplaces all over it's body.\n");
  set_chat_chance(2);
  set_a_chat_chance(15);
  load_chat("The mutant cackles maddeningly.\n");
  load_chat("The mutant mutates around.\n");
  load_a_chat("Pain shoots through you as the mutant attacks.\n");
}
chaoshound(){
    set_long("     The shaggy beast can only be called a hound by some sort of\n"+
             "great understatement. Its large form dwarfs even the most massive\n"+
             "of simple dogs. The other main difference is teh gifts of chaos that\n"+
             "give it various mutations.\n");
  set_chat_chance(2);
  set_a_chat_chance(15);
  load_chat("The hound growls low in its throat.\n");
  load_chat("Deep malice flickers within the eyes of the hound.\n");
  load_a_chat("Raw chaos assails as the hound leaps.\n");
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

a_spawn() {
tell_room(environment(this_object()),
HIG+"test"+NORM+"\n");
return 1;

}

a_tuskgor() {
tell_room(environment(this_object()),
HIG+"test"+NORM+"\n");
return 1;

}

a_harpy() {
tell_room(environment(this_object()),
HIG+"test"+NORM+"\n");
return 1;

}

a_mutant() {
tell_room(environment(this_object()),
HIG+"test"+NORM+"\n");
return 1;

}

a_chaoshound() {
tell_room(environment(this_object()),
HIG+"test"+NORM+"\n");
return 1;

}
