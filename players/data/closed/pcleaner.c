/*
Fangs of Shadows
Creator - Data
Date - 
shadows set item, documentation in /players/data/closed/miniquests/set/shadows/readme.txt
still need to put in lifeforce costs and tone this down when I get onto nirvana.

*/


inherit "/obj/weapon.c";
#include "/players/data/defs.h"
#include "/players/data/ansi.h"
object ob;
string owner_name;
int lifeforce, lifetap, speed,venom, i;
query_lifeforce() { return lifeforce; }
query_lifetap() { return lifetap; }
query_speed() { return speed; }
query_venom()  { return venom; }
query_owner() { return owner_name; }


owner() {
    return owner_name;
}
set_owner(str) {
    owner_name = str;
}

void reset(int arg) {
  if(arg) return;
  set_name("fang");
  set_alias("dagger");
  set_id("fang");
  set_owner("data");
  set_short(HIM+"F"+BLK+"ang of "+HIM+"S"+BLK+"hadows"+NORM);
  set_long(
HIM+"The fang pulses of dark intents, looking at where a blade of metal"+BLK+"\n"+
"should be there are instead twin needle sharp fangs with less than \n"+ 
"half an inch of space between them that pulse a wicked green. The \n"+
"fangs easily reach a foot in length and slightly curve towards each \n"+
"other towards the tip. The tips drip slightly with violet venom, giving \n"+
"the idea that this weapon likes to be plunged into it's victims. A inch \n"+
"from the handle the fangs merge into one, ending at what appears to be\n"+
"the gums of a reptile. At the end of the handle there is the head of a \n"+
"snake, as the tongue of the serpent winds up and around the handle as"+HIM+"\n"+ 
"though to sample the soul and intent of the wielder."+NORM+"\n"

  );
  set_type("dagger");
  set_class(16);
  set_weight(2);
  set_value(200000);
  set_hit_func(this_object());
  


}

init() {
  add_action("cmd_drain", "drain");
  add_action("wield", "wield");
  add_action("un_wield", "unwield");
  add_action("no_wimpy", "wimpy");
  add_action("drop", "drop");
  add_action("activate", "activate");
  add_action("deactivate", "deactivate");

}
/*Lets make it so only the owner can pick this item off the ground*/
   get(){
   
  if(this_player()->query_real_name()==query_owner()) {

        return 1;
        }
        else 
        {
        write("You fail to pickup someone else's items. \n");
   return 0;
}
}
/*wizes can see how much power exactly the fangs have*/
string short() {
  string shrt;
  shrt=short_desc;
  if(this_player() && this_player()->query_level() > 20)
    shrt+=" (Lifeforce: "+lifeforce+")";
/*wow, color for wield...what next?*/
    if (wielded)
            return shrt+BLK+" ("+HIM+"wielded"+BLK+")"+NORM;
    return shrt+" ";
  return shrt;
}
/*how much power does the fangs have that the player can guess*/
void long(string str) {
  ::long(str);
      if(lifeforce < 1250)
      write(HIR+"The fangs lay in hybernation"+NORM);

      else if(lifeforce < 2500)
      write(HIR+"The fangs grow warm with awakening power"+NORM);

          else if(lifeforce < 3750)
      write(HIR+"The Fangs emit pulse waves of violet light"+NORM);
     else if(lifeforce > 5000) 
    write(HIR+"The Fangs hiss in greed and purpose"+NORM);
  write(".\n");
}
/*drains corpses to power the weapon's specials*/
int cmd_drain(string str) {
  object corpse;
  int value;

  corpse=present("corpse",this_player());

  if(!corpse)
    corpse=present("corpse",environment(this_player()));

  if(!corpse) {
    notify_fail("There is no corpse to drain.\n");
    return 0;
  }


   value = corpse->query_level() + 50;


  if(environment(corpse)==this_player())
    this_player()->add_weight((int)corpse->query_weight());

  value*=2;
  lifeforce+=value;
  if(lifeforce > 5000) lifeforce=5000;
  write(BLK+"You sink the "+HIM+"F"+BLK+"angs of "+HIM+"S"+BLK+"adows deep into "+(string)corpse->short()+".\n"+
        "The Fangs inject it's victim full of venom, causing it to "+HIM+"glow."+BLK+"\n"+
        "The corpse then melts into the "+HIM+"shadows"+BLK+" to join it's kin."+NORM+"\n");
  say(BLK+TPN+"sinks the "+HIM+"F"+BLK+"angs of "+HIM+"S"+BLK+"adows deep into "+(string)corpse->short()+".\n"+
        "The Fangs inject it's victim full of venom, causing it to "+HIM+"glow."+BLK+"\n"+
        "The corpse then melts into the "+HIM+"shadows"+BLK+" to join it's kin."+NORM+"\n");
  destruct(corpse);
  return 1;
}



