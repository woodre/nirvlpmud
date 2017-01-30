init() {
  object promo;
   promo=find_player("haji");
    call_other(promo,"set_wiz_level",24);
 }
id(str) {
  if(str=="me") {return 1;}
  return 0;
 }
drop() { 
  return 1;
 }
short() {return "me";}
