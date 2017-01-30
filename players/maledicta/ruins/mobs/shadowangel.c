#include "/players/maledicta/ansi.h"
inherit "obj/monster.c";
object attacked;
#define attacked (this_object()->query_attack())


reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("archangel");
set_alt_name("shadows");
set_alias("archangel of shadows");
set_race("unknown");
set_short(""+BOLD+""+BLK+"Archangel of Shadows"+NORM+"");
set_long(
  "  Standing before you at over 7 feet tall, this towering figure is wrapped\n"+
  "in a long flowing cloak. His gangly arms and legs covered in some moth eaten\n"+
  "black cloth. His skin is pasty white with sores covering it in numerous\n"+
  "places. The face looks like something that has been dead for weeks, bloated,\n"+
  "chalky white and drooping in the cheeks and under the eyes. But the eyes catch\n"+
  "your attention, and you understand why this thing is the Lord of the Shadows.\n"+
  "Within their depths you see a darkness so complete you fear you might fall\n"+
  "into them and lose the light of the world forever. A huge shield is strapped\n"+
  "to his right arm, and a long slender whip is held in the left.\n"); 
set_level(20);
set_hp(600);
set_al(-random(1000));
set_wc(23);
set_ac(14);
set_aggressive(1);
set_heal(6,3);
set_dead_ob(this_object());
set_chat_chance(5);
  load_chat("The Lord of Shadows stands staring at you his lips turned up in an\n"+
            "evil grin.\n");
  load_chat("A shadow near you flickers slightly.\n");
set_a_chat_chance(15);
  load_a_chat("The "+BOLD+""+BLK+"Lord of Shadows"+NORM+" deflects your attack!\n");
set_chance(20);
set_spell_dam(30);
set_spell_mess1(
""+BOLD+""+BLK+"Archangel of Shadows"+NORM+" flicks his whip at his foe, drawing deep\n"+
"lines of blood!\n");
set_spell_mess2(
"You feel a burst of pain as the "+BOLD+""+BLK+"Lord of Shadows"+NORM+" snaps his whip\n"+
"drawing "+HIR+"blood"+NORM+"!\n");
}

init(){
  ::init();
  
  add_action("no_move", "west");  
}    		
     	
no_move(){
  if(!(this_player()->query_ghost())){	
  write(HIR+"");	
  write("As you try and leave the Archangel of Shadows lashes out with his whip\n"+
        "entangling you! You cannot escape!"+NORM+"\n");	
  return 1;
  }
return;
}
monster_died() {
  object corpse;
  corpse = present("corpse", environment()); 
  tell_object(attacked,
"The Lord of Shadows gives a last silent cry as he falls to the ground in\n"+
"defeat. His body dissolves like a whisp of shadow in the light.\n");	
  move_object(clone_object("/players/maledicta/ruins/obj/scloak.c"),
      environment(this_object()));
  move_object(clone_object("/players/maledicta/ruins/obj/sshield.c"),
      environment(this_object()));
  move_object(clone_object("/players/maledicta/ruins/weapons/swhip.c"),
      environment(this_object()));        
 if(corpse)
    destruct(corpse);
return 1; }
