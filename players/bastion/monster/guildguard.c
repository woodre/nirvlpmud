
inherit "obj/monster";

reset(arg) {
     object money, sword;
     ::reset(arg);
     if(!arg) {
          set_name("imperial guard");
          set_race("guard");
          set_level(19);
          set_hp(475);
          set_al(500);
          set_short("an imperial guard");
          set_long("He wear the livery of the Imperial Antarian guard:\n"+
                   "Silver and azure stripes on a field of purple.\n");
          set_aggressive(0);
          set_wc(26);
          set_ac(18); 
     sword=clone_object("obj/weapon");
     sword->set_name("bastard sword");
     sword->set_alt_name("sword");
     sword->set_class(15);
     sword->set_value(2500);
     sword->set_weight(3);
     move_object(sword, this_object());
          money=clone_object("obj/money");
          money->set_money(1000);
          move_object(money, this_object()); }
}


init() {
     set_heart_beat(1);
     ::init();
}

heart_beat() {
     if(!query_attack()) {
          check_criminal();
          move(); }
     ::heart_beat();
     return 1;
}

check_criminal() {
     object ob, next_ob;
     ob=first_inventory(environment(this_object()));
     while(ob) {
          next_ob=next_inventory(ob);
          if(ob->query_crime()) {
               attack_criminal(ob);
               return 1; }
     }
     return 1;
}

attack_criminal(who) {
     say("Guard yells: Hold, varlet!\n");
     attack(who);
     return 1;
}

move() {
     string dir;
     int x;
     dir=allocate(8);
     dir[0]="north";
     dir[1]="northeast";
     dir[2]="east";
     dir[3]="southeast";
     dir[4]="south";
     dir[5]="southwest";
     dir[6]="west";
     dir[7]="northwest";
     x=random(8);
     if(random(10) < 9) 
          command(dir[x]);
     return 1;
}
