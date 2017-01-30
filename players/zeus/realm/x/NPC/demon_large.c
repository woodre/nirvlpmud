/* Intended for use in Zeus' fallen lands forest 'arena'
*  will hunt players at random
*/
inherit "/obj/monster";
#include "/players/zeus/closed/all.h"
#include "/players/zeus/realm/x/defs.h"
#include "/players/zeus/realm/x/demon_check.h"
#define LEAVE "The demon thunders away, crashing through the trees.\n"
#define ARRIVE "A huge demon suddenly emerges from the shadows.\n"
#define QXL query_extra_level()
object *arena, *nmys, nmy;
string w;

reset(arg) {
   ::reset(arg);
   if (!arg) {

	   arena = allocate(9);
	   arena =({
		   "players/zeus/realm/x/r/1",
		   "players/zeus/realm/x/r/2",
		   "players/zeus/realm/x/r/3",
		   "players/zeus/realm/x/r/4",
		   "players/zeus/realm/x/r/5",
		   "players/zeus/realm/x/r/6",
		   "players/zeus/realm/x/r/7",
		   "players/zeus/realm/x/r/8",
		   "players/zeus/realm/x/r/9", });

  set_name("a huge cursed demon");
  set_short("A huge cursed demon");
  set_race("demon");
  set_gender("creature");
  set_long(
"This is a large red demon.  Its massive body is bulging with muscles.\n"+
"It is hunched way over, its powerful arms dragging on the ground.  Large\n"+
"claws protrude from its hands and feet.  A constant grin adorns its face,\n"+
"which is highlighted by two glowing red eyes.  This is a creature of pure\n"+
"evil, its only purpose to cause pain and agony to all who encounter it.\n");
  set_wc(30);
  set_wc_bonus(24);
  set_ac(7);
  set_heal(1,4);
  set_level(22);
  set_hp(470+random(180));
  set_aggressive(1);
  set_al(-1000);
  set_dead_ob(TO);
  call_out("fake_hb", 1);
   }
}

id(str){ return str == "demon" || str == "daemon" || str == "cursed demon" ||
str == "a huge curesd demon"; }

/*  Allow npcs to hunt players */
#include "/players/zeus/realm/x/hunt.h"

monster_died(){
	write(
	"As the huge demon slumps to the ground, you plunge your weapon\n"+
		"into the demons chest and cut out its heart.\n");
	MO(CO("/players/zeus/heals/demon_heart.c"), AO);  
  DD->add_kills(attacker_ob, 1);
  write_file("/players/zeus/log/X", ctime(time())+"   "+
	  capitalize((string)TP->QRN)+" killed a large demon.\n");
}

atk(){
  TR(environment(TO),
    "The cursed demon slashes "+AO->QN+" with its huge claws...\n"+
    AO->QN+" staggers backwards and blood gushes forth...\n", ({AO}));
  tell_object(AO,
    "The cursed demon slashes you with its huge claws...\n"+
    "You stagger backwards and blood gushes forth...\n");
  AO->hit_player((int)AO->query_level()+
    random((int)AO->query_extra_level())+random(10));
}

death(){
  TR(environment(),
    "The demon thunders off, crashing through the forest.\n");
  destruct(TO);
}

fake_hb(){
  if(!environment()) return;
  call_out("fake_hb", 1);
  if(AO && !present(AO, ENV))
    AO = 0;
  if(AO) nmy = AO;
  if(AO && present(AO, ENV))
    AO->hit_player((int)AO->query_level()+random((int)AO->QXL)-random(5));
  if(AO && !random(DEMON))
    demon_check();
  if(AO && !random(10))
    atk();
  if(!AO && !random(HCHANCE))
    hunt();
  if(!AO && nmy && present(nmy, ENV))
  {
    if(!present(nmy, ENV)->query_ghost())
    {
      TR(environment(), "The cursed demon roars in anger!\n");
      TO->attack_object(nmy);
    }
  }
  if(!AO && !random(DCHANCE))
    death();
}

