#include "/players/jaraxle/define.h"
#define USER environment(this_object())
#define ATT USER->query_attack()
inherit "obj/armor";

int change_color;

#define WORD1 "assimilate"
#define WORD2 "discharge"

int power;
int used;

set_type(string str){
   type = str;
}


object ob;
int tmp, num;


reset(arg) {
   ::reset(arg);
   
   set_name("orb of holding");
   set_alias("holding orb");
   set_long("This orb has been shaped from pure crystal.  It works as a type of\n"+
            "container, absorbing the final life energy of corpses, assimilating\n"+
            "them for stored energy to be discharged to the user at a later time.\n"+
            "To use it's properties you may "+HIW+"'"+NORM+RED+"activate"+HIW+"'"+NORM+" and "+HIW+"'"+NORM+RED+"deactivate"+HIW+"'"+NORM+" the orb.\n"+
          "With it, you may \""+WORD1+"\" a corpse, or \""+WORD2+"\" for a healing spell.\n");
   set_ac(0);
   set_type("orb"); 
   set_weight(1);
   set_value(8000);
}

short(){
   
   switch(random(2)){
      case 0: change_color = ""+HIR+"";
      break;
      case 1: change_color = ""+HIY+"";
      break;
   }
   return "Whirling -"+HIR+"X"+NORM+"- Vortex"+(worn_by?" "+change_color+"("+NORM+HIR+"floating nearby"+NORM+change_color+")"+NORM+"":"");
   
}

id(str) {
   return str == "holding orb" || str == "orb" || str == "orb of holding"
   || str == "vortex" || str == "whirling vortex";
}

query_worn() { return worn; }
query_type() { return type; }
query_save_flag(){ return 0; }

init(){
   ::init();
   
   add_action("wear_it","wear");
   add_action("wear_it","remove");
   add_action("activate","activate");
   add_action("deactivate","deactivate");
   add_action("cmd_drain", WORD1);
   add_action("cmd_heal", WORD2);
   add_action("cmd_gauge","vcharge");
}

wear_it(str){
   if(id(str)){
      write("You can "+HIW+"'"+NORM+MAG+"activate"+HIW+"'"+NORM+" and "+HIW+"'"+NORM+MAG+"deactivate"+HIW+"'"+NORM+" the orb to use this power.\n");
      return 1; }
}

activate(str){
   if(environment()->is_kid()){
      object room;
      tell_room(room, "The orb refuses the childs will.\n");
      return 1; }
   
   if(id(str)){
      if(!worn){
         write("The orb slowly floats to your side.\n");
         present(str, this_player())->wear(str);
         return 1; }
      return 0; }
}

deactivate(str){
   if(id(str)){
      if(worn){
         write("The orb slowly sinks back into your hand.\n");
         present(str, this_player())->remove(str);
         return 1; }
      return 0; }
}

