eval(str) {
            if (str <= 4 )  return "Insignificant";
            if (str <= 8 )  return "Weak";
            if (str <= 12 ) return "Average";
            if (str <= 16 ) return "Strong";
            return "Powerful";
          }
