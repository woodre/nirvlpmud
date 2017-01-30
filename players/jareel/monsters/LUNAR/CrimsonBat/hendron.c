inherit "/players/dragnar/closed/mob";
#include "/players/jareel/define.h"

     object bracelet;
     int a;
     int L;
	 int heal, x;
	 object *stuff;
     int scimitar;
       reset(arg) {
     a = 3300;
       ::reset(arg);
         if (arg) return;
     set_name("hendron");
     set_race("human");
     set_al(-1000);
     set_level(25);
     set_aggressive(0);
     set_hp(1300);
	 heal = 3;
     MOCO("/players/jareel/general_stuff/londros_bag.c"),this_object());
bracelet=clone_object("/players/jareel/SoulboundObjects/ARMOR/SetOfShadows/BracersOfDarkness.c");
        move_object(bracelet, this_object());
     MOCO("/players/jareel/weapons/chaos/scarlet_scimitar.c"),this_object());
       scimitar = present("scimitar",this_object());
       scimitar->set_short(BOLD+MAG+"Scarlet Scimitar "+HIK+"[ "+BOLD+MAG+"Glowing "+HIK+"] "+NORM+RED+"[ "+CYN+" Energized"+RED+" ]"+NORM);
         init_command("wield scimitar");
     set_ac(10);
     set_wc(75);
	 set_hp_bonus(1500);
     set_gender("male");
     set_dead_ob(this_object());
     set_short(
       "Hendron - Keeper of the "+RED+"Crimson Bat"+NORM+" [ "+RED+"Seven Mothers "+NORM+"] (lord of evil)");
     set_long(
       "Hendron has a chaotic twinkle in his eyes.  Having years of\n"+
       "battles under his belt, his flowing red hair is starting to\n"+
       "gray.  He stands in a crimson aura from which he seems to draw\n"+
       "energy. His cold stare chills you to the bone as he catches\n"+
       "you looking at him.\n");

     set_heal(7,1);
		 

		 
add_spell(
  "allied spirit","\n\
	Braklan summons a spirit from his "+BOLD+MAG+"Scarlet Scimitar.\n\
    "+NORM+BOLD+"\n\
    "+NORM+"             An enraged Spirit slashes at #TN#.\n\
    "+NORM+"                from his "+BOLD+MAG+"Scarlet Scimitar"+NORM+"\n\n",
	     "Braklan summons a spirit from his "+BOLD+MAG+"Scarlet Scimitar."+NORM+"\n\
         "+NORM+BOLD+"\n\
                 An enraged Spirit slashes at #TN#.\n\
         "+NORM+"\n\n",
    30,"1d50+100","other|Jareel", 1);	
	
add_spell(
  "scarlet scimitar","\n\
	Braklan releases . . . . .\n\
    "+NORM+"       a wave of power from\n\
    "+NORM+"              his "+BOLD+MAG+"Scarlet Scimitar"+NORM+"\n\n",
	"Braklan releases . . . . .\n\
    "+NORM+"       a wave of power from\n\
                  his "+BOLD+MAG+"Scarlet Scimitar"+NORM+"\n\n",
    30,"10-20+30","other|evil", 1);	
	
add_spell(
  "bladesharp scimitar","\n\
	Braklan casts a bladesharp spell over his blade.\n\n\
    "+NORM+"           "+BLINK+CYN+" E N E R G Y "+NORM+" flows over the blade.\n\
    "+NORM+"\n",
	"Braklan casts a bladesharp spell over his blade.\n\n\
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
                tell_object(stuff[x], "An aura heals Hendron!\n");
                if(stuff[x]->is_player())
                {
                        stuff[x]->hit_player(125,"other|energy");
                        tell_object(stuff[x]," "+GRN+"Hendron "+NORM+"screams as he sends out an "+HIY+"Energy Burst"+NORM+"!\n");
                }
                heal--;
        }
}
		 
         

 
/* by verte */
     corpse_loop()    {
       object ob;
         if((ob = present("corpse", environment())) && (int)ob->is_corpse()) {
           tell_room(environment(),
             "Hendron takes: "+(string)ob->short()+".\n");
             move_object(ob, this_object());
     corpse_loop();
  }
}

 monster_died() {
  if( attacker_ob && bracelet ) {
    bracelet->set_binder( attacker_ob->query_real_name() );
    tell_room( environment(), "\n"+HIW+"A flash of light flashes from "+HIR+BLINK+"Hendron's B R A C E R"+NORM+HIW+" as it is soulbound to "+
      attacker_ob->query_name()+".\n\n"+NORM );
}
  ::monster_died();
}
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
                        tell_object(attacker_ob,"Hendron anticipates your move.\n");
                        command(dir);
                    } } } } }



attackme(){
    if(!attacker_ob && random(2) == 1){
        if(this_player()->is_player()){
            tell_object(this_player(),"Hendron notices you and attacks.\n");
            attacker_ob = this_player();
        }
    }
    return 0;
}


     heals(arg) {
       if(!arg) { return 0; }
       if(arg == "heal" || arg == "heals") {
       if(!this_player()->add_weight(1)) {
         write("Hendron says: Lighten your load.\n");
           return 1; }
       if(this_player()->query_money() < a) {
         write("Hendron says: You lack the money for the heal\n");
           return 1; }
       TP->add_money(-a);
         write("Hendron takes your coins mutters a few words, the coins turn into a heal.\n");
         say(TPN+" buys a heal from Hendron.\n");
         MOCO("/players/jareel/heals/aura.c"),TP);
           return 1; }
}