cmd_gauge(){
   if(power >= 200){         write(HIB+"["+HIR+"|||||"+NORM+RED+"|||||"+HIY+"|||||"+HIG+"|||||"+HIB+"]\n"+NORM); return 1; }
   if(power > 189 && power < 200){ write(HIB+"["+HIR+"|||||"+NORM+RED+"|||||"+HIY+"|||||"+HIG+"||||"+HIB+" ]\n"+NORM); return 1; }
   if(power > 179 && power < 190){ write(HIB+"["+HIR+"|||||"+NORM+RED+"|||||"+HIY+"|||||"+HIG+"|||"+HIB+"  ]\n"+NORM); return 1; }
   if(power > 169 && power < 180){ write(HIB+"["+HIR+"|||||"+NORM+RED+"|||||"+HIY+"|||||"+HIG+"||"+HIB+"   ]\n"+NORM); return 1; }
   if(power > 159 && power < 170){ write(HIB+"["+HIR+"|||||"+NORM+RED+"|||||"+HIY+"|||||"+HIG+"|"+HIB+"    ]\n"+NORM); return 1; }
   if(power > 149 && power < 160){ write(HIB+"["+HIR+"|||||"+NORM+RED+"|||||"+HIY+"|||||"+HIB+"     ]\n"+NORM); return 1; }
   if(power > 139 && power < 150){ write(HIB+"["+HIR+"|||||"+NORM+RED+"|||||"+HIY+"||||"+HIB+"      ]\n"+NORM); return 1; }
   if(power > 129 && power < 140){ write(HIB+"["+HIR+"|||||"+NORM+RED+"|||||"+HIY+"|||"+HIB+"       ]\n"+NORM); return 1; }
   if(power > 119 && power < 130){ write(HIB+"["+HIR+"|||||"+NORM+RED+"|||||"+HIY+"||"+HIB+"        ]\n"+NORM); return 1; }
   if(power > 109 && power < 120){ write(HIB+"["+HIR+"|||||"+NORM+RED+"|||||"+HIY+"|"+HIB+"         ]\n"+NORM); return 1; }
   if(power > 99 && power < 110){  write(HIB+"["+HIR+"|||||"+NORM+RED+"|||||"+HIB+"          ]\n"+NORM); return 1; }
   if(power > 89 && power < 100){  write(HIB+"["+HIR+"|||||"+NORM+RED+"||||"+HIB+"           ]\n"+NORM); return 1; }
   if(power > 79 && power < 90){   write(HIB+"["+HIR+"|||||"+NORM+RED+"|||"+HIB+"            ]\n"+NORM); return 1; }
   if(power > 69 && power < 80){   write(HIB+"["+HIR+"|||||"+NORM+RED+"||"+HIB+"             ]\n"+NORM); return 1; }
   if(power > 59 && power < 70){   write(HIB+"["+HIR+"|||||"+NORM+RED+"|"+HIB+"              ]\n"+NORM); return 1; }
   if(power > 49 && power < 60){   write(HIB+"["+HIR+"|||||               ]\n"+NORM); return 1; }
   if(power > 39 && power < 50){   write(HIB+"["+HIR+"||||                ]\n"+NORM); return 1; }
   if(power > 29 && power < 40){   write(HIB+"["+HIR+"|||                 ]\n"+NORM); return 1; }
   if(power > 19 && power < 30){   write(HIB+"["+HIR+"||                  ]\n"+NORM); return 1; }
   if(power > 9 && power < 20){    write(HIB+"["+HIR+"|"+HIB+"                   ]\n"+NORM); return 1; }
   if(power > 0 && power < 10){    write(HIB+"[                    ]\n"+NORM); return 1; }
   write(HIB+"[                    ]\n"+NORM);
   return 1; }


int cmd_drain(string str) {
   object corpse;
   int value;
   
   corpse=present("corpse",this_player());
   
   if(!corpse)
      corpse=present("corpse",environment(this_player()));
   
   if(!corpse) {
      notify_fail("Nothing happens.\n");
      return 0;
   }
   if(!worn){ notify_fail("The orb is not activated.\n"); return 0; }
   
   value=(int)corpse->heal_value();
   
   if(!value) {
      notify_fail("Nothing happens.\n");
      return 0;
   }
   
   if(environment(corpse)==this_player())
      this_player()->add_weight((int)corpse->query_weight());
   /*
   value*=2;
   */
   
   power+=value;
   if(power > 200) power=200;
   write("You touch the corpse of "+(string)corpse->query_name()+" with the soulstone.\n"+
      "The corpse's life energy is sucked into it and then\n"+
      "crumbles into dust.\n");
   say(TPN+" dissolves "+(string)corpse->short()+" with the soulstone.\n");
   command("vcharge",TP);
   destruct(corpse);
   return 1;
}

int cmd_heal(string str) {
   int amt;
  amt=1+random(20);
   
   if(!worn){ notify_fail("The orb is not activated.\n"); return 0; }
   
   if(amt > power) {
      notify_fail("Nothing happens.\n");
      return 0;
   }
   if(used) {
      write("The Orb is still recharging.\n");
      return 1;
   }
   power-=amt;
   this_player()->add_hp(amt);
   write("You whisper to the stone, asking it for power.  It grants\n"+
      "your wish with a jolt of energy.\n");
   say(TPN+" is infused by the "+short()+"'s power!\n");
   used=1;
   command("vcharge",TP);
   call_out("unset",15);
   return 1;
}

void unset() {
   used=0;
}

generic_object() { return 1; } 

restore_thing(str) {
   restore_object(str);
   return 1;
}

save_thing(str) {
   save_object(str);
   return 1;
}

locker_arg() {
   return ""+power;
}

locker_init(str) {
   sscanf(str,"%d",power);
}
