#define ME capitalize(this_player()->query_name())
#define IT capitalize(obj->query_name())

int quaffed,num;
string color;

id(str) {
  if(!quaffed)  {
    return str == "vial" || str == "potion" || str == color ||
    str == color+" potion";
  }
  return str == "poison" || str == "potion_poison";
}

short() { 
  if(!quaffed) { return "A "+color+" potion"; }
  return 0;
}

long() {  
  if(!quaffed) {
    write("A vial of "+color+" liquid\n");
    return;
  }
  return;
}

get() { return 1; }
query_weight() { return 1; }
query_value(){ if(!quaffed) return 700; else return 0; }
query_save_flag(){ return 1; }

drop() { 
  if(!quaffed) return 0;
  return 1;
}

reset(arg){
  int i;
  if(arg) return;
  quaffed = 0;
  num = 0;
  i = random(3);
  if(i==0) color = "blue";
  if(i==1) color = "red";
  if(i==2) color = "green";
}

init(){
  add_action("drink_potion","drink");
}

drink_potion(str){
  if(id(str)) {

    if(quaffed) {
      return 0;
    }
    if(present("empty_potion", this_player())){
      write("It would not be a good idea to drink another potion right now.\n");
      return 1;
    }
    write(
    "You tip the bottle to your lips and drink the sweet liquid.  It feels\n"+
    "hot going down your throat and warmer yet in your stomach!\n"+
    "Something is not right ....\n");
    say(
    ME+" downs a small potion.\n");
    quaffed = 1;
    call_out("sick", 5, this_player());

    write_file("/players/pavlik/ilstkarn/ITEM_LOG",
	ctime()+"\t"+capitalize(this_player()->query_name())+" used a Black Potion.\n");

    return 1;
  }
}

sick(ob) {
  string who;
  if(ob) {
    who = capitalize(ob->query_name());
    tell_object(ob,
    "You don't feel so good.\n"+
    "You bend over and puke on your shoes!\n");
    tell_room(environment(ob),
    who+" looks a little green.\n"+
    who+" doubles over and wretches!\n");
    ob->hit_player(5+random(10), "other|poison");
    call_out("sick", 30+random(50), ob);
    return 1;
  }
}

