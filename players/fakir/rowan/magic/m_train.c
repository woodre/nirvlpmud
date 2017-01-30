
/*
 * Manual of Training (3/25/94)
 * Will raise weapon proficiency in one area by 1 for paladins
 * Or an attribute of a normal player by 1
 */

#define ATTRIB(x) this_player()->query_attrib(x)

reset(arg) {
   if(arg)
     return;
}

query_value() { return 4000; }

id(str) { return str == "book" || str == "manual"; }

get() { return 1; }

short() { return "A Manual of Training"; }

long() {
   write("A leatherbound book with metal edges.\n");
   write("It is a Manual of Training.\n");
   write("For Paladins it will raise a weapon proficiency by 1.\n");
   write("For all others it will raise an attribute.\n");
   write("Usage: study manual\n");
}

init() {
   add_action("study","study");
}

study(str) {
   int n, mod;
   string pro;
   object guild;
   
   if(!str || str != "manual")
     return 0;
   guild = present("guild_medal", this_player());
   if(!guild) {
     raise_attribute();
     return 1;
   }
   if(guild->query_weapon_pro("sword") < 20) 
     pro = "sword";
   else
     if(guild->query_weapon_pro("axe") < 20) 
       pro = "axe";
   else
     if(guild->query_weapon_pro("mace") < 20) 
       pro = "mace";
   else
     if(guild->query_weapon_pro("flail") < 20) 
       pro = "flail";
   else
     if(guild->query_weapon_pro("lance") < 20) 
       pro = "lance";
   else {
     write("Your weapon proficiencies are at their maximum.\n");
     return 1;
   }
   mod = guild->query_weapon_pro(pro);
   guild->set_weapon_pro(pro, (mod+1));
   write("Your "+pro+" proficiency was increased by 1.\n");
   destruct(this_object());
   return 1;
}

raise_attribute() {
   string what, raise;

   if(ATTRIB("str") < 20)
     what = "strength";
   else
     if(ATTRIB("sta") < 20)
       what = "stamina";
   else
     if(ATTRIB("mag") < 20)
       what = "magic_aptitude";
   else
     if(ATTRIB("int") < 20)
       what = "intelligence";
   else
     if(ATTRIB("pie") < 20)
       what = "piety";
   else
     if(ATTRIB("ste") < 20)
       what = "stealth";
   else
     if(ATTRIB("luc") < 20)
       what = "luck";
   else {
     write("All your attributes are at their maximum.\n");
     return 1;
   }
   raise = "raise_"+what;
   call_other(this_player(), raise, 1);
   destruct(this_object());
   return 1;
}


