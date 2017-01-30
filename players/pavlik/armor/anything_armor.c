inherit "obj/armor";
#define MAX 5

string myshort, mylong;
int count;

reset(arg){
 ::reset(arg);
 set_short("Anything Armor");
 set_long("Anything Armor.\n");
 set_ac(1);
 set_type("misc");
 set_weight(2);
 set_value(500);
 set_name("Anything Armor");
 set_alias("armor");
 set_save_flag(0);
 myshort = "Anything Armor";
 mylong = "Anything Armor\n'info' for help";
 count = MAX;
}

short(){
  if(worn) return myshort+" (worn)";
  else return myshort;
}
long(){ write(mylong+"\n(type 'info' for details)\n"); return; }

init(){
 ::init();
 add_action("mold_short","anysee");
 add_action("mold_long","anyread");
 add_action("mold_type","anytype");
 add_action("any_info","info");

}

any_info(){
  write(
  "The Anything Armor is a mystifying enchanted armor that can assume any\n"+
  "shape the user chooses.\n"+
  "  anysee <str>     - change what the item looks like\n"+
  "  anyread <str>    - change what you see when you look AT the item\n"+
  "  anytype <str>    - change the type of armor\n"+
  "  info             - this list\n"+
  "\n"+
  "You can change the armor type "+count+" more times.\n");
  return 1;
}

mold_short(str){
  if(worn){
  write("You must remove the armor first.\n"); return 1;
  }
  if(!str){
  write("What do you want the armor to look like?\n");
  return 1;
  }
  write("Reshape the anything armor.\n");
  write("You now have '"+str+"'\n");
  myshort = str;
  return 1;
}

mold_long(str){
  if(worn){
  write("You must remove the armor first.\n"); return 1;
  }
  if(!str){
  write("How do you want the description to read?\n");
  return 1;
  }
  write("You change the description of anything armor.\n");
  mylong = str;
  return 1;
}

mold_type(str){
  if(count <= 0) {
    write("You cannot change the type any more.\n");
    return 1;
  }
  if(worn){
  write("You must remove the armor first.\n"); return 1;
  }
  if(!str){
  write("What kind of armor do you want?\n");
  return 1;
  }
  if(str == "shield" || str == "helmet" || str == "ring" ||
   str == "boots" || str == "amulet" || str == "cloak" || str == "misc"){
    write("You mold the armor into a "+str+".\n");
    set_type(str);
    set_alias(str);
    count--;
    return 1;
  } else {
    write("You cannot make the anything armor a "+type+".\n");
    write("Valid types: shield, helmet, ring, boots, amulet, cloak, misc.\n");
    return 1;
  }
}

