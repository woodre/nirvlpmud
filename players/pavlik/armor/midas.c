#define IT capitalize(str)
#define ME capitalize(this_player()->query_name())
inherit "obj/armor";
  int count;
reset(arg){
   ::reset(arg);
set_short("The Glove of Midas");
set_long(
 "This is the glove of King Midas.  It was rumored that King\n"+
  "Midas had 'the golden touch'.\n");
   set_ac(1);
   set_weight(1);
   set_value(500);
   set_alias("glove");
   set_name("glove of midas");
   set_type("misc");
  count = 0;
}

init() {
   ::init();
  add_action("touch","touch");
}

touch(str){
  object ob, obj, nt;

  if(!str){
    write("Touch what?\n");
    return 1;
    }

  ob = present(lower_case(str), environment(this_player()));

  if(!ob){
    write("That is not here.\n");
    return 1;
    }

  if(count > 6){
    write("You touch the "+str+" with the Glove of Midas.\n"+
    "Nothing Happens.  You think the Glove's powers might be\n"+
    "all used up.\n");
    return 1;
    }

  if(living(ob)){
    write("You touch "+IT+" with the Glove of Midas.\n"+
    IT+"'s body shimmers for a moment, but nothing else happens.\n");
    return 1;
    }

  if(!ob->get()){
    write("You touch the "+str+" with the Gloves of Midas.\n"+
    "The "+str+"'s form shimmers for a moment, but nothing happens.\n");
    return 1;
    }

  write("You touch the "+str+" with the Glove of Midas.\n"+
  "The "+str+" form shimmers with a brilliant golden glow.\n"+
  "The "+str+" is turned into gold!\n");
  say(ME+" touches a "+str+" with a strange golden glove.\n"+
  "The "+str+" shimmers brilliantly and turns into gold!\n");
  obj = clone_object("players/pavlik/armor/statue");
  obj->set_short("A golden statue of "+ob->short()+"\n");
  obj->set_value(100+random(900));
  obj->set_weight(5+random(10));
  count++;
  return 1;
}
