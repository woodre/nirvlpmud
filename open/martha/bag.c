#define tp this_player()
#define ep environment(this_object())
#include "/players/mythos/closed/ansi.h"
#include "/players/feldegast/std/color_pad.h"
int wt;

id(str) { return str == "bag" || str == "mbag" || str == "bottomless"; }

get() { return 1; }
drop() { return 0; }
can_put_and_get() { return 1; }
query_weight() { return wt; }
query_value() { return 50; }
query_save_flag() { return 1; }
query_dest_flag() { return 1; }

reset(arg) { if(arg) return; wt = 1; }

short() { return "Bottomless Bag"; }

long() { write("This is the Bottomless Bag [a Mythos product]\n"+
               "You may put things and get things from it.\n"+
               "You may also sell items in and outside the bag.\n"+
               "Type 'sel' for more information.\n"+
               "To see what is inside the bag type baglist.\n");
       }
       
init() {
  add_action("baglist","baglist");
  add_action("sell","sel");
  add_action("pput","get");
  add_action("pput","take");
  add_action("pput","put");
  clearing();
}


pput() { clearing(); }
baglist() {
int h,i,j,k;
object ob;
i = 0;
j = k = 0;
ob = all_inventory(this_object());
write("Bag Inventory:\n\n"+
      "#\tName\t\t\tType\tValue\tSavability\n"+
      "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  for(h=0;h<sizeof(ob);h++) {
/* short() check added 7.13.01 by verte */
    if(ob[h] && ob[h]->short()) {
      i = i + 1; 
/* Added by Feldegast 11-7-00 */
          write(pad(i,5)+color_pad(ob[h]->short(),23)+"   "+NORM);
      if(ob[h]->weapon_class()) { write("Weapon"); j = j + 1; }
      else if(ob[h]->armor_class()) { write("Armor"); k = k + 1; }
      else write("Misc");
      write("\t"+ob[h]->query_value()+"\t");
      if(!ob[h]->query_save_flag()) write("Saveable\n");
      else write("Non-saveable\n");
    }
  }
  write("\nCurrently "+i+" objects in bag of which\n"+
          j+" are weapons and "+k+" are armor.\n");
return 1; }

add_weight(w) { clearing(); if(wt < 1) wt = 1; return 1; }
prevent_insert() { return 0; }

sell(str) {
object ob;
string name,null;
int h,j,i;
if(environment() != this_player()) return;
  if(!str) { 
     write("Usage:  sel <object name / option>\n"+
           " Options:   all     sells all objects in bag and in\n"+
           "                     personal inventory\n"+
           "            bagall   sells all objects in bag only\n"+
           "            invall   sells all in personal inventory\n"+
           "                     except bag and its contents\n"+
           "            nosave   sells all objects in bag and personal\n"+
           "                     inventory that are non-saveable\n"+
           "            noset    sells everything except for wielded weapon\n"+
           "                     worn armor, bag and bag's contents\n"+
           "            inbag <name>  sells object with the name <name> that\n"+
           "                     is in the bag\n "+
           "\n"+
           "Note: objects of value 0 will be sold as well.\n"+
           "      also, if sell inbag <name> is not used the object sold\n"+
           "      will be the object with name <name> in your inventory.\n");
     clearing();
    return 1; }
    clearing();
  if(sscanf(str,"%s %s",null,name) == 2 && null == "inbag") {
     ob = present(name,this_object());
     if(!ob) { write(capitalize(name)+" is not in the bag.\n"); return 1; }
     j = ob->query_value();
      j = j - (j/10);
    if(j > 1000) j = 1000;
     tp->add_money(j);
     write("You have received "+RED+j+NORM+" coins for selling "+ob->short()+".\n");
/* Added clearing() here so weight will be recalced.
  Thanks, Vert.       -Feldegast 11-7-00 */
     move_object(ob,"/room/void");
     clearing();
     destruct(ob);
   return 1; }
  if(str == "all" || str == "bagall" || str == "invall" ||
     str == "nosave" || str == "noset") {
     j = 0;
     if(str == "all" || str == "nosave") ob = deep_inventory(tp);
     if(str == "bagall") ob = all_inventory(this_object());
     if(str == "invall" || str == "noset") ob = all_inventory(tp);
     for(h=0;h<sizeof(ob);h++) {
       if(ob[h]) {
         if(ob[h] != this_object()) {
           if((str == "nosave" && ob[h]->query_save_flag()) ||
               str == "all" || str == "bagall" || str == "invall" ||
               (str == "noset" &&
                 ((!ob[h]->weapon_class() || ob[h] != tp->query_weapon()) && 
                 (!ob[h]->armor_class() || !ob[h]->query_worn())))) {
      if(ob[h]->short() && !ob[h]->query_auto_load() && 
      (str == "bagall" || ob[h]->query_weight()) && 
      !ob[h]->drop() && ob[h]->get()) {
             i = ob[h]->query_value();
             i = i - (i/10);
             if(i > 1000) i = 1000;
             j = j + i;
             if(i > 0) tp->add_money(i);
             if(environment(ob[h]) == tp) clearing();
             destruct(ob[h]);  } } }
       } 
     }
    write("You have sold ");
    if(str == "all") { write("all items.\n"); j += 50; }
    if(str == "nosave") write("all nonsaveable items.\n");
    if(str == "bagall") write("all items in the bag.\n");
    if(str == "invall") write("all items in your inventory.\n");
    if(str == "noset") 
  write("all items but your wielded weapon, worn armor, and bag.\n");
    write("You have received "+RED+j+NORM+" coins.\n");
    if(str == "all") { tp->add_money(query_value()); tp->add_weight(query_weight()); 
                       destruct(this_object()); }
  return 1; }
    ob = present(str,tp);
    if(!ob) { write(capitalize(str)+" is not in your inventory.\n"); return 1; }
    if(!ob->short() || ob->query_auto_load() || !ob->query_weight() || ob->drop() ||
        !ob->get()) {
      write("That item is not sellable!\n");
    return 1; }
     j = ob->query_value();
     j = j - (j/10);
   if(j > 1000) j = 1000;
     tp->add_money(j);
     command("drop "+str,tp);
      /* if(ob) check added by verte so items that dest on drop
        aren't called and whatnot. 6.8.01 */
     if(ob)
    {
     say(tp->query_name()+" sells "+ob->short()+".\n");
     write("You have received "+RED+j+NORM+" coins for selling "+ob->short()+".\n");
     destruct(ob);
     }
return 1; }

clearing() {
object op;
int lp;  
  wt = 1;
  op = all_inventory(this_object());
  for(lp=0;lp<sizeof(op);lp++) {
    wt += op[lp]->query_weight();
  } 
  wt = wt/5;
/* Changed check from ep->query_living() to living(ep) -Feldegast 11-7-00 */
  if(ep && living(ep)) ep->recalc_carry();
return 1; }
