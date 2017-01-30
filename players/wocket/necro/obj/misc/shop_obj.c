/* Object for the Necromancer Component Shop */

#define SAVE "players/daranath/guild/member/SHOP"

int blood, skin, eye, spine, heart, soul;

id(str) { return str == "shop_obj"; }

reset(arg) {
  if(!restore_object(SAVE));
  if(arg) return;
}

drop() { return 1; }
get() { return 0; }

add_blood(int num) { blood += num; }
add_skin(int num) { skin += num; }
add_eye(int num) { eye += num; }
add_spine(int num) { spine += num; }
add_heart(int num) { heart += num; }
add_soul(int num) { soul += num; }

query_blood() {return blood; }
query_skin() {return skin; }
query_eye() {return eye; }
query_spine() {return spine; }
query_heart() {return heart; }
query_soul() {return soul; }

save_obj() {save_object(SAVE); return 1; }

