short() { 
  int i;
  string sh;
  if(set_light(0) > 0) { 
    if(this_player()) {
      if(!environment(this_player())->query_ffroom()) return HBRED+HIW+FLAMEFOREST+NORM+NORM; 
      else { 
        sh = HBRED+HIW+short_desc+" ["+HBRED+WHT;
        if(!dest_dir || no_exits) sh += "no exits";
        else {
          for(i=1; i<sizeof(dest_dir); i+=2) {
            sh += translate_exit(dest_dir[i]);
            if (i < sizeof(dest_dir)-2) sh += ",";
          }
        }
        sh += HBRED+HIW+"]";
        return sh+NORM+NORM; 
      }
    }
    else return HBRED+HIW+FLAMEFOREST+NORM+NORM;   
  }
  else return "Dark room";     
}
