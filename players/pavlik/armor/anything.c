inherit "obj/armor";
#define ME this_object()
reset(arg){
   ::reset(arg);
 set_short("Anything Armor");
   set_arm_light(0);
set_long(
"This is Anything Armor.  This special object can be molded into\n"+
 "any kind of armor you want.  To customize this fabulous object\n"+
 "type: mold armor.\n");
   set_ac(1);
   set_weight(1);
   set_value(100);
   set_alias("armor");
   set_name("anything armor");
   set_type("misc");
}
 id(str) { return str == "armor"; }

init() {
  ::init();
   add_action("mold","mold");
}

mold(str) {
  if(!str) {
  write("Usage: mold armor.\n");
   return 1;
    }

if(str == "armor") {
 write("\n");
write(" You begin to mold the anything armor into a customized\n"+
       " item just for you!\n"+
       "    The first step in molding is to select the type of\n"+
       "    armor you would like to have.\n"+
       " You can choose from the following:  \n"+
       "   Helmet   Shield    Armor    Boots   Misc \n\n"+
       "     What type of Armor would you like?\n");
         input_to("type");
    return 1;
   }
  write("Usage: mold armor.\n");
     return 1;
}

type(str) {
  if(!str) {
  write("You must select the Type of armor you want to create!\n");
    command("mold armor", this_player());
       return 1;
         }
   if(str != "helmet" && str != "armor" && str != "boots" && str != "misc" && str != "shield") { write("There is no type like that.\n"); return 1; }
if(str == "helmet") {
    ME->set_type("helmet");
           }
if(str == "shield") {
    ME->set_type("shield");
           }
if(str == "armor") {
   ME->set_type("armor");
   }
if(str == "boots") {
    ME->set_type("boots");
           }
if(str == "misc") {
    ME->set_type("misc");
           }
  ME->set_alias(str);
 write("The type selected is: "+str+".\n");
 write("\nThe Next step is to name your armor.\n"+
       "example: The Cloak of Pavlik\n"+
       "  What would you like to name your armor?\n");
            input_to("nameit");
      return 1;
}

nameit(str) {
  if(!str) {
 write("You must enter the name of your object!\n"+
  "please do so now:\n");
   nameit();
   return 1;
   }
   ME->set_short(str);
  write("\nYour armor is now named: "+str+".\n");
    finish();
  return 1;
   }

finish() {
  write("\nYou have now created an armor:\n"+
     "    type: "+ME->query_type()+".\n"+
        "    name: "+ME->query_name()+"\n\n"+
        " To repeat the process and mold another armor just\n"+
        "type in: mold armor \n\n");
   return 1;
}
