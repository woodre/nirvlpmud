preserve()  {
string name;
object ob1,ob2;
int trans_level;

  ob1 = present("corpse",environment(this_player())); {
trans_level = ob1->query_corpse_level();
sscanf(ob1->short(),"corpse of %s",name);
}
  if(!ob1)  {
    ob1 = present("corpse",this_player()); {
trans_level = ob1->query_corpse_level();
sscanf(ob1->short(),"corpse of %s",name);
}
        }
  if(!ob1)  {
    write("There is no corpse here to preserve.\n");
    return 1;
        }
if(tp->query_sp() < 5) {
write("You do not have the spell points to preserve the corpse.\n");
return 1; }

write("You pull out your necromantic component pouch and preserve\n"+
      "the corpse. It will no longer decay over time.\n");
say(tp->query_name()+" bends over and preserves the corpse.\n");
  ob2 = clone_object("/players/daranath/guild/obj/misc/preserved.c");
  ob2->set_name(name);
  ob2->set_corpse_level(trans_level);
  destruct(ob1);
  move_object(ob2,environment(this_player()));
  tp->add_spell_point(-5);
  return 1;
        }
