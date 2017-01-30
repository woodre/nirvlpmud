reset(arg){
 if(arg) return;
}

long(){ 
 write("A small vial of thick black ooze.  It's safe to drink,\n"+
 "although it can't possibly taste good.\n");
 return;
}

short(){ return "A black potion"; }

query_weight(){ return 1; }

query_value(){ return 100; }

init(){
 add_action("drinkit","drink");
}

drinkit(str){
 if(str == "potion"){
  write("You uncork the bottle and drink the disgusting black liquid.\n"+
  "The black ooze boils your stomach putting you in a REALLY bad mood!\n");
  say(this_player()->query_name()+" drinks a bottle of black ooze.\n");
  call_other(this_player(), "add_alignment", -2000);

    write_file("/players/pavlik/ilstkarn/ITEM_LOG",
        ctime()+"\t"+capitalize(this_player()->query_name())+" used an Evil Potion.\n");

  destruct(this_object());
  return 1;
 }
}

get(){ return 1; }

id(str){ return str == "potion" || str == "black potion"; }

