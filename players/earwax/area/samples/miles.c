inherit "/obj/monster.c";
#include <ansi.h>
#define hoser this_object()->query_attack()
#define hosern capitalize(hoser->query_name())

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("miles");
  set_race("spirit");
  set_short(HIY+"Miles"+NORM+BOLD+", Chief of Security"+NORM);
  set_long(
    "  This was once the chief of security for the insane asylum.\n"+
    "He built a reputation for punishing anyone that crossed his path\n"+
    "or got out of line. With his extreme temper it is best not to try\n"+
    "anything funny.\n");
  move_object(clone_object("/players/fred/asylum/obj/dart.c"), this_object());
  move_object(clone_object("/players/fred/asylum/obj/fjacket.c"), this_object());
  move_object(clone_object("/players/fred/asylum/obj/bknuckles.c"), this_object());
  command("wield knuckles", this_object());
  command("wear jacket", this_object());
  set_level(21);
  set_al(-(random(500)));
  set_ac(17+random(8));
  set_hp(1200);
  set_hp_bonus(120);
  set_wc(40+random(5));
  set_wc_bonus(16);
  set_heal(3,1);
  set_gender("male");
  set_aggressive(0);
  set_dead_ob(this_object());
  set_chat_chance(5);
   load_chat("Miles barks: Why do you bother me?\n");
   load_chat("Miles yells: Get out of here before I get upset!\n");
  }

monster_died(){
  object corpse;
  corpse = present("corpse", environment());
  tell_object(hoser,
  "\nMiles yells: 'You may have won this time but I'll be back' and disappears into the darkness.\n\n");
 if(corpse)
    destruct(corpse);
  return 1; }

heart_beat(){
  int disturbed;
  disturbed = random(100);
  ::heart_beat();
   if(!environment()) return;
   if(!hoser) return;
     if(disturbed<20){
       pain();}
     else if(disturbed>92){
       heal();}
     else if(disturbed<75 && disturbed>35){
       spin();}
    }

pain(){
  int w, q, h;
  h = hoser->query_hp();
  w = hoser->query_attrib("luc");
  q = hoser->query_sp();
   if(q < (w*(10+random(5)))){
     tell_room(environment(hoser),
       "\nMiles' eyes turn a deep red as he screams in anguish...\n"+
       ""+hosern+" is "+BOLD+BLU+"pummeled"+NORM+" mercilessly with a series of brutal attacks.\n\n");
     hoser->add_hit_point(-(50+random(25))); }
   else if(h < (w*(10+random(4)))){
     tell_room(environment(hoser),
       "\nMiles' eyes glow a deep red as he screams in agony...\n"+
       "Miles "+RED+"E V I S C E R A T E S "+NORM+hosern+" with extreme prejudice.\n\n");
     hoser->add_hit_point(-(50+random(25))); }
   }

heal(){
  int y, a, rnd;
  y = hoser->query_hp();
  a = hoser->query_sp();
  if(y > a){
    rnd = y - a;
    if(rnd > 60) rnd = 60; 
     tell_room(environment(hoser),
     "\nThe room grows "+HIB+"cold"+NORM+" as Miles goes into a brief trance...\n\n");
     this_object()->heal_self(rnd); }
  else if(a > y){
    rnd = a - y;
    if(rnd > 60) rnd = 60;
     tell_room(environment(hoser),
     "\nA "+HIB+"cold"+NORM+" draft flushes into the room as Miles goes into a trance...\n\n");
     this_object()->heal_self(rnd); }
  }

spin(){
  int t, v;
  t = random(50);
  v = random(25);
   if(v > t){
    tell_room(environment(hoser),
    "\nMiles "+HIY+"spins"+NORM+" wildly around "+BOLD+hosern+NORM+" delivering several lethal blows.\n\n");
    hoser->add_hit_point(-(15+random(20))); 
    weapon_class += (random(3)+1); 
    if(weapon_class > 60) weapon_class = 60; }
  }

