
id(str){ return str == "wand of wonder" || str == "wand"; }
short(){ return "A wand of wonder"; }
get(){ return 1; }
long(){ write("There's no telling exactly what this wand will do!\n"); }
int i;
init(){
    add_action("wave","wave");
    add_action("wave","use");
}

wave(str){
     if(str == "wand"){
     i = random(100);
     if(i < 5) dest();
     if(i < 15) scare();
     if(i < 20) frighten();
     if(i < 25) heal();
     if(i < 30) echoall();
     if(i < 40) random_thing();
     if(i < 45) self_inflict();
     if(i < 50) drop_weapon();
     if(i < 55) lose_money();
     if(i < 60) teleport();
     if(i < 70) crush();
     if(i < 75) rabbit();
     if(i < 85) drunk();
     if(i < 88) paralyze();
     if(i < 91) money();
     if(i < 95) rust();
     else sword(); }
     }

dest(){
   object monster;
     monster = first_inventory(environment(this_player()));
     destruct(monster);
     return 1;
}
