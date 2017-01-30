#define tp this_player()->query_name()
#define SAVE "/players/daranath/guild/member/COMPSHOP"
inherit "room/room";

int blood, skin, eye, spine, heart, soul;

reset(int arg){
if(!present("shop_obj")) {
move_object(clone_object("/players/daranath/guild/obj/misc/shop_obj.c"),this_object());
}
  if(!arg){
    
    set_light(1);
    short_desc= "Necromancer Component Storage";
    long_desc=
     "A small store reeking of preservatives and dried blood. Any\n"+
     "necromancer could spend all day digging around the store looking\n"+
      "for the perfect component to use.\n"+
      "A small sign rests on the far wall of the storage area.\n";

    items=({
     "wall","The walls here are made of a very dirty marble",
     "walls","The walls here are made of a very dirty marble",
      "sign","The sign upon the far wall reads:\n"+
          "\nAny necromancer here can do the following:\n"+
        "deposit - Deposits a component for another Necro\n"+
        "withdraw - Takes a component from the storage area\n"+
        "clist - Shows how many components are current stored here\n"+
        "pouch_me - Replaces your component pouch if you lost it\n\n"+
        "The Darkness comes from Deep within the Corpse",
    });

    dest_dir=({
      "/players/daranath/guild/room/necro4.c","north",
    });

    }
  }

    init(){
      ::init();
add_action("search","search");
add_action("clist","clist");
add_action("deposit","deposit");
add_action("withdraw","withdraw");
add_action("pouch_me","pouch_me");
    }

search(){
  write("Bits of bone and areas of dried blood are all about the room.\n");
  say(tp +" searches the area.\n");
  return 1;
}

pouch_me() {
object ob, ob2;

ob = present("necro_pouch",this_player());

if(ob) {
write("You already have a component pouch. No need for another.\n");
return 1; }
else {
ob2 = clone_object("/players/daranath/guild/obj/misc/com_pouch.c");
move_object(ob2,this_player());
write("You have been given another component pouch.\n");
return 1; }
}

deposit(str) {
object shop_obj;
if(!str) {write("Which component do you wish to deposit?\n");
  return 1; }
if((str == "blood") || (str == "skin") || (str == "eye") || (str == "spine") || (str == "heart") || (str == "soul")) {
if(!present("necro_"+str,this_player())) {
write("You do not have that component to deposit.\n");
return 1; }

shop_obj = present("shop_obj",environment(this_player()));
  if(str == "blood") {shop_obj->add_blood(1); shop_obj->save_obj(); }
  if(str == "skin") {shop_obj->add_skin(1); shop_obj->save_obj(); }
  if(str == "eye") {shop_obj->add_eye(1); shop_obj->save_obj(); }
  if(str == "spine") {shop_obj->add_spine(1); shop_obj->save_obj(); }
  if(str == "heart") {shop_obj->add_heart(1); shop_obj->save_obj(); }
  if(str == "soul") {shop_obj->add_soul(1); shop_obj->save_obj(); }
write("You have deposited "+str+" within the storage area.\n");
destruct(present("necro_"+str,this_player()));
return 1; 
} else {
write("That is not something you can deposit.\n");
return 1; }
return 1;
}

withdraw(str) {
object comp, shop_obj;
if(!str) {write("Which component do you wish to withdraw?\n");
  return 1; }
if((str == "blood") || (str == "skin") || (str == "eye") || (str == "spine") || (str == "heart") || (str == "soul")){
shop_obj = present("shop_obj",environment(this_player()));
  if(str == "blood") {
if(shop_obj->query_blood() < 1) {
write("There is no blood to withdraw from storage.\n"); return 1; }
  shop_obj->add_blood(-1); shop_obj->save_obj();
  comp = clone_object("/players/daranath/guild/obj/misc/blood.c");
  move_object(comp,this_player());
  write("You withdraw some blood from the storage area.\n"); return 1; }
  if(str == "skin") {
if(shop_obj->query_skin() < 1) {
write("There is no skin to withdraw from storage.\n"); return 1; }
  shop_obj->add_skin(-1); shop_obj->save_obj();
  comp = clone_object("/players/daranath/guild/obj/misc/skin.c");
  move_object(comp,this_player());
  write("You withdraw some skin from the storage area.\n"); return 1; }
if(str == "eye") {
if(shop_obj->query_eye() < 1) {
write("The is no eye to withdraw from storage.\n"); return 1; }
  shop_obj->add_eye(-1); shop_obj->save_obj();
  comp = clone_object("/players/daranath/guild/obj/misc/eye.c");
  move_object(comp,this_player());
  write("You withdraw some eye from the storage area.\n"); return 1; }
if(str == "spine") {
if(shop_obj->query_spine() < 1) {
write("The is no spine to withdraw from storage.\n"); return 1; }
  shop_obj->add_spine(-1); shop_obj->save_obj();
  comp = clone_object("/players/daranath/guild/obj/misc/spine.c");
  move_object(comp,this_player());
  write("You withdraw some spine from the storage area.\n"); return 1; }
if(str == "heart") {
if(shop_obj->query_heart() < 1) {
write("The is no heart to withdraw from storage.\n"); return 1; }
  shop_obj->add_heart(-1); shop_obj->save_obj();
  comp = clone_object("/players/daranath/guild/obj/misc/heart.c");
  move_object(comp,this_player());
  write("You withdraw some heart from the storage area.\n"); return 1; }
if(str == "soul") {
if(shop_obj->query_soul() < 1) {
write("The is no soul to withdraw from storage.\n"); return 1; }
  shop_obj->add_soul(-1); shop_obj->save_obj();
  comp = clone_object("/players/daranath/guild/obj/misc/soul.c");
  move_object(comp,this_player());
  write("You withdraw a soul from the storage area.\n"); return 1; }
} else {
write("That is not something you can withdraw.\n"); return 1; }
}

clist() {
object shop_ob;
shop_ob = present("shop_obj",environment(this_player()));

write("Necromancer Component Storage currently contains:\n");
write("--------------------------------------------------\n");
write("Total Parts Blood: "+shop_ob->query_blood()+"\n");
write("Total Parts Skin : "+shop_ob->query_skin()+"\n");
write("Total Parts Eye  : "+shop_ob->query_eye()+"\n");
write("Total Parts Spine: "+shop_ob->query_spine()+"\n");
write("Total Parts Heart: "+shop_ob->query_heart()+"\n");
write("Total Parts Soul : "+shop_ob->query_soul()+"\n");
write("--------------------------------------------------\n");
write("The darkness comes from deep within the corpse.\n");
say(this_player()->query_name()+" checks the contents of the component shop.\n");
return 1; 
}

realm() {return "NT";}

