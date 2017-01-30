string monthday() {
  string old, new, t;

  old = ctime();

  new = "";
  
  switch(old[4..6]) {
    case "Jan" : new += "01"; break; 
    case "Feb" : new += "02"; break;
    case "Mar" : new += "03"; break;
    case "Apr" : new += "04"; break;
    case "May" : new += "05"; break;
    case "Jun" : new += "06"; break;
    case "Jul" : new += "07"; break;
    case "Aug" : new += "08"; break;
    case "Sep" : new += "09"; break;
    case "Oct" : new += "10"; break;
    case "Nov" : new += "11"; break; 
    case "Dec" : new += "12"; break;
  }

  new += ".";
  
  if (old[8..8] == "" || old[8..8] == " ")
    new += "0";
  else
    new += old[8..8];

  new += old[9..9];
  
  return new;
}
