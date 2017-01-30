/*  This weapon is made for worm.  He has chosen to spend all 15 of
    his found bugs into it, meaning it has gotten to be quite nice
    now.  
*/

#include "/players/maledicta/ansi.h"

inherit "players/maledicta/weapon/weapon.c";
#define USER environment()
#define TP this_player()
#define POS query_possessive()
#define OBJ query_objective()
#define PRO query_pronoun()

reset(arg){
  ::reset(arg);
  if (arg) return;
set_name("scythe");
set_alt_name("shardaks vengeance");
set_alias("vengeance");
set_short(RED+"Shardak's "+NORM+BOLD+"Vengeance"+NORM);
set_long(
"  This long scythe is the instrument of "+RED+"Shardak's"+NORM+" revenge. It\n"+
"was formed in the fires of Hell after His exile from the mortal\n"+
"realm.  This instrument of destruction is made specifically for\n"+
"the minion "+RED+"Worm"+NORM+".\n"+
"You can use the following commands:\n"+
" swing, grip, twirl, threaten <who>, and draw.\n");
set_hit_func(this_object());
set_type("polearm");  
set_class(20);
set_weight(4);
set_value(2000);
add_special_chance(30);
add_special_chance(15);
add_special_damage(3);
add_special_damage(7);
add_special_fun("/players/maledicta/weapon/powers/death.c");
add_special_message(
"You swing the Scythe in a low arc...\n\n"+
"       $H$- $R$S  L  A  S  H $N$H$-$N$\n\n"+
"              $AN$ cries out in agony!\n");
add_special_rmessage(
"$UN$ swings $UPO$ Scythe in a low arc...\n"+
"  $AN$ cries out in agony as the long blade $H$R$SLASHES $N$AOB$!\n");
set_no_break(1);
add_special_message(
"\n     $R$The Spirit of $H$Shardak$N$R$ enters the room...\n"+
"     You feel strength and power flow into your body...\n"+
"          $N$H$        _     _     _     _     _   $N$\n"+
"              $H$_$R$C $N$H$ _  $R$L  $N$H$_  $R$E  $N$H$_  $R$A  $N$H$_  $R$V  $N$H$_ $R$ E$N$H$_$N$   \n"+
"          $N$H$        _     _     _     _     _   $N$\n"+
"\n     $R$AN$ loses a part of their soul...$N$\n");
add_special_rmessage(
"  $H$A coldness enters the room and you shiver...$N$\n"+
"  $H$You lose something.$N$\n");
set_two_handed_wep(1);
}


weapon_hit(attacker){
if(environment()->query_real_name() != "worm") return;
   if(random(100) < 15){ 
     USER->add_alignment(-300);
     tell_object(USER, HIW+"\nThe God's evil courses through your veins!"+NORM+"\n\n");
     }
  if(attacker)
  if(attacker->query_alignment() > 400 && random(100) > 70){
     tell_object(USER,
     RED+"Shardak's Vengeance"+NORM+BOLD+" unleashes it's might again "+attacker->query_name()+"!"+NORM+"\n");
     return 2;
     }
  if(random(100) < 25 && (USER->query_soaked() || USER->query_stuffed())){  
     tell_object(USER, 
     HIG+"You feel Vengeance drain away the toxins in your body..."+NORM+"\n");
     USER->add_soaked(-(1 + random(3)));
     USER->add_stuffed(-(1 + random(3)));
     }
  return 1;
  }   
     
get(){ 
if(this_player())
if(this_player()->query_real_name() != "worm" && TP->query_level() < 20){
write("You are unable to grasp such a powerful artifact!\n");
return 0;
}
return 1;
}

init(){
    ::init();

add_action("emote1", "swing");
add_action("emote2", "twirl");
add_action("emote3", "threaten");
add_action("emote4", "draw");
add_action("emote5", "grip");
}

emote1(){
if(environment() != this_player()) return;
tell_object(this_player(),
"You swing the Scythe in a lazy arc, warding off your enemies...\n");
tell_room(environment(this_player()),
this_player()->query_name()+" swings "+this_player()->query_possessive()+" Scythe before"+
" "+this_player()->query_objective()+" in warning.\n", ({ this_player() }));
return 1;
}

emote2(){
if(environment() != this_player()) return;
tell_object(this_player(),
"You twirl the Scythe over your head and cackle with mad glee!\n");
tell_room(environment(this_player()),
this_player()->query_name()+" twirls "+this_player()->query_possessive()+" Scythe over"+
" "+this_player()->query_possessive()+" head and cackles in mad glee!\n", ({ this_player() }));
return 1;
}

emote3(str){
object ob;
if(environment() != this_player()) return;
if(!str){ write("threaten who?\n"); return 1; }
ob = present(str, environment(this_player()));
if(!ob){ write("You don't see them present!\n"); return 1; }
if(!living(ob)){ write("You can't threaten that!\n"); return 1; }
tell_object(this_player(),
"You raise your Scythe and point it at "+capitalize(str)+".\n"+
"You give a wicked smile as you imagine their corpse mangled before you.\n");
tell_object(ob,
TP->query_name()+" narrows "+TP->POS+" eyes as "+TP->PRO+" glares at you.\n"+
"A wicked smile crosses "+TP->POS+" face as "+TP->PRO+" raises his Scythe.\n");
tell_room(environment(TP),
TP->query_name()+" smiles wickedly as "+TP->PRO+" holds forth "+TP->POS+" Scythe.\n",
({ TP, ob }));
return 1;
}

emote4(){
if(environment() != this_player()) return;
tell_object(TP,
"You grin evilly as you slide your Scythe's blade before you...\n"+
"A line is drawn as you make your stand.\n");
tell_room(environment(TP),
TP->query_name()+" grins evilly as "+TP->PRO+" slides his Scythe's blade before "+TP->OBJ+".\n"+
"The line of challenge has been drawn.\n", ({ TP }));
return 1;
}

emote5(str){
if(environment() != this_player()) return;
tell_object(TP, 
"You grip your Scythe's handle eagerly as you prepare for combat!\n");
tell_room(environment(TP),
TP->query_name()+" grips "+TP->POS+" Scythe's handle eagerly as "+TP->PRO+" prepares for combat.\n",
({ TP }));
return 1;
}
