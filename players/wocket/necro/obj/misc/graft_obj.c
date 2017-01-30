int face, head, neck;
int chest, back, rightarm;
int leftarm, rightleg, leftleg;

id(str) { return str == "graft_obj"; }

drop() { return 1; }
get() { return 0; }

reset(arg) {
  if(arg) return;
  face = head = neck = 0;
  chest = back = rightarm = 0;
  leftarm = rightleg = leftleg = 0;
}

extra_look() {
  if(face) write(environment()->query_name()+" has "+scarring_level(face)+" scarring on "+
           environment()->query_possessive()+" face.\n");
  if(head) write(environment()->query_name()+" has "+scarring_level(head)+" scarring on "+
           environment()->query_possessive()+" head.\n");
  if(neck) write(environment()->query_name()+" has "+scarring_level(neck)+" scarring on "+
           environment()->query_possessive()+" neck.\n");
  if(chest) write(environment()->query_name()+" has "+scarring_level(chest)+" scarring on "+
           environment()->query_possessive()+" chest.\n");
  if(back) write(environment()->query_name()+" has "+scarring_level(back)+" scarring on "+
           environment()->query_possessive()+" back.\n");
  if(rightarm) write(environment()->query_name()+" has "+scarring_level(rightarm)+" scarring on "+
           environment()->query_possessive()+" right arm.\n");
  if(leftarm) write(environment()->query_name()+" has "+scarring_level(leftarm)+" scarring on "+
           environment()->query_possessive()+" left arm.\n");
  if(rightleg) write(environment()->query_name()+" has "+scarring_level(rightleg)+" scarring on "+
           environment()->query_possessive()+" right leg.\n");
  if(leftleg) write(environment()->query_name()+" has "+scarring_level(leftleg)+" scarring on "+
           environment()->query_possessive()+" left leg.\n");
 }

scarring_level(int h) {
string msg;
  switch(h) {
	case 1: msg = "minor"; break;
	case 2: msg = "massive"; break;
	case 3: msg = "grotesque"; break; 
  }
  return msg; 
}

set_face(arg) { face = arg; }
query_face() { return face; }

set_head(arg) { head = arg; }
query_head() { return head; }

set_neck(arg) { neck = arg; }
query_neck() { return neck; }

set_chest(arg) { chest = arg; }
query_chest() { return chest; }

set_back(arg) { back = arg; }
query_back() { return back; }

set_rightarm(arg) { rightarm = arg; }
query_rightarm() { return rightarm; }

set_leftarm(arg) { leftarm = arg; }
query_leftarm() { return leftarm; }

set_rightleg(arg) { rightleg = arg; }
query_rightleg() { return rightleg; }

set_leftleg(arg) { leftleg = arg; }
query_leftleg() { return leftleg; }

