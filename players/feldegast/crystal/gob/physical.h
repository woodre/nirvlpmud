/* Physical attributes */

string extra_look() {
  if(TP == owner)
  {
    return "A glowing "+HIC+"life crystal"+NORM+" is embedded in your chest";
  }
}

int drop() { return 1; }

int get() { return 0; }
