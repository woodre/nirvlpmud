/*
 *      File:                 /players/jareel/
 *      Function:             The forged full sets of Death & Chaos armors
 *      Author(s):            Jareel@Nirvana Fred@Nirvana
 *      Copyright:            Copyright (c) 2005 Jareel
 *                               All Rights Reserved.
 *      Source:               8/9/06 Code Shared by Fred
 *      Approved by:            
 *      Notes:                
 *      Chaos Set             Requires the following 16 pieces to forge:
 *                                        Dark Chaos Greaves.
 *                                        Dark Chaos Ring.
 *                                        Dark Chaos Shorts.
 *                                        Dark Chaos Shield.
 *                                        Dark Chaos Plate.
 *                                        Dark Chaos Vambraces.
 *                                        Dark Chaos Necklace.
 *                                        Dark Chaos Aura.
 *                                        Dark Chaos Helm.
 *                                        Dark Chaos Gloves.
 *                                        Dark Chaos Earring.
 *                                        Dark Chaos Cloak.
 *                                        Dark Chaos Guard.
 *                                        Dark Chaos Boots.
 *                                        Dark Chaos Belt.
 *                                        Dark Chaos Amulet.
 *                            
 *      Death Set             Requires the following 7 pieces to forge:
 *                                        Iron Shield of Death.
 *                                        Iron Guard of Death.
 *                                        Iron Helm of Death.
 *                                        Iron Gauntlets of Death.
 *                                        Iron Boots of Death.
 *                                        Iron Plate of Death.
 *                                        Iron Amulet of Death.
 *                                        Iron fullplate of death.
 *        
 *      Change History:
 */

/* 
 * Function name:  
 * Description:    
 * Arguments:      
 * Returns:        
 */
#define NAME HIK+"Darkbeard"+NORM+", Master Dwarven Blacksmith"

#include "/players/jareel/define.h"
#include "/players/jareel/ansi.h"
inherit "obj/monster.c";
string person;

int a, b, play, run;
object fullset, chaos, Adeath;

reset(arg)  {
  ::reset(arg);
    if(arg) return;

  MOCO("/players/jareel/weapons/chaos/woods2/hammer.c"),this_object());
    init_command("wield hammer");
   
  set_name("darkbeard");
  set_race("dwarf");
  set_alias("smith");
  set_short(NAME);
  set_long(
    "Short, stout, and muscular, Darkbeard is the pure image of a Blacksmith.\n"+
    "Coal and soot cover his body as his hammer hits his anvil.  His arms\n"+
    "are the size of small trees and his beard is probably longer than he is.\n"+
    "Darkbeard is a master at what he does 'ask' him if you need any help.\n");
  add_spell(
    "smackemup",">>>C L A N G<<< Darkbeard's hammer smashes into you!\n"+NORM+"",
                "Darkbeard >>>C L A N G S<<< into #TN#'s body with his hammer!\n",
    30,50,"other|physical");
  set_level(21);
  add_money(3000+random(2000));
  set_hp(750);
  set_al(0);
  set_ac(60);
  set_wc(20);
  set_heal(15,1);
  set_aggressive(0);
  set_dead_ob(this_object());
}

init(){
  ::init();
    add_action("askem","ask");
    add_action("chaos","chaos");
    add_action("Adeath","death");
    add_action("fix","fix");
  }

askem(){
  person = this_player();
  play = 1;
  call_out("talk",3,person);
  return 1; }

talk(person){
  say_it();
  a += 1;
  if(a<8) call_out("talk",2,person);
  else { 
  play = 0;
  a = 0;
  }
  return 1; }

say_it(){
  string stuff;
   switch(a){
     case 0: stuff =  " "; break;
     case 1: stuff = "Darkbeard nods to you."; break;
     case 2: stuff = "Darkbeard says: I am one of the few smiths who can make your life simple."; break;
     case 3: stuff = "Darkbeard says: I can merge the sets of Death and Chaos, into one piece."; break;
     case 4: stuff = "Darkbeard says: It will not only make them one piece but I can inscribe the armor also."; break;
     case 5: stuff = "Darkbeard says: The inscription will add some protection, but it may remove some also."; break;
     case 6: stuff = "Darkbeard says: After you give me any set you just need to type 'chaos' or 'death'."; break;
     case 7: stuff = "Darkbeard says: It aint cheep bitch so you better pay up. "; break;
   }
    tell_object(person,
    stuff+NORM+"\n");
    return 1; }
  