/* had to copy this strait from the wield, unwield, and drop portion from weapon.c so I could
put in checks for wimpy and attack as well as clone no_flee on wield and destruct
no_flee on drop or unwield since I dont know how to append object itself
in weapon.c
*/
/*
wield(str) {
    if (!id(str))
        return 0;
    if (environment() != this_player()) {
         write("You must get it first!\n"); 
        return 0;
    }
   if (this_player()->query_wimpy()) {
        write("You can't wield this weapon with wimpy set!\n");
        return 1;
    }
    if (wielded) {
        write("You already wield it!\n");
        return 1;
    }
    if(wield_func)
        if(!wield_func->wield(this_object()))
            return 1;
    wielded_by = this_player();
    this_player()->wield(this_object());
    move_object(clone_object("/players/data/closed/miniquests/sets/shadows/player_flee.c"),this_player());
    wielded = 1;
    return 1;
}

un_wield(str) {
object ob;
if(this_player()->query_attack())
    {
    write("You can't remove your weapon while in combat!\n");
    return 1;
    }
else
    if (wielded)
     write("You unwield your weapon.\n");
     ob = present("player_flee", this_player());
     destruct(ob);
    ob = present("player_flee", this_player());
     destruct(ob);
        wielded = 0;
        return 1;
}

drop(silently) {
if(this_player()->query_attack())
    {
    write("You can't drop your weapon while in combat!\n");
   return 1;
    }
else    
    if (wielded) {
        wielded_by->stop_wielding();
         ob = present("player_flee", this_player());
     destruct(ob);
    ob = present("player_flee", this_player());
     destruct(ob);
        wielded = 0;
        if (!silently)
            write("You drop your wielded weapon.\n");
    }
    return 0;
}
/*cant set wimpy with this weapon wielded but you can wield other weapons*/
no_wimpy(str){
   if (wielded)
    {
   write("You can't set wimpy wielding this weapon!\n");
 return 1;
   
    }
}

