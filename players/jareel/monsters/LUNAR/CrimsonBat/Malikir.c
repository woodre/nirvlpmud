inherit "/obj/monster";
#include "/players/jareel/define.h"


#define BOOMA HIK+"                             ____"
#define BOOMB "                     __,-..|.    `---."
#define BOOMC "                   _ |_,---(      ,    )"
#define BOOM1 "                  -        <    (   )  \_"
#define BOOM2 HIR+"- ------"+HIY+" ==,,,'====------    --------===,,,== "+HIR+"----- -  "+NORM
#define BOOM3 HIK+"                  \|  -'-'-'-'-'-\-'-)-'("
#define BOOM4 "                  (_ (   \  (     >    \)"
#define BOOM5 "                   \_( _ <         >_>'"
#define BOOM6 NORM+RED+"                      - `-i' ::>|--'"
#define BOOM7 "                          I;|.|.|"
#define BOOM8 "                         <|i::|i|`."
#define BOOM9 "                        (` ^''`-' ')"
#define BOOM10 NORM+HIK+"------------------------------------------------------------------"+NORM

  object sword;

  int a;
  int L;
  int heal, x;
  object *stuff;
  
  reset(arg) {
    ::reset(arg);
      if (arg) return;

	  
	  
     set_name("malikir");
     set_race("human");
     set_gender("male");
	 set_wander(1);
     set_wander_interval(300);
	 set_wander_realm("/players/jareel/areas/chaos/woods4");

     set_al(-1000);
     set_level(25);
     set_hp(1300);
     set_ac(65);
     set_wc(55);
	 set_res(30);
	 
 	      set_armor_params("other|good",0,-50,0); /* 1/2 again Damage from Good */
	      set_armor_params("other|evil",0,50,0); /* 1/2 Damage from Evil */
          set_armor_params("magical",0,50,0); /* 1/2 Damage from Magic */
          set_armor_params("other|sonic",0,50,0); /* 1/2 again Damage from Sonic */
          set_armor_params("other|fire",0,-50,0); /* 1/2 Damage from fire */
          set_armor_params("other|ice",0,50,0); /* 1/2 again Damage from ice */

		  set_ac_bonus(15);
 	 set_hp_bonus(1500);

	 heal = 3;  /****** SPECIAL HEAL DAMAGE SPELL ******/

	/******** OBJECTS MOB HAS SOULBOUND OBJECT IS SECOND OBJECT **********/ 
     MOCO("/players/jareel/general_stuff/londros_bag.c"),this_object());
     sword=clone_object("/players/jareel/weapons/redgoddess/crimsonbat/IronGreatSword.c");
        move_object(sword, this_object());


     set_dead_ob(this_object());

     set_short(
       "Malikir - Keeper of the "+RED+"Crimson Bat"+NORM+" [ "+RED+"Seven Mothers "+NORM+"] (lord of evil)");
     set_long(
       "Malikir has a chaotic twinkle in his eyes.  Having years of\n"+
       "battles under his belt, his flowing red hair is starting to\n"+
       "gray.  He stands in a crimson aura from which he seems to draw\n"+
       "energy. His cold stare chills you to the bone as he catches\n"+
       "you looking at him.\n");

     set_heal(10,1);
		 

		 
add_spell(
  "allied spirit","\n\
	Malikir summons a spirit from his "+BOLD+MAG+"Scarlet Scimitar.\n\
    "+NORM+BOLD+"\n\
    "+NORM+"             An enraged Spirit slashes at #TN#.\n\
    "+NORM+"                 his "+BOLD+MAG+"Scarlet Scimitar"+NORM+"\n\n",
	     "Malikir summons a spirit from his "+BOLD+MAG+"Scarlet Scimitar.\n\
         "+NORM+BOLD+"\n\
                 An enraged Spirit slashes at #TN#.\n\
         "+NORM+"\n\n",
    30,"1d50+150","other|Jareel", 6);	
	