Adeath(){
  object one, two, three, four, five, six, seven, sword;
    one = present("death_plate", this_object());
    two = present("death_shield", this_object());
    three = present("death_helm", this_object());
    four = present("death_boots", this_object()); 
    five = present("death_amulet", this_object());
    six = present("death_guard", this_object());
    seven = present("death_gauntlets", this_object());
    

  Adeath = clone_object("/players/jareel/armor/chaos/cave/fullset.c");
    if (call_other(this_player(), "query_money", 0) < 20000) {
      write("Darkbeard says: Come back when you have some cash bitch.\n");
      destruct(Adeath);
    return 1;
  }

  if(!this_player()->add_weight(Adeath->query_weight())) {
    write("Darkbeard says: You pussy grow some muscles.\n");
    destruct(Adeath);
  return 1; }  

  if(one && two && three && four && five && six && seven){
    this_object()->add_weight(-(one->query_weight()));
    this_object()->add_weight(-(two->query_weight()));
    this_object()->add_weight(-(three->query_weight()));
    this_object()->add_weight(-(four->query_weight()));
    this_object()->add_weight(-(five->query_weight()));
    this_object()->add_weight(-(six->query_weight()));
    this_object()->add_weight(-(seven->query_weight()));
    destruct(one);
    destruct(two);
    destruct(three); 
    destruct(four);
    destruct(five);
    destruct(six);
    destruct(seven);
    write("Darkbeard hands you the forged set of Death.\n");
    this_player()->add_money(-(20000));
    move_object(Adeath, this_player());
    write_file("/players/jareel/log/death", this_player()->query_name() + " received the Chaos Full Set " + ctime()[4..15] + "\n");
  return 1;
  }


  write("Darkbeard says: Nice try bitch, you need the whole set for that.\n");
    return 1;
  }


chaos(){
  object one, two, three, four, five, six, seven, eight, nine, ten, eleven, twelve, thirteen, fourteen, fifteen, sixteen, sword;
    one = present("chaos_armor", this_object());
    two = present("chaos_shield", this_object());
    three = present("chaos_helm", this_object());
    four = present("chaos_boots", this_object()); 
    five = present("chaos_amulet", this_object());
    six = present("chaos_chest", this_object());
    seven = present("chaos_necklace", this_object());
    eight = present("chaos_cloak", this_object());
    nine = present("chaos_bracers", this_object());
    ten = present("chaos_pants", this_object());
    eleven = present("chaos_belt", this_object());
    twelve = present("chaos_gloves", this_object());
    thirteen = present("chaos_earring", this_object());
    fourteen = present("chaos_ring", this_object());
    fifteen = present("chaos_underwear", this_object());
    sixteen = present("chaos_misc", this_object());

  chaos = clone_object("/players/jareel/armor/chaos/cave/fullset.c");
    if (call_other(this_player(), "query_money", 0) < 20000) {
      write("Darkbeard says: Get some money bitch till then thanks for the gear.\n");
      destruct(chaos);
    return 1;
  }

  if(!this_player()->add_weight(chaos->query_weight())) {
    write("Darkbeard says: You pussy, go workout.\n");
    destruct(chaos);
  return 1; }  

  if(one && two && three && four && five && six && seven && eight && nine && ten && eleven && twelve && thirteen && fourteen && fifteen && sixteen){
    this_object()->add_weight(-(one->query_weight()));
    this_object()->add_weight(-(two->query_weight()));
    this_object()->add_weight(-(three->query_weight()));
    this_object()->add_weight(-(four->query_weight()));
    this_object()->add_weight(-(five->query_weight()));
    this_object()->add_weight(-(six->query_weight()));
    this_object()->add_weight(-(seven->query_weight()));
    this_object()->add_weight(-(eight->query_weight()));
    this_object()->add_weight(-(nine->query_weight()));
    this_object()->add_weight(-(ten->query_weight()));
    this_object()->add_weight(-(eleven->query_weight()));
    this_object()->add_weight(-(twelve->query_weight()));
    this_object()->add_weight(-(thirteen->query_weight()));
    this_object()->add_weight(-(fourteen->query_weight()));
    this_object()->add_weight(-(fifteen->query_weight()));
    this_object()->add_weight(-(sixteen->query_weight()));
    destruct(one);
    destruct(two);
    destruct(three); 
    destruct(four);
    destruct(five);
    destruct(six);
    destruct(seven);
    destruct(eight);
    destruct(nine);
    destruct(ten);
    destruct(eleven);
    destruct(twelve);
    destruct(thirteen);
    destruct(fourteen);
    destruct(fifteen);
    destruct(sixteen);
    write("Darkbeard hands you the forged set of Chaos.\n");
    this_player()->add_money(-(20000));
    move_object(chaos, this_player());
    write_file("/players/jareel/log/chaos", this_player()->query_name() + " received the Chaos Full Set " + ctime()[4..15] + "\n");
  return 1;
  }

  write("Darkbeard says: You haven't given me the entire set yet.\n");
    return 1;
  }

fix(str) {

  int cost;

  object ob;

  if (!str) return 0;
      
  ob=present(str,this_player());
 
  if(!ob) ob = present(str,this_object());
  if(!ob) {
    write("Darkbeard says: I don't see that shit.\n");
  return 1;
  }

  if(ob->query_wielded()){ 
    write("Darkbeard says: Unwield that shit.\n");
  return 1;
  }
 
  if(!ob->fix_weapon()) {
    write("Darkbeard say: That shit ain't broken, you're a fucken moron.\n");
  return 1;
  }

  cost = 500;
  if (this_player()->query_money() < cost) {
    ob->re_break();
      write("Darkbead says: I don't do this shit for free Bitch.\n");
  return 1;
  }
  
  this_player()->add_money(-500);
  write(
    "Darkbeard takes "+str+" in one hand grabs his hammer and...\n\n\n"+
    BOLD+"<-><-><-><-><-><-><-><-> C L A N G <-><-><-><-><-><-><-><->"+NORM+"\n\n\n"+
    "Darkbeard returns it to your waiting grasp.\n"+
    "Darkbeard say: Treat your weapon better next time.\n");
  return 1;
  }
