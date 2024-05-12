
#include <math.h>
#include "CALC_DISP.h"

#define pi 3.14159265358979323846



double calc_displacment(double lat1, double lon1, double lat2, double lon2, char unit) {
  double theta, dist;
  if ((lat1 == lat2) && (lon1 == lon2)) {
    return 0;
  }
  else {
    theta = lon1 - lon2;
    dist = sin(deg2rad(lat1)) * sin(deg2rad(lat2)) + cos(deg2rad(lat1)) * cos(deg2rad(lat2)) * cos(deg2rad(theta));
    dist = acos(dist);
    dist = rad2deg(dist);
    dist = dist * 60 * 1.1515;
    switch(unit) {
      case 'M'://miles
        break;
      case 'm'://meters
        dist = dist * 1.609344;
				dist = dist/1000.00;
        break;
      case 'N':
        dist = dist * 0.8684;
        break;
    }
    return (dist);
  }
}


double deg2rad(double deg) {
  return (deg * pi / 180);
}


double rad2deg(double rad) {
  return (rad * 180 / pi);
	

}

