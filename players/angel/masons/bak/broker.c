compare(z) {
int a,b;
string as,bs,str;
object oa,ob;
if (!z || sscanf(z," %s",str)!=2) str = z;
if (!str || sscanf(str,"%s %s",as,bs)!=2 ) {
write("Compare what against what?\n");
return 1;
}
if(this_player()->query_spell_point() < 8) {
   write("You do not have enough spell points for this ability.\n");
   return 1;
}
oa=present(as,this_player());
ob=present(bs,this_player());
if (!oa) {
write("Couldn't find "+as+"\n");
return 1;
}
if (!ob) {
write("Couldn't find "+bs+"\n");
return 1;
}
this_player()->add_spell_point(-8);
a = oa->weapon_class();
b = ob->weapon_class();
if (a && b) {
if (a==b) 
write(" A voice inside your head says: They are of equal value.\n");
else if (a<b) 
write("  A voice inside your head says: "+bs+" is better.\n");
else 
write("  A voice inside your head says: "+as+" is better.\n");
return 1;
}
a = oa->armour_class();
b = ob->armour_class();
 
if (a && b) {
if (a==b) 
write("  A voice inside your head says: They are of equal value.\n");
else if (a<b) 
write("  A voice inside your head says: "+bs+" is better.\n");
else 
write("  A voice inside your head says: "+as+" is better.\n");
return 1;
}
a = oa->query_value();
b = ob->query_value();
if (a && b) {
if (a==b) 
write("  A voice inside your head says: They are of equal value.\n");
else if (a<b) 
write("  A voice inside your head says: "+bs+" is better.\n");
else 
write("  A voice inside your head says: "+as+" is better.\n");
return 1;
}
write("  A voice inside your head says: I'm confused. I think you are comparing different types of\n");
write("of objects. Either that, or valueless ones.\n");
return 1;
}