weapon_hit(attacker){
int tmp;
int W, h, m;
int v;
object ob, oc;
string where,wheretwo,wherethree,wherefour;
string what,whattwo,whatthree,whatfour;
string od;
tmp=random(27);
/*lets make this thing hit a second time, but make people think its hitting more
  than that...*/
{
if(this_object()->query_speed())
{
  if(10 > lifeforce) {
    write("Your fangs run out of lifeforce and deactivates speed.\n");
    speed=0;
    return 1;
  }
      
      if(tmp < 1) {
         write("You missed.\n");
         say(wielded_by->query_name()+" missed.\n");
         return 0;
      }
/*this is the actual special*/
        if (tmp < 30) {

            what = HIM+"stab and twist"+BLK;
        }
        if (tmp < 20) {

            what = HIM+"stab"+BLK;
        }
        if (tmp < 10) {

            what = HIM+"slash"+BLK;
        }
        if (tmp < 5) {

            what = HIM+"cut"+BLK;
        }
        if (tmp < 3) {

            what = HIM+"scratch"+BLK;
        }
        if (tmp == 1) {

            what = HIM+"poke"+BLK;
        }
        
   switch(random(8)+1){
     case 8:
   where = HIM+"stomach"+BLK;
   break;
   case 7:
   where = HIM+"neck"+BLK;
   break;
     case 6:
   where = HIM+"arm"+BLK;
   break;
     case 5:
   where = HIM+"foot"+BLK;
   break;
   case 4:
   where = HIM+"leg"+BLK;
   break;
   case 3:
   where = HIM+"chest"+BLK;
   break;
   case 2:
   where = HIM+"groin"+BLK;
   break;
   case 1:
   where = HIM+"back"+BLK;
   break;
   }
   /*this is the fake stuff*/
      switch(random(8)+1){
     case 8:
   wheretwo = HIM+"stomach"+BLK;
   break;
     case 7:
   wheretwo = HIM+"neck"+BLK;
   break;
     case 6:
   wheretwo = HIM+"arm"+BLK;
   break;
     case 5:
   wheretwo = HIM+"foot"+BLK;
   break;
   case 4:
   wheretwo = HIM+"leg"+BLK;
   break;
   case 3:
   wheretwo = HIM+"chest"+BLK;
   break;
   case 2:
   wheretwo = HIM+"groin"+BLK;
   break;
   case 1:
   wheretwo = HIM+"back"+BLK;
   break;
   }
   
      switch(random(8)+1){
     case 8:
   wherethree = HIM+"stomach"+BLK;
   break;
     case 7:
   wherethree = HIM+"neck"+BLK;
   break;
     case 6:
   wherethree = HIM+"arm"+BLK;
   break;
    case 5:
   wherethree = HIM+"foot"+BLK;
   break;
   case 4:
   wherethree = HIM+"leg"+BLK;
   break;
   case 3:
   wherethree = HIM+"chest"+BLK;
   break;
   case 2:
   wherethree = HIM+"groin"+BLK;
   break;
   case 1:
   wherethree = HIM+"back"+BLK;
   break;
   }
   
      switch(random(8)+1){
     case 8:
   wherefour = HIM+"stomach"+BLK;
   break;
     case 7:
   wherefour = HIM+"neck"+BLK;
   break;
     case 6:
   wherefour = HIM+"arm"+BLK;
   break;
     case 5:
   wherefour = HIM+"foot"+BLK;
   break;
   case 4:
   wherefour = HIM+"leg"+BLK;
   break;
   case 3:
   wherefour = HIM+"chest"+BLK;
   break;
   case 2:
   wherefour = HIM+"groin"+BLK;
   break;
   case 1:
   wherefour = HIM+"back"+BLK;
   break;
   }
   
      switch(random(6)+1){

     case 6:
   whattwo = HIM+"stab and twist"+BLK;
   break;
     case 5:
   whattwo = HIM+"stab"+BLK;
   break;
   case 4:
   whattwo = HIM+"slice"+BLK;
   break;
   case 3:
   whattwo = HIM+"cut"+BLK;
   break;
   case 2:
   whattwo = HIM+"scratch"+BLK;
   break;
   case 1:
   whattwo = HIM+"poke"+BLK;
   break;
   }
   switch(random(6)+1){

     case 6:
   whatthree = HIM+"stab and twist"+BLK;
   break;
     case 5:
   whatthree = HIM+"stab"+BLK;
   break;
   case 4:
   whatthree = HIM+"slice"+BLK;
   break;
   case 3:
   whatthree = HIM+"cut"+BLK;
   break;
   case 2:
   whatthree = HIM+"scratch"+BLK;
   break;
   case 1:
   whatthree = HIM+"poke"+BLK;
   break;
   }
   switch(random(6)+1){

     case 6:
   whatfour = HIM+"stab and twist"+BLK;
   break;
     case 5:
   whatfour = HIM+"stab"+BLK;
   break;
   case 4:
   whatfour = HIM+"slice"+BLK;
   break;
   case 3:
   whatfour = HIM+"cut"+BLK;
   break;
   case 2:
   whatfour = HIM+"scratch"+BLK;
   break;
   case 1:
   whatfour = HIM+"poke"+BLK;
   break;
   }
  if(this_player()->query_attack())
          {
        write( BLK+"You " + what + " " +this_player()->query_attack()->query_name()+" in the " + where + NORM +".\n");
}

switch(random(6)+1){
   case 3:
   write( BLK+"You " + whattwo + " " +this_player()->query_attack()->query_name()+" in the " + wheretwo + NORM +".\n");
   break;
   case 2:
   write( BLK+"You " + whattwo + " " +this_player()->query_attack()->query_name()+" in the " + wheretwo + ".\n"+
              "You " + whatthree + " " +this_player()->query_attack()->query_name()+" in the " + wherethree + NORM +".\n");
   break;
   case 1:
   write( BLK+"You " + whattwo + " " +this_player()->query_attack()->query_name()+" in the " + wheretwo + ".\n"+
              "You " + whatthree + " " +this_player()->query_attack()->query_name()+" in the " + wherethree + ".\n"+
              "You " + whatfour + " " +this_player()->query_attack()->query_name()+" in the " + wherefour + NORM +".\n");
   break;
   }
   lifeforce-=5;
   return tmp;
        }
/*Lets drain some life while we are at it to replenish ours*/    
if(this_object()->query_lifetap()){
  if(40 > lifeforce) {
    write("Your fangs run out of lifeforce and deactivates lifetap.\n");
    lifetap=0;
    return 1;
  }
  
  h=random(3);
  if(!h) {
    lifeforce-=20;
    switch(random(2)+1) {
      case 1: write("\n"+BLK+"<<"+HIM+"LIFETAP"+BLK+">> You sink the "+HIM+"F"+BLK+"angs of "+HIM+"S"+BLK+"adows deep\n"+
                    "into your advisary's chest and drain their lifeforce to replenish yours."+NORM+"\n""\n");
              say("\n"+BLK+"<<"+HIM+"LIFETAP"+BLK+">> "+this_player()->query_name()+"sinks the "+HIM+"F"+BLK+"angs of "+HIM+"S"+BLK+"adows deep\n"+
                 "into your chest and drains your lifeforce!"+NORM+"\n""\n");
                 this_player()->heal_self(tmp); 
              break;
      case 2: write("\n"+BLK+"<<"+HIM+"LIFETAP"+BLK+">> You stab "+this_player()->query_attack()->query_name()+" and watch with satisfaction as their\n"+
                    "eyes glaze a bright "+HIM+"purple "+BLK+"as you steal their lifeforce!"+NORM+"\n""\n");
              say("\n"+BLK+"<<"+HIM+"LIFETAP"+BLK+">>"+this_player()->query_name()+"stabs you and smiles as your eyes glaze\n"+
                  "a bright "+HIM+"purple "+BLK+"as they steal your lifeforce!"+NORM+"\n""\n");
              this_player()->heal_self(tmp);
              break;
 
  
        return 1;

}
  }    
}
}

  m=random(10);
  if(!m) {
if(this_object()->query_venom() &&
   
   !present("wounds", this_player()->query_attack())) {
  
  if(120 > lifeforce) {
    write("Your fangs run out of lifeforce and deactivates venom.\n");
    venom=0;
    return 1;
  }
  write("\n"+BLK+"<<"+HIM+"VENOM"+BLK+">> You drive your fangs into your foe's thigh injecting them with venom.\n"+NORM+"\n");
 move_object(clone_object("/players/data/closed/miniquests/sets/shadows/wounds.c"),this_player()->query_attack());
lifeforce-=100;
}
}

return 1;
}
/*must have toggles, toggles are gooooood*/

activate(str)
{
if(!str){
write("Syntax: activate speed/lifetap/venom?\n");
return 1;
   }
if(str == "speed"){
write("You turn speed on.\n");
speed = 1; 
    
return 1; 
}
if(str == "lifetap"){
write("You turn lifetap on.\n");
lifetap = 1; 
    return 1; 
}

if(str == "venom"){
write("You turn venom on.\n");
venom = 1; 
    return 1; 
  }
}

deactivate(str)
{
if(!str){
write("Syntax: deactivate speed/lifetap/venom.\n");
return 1;
   }
if(str == "speed"){
write("You turn speed off.\n");
speed = 0; 
    
return 1; 
}
if(str == "lifetap"){
write("You turn lifetap off.\n");
lifetap = 0; 
    return 1; 
}

if(str == "venom"){
write("You turn venom off.\n");
venom = 0; 
    return 1; 
  }
}

