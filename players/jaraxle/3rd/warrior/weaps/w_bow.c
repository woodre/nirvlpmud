#include "/players/jaraxle/define.h"
inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("longbow");
set_alias("surtido");
set_short("Surtido, the Longbow");
set_long(
    "A long, curved bow made of a flexible wood.  The bow string has\n"+
    "a hazy blue glow to it.  The longbow has a light feel to it.  There\n"+
    "is an insignia carved into the longbow.\n");


set_type("bow");  /*  sword/knife/club/axe/bow/polearm  */
set_class(16);
set_weight(1);
set_value(1500);
set_hit_func(this_object());
}

init(){
  ::init();
add_action("read","read");
}
read(arg){
if(arg == "insignia"){
write("Willa [S.E.M.P.]\n");
return 1; } 
}
weapon_hit(attacker){
int W, X, Y, Z;
W = random(5);
X = random(5);
Y = random(5);
Z = random(2);

if(W == 0){  
  if(present("E_quiver", environment())){
  present("E_quiver", environment())->set_arrows(-1);
    say(TPN+" pulls an arrow from their quiver, which immediately bursts into "+HIR+"flames"+NORM+"!\n\n");
    say(TPN+" fires a "+HIY+"flam"+HIR+"ing"+NORM+" arrow into "+attacker->query_name()+"!\n");
     
    write("You pull an arrow from your quiver, which immediately bursts into "+HIR+"flames"+NORM+"!\n\n");
    write("You fire a "+HIR+"flam"+HIY+"ing "+HIR+"arrow"+NORM+" from your bow!\n");
    write("It lands square in "+attacker->query_name()+"'s chest with a loud 'THUK!'\n");

    MOCO("/players/jaraxle/3rd/warrior/weaps/f_arrow.c"), attacker);

   return((environment()->query_attrib("mag")+environment()->query_attrib("int")+environment()->query_attrib("wil"))/6);

  return 2; }

}

if(X == 1){
  if(present("M_quiver", environment())){
  present("M_quiver", environment())->set_arrows(-1);

    say(TPN+" fires a "+HIG+"glowing"+NORM+""+GRN+" green"+NORM+" arrow at "+attacker->query_name()+"!\n");

    write("You fire a "+HIG+"pois"+HIM+"onous ar"+HIG+"row"+NORM+" from your bow!\n");
    write("The arrow stabs "+attacker->query_name()+" in the leg.\n");

    MOCO("/players/jaraxle/3rd/warrior/weaps/p_arrow.c"), attacker);

   return((environment()->query_attrib("mag")+environment()->query_attrib("int")+environment()->query_attrib("wil"))/8+random(3));

  return 2; }
}

if(Y == 2){
  if(present("P_quiver", environment())){
  present("P_quiver", environment())->set_arrows(-1);

    say(TPN+" fires an "+HIW+"e"+HIR+"X"+HIY+"pl"+HIW+"od"+HIM+"in"+HIR+"g"+NORM+" arrow from "+POS+" bow!\n");
    say("The arrow "+BLINK+""+HIW+"e"+HIR+"X"+HIY+"pl"+HIW+"od"+HIM+"e"+HIR+"s"+NORM+" into "+attacker->query_name()+"'s chest!\n");

    write("You fire an "+HIW+"e"+HIR+"X"+HIY+"pl"+HIW+"od"+HIM+"in"+HIR+"g"+NORM+" arrow from your bow!\n");
    write("The arrow "+BLINK+""+HIW+"e"+HIR+"X"+HIY+"pl"+HIW+"od"+HIM+"e"+HIR+"s"+NORM+" into "+attacker->query_name()+"'s chest!\n");

    return((environment()->query_attrib("str")+environment()->query_attrib("str"))/4);
  
  return 2; }
}


