inherit "/obj/monster";
#include "/players/jareel/define.h"

     object armor;
     int a;
     int L;
	 int heal, x;
	 object *stuff;
     int scimitar;
       reset(arg) {
     a = 3300;
       ::reset(arg);
         if (arg) return;
     set_name("grailion");
     set_race("human");
     set_al(-1000);
     set_level(2);
     set_aggressive(0);
     set_hp(130);
	 heal = 1;
     MOCO("/players/jareel/general_stuff/londros_bag.c"),this_object());
armor=clone_object("/players/jareel/SoulboundObjects/ARMOR/SetOfShadows/GuardOfDarkness.c");
        move_object(armor, this_object());
     MOCO("/players/jareel/weapons/chaos/scarlet_scimitar.c"),this_object());
       scimitar = present("scimitar",this_object());
       scimitar->set_short(BOLD+MAG+"Scarlet Scimitar "+HIK+"[ "+BOLD+MAG+"Glowing "+HIK+"] "+NORM+RED+"[ "+CYN+" Energized"+RED+" ]"+NORM);
         init_command("wield scimitar");
     set_ac(1);
     set_wc(7);
	 set_hp_bonus(1);
     set_gender("male");
     set_dead_ob(this_object());
     set_short(
       "Grailion - Keeper of the "+RED+"Crimson Bat"+NORM+" [ "+RED+"Seven Mothers "+NORM+"] (lord of evil)");
     set_long(
       "Grailion has a chaotic twinkle in his eyes.  Having years of\n"+
       "battles under his belt, his flowing red hair is starting to\n"+
       "gray.  He stands in a crimson aura from which he seems to draw\n"+
       "energy. His cold stare chills you to the bone as he catches\n"+
       "you looking at him.\n");

     set_heal(0,0);
		 

		 
add_spell(
  "allied spirit","\n\
	Braklan summons a spirit from his "+BOLD+MAG+"Scarlet Scimitar.\n\
    "+NORM+BOLD+"\n\
    "+NORM+"             An enraged Spirit slashes at #TN#.\n\
    "+NORM+"                 his "+BOLD+MAG+"Scarlet Scimitar"+NORM+"\n\n",
	     "Braklan summons a spirit from his "+BOLD+MAG+"Scarlet Scimitar."+NORM+"\n\
         "+NORM+BOLD+"\n\
                 An enraged Spirit slashes at #TN#.\n\
         "+NORM+"\n\n",
    3,"1d5+1","other|Jareel", 1);	
	
add_spell(
  "scarlet scimitar","\n\
	Grailian releases . . . . .\n\
    "+NORM+"       a wave of power from\n\
    "+NORM+"             from his "+BOLD+MAG+"Scarlet Scimitar"+NORM+"\n\n",
	"Grailian releases . . . . .\n\
    "+NORM+"       a wave of power from\n\
                  his "+BOLD+MAG+"Scarlet Scimitar"+NORM+"\n\n",
    3,"1-2+3","other|evil", 1);	
	
add_spell(
  "bladesharp scimitar","\n\
	Braklan casts a bladesharp spell over his blade.\n\n\
    "+NORM+"           "+BLINK+CYN+" E N E R G Y "+NORM+" flows over the blade.\n\
    "+NORM+"\n",
	"Braklan casts a bladesharp spell over his blade.\n\n\
    "+NORM+"           "+BLINK+CYN+" E N E R G Y "+NORM+" flows over the blade.\n\
    "+NORM+"\n",
    3,"1-2+3","other|evil", 1);		

		 
}

     heart_beat(){
       object       ob;
         ::heart_beat();
         corpse_loop();
		 if(!environment()) return ;
        
        if(heal && (this_object()->query_hp() < 400))
        {
                this_object()->heal_self(5);
                stuff = all_inventory(environment(this_object()));
                tell_object(stuff[x], "An Aura heals Grailion!\n");
                if(stuff[x]->is_player())
                {
                        stuff[x]->hit_player(1,"other|energy");
                        tell_object(stuff[x]," "+GRN+"Grailion "+NORM+"screams as he sends out an "+HIY+"Energy Burst"+NORM+"!\n");
                }
                heal--;
        }
}
		 
         

 
/* by verte */
     corpse_loop()    {
       object ob;
         if((ob = present("corpse", environment())) && (int)ob->is_corpse()) {
           tell_room(environment(),
             "Grailion takes: "+(string)ob->short()+".\n");
             move_object(ob, this_object());
     corpse_loop();
  }
}

 monster_died() {
  if( attacker_ob && armor ) {
    armor->set_binder( attacker_ob->query_real_name() );
    tell_room( environment(), "\n"+HIW+"A flash of light flashes from "+HIR+BLINK+"Grailion's A R M O R"+NORM+HIW+" as it is soulbound to "+
      attacker_ob->query_name()+".\n\n"+NORM );
  }}

     init() { 
       ::init(); 
         add_action("heals","buy");

}

catch_tell(str){
    string name,dir;
    if(this_player() && this_player()->is_player())
        if(sscanf(str,"%s leaves %s.",name,dir) == 2){
            if(attacker_ob){
                if(name = attacker_ob->query_name()){
                    if(random(4)==1){
                        tell_object(attacker_ob,"Grailion anticipates your move.\n");
                        command(dir);
                    } } } } }






     heals(arg) {
       if(!arg) { return 0; }
       if(arg == "heal" || arg == "heals") {
       if(!this_player()->add_weight(1)) {
         write("Grailion says: Lighten your load.\n");
           return 1; }
       if(this_player()->query_money() < a) {
         write("Grailion says: You lack the money for the heal\n");
           return 1; }
       TP->add_money(-a);
         write("Grailion takes your coins mutters a few words, the coins turn into a heal.\n");
         say(TPN+" buys a heal from Grailion.\n");
         MOCO("/players/jareel/heals/aura.c"),TP);
           return 1; }
}