add_spell(
  "scarlet scimitar","\n\
	Malikir releases . . . . .\n\
    "+NORM+"       a wave of power from\n\
    "+NORM+"              his "+BOLD+MAG+"Scarlet Scimitar"+NORM+"\n\n",
	"Malikir releases . . . . .\n\
    "+NORM+"       a wave of power from\n\
    "+NORM+"              his "+BOLD+MAG+"Scarlet Scimitar"+NORM+"\n\n",
    30,"10-20+30","other|evil", 1);	
	
add_spell(
  "bladesharp scimitar","\n\
	Malikir casts a bladesharp spell over his blade.\n\n\
    "+NORM+"           "+BLINK+CYN+" E N E R G Y "+NORM+" flows over the blade.\n\
    "+NORM+"\n",
	"Malikir casts a bladesharp spell over his blade.\n\n\
    "+NORM+"           "+BLINK+CYN+" E N E R G Y "+NORM+" flows over the blade.\n\
    "+NORM+"\n",
    30,"10-20+30","other|evil", 1);		

		 
}

     heart_beat(){
       object       ob;
         ::heart_beat();
         corpse_loop();
		 if(!environment()) return ;
        
        if(heal && (this_object()->query_hp() < 400))
        {
                this_object()->heal_self(500);
                stuff = all_inventory(environment(this_object()));
                tell_object(stuff[x], "\n"+BOOMA+"\n"+BOOMB+"\n"+BOOMC+"\n"+BOOM1+"\n"+BOOM2+"\n"+BOOM3+"\n"+BOOM4+"\n"+BOOM5+"\n"+BOOM6+"\n"+BOOM7+"\n"+BOOM8+"\n"+BOOM9+"\n"+BOOM10+"\n"+NORM);
                if(stuff[x]->is_player())
                {
                        stuff[x]->hit_player(150,"energy");
                        tell_object(stuff[x]," "+HIY+"\nMalikir explodes energy from his body!\n\n"+NORM);
                }
                heal--;
        }
}
		 
     corpse_loop()    {
       object ob;
         if((ob = present("corpse", environment())) && (int)ob->is_corpse()) {
           tell_room(environment(),
             "Malikir takes: "+(string)ob->short()+".\n");
			 heal = 10;
             move_object(ob, this_object());
     corpse_loop();
  }
}

 monster_died() {
  if( attacker_ob && sword ) {
    sword->set_binder( attacker_ob->query_real_name() );
    tell_room( environment(), "\n"+HIW+"A flash of light flashes from "+HIR+BLINK+"Malikir's S W O R D"+NORM+HIW+" as it is soulbound to "+
      attacker_ob->query_name()+".\n\n"+NORM );
  }}

     init() { 
       ::init(); 
         add_action("heals","buy");
#ifndef __LDMUD__
   add_action("attackme");add_xverb("");
#else
   add_action("attackme","", 3);
#endif
}

catch_tell(str){
    string name,dir;
    if(this_player() && this_player()->is_player())
        if(sscanf(str,"%s leaves %s.",name,dir) == 2){
            if(attacker_ob){
                if(name = attacker_ob->query_name()){
                    if(random(4)==1){
                        tell_object(attacker_ob,"Malikir anticipates your move.\n");
                        command(dir);
                    } } } } }



attackme(){
    if(!attacker_ob && random(20) == 1){
        if(this_player()->is_player()){
            tell_object(this_player(),"Malikir notices you and attacks.\n");
            attacker_ob = this_player();
        }
    }
    return 0;
}


     heals(arg) {
       if(!arg) { return 0; }
       if(arg == "heal" || arg == "heals") {
       if(!this_player()->add_weight(1)) {
         write("Malikir says: Lighten your load.\n");
           return 1; }
       if(this_player()->query_money() < a) {
         write("Malikir says: You lack the money for the heal\n");
           return 1; }
       TP->add_money(-a);
         write("Malikir takes your coins mutters a few words, the coins turn into a heal.\n");
         say(TPN+" buys a heal from Malikir.\n");
         MOCO("/players/jareel/heals/aura.c"),TP);
           return 1; }
}
query_limited_shadow() { return 1; }