if(W == 3){
  if(present("E_quiver", environment())){
  present("E_quiver", environment())->set_arrows(-1);

    say(TPN+" fires a "+HIB+"free"+HIC+"zing"+NORM+" arrow into "+attacker->query_name()+"!\n");
    say(HIW+"Ice"+NORM+" crackles over "+attacker->query_name()+"'s body.\n");
    
    write("You fire an arrow at "+attacker->query_name()+"\n");
    write("The arrow "+HIW+"free"+HIB+"zes"+NORM+" in mid air as it screams towards "+attacker->query_name()+"!\n");
    write("The arrow lands directly in "+attacker->query_name()+"'s chest\n"+HIW+"Ice"+NORM+" crackles over "+attacker->query_name()+"'s body.\n");

    MOCO("/players/jaraxle/3rd/warrior/weaps/i_arrow.c"), attacker);

    return((environment()->query_attrib("mag")+environment()->query_attrib("int"))/5);

  return 2; }
}

if(X == 4){
  if(present("M_quiver", environment())){
  present("M_quiver", environment())->set_arrows(-1);

    say(TPN+" fires a "+HIW+"lig"+HIY+"h"+HIW+"t"+HIY+"ning "+NORM+" from "+POS+" bow!\n");
    say(HIW+"Lig"+HIY+"h"+HIW+"t"+HIY+"ning "+NORM+"crackles over "+attacker->query_name()+"'s body.\n");

    write("You pull an arrow from the quiver.\nThe arrow slices through the wind, "+HIW+"ele"+HIY+"ctr"+HIW+"ic"+HIY+"ity"+NORM+" crackles over the arrow.\n");
   write(HIW+"Ele"+HIY+"ctr"+HIW+"ic"+HIY+"ity"+NORM+" crackles over "+attacker->query_name()+"'s body.\n");

    MOCO("/players/jaraxle/3rd/warrior/weaps/f_arrow.c"), attacker);

    return((environment()->query_attrib("mag")+environment()->query_attrib("wil")+environment()->query_attrib("int"))/7);

  return 2; }
}

if(Y == 4){
  if(present("P_quiver", environment())){
  present("P_quiver", environment())->set_arrows(-1);
   
    say(TPN+" fires a "+BLK+""+BOLD+"st"+NORM+""+HIW+"o"+BOLD+""+BLK+"ne ti"+NORM+""+HIW+"pp"+BOLD+""+BLK+"ed"+NORM+" arrow from "+POS+" bow!\n");
    say("The "+BLK+""+BOLD+"st"+NORM+""+HIW+"o"+BOLD+""+BLK+"ne ti"+NORM+""+HIW+"pp"+BOLD+""+BLK+"ed"+NORM+" arrow slams into "+attacker->query_name()+"'s head.\nLanding with a hard 'THUD!'\n");

    write("You fire a  "+BLK+""+BOLD+"st"+NORM+""+HIW+"o"+BOLD+""+BLK+"ne ti"+NORM+""+HIW+"pp"+BOLD+""+BLK+"ed"+NORM+" arrow from your bow!\n");
    write("The "+BLK+""+BOLD+"st"+NORM+""+HIW+"o"+BOLD+""+BLK+"ne ti"+NORM+""+HIW+"pp"+BOLD+""+BLK+"ed"+NORM+" arrow slams into "+attacker->query_name()+"'s head.\nLanding with a hard 'THUD!'\n");
   
    MOCO("/players/jaraxle/3rd/warrior/weaps/s_arrow.c"), environment(attacker));
    
    return((environment()->query_attrib("str")+environment()->query_attrib("int")+environment()->query_attrib("str")+environment()->query_attrib("wil"))/9);

  return 2; }
}

if(Z == 1){
  if(present("S_quiver", environment())){
  present("S_quiver", environment())->set_arrows(-2);

    say(TPN+" fires an arrow from "+POS+" bow!\n"+TPN+" fires a "+HBYEL+""+HIW+"second"+NORM+" arrow from the bow!!\n");
    say("The arrows zing through the air and thunder into "+attacker->query_name()+"!\n");
  
    write("You fire an arrow from "+POS+" bow!\nYou fire a "+HBYEL+""+HIW+"second"+NORM+" arrow from the bow!!\n");
   write("The arrows zing through the air and thunder into "+attacker->query_name()+"!\n");

    MOCO("/players/jaraxle/3rd/warrior/weaps/arrow.c"), attacker);
    MOCO("/players/jaraxle/3rd/warrior/weaps/arrow.c"), attacker);

    return(2+(environment()->query_attrib("ste")+environment()->query_attrib("str"))/5);
  return 2; }
}

}


