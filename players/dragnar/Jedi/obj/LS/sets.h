/* Sets and query's used by lightsaber */

set_ignited(int i){ ignited = i; }
query_ignited(){ return ignited; }

adj_wep_life(int i) { wep_life += i; }
set_wep_life(int i){ wep_life = i; }
query_wep_life(){ return wep_life; }

query_wep_color(){ return wep_color; }

set_is_jedi(int i){ is_jedi = i; }
query_is_jedi(){ return is_jedi; }

set_wep_color(string x){
	if(x == "HIR" || x == "red"){
		wep_color = HIR;
	}
	else if(x == "HIB" || x == "blue"){
		wep_color = HIB;
	}
	else if(x == "HIG" || x == "green"){
		wep_color = HIG;
	}
	else if(x == "HIY" || x == "yellow"){
		wep_color = HIY;
	}
	else if(x == "HIM" || x == "magenta"){
		wep_color = HIM;
	}
	else if(x == "HIC" || x == "cyan"){
		wep_color = HIC;
	}
	else{
		wep_color = NORM;
	}
  Color = x;
}			

set_modtype(string str) { modtype = str; }
query_modtype() {
  if(ATT && ComboAtt != ATT) return 0;
  tell_object(USER, HIB+"modtype: "+modtype+"\n"+NORM);
  return modtype;
}

set_modifier(int x) { modifier = x; }
query_modifier() { return modifier; }

int set_combo(string str) {
  int i;
  string ComboStr;

  /* This is not ideal, but faster than constantly resizing the array */
  combo_status = 1;
  if(!combo) {
    combo = ({ "null","null","null","null","null","null","null","null","null","null", });
    combo_index = 0;
  }
  combo[combo_index] = str;
  combo_index++;   /* point to the next index where we will insert */
  /* If we at at index 10, we need to start at the beginning again */
  if(combo_index > 9) combo_index = 0;

  for(i=0, combo_no=0; i < MAX; i++) 
  {
  	if(combo[i] == str) combo_no++;
  	/************ FOR TESTING ONLY ***************/
  	if(i == 0) ComboStr = combo[i];
  	else ComboStr += ":" + combo[i];
  	/*********************************************/
  }
  
  tell_object(USER, HIR+"combos: "+ComboStr+"\n"+NORM);
  if(combo_no > 2) return combo_no - 2;
  else return 0;
}
