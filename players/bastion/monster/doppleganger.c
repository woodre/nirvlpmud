
inherit "obj/monster";

reset(arg) {
     object money;
     ::reset(arg);
     if(!arg) {
          name="doppleganger";
          cap_name="Doppleganger";
          level=13;
          experience=105000;
          max_hp=195;
          hit_point=195;
          weapon_class=17;
          armor_class=10;
          is_npc=1;
          alignment=-350;
          enable_commands(); 
          money=clone_object("obj/money");
          money->set_money(700);
          move_object(money, this_object()); }
}

id(str) {
  if(this_player()) { return (str==name || str==this_player()->query_real_name() || str==this_player()->query_name()); }
  else return str==name;
}

short() {
  if(this_player())
     return this_player()->short();
  else return name;
}

long() {
  if(this_player())
     this_player()->long();
  else return name;
}

