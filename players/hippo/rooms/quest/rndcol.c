string *color;
int num_room,x,y;
string *room;
string *box;
string kleur;
set_color(str) { color=str; }
query_color(i) {return color[i];}
random_color() {
   color=({"crimson",
      "red","orange","yellow","light_green","dark_green","light_blue",
      "dark_blue","blood_red","indigo","grass_green",
      "purper","black","white","cyane","light_brown","dark_brown",
      "rose","cobalt_blue","grey"});
   }
reset(arg) {
   num_room=12;
   for(x=0;x<num_room;x++) {
      room[x]->set_color(room[x]->random_color[x]);
      box[x]->set_color(room[x]->query_color[x]);
}
}
