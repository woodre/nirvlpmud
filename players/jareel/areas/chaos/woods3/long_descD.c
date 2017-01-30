

string get_long_desc(int lineno) {
  string *line1, *line2, *line3, *line4;

  line1 = ({
"Large colourful trees surround the isolated worn driven path.",
"Large trees loom ominously, seemingly watching every move.",
"Large swaying branches creek in the wind as trees move overhead.",
"Large colourful trees let little light in past the dense canopy.",
"Large swaying branches sway overhead creating ominous shadows.",
  });

  line2 = ({
"Flowing mystical energy creates a quiescent aura in the air.",
"A crackling mystical energy creates a powerful aura.",
"A powerful aura is created by crackling mystical energy.",
  });

  line3 = ({
"Heavily travelled dirt lies beneath every step taken on the path.",
"Worn beaten heavily travelled dirt lies beneath every weary step.",
"A Heavily trodden dirt path lies beneath every weary stride.",
  });

  line4 = ({
"Dark shifting shadows ebb and flow over the forest floor.",
"Rolling shadows shift over the forest causing dark illusions.",
"Shifting shadows cause start illusions over the dirt road.",
"Running shadows shift and flow over the forest floor.",
  });

  switch(lineno) {
  case 4: return line4[random(sizeof(line4))] + "\n"; break;
  case 3: return line3[random(sizeof(line3))] + "\n"; break;
  case 2: return line2[random(sizeof(line2))] + "\n"; break;
  case 1: return line1[random(sizeof(line1))] + "\n"; break;
  default: return 0;
  }
  return 0;
}
