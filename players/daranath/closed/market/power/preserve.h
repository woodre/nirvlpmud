market_preserve(str) {
string name;
object ob1,ob2;
int trans_level;

if(str != "corpse") {
write("You can only preserve a corpse for the Bone Marketplace.\n");
return 1; }
if(!present("corpse",environment(this_player()))) {
write("There is no corpse in the area to preserve.\n");
return 1; }

  ob1 = present("corpse",environment(this_player())); {
trans_level = ob1->query_corpse_level();
sscanf(ob1->short(),"corpse of %s",name);
}

if(tp->query_sp() < 25) {
write("You do not have the spell points to preserve the corpse.\n");
return 1; }

write("As you grasp the badge, it glows softly and the corpse hardens\n"+
      "becoming perfectly preserved for transport.\n");
say(tp->query_name()+" grasps the small "+WHT+"Bone Badge"+NORM+" and whispers a prayer.\n"+
     "The corpse takes on a hardened, preserved look.\n");
  ob2 = clone_object("/players/daranath/closed/market/obj/preserved.c");
  ob2->set_name(name);
  ob2->set_corpse_level(trans_level);
  destruct(ob1);
  move_object(ob2,environment(this_player()));
  tp->add_spell_point(-25);
  return 1;
        }
